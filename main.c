
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

  int from = 3;
  int n = 10;
	char *a = "A string ";
	char *b = "and a second string";
  char *source ="A string with many characters"
  char *c;
  char *c = safeststrcat(a,b);
  printf("Result of safeststrcat: %s\n", c);
  char target[strlen(source)];
  substring(source, from, n, target);
  printf("Result of substring: %s\n", target);
  
  
