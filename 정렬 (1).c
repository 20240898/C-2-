#include <stdio.h>
int exec1(int input) {
    int sum = 0;
    while (1) {
        if (input == -1)break;
        if (input % 2 != 0)continue;
        if (input % 10 == 0)continue;
        sum += input;
        //�ݺ��Ǵ� ���� ��ȯ �Ϸ��� ��� �ؾߵɱ�?
        
    }
    
}
int main()
{
    int sum = 0;
    int input = 0;
    scanf("%d", &input);
    sum = exec1(input);
    printf("sum = %d\n", sum);
    return 0;
}
