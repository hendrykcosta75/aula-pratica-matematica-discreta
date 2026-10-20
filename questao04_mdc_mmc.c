#include <stdio.h>

// MDC e MMC pela fatoracao em primos.
int main()
{
    int numeroA, numeroB;
    long long a, b;
    long long mdc, mmc;
    long long primo;
    int expoenteA, expoenteB, menorExpoente, maiorExpoente, i;

    if (scanf("%d %d", &numeroA, &numeroB) != 2)
    {
        return 1;
    }

    a = numeroA;
    b = numeroB;

    // Trabalha com valores positivos.
    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }

    // Caso especial: um dos numeros e zero.
    if (a == 0 || b == 0)
    {
        mdc = (a > b) ? a : b;
        printf("MDC = %lld\nMMC = 0\n", mdc);
        return 0;
    }

    mdc = 1;
    mmc = 1;

    // Percorre os fatores primos comuns aos dois numeros.
    for (primo = 2; primo <= a / primo || primo <= b / primo; primo++)
    {
        expoenteA = 0;
        expoenteB = 0;

        while (a % primo == 0)
        {
            a /= primo;
            expoenteA++;
        }

        while (b % primo == 0)
        {
            b /= primo;
            expoenteB++;
        }

        menorExpoente = (expoenteA < expoenteB) ? expoenteA : expoenteB;
        maiorExpoente = (expoenteA > expoenteB) ? expoenteA : expoenteB;

        // MDC usa o menor expoente; MMC usa o maior.
        for (i = 0; i < menorExpoente; i++)
        {
            mdc *= primo;
        }

        for (i = 0; i < maiorExpoente; i++)
        {
            mmc *= primo;
        }
    }

    // Fatores que sobraram depois da divisao.
    if (a > 1 && b > 1 && a == b)
    {
        mdc *= a;
        mmc *= a;
    }
    else
    {
        if (a > 1)
        {
            mmc *= a;
        }
        if (b > 1)
        {
            mmc *= b;
        }
    }

    printf("MDC = %lld\nMMC = %lld\n", mdc, mmc);
    return 0;
}
