#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define tam 1000000
#define tamInd 200

void gerarNumAleatorio(int *vetor[tam]);

void criarIndices(int *vetor[tam], int vetorInd[tamInd], int vetorInd2[tamInd]);
void buscadorDeNumeroPelosIndices(int *vetor[tam], int vetorInd[tamInd], int vetorInd2[tamInd] , int numProc);


void main(){
    srand(time(NULL)); 
    
    int *numGeradosAleatoriamente = malloc(sizeof(int) * 1000000);
    
    int indicesDosNumerosAleatoriosOrdenados1[tamInd];
    int indicesDosNumerosAleatoriosOrdenados2[tamInd];

    int numProc;
    
    printf("\nNumeros gerados:\n");
    gerarNumAleatorio(numGeradosAleatoriamente);

    printf("\nNumeros Indices:\n");
    criarIndices(numGeradosAleatoriamente, indicesDosNumerosAleatoriosOrdenados1, indicesDosNumerosAleatoriosOrdenados2);

    printf("\nDigite o numero a ser procurado: ");
    scanf("%d", &numProc);

    int resp = 1;

    while(resp != 0){
        printf("\ndigite qualquer numero menos 0");
        scanf("%d", &resp);
        printf("\nDigite o numero a ser procurado: ");
        scanf("%d", &numProc);
        buscadorDeNumeroPelosIndices(numGeradosAleatoriamente, indicesDosNumerosAleatoriosOrdenados1, indicesDosNumerosAleatoriosOrdenados2, numProc);
    }
    
}

void gerarNumAleatorio(int *vetor[tam]){
    vetor[0] = rand() % 100;
    for(int i = 1; i != tam; i++){
        vetor[i] = vetor[i-1] + (rand() % 10) + 1;
        printf(" %d", vetor[i]);

    }


}

// criando e mostrando os indices 
            // basicamente como 10000/100 entao da 100 indices so que cada um desses indices é multiplicado por I entao é 0, 100, 200, 300, ate 9900
void criarIndices(int *vetor[tam], int vetorInd[tamInd], int vetorInd2[tamInd]){
    printf("\nIndices da primeira metade:\n");
    for(int i = 0; i < tamInd/2; i++){
        vetorInd[i] = vetor[i * (tam / (2 * tamInd))]; 
        printf("%d ", vetorInd[i]);
    }

    printf("\n\nIndices da segunda metade:\n");
    for(int i = tamInd/2; i < tamInd; i++){
        vetorInd2[i] = vetor[(tam / 2) + i * (tam / (2 * tamInd))];
        printf("%d ", vetorInd2[i]);
    }
}



void buscadorDeNumeroPelosIndices(int *vetor[tam], int vetorInd[tamInd], int vetorInd2[tamInd] , int numProc){
    int achou = 0;
    if(numProc <= vetorInd[tamInd/2]){
        for(int i = 0; i < tamInd  && achou != 1; i++){ // ele vai ver pegar cada indice que e um numero 100 200
            if(numProc >= vetorInd[i]){ // e vai pegar o q for o ultimo menor 
                int comeco = vetorInd[i];  //define o inicio do indice
                
                for(int j = comeco; j < vetorInd[i+1] && achou != 1 ; j++){ //usando esse inicio define o maximo que vai que ate o fim do indice
                    if(vetor[j] == numProc){
                        achou = 1;
                        printf("\n\nO indice do numero %d eh %d e esta dentro do indice %d ou %d PRIMEIRA METADE", numProc, j, i, vetorInd[i]);
                        j = comeco + (tam/tamInd);
                    
                    }   
                } 
            if (achou == 1) i = tamInd;
            }
        }    
    }


    else if(numProc >= vetorInd[tamInd/2] && numProc <= vetorInd2[tamInd]){
        for(int i = 0; i < tamInd && achou != 1; i++){
            if(numProc >= vetorInd2[i]){
                // Cálculo do início do intervalo
                int comeco = vetorInd2[i];
                
                // Loop para buscar dentro do intervalo
                for(int j = comeco; j < vetorInd2[i+1] && achou != 1; j++){
                    if(vetor[j] == numProc){
                        achou = 1;
                        printf("\n\nO indice do numero %d eh %d e esta dentro do indice %d ou %d SEGUNDA METADE", numProc, j, i, vetorInd[i]);
                        break; // Encerra a busca uma vez que o número é encontrado
                    }   
                }
                if (achou == 1) break; // Encerra o loop externo
            }
        }
    }

   // for(int h = 0; h <= tam)

if(achou == 0) printf("\n\nO numero nao foi encontrado");

}


/*
///metas 
- arrumar sistema de busca ele nao pega os ultimos
- trocar os breaks
*/

















