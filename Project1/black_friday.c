#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int main(void) {
	int*** inventory;

	int stores = 2;
	int depts = 3;
	int itmes = 4;
	printf("======== BLACK FRIDAY INVENTORY SYSTEM ==========\n\n");
	inventory = (int***)malloc(stores * sizeof(int**));
	for (int i = 0; i < stores; i++) {
		inventory[i] = (int**)malloc(depts * sizeof(int*));
	}
	printf("[단계 2] 각 매장의 부서 (2 * 3 = 6 포인터)\n");

	for (int i = 0; i < stores; i++) {
		for (int j = 0; j < depts; j++) {
			inventory[i][j] = (int*)malloc(itmes * sizeof(int));
		}
	}
	printf("[단계 3] 각 부서의 항목 할당 (2 * 3 * 4 =24 포인터)\n");
	printf("총 메모리: 24 * %lu bytes = %lu bytes\n\n",
		sizeof(int), 24 * sizeof(int));

	int sample_prices[2][3][4] = {
		{
			{299,149,79,199},
			{38,59,29,49},
			{89,129,49,59}
		},
		{
			{ 329,159,89,179 },
			{35,55,25,45},
			{99,119,59,69}
		}
	};
	for (int i = 0; i < stores; i++) {
		for (int j = 0; j < depts; j++) {
			for (int k = 0; k < itmes; k++) {
				inventory[i][j][k] = sample_prices[i][j][k];
			}
		}
	}

	printf("========= Inventory Data ======\n\n");

	char* dept_names[] = { "Electronics","Clothing","Home" };

	for (int i = 0; i < stores; i++) {
		printf("[Store %d]\n", i + 1);
		for (int j = 0; j < depts; j++) {
			printf("-$s:", dept_names);
			for (int k = 0; k < itmes; k++) {
				printf("$%d ", inventory[i][j][k]);
				inventory[i][j][k] = sample_prices[i];
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("========= FREEING MEMORY ======\n\n");
	for (int i = 0; i < stores; i++) {
		for (int j = 0; j < depts; j++) {
			free(inventory[i][j]);
			printf("[해제] 매장 %d, 부서 %d의 항목 배열 해제\n",
				i+1,j+1);
		}
	}
	printf("\n");

	for (int i = 0; i < stores; i++) {
			free(inventory[i]);
			printf("[해제] 매장 %d, 부서 배열 해제\n",
				i + 1);
	}
	printf("\n");

	free(inventory);
	printf("[해제] 매장 배열 해제\n");
	printf("모든 메모리가 해제되었습니다\n");

	return 0;
}