#include<stdio.h>
#include<stdlib.h>

//Primeiramente eu defino o meu ponteiro para função 
//do tipo generico ou seja void
typedef void (*pointerF)(float *p,int q);

//defino minha função que faz a alocação dinamica de memoria
void alocaVet(float **v, int n){
    
    *v = (float*)(malloc(n * sizeof(float)));
    
}

//Neste passo defino minha função swap(), que faz a troca que será o meu criterio de comparação
void swap(float *a, float *b) {
        float temp;      
        
        if( a < b){
            temp = *a;
            *a = *b;
            *b = temp;
        }
        
}

//aqui eu crio a minha função sort que usa como parametro um ponteiro void para função
void _sort(float *vetor, int n, void (*pointerF)(float *p,float *q)) {
    
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n; j++) {
                
                    (*pointerF)(&vetor[i],&vetor[j]);
                
            }
        }
}

void vetRecebe(float *v, int n){

    for(int i = 0; i < n; i++){
        printf("Digite o %d numero que deseja adicionar:  ", i+1);
        scanf("%f", &v[i]);
    }
}

void imprimeVet(float *v, int n){

    for (int i = 0; i < n; i++)
    {
        printf(" %.2f ", v[i]);
    }
    

}

int main(void)
{
    //crio meu ponteiro para função
    pointerF *pF;
    float *vetor;
    int scale;

    //o ponteiro agora aponta para o endereço da minha função swap();
    pF = swap;

    printf("Digite a quantidade de valores que deseja armazenar:");
    scanf("%d", &scale);
    alocaVet(&vetor,scale);

    if(vetor == NULL){
        return 404;
    }

    vetRecebe(vetor,scale);

    //chamo minha função sort e no ultimo parametro envio meu ponteiro pF
    //pF tem o endereço do  meu criterio de comparação definido na função swap()
    _sort(vetor, scale,pF);
    
    printf("\nVetor ordenado: [");
    imprimeVet(vetor,scale);
    printf("]");

    //libero a memoria alocada
    free(vetor);
    return 0;
}