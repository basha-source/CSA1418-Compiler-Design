%{
#include<stdio.h>
int count = 0;
%}

%%
[aAeEiIoOuU]     { count++; }   /* match vowels */
.|\n             ;              /* ignore others */

%%

int main()
{
    printf("Enter a sentence:\n");
    yylex();
    printf("Number of vowels: %d\n", count);
    return 0;
}

int yywrap()
{
    return 1;
}
