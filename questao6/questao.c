#include<stdio.h>

int main(){
    int pulo[5];


    printf("%d ",*(pulo + 2));
    printf("%d ",*(pulo + 4));
    printf("%d ",pulo + 2);
    printf("%d ",pulo + 4);
    
    for(int i = 0 ; i <= 4 ; i++){
        printf("\n i = %d",i);
        printf(" pulo[%d] = %d",i, pulo[i]);
        printf(" &pulo[%d] = %X",i, &pulo[i]);
    }
    return 0;
}