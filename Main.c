#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define tam 1000000
#define tamInd 200//100 para cada vetor de indice

void gerarNumAleatorio(int *vetor);
void criarIndices(int *vetor, int vetorInd[tamInd], int vetorInd2[tamInd]);
void buscadorDeNumeroPelosIndices(int *vetor, int vetorInd[tamInd], int vetorInd2[tamInd], int numProc);


void main(){
    srand(time(NULL)); 
    
    int *numGeradosAleatoriamente = malloc(sizeof(int) * tam); // malloc aloca dinamicamente 1 milhao na memoria 
    
    int indicesDosNumerosAleatoriosOrdenados1[tamInd/2];
    int indicesDosNumerosAleatoriosOrdenados2[tamInd/2];

    int numProc;
    
    printf("\nNumeros gerados:\n");
    gerarNumAleatorio(numGeradosAleatoriamente);

    printf("\nNumeros Indices:\n");
    criarIndices(numGeradosAleatoriamente, indicesDosNumerosAleatoriosOrdenados1, indicesDosNumerosAleatoriosOrdenados2);

    printf("\nDigite o numero a ser procurado: ");
    scanf("%d", &numProc);

    buscadorDeNumeroPelosIndices(numGeradosAleatoriamente, indicesDosNumerosAleatoriosOrdenados1, indicesDosNumerosAleatoriosOrdenados2, numProc);
    

}

void gerarNumAleatorio(int *vetor){
    vetor[0] = rand() % 10;
    for(int i = 1; i < tam; i++){
        vetor[i] = vetor[i-1] + (rand() % 10) + 1;
        printf(" %d", vetor[i]);

    }


}

// criando e mostrando os indices 
// basicamente como 10000/100 entao da 100 indices so que cada um desses indices é multiplicado por I entao é 0, 100, 200, 300, ate 9900
void criarIndices(int *vetor, int vetorInd[tamInd], int vetorInd2[tamInd]){    
    printf("\nIndices da primeira metade:\n");
    for(int i = 0; i < tamInd / 2; i++){
        vetorInd[i] = i * (tam / (tamInd)); // 0 * 1000000/200 = 0*5000 = 0
        // 1 * 5000 = 5000 vetorComNumero[vetorINdice[1]] 
        printf("\nIndice %d aponta para o valor %d", vetorInd[i], vetor[vetorInd[i]]);

    }

    printf("\n\nIndices da segunda metade:\n");
    for(int i = 0; i < tamInd / 2; i++){
        vetorInd2[i] = (tam/2) + i * (tam / tamInd);
        printf("\nIndice %d aponta para o valor %d", vetorInd2[i], vetor[vetorInd2[i]]);

    }
}



void buscadorDeNumeroPelosIndices(int *vetor, int vetorInd[tamInd], int vetorInd2[tamInd], int numProc) {
    int achou = 0;
    
    // Verificando se o número está na primeira metade
    if (numProc <= vetor[vetorInd[tamInd / 2 - 1]]) {
        for (int i = 0; i < tamInd / 2 && achou != 1; i++) {
            if(numProc >= vetor[vetorInd[i]] && achou != 1){
                int comeco = vetorInd[i];
                int fim = (i + 1 < tamInd / 2) ? vetorInd[i + 1] : tam / 2;//

                for (int j = comeco; j < fim && achou != 1; j++) {
                    if (vetor[j] == numProc) {
                        achou = 1;
                        printf("\n\nO numero %d foi encontrado na posicao: %d (primeira metade i: %d indice: %d que representa o numero do vetor: %d)\n", numProc, j, i, vetorInd[i], vetor[vetorInd[i]]);
                    }
                }
            }
        }
    }

    else if (numProc > vetor[vetorInd[tamInd / 2 - 1]]) {
        for (int i = 0; i < tamInd / 2 && achou != 1; i++) {
            if(numProc >= vetor[vetorInd2[i]] && achou != 1){

                int comeco = vetorInd2[i];//455000
                int fim = (i + 1 < tamInd / 2) ? vetorInd2[i + 1] : tam;


                for (int j = comeco; j < fim && achou != 1; j++) {
                    if (vetor[j] == numProc) {
                        achou = 1;
                        printf("\n\nO numero %d foi encontrado na posicao: %d (segunda metade i: %d indice: %d)\n", numProc, j, i, vetorInd2[i]);
                    }
                }
            }
        }
    }

    if (achou == 0) {
        printf("\n\nO numero nao foi encontrado\n");
    }
}



/*
///metas 
- fazer o readme
- fazer relatorio
- gravar o videp e postar no ytb
*/

















