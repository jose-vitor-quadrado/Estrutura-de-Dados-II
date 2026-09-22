#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

void menu();
void printProduct(product p);
void printAllProducts(product *products, int quantity);
void registerProducts(product *products, int quantity);
void findHighestPrice(product *products, int quantity);
void findProductsByQuantity(product *products, int quantity);

int main() {
    int quantity, op = 0;
    printf("Quantos tipos de produtos serao cadastrados? ");
    scanf(" %d", &quantity);

    product *products = (product*) malloc(quantity * sizeof(product));

    do {
        menu();
        scanf(" %d", &op);

        switch (op) {
            case 1:
                registerProducts(products, quantity);
            break;
            case 2:
                printAllProducts(products, quantity);
            break;
            case 3:
                findHighestPrice(products, quantity);
            break;
            case 4:
                findProductsByQuantity(products, quantity);
            break;
            case 5:
                printf("Saindo...\n");
            break;
            default:
                printf("Valor invalido!\n");
                op = 0;
            break;
        }
    } while (op != 4);

    free(products);
    return 0;
}

void menu() {
    printf("\n Menu:\n");
    printf(" 1: Castrar produtos\n");
    printf(" 2: Encontrar produto com o maior preco de venda:\n");
    printf(" 3: Encontrar produtos com estoque menor que a quanitidade escolhida:\n");
    printf(" 4: Sair\n");
    printf("--> ");
}

void printProduct(product p) {
    printf("\nDetalhes sobre o produto.\n");
    printf("Codigo: %d\n", p.id);
    printf("Nome: %s\n", p.name);
    printf("Quantidade: %d\n", p.quantity);
    printf("Preco: %.2f\n\n", p.price);
}

void printAllProducts(product *products, int quantity) {
    for (int i = 0; i < quantity; i++) {
        printProduct(products[i]);
    }
}

void registerProducts(product *products, int quantity) {
    for (int i = 0; i < quantity; i++) {
        printf("Digite o codigo do produto: ");
        scanf(" %d", &products[i].id);
        printf("Digite o nome do produto: ");
        scanf(" %50[^\n]", &products[i].name);
        printf("Digite a quantidade em estoque do produto: ");
        scanf(" %d", &products[i].quantity);
        printf("Digte o preco do produto: ");
        scanf(" %f", &products[i].price);
    }
}

void findHighestPrice(product *products, int quantity) {
    float highestPrice = products[0].price;
    for (int i = 0; i < quantity; i++) {
        if (highestPrice < products[i].price) {
            highestPrice = products[i].price;
        }
    }

    printf("Os produtos com o maior preco:\n");
    for (int i = 0; i < quantity; i++) {
        if (products[i].price == highestPrice) {
            printProduct(products[i]);
        }
    }
}

void findProductsByQuantity(product *products, int quantity) {
    int qt;
    printf("Qual a quantidade limite de produtos em estoque que deseja pesquisar? ");
    scanf(" %d", &qt);

    printf("Lista de produtos com estoque menor que %d:\n", qt);
    for (int i = 0; i < quantity; i++) {
        if (products[i].quantity <= qt) {
            printProduct(products[i]);
        } 
    }
}
