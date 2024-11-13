#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define MAX_NOME_CIDADE 50

typedef struct {
    char codigo[4]; // Código da cidade, como "A01"
    char nomeCidade[MAX_NOME_CIDADE]; // Nome da cidade
    int populacao; // População da cidade
    float area; // Área da cidade em km²
    float pib; // PIB da cidade em reais (use float para incluir centavos)
    int pontos_turisticos; // Número de pontos turísticos
} Cidade;

int main() {
    Cidade cidades[NUM_ESTADOS][CIDADES_POR_ESTADO];
    char estado;
    int cidade;

    printf("=== Cadastro de Cartas do Jogo Super Trunfo - Países ===\n");

    // Cadastro das cidades diretamente no main
    for (int i = 0; i < NUM_ESTADOS; i++) {
        estado = 'A' + i;  // Define a letra do estado (A, B, C, ..., H)
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            cidade = j + 1;

            // Definindo o código da cidade (ex: A01, B02)
            snprintf(cidades[i][j].codigo, sizeof(cidades[i][j].codigo), "%c%02d", estado, cidade);

            // Solicita e lê os dados da cidade pelo terminal
            printf("Cadastro da cidade %s\n", cidades[i][j].codigo);

            printf("Nome da cidade: ");
            scanf(" %[^\n]", cidades[i][j].nomeCidade); // Lê o nome da cidade com espaços

            printf("População: ");
            scanf("%d", &cidades[i][j].populacao);

            printf("Área (em km²): ");
            scanf("%f", &cidades[i][j].area);

            printf("PIB (em reais): ");
            scanf("%f", &cidades[i][j].pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &cidades[i][j].pontos_turisticos);

            printf("\n");
        }
    }

    // Exibição das cidades cadastradas
    printf("\n=== Exibição das Cartas ===\n");
    for (int i = 0; i < NUM_ESTADOS; i++) {
        for (int j = 0; j < CIDADES_POR_ESTADO; j++) {
            printf("Código: %s\n", cidades[i][j].codigo);
            printf("Nome: %s\n", cidades[i][j].nomeCidade);
            printf("População: %d\n", cidades[i][j].populacao);
            printf("Área: %.2f km²\n", cidades[i][j].area);
            printf("PIB: R$ %.2f\n", cidades[i][j].pib); // Exibe o PIB com duas casas decimais e símbolo de reais
            printf("Pontos turísticos: %d\n", cidades[i][j].pontos_turisticos);
            printf("-------------------------\n");
        }
    }

    return 0;
}
