#include <stdio.h>
#include <string.h>

char str[100];
int i = 0;

int E();
int T();
int F();

int E()
{
    if (!T())
        return 0;

    while (str[i] == '+')
    {
        i++;
        if (!T())
            return 0;
    }

    return 1;
}

int T()
{
    if (!F())
        return 0;

    while (str[i] == '*')
    {
        i++;
        if (!F())
            return 0;
    }

    return 1;
}

int F()
{
    if (str[i] == 'i' && str[i + 1] == 'd')
    {
        i += 2;
        return 1;
    }

    if (str[i] == '(')
    {
        i++;

        if (E() && str[i] == ')')
        {
            i++;
            return 1;
        }
    }

    return 0;
}

int main()
{
    printf("Enter input string: ");
    scanf("%s", str);

    if (E() && str[i] == '\0')
        printf("String is accepted by the grammar.\n");
    else
        printf("String is rejected by the grammar.\n");

    return 0;
}
