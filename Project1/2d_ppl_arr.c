#include <stdio.h>

int main(void) {
    int ages, member, temp;
    unsigned char limit_table[3] = { 4, 2, 3 };   // 20대=4명, 30대=2명, 40대=3명
    unsigned char count[3][4];

    // 데이터 입력
    for (ages = 0; ages < 3; ages++) {
        printf("\n%d0대 참가자 입력:\n", ages + 2);  // ages=0 → 20대, ages=1 → 30대, ages=2 → 40대
        for (member = 0; member < limit_table[ages]; member++) {
            printf("member #%d: ", member + 1);
            scanf_s("%d", &temp);
            count[ages][member] = (unsigned char)temp;
        }
    }

    // 평균 출력
    printf("\n\n연령별 평균 윗몸 일으키기 횟수\n");
    for (ages = 0; ages < 3; ages++) {
        int sum = 0;
        for (member = 0; member < limit_table[ages]; member++) {
            sum += count[ages][member];
        }
        double avg = (double)sum / limit_table[ages];
        printf("%d0대 평균: %.2f\n", ages + 2, avg);
    }

    return 0;
}
