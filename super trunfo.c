#include <stdio.h>
#include <stdlib.h> // Para system("cls") ou system("clear")
#include <string.h> // Para strcpy (não usado diretamente aqui, mas bom para futuras expansões)
#include <float.h>  // Para constantes de ponto flutuante, se necessário

// Define a estrutura para a carta do país
typedef struct {
    char nome[50];
    double area;          // km²
    long int populacao;
    double pib;           // em trilhões de USD
    double idh;
    double densidade;     // habitantes/km²
} CartaPais;

// Protótipos das funções
void exibirAtributosDisponiveis(int atributoJaEscolhido);
int escolherAtributo(const char* prompt, int atributoJaEscolhido);
const char* nomeAtributo(int escolha);
double valorAtributo(CartaPais carta, int escolha);
int comparaAtributoIndividual(double valorA, double valorB, int atributo_idx_regra_densidade);
void exibirResultadoComparacao(CartaPais c1, CartaPais c2, int atr1_idx, int atr2_idx);

// Define o comando para limpar a tela com base no sistema operacional
#if defined(_WIN32) || defined(_WIN64)
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

int main() {
    // Pré-cadastrar duas cartas (exemplo)
    CartaPais carta1 = {"Brasil", 8515767.0, 214300000, 1.92, 0.754, 0.0};
    carta1.densidade = (carta1.area > 0) ? (double)carta1.populacao / carta1.area : 0.0; // Operador ternário para cálculo seguro

    CartaPais carta2 = {"Japao", 377975.0, 125700000, 4.23, 0.925, 0.0};
    carta2.densidade = (carta2.area > 0) ? (double)carta2.populacao / carta2.area : 0.0; // Operador ternário

    int atributo1 = 0, atributo2 = 0;

    system(CLEAR_SCREEN);
    printf("--- SUPER TRUNFO - DESAFIO FINAL ---\n\n");
    printf("Carta Jogador 1: %s\n", carta1.nome);
    printf("  Area: %.0f km^2\n", carta1.area);
    printf("  Populacao: %ld\n", carta1.populacao);
    printf("  PIB: %.2f Trilhoes USD\n", carta1.pib);
    printf("  IDH: %.3f\n", carta1.idh);
    printf("  Densidade: %.2f hab/km^2\n\n", carta1.densidade);

    printf("Carta Jogador 2: %s\n", carta2.nome);
    printf("  Area: %.0f km^2\n", carta2.area);
    printf("  Populacao: %ld\n", carta2.populacao);
    printf("  PIB: %.2f Trilhoes USD\n", carta2.pib);
    printf("  IDH: %.3f\n", carta2.idh);
    printf("  Densidade: %.2f hab/km^2\n\n", carta2.densidade);

    printf("Jogador, escolha os atributos para comparar:\n\n");

    // Escolha do primeiro atributo
    atributo1 = escolherAtributo("Escolha o PRIMEIRO atributo (1-5): ", 0);
    system(CLEAR_SCREEN);

    printf("--- SUPER TRUNFO - DESAFIO FINAL ---\n\n");
    printf("Carta Jogador 1: %s\n", carta1.nome);
    printf("Carta Jogador 2: %s\n\n", carta2.nome);
    printf("Primeiro atributo escolhido: %s\n\n", nomeAtributo(atributo1));

    // Escolha do segundo atributo
    atributo2 = escolherAtributo("Escolha o SEGUNDO atributo (1-5, diferente do primeiro): ", atributo1);
    system(CLEAR_SCREEN);

    // Exibir resultado da comparação
    exibirResultadoComparacao(carta1, carta2, atributo1, atributo2);

    return 0;
}

/**
 * @brief Exibe os atributos disponíveis para escolha, omitindo um atributo já escolhido.
 *
 * @param atributoJaEscolhido O índice do atributo já escolhido (1-5), ou 0 se nenhum foi escolhido.
 */
