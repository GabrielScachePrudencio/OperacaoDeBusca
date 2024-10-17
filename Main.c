#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define tam 1000000
#define tamInd 100

void gerarNumAleatorio(int *vetor[tam]);
void mostrar(int *vetor[tam]);

void criarIndices(int *vetor[tam], int vetorInd[tamInd]);
void mostrarIndices(int vetorInd[tamInd]);
void buscadorDeNumeroPelosIndices(int *vetor[tam], int vetorInd[tamInd], int numProc);

int *numGeradosAleatoriamente[tam];

void main(){
    srand(time(NULL)); 

    gerarNumAleatorio(numGeradosAleatoriamente);
    printf("\nNumeros gerados:\n");
    mostrar(numGeradosAleatoriamente);

    int indicesDosNumerosAleatoriosOrdenados[tamInd];
    int numProc;
    printf("\nDigite o numero a ser procurado: ");
    scanf("%d", &numProc);

    criarIndices(numGeradosAleatoriamente, indicesDosNumerosAleatoriosOrdenados);
    printf("\nNumeros Indices:\n");
    mostrarIndices(indicesDosNumerosAleatoriosOrdenados);
    buscadorDeNumeroPelosIndices(numGeradosAleatoriamente, indicesDosNumerosAleatoriosOrdenados, numProc);
    
}

void gerarNumAleatorio(int *vetor[tam]){
    
    vetor[0] = rand() % 100;
    for(int i = 1; i != tam; i++){
        vetor[i] = vetor[i-1] + (rand() % 10);
       
    }


}

void mostrar(int *vetor[tam]){
    int qtdd= 0;
    for(int i = 0; i < tam; i++){
        printf(" %d", vetor[i]);
        qtdd++;
    }
}



// criando e mostrando os indices 
void criarIndices(int *vetor[tam], int vetorInd[tamInd]){
    for(int i = 0; i < tamInd; i++){
        vetorInd[i] =  vetor[i * (tam/tamInd)]; 
        // basicamente como 10000/100 entao da 100 indices so que cada um desses indices é multiplicado por I entao é 0, 100, 200, 300, ate 9900
    }
}


void mostrarIndices(int vetorInd[tamInd]){
    for(int i = 0; i < tamInd; i++){
        printf(" %d", vetorInd[i]);
    }
}


void buscadorDeNumeroPelosIndices(int *vetor[tam], int vetorInd[tamInd], int numProc){
    int achou = 0;
    for(int i = 0; i < tamInd; i++){ // ele vai ver pegar cada indice que e um numero 100 200
        if(numProc <= vetorInd[i]){ // e vai pegar o q for o ultimo menor 
            int comeco = i * (tam / tamInd);  //define o inicio do indice

            for(int j = comeco; j < comeco + (tam/tamInd); j++){ //usando esse inicio define o maximo que vai que ate o fim do indice
                if(vetor[j] == numProc){
                    achou = 1;
                    printf("\n\nO indice do numero %d é %d dentro do indice %d ou %d", numProc, j, i, vetorInd[i]);
                    j = comeco + (tam/tamInd);
                
                }   
            }
        if (achou == 1) i = tamInd;
        }
    }
    if(achou == 0) printf("\n\nO numero nao foi encontrado");
}

/*
///metas 
- buscadorDeNumeroPelosIndices nao ta funcionando
- add mais vetores de indices mais cinco mais + -
*/

















