%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "Assembly.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;

FILE * IRcode;
//FILE * MIPScode;


void yyerror(const char* s);
char currentScope[50] ="Global"; // "global" or the name of the function
int semanticCheckPassed = 1; // flags to record correctness of semantic checks

//The following union enables four data types, which are number character string and ast
%}

%union {
	int number;
	char character;
	char* string;
	struct AST* ast;
}

%token <string> TYPE
%token <string> ID
%token <char> SEMICOLON
%token <char> STARTFUN
%token <char> ENDFUN
%token <char> STARTPASS
%token <char> ENDPASS
%token <char> STARTARRAY
%token <char> ENDARRAY
%token <char> EQ 
%token <char> PLUS
%token <char> COMMA


%token <number> NUMBER
%token <string> WRITE
%token <string> RETURN
%token <string> IF
%token <string> ELSE
%token <string> GREATERTHAN
%token <string> LESSTHAN

%printer { fprintf(yyoutput, "%s", $$); } ID;
%printer { fprintf(yyoutput, "%d", $$); } NUMBER;
%printer { fprintf(yyoutput, "%s", $$); } RETURN;

%type <ast> Program DeclList Decl VarDecl Stmt StmtList Expr Iteration FunDecl Block Primary IfExpr Condition

%start Program

%%

Program: DeclList  { $$ = $1;
					 printf("\n--- Abstract Syntax Tree ---\n\n");
					 printAST($$,0);
					}
;

DeclList:	Decl DeclList	{ $1->left = $2;
							  $$ = $1;
							}
	| Decl	{ $$ = $1; }
;

Decl:	FunDecl
	| VarDecl SEMICOLON
	| StmtList
;

VarDecl: {}	
	| TYPE ID { printf("\n RECOGNIZED RULE: Variable declaration %s\n", $2);
									// Symbol Table
									symTabAccess();
									int inSymTab = found($2, currentScope);
									//printf("looking for %s in symtab - found: %d \n", $2, inSymTab);
									
									printf("Current scope is: %s\n", currentScope);

									if (inSymTab == 0) 
										addItem($2, "Var", $1,0, currentScope);
										
									else
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									showSymTable();
									
								  // ---- SEMANTIC ACTIONS by PARSER ----
								    $$ = AST_Type("Type",$1,$2);
									printf("-----------> %s", $$->LHS);
								}
	| TYPE ID STARTARRAY Primary ENDARRAY {printf("\n RECOGNIZED RULE: Array declaration %s\n", $2);
									symTabAccess();
									
									int inSymTab = found($2 , currentScope);

									printf("Current scope is: %s\n", currentScope);

									if(inSymTab == 0)
										addItem($2,"Array",$1,$4,currentScope);
										
										// showSymTable();
									else 
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", $2);
									showSymTable();

									// ---- SEMANTIC ACTIONS by PARSER ----
									$$ = AST_Type("Array",$1,$2);
									printf("-----------> %s", $$->LHS);

									emitMIPSArray($2,$4);
									}
;

FunDecl: TYPE ID STARTPASS { 

	sprintf(currentScope,"%s",$2); 
	emitMIPSFunction($2);

	} ParamDeclList ENDPASS Block{ 
		printf("\n RECOGNIZED RULE: Function declaration %s\n", $2);
		
		printf("Current scope is: %s\n", currentScope);
		addItem($2,"Fun","fun",0,"Global");
		//  sprintf(str, "%d", $3); convert $3 from int to string
		printf("new scope is: %s\n", currentScope);
		// emitMIPSFunction($2);

		showSymTable();	
		
}

ParamDeclList: { /* epsilon - no variable declarations are an option */}

Block: STARTFUN ENDFUN
	| STARTFUN DeclList ENDFUN {}


StmtList:	
	| Stmt StmtList
;

Stmt:	SEMICOLON	{}
	| Expr SEMICOLON	{$$ = $1;}
	| IfExpr {}
	| Condition {}
;

