#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MSG_MAIN    "���ϴ� �޴��� �����ϼ���"
#define MSG_MENU0   "1. �԰�\n"
#define MSG_MENU1   "2. �Ǹ�\n"
#define MSG_MENU2   "3. ��ǰ��Ȳ\n"
#define MSG_MENU3   "4. ��ǰ�� �Է�\n"
#define MSG_MENU4   "5. ����\n"
#define MSG_EXIT    ":���α׷��� �����մϴ�."

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
    char* minname = "����";
    int max = 0;
    int maxroom = 0;
    char* maxname = "����";
    int input = 0;
    int ininput = 0;
    int outinput = 0;
    char Name = 0;

    printf("1~100������ ��ǰ ���� �Է�Enter>\n");
    scanf("%d", &a);
    do {
        printMENU();
        scanf("%d", &input);
        system("cls");
        switch (input) {
        case 1:
            printf("1. ��ü ��ǰ �԰���� �Է�\n ");
            printf("2. ���� ��ǰ �Է� \n");
            scanf("%d", &ininput);
            if (ininput == 1) {
                for (int i = 0; i < a; i++) {
                    printf("��ǰ�� �԰���� �Է�Enter>\n");
                    int b = 0;
                    scanf("%d", &b);
                    insum += b;
                    in_num[i] += b;
                }
            }
            else if (ininput == 2) {
                printf("��ǰID :\n");
                scanf("%d", &ID);
                printf("�԰����:\n");
                ID--;
                scanf("%d", &b);
                insum += b;
                in_num[ID] += b;
            }
            break;
        case 2:
            printf("1. ��ü ��ǰ �Ǹż��� �Է�\n ");
            printf("2. ���� ��ǰ �Է� \n ");
            scanf("%d", &outinput);
            if (outinput = 1) {
                for (int j = 0; j < a; j++) {
                    printf("��ǰ�� �Ǹż��� �Է�Enter>\n");
                    scanf("%d", &c);
                    sellsum += c;
                    out_num[j] += c;
                }
            }
            else if (outinput = 2) {
                printf("��ǰID :\n");
                scanf("%d", &ID);
                printf("�԰����:\n");
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

            // �ּ� �Ǹŷ� ��ǰ ã��
            for (int i = 0; i < a; i++) {
                if (out_num[i] < min && out_num[i] > 0) { // �Ǹŷ��� 0���� ū ���
                    min = out_num[i];
                    minroom = i + 1;
                    minname = ID_name[i];
                }
            }

            if (min == 1000) {
                minname = "����";
            }

            if (insum != 0) {
                selling = (sellsum / insum) * 100;
            }
            //selling = (sellsum/insum)*100;

            printf("������: ");

            for (int h = 0; h < a; h++) {
                printf("%d ", inventory[h]);
            }


            printf("\n");
            printf("�� �Ǹŷ� : %f(�Ǹ���:%f%%)\n", sellsum, selling);
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ��:%s, �Ǹŷ� %d\n", maxroom, maxname, max);
            printf("���� ���� �Ǹŵ� ��ǰ : ID %d, ��ǰ��:%s, �Ǹŷ� %d\n", minroom, minname, min);

            for (int h = 0; h < a; h++) {
                if (inventory[h] <= 2) {
                    int invent_ID = 0;
                    int invent_shortage = 0;
                    char* roomname;
                    invent_shortage = inventory[h];
                    invent_ID = h + 1;
                    roomname = ID_name[h];
                    printf("��ǰ ID %d: ��ǰ��: %s ������(%d)\n", invent_ID, roomname, invent_shortage);
                }
            }
            break;
        case 4:
            for (int i = 0; i < a; i++) {
                printf("ID %d ��ǰ��:", i + 1);
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