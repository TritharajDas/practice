#include <stdio.h>
#include <string.h>

int checkPallindrom(char str[]) {
    int len = strlen(str);
    char rstr[len + 1];

    
    for (int i = 0; i < len; i++) {
        rstr[i] = str[len - 1 - i]; 
    }
    rstr[len] = '\0';

    printf("Reversed string: %s\n", rstr);

    if (strcmp(str, rstr) == 0) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    checkPallindrom(str);

    return 0;
}
