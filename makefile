#Anna Teng 10061146
#Henry Wang 10199252
#Katherine Le 10188031
#Marshall Ruse 10066247


mystring.o: mystring.c mystring.h
	gcc -Wall -c mystring.c
  
main.o: main.c mystring.h
	gcc -Wall -c main.c
  
copier: main.o mystring.o
	gcc -Wall -o copier mystring.o main.o
