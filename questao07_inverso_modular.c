#include <stdio.h>

// Euclides estendido: devolve mdc(a,b) e coeficientes x, y com
// x*a + y*b = mdc(a,b).
int euclides(int a, int b, int *x, int *y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;
    }
    else
    {
        int x1, y1;
        int mdc = euclides(b, a % b, &x1, &y1);

        *x = y1;
        *y = x1 - (a / b) * y1;

        return mdc;
    }
}

int main()
{
    int a, b;
    int x, y;

    if (scanf("%d %d", &a, &b) != 2)
    {
        return 1;
    }

    // O modulo precisa ser maior que 1.
    if (b <= 1)
    {
        printf("Modulo invalido\n");
        return 0;
    }

    // Reduz a ao intervalo [0, b); assim o mdc sai sempre positivo.
    a = ((a % b) + b) % b;

    int mdc = euclides(a, b, &x, &y);

    if (mdc != 1)
    {
        printf("O inverso modular nao existe\n");
    }
    else
    {
        int inverso = ((x % b) + b) % b;
        printf("%d\n", inverso);
    }

    return 0;
}
