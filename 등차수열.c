#include <stdio.h>
void jumhwasick(int jum) {
	int N = jum;
	int A = 1;
	printf("��ȭ��\n");
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
	printf("����� ���� �����Է� �� Enter >");
	scanf("%d", &n);
	jumhwasick(n);
	printf("�Ϲݽ�\n");
	eilbansick(n);
	return 0;
}
/*printf �� �ڿ� ���� ������ �ʱ�ȭ�� ���ص� �Ǵ°�?
a = 2 * i - 1; ���� ��� �Ǵ°���..*/