#include<stdio.h>
#include<stdlib.h>

void alocaVet(float **v, int n){
    
    *v = (float*)(malloc(n * sizeof(float)));

    
}

void vetRecebe(float *v, int n){

    for(int i = 0; i < n; i++){
        printf("Digite o %d numero que deseja adicionar:  ", i+1);
        scanf("%f", &v[i]);
    }
}

void ordenaCresc(float *v, int n){

    float aux;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(v[i] < v[j]){

                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
        
    }
    
}

void imprimeVet(float *v, int n){

    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", v[i]);
    }
    

}

int main(void)
{
    float *vetor;
    int scale;

    printf("Digite a quantidade de valores que deseja armazenar:");
    scanf("%d", &scale);
    alocaVet(&vetor,scale);

    if(vetor == NULL){
        return 404;
    }

    vetRecebe(vetor,scale);
    ordenaCresc(vetor, scale);
    printf("\n");
    imprimeVet(vetor,scale);

    free(vetor);
    return 0;
}