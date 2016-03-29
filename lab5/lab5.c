#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mark {
	int x;
	int y;
};

typedef struct Mark Mark;

/* load the structure that p points to with the date from f */
void getInfo (FILE * f, Mark * p);

/* write the data stored in structure item into output file f */
void printInfo (FILE * f, Mark item);

/* compare what pointers a and b point to; to be used by qsort() */
int compare (const void * a, const void * b);

int main()
{
	Mark list[100];
	Mark mark;
	int size = 0, i, col = 0;
	FILE * fin;

	fin = fopen ("lab5.dat", "r");
	if ( fin == NULL )
	{
		printf ("Cannot open file.\n");
		exit(1);
	}

	while ( !feof(fin) )
	{
		getInfo (fin, &mark);
		list[size++] = mark;
	}

	// use qsort() to sort data in list
	qsort(list, size, sizeof(Mark), compare);

	for (i = 0; i < size; i++)
	{
		printInfo (stdout, list[i]);
		if ( ++col % 5 == 0 )
			printf("\n");
	}
	
	printf("\n");

	fclose (fin);

	return 0;
}

/* complete the following helper functions */

void getInfo (FILE * f, Mark * p)
{
	fscanf(f, "%d %d", &(p->x), &(p->y));
/*
	char str[10];
	char *stringSplit;
	char token[2] = " ";
	
	fgets(str, 10, f);
	stringSplit = strtok(str, token);
	p->x = atoi(stringSplit);
	stringSplit = strtok(NULL, token);
	p->y = atoi(stringSplit);
*/
}

void printInfo (FILE * f, Mark item)
{
	// display each mark in format of (x, y) 
	// and five marks per line 
	fprintf(f, "(%i, %i)", item.x, item.y);
}

int compare (const void * a, const void * b){
	if(((Mark*)b)->y == ((Mark*)a)->y) {
		return ((Mark*)b)->x - ((Mark*)a)->x;
	} else {
		return ((Mark*)b)->y - ((Mark*)a)->y;
	}
}


