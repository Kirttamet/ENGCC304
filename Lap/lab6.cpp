#include <stdio.h>

int main() {
    int N;

    printf("Enter value: ");
    
    if (scanf("%d", &N) != 1) {
        printf("NO!!!! Only number\n");
        return 1;
    }

    if (N % 2 != 0) {
        printf("Series: ");
        for (int i = 1; i <= N; i += 2) {
            printf("%d ", i);
        }
        printf("\n");
    } else {
        printf("Series: ");
        for (int i = N; i >= 0; i -= 2) {
            printf("%d ", i);
        }
        printf("\n");
    }
    
}

