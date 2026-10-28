#include <stdio.h>

char nomes[10][30];
float precos[10];
int qtds[10];
int total = 0;

float calcularFaturamento(float preco, int qtd) {
    return preco * qtd;
}

float valorTotalEstoque() {
    int i;
    float soma = 0;
    for (i = 0; i < total; i++) {
        soma = soma + precos[i] * qtds[i];
    }
    return soma;
}

void cadastrar() {
    int i, n;
    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        if (total < 10) {
            printf("Nome: ");
            scanf("%s", nomes[total]);
            printf("Preco: ");
            scanf("%f", &precos[total]);
            printf("Quantidade: ");
            scanf("%d", &qtds[total]);
            total = total + 1;
        } else {
            printf("Limite de 10 produtos atingido.\n");
        }
    }
}

void consultar() {
    int i;
    for (i = 0; i < total; i++) {
        printf("%d - %s | R$ %.2f | %d un.\n", i + 1, nomes[i], precos[i], qtds[i]);
    }
    printf("Valor total do estoque: R$ %.2f\n", valorTotalEstoque());
}

void vender() {
    int cod, qtd;
    printf("Codigo do produto: ");
    scanf("%d", &cod);
    printf("Quantidade: ");
    scanf("%d", &qtd);

    if (cod < 1 || cod > total) {
        printf("Produto inexistente.\n");
    } else if (qtds[cod - 1] >= qtd) {
        qtds[cod - 1] = qtds[cod - 1] - qtd;
        printf("Venda realizada! Total: R$ %.2f\n",
               calcularFaturamento(precos[cod - 1], qtd));
    } else {
        printf("Venda nao pode ser realizada: estoque insuficiente.\n");
    }
}

void reposicao() {
    int i;
    for (i = 0; i < total; i++) {
        if (qtds[i] < 5) {
            printf("%s - quantidade atual: %d\n", nomes[i], qtds[i]);
        }
    }
}

void entrada() {
    int cod, qtd;
    printf("Codigo do produto: ");
    scanf("%d", &cod);
    printf("Quantidade recebida: ");
    scanf("%d", &qtd);

    if (cod < 1 || cod > total) {
        printf("Produto inexistente.\n");
    } else if (qtd <= 0) {
        printf("Quantidade invalida.\n");
    } else {
        qtds[cod - 1] = qtds[cod - 1] + qtd;
    }
}