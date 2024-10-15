/*5. Palindrome Check:
Question: Write a recursive function to check if a given string is a palindrome. A
string is a palindrome if it reads the same forward and backward.*/

#include <stdio.h>
#include <string.h>
int is_palindrome(char str[], int start, int end) {
    if (start >= end)
        return 1; // Base case
    if (str[start] != str[end])
        return 0; // Not a palindrome
    return is_palindrome(str, start + 1, end - 1); // Recursive case
}

int main() {
    char str1[] = "madam";
    if (is_palindrome(str1, 0, strlen(str1) - 1))
        printf("The string \"%s\" is a palindrome\n", str1);
    else
        printf("The string \"%s\" is not a palindrome\n", str1);

    char str2[] = "hello";
    if (is_palindrome(str2, 0, strlen(str2) - 1))
        printf("The string \"%s\" is a palindrome\n", str2);
    else
        printf("The string \"%s\" is not a palindrome\n", str2);

    return 0;
}
