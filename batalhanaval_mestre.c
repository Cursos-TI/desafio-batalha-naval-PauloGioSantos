#include <stdio.h>
#include <stdlib.h>

/*
Desafio Batalha Naval - Nível Aventureiro
Autor: Paulo Giovani dos Santos
Descrição:
Este programa cria um tabuleiro 10x10 de Batalha Naval,
posiciona quatro navios (dois horizontais/verticais e dois diagonais)
e exibe o tabuleiro no console. Áreas de habilidade = 5 (cone, cruz, octaedro).
Matrizes de habilidade geradas dinamicamente com loops e condicionais.
Sobreposição centrada em um ponto de origem (com validação de limites).
*/

#define TAM 10      // Tamanho do tabuleiro
#define AGUA 0      // Água
#define NAVIO 3     // Parte de navio
#define HABIL 5     // Área afetada por habilidade


// Função: imprimir_tabuleiro
// Exibe o tabuleiro com legenda e cabeçalho (A-J / 1-10).

void imprimir_tabuleiro(int tab[TAM][TAM]) {
    printf("=== TABULEIRO BATALHA NAVAL - NIVEL MESTRE ===\n");
    printf("Legenda -> %d = Agua | %d = Navio | %d = Area de Habilidade\n\n", AGUA, NAVIO, HABIL);

    // Cabeçalho com letras A-J
    printf("   ");
    for (int c = 0; c < TAM; c++) {
        printf(" %c", 'A' + c);
    }
    printf("\n");

    // Linhas numeradas
    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf(" %d", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Funções que geram as matrizes das habilidades
// Todas usam loops + condicionais conforme solicitado.

// Cone: centro expande para baixo
void gerar_cone(int n, int m[n][n]) {
    int centro = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(j - centro) <= i) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
}

// Cruz: formato de + com centro no meio
void gerar_cruz(int n, int m[n][n]) {
    int centro = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == centro || j == centro) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
}

// Octaedro: formato de losango (diamante)
void gerar_octaedro(int n, int m[n][n]) {
    int centro = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
}

// ---------------------------------------------------------
// Função: aplicar_habilidade
// Sobrepõe uma matriz de habilidade no tabuleiro,
// posicionando pelo ponto de origem informado.
// ---------------------------------------------------------
void aplicar_habilidade(int tab[TAM][TAM], int n, int masc[n][n],
                        int origem_linha, int origem_coluna) {

    int centro = n / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (masc[i][j] != 1) continue;

            int linha = origem_linha - centro + i;
            int coluna = origem_coluna - centro + j;

            // Garantir que está dentro do tabuleiro
            if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) continue;

            // Só aplica habilidade em água → não sobrescreve navio
            if (tab[linha][coluna] == AGUA) {
                tab[linha][coluna] = HABIL;
            }
        }
    }
}

int main() {

    int tab[TAM][TAM];

    // ---------------------------------------------------------
    // 1) Inicializar o tabuleiro com água
    // ---------------------------------------------------------
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tab[i][j] = AGUA;

    // ---------------------------------------------------------
    // 2) Posicionar quatro navios de tamanho 3
    //    Dois horizontais/verticais + dois diagonais
    // ---------------------------------------------------------

    // Navio horizontal (linha 2)
    tab[1][1] = NAVIO;
    tab[1][2] = NAVIO;
    tab[1][3] = NAVIO;

    // Navio vertical (coluna 7)
    tab[5][7] = NAVIO;
    tab[6][7] = NAVIO;
    tab[7][7] = NAVIO;

    // Navio diagonal ↘
    tab[0][5] = NAVIO;
    tab[1][6] = NAVIO;
    tab[2][7] = NAVIO;

    // Navio diagonal ↙
    tab[9][2] = NAVIO;
    tab[8][3] = NAVIO;
    tab[7][4] = NAVIO;

    // ---------------------------------------------------------
    // 3) Criar matrizes das habilidades (cone, cruz, octaedro)
    // ---------------------------------------------------------
    int tamanho = 5; // Pode ser 5 ou 7
    int cone[tamanho][tamanho];
    int cruz[tamanho][tamanho];
    int octa[tamanho][tamanho];

    gerar_cone(tamanho, cone);
    gerar_cruz(tamanho, cruz);
    gerar_octaedro(tamanho, octa);

    // ---------------------------------------------------------
    // 4) Definir pontos de origem das habilidades
    // ---------------------------------------------------------
    int origem_cone_l = 4, origem_cone_c = 1;
    int origem_cruz_l = 8, origem_cruz_c = 0;
    int origem_octa_l = 3, origem_octa_c = 8;

    // ---------------------------------------------------------
    // 5) Aplicar habilidades no tabuleiro
    // ---------------------------------------------------------
    aplicar_habilidade(tab, tamanho, cone, origem_cone_l, origem_cone_c);
    aplicar_habilidade(tab, tamanho, cruz, origem_cruz_l, origem_cruz_c);
    aplicar_habilidade(tab, tamanho, octa, origem_octa_l, origem_octa_c);

    // ---------------------------------------------------------
    // 6) Exibir tabuleiro final
    // ---------------------------------------------------------
    imprimir_tabuleiro(tab);

    return 0;
}
