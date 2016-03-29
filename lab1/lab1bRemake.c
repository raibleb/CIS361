#include <stdio.h>
#include <ctype.h>

int main() {
	char c;
	int wordCount, avgLength;
	int state = 0; //0 = space, 1 = word, 2 = other
	printf("Enter a sequence of characters. Ctrl+D to quit.\n");
	while(c = getchar(), c != EOF) {
		switch(state) {
			case 0: if (isalnum(c)) {
					wordCount++;
					avgLength++;
					state = 1;
				} else if (!isspace(c)) {
					state = 2;
				}
				break;
			case 1: if (isalnum(c)) {
					avgLength++;
				} else if (isspace(c)) {
					state = 0;
				} else {
					state = 2;
				}
				break;
			default: if(isspace(c)) {
					state = 0;
				 }
		}
	}
	avgLength = avgLength/wordCount;
	printf("Words: %d\nAverage length of words: %d\n", 
		wordCount, avgLength);
	return 0;
}
