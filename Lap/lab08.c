#include <stdio.h>

int main() {
    int position;
    int years_of_experience;
    int projects_completed;
    double base_salary;
    double bonus_from_experience;
    double special_bonus;
    double net_salary;

    // Get input from the user
    printf("Enter position (1=Junior, 2=Mid-Level, 3=Senior): ");
    scanf("%d", &position);

    printf("Enter years of experience: ");
    scanf("%d", &years_of_experience);

    printf("Enter number of projects completed this year: ");
    scanf("%d", &projects_completed);

    // --- Using if-else if-else to determine base salary ---
    if (position == 1) {
        base_salary = 20000.0;
    } else if (position == 2) {
        base_salary = 35000.0;
    } else if (position == 3) {
        base_salary = 50000.0;
    } else {
        printf("Invalid position entered.\n");
        return 1;
    }

    // The rest of the code remains the same
    if (years_of_experience < 1) {
        bonus_from_experience = 0.0;
    } else if (years_of_experience >= 1 && years_of_experience <= 3) {
        bonus_from_experience = base_salary * 0.10;
    } else if (years_of_experience >= 4 && years_of_experience <= 5) {
        bonus_from_experience = base_salary * 0.15;
    } else {
        bonus_from_experience = base_salary * 0.20;
    }

    if (projects_completed > 5) {
        special_bonus = base_salary * 0.05;
    } else {
        special_bonus = 0.0;
    }

    net_salary = base_salary + bonus_from_experience + special_bonus;

    printf("\n--- Calculation Results ---\n");
    printf("Base Salary: %.2f Baht\n", base_salary);
    printf("Bonus from Experience: %.2f Baht\n", bonus_from_experience);
    printf("Special Bonus: %.2f Baht\n", special_bonus);
    printf("---------------------------\n");
    printf("Net Salary: %.2f Baht\n", net_salary);

    return 0;
}
