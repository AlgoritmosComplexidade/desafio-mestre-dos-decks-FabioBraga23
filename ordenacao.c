#include <stdio.h>
#include <string.h>

// ============================================================
// ARENA DE CÓDIGO - MESTRE DOS DECKS
// NÍVEL NOVATO
// Ordenação da mão de cartas utilizando Insertion Sort
// ============================================================

// Estrutura que representa uma carta
struct Carta {
    int id;
    char nome[50];
    int ataque;
    int defesa;
    int energia;
    int raridade;
};

// Função para imprimir as cartas
void imprimirCartas(struct Carta lista[], int tamanho) {

    printf("%-5s | %-25s | %-7s | %-7s | %-8s | %-9s\n",
           "ID", "Nome", "Ataque", "Defesa", "Energia", "Raridade");
    printf("-------------------------------------------------------------------------\n");

    for (int i = 0; i < tamanho; i++) {

        printf("%-5d | %-25s | %-7d | %-7d | %-8d | %-9d\n",
               lista[i].id,
               lista[i].nome,
               lista[i].ataque,
               lista[i].defesa,
               lista[i].energia,
               lista[i].raridade);
    }

    printf("\n");
}

// ============================================================
// Insertion Sort
// Ordena as cartas pela energia em ordem crescente
// ============================================================
void insertionSortEnergia(struct Carta mao[], int n) {

    // Percorre o vetor a partir do segundo elemento
    for (int i = 1; i < n; i++) {

        // Guarda a carta atual
        struct Carta chave = mao[i];

        int j = i - 1;

        // Desloca as cartas com energia maior para a direita
        while (j >= 0 && mao[j].energia > chave.energia) {
            mao[j + 1] = mao[j];
            j--;
        }

        // Insere a carta na posição correta
        mao[j + 1] = chave;
    }
}

// ============================================================
// Função principal
// ============================================================
int main() {

    printf("=== ARENA DE CODIGO - MESTRE DOS DECKS ===\n\n");

    // Mão inicial desordenada
    struct Carta mao_inicial[7] = {

        {105, "Ogro Esmagador",      5, 4, 5, 2},
        {102, "Elfa Arqueira",       2, 1, 2, 1},
        {107, "Anjo da Furia",       6, 5, 6, 3},
        {101, "Goblin Batedor",      1, 1, 1, 1},
        {103, "Guardiao de Pedra",   2, 5, 4, 1},
        {106, "Cavaleiro de Aco",    3, 3, 3, 2},
        {104, "Dragao das Cinzas",   7, 7, 8, 3}

    };

    // Exibe a mão antes da ordenação
    printf("--- Mao Inicial (Desordenada) ---\n");
    imprimirCartas(mao_inicial, 7);

    // Ordena as cartas por energia
    insertionSortEnergia(mao_inicial, 7);

    // Exibe a mão após a ordenação
    printf("--- Mao Organizada por Energia (Crescente) ---\n");
    imprimirCartas(mao_inicial, 7);

    printf("Mao organizada! Pronto para a batalha!\n");

    return 0;
}