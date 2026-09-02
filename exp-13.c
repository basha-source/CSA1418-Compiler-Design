#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

/* Function for non-terminal A -> epsilon */
int A() {
    return 1;
}

/* Function for non-terminal B -> epsilon */
int B() {
    return 1;
}

/* Function for start symbol S */
int S() {

    int start = pos;

    /* Try S -> A a A b */
    if (A() && input[pos] == 'a') {
        pos++;

        if (A() && input[pos] == 'b') {
            pos++;

            if (input[pos] == '\0')
                return 1;
        }
    }

    /* Backtrack and try S -> B b B a */
    pos = start;

    if (B() && input[pos] == 'b') {
        pos++;

        if (B() && input[pos] == 'a') {
            pos++;

            if (input[pos] == '\0')
                return 1;
        }
    }

    return 0;
}

int main() {

    printf("Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> epsilon\n");
    printf("B -> epsilon\n\n");

    printf("Enter the input string: ");
    scanf("%s", input);

    if (S())
        printf("\nThe string \"%s\" is ACCEPTED by the grammar.\n", input);
    else
        printf("\nThe string \"%s\" is NOT ACCEPTED by the grammar.\n", input);

    return 0;
}
