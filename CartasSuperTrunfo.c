#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
typedef struct {
    char estado[50];
    char codigo[20];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para calcular a densidade populacional
float calcularDensidadePopulacional(Carta carta) {
    return carta.populacao / carta.area;
}

// Função para calcular o PIB per capita
float calcularPIBPerCapita(Carta carta) {
    return carta.pib / carta.populacao;
}

// Função para comparar e determinar a carta vencedora
void compararCartas(Carta carta1, Carta carta2) {
    // Escolha fixa do atributo para comparação (pode ser alterado conforme necessário)
    char atributoComparado[] = "Populacao"; // Alterar para "Area", "PIB", "Densidade Populacional" ou "PIB per capita" conforme desejado
    float valor1, valor2;
    int menorVence = 0; // 1 se o menor valor vence (para Densidade Populacional)

    if (strcmp(atributoComparado, "Populacao") == 0) {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
    } else if (strcmp(atributoComparado, "Area") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
    } else if (strcmp(atributoComparado, "PIB") == 0) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
    } else if (strcmp(atributoComparado, "Densidade Populacional") == 0) {
        valor1 = calcularDensidadePopulacional(carta1);
        valor2 = calcularDensidadePopulacional(carta2);
        menorVence = 1;
    } else if (strcmp(atributoComparado, "PIB per capita") == 0) {
        valor1 = calcularPIBPerCapita(carta1);
        valor2 = calcularPIBPerCapita(carta2);
    } else {
        printf("Atributo desconhecido!\n");
        return;
    }

    // Determinação do vencedor
    printf("\nComparacao de cartas (Atributo: %s):\n\n", atributoComparado);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valor2);

    if ((menorVence && valor1 < valor2) || (!menorVence && valor1 > valor2)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if ((menorVence && valor2 < valor1) || (!menorVence && valor2 > valor1)) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Definição das cartas pré-definidas
    Carta carta1 = {"SP", "001", "Sao Paulo", 12300000, 1521.11, 699000000000, 10};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.27, 362000000000, 8};

    // Comparação das cartas
    compararCartas(carta1, carta2);

    return 0;
}
