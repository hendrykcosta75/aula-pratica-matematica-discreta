#include <stdio.h>

// mdc pelo algoritmo de Euclides, com correcao de sinal.
int mdc(int a, int b)
{
    if (a < 0)
    {
        a = -a;
    }

    if (b < 0)
    {
        b = -b;
    }

    if (b == 0)
    {
        return a;
    }

    return mdc(b, a % b);
}

int main()
{
    int a, b;

    if (scanf("%d %d", &a, &b) != 2)
    {
        return 1;
    }

    printf("MDC(%d,%d) = %d\n", a, b, mdc(a, b));

    return 0;
}
