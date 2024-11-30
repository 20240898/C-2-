#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main() {
    int number[SIZE];
    int temp;
    srand(time(NULL));

    // 배열 초기화
    for (int i = 0; i < SIZE; i++) {
        number[i] = (rand() % 100) + 1;
    }

    // 버블 정렬 (내림차순)
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (number[j] < number[j + 1]) {  // 내림차순
                temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < SIZE; i++) {
        printf("%5d\t", number[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }

    return 0;
}
