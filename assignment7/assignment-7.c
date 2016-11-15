#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void privateFunction(int n, int left, int right, int position);
int privateFunc(char str[], int posS1, int posS2);
int isPalindrome(char str[], int beginning, int end);


void generateAllMatchedParens(int n) {
	if (n > 0) {
		privateFunction(n, 0, 0, 0);
	}
}

void privateFunction(int n, int left, int right, int position) {
	static char string[1000];
	if (right == n) {
		printf("%s\n", string);
	}
	else {
		if (left > right) {
			string[position] = ')';
			privateFunction(n, left, right + 1, position + 1);
		}
		if (left < n) {
			string[position] = '(';
			privateFunction(n, left + 1, right, position + 1);
		}
	}
}
/*Determines if subsection of input string is a palindrome.*/
int isPalindrome(char str[], int beginning, int end) {
	char str2[1000] = { 0 }; 
	int j = beginning;
	int k = 0;
	while (j != end +1) {
		str2[k] = str[j];
		k++;
		j++; 
	}
	char substring[1000];
	strcpy(substring, str2);
	return !strcmp(substring, _strrev(str2));
}

void generateAllPalindromicDecompositions(char str[]) {

		privateFunc(str, 0, 0, 0);
		
}

int privateFunc(static char str[], int pos1, int arrayIndex) {
	static char output[1000] = { 0 };
	// BASE CASE 1
	if (pos1 > strlen(str) - 1) {
		printf("%s\n", output); 
		return; 
	}
	// BASE CASE 2
	if (pos1 == strlen(str)-1){
		output[arrayIndex] = str[pos1];
		output[arrayIndex + 1] = '\0';
		printf("%s\n", output);
		output[arrayIndex] = '\0';
		return; 
	}
	for (int i = 1; i < strlen(str)-pos1 +1; i++) {
		char str2[1000] = { 0 };
		for (int j = 0; j < i; j++) {
			str2[j] = str[pos1 + j];
		}
		
		if (isPalindrome(str2, 0, i)) {
			strcat(str2, " ");
			strcat(output, str2);
			privateFunc(str, pos1 +i, arrayIndex + strlen(str2));
			output[arrayIndex] = '\0';
		}
	}

}