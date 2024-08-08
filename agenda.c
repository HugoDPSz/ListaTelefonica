#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agenda.h"

int qtdContatos(contato *inicio){
    int count = 0;
    while(inicio != NULL){
        inicio = inicio->prox;
        count++;
    }
    return count;
}

contato *criaContato(){
    contato *p = (contato *)calloc(1,sizeof(contato));
    p->prox = NULL;
    return p;
}

void organizaAgenda(contato **inicio, contato *pessoa){
    contato *pos = *inicio;
    contato *ant = NULL;

    while (pos != NULL && strcmp(pos->nome, pessoa->nome) < 0) {
        ant = pos;
        pos = pos->prox;
    }

    if (ant == NULL) {
        pessoa->prox = *inicio;
        *inicio = pessoa;
    } else {
        ant->prox = pessoa;
        pessoa->prox = pos;
    }
}

void insereContato(contato **inicio){
    contato *pessoa = criaContato();
    if (pessoa == NULL) {
        printf("Erro ao alocar memória para o contato.\n");
        return;
    }

    printf("Insira o nome: \n");
    scanf(" %[^\n]", pessoa->nome);
    printf("Insira o telefone: \n");
    scanf(" %s", pessoa->telefone);
    printf("Insira o celular: \n");
    scanf(" %s", pessoa->celular);
    printf("Insira o email: \n");
    scanf(" %s", pessoa->email);
    printf("Insira a data de aniversário digitando o dia e o mês separado - XX XX: \n");
    scanf(" %d %d", &pessoa->data.dia, &pessoa->data.mes);

    organizaAgenda(inicio, pessoa);
}

void listaContatos(contato *inicio){
    while(inicio != NULL){
        printf("Nome: %s\nTelefone: %s\nCelular: %s\nEmail: %s\nAniversario: %d/%d\n", inicio->nome, inicio->telefone, inicio->celular, inicio->email, inicio->data.dia, inicio->data.mes);
        printf("\n");
        inicio = inicio->prox;
    }
    printf("\n");
}

contato *buscaContato(contato *inicio, char nome[], contato **ant, contato **pos){
    *ant = NULL; 
    *pos = inicio;
    while ((*pos) != NULL){
        if (strcmp((*pos)->nome, nome) == 0){
            printf("Nome: %s\nTelefone: %s\nCelular: %s\nEmail: %s\nAniversario: %d/%d\n", (*pos)->nome, (*pos)->telefone, (*pos)->celular, (*pos)->email, (*pos)->data.dia, (*pos)->data.mes);
            return *pos;
        }
        *ant = (*pos);
        *pos = (*pos)->prox;    
    }
    return NULL;
}

void editarContato(contato **inicio, char nome[]){
    contato *ant = NULL;
    contato *pos = *inicio;
    contato *pessoa = buscaContato(*inicio, nome, &ant, &pos);
    if(pessoa != NULL){
        printf("\nInsira o telefone: \n");
        scanf(" %s", pessoa->telefone);
        printf("Insira o celular: \n");
        scanf(" %s", pessoa->celular);
        printf("Insira o email: \n");
        scanf(" %s", pessoa->email);
        printf("Insira a data de aniversário digitando o dia e o mês separado - XX XX: \n");
        scanf(" %d %d", &pessoa->data.dia, &pessoa->data.mes);
    }else{
        printf("Contato nao encontrado");
    }
}

void removerContato(contato **inicio, char nome[]){
    contato *ant = NULL;
    contato *pos = *inicio;
    contato *pessoa = buscaContato(*inicio, nome, &ant, &pos);
    if(pessoa != NULL){
        if (ant == NULL) {
            *inicio = pos->prox; 
        } else {
            ant->prox = pos->prox;
        }
        free(pos);
    }else{
        printf("Contato nao existe\n");
    }
}

void removeDuplicado(contato **inicio, int qtd){
    for(int i=0; i<qtd; i++){
        contato *ant = NULL;
        contato *pos = *inicio;
        contato *pessoa = buscaContato(*inicio, pos->nome, &ant, &pos);
        if(pessoa != NULL){
            if (ant == NULL) {
            *inicio = pos->prox; 
            } else {
            ant->prox = pos->prox;
            }
            free(pos);
        }
    }
}