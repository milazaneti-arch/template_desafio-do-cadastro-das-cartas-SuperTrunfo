#include <stdio.h>
#include <stdlib.h> // Para system("clear") ou system("cls")

// 1. Estrutura para representar uma carta de país
typedef struct {
    char nome[50];
    int populacao; // int
    float area;    // float
    float pib;     // float
    int pontosTuristicos; // int
    float densidadeDemografica; // float (Populacao / Area)
} CartaPais;

// Protótipo da função de comparação
void compararCartas(CartaPais carta1, CartaPais carta2, int escolha);

int main() {
    // 2. Dados de Exemplo (Duas Cartas)
    // Os dados da Densidade Demográfica devem ser pré-calculados (População / Área)
    CartaPais brasil = {"Brasil", 214000000, 8515767.0, 1833000000000.0, 20, 214000000.0 / 8515767.0}; // ~25.13 hab/km²
    CartaPais canada = {"Canadá", 38000000, 9984670.0, 1990000000000.0, 15, 38000000.0 / 9984670.0}; // ~3.81 hab/km²

    int escolha = 0;

    do {
        // Limpa a tela para o menu (opcional, dependendo do terminal)
        // #ifdef _WIN32
        //     system("cls");
        // #else
        //     system("clear");
        // #endif

        printf("\n=== Super Trunfo - Escolha de Atributo ===\n");
        printf("Cartas em jogo: %s vs %s\n\n", brasil.nome, canada.nome);
        printf("Escolha o atributo para a comparação:\n");
        printf("1. População (Maior Valor Vence)\n");
        printf("2. Área (Maior Valor Vence)\n");
        printf("3. PIB (Maior Valor Vence)\n");
        printf("4. Número de Pontos Turísticos (Maior Valor Vence)\n");
        printf("5. Densidade Demográfica (Menor Valor Vence!)\n");
        printf("0. Sair do Jogo\n");
        printf("Sua escolha: ");
        
        // Garante que a leitura da escolha é bem-sucedida
        if (scanf("%d", &escolha) != 1) {
            printf("\nEntrada inválida. Tente novamente.\n");
            // Limpa o buffer de entrada para evitar loops
            while (getchar() != '\n'); 
            continue; 
        }

        // 4. Menu Interativo (switch)
        switch (escolha) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                compararCartas(brasil, canada, escolha);
                break;
            case 0:
                printf("\nObrigado por jogar! Encerrando...\n");
                break;
            default:
                printf("\nOpção inválida. Por favor, escolha um número de 1 a 5, ou 0 para sair.\n");
                break;
        }

        if (escolha != 0) {
            printf("\nPressione ENTER para continuar para o menu...\n");
            // Aguarda o ENTER
            while (getchar() != '\n'); // Limpa a linha pendente do scanf
            getchar(); 
        }

    } while (escolha != 0);

    return 0;
}

// 3. Função de Comparação (Lógica principal com if-else aninhado)
void compararCartas(CartaPais carta1, CartaPais carta2, int escolha) {
    char *atributoNome = "";
    float valor1 = 0;
    float valor2 = 0;
    int regraInvertida = 0; // 0 para maior valor vence, 1 para menor valor vence

    // Define o nome do atributo, os valores e a regra de comparação
    switch (escolha) {
        case 1: // População
            atributoNome = "População";
            valor1 = (float)carta1.populacao;
            valor2 = (float)carta2.populacao;
            break;
        case 2: // Área
            atributoNome = "Área";
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 3: // PIB
            atributoNome = "PIB";
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 4: // Pontos Turísticos
            atributoNome = "Número de Pontos Turísticos";
            valor1 = (float)carta1.pontosTuristicos;
            valor2 = (float)carta2.pontosTuristicos;
            break;
        case 5: // Densidade Demográfica (Regra Invertida)
            atributoNome = "Densidade Demográfica";
            valor1 = carta1.densidadeDemografica;
            valor2 = carta2.densidadeDemografica;
            regraInvertida = 1; // Vence o menor valor!
            break;
    }

    printf("\n--- Resultado da Comparação ---\n");
    printf("Atributo escolhido: %s\n", atributoNome);
    printf("%s valor: %.2f\n", carta1.nome, valor1);
    printf("%s valor: %.2f\n", carta2.nome, valor2);

    // 5. Regras de Comparação (If-Else Aninhado)

    // Verifica primeiro se é um empate
    if (valor1 == valor2) {
        printf("\nResultado: **Empate!**\n");
    } else { 
        // Lógica Principal de Vencedor
        if (regraInvertida == 0) {
            // Regra Geral: Maior Valor Vence
            if (valor1 > valor2) {
                printf("\nResultado: **%s VENCE!** (%.2f > %.2f)\n", carta1.nome, valor1, valor2);
            } else {
                // if (valor2 > valor1) já está implícito
                printf("\nResultado: **%s VENCE!** (%.2f > %.2f)\n", carta2.nome, valor2, valor1);
            }
        } else {
            // Regra Invertida (Densidade Demográfica): Menor Valor Vence
            if (valor1 < valor2) {
                printf("\nResultado: **%s VENCE!** (%.2f < %.2f)\n", carta1.nome, valor1, valor2);
            } else {
                // if (valor2 < valor1) já está implícito
                printf("\nResultado: **%s VENCE!** (%.2f < %.2f)\n", carta2.nome, valor2, valor1);
            }
        }
    }
    printf("------------------------------\n");
}
