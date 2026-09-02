%{
#include<stdio.h>
int chars=0, words=0, lines=0;
%}

%%
"//".*                ; 
"/*"([^*]|\*+[^*/])*\*+"/"   ; 

[ \t]+                ;  
\n                    { lines++; }
[a-zA-Z0-9_]+         { words++; chars += yyleng; }
.                     { chars++; }

%%

int main()
{
    yyin = fopen("sample.c","r");
    yylex();
    printf("Characters: %d\nWords: %d\nLines: %d\n", chars, words, lines);
    return 0;
}

int yywrap(){ return 1; }
