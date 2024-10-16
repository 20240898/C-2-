/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int a = 0;
    float insum=0;
    float sellsum = 0;
    int in_num[100];
    int out_num[100];
    int inventory[100];
    float selling=0;
    int ID;
    int min;
    int minroom=1;
    int max;
    int maxroom=1;
    printf("1~100까지의 상품 개수 입력Enter>\n");
    scanf("%d",&a);
    /*판매수량 합*/
    for(int i=0;i<a;i++){
        printf("상품별 입고수량 입력Enter>\n");
        int b = 0;
        scanf("%d",&b);
        insum += b;
        in_num[i]=b;
        }
        
    for(int j=0;j<a;j++){
        printf("상품별 판매수량 입력Enter>\n");
        int c = 0;
        scanf("%d",&c);
        sellsum += c;
        out_num[j] = c;
        }
    
    for(int h=0;h<a;h++){
        inventory[h] = in_num[h]-out_num[h];
        }
    
    for (int i = 0; i < a; i++) {
            if (max < out_num[i]) {
                max = out_num[i];
				maxroom = i+1;
			}
		}
	 for (int i = 0; i < a; i++) {
			if (out_num[i] < min ) {
				min = out_num[i];
				minroom = i+1;
			}
		} 
    if (insum != 0) {
        selling = (sellsum / insum) * 100;}
    //selling = (sellsum/insum)*100;
    
    printf("재고수량: ");
    
    for(int h=0;h<a;h++){
       printf("%d ",inventory[h]);
    }
   
    
    printf("\n");
    printf("총 판매량 : %f(판매율:%f%%)\n",sellsum, selling);
    printf("가장 많이 판매된 상품 : ID %d, 판매량 %d\n", maxroom, max );
    printf("가장 적게 판매된 상품 : ID %d, 판매량 %d\n", minroom, min );
    
     for (int h = 0; h < a; h++) {
			if (inventory[h] <= 2 ) {
			    int invent_ID=0;
                int invent_shortage=0;
				invent_shortage = inventory[h];
				invent_ID = h+1;
				printf("상품 ID %d:재고부족(%d)\n",invent_ID,invent_shortage);
			}
		} 
		
    return 0;
    }