void exibirAtributosDisponiveis(int atributoJaEscolhido) {
    printf("Atributos disponiveis:\n");
    if (atributoJaEscolhido != 1) printf("  1. Area (km^2)\n");
    if (atributoJaEscolhido != 2) printf("  2. Populacao\n");
    if (atributoJaEscolhido != 3) printf("  3. PIB (Trilhoes USD)\n");
    if (atributoJaEscolhido != 4) printf("  4. IDH\n");
    if (atributoJaEscolhido != 5) printf("  5. Densidade Demografica (hab/km^2)\n"); // Menor é melhor
}

/**
 * @brief Permite ao jogador escolher um atributo, garantindo que não seja um já selecionado.
 *
 * @param prompt Mensagem a ser exibida ao jogador.
 * @param atributoJaEscolhido O índice do atributo já escolhido (1-5), ou 0 se nenhum foi escolhido.
 * @return int O índice do atributo escolhido (1-5).
 */
int escolherAtributo(const char* prompt, int atributoJaEscolhido) {
    int escolha = 0;
    int valido = 0;

    do {
        exibirAtributosDisponiveis(atributoJaEscolhido);
        printf("%s", prompt);

        // Validação da entrada
        if (scanf("%d", &escolha) != 1) {
            printf("\nEntrada invalida. Por favor, insira um numero.\n\n");
            while (getchar() != '\n'); // Limpar buffer de entrada
            escolha = 0; // Resetar escolha para forçar nova tentativa
            continue;
        }
        while (getchar() != '\n'); // Limpar o restante do buffer de entrada

        switch (escolha) {
            case 1: // Area
            case 2: // Populacao
            case 3: // PIB
            case 4: // IDH
            case 5: // Densidade
                if (escolha == atributoJaEscolhido) {
                    printf("\nAtributo ja selecionado! Escolha um atributo diferente.\n\n");
                    valido = 0;
                } else {
                    valido = 1;
                }
                break;
            default:
                printf("\nOpcao invalida! Escolha um numero da lista de atributos disponiveis.\n\n");
                valido = 0;
        }
    } while (!valido);
    return escolha;
}

/**
 * @brief Retorna o nome de um atributo com base no seu índice.
 *
 * @param escolha O índice do atributo (1-5).
 * @return const char* O nome do atributo.
 */
const char* nomeAtributo(int escolha) {
    switch (escolha) {
        case 1: return "Area";
        case 2: return "Populacao";
        case 3: return "PIB";
        case 4: return "IDH";
        case 5: return "Densidade Demografica";
        default: return "Desconhecido";
    }
}

/**
 * @brief Retorna o valor de um atributo específico de uma carta.
 *
 * @param carta A carta do país.
 * @param escolha O índice do atributo (1-5).
 * @return double O valor do atributo.
 */
double valorAtributo(CartaPais carta, int escolha) {
    switch (escolha) {
        case 1: return carta.area;
        case 2: return (double)carta.populacao; // Cast para double para consistência na soma
        case 3: return carta.pib;
        case 4: return carta.idh;
        case 5: return carta.densidade;
        default: return 0.0; // Não deve acontecer com a validação de entrada
    }
}

/**
 * @brief Compara dois valores para um atributo específico.
 *
 * @param valorA Valor do atributo para a carta A.
 * @param valorB Valor do atributo para a carta B.
 * @param atributo_idx_regra_densidade O índice do atributo (5 para Densidade, outros para regra normal).
 * @return int Retorna 1 se cartaA vence, -1 se cartaB vence, 0 se empate.
 */
int comparaAtributoIndividual(double valorA, double valorB, int atributo_idx_regra_densidade) {
    if (atributo_idx_regra_densidade == 5) { // Densidade: menor é melhor
        if (valorA < valorB) return 1;  // A vence
        if (valorB < valorA) return -1; // B vence
        return 0; // Empate
    } else { // Outros atributos: maior é melhor
        if (valorA > valorB) return 1;  // A vence
        if (valorB < valorA) return -1; // B vence
        return 0; // Empate
    }
}

/**
 * @brief Exibe o resultado detalhado da comparação entre duas cartas com base em dois atributos.
 *
 * @param c1 Carta do jogador 1.
 * @param c2 Carta do jogador 2.
 * @param atr1_idx Índice do primeiro atributo escolhido.
 * @param atr2_idx Índice do segundo atributo escolhido.
 */
