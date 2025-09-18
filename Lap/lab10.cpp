#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int i, len, isPalindrome = 1;

    printf("Enter word: ");
    scanf("%s", word);   // รับค่าเป็น string  

    len = strlen(word);  // หาความยาวสตริง

    // ตรวจสอบ palindrome
    for (i = 0; i < len / 2; i++) {
        if (word[i] != word[len - i - 1]) {
            isPalindrome = 0;   // ถ้าเจอไม่ตรงให้เปลี่ยน flag
            break;
        }
    }

    if (isPalindrome == 1)
        printf("Pass\n");
    else
        printf("Not Pass\n");

    return 0;
}