#include <stdio.h>
void generateAllMatchedParens(int n);
void generateAllPalindromicDecompositions(char str[]);
int isPalindrome(char str[], int beginning, int end);
int main() {
//	isPalindrome("ABAA", 1, 3);
	generateAllPalindromicDecompositions("malayalam");
	//generateAllMatchedParens(5);
	getchar();
}