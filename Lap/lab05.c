#include <stdio.h>
#include <math.h>

int main() {
    float score;
    int result;

    printf("Enter your raw score: ");
    result = scanf("%f", &score);

    if (result != 1) {
        printf("Please enter number only.\n");
        return 1;
    }
    
    if (score < 50) {
        printf("Grade: F !\n");
    } else if (score >= 50 && score < 55) {
        printf("Grade: D !\n");
    } else if (score >= 55 && score < 60) {
        printf("Grade: D+ !\n");
    } else if (score >= 60 && score < 65) {
        printf("Grade: C !\n");
    } else if (score >= 65 && score < 70) {
        printf("Grade: C+ !\n");
    } else if (score >= 70 && score < 75) {
        printf("Grade: B !\n");
    } else if (score >= 75 && score < 80) {
        printf("Grade: B+ !\n");
    } else if (score >= 80) {
        printf("Grade: A !\n");
    }

    return 0;
}

