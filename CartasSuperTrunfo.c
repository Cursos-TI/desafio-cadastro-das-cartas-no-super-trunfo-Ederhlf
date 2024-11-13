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
    float pib; // PIB da cidade em reais
    int pontos_turisticos; // Número de pontos turísticos
    float densidade_populacional; // Densidade Populacional
    double pib_per_capita; // PIB per capita
} Cidade;

// Função para calcular a densidade populacional 
float calcularDensidadePopulacional(Cidade cidade) {
    if (cidade.area > 0) {
        return cidade.populacao / cidade.area;
    } else {
        return 0.0;
    }
}

// Função para calcular o PIB 
double calcularPIBPerCapita(Cidade cidade) {
    if (cidade.populacao > 0) {
        return (float) cidade.pib / cidade.populacao;
    } else {
        return 0.0;
    }
}


// Função para calcular o "Super Poder" de uma carta (soma de todas as propriedades principais)
void calcularSuperPoder(Cidade cidade1, Cidade cidade2) {
    double c1 = cidade1.populacao + cidade1.area + cidade1.pib + cidade1.pontos_turisticos;
    double c2 = cidade2.populacao + cidade2.area + cidade2.pib + cidade2.pontos_turisticos;
        printf("\nComparação de Super Trunfo:\n");
        printf("cidade1 %2.f vs %2.f cidade2 \n", c1, c2);

    if (c1 > c2) {
        printf("%s vence\n", cidade1.codigo);
    } else if (c1 < c2) {
        printf("%s vence\n", cidade2.codigo);
    } else {
        printf("Empate\n");
    }

}

// Função para comparar duas cartas
void compararCartas(Cidade cidade1, Cidade cidade2) {
    printf("\nComparação de Cartas:\n");
    
    // Comparação de cada propriedade
    printf("População: %d vs %d -> ", cidade1.populacao, cidade2.populacao);
    if (cidade1.populacao > cidade2.populacao) {
        printf("%s vence\n", cidade1.codigo);
    } else if (cidade1.populacao < cidade2.populacao) {
        printf("%s vence\n", cidade2.codigo);
    } else {
        printf("Empate\n");
    }

    printf("Área: %.15lf km² vs %.15lf km² -> ", cidade1.area, cidade2.area);
    if (cidade1.area > cidade2.area) {
        printf("%s vence\n", cidade1.codigo);
    } else if (cidade1.area < cidade2.area) {
        printf("%s vence\n", cidade2.codigo);
    } else {
        printf("Empate\n");
    }

    printf("PIB: R$ %.15lf vs R$ %.15lf -> ", cidade1.pib, cidade2.pib);
    if (cidade1.pib > cidade2.pib) {
        printf("%s vence\n", cidade1.codigo);
    } else if (cidade1.pib < cidade2.pib) {
        printf("%s vence\n", cidade2.codigo);
    } else {
        printf("Empate\n");
    }

    printf("Pontos Turísticos: %d vs %d -> ", cidade1.pontos_turisticos, cidade2.pontos_turisticos);
    if (cidade1.pontos_turisticos > cidade2.pontos_turisticos) {
        printf("%s vence\n", cidade1.codigo);
    } else if (cidade1.pontos_turisticos < cidade2.pontos_turisticos) {
        printf("%s vence\n", cidade2.codigo);
    } else {
        printf("Empate\n");
    }

    printf("Densidade Populacional: %.15lf vs %.15lf -> ", cidade1.densidade_populacional, cidade2.densidade_populacional);
    if (cidade1.densidade_populacional < cidade2.densidade_populacional) {
        printf("%s vence\n", cidade1.codigo);
    } else if (cidade1.densidade_populacional > cidade2.densidade_populacional) {
        printf("%s vence\n", cidade2.codigo);
    } else {
        printf("Empate\n");
    }
}

