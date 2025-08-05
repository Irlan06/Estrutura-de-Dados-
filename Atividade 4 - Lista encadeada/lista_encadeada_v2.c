#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int conteudo_no;
    struct no *proximo_elemento;
}no;


typedef struct{
    no *primeiro_no;
    int numero_nos;
}lista_encadeada;


lista_encadeada *criar_lista_vazia(){
    lista_encadeada *lista_vazia;
    lista_vazia = malloc(sizeof(lista_encadeada));

    if (lista_vazia != NULL){
        lista_vazia->primeiro_no = NULL;
        lista_vazia->numero_nos = 0;
    }

    return lista_vazia;
    
}

int verificar_lista_vazia(lista_encadeada *lista){
    if (lista->numero_nos == 0 && lista->primeiro_no == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

int contar_elementos_lista(lista_encadeada *lista){
    int quantidade = 0;
    no *auxiliar = lista->primeiro_no;
    
    while(auxiliar != NULL){
        quantidade += 1;
        auxiliar = auxiliar->proximo_elemento;
        }
    
    return quantidade;
}

int acessar_elemento_lista(int pos, lista_encadeada *lista){
    no *auxiliar;
    if(pos < 1 || pos > lista->numero_nos || lista->primeiro_no == NULL){
        return -1;
    } else {
        auxiliar = lista->primeiro_no;
        for(int i = 1; i < pos; i++){
            auxiliar = auxiliar->proximo_elemento;
        }   
    }
    return auxiliar->conteudo_no;
}

int alterar_elemento_lista(int pos, int novo_valor, lista_encadeada *lista){
    no *auxiliar;
    if(pos < 1 || pos > lista->numero_nos || lista->primeiro_no == NULL){
        return 0;
    } else {
        auxiliar = lista->primeiro_no;
        for(int i = 1; i < pos; i++){
            auxiliar = auxiliar->proximo_elemento;
        }
        auxiliar->conteudo_no =  novo_valor;
        return 1;
    }

}

int inserir_elemento_lista(int pos, int valor, lista_encadeada *lista){
    no *auxiliar;
    no *novo_no;

    if (pos < 1 || pos > contar_elementos_lista(lista) + 1){
        return 0;
    } else {
        novo_no = malloc(sizeof(no));
        novo_no->conteudo_no = valor;
        lista->numero_nos += 1;

        if(pos == 1){
            novo_no->proximo_elemento = lista->primeiro_no;
            lista->primeiro_no = novo_no;
        }else {
            auxiliar = lista->primeiro_no;
            for(int i = 1; i < pos - 1; i++){
            auxiliar = auxiliar->proximo_elemento;
        }

        novo_no->proximo_elemento = auxiliar->proximo_elemento;
        auxiliar->proximo_elemento = novo_no;
        }
        return 1;}
}

int remover_elemento_lista(int pos, lista_encadeada *lista){

    no *auxiliar;
    no *anterior;
    
    if (pos < 1 || pos > contar_elementos_lista(lista)){
        return 0;
    } 
    if (pos == 1){
        auxiliar = lista->primeiro_no;
        lista->primeiro_no = auxiliar->proximo_elemento;
        lista->numero_nos = lista->numero_nos -1;
    }
    else {
        auxiliar = lista->primeiro_no;
        for(int i = 1; i < pos; i++){
            if (i == pos-1){
                anterior = auxiliar;
            }
            auxiliar = auxiliar->proximo_elemento;
        }
        
        anterior->proximo_elemento = auxiliar->proximo_elemento;
        lista->numero_nos = lista->numero_nos -1;
        return 1;
    }
}

void exibir_elementos_lista(lista_encadeada *lista){

    no *auxiliar;

    if(lista->primeiro_no == NULL || lista->numero_nos == 0){
        printf("\nNAO HA VALORES/NOS A SEREM MOSTRADOS!\n");
    } else {
        auxiliar = lista->primeiro_no;
        for(int i = 1; i <= contar_elementos_lista(lista); i++){
            printf("%d\t", auxiliar->conteudo_no);
            auxiliar = auxiliar->proximo_elemento;
        }
        printf("\n");
    }
}

int main(){

    lista_encadeada *lista = criar_lista_vazia();

    if (verificar_lista_vazia(lista)){
        printf("A lista esta vazia!\n");
    } else {
        printf("A lista esta cheia!\n");
    }

    printf("Quantidade de elementos: %d\n", contar_elementos_lista(lista));

    // Inserindo elementos aleatórios na lista
    inserir_elemento_lista(1, 30, lista);
    inserir_elemento_lista(2, 100, lista);
    inserir_elemento_lista(3, 24, lista);
    inserir_elemento_lista(4, 36, lista);
    inserir_elemento_lista(5, 32, lista);
    inserir_elemento_lista(6, 999, lista);

    // Verificando se os elementos foram inseridos e contabilizados
    printf("Quantidade de elementos: %d\n", contar_elementos_lista(lista));


    // Removendo um elemento da lista e verificando sua remoção...
    exibir_elementos_lista(lista);
    remover_elemento_lista(3, lista);
    remover_elemento_lista(1, lista); // Removendo do início
    exibir_elementos_lista(lista);
    printf("Quantidade de elementos: %d\n", contar_elementos_lista(lista));

    //Consultando valores da lista

    printf("O valor da posicao %d eh: %d\n", 3, acessar_elemento_lista(3, lista));
    printf("O valor da posicao %d eh: %d\n", 1, acessar_elemento_lista(1, lista));
    printf("O valor da posicao %d eh: %d\n", 2, acessar_elemento_lista(2, lista));

    return 0;

}
