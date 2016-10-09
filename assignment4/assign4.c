/*
Johnson, Matthew
EID: mdj857
Unique #: 16290
EE 312 Assignment 4
*/

#include <stdio.h>
#include <string.h>
#define BEGIN_FCN "{\n"
#define END_FCN "}\n"
#define MAX_STR_LEN 500				// max length of input file name and file size 
#define MAX_FILE_LEN 1000			// assume length of file is less than 1000 chars
#define _CRT_SECURE_NO_WARNINGS


/*GLOBALS*/
char clear_array[100] = { '\0' };	// array used to clear line1 and line 2 arrays 
char outputFile[5000] = "File Counting Summary Table\nFilename: ";		// string to be placed in file and displayed on stdout after exection
int numFuncs = 0;					//  total number of functions in input file 
int total_lines = 0;				// total number of input lines in input file 

/*FUNCTION HEADERS*/
int findSemicolons(char func[]);
void getFunctionName(char funcHeader[], char functionName[]);
void appendTable(char functionName[], int lines);


int main() {
	char  inputFile[MAX_FILE_LEN];
		printf("Please enter a file to be processed. Enter STOP to end execution. \n\n");
		scanf("%s", inputFile);
		while (strcmp(inputFile, "STOP") != 0) {
		FILE *fp = fopen(inputFile, "r+");		// opens read-only input file 
		if (fp == NULL) {
			printf("Uhhh...something's wrong. Try another file name.");
		}
		strcat(inputFile, "\n\n");
		strcat(outputFile, inputFile);
		char line1[MAX_STR_LEN];
		char line2[MAX_STR_LEN];
		// looks for first function
		fgets(line1, 500, fp);
		while (strcmp(line1, "EOF\n") != 0) {
			if (strcmp(line1, BEGIN_FCN) != 0) {
				memcpy(line2, line1, 500);
				fgets(line1, 500, fp);
			}
			else {
				char funcName[MAX_STR_LEN] = { '\0' };	// creates empty string for name of function
				char functionBody[1000] = { "\0" };		// creates empty string for function body
				getFunctionName(line2, funcName);
				int flag2 = 1;							// flag2 shows were adding function to function block array 
				while (flag2) {
					fgets(line1, 500, fp);
					if (strcmp(line1, END_FCN) != 0) {
						strcat(functionBody, line1);		// append to function body string
					}
					if (strcmp(END_FCN, line1) == 0) {
						flag2 = 0;
					}
					strcat(functionBody, "");			// adds null char to end of function body string
				}
				int lines_in_function = findSemicolons(functionBody);
				appendTable(funcName, lines_in_function);
			}
		}
		fclose(fp);										// close input stream
		/*Output to File */
		char outputFilename[MAX_FILE_LEN];
		printf("Please enter an output file name.\n");
		scanf("%s", outputFilename);
		FILE *fpOut = fopen(outputFilename, "w+");		// opens output file 
		while (fpOut == NULL) {
			printf("Uhhh...something's wrong. Try another output file name.\n");
			scanf("%s", outputFilename);
			FILE *fpOut = fopen(outputFilename, "w+");		// opens output file 
		}


		/*Output to stdin*/
		char totfunc[10];
		char totlines[10];
		sprintf(totfunc, "%d\n", numFuncs);
		sprintf(totlines, "%d\n", total_lines);
		strcat(outputFile, "\nTotal Functions: ");
		strcat(outputFile, totfunc);
		strcat(outputFile, "\nTotal Lines: ");
		strcat(outputFile, totlines);
		printf("%s", outputFile);				// prints to stdout 
		while (fputs(outputFile, fpOut) == 'EOF') {
			printf("There was an error writing to the output file. Please enter another file name.");
			scanf("%s", outputFilename);
		}
		fclose(fpOut);			// close output stream 
	}
	}
	

// finds number of SLOC in a given function
int findSemicolons(char func[]) {
	int i = 0;
	int semicolons = 0;
	while (func[i] != '\0') {
		if (func[i] == '"') {							// parentheses case
			do {
				i++;
			} while (func[i] != '"');
		}
		if (func[i] && func[i + 1] == '*') {			// comment case
			do {
				i++;
			} while (func[i - 1] != '*' || func[i] != '/');
		}
		if (func[i] == ';') {
			semicolons++; 
		}
		i++;
	}
	return semicolons; 
}
// fills functionName with the name of function in FunctionHeader 
void getFunctionName(char funcHeader[], char functionName[]){
	int i = 0; 
	int ind = 0; 
	int startLet = -1;
	int endLet = -1;
	while (funcHeader[i] != '\0'){
		if (funcHeader[i] == ' ') {
			startLet = i+1;
		}
		if (funcHeader[i] == '(') {	
			endLet = i;
			break;
		}
		i++;
	}
	for (int k = startLet; k < endLet; k++) {
		functionName[ind] = funcHeader[k];
		ind++;
	}

}


/*Changes output string (for stdout and output file) to include additional function*/
void appendTable(char functionName[], int lines ) {
	char* buffer[20];
	sprintf(buffer, "%d\n", lines);
	strcat(outputFile, functionName);
	strcat(outputFile, "\t ");
	strcat(outputFile, buffer);
	numFuncs++; 
	total_lines += lines;
}


// END SOURCE CODE