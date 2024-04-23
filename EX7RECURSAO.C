#include <stdio.h>
#include <stdbool.h>

int divisiveis_rec(int arr[], int tam, int x, int quantidade) {
    if (tam == 0) {
        return quantidade;
    } else {
        int resto = arr[tam - 1] % x;
        if (resto == 0) {
            quantidade++;
        }
        return divisiveis_rec(arr, tam - 1, x, quantidade);
    }
}

int divisiveis(int arr[], int tam, int x) {
    return divisiveis_rec(arr, tam, x, 0);
}

void mostrar(int arr[], int tam) {
    printf("[ ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int array[] = {21, 27, 33, 60};
    int n = sizeof(array) / sizeof(array[0]);
    mostrar(array, n);
    printf("Valor de x: ");
    int x;
    if (scanf("%d", &x) != 1) {
        return 1;
    }
    int divisiveis_count = divisiveis(array, n, x);
    if (divisiveis_count == n) {
        printf("Todos são divisíveis por %d.\n", x);
    } else if (divisiveis_count > 0) {
        printf("Existe(m) %d número(s) divisíveis por %d.\n", divisiveis_count, x);
    } else {
        printf("Nenhum número é divisível por %d.\n", x);
    }
    return 0;
}
