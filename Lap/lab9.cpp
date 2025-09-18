#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    int values[N];

    for (int i = 0; i < N; i++) {
        printf("Enter value[%d]: ", i);
        scanf("%d", &values[i]);
    }

    printf("Output\n");
    printf("Index:");
    for (int i = 0; i < N; i++) {
        printf(" %2d", i);
    }
    printf("\n");

    printf("Array:");
    for (int i = 0; i < N; i++) {
        if (isPrime(values[i])) {
            printf(" %2d", values[i]);
        } else {
            printf("  #");
        }
    }
    printf("\n");

    return 0;
}