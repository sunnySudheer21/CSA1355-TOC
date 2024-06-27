#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the DFA
typedef struct {
    int transitions[2][2]; // [current state][input 'a' or 'b']
    int start_state;
    int accepting_state;
} DFA;

// Initialize the DFA for the language starting and ending with 'b'
void initialize_dfa(DFA *dfa) {
    // Define the DFA transitions
    dfa->transitions[0][0] = -1; // State 0 on input 'a'
    dfa->transitions[0][1] = 1;  // State 0 on input 'b'
    dfa->transitions[1][0] = -1; // State 1 on input 'a'
    dfa->transitions[1][1] = 1;  // State 1 on input 'b'

    dfa->start_state = 0; // Initial state
    dfa->accepting_state = 1; // Accepting state
}

// Function to simulate the DFA and check if the input string is accepted
bool simulate_dfa(DFA *dfa, const char *input) {
    int current_state = dfa->start_state;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        char symbol = input[i];
        int input_index = (symbol == 'a') ? 0 : 1; // 'a' -> 0, 'b' -> 1

        // Check if there's a transition defined for the current state and input symbol
        if (dfa->transitions[current_state][input_index] == -1) {
            return false; // No transition defined
        } else {
            current_state = dfa->transitions[current_state][input_index];
        }
    }

    // After processing all input symbols, check if we're in the accepting state
    return (current_state == dfa->accepting_state);
}

int main() {
    DFA dfa;
    initialize_dfa(&dfa);

    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulate_dfa(&dfa, input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is rejected by the DFA.\n");
    }

    return 0;
}
