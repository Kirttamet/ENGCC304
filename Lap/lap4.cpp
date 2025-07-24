#include <stdio.h>
#include <math.h>

int main() {
    char emid[10];
    int hrs;
    float salary;
    float total;

    printf("Input the Employees ID(Max. 10 chars) : ");
    scanf("%s", &emid);
    
    printf("Input the working hrs : ");
    scanf("%d", &hrs);
    
    printf("Salary amount/hr : ");
    scanf("%f", &salary);
    
    total = salary * hrs ;
    
    printf("\nExpected Output:\n");
    printf("Employees ID = %s\n", emid);
    printf("Salary = U$ %.2f\n", total);
    
}
