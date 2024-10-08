#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MSG_MAIN    "원하는 메뉴를 선택하세요"
#define MSG_MENU0   "1. 입고\n"
#define MSG_MENU1   "2. 판매\n"
#define MSG_MENU2   "3. 상품현황\n"
#define MSG_MENU3   "4. 상품명 입력\n"
#define MSG_MENU4   "5. 종료\n"
#define MSG_EXIT    ":프로그램을 종료합니다."

void printMENU(void) {
    printf(MSG_MENU0);
    printf(MSG_MENU1);
    printf(MSG_MENU2);
    printf(MSG_MENU3);
    printf(MSG_MENU4);
    //printf(MSG_EXIT);
}
int main() {
    int a, b, c = 0;
    float insum = 0;
    float sellsum = 0;
    int in_num[100] = { 0 };
    int out_num[100] = { 0 };
    int inventory[100] = { 0 };
    char ID_name[100][100] = { 0 };
    float selling = 0;
    int ID;
    int min = 1000;
    int minroom = 0;
    char* minname = "없음";
    int max = 0;
    int maxroom = 0;
    char* maxname = "없음";
    int input = 0;
    int ininput = 0;
    int outinput = 0;
    char Name = 0;

    printf("1~100까지의 상품 개수 입력Enter>\n");
    scanf("%d", &a);
    do {
        printMENU();
        scanf("%d", &input);
        system("cls");
        switch (input) {
        case 1:
            printf("1. 전체 상품 입고수량 입력\n ");
            printf("2. 개별 상품 입력 \n");
            scanf("%d", &ininput);
            if (ininput == 1) {
                for (int i = 0; i < a; i++) {
                    printf("상품별 입고수량 입력Enter>\n");
                    int b = 0;
                    scanf("%d", &b);
                    insum += b;
                    in_num[i] += b;
                }
            }
            else if (ininput == 2) {
                printf("상품ID :\n");
                scanf("%d", &ID);
                printf("입고수량:\n");
                ID--;
                scanf("%d", &b);
                insum += b;
                in_num[ID] += b;
            }
            break;
        case 2:
            printf("1. 전체 상품 판매수량 입력\n ");
            printf("2. 개별 상품 입력 \n ");
            scanf("%d", &outinput);
            if (outinput = 1) {
                for (int j = 0; j < a; j++) {
                    printf("상품별 판매수량 입력Enter>\n");
                    scanf("%d", &c);
                    sellsum += c;
                    out_num[j] += c;
                }
            }
            else if (outinput = 2) {
                printf("상품ID :\n");
                scanf("%d", &ID);
                printf("입고수량:\n");
                int c = 0;
                scanf("%d", &c);
                sellsum += c;
                out_num[ID] += c;
            }
            break;
        case 3:
            for (int h = 0; h < a; h++) {
                inventory[h] = in_num[h] - out_num[h];
            }

            for (int i = 0; i < a; i++) {
                if (max < out_num[i]) {
                    max = out_num[i];
                    maxroom = i + 1;
                    maxname = ID_name[i];
                }
            }

            // 최소 판매량 상품 찾기
            for (int i = 0; i < a; i++) {
                if (out_num[i] < min && out_num[i] > 0) { // 판매량이 0보다 큰 경우
                    min = out_num[i];
                    minroom = i + 1;
                    minname = ID_name[i];
                }
            }

            if (min == 1000) {
                minname = "없음";
            }

            if (insum != 0) {
                selling = (sellsum / insum) * 100;
            }
            //selling = (sellsum/insum)*100;

            printf("재고수량: ");

            for (int h = 0; h < a; h++) {
                printf("%d ", inventory[h]);
            }


            printf("\n");
            printf("총 판매량 : %f(판매율:%f%%)\n", sellsum, selling);
            printf("가장 많이 판매된 상품 : ID %d, 상품명:%s, 판매량 %d\n", maxroom, maxname, max);
            printf("가장 적게 판매된 상품 : ID %d, 상품명:%s, 판매량 %d\n", minroom, minname, min);

            for (int h = 0; h < a; h++) {
                if (inventory[h] <= 2) {
                    int invent_ID = 0;
                    int invent_shortage = 0;
                    char* roomname;
                    invent_shortage = inventory[h];
                    invent_ID = h + 1;
                    roomname = ID_name[h];
                    printf("상품 ID %d: 상품명: %s 재고부족(%d)\n", invent_ID, roomname, invent_shortage);
                }
            }
            break;
        case 4:
            for (int i = 0; i < a; i++) {
                printf("ID %d 상품명:", i + 1);
                scanf("%s", ID_name[i]);
                printf("\n");
            }
            break;
        case 5:
            printf(MSG_EXIT);
            break;
        }

    } while (input != 5);
    return 0;
}