Expr: ID EQ Iteration {printf("\n\n\n\n Iteration after Expression");
				printf(": %d\n\n\n%s\n\n", $3 , $1)	
				//emitAssignment($1, $3);
	}
	| RETURN Primary { printf("\n RECOGNIZED RULE: RETURN %d\n", $2);
		emitMIPSEndFunction();
	}
	| ID EQ ID 	{ printf("\n RECOGNIZED RULE: Assignment statement\n"); 
					// ---- SEMANTIC ACTIONS by PARSER ---- //
					  $$ = AST_assignment("=",$1,$3);

					// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

					// Check if identifiers have been declared

					    if(found($1, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
					    if(found($3, currentScope) != 1){
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}

					// Check types

						printf("\nChecking types: \n");
						int typeMatch = compareTypes ($1, $3, currentScope);
						if (typeMatch == 0){
							printf("SEMANTIC ERROR: Type mismatch for variables %s and %s \n", $1, $3);
							semanticCheckPassed = 0;
						}
						

					if (semanticCheckPassed == 1) {
						printf("\n\n>>> AssignStmt Rule is SEMANTICALLY correct and IR code is emitted! <<<\n\n");

						// ---- EMIT IR 3-ADDRESS CODE ---- //
						
						// The IR code is printed to a separate file

						// Temporary variables management will eventually go in here
						// and the paramaters of the function below will change
						// to using T0, ..., T9 variables

						emitAssignment($1, $3);

						// ----     EMIT MIPS CODE   ----  //

						// The MIPS code is printed to a separate file

						// MIPS registers management will eventually go in here
						// and the paramaters of the function below will change
						// to using $t0, ..., $t9 registers

						emitMIPSAssignment($1, $3);



					}
					

				}

	| ID EQ NUMBER 	{ printf("\n RECOGNIZED RULE: Constant Assignment statement\n"); 
	
					   // ---- SEMANTIC ACTIONS by PARSER ----
					   char str[50];
						
					   sprintf(str, "%d", $3); // convert $3 from int to string
					   $$ = AST_assignment("=",$1, str);

						// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

						// Check if identifiers have been declared

					    if(found($1, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $1, currentScope);
							semanticCheckPassed = 0;
						}
						
						// Check types

						printf("\nChecking types: \n");

						//printf("%s = %s\n", getVariableType($1, currentScope), getVariableType($3, currentScope));
						
						printf("%s = %s\n", "int", "number");  // This temporary for now, until the line above is debugged and uncommented
						
						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							// Symbol Table Editing itemKind
							// char num[50] = $3;
							
							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file

							// Temporary variables management will eventually go in here
							// and the paramaters of the function below will change
							// to using T0, ..., T9 variables

							char itemName[50], id2[50],itemId[10];
							sprintf(itemName, "%s", $1);
							sprintf(id2, "%d", $3);

							newItemKind(itemName,id2,currentScope);

							sprintf(itemId, "%d",getIdByItemName(itemName,currentScope));

							printf("\n\n\n ITEM ID %s \n\n", (itemId));
							// Temporary variables management will eventually go in here
							// and the paramaters of the function below will change
							// to using T0, ..., T9 variables

							//emitConstantIntAssignment(id1, id2);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers


							emitMIPSConstantIntAssignment(atoi(itemId), id2);

						}
					}
	
	| WRITE ID 	{ printf("\n RECOGNIZED RULE: WRITE statement\n");

					$$ = AST_Write("write",$2,"");
					
					// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

					// Check if identifiers have been declared
					if(found($2, currentScope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", $2, currentScope);
							semanticCheckPassed = 0;
						}

					if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");

							// ---- EMIT IR 3-ADDRESS CODE ---- //
							
							// The IR code is printed to a separate file
							
							emitWriteId($2);

							// ----     EMIT MIPS CODE   ----  //

							// The MIPS code is printed to a separate file

							// MIPS registers management will eventually go in here
							// and the paramaters of the function below will change
							// to using $t0, ..., $t9 registers

							char itemName[50],itemId[10];
							sprintf(itemName, "%s", $2);
							sprintf(itemId, "%d",getIdByItemName(itemName,currentScope));

							printf("\n\n\n ITEM ID %s \n\n", (itemId));
						
							emitMIPSWriteId(itemId);
			
						}
				}
	| ID STARTARRAY NUMBER ENDARRAY EQ NUMBER { printf("\n Access to an element of the array.\n");
			//find array in symbol table
			//find position in symbol table and assign value
			char itemName[50], value[50],arrayPosition[10];
			sprintf(itemName, "%s", $1);
			sprintf(value, "%d", $6);
			sprintf(arrayPosition, "%d",$3);
			assignArray(itemName,arrayPosition,value);
			// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

			// ----     EMIT MIPS CODE   ----  //
			emitMIPSIntegerAssignmentArray($3,$6);


		}
		| ID STARTARRAY NUMBER ENDARRAY EQ ID { printf("\n Access to an element of the array.\n");
			//find array in symbol table
			//find position in symbol table and assign value
			char itemName[50], value[50],arrayPosition[10];
			sprintf(itemName, "%s", $1);
			int foundValue = atoi(getVariableValue($6, currentScope));
			sprintf(arrayPosition, "%d",$3);
			assignArray(itemName,arrayPosition,getVariableValue($6, currentScope));
			// ---- SEMANTIC ANALYSIS ACTIONS ---- //  

			// ----     EMIT MIPS CODE   ----  //
			emitMIPSIntegerAssignmentArray($3,atoi(getVariableValue($6, currentScope)));


		}
	| WRITE ID STARTARRAY NUMBER ENDARRAY{	printf("\n RECOGNIZED RULE: WRITE element from array\n");
			emitMIPSWriteArray($2,$4);

		}
	| ID STARTPASS ENDPASS {	printf("\n CALLING A FUNCTION");
		emitMIPSCallFunction($1);
	}
;
Condition: NUMBER GREATERTHAN NUMBER{printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %d Greater than %d \n\n\n",$1, $3)
			
		};
		| NUMBER LESSTHAN NUMBER{printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %d Less than %d \n\n\n",$1, $3)
		
		
		};
		| ID GREATERTHAN NUMBER{printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %s Greater than %d \n\n\n",$1, $3)
		
		
		};
		| ID LESSTHAN NUMBER{printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %s Less than %d \n\n\n",$1, $3)
		
		
		};
		| NUMBER LESSTHAN ID{printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %d Less than %s \n\n\n",$1, $3)
		
		
		};
		| NUMBER GREATERTHAN ID{printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %d Greater than %s \n\n\n",$1, $3)
		
		
		};
		| ID GREATERTHAN ID{printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %s Greater than %s \n\n\n",$1, $3)
		
		
		};
		| ID LESSTHAN ID{printf("\n\n\n\n RECOGNIZED RULE: Logic Expression , Check if %s Less than %s \n\n\n",$1, $3)
		
		
		};
;
IfExpr: IF STARTPASS Condition ENDPASS Block {}
	| IF STARTPASS Condition ENDPASS Block ELSE Block {}
Iteration: ID PLUS NUMBER {
			printf("\nRECOGNIZED RULE: Iterating Expression:\n");
			int num = 0;
			char id1[10], id2[10];
			//sprintf(id1, "%d", $1);
			sprintf(id2, "%d", $3);
			//printf("\n%d,is a number add it, %d\n", $1,Iteration_Number_AST(id1));

			if(found($1,currentScope) == 1){
				printf("\nHere is a found number in Symbol Table %s : ",$1);
				int foundValue = atoi(getVariableValue($1, currentScope));
				printf("%d \n",foundValue);

				num += foundValue;

			} else {
				printf("\nInvalid variable used in Statement!\n");
			}

			if(!num == 0 && Iteration_Number_AST(id2) == 1){
				//printf("\n%d\n",$1->nodeType);
				//int b = $3;
				//printf("\n%d\n",$3->nodeType);
				int number = num + $3;
				printf("\n%d + %d = %i\n",num, $3, number);
				num += number;
				printf("\n new value: %d\n",number);
				char charpass[10], str[50], itemId[10];
				sprintf(charpass, "%d", number);
				sprintf(str, "%s", iterationKind(charpass,0)); 
				printf("\n\n\n\n THE VARIABLE USED: %s",str);

				sprintf(itemId, "%d",getIdByItemName(str,currentScope));
				printf("\n\n\n ITEM ID %s \n\n", (itemId));
				
				emitMIPSConstantIntAssignment(atoi(itemId),charpass);

			} 
		}
		| ID PLUS ID {
			printf("\nRECOGNIZED RULE: On 2 Variables Iterating Expression:\n");
			//int num = $1->nodeType;
			int num = 0;
			//sprintf(id1, "%d", $1);
			//printf("\n%d,is a number add it, %d\n", $1,Iteration_Number_AST(id1));

			if(found($1,currentScope) == 1 && found($3,currentScope) == 1){
				printf("\nHere is a found number in Symbol Table %s : ",$1);
				int foundValue = atoi(getVariableValue($1, currentScope));
				int foundValue1 = atoi(getVariableValue($3, currentScope));
				printf("%d \n",foundValue);
				int number  = foundValue + foundValue1;
				printf("\n%d + %d = %i\n",foundValue, foundValue1, number);
				char charpass[10];
				sprintf(charpass, "%d", number);
				char str[50],itemId[10];
				//temp work around
				sprintf(str, "%s", iterationKind(charpass,0)); 
				printf("\n\n\n\n THE VARIABLE USED: %s",str);

				sprintf(itemId, "%d",getIdByItemName(str,currentScope));
				printf("\n\n\n ITEM ID %s \n\n", (itemId));
				
				emitMIPSConstantIntAssignment(atoi(itemId),charpass);
				//when multiple iterations
				
				num += number;

			} else {
				printf("\nInvalid variable used in Statement!\n");
			}
			// else {
			// 	int number = 0 + $1->nodeType;
			// 	num += number;
			// 	printf("\n%d + %d = %i\n",0, $1->nodeType, number);
			// 	printf("Added %d\n",num);
			// }
		}
		| NUMBER PLUS NUMBER {
			printf("\nRECOGNIZED RULE: On 2 Variables Iterating Expression:\n");
			char id1[10], id2[10];
			sprintf(id1, "%d", $1);
			sprintf(id2, "%d", $3);
			if(Iteration_Number_AST(id1) == 1 && Iteration_Number_AST(id2) == 1){
				int number = $1 + $3;
				printf("\n%d + %d = %i\n",$1, $3, number);
				printf("\n new value: %d\n",number);
				char charpass[10];
				sprintf(charpass, "%d", number);
				iterationKind(charpass,0);
				// showSymTable();


			} 
		}
;
Primary: {}
	| ID {"%s",$1}
	| NUMBER {"%d",$1}
	| STARTFUN Expr ENDFUN

//check if isNumber or not



%%

int main(int argc, char**argv)
{
/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
*/
	printf("\n\n##### COMPILER STARTED #####\n\n");
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}

	// Initialize IR and MIPS files

	initIRcodeFile();

	initAssemblyFile();

	// Start parser
	yyparse();

	// Add the closing part required for any MIPS file
	emitEndOfAssemblyCode();

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}