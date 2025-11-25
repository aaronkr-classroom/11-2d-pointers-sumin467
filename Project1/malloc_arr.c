#include <stdio.h>
#include <malloc.h>

int main(void) {
	int* p_num_list,
		count = 0,
		sum = 0,
		limit =0,
		i;

	printf("최대 개수를 입력: ");
	scanf_s("%d", &limit);
	//최대개수 입력 받고 중간에 9999오면 종료
	p_num_list = (int*)malloc(sizeof(int) * limit);

	while (count < limit) {
		printf("숫자 입력 (9999 누르면 종료): ");
		//scanf_s("%d", &num[count]);
		scanf_s("%d", p_num_list + count);

		if (*(p_num_list + count) == 9999)break;

		count++;
	}
	for (i = 0; i < count; i++) {
		if (i > 0) printf(" + ");
		printf("%d", *(p_num_list + i));
		sum = sum + *(p_num_list + i);
	}
	printf(" = %d\n", sum);
	free(p_num_list);

	return 0;
}