#include <stdio.h>
void jumhwasick(int jum) {
	int N = jum;
	int A = 1;
	printf("점화식\n");
	for (int i = 1; i <= N; i += 1) {
		printf("%d ", A);
		A += 2;
	}
	printf("\n");
}
void eilbansick(int eil) {
	int T = eil;
	int Y;
	for (int i = 1; i <= T; i += 1) {
		Y = 2 * i - 1;
		printf("%d ", Y);
	}
}
void main() {
	int n;
	int a = 1;
	printf("출력할 항의 개수입력 후 Enter >");
	scanf("%d", &n);
	jumhwasick(n);
	printf("일반식\n");
	eilbansick(n);
	return 0;
}
/*printf 앞 뒤에 따라서 변수를 초기화를 안해도 되는가?
a = 2 * i - 1; 여긴 어떻게 되는건지..*/