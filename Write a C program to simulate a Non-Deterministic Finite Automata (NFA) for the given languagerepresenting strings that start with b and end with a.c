#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_LEN 100

bool isAccepted(char *str) {
    int len = strlen(str);
    if (str[0] != 'b') return false;
    if (str[len - 1] != 'a') return false;
    return true;
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isAccepted(str)) {
        printf("Accepted\n");
    } else {
        printf("Not Accepted\n");
    }
    return 0;
}
