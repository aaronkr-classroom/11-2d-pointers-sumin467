#include <stdio.h>

int main(void) {
	short data = 3,
		* p = &data,//data 변수 주소
		** pp = &p;//포인터 p의 주소
	printf("[Before ] data: %d\n", data);
	*p = 40;
	printf("[Use *p ] data: %d\n", data);
	**pp = 500;
	printf("[Use **pp] data: %d\n", data);

	return 0;
}