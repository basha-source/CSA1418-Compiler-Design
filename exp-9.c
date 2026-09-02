#include <stdio.h>
#include <string.h>

#define MAX 20

char productions[MAX][MAX];
char followSet[MAX][MAX];
int n;

/* Add a symbol to FOLLOW set without duplication */
void addFollow(char nonTerminal, char symbol) {
    int i = nonTerminal - 'A';

    if (strchr(followSet[i], symbol) == NULL) {
        int len = strlen(followSet[i]);
        followSet[i][len] = symbol;
        followSet[i][len + 1] = '\0';
    }
}

/* Find FOLLOW sets for the given grammar */
void findFollow() {

    /* S is the start symbol */
    addFollow('S', '$');

    /*
       Grammar:
       S -> AaAb
       S -> BbBa
       A -> ε
       B -> ε
    */

    /* From S -> A a A b */
    addFollow('A', 'a');   // First A followed by 'a'
    addFollow('A', 'b');   // Second A followed by 'b'

    /* From S -> B b B a */
    addFollow('B', 'b');   // First B followed by 'b'
    addFollow('B', 'a');   // Second B followed by 'a'
}

int main() {

    memset(followSet, 0, sizeof(followSet));

    findFollow();

    printf("Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> epsilon\n");
    printf("B -> epsilon\n\n");

    printf("FOLLOW Sets:\n");
    printf("FOLLOW(S) = { %s }\n", followSet['S' - 'A']);
    printf("FOLLOW(A) = { %s }\n", followSet['A' - 'A']);
    printf("FOLLOW(B) = { %s }\n", followSet['B' - 'A']);

    return 0;
}
