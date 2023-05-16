#include<stdio.h>
#include<stdlib.h>

float **alocaMat(float **m, int nl,int nc){
    
    m = (float **)(malloc(nl * sizeof(float)));
    m[0] = (float *)(malloc(nc*nl*sizeof(float)));
    
    for (int i = 1; i < nl; i++){

        m[i] = m[i-1] + nc;
    }
    return m;
}


void matRecebe(float  **m, int nl,int nc){

    for(int i = 0; i < nl; i++){
        for (int j = 0; j < nc; j++){
            printf("\n Digite o valor que deseja adicionar na linha %d e coluna %d:  ", i+1,j+1);
            scanf("%f", &m[i][j]);
        
        }
        
    }
}


void imprimeMat(float **m, int nl, int nc){

     for(int i = 0; i < nl; i++){
        for (int j = 0; j < nc; j++){
            
            printf(" %.2f ", m[i][j]);
        }
        printf("\n");
        
    }
    

}

void prodMat(float **mA, float **mB, float **mC, int nlA, int ncA, int ncB){
    
    float temp;
    
    for(int i = 0; i < nlA; i++){
        for (int j = 0; j < ncB; j++){
            
           temp = 0;
           for (int k = 0; k < ncA; k++){

               temp += mA[i][k]*mB[k][j];
           }
           mC[i][j] = temp;
        }
        
    }

}

void liberaMat(float **m){
    
    free(m[0]);
    free(m);
}

int main(void)
{
    float **matA = NULL, **matB = NULL,**matC = NULL;
    int nlinhaA, ncolunaA,ncolunaB;

    printf("Digite a quantidade de linhas da matriz A :");
    scanf("%i", &nlinhaA);
    printf("\n\nDigite a quantidade de colunas da matriz A :");
    scanf("%i", &ncolunaA);
    printf("\n\nDigite a quantidade de colunas da matriz B :");
    scanf("%i", &ncolunaB);

    matA = alocaMat(matA,nlinhaA,ncolunaA);
    matB = alocaMat(matB,ncolunaA,ncolunaB);
    matC = alocaMat(matC,nlinhaA,ncolunaB);
        

    matRecebe(matA,nlinhaA,ncolunaA);

    printf("\n ----------- MATRIZ A ---------------- \n");
    imprimeMat(matA,nlinhaA,ncolunaA);
    printf("\n");

    matRecebe(matB,ncolunaA,ncolunaB);

    printf("\n ----------- MATRIZ B ---------------- \n");
    imprimeMat(matB,ncolunaA,ncolunaB);
    printf("\n");

    prodMat(matA,matB,matC,nlinhaA,ncolunaA,ncolunaB);

    printf("\n ----------- MATRIZ C ---------------- \n");
    imprimeMat(matC,nlinhaA,ncolunaB);
    printf("\n");


    
    liberaMat(matC);
    liberaMat(matB);
    liberaMat(matA);
    return 0;
}