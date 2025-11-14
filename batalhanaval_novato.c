#include <stdio.h>

/*
Desafio Batalha Naval - Nível Novato
Autor: Paulo Giovani dos Santos
Descrição:
Este programa cria um tabuleiro 10x10 de Batalha Naval,
posiciona dois navios (dois horizontais/verticais)
e exibe o tabuleiro no console.
*/


int main() {
    // Declaração da matriz 10x10 para o tabuleiro
    int tabuleiro[10][10];
    
    // Inicializar o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    // Posicionar navio horizontal (linha 2, colunas 1, 2, 3)
    tabuleiro[2][3] = 3;
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    
    // Posicionar navio vertical (linhas 5, 6, 7, coluna 7)
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;
    
    // Exibir o tabuleiro
    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    printf("0 = Agua, 3 = Navio\n\n");
    
    // Imprimir letras das colunas (A-J)
    printf("  ");
    for (int j = 0; j < 10; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");
    
    // Imprimir o tabuleiro com números das linhas (1-10)
    for (int i = 0; i < 10; i++) {
        printf("%d ", i + 1);  // Número da linha começando em 1
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    } 

    return 0;
}
