#include <stdio.h>

int main(void) {


	char c;
	printf("Enter chars to read(@ to stop) >>>");

	//char*filename = 'C:/Windows/Data/file.txt' ; 
	//while(ch = getc(filename) !='E0F')
	printf("버퍼에 남은 문자 : ");
	while ((c = getchar()) != '\n'&&  c != E0F) {

		putchar(c);
	}
	printf("\nEnd of input. \n");


	return 0;
}