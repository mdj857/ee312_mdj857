#include <stdio.h>
#define LOWER_CASE_ASCII_SHIFT 97
#define UPPER_CASE_ASCII_SHIFT 65

/*
 * return 1 if the ASCII interpretation of 
 * c is an upper case letter.  
 * return 0 otherwise
 */
int isUpperCase(char c) {
	if (c >= 'A' && c <= 'Z') {
		return 1; 
	} else {
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
	} else {
		return 0;
	}
}

/*
 * return 1 c is an Alphabet.  
 * return 0 otherwise
 */
int isAlphabet(char c){
	return isUpperCase(c) || isLowerCase(c);
}

/*
 * if the ASCII interpretation of c is a letter, then
 * return a number between 0 and 25 indicating which letter of 
 * the alphabet c represents.  For example, if c is the ASCII
 * encoding for 'A', then we should return 0.  If c is the
 * ASCII encoding for 'e', then we should return 4.
 * if the ASCII interpretation of c is not a letter, then
 * return -1.
 */
int ASCII2Int(char c) {
	if (isUpperCase(c)) {
		return c - 'A';
	} else if (isLowerCase(c)) {
		return c - 'a';
	} else { 
		return -1;
	}
}

/*
* assumes i is between 0 and 25 inclusive
*/
char int2UpperCase(int i){
	char c = 'A'+i;
	return c;
}

/*
* assumes i is between 0 and 25 inclusive
*/
char int2LowerCase(int i){
	char c = 'a'+i;
	return c;
}

/*
* This function takes in a message and computes the frequencies of all the alphabets
*/
void buildHistogram(char message[], int messageLength, int histogram[], int histogramLength){
	for (int i = 0; i < messageLength; i++) {
		if (ASCII2Int(message[i]) != -1) {	// make sure char is indeed an alphanumeric
			histogram[ASCII2Int(message[i])]++;	// +1 to the histogram array
		}
	}
}

/*
* This function computes the maximum value in an array and returns the index location
* for which the maximum value occured. ?? 0-length array ??
*/

int maxIndex(int myArray[], int arrayLength){
	int max = -1;
	int maxIndex = 0;
	for (int i = 0; i < arrayLength; i++) {
		if (myArray[i] > max) {
			maxIndex = i;		// new index of max
			max = myArray[i];	// new max value
		}
	}
	return maxIndex;		// return index of max value 
}

/*
 * Encrypt the string s using the rotation cypher
 * Each letter in s should be shifted "shift" letters to the 
 * right.  For example, if "shift" is 2, then "a zebra" should be
 * changed to "c bgdtc".  Note that when shifting past the end
 * of the alphabet, we wrap around again to a.
 *
 * Only change the letters in s.  Do not change spaces, punctuation
 * or numbers in s.  
 * For full credit, you should keep upper case letters as 
 * upper case, and leave lower case letters as lower case.  So, if
 * s had been the string "a ZeBra", you should change s to be
 * "c BgDtc".
 */
void encrypt(char message[], int messageLength, int shift) {
	for (int i = 0; i < messageLength; i++) {
			if (isLowerCase(message[i])) {
				message[i] = (message[i] + shift - LOWER_CASE_ASCII_SHIFT) % 26 + LOWER_CASE_ASCII_SHIFT;
			}
			else if(isUpperCase(message[i])) {
				message[i] = (message[i] + shift  - UPPER_CASE_ASCII_SHIFT) % 26  + UPPER_CASE_ASCII_SHIFT;
			}
		
	}		
}

/*
 * return a number between 0 and 25 indicating which letter
 * of the alphabet is most common in the string s
 */
int mostFrequentLetter(char message[], int messageLength) {
	int hist[26] = { 0 };  //initialize histogram array  
	buildHistogram(message, messageLength, hist, 26); // builds frequency histogram
	return maxIndex(hist, 26);		// returns maxIndex of most frequent alphbetical char
	}

/*
* Decrypts Message
*/
void decrypt(char cypher[],int cypherLength, int common) {
	int mostFrequentCypher = mostFrequentLetter(cypher, cypherLength);

	

	// max index stuff 
	//int max = -1;
	//int maxIndex = 0;
	//for (int i = 0; i < 26; i++) {
		//if (histo[i] > max) {
			//maxIndex = i;		// new index of max
			//max = histo[i];		// new max value
		//}
		//else if (histo[i] == max){		// case of two or more max appearing chars 
			//for (int j = 0; i < cypherLength; i++) {	// need to look for first instance of max char 

			//}
		//}
	//}
	 



	int shiftToDecode = (common - mostFrequentCypher + 26) % 26;	 
	encrypt(cypher, cypherLength, shiftToDecode);
	

}


