#include <stdio.h>
#include <time.h>

// Primos guardados para teste: ate 1 milhao, o que basta para
// testar qualquer candidato menor que 10^12.
#define LIMITE_ARMAZENADO 1000000
#define TAMANHO_ARRAY 80000

// Testa se numero e primo dividindo pelos primos ja guardados.
int eh_primo(int numero, int primos[], int quantidade, int indice)
{
    if(indice >= quantidade)
    {
        return 1;
    }
    if(primos[indice] > numero / primos[indice])
    {
        return 1;
    }
    if(numero % primos[indice] == 0)
    {
        return 0;
    }
    return eh_primo(numero, primos, quantidade, indice + 1);
}

int main()
{
    static int primos[TAMANHO_ARRAY];
    static char buffer_saida[1048576];
    int quantidade = 1;
    long long total = 1;
    int candidato = 3;
    time_t inicio;

    primos[0] = 2;
    setvbuf(stdout, buffer_saida, _IOFBF, sizeof(buffer_saida));

    printf("Numeros primos encontrados durante 60 segundos:\n");
    printf("2\n");

    inicio = time(NULL);

    // So testa impares, durante 60 segundos.
    while(difftime(time(NULL), inicio) < 60.0)
    {
        if(eh_primo(candidato, primos, quantidade, 0))
        {
            total++;
            printf("%d\n", candidato);

            // Guarda apenas os primos pequenos, usados na divisao.
            if(candidato <= LIMITE_ARMAZENADO && quantidade < TAMANHO_ARRAY)
            {
                primos[quantidade] = candidato;
                quantidade++;
            }
        }
        candidato = candidato + 2;
    }

    fflush(stdout);
    printf("Total de primos encontrados: %lld\n", total);
    return 0;
}
