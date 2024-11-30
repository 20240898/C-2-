/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 100
#define COL 100
void input2DArray(int array[][100], int row, int col){
    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++) array[i][j] = rand() % 10;
    }
}
void print2DArray(int array[][100], int row, int col){
    printf("=======================\n");
    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++) printf("[%3d]",array[i][j]) ;
        printf("\n");
    }
}
void addMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col)
{
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++) target[i][j] = s1[i][j] + s2[i][j];
    }
}
void subMatrix(int s1[][100], int s2[][100], int target[][100], int row, int col)
{
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++) target[i][j] = s1[i][j] - s2[i][j];
    }
}
void mutiMatrix(int s1[][100], int s2[][100], int target[100][100], int row1, int col1, int row2, int col2){
    for(int i=0; i<row1; i++){
        for(int j=0;j<col2;j++){
            target[i][j] = 0;
            for(int k=0; k< col1;k++){
                target[i][j] += s1[i][k] * s2[k][j];
            }
        }
    }
}
int main()
{
    
    int matrix1[ROW][COL];
    int matrix2[ROW][COL];
    int result[ROW][COL];
    //int addresult[ROW][COL];
    //int subresult[ROW][COL];
    
    int row1, row2, col1, col2 = 0;
    srand(time(NULL));
    
    do{
        
        if(col1 != row2) printf("크기가 맞지 않습니다. 다시입력해주세요 \n");
        
        printf("input matrix 1 row & col : ");
        scanf("%d %d", &row1, &col1);
        printf("input matrix 2 row & col : ");
        scanf("%d %d", &row2, &col2);
    }while (col1 != row2);
    
    input2DArray(matrix1, row1, col1);
    input2DArray(matrix2, row2, col2);
    //input2DArray(matrix1, row, col);
    //input2DArray(matrix2, row, col);
    //addMatrix(matrix1, matrix2, addresult, row, col);
    //subMatrix(matrix1, matrix2, subresult, row, col);
    mutiMatrix(matrix1, matrix2, result, row1, col1, row2, col2);
    
    printf("Matrix 1:\n");
    print2DArray(matrix1, row1, col1);

    printf("Matrix 2:\n");
    print2DArray(matrix2, row2, col2);
    print2DArray(result,row1,col2);
    //print2DArray(matrix1, row, col);
    //print2DArray(matrix2, row, col);
    //print2DArray(addresult, row, col);
    //print2DArray(subresult, row, col);
    return 0;
}
