#include <stdio.h>

// MAPA
#define linha 10
#define coluna 10

// Barco Horizontal
#define Barco_H_X 2 
#define Barco_H_Y 7

// Barco Vertical
#define Barco_V_X 5
#define Barco_V_Y 1

// Barco Diagonal Esquerda
#define Barco_DE_X 0 
#define Barco_DE_Y 2

// Braco Diagonal Direita
#define Barco_DD_X 3
#define Barco_DD_Y 2


int main() {
    // Variaveis
    char Coordenadas_Colunas [10] = {'A','B','C','D','E','F','G','H','I','J'};
    char Coordenadas_Linhas [10] = {'0','1','2','3','4','5','6','7','8','9'};
    int l, c;
    int found = 0;
    int matriz_final[10][10],matriz_inicial[10][10];
    int navio[3][3] = {{3, 3, 3},{3, 3, 3},{3, 3, 3}};
    int hab_cone[5][5] = {{0, 0, 1, 0, 0},{0, 1, 1, 1, 0},{1, 1, 1, 1, 1},};
    int hab_cruz[5][5] = {{0, 0, 1, 0, 0},{0, 1, 1, 1, 0},{0, 0, 1, 0, 0},};
    int hab_octaedro[5][5] = {{0, 0, 1, 0, 0},{1, 1, 1, 1, 1},{0, 0, 1, 0, 0},};

 // Criando a Matriz
    for(l = 0; l < linha; l++){
        for(c = 0; c < coluna; c++){
            matriz_inicial[l][c] = 0;
            matriz_final[l][c] = 0;
        }
    }
    

    // Loop para Imprimir os Navios
    for (l = 0, c = 0; l > 3, c < 3; l++, c++){

        // Barco Horizontal
        if (matriz_final[l+Barco_DE_X][Barco_DE_Y-c] == 0){
            matriz_final[l+Barco_DE_X][Barco_DE_Y-c] = matriz_inicial[l][c] + navio[l][c];
            found = 1;
        }
        if (!found) {
            printf("a Posição %d \n", matriz_final[l+Barco_DE_X][Barco_DE_Y-c]);
        }

        // Barco Vertical
        if (matriz_final[Barco_DD_X+l][Barco_DD_Y+c] == 0){
            matriz_final[Barco_DD_X+l][Barco_DD_Y+c] = matriz_inicial[l][c] + navio[l][c];
            found = 1;
        }
        if (!found) {
            printf("a Posição %d \n", matriz_final[Barco_DD_X+l][Barco_DD_Y+c]);
        
        }

        // Barco Diagonal Esquerda
        if (matriz_final[Barco_H_X][c+Barco_H_Y] == 0){
            matriz_final[Barco_H_X][c+Barco_H_Y] = matriz_inicial[l][c] + navio[0][c];
            found = 1;
        }
        if (!found) {
            printf("a Posição %d \n", matriz_final[Barco_H_X][c+Barco_H_Y]);
        
        }

        // Barco Diagonal Direita
        if (matriz_final[l+Barco_V_X][Barco_V_Y] == 0){
            matriz_final[l+Barco_V_X][Barco_V_Y] = matriz_inicial[l][c] + navio[c][0];
            found = 1;
        }
        if (!found) {
            printf("a Posição %d \n", matriz_final[l+Barco_V_X][Barco_V_Y]);
        
        }
    }
    // Loop para mesclar a Matriz de Habilidade (deixei com que ficasse a soma entre os numerais, deixando )
    for (l = 0; l < 5; l++){
        for(c = 0; c < 5; c++){

            //Habilidade CRUZ
            matriz_final[4+l][4+c] = matriz_final[4+l][4+c] + hab_cruz[l][c];
            if (matriz_final[4+l][4+c] == 4){
                printf("A Habilidade acertou o navio nas posições Linha[%d] Coluna[%d]\n", 4+l, 4+c);
            }
            //Habilidade CONE
            matriz_final[l][c] = matriz_final[l][c] + hab_cone[l][c];
            if (matriz_final[l][c] == 4){
                printf("A Habilidade acertou o navio nas posições Linha[%d] Coluna[%d]\n", l, c);
            }
            //Habilidade OCTAEDRO
            matriz_final[1+l][5+c] = matriz_final[1+l][5+c] + hab_octaedro[l][c];
            if (matriz_final[1+l][5+c] == 4){
                printf("A Habilidade acertou o navio nas posições Linha[%d] Coluna[%d]\n", 1+l, 5+c);
            }
        }
    }

// Coordenadas
    for (l = 0; l < linha; l++){
        printf(" %c", Coordenadas_Linhas[l]);
    }

// Imprimindo a Matris
    printf("\n");
    for(l = 0; l < linha; l++){
        for(c = 0; c < coluna; c++){
            printf(" %d", matriz_final[l][c]);
        }
        printf(" - %c", Coordenadas_Linhas[l]);
        printf("\n");
    }
    return 0;
}
