#include <stdio.h>
#include <string.h>

//======================================================
// Estrutura da carta
//======================================================
struct Carta{
    int id;
    char nome[50];
    int ataque;
    int defesa;
    int energia;
    int raridade;
};

//======================================================
// Imprime a coleção em formato de tabela
//======================================================
void imprimir(struct Carta vetor[], int tamanho){

    printf("--------------------------------------------------------------------------\n");
    printf("%-5s %-30s %-10s %-10s %-10s\n",
           "ID",
           "Nome",
           "Raridade",
           "Ataque",
           "Energia");
    printf("--------------------------------------------------------------------------\n");

    for(int i = 0; i < tamanho; i++){

        printf("%-5d %-30s %-10d %-10d %-10d\n",
               vetor[i].id,
               vetor[i].nome,
               vetor[i].raridade,
               vetor[i].ataque,
               vetor[i].energia);
    }

    printf("--------------------------------------------------------------------------\n");
}

//======================================================
// Troca duas cartas de posição
//======================================================
void trocar(struct Carta *a, struct Carta *b){

    struct Carta aux = *a;
    *a = *b;
    *b = aux;
}

//======================================================
// Função de comparação
//
// Critério 1:
// Raridade em ordem decrescente.
//
// Critério 2:
// Nome em ordem alfabética crescente.
//
// Retorno:
//
// Valor negativo -> carta1 vem antes.
// Zero           -> cartas equivalentes.
// Valor positivo -> carta1 vem depois.
//======================================================
int comparar(const struct Carta *carta1, const struct Carta *carta2){

    // 1. Critério principal: raridade (decrescente)
    if(carta1->raridade > carta2->raridade){
        return -1;
    }

    if(carta1->raridade < carta2->raridade){
        return 1;
    }

    // 2. Critério de desempate: nome
    return strcmp(carta1->nome, carta2->nome);
}

//======================================================
// Particionamento do Quick Sort
//
// Pivô: último elemento da partição.
//======================================================
int particionar(struct Carta vetor[], int inicio, int fim){

    struct Carta pivo = vetor[fim];

    int i = inicio - 1;

    for(int j = inicio; j < fim; j++){

        if(comparar(&vetor[j], &pivo) < 0){

            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }

    trocar(&vetor[i + 1], &vetor[fim]);

    return i + 1;
}

//======================================================
// Quick Sort
//======================================================
void quickSort(struct Carta vetor[], int inicio, int fim){

    if(inicio < fim){

        int posicaoPivo = particionar(vetor, inicio, fim);

        quickSort(vetor, inicio, posicaoPivo - 1);
        quickSort(vetor, posicaoPivo + 1, fim);
    }
}

//======================================================
// Programa Principal
//======================================================
int main(){

    struct Carta grande_registro[20] = {

        {225, "Elemental de Fogo", 6, 2, 5, 2},
        {105, "Ogro Esmagador", 5, 4, 5, 2},
        {102, "Elfa Arqueira", 2, 1, 2, 1},
        {315, "Paladino da Ordem", 5, 7, 7, 3},
        {201, "Lobo das Sombras", 3, 2, 2, 1},
        {401, "Lich King", 10, 10, 10, 4},
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
        {405, "Fenix Imortal", 9, 9, 9, 4}

    };

    int tamanho = 20;

    printf("\n--- O Grande Registro da Arena (Colecao Original) ---\n");
    imprimir(grande_registro, tamanho);

    quickSort(grande_registro, 0, tamanho - 1);

    printf("\n--- O Grande Registro da Arena (Ordem Restaurada) ---\n");
    imprimir(grande_registro, tamanho);

    printf("\nO grande registro da arena foi restaurado!\n");

    return 0;
}