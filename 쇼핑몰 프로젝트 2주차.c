/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int number[100];
    int sum;
    printf("1~100까지의 상품의 종류중 하나를 정하고 Enter>\n");
    scanf("%d",&a);
    printf("상품 별 입고수량 입력Enter>\n");
    scanf("%d",&b);
    printf("상품별 판매수량 입력Enter>\n");
    scanf("%d",&c);
    number[a]= b - c ;
    sum = number[a];
    printf("%d의 재고수량은 %d입니다",a, sum);
    
    
    
}
