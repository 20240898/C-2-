#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int number[10];
	int total;
	int max, min;
	float avg = 0.0;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		number[i] = (rand() % 100) + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%3d\t", number[i]);
		if ((i + 1) % 5 == 0)
		{
			printf("\n");
		}
	}
	return 0;
}
