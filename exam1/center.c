/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Returns a heap-allocated string with length n, with
// the given string in the middle, surrounded by fillchar.
//
// For example, if s is allen, n is 10 and fillchar is .
// the result is ..allen... 

char *center(char *s, int n, char fillchar)
{
    char *result;
    
    int remaining = n;
    int i = 0;
    int j;
    
    result = malloc(n * sizeof(char));
    
    
    while(remaining-1 > strlen(s)){   
    	result[i] = fillchar;
		remaining--;
		
	    result[n-i-1] = fillchar;
    	remaining--;
		
		i++;
    }
    
    for (j=0; j<strlen(s); j++) {
    	result[i+j] = s[j];
    }

	result[i+j] = fillchar;  
      
    return result;
    
}


int main (int argc, char *argv[])
{
    char *s = center("Software", 30, '.');
    printf("%s\n", s);

    char *s2 = center("Systems", 31, '-');
    printf("%s\n", s2);

    char *s3 = center("Spring 2014", 32, '*');
    printf("%s\n", s3);

    char *s4 = center("Exam 1", 33, '^');
    printf("%s\n", s4);

    return 0;
}
