%{
#include<stdio.h>
%}

%%
\<[^>]+\>      { printf("Tag: %s\n", yytext); }

.|\n           ;

%%

int main()
{
    yyin=fopen("sample22.html","r");
    yylex();
    return 0;
}

int yywrap(){ return 1; }
