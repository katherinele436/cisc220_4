#include <stdio.h>

#include <string.h>

#include <stdlib.h>




int main(int argc, char **argv)

{

	FILE *fp = fopen(argv[1],"r+");

	char buff[10000], newBuff[10000];

	while (1) {

		fgets(buff, 10000, fp);

		if ( feof(fp) ) {

			break;

		}

		printf("%s",buff);

	}

	fclose(fp);

	return 0;

}
