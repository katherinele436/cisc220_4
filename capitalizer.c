#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include<ctype.h>


int main(int argc, char *argv[]) {
FILE *fp;
char string[255];
fp = fopen(argv[1], "r+");
long pos = ftell(fp);
while(fgets(string, 255, fp) != NULL) {
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
	fseek(fp, pos, SEEK_SET);
	fprintf(fp, "%s", string);
	fflush(fp);
	pos = ftell(fp);
}
fclose(fp);
return 0;
}