void exibirResultadoComparacao(CartaPais c1, CartaPais c2, int atr1_idx, int atr2_idx) {
    printf("--- RESULTADO DA RODADA ---\n\n");
    printf("Paises: %s vs %s\n", c1.nome, c2.nome);
    printf("Atributos Comparados: %s e %s\n\n", nomeAtributo(atr1_idx), nomeAtributo(atr2_idx));

    double val1_c1 = valorAtributo(c1, atr1_idx);
    double val1_c2 = valorAtributo(c2, atr1_idx);
    double val2_c1 = valorAtributo(c1, atr2_idx);
    double val2_c2 = valorAtributo(c2, atr2_idx);

    // Comparação individual do Atributo 1
    printf("Comparacao - %s:\n", nomeAtributo(atr1_idx));
    printf("  %s: %.2f %s\n", c1.nome, val1_c1, (atr1_idx == 5 ? "(Menor e Melhor)" : "(Maior e Melhor)"));
    printf("  %s: %.2f\n", c2.nome, val1_c2);
    int res_comp_atr1 = comparaAtributoIndividual(val1_c1, val1_c2, atr1_idx);
    // Uso do operador ternário para exibir o resultado da comparação individual
    printf("  Resultado para %s: %s\n", c1.nome, (res_comp_atr1 == 1 ? "Venceu este atributo" : (res_comp_atr1 == 0 ? "Empate neste atributo" : "Perdeu este atributo")));
    printf("  Resultado para %s: %s\n\n", c2.nome, (res_comp_atr1 == -1 ? "Venceu este atributo" : (res_comp_atr1 == 0 ? "Empate neste atributo" : "Perdeu este atributo")));

    // Comparação individual do Atributo 2
    printf("Comparacao - %s:\n", nomeAtributo(atr2_idx));
    printf("  %s: %.2f %s\n", c1.nome, val2_c1, (atr2_idx == 5 ? "(Menor e Melhor)" : "(Maior e Melhor)"));
    printf("  %s: %.2f\n", c2.nome, val2_c2);
    int res_comp_atr2 = comparaAtributoIndividual(val2_c1, val2_c2, atr2_idx);
    // Uso do operador ternário
    printf("  Resultado para %s: %s\n", c1.nome, (res_comp_atr2 == 1 ? "Venceu este atributo" : (res_comp_atr2 == 0 ? "Empate neste atributo" : "Perdeu este atributo")));
    printf("  Resultado para %s: %s\n\n", c2.nome, (res_comp_atr2 == -1 ? "Venceu este atributo" : (res_comp_atr2 == 0 ? "Empate neste atributo" : "Perdeu este atributo")));

    // Soma dos valores dos atributos escolhidos para cada carta
    double soma_c1 = val1_c1 + val2_c1;
    double soma_c2 = val1_c2 + val2_c2;

    printf("Soma dos valores dos atributos escolhidos:\n");
    printf("  %s (%s + %s): %.2f + %.2f = %.2f\n", c1.nome, nomeAtributo(atr1_idx), nomeAtributo(atr2_idx), val1_c1, val2_c1, soma_c1);
    printf("  %s (%s + %s): %.2f + %.2f = %.2f\n\n", c2.nome, nomeAtributo(atr1_idx), nomeAtributo(atr2_idx), val1_c2, val2_c2, soma_c2);

    // Resultado final da rodada com base na soma
    printf("--- RESULTADO FINAL DA RODADA ---\n");
    if (soma_c1 > soma_c2) {
        printf("🏆 VENCEDOR: %s com soma %.2f (Soma %s: %.2f)\n", c1.nome, soma_c1, c2.nome, soma_c2);
    } else if (soma_c2 > soma_c1) {
        printf("🏆 VENCEDOR: %s com soma %.2f (Soma %s: %.2f)\n", c2.nome, soma_c2, c1.nome, soma_c1);
    } else {
        printf("🎌 EMPATE! (Soma %s: %.2f, Soma %s: %.2f)\n", c1.nome, soma_c1, c2.nome, soma_c2);
    }
    printf("-------------------------------\n");
}