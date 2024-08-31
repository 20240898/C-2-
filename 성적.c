#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
int main() 
	{
		int number[SIZE];
		int total = 0;
		int max;
		int maxroom;
		float avg = 0.0;
		srand(time(NULL));
		for (int i = 0; i < SIZE; i++) {
			number[i] = (rand() % 100) + 1;
		}
		for (int i = 0; i < SIZE; i++) {
			printf("%3d\t", number[i]);
			if ((i + 1) % 10 == 0) printf("\n");
        }
		for (int i = 0; i < SIZE; i++) {
			total += number[i];
		}
		avg = (float)total / SIZE;
		max = number[0];
		min = number[0];
		maxroom = 0;
		for (int i = 1; i < SIZE; i++) {
			if (max < number[i]) {
				max = number[i];
				maxroom = ++i;
			}
			
		}
		printf("avg = %f, max = %d, min = %d, maxroom = %d ", avg, max, min,maxroom);
		return 0;
	}
