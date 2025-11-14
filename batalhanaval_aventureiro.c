#include <stdio.h>

/*
Desafio Batalha Naval - Nível Aventureiro
Autor: Paulo Giovani dos Santos
Descrição:
Este programa cria um tabuleiro 10x10 de Batalha Naval,
posiciona quatro navios (dois horizontais/verticais e dois diagonais)
e exibe o tabuleiro no console.

*/

int main() {
    // Declaração do tabuleiro 10x10
    int tabuleiro[10][10];

    // 1. Inicializar todas as posições com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Navio 1 (horizontal) linha 5, colunas 1, 2, 3
    tabuleiro[4][1] = 3;
    tabuleiro[4][2] = 3;
    tabuleiro[4][3] = 3;

    // Navio 2 (vertical) linhas 6, 7, 8, coluna H
    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Navio 3 (diagonal principal) da esquerda para a direita
    // começa em (0,0)
    tabuleiro[0][5] = 3;
    tabuleiro[1][6] = 3; 
    tabuleiro[2][7] = 3;

    // Navio 4 (diagonal inversa) da direita para a esquerda
    // começa em (0,9)
    tabuleiro[9][2] = 3;
    tabuleiro[8][3] = 3;
    tabuleiro[7][4] = 3;

    printf("=== TABULEIRO BATALHA NAVAL ===\n");
    printf("0 = Agua, 3 = Navio\n\n");

    // Cabeçalho com letras das colunas (A-J)
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf(" %c", 'A' + j);
    }
    printf("\n");

    // Linhas numeradas (1 a 10)
    for (int i = 0; i < 10; i++) {
        printf("%2d ", i + 1); // número da linha
        for (int j = 0; j < 10; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
