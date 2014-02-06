/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void print_another_local(){
	int x = 7;
	printf("Adress of local variable in another function is %p\n", &x);
}

void print_local(){
	int x = 5;
	printf("Adress of local variable in function is %p\n", &x);
	print_another_local();
}



int main ()
{
    int local = 5;
    void *p = malloc(128);
    print_local();
	
	void *first = malloc(16);
	void *second = malloc(16);


    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    printf ("Address of p is %p\n", p);
    printf ("Address of first is %p\n", first);
    printf ("Address of second is %p\n", second);
    
    return 0;
}
