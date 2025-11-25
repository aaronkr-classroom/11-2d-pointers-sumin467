#include <stdio.h>

#define MAX_COUNT 5 // 최대 입력

int main(void) {
	int num[MAX_COUNT],
		count = 0,
		sum = 0,
		i;
	//최대 5회까지 입력 받고 중간에 9999오면 종료
	while (count < MAX_COUNT) {
		printf("숫자 입력 (9999 누르면 종료): ");
		//scanf_s("%d", &num[count]);
		scanf_s("%d", num + count);
		
		if (num[count] == 9999)break;

		count++;
	}
	for (i = 0; i < count; i++) {
		if (i > 0) printf(" + ");
		printf("%d", num[i]);
		sum = sum + num[i];
	}
	printf(" = %d\n", sum);

	return 0;
}