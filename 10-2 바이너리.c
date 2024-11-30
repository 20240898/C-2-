/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int array[1000];
    FILE* fp;
    int i = 0;
    fp = fopen("array.bin", "rb");
    if(fp == NULL)return -1;
    
    fread(array, sizeof(int), 100, fp);
    
    i--;
    for(int j=0; j<100;j++)printf("%d ", array[j]);
    //fwrite(array, sizeof(int), 100 ,fp);
    fclose(fp);
    return 0;
}
/*char input[SIZE];
    FILE* fp = NULL;
    int i =0;
    if((fp = fopen("output.bin", "rb")) == NULL){
       printf("error...");
       return 0;
    }
    while(!feof(fp)){
        fread(&input[i],sizeof(char), 1, fp);
        i++;
    }
    input[i] = '\0';
    puts(input);
    
    fclose(fp);
    */