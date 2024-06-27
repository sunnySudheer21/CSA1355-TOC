#include <stdio.h>
#include <stdbool.h>

#define MAX_STATES 10

// Define the NFA
typedef struct {
    int transitions[MAX_STATES][3][MAX_STATES]; // [current state][0 (e), 1 (a), 2 (b)][next states]
    int num_states;
} NFA;

// Function to compute e-closure for a state
void compute_epsilon_closure(NFA *nfa, int state, bool visited[], bool epsilon_closure[]) {
    visited[state] = true;
    epsilon_closure[state] = true;

    // Traverse all states reachable from 'state' with e-transitions
    for (int i = 0; i < nfa->num_states; i++) {
        if (nfa->transitions[state][0][i] == 1 && !visited[i]) {
            compute_epsilon_closure(nfa, i, visited, epsilon_closure);
        }
    }
}

// Function to print e-closure for all states
void print_epsilon_closures(NFA *nfa) {
    bool visited[MAX_STATES] = {false};
    bool epsilon_closure[MAX_STATES] = {false};

    printf("e-closures for all states:\n");
    for (int i = 0; i < nfa->num_states; i++) {
        // Reset visited and epsilon_closure arrays for each state
        for (int j = 0; j < nfa->num_states; j++) {
            visited[j] = false;
            epsilon_closure[j] = false;
        }

        // Compute e-closure for state i
        compute_epsilon_closure(nfa, i, visited, epsilon_closure);

        printf("e-closure(%d): {", i);
        bool first = true;
        for (int j = 0; j < nfa->num_states; j++) {
            if (epsilon_closure[j]) {
                if (!first) {
                    printf(", ");
                }
                printf("%d", j);
                first = false;
            }
        }
        printf("}\n");
    }
}

int main() {
    NFA nfa;
    int num_states;

    printf("Enter the number of states in the NFA: ");
    scanf("%d", &num_states);
    nfa.num_states = num_states;

    // Initialize transitions with 0 (no transition)
    for (int i = 0; i < MAX_STATES; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < MAX_STATES; k++) {
                nfa.transitions[i][j][k] = 0;
            }
        }
    }

    // Example NFA with e-moves (transitions[0][0][1] = 1 represents e-transition from state 0 to state 1)
    nfa.transitions[0][0][1] = 1;
    nfa.transitions[1][0][2] = 1;
    nfa.transitions[2][1][3] = 1;
    nfa.transitions[3][0][4] = 1;
    nfa.transitions[3][2][5] = 1;

    print_epsilon_closures(&nfa);

    return 0;
}
