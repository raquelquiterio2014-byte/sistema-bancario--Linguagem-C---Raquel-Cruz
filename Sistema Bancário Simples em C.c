#include <stdio.h>

// Função para mostrar o menu
void mostrarMenu() {
    printf("\n===== BANCO EM C =====\n");
    printf("1 - Depositar\n");
    printf("2 - Sacar\n");
    printf("3 - Ver Saldo\n");
    printf("4 - Sair\n");
    printf("Escolha uma opção: ");
}

// Função depósito
float deposito(float saldo) {
    float valor;

    printf("Digite o valor para depósito: R$ ");
    
    if (scanf("%f", &valor) != 1) {
        printf("Entrada inválida!\n");
        while(getchar() != '\n'); // limpa buffer
        return saldo;
    }

    if (valor <= 0) {
        printf("Valor inválido! Digite valor positivo.\n");
        return saldo;
    }

    saldo += valor;
    printf("Depósito realizado com sucesso!\n");
    return saldo;
}

// Função saque
float saque(float saldo) {
    float valor;

    printf("Digite o valor para saque: R$ ");

    if (scanf("%f", &valor) != 1) {
        printf("Entrada inválida!\n");
        while(getchar() != '\n'); // limpa buffer
        return saldo;
    }

    if (valor <= 0) {
        printf("Valor inválido! Digite valor positivo.\n");
        return saldo;
    }

    if (valor > saldo) {
        printf("Saldo insuficiente!\n");
        return saldo;
    }

    saldo -= valor;
    printf("Saque realizado com sucesso!\n");
    return saldo;
}

// Função ver saldo
void verSaldo(float saldo) {
    printf("Seu saldo atual é: R$ %.2f\n", saldo);
}

// Função principal
int main() {
    int opcao;
    float saldo = 0.0;

    do {
        mostrarMenu();

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida!\n");
            while(getchar() != '\n'); // limpa buffer
            continue;
        }

        switch(opcao) {
            case 1:
                saldo = deposito(saldo);
                break;

            case 2:
                saldo = saque(saldo);
                break;

            case 3:
                verSaldo(saldo);
                break;

            case 4:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 4);

    return 0;
}