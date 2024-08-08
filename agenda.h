#ifndef AGENDA_H
#define AGENDA_H

typedef struct dataAniversario{
    int dia;
    int mes;
} data;

typedef struct contato{
    char nome[41];
    char telefone[16];
    char celular[16];
    char email[41];
    data data;
    struct contato *prox;
} contato;

int qtdContatos(contato *inicio);
contato *criaContato();
void organizaAgenda(contato **inicio, contato *pessoa);
void insereContato(contato **inicio);
void listaContatos(contato *inicio);
contato *buscaContato(contato *inicio, char nome[], contato **ant, contato **pos);
void editarContato(contato **inicio, char nome[]);
void removerContato(contato **inicio, char nome[]);
void removeDuplicado(contato **inicio, int qtd);

#endif