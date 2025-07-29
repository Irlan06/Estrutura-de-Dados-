#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

// 1. Criação da lista vazia. Atendendo ao requisito 1 da atividade: Função de criação de uma nova lista vazia
No* nova_lista() {
    return NULL;
}

// 2. Verificar se a lista está vazia. Atendendo ao requisito 2 da atividade. Função que verifica se a lista está vazia
char esta_vazia(No* lista) {
    return lista == NULL; 
}

/* 3. Obter o tamanho da lista. Atendendo ao requisito 3 da atividade: Função de Contagem da quantidade de elementos 
presentes na lista. */
int contar_elementos(No* lista) {
    int qtd = 0;
    while (lista != NULL) {
        qtd++;
        lista = lista->prox;
    }
    return qtd;
}

/* 4. Obter/modificar o valor do elemento de uma determinada posição na lista. Parâmetro pos (posição do elemento a ser
removido) */
int acessar_elemento(No* lista, int pos) {
    int i = 1;
    while (lista != NULL) {
        if (i == pos) return lista->valor;
        lista = lista->prox;
        i++;
    }
    return -1;
}

/*4. Obter/modificar o valor do elemento de uma determinada posição na lista. Atendendo ao requisito 4 da atividade: Função
que altera o valor de determinado elemento de acordo com a posição indicado - Parâmetros pos (posição do elemento) e novo_valor
(novo valor que o elemento passará a ter)
*/
char alterar_elemento(No* lista, int pos, int novo_valor) {
    int i = 1;
    while (lista != NULL) {
        if (i == pos) {
            lista->valor = novo_valor;
            return 0;
        }
        lista = lista->prox;
        i++;
    }
    return 1;
}
/*
/*5. Inserir um elemento em uma determinada posição. Atendendo ao requisito 5 da atividade: Função que insere um elemento
em determinado posição indicada pelo usuário Parâmetros pos (posição do elemento) e novo_valor (novo valor que o elemento
 passará a ter)
*/
char inserir_em(No** lista, int pos, int novo_valor) {
    if (pos < 1 || pos > contar_elementos(*lista) + 1) return 1;

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 1;

    novo->valor = novo_valor;

    if (pos == 1) {
        novo->prox = *lista;
        *lista = novo;
    } else {
        No* atual = *lista;
        for (int i = 1; i < pos - 1; i++) atual = atual->prox;
        novo->prox = atual->prox;
        atual->prox = novo;
    }

    return 0;
}

/*6. Retirar um elemento de uma determinada posição. Atendendo ao requisito 6 da atividade: Função que remove um elemento
da lista de acordo com a posição indicada pelo usuário. Possui como parâmetro apenas 'pos', que é a posição do elemento
que o usuário deseja remover */
char remover_em(No** lista, int pos) {
    if (pos < 1 || pos > contar_elementos(*lista)) return 1;

    No* atual = *lista;
    No* anterior = NULL;

    if (pos == 1) {
        *lista = atual->prox;
        free(atual);
    } else {
        for (int i = 1; i < pos; i++) {
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = atual->prox;
        free(atual);
    }

    return 0;
}

/* 7. Imprimir os elementos de toda a lista. Atendendo ao requisito 7 da atividade: Função que irá imprimar todos os
elementos da lista encadeada.*/
void exibir(No* lista) {
    if (esta_vazia(lista)) {
        printf("Lista está vazia\n");
        return;
    }

    while (lista != NULL) {
        printf("%d -> ", lista->valor);
        lista = lista->prox;
    }

    printf("NULL\n");
}

int main() {
    No* lista = nova_lista();

    printf("Inserindo valores diversos:\n");
    inserir_em(&lista, 1, 42);
    inserir_em(&lista, 2, 8);
    inserir_em(&lista, 2, 99);  // insere no meio
    inserir_em(&lista, 4, 100);
    inserir_em(&lista, 3, 73);
    exibir(lista);

    printf("\nAlterando valores:\n");
    alterar_elemento(lista, 3, 777); // posição 3 vira 777
    alterar_elemento(lista, 5, 888); // última posição vira 888
    exibir(lista);

    printf("\nConsultando valores da lista:\n");
    printf("Elemento na posição 1: %d\n", acessar_elemento(lista, 1));
    printf("Elemento na posição 4: %d\n", acessar_elemento(lista, 4));
    printf("Elemento inválido (posição 10): %d\n", acessar_elemento(lista, 10));

    printf("\nRemoções específicas:\n");
    remover_em(&lista, 2); // remove da posição 2
    exibir(lista);
    remover_em(&lista, contar_elementos(lista)); // remove último
    exibir(lista);
    remover_em(&lista, 1); // remove início
    exibir(lista);

    printf("\nTotal de elementos restantes: %d\n", contar_elementos(lista));

    return 0;
}
