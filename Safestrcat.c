#Anna Teng 10061146
#Henry Wang 10199252
#Katherine Le 10188031
#Marshall Ruse 10066247 

#include <string.h>
#include <stdio.h>

char* safestrcat(char *a, char *b) {
  char *a[100];
  fgets(*a, 100, stdin);     // sets character limit to 100
  printf("Enter a string: ");
  scanf("%[^\n]s",*a);
  
  char *b;
  fgets(*b, 100, stdin);     // sets character limit to 100
  printf("Enter another string: ");
  scanf("%[^\n]s",*b);
  return strcat(char *a, char *b);
}
