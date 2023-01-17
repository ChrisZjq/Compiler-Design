// Symbol table header
#include <string.h>

struct Entry
{
	int itemID;
	char itemName[50]; // the name of the identifier
	char itemKind[8];  // is it a function or a variable?
	char itemType[8];  // Is it int, char, etc.?
	int arrayLength;
	char scope[50]; // global, or the name of the function
};

struct Entry symTabItems[100];
int symTabIndex = 0;
int SYMTAB_SIZE = 20;

void symTabAccess(void)
{
	printf("::::> Symbol table accessed.\n");
}

int getTableSize()
{
	return symTabIndex;
}

void showSymTable()
{
	printf("itemID    itemName    itemKind    itemType     ArrayLength    itemScope\n");
	printf("-----------------------------------------------------------------------\n");
	for (int i = 0; i < symTabIndex; i++)
	{
		printf("%5d %15s  %7s  %7s %6d %15s \n", symTabItems[i].itemID, symTabItems[i].itemName, symTabItems[i].itemKind, symTabItems[i].itemType, symTabItems[i].arrayLength, symTabItems[i].scope);
	}

	printf("-----------------------------------------------------------------------\n");
}
const addItemArray(char itemName[50], char itemKind[30], char itemType[8], int arrayLength, char scope[50])
{
	// symTabItems[symTabIndex].itemID = symTabIndex;
	strcpy(symTabItems[symTabIndex].itemName, itemName);
	strcpy(symTabItems[symTabIndex].itemKind, itemKind);
	strcpy(symTabItems[symTabIndex].itemType, itemType);
	symTabItems[symTabIndex].arrayLength = arrayLength;
	strcpy(symTabItems[symTabIndex].scope, itemName);
	showSymTable();
}

const initialArray(int symIndex, char itemName[50], char scope[50], int arrayLength)
{

	for (int i = 0; i < arrayLength; i++)
	{
		printf("\n\n\nAdding size:%d to sym table, for array\n\n", arrayLength);
		// addItemArray(itemName, "null", "array", i, itemName);
		//  strcpy(symTabItems[i].itemKind, ",");
		addItemArray(itemName, "null", "array", 0, scope);
	}
	// printf("Adding new Array To %s with value %s\n", itemName, itemValue);
	// strcpy(symTabItems[i].itemKind, "0");
}

const addItem(char itemName[50], char itemKind[8], char itemType[8], int arrayLength, char scope[50])
{

	// what about scope? should you add scope to this function?
	symTabItems[symTabIndex].itemID = symTabIndex;
	strcpy(symTabItems[symTabIndex].itemName, itemName);
	strcpy(symTabItems[symTabIndex].itemKind, itemKind);
	strcpy(symTabItems[symTabIndex].itemType, itemType);
	symTabItems[symTabIndex].arrayLength = arrayLength;
	strcpy(symTabItems[symTabIndex].scope, scope);
	symTabIndex++;
	if (arrayLength > 0)
	{
		char indexNum[5], arrayPosition[10];
		sprintf(indexNum, "%d", symTabIndex - 1);
		for (int i = 0; i < arrayLength; i++)
		{
			sprintf(arrayPosition, "%d", i);
			addItem(itemName, indexNum, arrayPosition, 0, arrayPosition);
			showSymTable();
		}
	}
}

int found(char itemName[50], char scope[50])
{
	// Lookup an identifier in the symbol table
	// what about scope?
	// return TRUE or FALSE
	// Later on, you may want to return additional information

	// Dirty loop, becuase it counts SYMTAB_SIZE times, no matter the size of the symbol table
	for (int i = 0; i < SYMTAB_SIZE; i++)
	{
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		// printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope, scope);
		// printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if (str1 == 0 && str2 == 0)
		{
			return 1; // found the ID in the table
		}
	}
	return 0;
}

const char *getIdByItemName(char itemName[50], char scope[50])
{
	for (int i = 0; i < SYMTAB_SIZE; i++)
	{
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		// printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope, scope);
		// printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if (str1 == 0 && str2 == 0)
		{
			return symTabItems[i].itemID; // found the ID in the table
		}
	}
	return NULL;
}

const newItemKind(char itemName[50], char itemKind[8], char scope[50])
{
	for (int i = 0; i < SYMTAB_SIZE; i++)
	{
		if (strcmp(symTabItems[i].itemName, itemName) == 0 && found(itemName, scope) == 1)
		{

			printf("Adding new assignment To %s with value %s\n", itemName, itemKind);
			strcpy(symTabItems[i].itemKind, itemKind);
			showSymTable();
		}
	}
}

const assignArray(char itemName[50], char arrayPosition[5], char value[50])
{
	for (int i = 0; i < SYMTAB_SIZE; i++)
	{

		if (strcmp(symTabItems[i].itemName, itemName) == 0 && strcmp(symTabItems[i].itemType, arrayPosition)== 0)
		{
			printf("\n\n\nFound position in array %s ", itemName);

			printf("Adding new assignment To %s at position %d with value %s\n", itemName, arrayPosition, value);
			strcpy(symTabItems[i].itemKind, value);
			showSymTable();
		}
	}
}
const char *iterationKind(char itemKind[8], char scope[50])
{
	for (int i = 0; i < SYMTAB_SIZE; i++)
	{
		if (strcmp(symTabItems[i].itemKind, "Var") == 0)
		{

			printf("Adding new assignment To %s with value %s\n", symTabItems[i].itemName, itemKind);
			strcpy(symTabItems[i].itemKind, itemKind);
			showSymTable();

			return symTabItems[i].itemName;
		}
	}
}

const char *getVariableType(char itemName[50], char scope[50])
{
	// char *name = "int";
	// return name;

	for (int i = 0; i < SYMTAB_SIZE; i++)
	{
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		// printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope, scope);
		// printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if (str1 == 0 && str2 == 0)
		{
			return symTabItems[i].itemType; // found the ID in the table
		}
	}
	return NULL;
}

const char *getVariableValue(char itemName[50], char scope[50])
{
	for (int i = 0; i < SYMTAB_SIZE; i++)
	{
		int str1 = strcmp(symTabItems[i].itemName, itemName);
		// printf("\n\n---------> str1=%d: COMPARED: %s vs %s\n\n", str1, symTabItems[i].itemName, itemName);
		int str2 = strcmp(symTabItems[i].scope, scope);
		// printf("\n\n---------> str2=%d: COMPARED %s vs %s\n\n", str2, symTabItems[i].itemName, itemName);
		if (str1 == 0 && str2 == 0)
		{

			return symTabItems[i].itemKind; // found the ID in the table
		}
	}
	return NULL;
}
int compareTypes(char itemName1[50], char itemName2[50], char scope[50])
{
	const char *idType1 = getVariableType(itemName1, scope);
	const char *idType2 = getVariableType(itemName2, scope);

	printf("%s = %s\n", idType1, idType2);

	int typeMatch = strcmp(idType1, idType2);
	if (typeMatch == 0)
	{
		return 1; // types are matching
	}
	else
		return 0;
}