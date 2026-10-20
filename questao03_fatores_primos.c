#include <stdio.h>

// Fatoracao prima por divisao sucessiva.
int fatorar(int numero, int divisor, int fatores[], int quantidade)
{
    // Nao ha mais fatores para extrair.
    if(numero == 1)
    {
        return quantidade;
    }

    // Se o divisor passou da raiz, o que sobrou e primo.
    if(divisor > numero / divisor)
    {
        fatores[quantidade] = numero;
        return quantidade + 1;
    }

    if(numero % divisor == 0)
    {
        fatores[quantidade] = divisor;
        return fatorar(numero / divisor, divisor, fatores, quantidade + 1);
    }

    // Depois do 2, testa apenas impares.
    if(divisor == 2)
    {
        return fatorar(numero, 3, fatores, quantidade);
    }

    return fatorar(numero, divisor + 2, fatores, quantidade);
}

// Imprime os fatores no formato "2 x 2 x 3".
int mostrar_fatores(int fatores[], int quantidade, int indice)
{
    if(indice >= quantidade)
    {
        printf("\n");
        return 0;
    }

    if(indice > 0)
    {
        printf(" x ");
    }

    printf("%d", fatores[indice]);
    return mostrar_fatores(fatores, quantidade, indice + 1);
}

int main()
{
    int numero;
    int fatores[32];
    int quantidade;

    printf("Digite um inteiro maior que 1: ");

    if(scanf("%d", &numero) != 1 || numero < 2)
    {
        printf("Entrada invalida. Digite um inteiro maior que 1.\n");
        return 1;
    }

    quantidade = fatorar(numero, 2, fatores, 0);

    printf("Fatores primos: ");
    mostrar_fatores(fatores, quantidade, 0);

    return 0;
}
