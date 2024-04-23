#include <stdio.h>
#include <stdbool.h>

int divisiveis_rec(int arr[], int tam, int x) {
    if (tam == 0) {
        return 0;
    } else {
        int resto = arr[tam - 1] % x;
        int soma = divisiveis_rec(arr, tam - 1, x);
        if (resto == 0) {
            soma += arr[tam - 1];
        }
        return soma;
    }
}

int divisiveis(int arr[], int tam, int x) {
    return divisiveis_rec(arr, tam, x);
}

void mostrar(int arr[], int tam) {
    printf("[ ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int array[] = {21, 27, 33, 60, 49, 5, 42, 55, 81};
    int n = sizeof(array) / sizeof(array[0]);
    mostrar(array, n);
    printf("Valor de x: ");
    int x;
    if (scanf("%d", &x) != 1) {
        return 1;
    }
    int soma_divisiveis = divisiveis(array, n, x);
    if (soma_divisiveis > 0) {
        printf("A soma dos números divisíveis por %d é %d.\n", x, soma_divisiveis);
    } else {
        printf("Nenhum número é divisível por %d.\n", x);
    }
    return 0;
}
