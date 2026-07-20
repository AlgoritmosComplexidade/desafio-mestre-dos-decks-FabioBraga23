#include <stdio.h>
#include <string.h>


// ============================================================
// ARENA DE CODIGO - MESTRE DOS DECKS
// NIVEL AVENTUREIRO
// Ordenacao utilizando Shell Sort
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

// ------------------------------------------------------------
// Funcao para imprimir o deck
// ------------------------------------------------------------
void imprimirCartas(struct Carta lista[], int tamanho) {

    printf("------------------------------------------------------------------------------------------\n");
    printf("%-5s %-30s %-8s %-8s %-8s %-10s\n",
           "ID", "Nome", "Ataque", "Defesa", "Energia", "Raridade");
    printf("------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < tamanho; i++) {

        printf("%-5d %-30s %-8d %-8d %-8d %-10d\n",
               lista[i].id,
               lista[i].nome,
               lista[i].ataque,
               lista[i].defesa,
               lista[i].energia,
               lista[i].raridade);
    }

    printf("\n");
}

// ------------------------------------------------------------
// Shell Sort
// Ordena as cartas pelo ataque (ordem decrescente)
// Utiliza a sequencia de Knuth para calcular os gaps.
// ------------------------------------------------------------
void shellSortAtaque(struct Carta deck[], int n) {

    int h = 1;

    // Calcula o maior gap utilizando a sequencia de Knuth
    while (h < n / 3) {
        h = 3 * h + 1;
    }

    // Diminui o gap ate chegar a 1
    while (h >= 1) {

        // Executa um Insertion Sort considerando o gap atual
        for (int i = h; i < n; i++) {

            struct Carta chave = deck[i];
            int j = i;

            while (j >= h && deck[j - h].ataque < chave.ataque) {

                deck[j] = deck[j - h];
                j -= h;
            }

            deck[j] = chave;
        }

        h /= 3;
    }
}

int main() {

    printf("=============== ARENA DE CODIGO ===============\n\n");

    struct Carta deck_de_torneio[40] = {

        {105, "Ogro Esmagador", 5, 4, 5, 2},
        {102, "Elfa Arqueira", 2, 1, 2, 1},
        {201, "Lobo das Sombras", 3, 2, 2, 1},
        {107, "Anjo da Furia", 6, 5, 6, 3},
        {301, "Mago de Gelo", 2, 4, 3, 2},
        {101, "Goblin Batedor", 1, 1, 1, 1},
        {205, "Ciclope Brutal", 7, 5, 6, 2},
        {103, "Guardiao de Pedra", 2, 5, 4, 1},
        {305, "Hidra de Nove Cabecas", 8, 8, 9, 4},
        {106, "Cavaleiro de Aco", 3, 3, 3, 2},
        {210, "Grifo Veloz", 4, 3, 4, 1},
        {104, "Dragao das Cinzas", 7, 7, 8, 3},
        {215, "Minotauro Guerreiro", 5, 6, 5, 2},
        {310, "Feiticeira Arcana", 4, 2, 5, 3},
        {220, "Basilisco Petrificante", 3, 5, 4, 2},
        {110, "Clerigo Iluminado", 1, 3, 2, 1},
        {225, "Elemental de Fogo", 6, 2, 5, 2},
        {315, "Paladino da Ordem", 5, 7, 7, 3},
        {115, "Besta Feral", 4, 1, 3, 1},
        {230, "Gargula de Granito", 3, 6, 4, 2},
                // Repeticao das 20 cartas para totalizar 40
        {105, "Ogro Esmagador", 5, 4, 5, 2},
        {102, "Elfa Arqueira", 2, 1, 2, 1},
        {201, "Lobo das Sombras", 3, 2, 2, 1},
        {107, "Anjo da Furia", 6, 5, 6, 3},
        {301, "Mago de Gelo", 2, 4, 3, 2},
        {101, "Goblin Batedor", 1, 1, 1, 1},
        {205, "Ciclope Brutal", 7, 5, 6, 2},
        {103, "Guardiao de Pedra", 2, 5, 4, 1},
        {305, "Hidra de Nove Cabecas", 8, 8, 9, 4},
        {106, "Cavaleiro de Aco", 3, 3, 3, 2},
        {210, "Grifo Veloz", 4, 3, 4, 1},
        {104, "Dragao das Cinzas", 7, 7, 8, 3},
        {215, "Minotauro Guerreiro", 5, 6, 5, 2},
        {310, "Feiticeira Arcana", 4, 2, 5, 3},
        {220, "Basilisco Petrificante", 3, 5, 4, 2},
        {110, "Clerigo Iluminado", 1, 3, 2, 1},
        {225, "Elemental de Fogo", 6, 2, 5, 2},
        {315, "Paladino da Ordem", 5, 7, 7, 3},
        {115, "Besta Feral", 4, 1, 3, 1},
        {230, "Gargula de Granito", 3, 6, 4, 2}

    };

    int tamanho = sizeof(deck_de_torneio) / sizeof(deck_de_torneio[0]);

    printf("--- Deck do Torneio (Desordenado) ---\n\n");
    imprimirCartas(deck_de_torneio, tamanho);

    // Ordena o deck por ataque em ordem decrescente
    shellSortAtaque(deck_de_torneio, tamanho);

    printf("--- Deck Otimizado (Ataque Decrescente) ---\n\n");
    imprimirCartas(deck_de_torneio, tamanho);

    printf("Deck otimizado e pronto para o torneio!\n");

    return 0;
}