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
int main()
{
    int matrix[ROW][COL];
    int row,col;
    scanf("%d %d", &row, &col);
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++) matrix[i][j] = rand() % 1000;
    }
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col;j++) printf("[%3d]",matrix[i][j]) ;
        printf("\n");
    }
    return 0;
}
