%option noyywrap

%{
#include <stdio.h>
#include <string.h>

#define YY_DECL int yylex()
#include "parser.tab.h"

int words = 0;
int chars = 0;
int lines = 0;

%}
/*recognize letters from a to Z
  recognize numbers from 0 to 9
  allows combination for more than one of them
  allows white spaces and tabs
  allows more than one integers
  white spaces
  For the lines below %% it enable lexer to recognize the keywords that is in " "*/
letter      [a-zA-Z]
digit       [0-9]
ID          {letter}({letter}|{digit})*
delim       [ \t\n]
NUMBER      {digit}+(\.{digit}+)?(E[+\-]?(digit)+)?
ws          {delim}+

%%
"/*"    				{
							int c;
							while((c = input()) != 0) {
								if(c == '*') {
									if((c = input()) == '/')
										break;
									else
										unput(c);
								}
							}
						}
						
"int"	{words++; chars += strlen(yytext);
			printf("%s : TYPE\n", yytext);
			yylval.string = strdup(yytext); 
			return TYPE;
		}

"write"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return WRITE;
		}
"return"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return RETURN;
		}
"if"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return IF;
		}
"else"	{words++; chars += strlen(yytext);
			printf("%s : KEYWORD\n", yytext);
			yylval.string = strdup(yytext); 
			return ELSE;
		}
{ID}	{words++; chars += strlen(yytext);
			  printf("%s : IDENTIFIER\n",yytext);
			  yylval.string = strdup(yytext); 
			  return ID;
			}
			
{NUMBER}		{words++; chars += strlen(yytext);
			  printf("%s : NUMBER\n",yytext);
			  yylval.number = atoi(strdup(yytext)); 
			  return NUMBER;
			}
";"		{chars++;
		  printf("%s : SEMICOLON\n", yytext);
		  yylval.string = strdup(yytext); 
		  return SEMICOLON;
		}
"("		{chars++;
		  printf("%s : STARTPASS\n", yytext);
		  yylval.string = strdup(yytext); 
		  return STARTPASS;
		}
","		{chars++;
		  printf("%s : EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return COMMA;
		}
"="		{chars++;
		  printf("%s : EQ\n", yytext);
		  yylval.string = strdup(yytext); 
		  return EQ;
		}
")"		{chars++;
		 printf("%s : ENDPASS\n",yytext);
		 yylval.string = strdup(yytext);
		 return ENDPASS;
		}
"["		{chars++;
		 printf("%s : STARTARRAY\n",yytext);
		 yylval.string = strdup(yytext);
		 return STARTARRAY;
		}
"]"		{chars++;
		 printf("%s : ENDARRAY\n",yytext);
		 yylval.string = strdup(yytext);
		 return ENDARRAY;
		}
"{"		{chars++;
		 printf("%s : STARTFUN\n",yytext);
		 yylval.string = strdup(yytext);
		 return STARTFUN;
		}
"}"		{chars++;
		 printf("%s : ENDFUN\n",yytext);
		 yylval.string = strdup(yytext);
		 return ENDFUN;
		}
"+"		{chars++;
		  printf("%s : PLUS\n", yytext);
		  yylval.string = strdup(yytext); 
		  return PLUS;
		}
">"		{chars++;
		  printf("%s : GREATERTHAN\n", yytext);
		  yylval.string = strdup(yytext); 
		  return GREATERTHAN;
		}
"<"		{chars++;
		  printf("%s : LESSTHAN\n", yytext);
		  yylval.string = strdup(yytext); 
		  return LESSTHAN;
		}

[\n]	{lines++; chars=0;}
[ \t]	{chars++;}
.		{chars++;
         printf("%s : Unrecognized symbol at line %d char %d\n", yytext,lines,chars);
		}
%%