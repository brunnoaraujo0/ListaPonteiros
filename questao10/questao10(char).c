#include<stdio.h>

int main(void){
   
    char x[4];
    for(int i = 0; i < 4; i++){
        printf(" xS + %d = %X \n", i , x + i);
    }
   

    return 0;
}