#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

int len1, wid1, len2, wid2;

void matrixFirstPrompt(int matNum){
    printf("\nInsert matrix %d dimensions separated by a space: ", matNum);
    if (matNum == 1){
        scanf("%d %d", &len1, &wid1);
        //counter-intuitvely, this leads to desired outcome (ie. error if not-digit)
        if (isdigit(len1) || isdigit(wid1) ){
        	fprintf(stderr, "Invalid Input\n");
        	exit(-1);
        }
    }
    if (matNum == 2){
        scanf("%d %d", &len2, &wid2);
        if (len2 != wid1){
        	fprintf(stderr, "Dimensions Mismatch\n");
        	printf("Try again: ");
        	scanf("%d %d", &len2, &wid2);
        }
        if (isdigit(len2) || isdigit(wid2)){
        	fprintf(stderr, "Invalid Input\n");
        	exit(-1);
        }
    }
}//end matrixFirstPrompt

void matrixSecondPrompt(int matNum, int **matArray){
    printf("\nInput matrix %d elements:\n ", matNum);
    int length;
    int width;

    if (matNum == 1){
    	length = len1;
    	width = wid1;
    }
    if (matNum == 2){
    	length = len2;
    	width = wid2;
    }
    for (int i = 0; i < length; i++){
    	for (int j = 0; j < width; j++){
    		printf("Row: %d, Element: %d is > ", i+1, j+1);
    		scanf("%d", &matArray[i][j]);
    		if (isdigit(matArray[i][j])){
    			fprintf(stderr, "Invalid Input\n");
    			exit(-1);
    		}
    	}//end inner loop
    }//end outer loop
}//end matrixSecondPrompt

void printMatrix(int matNum, int **matArray){
	int length;
	int width;

	printf("\nMatrix %d", matNum);
	if (matNum == 1){
		length = len1;
		width = wid1;
	}
	if (matNum == 2){
		length = len2;
		width = wid2;
	}
	for (int i = 0; i < length; i++){
		printf("\n");
		for (int j = 0; j < width; j++){
			printf("%d\t", matArray[i][j]);
		}//end inner loop
	}//end outer loop
	printf("\n");
}//end printMatrix

void multiplyMatrices(int **matrix1, int **matrix2){
	int sum = 0;
	int multArray[len1][wid2];

	for (int mat1Row = 0; mat1Row < len1; mat1Row++){
		for (int mat2Col = 0; mat2Col < wid2; mat2Col++){
			for (int mat2Row = 0; mat2Row < len2; mat2Row++){
				sum = sum + (matrix1[mat1Row][mat2Row] * matrix2[mat2Row][mat2Col]);
			}
			multArray[mat1Row][mat2Col] = sum;
			sum = 0;
		}
	}

	printf("Final Output:\n");
	for (int i = 0; i < len1; i++){
		for (int j = 0; j < wid2; j++){
			printf("%d\t", multArray[i][j]);
		}
		printf("\n");
	}

}//end multiplyMatrices

int** createArray(int length, int width){

    int **matArray;
    matArray = (int**) malloc(length * sizeof(int*));
    for (int i = 0; i < length; i++){
        matArray[i] = (int*) malloc(width * sizeof(int));
    }
    return matArray;
}//end createArray

int main()
{
    matrixFirstPrompt(1);
    matrixFirstPrompt(2);

    int** mat1Array = createArray(len1, wid1);
    int** mat2Array = createArray(len2, wid2);

    matrixSecondPrompt(1, mat1Array);
    matrixSecondPrompt(2, mat2Array);

    printMatrix(1, mat1Array);
    printMatrix(2, mat2Array);

    multiplyMatrices(mat1Array, mat2Array);

    free(mat1Array);
    free(mat2Array);
    return 0;
}
