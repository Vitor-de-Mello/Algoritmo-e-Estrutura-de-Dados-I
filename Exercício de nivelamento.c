//Vitor de Mello   Turma: M3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    float valor;
    int quantidade;
} Produto;

void menu(int *opcao) {
    printf("###### CONTROLE DE ESTOQUE ######\n");
    printf("1 - Adicionar produto\n");
    printf("2 - Listar produtos\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", opcao);
}

void cadastrarProduto(Produto *produto) {
    printf("###### Cadastro de Produto ######\n");
    printf("Nome: ");
    scanf(" %[^\n]", produto->nome);
    printf("Valor: ");
    scanf("%f", &produto->valor);
    printf("Quantidade: ");
    scanf("%d", &produto->quantidade);
}

void exibirRelatorio(Produto *produto) {
    float valorTotal = produto->valor * produto->quantidade;
    printf("Nome: %s; Valor: R$ %.2f; Quantidade: %d; Valor Total: R$ %.2f\n", 
           produto->nome, produto->valor, produto->quantidade, valorTotal);
}

int main() {
    Produto *estoque = NULL;
    int tamanho = 0;
    int opcao;

    do {
        menu(&opcao);
        
        switch (opcao) {
            case 1: {
                if (tamanho == 0) {
                    estoque = (Produto *) malloc(sizeof(Produto));
                } else {
                    estoque = (Produto *) realloc(estoque, (tamanho + 1) * sizeof(Produto));
                }
                
                if (estoque == NULL) {
                    printf("Erro ao alocar memoria!\n");
                    exit(1);
                }
                
                cadastrarProduto(&estoque[tamanho]);
                tamanho++;
                break;
            }
            case 2: {
                printf("===== RELATORIO DO ESTOQUE =====\n");
                for (int i = 0; i < tamanho; i++) {
                    exibirRelatorio(&estoque[i]);
                }
                break;
            }
            case 0:
                free(estoque);
                break;
            default:
                printf("Opcao invalida!\n");
        }
        printf("\n");
    } while (opcao != 0);

    return 0;  
}