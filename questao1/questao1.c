#include<stdio.h>

int main(void) {
    int i=3; 
    int j=5;
    int *p = &i; 
    int *q = &j;

    if(p == &i) {
        printf("Resultado: Verdadeiro(%d)\n\n", p==&i);
        //é verdadeiro pois o endereço de memoria que o ponteiro "p" aponta é o da variavel "i"
    }else {
        printf("Resultado: Falso(%d)\n\n", p==&i);
    }

    printf("*p - *q = %d\n\n", *p - *q);
    //*p amarmazena o valor i=3 e em *q  o valor j=5 a saida é igual a 3 - 5 = -2

    printf("**&p = %d \n\n", **&p );
    //**&p me mostra o valor que está guardado em p que é = 3

     printf("3 - *p/(*q) + 7 = %d \n\n", 3 - *p/(*q) + 7 );
     // a expressao resultante é 3 - (3/5) + 7 = 10

     return 0;
}