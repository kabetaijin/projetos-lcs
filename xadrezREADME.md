# Simulação de Movimento de Peças de Xadrez em C

## Descrição

Este programa em C simula o movimento de três peças de xadrez: a Torre, o Bispo e a Rainha. O objetivo principal é demonstrar o uso de diferentes estruturas de repetição (`for`, `while` e `do-while`) para controlar a lógica de movimentação de cada peça, imprimindo no console a direção do movimento a cada "casa" percorrida.

Este projeto foi desenvolvido como um exercício prático para aplicar conceitos fundamentais da linguagem C, focando em estruturas de repetição e organização básica de código com funções.

## Peças e Movimentos Simulados

O programa simula os seguintes movimentos:

* **Torre:**
    * **Estrutura de Repetição Utilizada:** `for`
    * **Movimento Simulado:** 5 casas para a direita.
    * **Saída por Passo:** `Direita`
* **Bispo:**
    * **Estrutura de Repetição Utilizada:** `while`
    * **Movimento Simulado:** 5 casas na diagonal para cima e à direita.
    * **Saída por Passo:** `Cima, Direita`
* **Rainha:**
    * **Estrutura de Repetição Utilizada:** `do-while`
    * **Movimento Simulado:** 8 casas para a esquerda.
    * **Saída por Passo:** `Esquerda`

## Como Compilar e Executar

### Pré-requisitos

* Um compilador C instalado no seu sistema (ex: GCC, Clang, MinGW para Windows, ou o compilador do Visual Studio).

### Passos para Compilação

1.  **Salve o código:** Certifique-se de que o código-fonte esteja salvo em um arquivo com a extensão `.c` (por exemplo, `xadrez_movimentos.c`).
2.  **Abra o terminal ou prompt de comando:** Navegue até o diretório onde você salvou o arquivo.
3.  **Compile o código:**
    * Se estiver usando **GCC** (comum em Linux, macOS, ou com MinGW no Windows):
        ```bash
        gcc xadrez_movimentos.c -o xadrez_movimentos
        ```
    * Se estiver usando o compilador do **Visual Studio** (MSVC), abra o "Developer Command Prompt for VS" e digite:
        ```bash
        cl xadrez_movimentos.c
        ```
        (Isso geralmente criará um `xadrez_movimentos.exe`)

### Passos para Execução

1.  Após a compilação bem-sucedida, um arquivo executável será gerado. Para executá-lo:
    * No **Linux ou macOS** (se você usou GCC e nomeou a saída como `xadrez_movimentos`):
        ```bash
        ./xadrez_movimentos
        ```
    * No **Windows** (o nome do executável será `xadrez_movimentos.exe` ou o nome que você especificou):
        ```bash
        xadrez_movimentos.exe
        ```
        ou simplesmente
        ```bash
        xadrez_movimentos
        ```

## Estrutura do Código

O código está organizado da seguinte maneira:

* **Constantes Globais:** `CASAS_TORRE`, `CASAS_BISPO`, `CASAS_RAINHA` são definidas no início para especificar o número de casas que cada peça se moverá.
* **Função `moverTorre(int casas)`:** Simula o movimento da Torre utilizando um loop `for`.
* **Função `moverBispo(int casas)`:** Simula o movimento do Bispo utilizando um loop `while`.
* **Função `moverRainha(int casas)`:** Simula o movimento da Rainha utilizando um loop `do-while`.
* **Função `main()`:** É a função principal que inicia a execução do programa, chamando as funções de movimento para cada peça e exibindo mensagens introdutórias.

## Objetivos de Aprendizagem

Este projeto visa reforçar o entendimento sobre:
* A sintaxe e o uso das estruturas de repetição `for`, `while` e `do-while` na linguagem C.
* A criação e chamada de funções para modularizar o código.
* O uso da função `printf` para exibir informações no console.
* A importância de escrever código claro, bem comentado e organizado.

## Tecnologias Utilizadas

* Linguagem C

---
