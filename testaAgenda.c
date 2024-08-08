#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main(){
    contato *inicio = NULL, *achou, *ant, *pos;
    int n, continua = 1, qtd;
    char nome[41];
    
    while(continua){
        printf("1. Inserir contato\n");
        printf("2. Listar contatos\n");
        printf("3. Buscar contato\n");
        printf("4. Editar contato\n");
        printf("5. Remover contato\n");
        printf("6. Remover contatos duplicados\n");
        printf("7. Sair\n");
        scanf("%d", &n);

        switch(n){
            case 1:
                insereContato(&inicio);
                break;
            case 2:
                listaContatos(inicio);
                break;
            case 3:
                scanf(" %[^\n]", nome);
                achou = buscaContato(inicio, nome, &ant, &pos);
                break;
            case 4: 
                scanf(" %[^\n]", nome);
                editarContato(&inicio, nome);
                break;
            case 5:
                scanf(" %[^\n]", nome);
                removerContato(&inicio, nome);
                break;
            case 6:
                qtd = qtdContatos(inicio);
                removeDuplicado(&inicio, qtd);
                break;
            case 7:
                continua = 0;
                break;
        }
    }
    return 0;
}