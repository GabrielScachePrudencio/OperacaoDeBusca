#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define tam 100

void gerarNumAleatorio(int vetor[tam]);
void mostrar(int vetor[tam]);
void ordenadorEmOrdemCrescente(int vetor[tam]);


void main(){
    srand(time(NULL)); 
    //rand() % 10;

    int numGeradosAleatoriamente[tam];
    gerarNumAleatorio(numGeradosAleatoriamente);
    printf("\nNumeros gerados:\n");
    mostrar(numGeradosAleatoriamente);

    ordenadorEmOrdemCrescente(numGeradosAleatoriamente);
    printf("\nNumeros gerados agora ordenados:\n");
    mostrar(numGeradosAleatoriamente);
}

void gerarNumAleatorio(int vetor[tam]){
    int qtdd = 0;
    for(int i = 0; i < tam; i++){
        int achou = 0;
        int numAlea = rand() % tam; // ele cria um num aleatorio

        for(int j = 0; j < qtdd; j++){ //aqui ele verifica se ja existe
            if(vetor[j] == numAlea){ 
                achou = 1;// defini se existe ou nao
                j = qtdd;//break
            }
        }

        if(achou == 0){ // se nao existir ele passa pelo if
            qtdd++; //o qtdd e uma forma de pelo menos no inicio tornar mais eficiente a busca pela duplicagem pq so ele so vai procurar ate quantos numeros ja foram criados nao o total
            vetor[i] = numAlea; // passa o num aleatorio pelo indice i no vetor
        } else { // caso ele tenha cido duplicado
            i--; // ele retrocede e faz tudo de novo nao duplicando
        }      
    }

    printf("\n\n%d\n\n", qtdd);
}

void mostrar(int vetor[tam]){
    for(int i = 0; i < tam; i++){
        printf(" %d", vetor[i]);
    }
}

void ordenadorEmOrdemCrescente(int vetor[tam]){
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(vetor[i] < vetor[j]){ // basciamente vai trocando o maior com menor deixar os menores na frente
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}
















