#include <stdio.h> // Biblioteca padrão para entrada e saída de dados (ex: printf)

// Constantes para definir o número de casas que cada peça moverá
const int CASAS_TORRE = 5;
const int CASAS_BISPO = 5;
const int CASAS_RAINHA = 8;

/**
 * @brief Simula o movimento da Torre.
 * A Torre move-se em linha reta. Neste caso, 5 casas para a direita.
 * Utiliza um loop 'for'.
 *
 * @param casas Número de casas que a Torre se moverá.
 */
void moverTorre(int casas) {
    printf("--- Movimento da Torre ---\n");
    // Loop 'for' para simular o movimento casa por casa
    // 'i' é o contador de casas percorridas
    for (int i = 0; i < casas; i++) {
        printf("Direita\n"); // Imprime a direção do movimento
    }
}

/**
 * @brief Simula o movimento do Bispo.
 * O Bispo move-se na diagonal. Neste caso, 5 casas na diagonal para cima e à direita.
 * Utiliza um loop 'while'.
 *
 * @param casas Número de casas que o Bispo se moverá.
 */
void moverBispo(int casas) {
    printf("--- Movimento do Bispo ---\n");
    int casasPercorridas = 0; // Contador para as casas já percorridas

    // Loop 'while' para simular o movimento casa por casa
    // Continua enquanto o número de casas percorridas for menor que o total
    while (casasPercorridas < casas) {
        printf("Cima, Direita\n"); // Imprime a direção do movimento diagonal
        casasPercorridas++;        // Incrementa o contador de casas percorridas
    }
}

/**
 * @brief Simula o movimento da Rainha.
 * A Rainha move-se em linha reta ou diagonal. Neste caso, 8 casas para a esquerda.
 * Utiliza um loop 'do-while'.
 *
 * @param casas Número de casas que a Rainha se moverá.
 */
void moverRainha(int casas) {
    printf("--- Movimento da Rainha ---\n");
    int casasPercorridas = 0; // Contador para as casas já percorridas

    // Verifica se há casas a percorrer para evitar execução desnecessária se casas for 0
    if (casas <= 0) {
        printf("Nenhuma casa para mover.\n");
        return;
    }

    // Loop 'do-while' para simular o movimento casa por casa
    // O bloco de código é executado pelo menos uma vez, e depois a condição é verificada
    do {
        printf("Esquerda\n");       // Imprime a direção do movimento
        casasPercorridas++;        // Incrementa o contador de casas percorridas
    } while (casasPercorridas < casas); // Continua enquanto não atingir o total de casas
}

int main() {
    // Mensagem inicial do programa
    printf("Simulacao de Movimento de Pecas de Xadrez:\n\n");

    // Simula o movimento da Torre
    moverTorre(CASAS_TORRE);
    printf("\n"); // Adiciona uma linha em branco para melhor formatação

    // Simula o movimento do Bispo
    moverBispo(CASAS_BISPO);
    printf("\n"); // Adiciona uma linha em branco

    // Simula o movimento da Rainha
    moverRainha(CASAS_RAINHA);
    printf("\n"); // Adiciona uma linha em branco

    return 0; // Indica que o programa terminou com sucesso
}