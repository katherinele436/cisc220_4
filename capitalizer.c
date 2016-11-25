#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include<ctype.h>


int main( int argc, char *argv[]) {
FILE *file;
char string[255];
file = fopen(argv[1], "r+");
long pos = ftell(file); 
	
if (file == NULL) {
    fprintf(stderr, "Fail to open poem.txt\n");
    exit(EXIT_FAILURE);
}
while(fgets(string, 255, file) != NULL) {
	int i;
	int numWord = 1;
	int size = strlen(string);
	string[0] = toupper(string[0]);
	for (i=1 ; i < size ; i++) {
		if (isalpha(string[i]) && string[i-1] == ' '){
			if ((numWord % 2) == 0) {
			string[i] = toupper(string[i]);
			}
			numWord++;
		}
	}
	fseek(file, pos, SEEK_SET);
	fprintf(file, "%s", string);
	fflush(file);
	pos = ftell(file);
}
fclose(file);
return 0;
}
