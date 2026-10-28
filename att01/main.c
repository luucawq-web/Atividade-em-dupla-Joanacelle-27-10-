#include <stdio.h>
#include "estoque.h"

int main() {
    int opcao = 0;

    while (opcao != 6) {
        printf("\n1. Cadastrar produtos\n");
        printf("2. Consultar estoque\n");
        printf("3. Registrar venda\n");
        printf("4. Produtos que precisam de reposicao\n");
        printf("5. Registrar entrada de mercadorias\n");
        printf("6. Encerrar\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            cadastrar();
        } else if (opcao == 2) {
            consultar();
        } else if (opcao == 3) {
            vender();
        } else if (opcao == 4) {
            reposicao();
        } else if (opcao == 5) {
            entrada();
        } else if (opcao == 6) {
            printf("Valor total do estoque: R$ %.2f\n", valorTotalEstoque());
        } else {
            printf("Opcao invalida.\n");
        }
    }

    return 0;
}
