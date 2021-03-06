#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 4

char* strnsub (char *p, int n);

int main()
{
	char line[] = "His textbook was bought from that bookstore";  
	char *p1, *p2;

	//set p1 to the beginning of string line;
	p1 = line;
	
	while (*p1 != '\0' ) 	// do not go beyond the null character
	{
		//set p2 to the position immediately after p1
		p2 = p1 + 1;
		
		while ( *p2 !='\0' )	// do not go beyond the null character
		{
			if(strncmp(p1, p2, 4)==0)	
				goto done;	
				
			//advance p2 to the next position
			p2++;
		}

		//advance p1 to the next position
		p1++;
	}

done:	;
	char* strn1 = strnsub(p1, LEN);
	char* strn2 = strnsub(p2, LEN);
	printf ("the first substring: %s\n", strn1);
	printf ("the second substring: %s\n", strn2);
	free(strn1);
	free(strn2);

	return 0;
}


// returns a string with the first n characters of string p

char* strnsub (char *p, int n)
{
	// write function definition here
	char* result = malloc(n * sizeof(char*));
	int i = 0;
	while (i < n) {
		*(result + i) = *(p + i);
		i++;
	}
	*(result + n) = '\0';
	return result;

}
