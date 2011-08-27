#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){
    int i;
    char c,str[10];
    printf("\n Tabela ASCII Estendida\n");
    for (i = 0; i < 256; i++){
        itoa(i,str,16);
        printf("\n \\x%s :  %d  :  %c  ",str, i, i);
    }
    getch();
    return(0);
}
