// lab3.c - measure execution time of C code

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main ()
{
	const int MaxSize = 25000;
	int i, j, temp;


	// Part one: processing a statically allocated array

	clock_t beginStatic = clock();

	int staticArray[MaxSize];		// declare an array 

	for (i=0; i<MaxSize; i++)		// initialize the array with a
		staticArray[i] = MaxSize-i;	// descending sequence of values

	for (i=0; i<MaxSize-1; i++)		// bubble sort data in the array
		for (j=MaxSize-1; j>i; j--)
			if (staticArray[j-1] > staticArray[j])
			{
				temp = staticArray[j-1];
				staticArray[j-1] = staticArray[j];
				staticArray[j] = temp;
			}

	clock_t endStatic = clock();

	// Part two: processing a dynamically allocated array

	clock_t beginDynamic = clock();
	
	int *dynamicArray;
	dynamicArray = (int*) malloc(MaxSize * sizeof(int));

	for (i = 0; i < MaxSize-1; i++) {
		*(dynamicArray + i) = MaxSize - i;
	}

	for (i = 0; i < MaxSize-1; i++)
		for(j = MaxSize; j > i; j--)
			if(*(dynamicArray + (j-1)) > *(dynamicArray + j)) {
				temp = *(dynamicArray + (j-1));
				*(dynamicArray + (j-1)) = *(dynamicArray + j);
				*(dynamicArray + j) = temp;
			}


	free(dynamicArray);

	clock_t endDynamic = clock();


	// Display the amount of time used for each part above

	printf("Time used for the static section: %.3f seconds\n",
		(double)(endStatic - beginStatic)/CLOCKS_PER_SEC);

	printf("Time used for the dynamic section: %.3f seconds\n",
		(double)(endDynamic - beginDynamic)/CLOCKS_PER_SEC);


	return 0;
}
