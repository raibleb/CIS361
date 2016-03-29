#include <stdio.h>

void swap(char **p, char **q);

int main() {
	char s[5] = "abc";
	char t[5] = "xyz";
	printf("%s\t%s\n", s, t);
	swap(&s, &t);
	printf("%s\t%s\n", s, t);
}

void swap(char **p, char **q) {
	char * temp;
	temp = p;
	p = q;
	q = temp;
}
