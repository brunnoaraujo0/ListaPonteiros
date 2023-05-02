#include<stdio.h>

int main(void){
   
    int x[4];
    for(int i = 0; i < 4; i++){
        printf(" x + %d = %X \n", i , x + i);
    }

    return 0;
}