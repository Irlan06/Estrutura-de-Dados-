#include <stdlib.h>
#include <stdio.h>

#define MAXIMO 3 

typedef struct{
    int conteudo[MAXIMO];
    int inicio;
    int fim;
    int quantidade_elementos;
}fila_sequencial;

// Inicializando a fila com valores padrões/"zerados"
void criar_fila_vazia(fila_sequencial *fila){
    fila->inicio = 0;
    fila->fim = -1;
    fila->quantidade_elementos = 0;
}

int inserir_fim_fila(fila_sequencial *fila, int novo_valor){
    if(fila->quantidade_elementos == MAXIMO){
        return 0; // Retorno 0 p/ ser identificado como TRUE na implementação do MAIN, indicicando que deu certo!
    }
    fila->fim = (fila->fim + 1) % MAXIMO;
    fila->conteudo[fila->fim] = novo_valor;
    fila->quantidade_elementos = fila->quantidade_elementos + 1;
    return 1; // Retorno 1 p/ ser identificado como TRUE na implementação do MAIN, indicicando que deu certo!
}

int remover_inicio_fila(fila_sequencial *fila){
    if(fila->quantidade_elementos == 0){
        return 0; 
    }
    fila->inicio = (fila->inicio + 1) % MAXIMO;
    fila->quantidade_elementos = fila->quantidade_elementos - 1;
    return 1; 
}

int consultar_inicio_fila(fila_sequencial *fila, int *valor){
    if(fila->quantidade_elementos == 0){
        return 0; 
    }
    *valor = fila->conteudo[fila->inicio];
    return 1; 
}

int verificar_fila_vazia(fila_sequencial *fila){
    if(fila->quantidade_elementos == 0){
        return 1;
    }
    return 0;
}

int verificar_fila_cheia(fila_sequencial *fila){
    if(fila->quantidade_elementos == MAXIMO){
        return 1;
    }
    return 0;
}

// Função auxiliar apenas para complementar a implementação e printar os elementos
void exibir_fila(fila_sequencial *fila){
    if(verificar_fila_vazia(fila)){
        printf("\nA Fila esta vazia\n");
        return;
    }
    printf("\nFILA: ");
    int i, indice;
    indice = fila->inicio;
    for(i = 0; i < fila->quantidade_elementos; i++){
        printf("%d ", fila->conteudo[indice]);
        indice = (indice + 1) % MAXIMO;
    }
    printf("\n");
}

int main(){
    fila_sequencial fila;
    criar_fila_vazia(&fila); // Criando fila vazia

    int valor;

    // Inserindo elementos 
    inserir_fim_fila(&fila, 10);
    inserir_fim_fila(&fila, 20);
    inserir_fim_fila(&fila, 30); // Tamanho máximo atingido
   
    exibir_fila(&fila);

     if(inserir_fim_fila(&fila, 50) == 0){ // Tentativa de inserção com a lista cheia (Retorno = 0)
        printf("A lista esta cheia!");
    }

    if(verificar_fila_cheia(&fila)){
    printf("\nFila cheia!\n");
}
    
    if(consultar_inicio_fila(&fila, &valor)){
        printf("\nInicio da fila: %d\n", valor);
    }

    
    if(remover_inicio_fila(&fila)){
        printf("\nElemento removido!\n");
    }
    remover_inicio_fila(&fila);
    remover_inicio_fila(&fila); // Removendo todos
    
    exibir_fila(&fila);

    if(verificar_fila_vazia(&fila)){
    printf("\nFila vazia!\n");
}


    return 0;
}