int main() {
   Cidade cidades[NUM_ESTADOS * CIDADES_POR_ESTADO];
    int totalCidades = 0;
    int opcao;

    printf("=== Cadastro de Cartas do Jogo Super Trunfo - Países ===\n");

    do {
        // Exibe o menu para o usuário escolher a ação
        printf("Escolha uma opção:\n");
        printf("1 - Criar nova carta\n");
        printf("2 - Ver lista de cartas cadastradas\n");
        printf("3 - Comparar cards\n");
        printf("4 - Sair\n");

        printf("Opção: \n ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Definindo o código da cidade (ex: A01, B02)
            int estadoIdx = totalCidades / CIDADES_POR_ESTADO;
            int cidadeIdx = totalCidades % CIDADES_POR_ESTADO;
            char estado = 'A' + estadoIdx;
            snprintf(cidades[totalCidades].codigo, sizeof(cidades[totalCidades].codigo), "%c%02d", estado, cidadeIdx + 1);

            // Solicita e lê os dados da cidade pelo terminal
            printf("Cadastro da cidade %s\n", cidades[totalCidades].codigo);

            printf("Nome da cidade: ");
            scanf(" %[^\n]", cidades[totalCidades].nomeCidade); // Lê o nome da cidade com espaços

            printf("População: ");
            scanf("%d", &cidades[totalCidades].populacao);

            printf("Área (em km²): ");
            scanf("%f", &cidades[totalCidades].area);

            printf("PIB (em reais): ");
            scanf("%f", &cidades[totalCidades].pib);

            printf("Número de pontos turísticos: ");
            scanf("%d", &cidades[totalCidades].pontos_turisticos);

            // Calcula densidade populacional e PIB per capita
            cidades[totalCidades].densidade_populacional = calcularDensidadePopulacional(cidades[totalCidades]);
            cidades[totalCidades].pib_per_capita = calcularPIBPerCapita(cidades[totalCidades]);

            // Exibe os resultados logo após o cálculo
            printf("Densidade Populacional calculada: %.2f hab/km²\n", cidades[totalCidades].densidade_populacional);
            printf("PIB per Capita calculado: R$ %.8lf\n", cidades[totalCidades].pib_per_capita);
            printf("-------------------------\n");

            totalCidades++; // Incrementa o contador de cartas
        } else if (opcao == 2) {
            // Exibição das cidades cadastradas
            printf("\n=== Exibição das Cartas Cadastradas ===\n");
            for (int i = 0; i < totalCidades; i++) {
                printf("Código: %s\n", cidades[i].codigo);
                printf("Nome: %s\n", cidades[i].nomeCidade);
                printf("População: %d\n", cidades[i].populacao);
                printf("Área: %.2f km²\n", cidades[i].area);
                printf("PIB: R$ %.2f\n", cidades[i].pib);
                printf("Pontos turísticos: %d\n", cidades[i].pontos_turisticos);
                printf("Densidade Populacional: %.2f hab/km²\n", cidades[i].densidade_populacional);
                printf("PIB per Capita: R$ %.8f\n", cidades[i].pib_per_capita);
                printf("-------------------------\n");
            }
        } else if (opcao == 3) {
             if (totalCidades < 2) {
                printf("É necessário cadastrar pelo menos duas cartas para comparar.\n");
                continue;
            }
          
            int opcaoTrunfo;

            printf("Deseja usar Super trunfo?\n");
            printf("1 - sim\n");
            printf("2 - não\n");

            printf("Deseja usar Super trunfo?\n");
            scanf("%d", &opcaoTrunfo );

           
            int indice1, indice2;
            printf("Digite o índice da primeira carta para comparar (0 a %d): ", totalCidades);
            scanf("%d", &indice1 );
            printf("Digite o índice da segunda carta para comparar (0 a %d): ", totalCidades );
            scanf("%d", &indice2 );
             indice1 -= 1;
             indice2 -= 1;

              if (opcaoTrunfo == 1) {
                calcularSuperPoder(cidades[indice1], cidades[indice2]);
            }

            if (indice1 >= 0 && indice1 < totalCidades && indice2 >= 0 && indice2 < totalCidades && indice1 != indice2) {
                compararCartas(cidades[indice1], cidades[indice2]);
            } else {
                printf("Índices inválidos!\n");
            }

        } else {
            printf("Opção inválida! Por favor, escolha 1 ou 2.\n");
        }

    } while (opcao != 4);

    printf("Saiu do jogo.\n");

    return 0;
}