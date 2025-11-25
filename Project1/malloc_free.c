#include <stdio.h>
#include <malloc.h>

void Test() {
	short* p = (short*)malloc(100); // 200바이트 할당
	free(p);
}

int main(void) {
	int i;
	for (i = 0; i < 100; i++)Test();

	return 0;
}