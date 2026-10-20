#include <stdio.h>

// Conta os divisores de x entre 2 e y.
int primo(int x, int y, int divisor)
{
    if(y < 2)
    {
        return divisor;
    }
    else if(x % y == 0)
    {
        return primo(x, y - 1, divisor + 1);
    }
    else
    {
        return primo(x, y - 1, divisor);
    }
}

// Parte inteira da raiz quadrada, subtraindo impares.
int raiz(int x, int impar, int resultado)
{
    if(x < impar)
    {
        return resultado;
    }
    return raiz(x - impar, impar + 2, resultado + 1);
}

int main()
{
    int x;
    if(scanf("%d", &x) != 1){
        return 0;
    }

    // 0, 1 e negativos nao sao primos.
    if(x < 2)
    {
        printf("%d Nao eh primo.\n", x);
        return 0;
    }

    // Basta procurar divisores ate a raiz quadrada.
    int limite = raiz(x, 1, 0);
    int divisores = primo(x, limite, 0);

    if(divisores > 0)
    {
        printf("%d Nao eh primo.\n", x);
    }
    else
    {
        printf("%d eh primo.\n", x);
    }

    return 0;
}
