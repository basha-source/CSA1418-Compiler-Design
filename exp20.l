%{
#include<stdio.h>
%}

%%
[0-9]+\.[0-9]+      { printf("Float: %s\n", yytext); }
[0-9]+              { printf("Integer: %s\n", yytext); }
\".*\"              { printf("String: %s\n", yytext); }
\'.\'               { printf("Char: %s\n", yytext); }

.|\n                ;

%%

int main()
{
    yyin=fopen("sample1.c","r");
    yylex();
    return 0;
}

int yywrap(){ return 1; }
