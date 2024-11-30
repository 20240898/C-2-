/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


int main()
{
    char input[200] = "";
    int count[26] = {0};
    int ch;
    int i=0;
    
    while((ch = getchar()) != EOF){
        input[i++] =  ch;
    }
    i=0;
    while(input[i] != '\0'){
        if(input[i] >= 'a' && input[i] <= 'z'){
            count[input[i] - 'a']++;
        }
        i++;
    }
    printf("입력문자열 : %s\n", input);
    for(int i=0;i<26;i++) printf("%c 출현횟수 : %d\n",'a'+ i, count[i]);
    return 0;
}
