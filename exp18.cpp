#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define the NFA
typedef struct {
    int transitions[4][2][2]; // [current state][input '0' or '1'][next states]
    int start_state;
    int accepting_state;
} NFA;

// Initialize the NFA for the language starting with "00" and ending with "11"
void initialize_nfa(NFA *nfa) {
    // Define the NFA transitions
    // State 0 transitions
    nfa->transitions[0][0][1] = 1; // State 0 on '0' moves to State 1
    // State 1 transitions
    nfa->transitions[1][0][2] = 1; // State 1 on '0' moves to State 2
    nfa->transitions[1][1][1] = 1; // State 1 on '1' moves to State 1
    // State 2 transitions
    nfa->transitions[2][1][3] = 1; // State 2 on '1' moves to State 3
    // State 3 transitions
    nfa->transitions[3][0][1] = 1; // State 3 on '0' moves to State 1
    nfa->transitions[3][1][3] = 1; // State 3 on '1' moves to State 3

    nfa->start_state = 0; // Initial state
    nfa->accepting_state = 3; // Accepting state
}

// Function to simulate the NFA and check if the input string is accepted
bool simulate_nfa(NFA *nfa, const char *input) {
    int current_states[4] = {0}; // Array to hold current states, start with initial state
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        int next_states[4] = {0}; // Array to calculate next states

        char symbol = input[i];
        int input_index = (symbol == '0') ? 0 : 1; // '0' -> 0, '1' -> 1

        // Compute next states based on current states and input symbol
        for (int j = 0; j < 4; j++) {
            if (current_states[j] == 1) {
                for (int k = 0; k < 2; k++) {
                    if (nfa->transitions[j][input_index][k] == 1) {
                        next_states[k] = 1; // Move to next state if transition exists
                    }
                }
            }
        }

        // Update current states with next states
        for (int j = 0; j < 4; j++) {
            current_states[j] = next_states[j];
        }
    }

    // After processing all input symbols, check if we're in the accepting state
    return (current_states[nfa->accepting_state] == 1);
}

int main() {
    NFA nfa;
    initialize_nfa(&nfa);

    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulate_nfa(&nfa, input)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is rejected by the NFA.\n");
    }

    return 0;
}
