# Operação de busca / Projeto da Matéria de Estrutura de Dados do prof. Edinilson Geraldo Rossi
# Este trabalho foi fruta da parceria entre Wesley Martins e Gabriel Scache
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

<stdio.h>: Para entrada e saída.

<stdlib.h>: Para alocação de memória.

<time.h>: Para geração de números aleatórios.

<string.h>: Para manipulação de strings.