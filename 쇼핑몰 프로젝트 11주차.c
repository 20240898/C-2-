#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int menu = 0;
    int ids = 0, input = 0, output = 0;
    int quantity = 0;
    int price = 0;
    int ID[5][100];
    int ALLjeogo = 0;
    int ALLpanmea = 0;
    float ALLpanmeayul = 0;
    int ALLepgo = 0;
    int totalOutprice = 0;
    int max = 0;
    int maxID;
    int min = 1000;
    int minID;
    char* maxroomname = "없음";
    char* minroomname = "없음";
    char ID_name[5][100] = { "" };
    char date[11]; // 날짜 입력받기 위한 문자열


    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 5; i++) {
            ID[j][i] = 0;
        }
    }

    do {
        printf("원하는 메뉴를 선택하세요.(1. 입고, 2. 판매, 3. 개별현황. 4. 전체현황. 5. 상품정보저장. 6.상품정보 불러오기.7종료): ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            system("cls");
            printf("상품 ID: ");
            scanf("%d", &ids);
            int i;
            for (i = 0; i < 5; i++)
            {

                if (ID[i][0] == ids && ID[i][0] != 0)
                {
                    printf("입고량: ");
                    scanf("%d", &quantity);
                    ID[i][1] += quantity;
                    printf("판매가격: ");
                    scanf("%d", &price);
                    ID[i][3] = price;
                    break;
                }
                else if (ID[i][0] == 0)
                {
                    ID[i][0] = ids;
                    printf("상품명: ");
                    scanf("%s", ID_name[i]);
                    printf("입고량: ");
                    scanf("%d", &quantity);
                    ID[i][1] += quantity;
                    printf("판매가격: ");
                    scanf("%d", &price);
                    ID[i][3] = price;

                    break;
                }




            }
            if (i == 5)
            {
                printf("상품의 갯수를 초과하였습니다\n");
            }

            break;
        case 2:
            system("cls");
            printf("상품 ID: ");
            scanf("%d", &ids);
            for (i = 0; i < 5; i++)
            {
                if (ID[i][0] == ids) {
                    printf("판매 수량 :");
                    scanf("%d", &output);
                    ID[i][2] = output;
                    break;
                }


            }
            if (ID[i][0] != ids) {
                printf("ID가 잘못 입력되었습니다.\n");
            }
            ALLpanmea += ID[i][2];
            ALLepgo += ID[i][1];
            ALLpanmeayul = ((float)ALLpanmea / ALLepgo) * 100;
            break;


        case 3:
            system("cls");
            printf("상품 ID: ");
            scanf("%d", &ids);
            for (i = 0; i < 5; i++)
            {
                if (ID[i][0] == ids)
                {
                    printf("ID :%d\n", ID[i][0]);
                    printf("상품명 : %s\n", ID_name[i]);
                    printf("상품가격 :%d\n", ID[i][3]);
                    printf("입고량 :%d\n", ID[i][1]);
                    printf("판매량 :%d\n", ID[i][2]);
                    totalOutprice = 0;
                    totalOutprice = ID[i][2] * ID[i][3];

                    printf("ID: %d 의 판매금액 :%d\n", ids, totalOutprice);
                    break;
                }
            }   if (i == 5)
            {
                printf("ID가 잘못 입력되었습니다.\n");
            }

            break;

        case 4:
            system("cls");
            for (i = 0; i < 5; i++) {
                ALLjeogo += ID[i][1] - ID[i][2];
                
                
                if (max < ID[i][2])
                {
                    max = ID[i][2];
                    maxroomname = ID_name[i];
                    maxID = i + 1;
                }
                if (ID[i][2] < min && ID[i][2]>0)
                {
                    min = ID[i][2];
                    minroomname = ID_name[i];
                    minID = i + 1;
                }
                else if (ID[i][2] <= 0)
                {
                    ID[i][2] = 0;
                }

            }
            if (min == 1000) {
                minroomname = "없음";
            }
            
            printf("재고수량: ");
            for (int i = 0; i < 5; i++)
            {
                printf("%d ", ID[i][1] - ID[i][2]);
            }

            printf("\n");
            printf("총 판매량 : %d(판매율:%0.2f%%)\n", ALLpanmea, ALLpanmeayul);
            printf("가장 많이 판매된 상품 : ID %d, 상품명:%s, 판매량 %d\n", maxID, maxroomname, max);
            printf("가장 적게 판매된 상품 : ID %d, 상품명:%s, 판매량 %d\n", minID, minroomname, min);
            for (int h = 0; h < 5; h++) {
                if (ID[h][1] - ID[h][2] <= 2)
                {
                    int buzok_ID = 0;
                    char* buzok_name;
                    int buzokjeago = 0;
                    buzok_ID = h + 1;
                    buzok_name = ID_name[h];
                    buzokjeago = ID[h][1] - ID[h][2];
                    printf("상품 ID %d: 상품명: %s 재고부족(%d)\n", buzok_ID, buzok_name, buzokjeago);
                }
            }
            break;
        case 5: // 상품 정보 저장하기
            system("cls");
            printf("저장할 날짜를 입력하세요 (YYYY-MM-DD 형식): ");
            scanf("%s", date);

            char filename[20];
            snprintf(filename, sizeof(filename), "%s.txt", date);

            FILE* fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("파일을 열 수 없습니다.\n");
                break;
            }

            // 개별 현황 저장
            for (int i = 0; i < 5; i++) {
                if (ID[i][0] != 0) {
                    fprintf(fp, "ID: %d, 이름: %s, 입고량: %d, 판매량: %d, 가격: %d\n",
                        ID[i][0], ID_name[i], ID[i][1], ID[i][2], ID[i][3]);
                }
            }

            // 전체 현황 저장
            fprintf(fp, "총 판매량: %d, 판매율: %.2f%%\n", ALLpanmea, ALLpanmeayul);

            fclose(fp);
            printf("상품 정보를 %s에 저장했습니다.\n", filename);
            break;

        case 6: // 상품 정보 불러오기
            system("cls");
            printf("불러올 날짜를 입력하세요 (YYYY-MM-DD 형식): ");
            scanf("%s", date);

            snprintf(filename, sizeof(filename), "%s.txt", date);
            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("해당 날짜의 파일이 없습니다.\n");
                break;
            }

            printf("파일 내용을 불러옵니다:\n");
            char line[200];
            while (fgets(line, sizeof(line), fp)) {
                printf("%s", line);
            }

            fclose(fp);
            break;
        case 7:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다.\n");
            system("cls");
            break;
        }
    } while (menu != 7);

    return 0;
}
