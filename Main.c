#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define tam 100
#define tamInd 10

void gerarNumAleatorio(int vetor[tam]);
void mostrar(int vetor[tam]);
void ordenadorEmOrdemCrescente(int vetor[tam]);

void criarIndices(int vetor[tam], int vetorInd[tamInd]);
void mostrarIndices(int vetorInd[tamInd]);


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

    
    int indicesDosNumerosAleatoriosOrdenados[tamInd];
    int numProc = 99;

    criarIndices(numGeradosAleatoriamente, indicesDosNumerosAleatoriosOrdenados);
    printf("\nNumeros Indices:\n");
    mostrarIndices(indicesDosNumerosAleatoriosOrdenados);
    buscadorDeNumeroPelosIndices(numGeradosAleatoriamente, indicesDosNumerosAleatoriosOrdenados, numProc);


}

void gerarNumAleatorio(int vetor[tam]){
    int qtdd = 0;
    for(int i = 0; i < tam; i++){
        int achou = 0;
        int numAlea = rand() % tam; // ele cria um num aleatorio

        for(int j = 0; j < qtdd && achou == 0; j++){ //aqui ele verifica se ja existe
            if(vetor[j] == numAlea){ 
                achou = 1;// defini se existe ou nao
                j = qtdd;//break
            }
        }

        if(achou == 0){ // se nao existir ele passa pelo if
            qtdd++; //o qtdd e uma forma de pelo menos no inicio tornar mais eficiente a busca pela duplicagem pq so ele so vai procurar ate quantos numeros ja foram criados nao o total
            vetor[i] = numAlea; // passa o num aleatorio pelo indice i no vetor
        } else { // caso ele tenha cido duplicado
            i--; // ele retrocede e faz tudo de novo, nao duplicando
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



// criando e mostrando os indices 
void criarIndices(int vetor[tam], int vetorInd[tamInd]){
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


void buscadorDeNumeroPelosIndices(int vetor[tam], int vetorInd[tamInd], int numProc){
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



//NAO FUNCIONOU A buscadorDeNumeroPelosIndices



