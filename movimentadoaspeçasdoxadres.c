#include <stdio.h>

// -------------------------------------------
// Movimentação do Cavalo no tabuleiro
// (2 pra baixo e 1 pra esquerda)
// -------------------------------------------

// constantes com o número de passos
const int MOV_BAIXO = 2;
const int MOV_ESQUERDA = 1;

// função que faz o movimento do cavalo
void moverCavalo() {
    printf("\nMovimento do Cavalo (2 baixo, 1 esquerda)\n");

    // loop for = responsável pelas 2 casas pra baixo
    for (int i = 0; i < MOV_BAIXO; i++) {
        printf("Baixo\n");

        // quando chegar na última descida, faz o movimento pra esquerda
        if (i == MOV_BAIXO - 1) {
            int j = 0;
            while (j < MOV_ESQUERDA) {
                printf("Esquerda\n");
                j++;
            }
        }
    }
}

int main() {
    moverCavalo();

    // só pra mostrar outros movimentos (não faz parte principal)
    printf("\nOutros movimentos (exemplo):\n");
    printf("Cima\n");
    printf("Direita\n");

    return 0;
}
