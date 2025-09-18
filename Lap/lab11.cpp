#include <stdio.h>
#include <math.h>

// ฟังก์ชันหาจำนวนหลัก
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

// ฟังก์ชันตรวจสอบ Armstrong number
int isArmstrong(int num) {
    int n = countDigits(num);   // เรียกใช้ฟังก์ชันหาจำนวนหลัก
    int temp = num, remainder;
    int sum = 0;

    while (temp != 0) {
        remainder = temp % 10;
        sum += pow(remainder, n);  // ยกกำลัง n
        temp /= 10;
    }

    if (sum == num)
        return 1;  // ใช่ Armstrong
    else
        return 0;  // ไม่ใช่
}

// ฟังก์ชันหลักในการแสดงผล
void checkArmstrong(int num) {
    if (isArmstrong(num))
        printf("Pass\n");
    else
        printf("Not Pass\n");
}

int main() {
    int number;

    printf("Enter Number: ");
    scanf("%d", &number);

    checkArmstrong(number);  // เรียกฟังก์ชันตรวจสอบ

    return 0;
}
