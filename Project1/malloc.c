#include <stdio.h>
#include <malloc.h>

int main(void) {
	char* p_name;
	p_name = (char*)malloc(20);
	if (p_name != NULL) {//메모리 할당
		while (1) {
			printf("Enter your name: >> ");
			gets(p_name);

			if ((int)p_name == 0) break;

			printf("Hi %s\n", p_name);
		}
			//p_name 동적 할당 메모리 해제
		free(p_name);
	}
	else {
		printf("Error: Memory allocation error!");
	}
	return 0;
}