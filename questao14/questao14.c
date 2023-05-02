#include<stdio.h>
#include<stdlib.h>

//similar a questão anterior criamos uma função para alocação de memoria dinamica
void alocaVet(float **v, int n){
    
    *v = (float*)(malloc(n * sizeof(float)));

    
}

//escreve os elementos do vetor 
void vetRecebe(float *v, int n){

    for(int i = 0; i < n; i++){
        printf("Digite o %d numero que deseja adicionar:  ", i+1);
        scanf("%f", &v[i]);
    }
}
//aqui criamos o nosso criterio de comparação
int comparador(const void *a, const void *b){
    //retorna 1 caso a seja maior que b
    if (*(int*)a > *(int*)b) {
      return 1;
      //-1 caso a seja menor
   } else if (*(int*)a < *(int*)b) {
      return -1;
      //e retorna 0 caso não seja nenhum dos resultados anteriores
   } else {
      return 0;
   }
}
//função que imprime o vetor para o usuario
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

    // chamada da função qsort()
    qsort(vetor, scale, sizeof(float),comparador);

    printf("\n");
    imprimeVet(vetor,scale);

    free(vetor);
    return 0;
}