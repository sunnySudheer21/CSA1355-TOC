#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool match_S(char *input);
bool match_A(char *input);

// Function to match the production rule S -> A00A
bool match_S(char *input) {
    if (*input == '\0') {
        return false; // Empty string not allowed for S -> A00A
    }

    // Try to match A
    if (match_A(input)) {
        input++; // Move past 'A'
        if (*input == '0') {
            input++; // Move past '0'
            if (*input == '0') {
                input++; // Move past '0'
                return match_A(input); // Try to match 'A' after '00'
            }
        }
    }
    return false;
}

// Function to match the production rule A -> 0A | 1A | e
bool match_A(char *input) {
    if (*input == '\0') {
        return true; // e production
    }

    if (*input == '0' || *input == '1') {
        input++; // Move past '0' or '1'
        return match_A(input); // Recursively match A
    }

    return false;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (match_S(input)) {
        printf("The string \"%s\" belongs to the language defined by the CFG.\n", input);
    } else {
        printf("The string \"%s\" does not belong to the language defined by the CFG.\n", input);
    }

    return 0;
}
