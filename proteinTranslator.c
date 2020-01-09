/*

Name: Aryan Timla
Collab: Matthew Mai
Date: 11/04/2019
Objective: This program takes two command line arguments; the first is an input file
containing a DNA sequence, and the second is the name of the output file in which you'll
place the translated protein sequence

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "protein_utils.h"

//Declare functions used in program
void removeChar(char *s, char c);
char *DNAstuffs(const char *filePath);
char *clonegetsFileContents(const char *filePath);

int main(int argc, char **argv) {

	char *ans = DNAstuffs(argv[1]);
	removeChar(ans, '\n');
	FILE *outputFile = fopen(argv[2], "w");
	char vic[3];
	char tor = NULL;
	int n = 0;
	int i;

	for (i = 0; i < strlen(ans); i++) {
		vic[n] = ans[i]; n++;
		if (n == 3) {
			n = 0;
			tor = rnaToProtein(vic);
			if (tor == 'x') {
				break;
			}
			fprintf(outputFile, "%c\n", tor);
			if (tor == 'x') {
				break;
			}
		}
	}
	fclose(outputFile);

	return 0;
}

char *DNAstuffs(const char *filePath) {

	char *stuff = clonegetsFileContents(filePath);
	int i;

	for (i = 0; i < strlen(stuff); i++) {
		if (stuff[i] == 'T') {
			stuff[i] = 'U';
		}
	}

	return stuff;
}

char *clonegetsFileContents(const char *filePath) {

	FILE *file = fopen(filePath, "r");
	if (file == NULL) {
		return NULL;
	}

	char *fileString = (char *)malloc(sizeof(char) * 100000);
	char buffer[100000];

	while(fgets(buffer, 100000, file) != NULL) {
		strcat(fileString, buffer);
	}
	fclose(file);

	return fileString;
}

void removeChar (char *s, char c) {

	if (s == NULL) {
		return;
	}

	int i;
	for (i = 0; i < strlen(s); i++) {
		int j;
		if (s[i] == c) {
			for (j = i; j < strlen(s); j++) {
				s[j] = s[j + 1];
			}
			j = i;
			while (s[j] == c) {
				for (j = i; j < strlen(s); j++) {
					s[j] = s[j + 1];
				}
			}
		} else if (s[i] == '\0') {
			for (j = i; j < strlen(s); j++) {
				s[j] = '\0';
			}
		}
	}

	return;
}
