#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool match_S(char *input);
bool match_A(char *input);

// Function to match the production rule S -> AaAaA
bool match_S(char *input) {
    int len = strlen(input);

    if (len < 5) {
        return false; // Minimum length required for S -> AaAaA is 5
    }

    // Check AaAaA structure
    if (match_A(input) && *input == 'a') {
        input++; // Move past 'a'
        if (match_A(input) && *input == 'a') {
            input++; // Move past 'a'
            if (match_A(input) && *input == 'a') {
                input++; // Move past 'a'
                if (match_A(input)) {
                    return true;
                }
            }
        }
    }

    return false;
}

// Function to match the production rule A -> aA | bA | e
bool match_A(char *input) {
    if (*input == '\0') {
        return true; // e production
    }

    if (*input == 'a' || *input == 'b') {
        input++; // Move past 'a' or 'b'
        return match_A(input); // Recursively match A
    }

    return false;
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (match_S(input) && *input == '\0') {
        printf("The string \"%s\" belongs to the language defined by the CFG.\n", input);
    } else {
        printf("The string \"%s\" does not belong to the language defined by the CFG.\n", input);
    }

    return 0;
}
