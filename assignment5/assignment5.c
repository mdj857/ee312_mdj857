#define _CRT_SECURE_NO_WARNINGS 1 // this #define is for VS2012, which doesn't like the standard C library

/* Johnson, Matthew 
 * EID: mdj857
 * Unique: 16290
 * Programming Assignment 5
 * assignment5.c
 * SpellCheck
 */

#include <stdio.h>	// provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
#include <stdlib.h>
#include <string.h>


//Functions
void findWords(char article[]);
int isUpperCase(char c);
int isLowerCase(char c);
int isAlphabet(char c);
void stringToUpper(char string[]);
char charToUpper(char c);
int checkIfInDictionary(char word[], char dict[]);

/* All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)
 *
 * Many students find it helpful to declare global variables (often arrays). You are welcome to use
 * globals if you find them helfpul. Global variables are by no means necessary for this project.
 */

/* You must write this function (spellCheck). Do not change the way the function is declared (i.e., it has
 * exactly two parameters, each parameter is a standard (mundane) C string (see SpellCheck.pdf).
 * You are expected to use reasonable programming style. I strongly encourage you to avoid big functions
 * (while there are always exceptions, a good rule of thumb is about 15 lines in a function).
 * So, plan on implementing spellCheck by writing two or three other "support functions" that
 * help make the actual spell checking easier for you.
 * There are no explicit restictions on using 
 functions from the C standard library. However,
 * for this project you should avoid using functionality from the C++ standard libary. You will
 * almost certainly find it easiest to just write everything you need from scratch!
 */


//TODO:
void spellCheck(char article[], char dictionary[]) {
	stringToUpper(article);
	stringToUpper(dictionary);		// convert dictionary and article to same typset

	int i = 0;
	while (i < strlen(article)) {
		if (isAlphabet(article[i])) {
			char word[100] = { '\0' };			// create array for single word
			while (isAlphabet(article[i])) {
				char charToStr[2] = { '\0' };					// create empty string
				charToStr[0] = article[i];			// convert char to string
				strcat(word, charToStr);			// put char in to "word"
				i++;
			}
			if (strlen(word) > 1) {		// word must be > 1 char
				strcat(word, "\n");
				if (!checkIfInDictionary(word, dictionary)) {		// search for word in dictionary
					strcat(word, "\n");
					printf("%s", word);
				}
			}
			
		}
		i++;
	}
}



/*
Function checks article to see if given word is present in dictionary. 
Returns 1 if word is in the dictionary, 0 if not. 
*/
int checkIfInDictionary(char word[], char dict[]) {
	int i = 0;
	int length = strlen(word);
	int returnFlag = 0; 
	while (dict[i] != '\0') {
		if (dict[i] != '\n' && dict[i] != '\0') {
			char wordInDict[100] = { '\0' };
			while (dict[i] != '\n' && dict[i] != '\0') {
				char cToStr[2] = { '\0' };			// create empty string
				cToStr[0] = dict[i];				// convert char to string
				strcat(wordInDict, cToStr);			// put char in to "word"
				i++;
			}
			strcat(wordInDict, "\n");
			if (!strcmp(wordInDict, word)) {
				returnFlag = 1; 
				break;
			}
		}
		i++;
	}
	return returnFlag; 
}


/*This function converts the input string to uppercase.*/
void stringToUpper(char string[]){
	int i = 0; 
	while (string[i] != '\0') {
		string[i] = charToUpper(string[i]);
		i++; 
	}
}



/*This function takes a character and returns an uppercase version of the character.
  Assumes input character is indeed an alphabetical character. 
*/
char charToUpper(char c) {
	if (isLowerCase(c)) {
		return c - 32;
	} else {
		return c; 
	}
}
/*
* return 1 if the ASCII interpretation of
* c is an upper case letter.
* return 0 otherwise
*/
int isUpperCase(char c) {
	if (c >= 'A' && c <= 'Z') {
		return 1;
	}
	else {
		return 0;
	}
}

/*
* return 1 if the ASCII interpretation of
* c is a lower case letter.
* return 0 otherwise
*/
int isLowerCase(char c) {
	if (c >= 'a' && c <= 'z') {
		return 1;
	}
	else {
		return 0;
	}
}

/*
* return 1 c is an Alphabet.
* return 0 otherwise
*/
int isAlphabet(char c) {
	return isUpperCase(c) || isLowerCase(c);
}




