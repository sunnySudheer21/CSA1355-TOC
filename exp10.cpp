#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STATES 10

// Define the NFA
typedef struct {
    int transitions[MAX_STATES][2][MAX_STATES]; // [current state][input 0 or 1][next states]
    int start_state;
    int accepting_states[MAX_STATES];
    int num_accepting;
} NFA;

// Initialize the NFA
void initialize_nfa(NFA *nfa) {
    memset(nfa->transitions, -1, sizeof(nfa->transitions));
    nfa->start_state = 0;
    nfa->accepting_states[0] = 2;
    nfa->num_accepting = 1;

    // Add transitions
    // Transition for state 0 on '1' (represented by 1)
    nfa->transitions[0][1][0] = 1;

    // Transitions for state 1 on '0' and '1'
    nfa->transitions[1][0][0] = 1; // '0' (represented by 0)
    nfa->transitions[1][1][0] = 1; // '1' (represented by 1)
    nfa->transitions[1][1][1] = 2; // '1' leading to accepting state 2
}

// Check if a state is an accepting state
bool is_accepting(NFA *nfa, int state) {
    for (int i = 0; i < nfa->num_accepting; i++) {
        if (nfa->accepting_states[i] == state) {
            return true;
        }
    }
    return false;
}

// Recursive function to simulate the NFA
bool simulate_nfa(NFA *nfa, const char *input, int pos, int state) {
    if (pos == strlen(input)) {
        return is_accepting(nfa, state);
    }

    int symbol = input[pos] == '0' ? 0 : 1;
    for (int i = 0; i < MAX_STATES; i++) {
        if (nfa->transitions[state][symbol][i] != -1) {
            if (simulate_nfa(nfa, input, pos + 1, nfa->transitions[state][symbol][i])) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    NFA nfa;
    initialize_nfa(&nfa);

    char input[100];
    printf("Enter a string: ");
    scanf("%s", input);

    if (simulate_nfa(&nfa, input, 0, nfa.start_state)) {
        printf("The string is accepted by the NFA.\n");
    } else {
        printf("The string is rejected by the NFA.\n");
    }

    return 0;
}
