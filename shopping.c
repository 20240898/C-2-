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
    char* maxroomname = "����";
    char* minroomname = "����";


    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 5; i++) {
            ID[j][i] = 0;
        }
    }
    char ID_name[5][100];
    do {
        printf("���ϴ� �޴��� �����ϼ���.(1. �԰�, 2. �Ǹ�, 3. ������Ȳ. 4. ��ü��Ȳ. 5. ����): ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            system("cls");
            printf("��ǰ ID: ");
            scanf("%d", &ids);
            int i;
            for (i = 0; i < 5; i++)
            {

                if (ID[i][0] == ids && ID[i][0] != 0)
                {
                    printf("�԰�: ");
                    scanf("%d", &quantity);
                    ID[i][1] += quantity;
                    printf("�ǸŰ���: ");
                    scanf("%d", &price);
                    ID[i][3] = price;
                    break;
                }
                else if (ID[i][0] == 0)
                {
                    ID[i][0] = ids;
                    printf("��ǰ��: ");
                    scanf("%s", ID_name[i]);
                    printf("�԰�: ");
                    scanf("%d", &quantity);
                    ID[i][1] += quantity;
                    printf("�ǸŰ���: ");
                    scanf("%d", &price);
                    ID[i][3] = price;

                    break;
                }




            }
            if (i == 5)
            {
                printf("��ǰ�� ������ �ʰ��Ͽ����ϴ�\n");
            }

            break;
        case 2:
            system("cls");
            printf("��ǰ ID: ");
            scanf("%d", &ids);
            for (i = 0; i < 5; i++)
            {
                if (ID[i][0] == ids) {
                    printf("�Ǹ� ���� :");
                    scanf("%d", &output);
                    ID[i][2] = output;
                    break;
                }


            }
            if (ID[i][0] != ids) {
                printf("ID�� �߸� �ԷµǾ����ϴ�.\n");
            }
            break;


        case 3:
            system("cls");
            printf("��ǰ ID: ");
            scanf("%d", &ids);
            for (i = 0; i < 5; i++)
            {
                if (ID[i][0] == ids) 
                {
                    printf("ID :%d\n", ID[i][0]);
                    printf("��ǰ�� : %s\n", ID_name[i]);
                    printf("��ǰ���� :%d\n", ID[i][3]);
                    printf("�԰� :%d\n", ID[i][1]);
                    printf("�Ǹŷ� :%d\n", ID[i][2]);
                    totalOutprice = 0;
                    totalOutprice = ID[i][2] * ID[i][3];
                    
                    printf("ID: %d �� �Ǹűݾ� :%d\n", ids ,totalOutprice);
                    break;
                }
            }   if (i == 5)
                {
                printf("ID�� �߸� �ԷµǾ����ϴ�.\n");
                }
            
            break;

        case 4:
            system("cls");
            ALLpanmea = 0;
            ALLpanmeayul = 0;
            ALLjeogo = 0;
            ALLepgo =0;
            for (i = 0; i < 5; i++) {
                ALLjeogo += ID[i][1] - ID[i][2];
                ALLepgo += ID[i][1];
                ALLpanmea += ID[i][2];
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
                minroomname = "����";
            }
            ALLpanmeayul = ((float)ALLpanmea / ALLepgo) * 100;
            printf("������: ");
            for (int i = 0; i < 5; i++)
            {
                printf("%d ", ID[i][1] - ID[i][2]);
            }
            
            printf("\n");
            printf("�� �Ǹŷ� : %d(�Ǹ���:%0.2f%%)\n", ALLpanmea, ALLpanmeayul);
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ��:%s, �Ǹŷ� %d\n", maxID, maxroomname, max);
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ��:%s, �Ǹŷ� %d\n", minID, minroomname, min);
            for (int h = 0; h < 5; h++) {
                if (ID[h][1] - ID[h][2] <= 2)
                {
                    int buzok_ID = 0;
                    char* buzok_name;
                    int buzokjeago = 0;
                    buzok_ID = h + 1;
                    buzok_name = ID_name[h];
                    buzokjeago = ID[h][1] - ID[h][2];
                    printf("��ǰ ID %d: ��ǰ��: %s ������(%d)\n", buzok_ID, buzok_name, buzokjeago);
                }
            }
            break;
        case 5:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �����Դϴ�.\n");
            system("cls");
            break;
        }
    } while (menu != 5);

    return 0;
}
