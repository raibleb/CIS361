#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *myString = "Here is a string.";
	printf("%p\n", myString);
	printf("%p\n", &myString);
	return 0;
}
