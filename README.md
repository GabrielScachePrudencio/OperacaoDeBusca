# Operação de busca / Projeto da Matéria de Estrutura de Dados do prof. Edinilson Geraldo Rossi
# Este trabalho foi fruto da parceria entre Wesley Martins e Gabriel Scache
Este projeto implementa um programa em C para gerar uma lista de números aleatórios, cria índices para facilitar a busca, e realizar a busca eficiente de um número na lista usando esses índices.

Descrição do Projeto

O programa realiza as seguintes etapas:

I. Geração de Números Aleatórios: Lista ordenada de 1.000.000 de números aleatórios, armazenados em um vetor.

II. Criação de Índices: Gera dois índices para uma busca mais rapida:

A primeira metade dos índices aponta para elementos do início do vetor.
A segunda metade dos índices aponta para elementos a partir do meio do vetor.

III. Busca de Número: Através dos índices criados, o programa realiza uma busca eficiente de um número fornecido pelo usuário.

1. gerarNumAleatorio(): Gera uma sequência de números aleatórios, armazenando-os de forma crescente no vetor.

2. criarIndices(): Cria dois conjuntos de índices, um para a primeira metade e outro para a segunda metade do vetor, facilitando a busca.

3. buscadorDeNumeroPelosIndices(): Realiza a busca do número fornecido pelo usuário, usando os índices para dividir a busca entre as duas metades do vetor.

Este projeto utiliza apenas bibliotecas padrão da linguagem C:

Como Funciona a Busca de Números

1. Divisão do Vetor em Índices
A função criarIndices divide o vetor em duas metades, criando dois vetores de índices (vetorInd e vetorInd2). Cada índice aponta para uma posição no vetor original.

2. Busca pelo Número
A busca é realizada na função buscadorDeNumeroPelosIndices. O usuário insere o número a ser procurado, e o programa verifica em qual metade ele está baseado nos valores dos índices:

Primeira Metade: Se o número é menor ou igual ao valor máximo da primeira metade, ele será procurado nela.

Segunda Metade: Caso contrário, a busca acontece na segunda metade.

3. Processo de Busca em Subfaixas
Dentro da metade selecionada, o código usa os índices para restringir a faixa onde o número pode estar. Em cada faixa, ele verifica de comeco a fim se o número procurado está presente. Isso evita uma busca completa, verificando apenas nas posições mais prováveis.


4. Resultado da Busca
Se o número é encontrado, a posição é exibida.
Caso contrário, uma mensagem informa que o número não foi encontrado.


<stdio.h>: Para entrada e saída.

<stdlib.h>: Para alocação de memória.

<time.h>: Para geração de números aleatórios.

<string.h>: Para manipulação de strings.