#include <stdio.h>

#define MAX_CH 25

int getMyStr(char buffer[], int limit) {

	int i = 0;
	int ch; 



	while ((ch = getchar()) != '\n' && ch != E0F) {

		if (i < limit - 1) {

			buffer[i++] = (char)ch;


		}
		else {

			while (getchar() != '\n' && getchar() != E0F);
			buffer[i] = '\0';
			return 0;


		}
	}





	return 1; 




}

int main(void) {


	char input_str[MAX_CH];
	int state;

	printf("Enter text (max %s char ) : \n", );
	state = getMyStr(input_str, MAX_CH);

	if (state) printf("input : %s \n", input_str);
	else printf("input : %s -> out of range \n", input_str);


	return 0;
}