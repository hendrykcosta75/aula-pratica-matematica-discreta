#include <stdio.h>

// Le os pares (resto, modulo) do sistema.
int input(int restos[], int modulos[], int n, int contador){
    if(contador == n){
        return 0;
    }
    if(scanf("%d %d", &restos[contador], &modulos[contador]) != 2){
        return 0;
    }
    return input(restos, modulos, n, contador + 1);
}

// mdc pelo algoritmo de Euclides.
long long mdc(long long a, long long b){
    if(b == 0){
        return a;
    }
    return mdc(b, a % b);
}

// Euclides estendido: devolve o mdc e os coeficientes em coeficientes[0] e [1].
long long euclides(long long valorA, long long valorB, long long coeficientes[]){
    if(valorB == 0){
        coeficientes[0] = 1;
        coeficientes[1] = 0;
        return valorA;
    }
    long long g = euclides(valorB, valorA % valorB, coeficientes);
    long long x = coeficientes[0];
    long long y = coeficientes[1];
    coeficientes[0] = y;
    coeficientes[1] = x - (valorA / valorB) * y;
    return g;
}

// Resto sempre no intervalo [0, modulo).
long long ajustar(long long valor, long long modulo){
    long long resto = valor % modulo;
    if(resto < 0){
        resto = resto + modulo;
    }
    return resto;
}

// Inverso de a modulo m; devolve -1 quando nao existe.
long long inverso(long long a, long long m){
    long long coeficientes[2];
    long long g = euclides(ajustar(a, m), m, coeficientes);
    if(g != 1){
        return -1;
    }
    return ajustar(coeficientes[0], m);
}

// Multiplicacao modular sem estourar 64 bits.
long long multiplicar_mod(long long a, long long b, long long m){
    return (long long)((__int128)a * b % m);
}

// Verifica se a*b cabe em long long.
int cabe(long long a, long long b){
    return a <= 9223372036854775807LL / b;
}

// Confere se os modulos sao coprimos dois a dois.
int coprimos(int modulos[], int i, int j, int n){
    if(i >= n){
        return 1;
    }
    if(j >= n){
        return coprimos(modulos, i + 1, i + 2, n);
    }
    if(mdc(modulos[i], modulos[j]) != 1){
        return 0;
    }
    return coprimos(modulos, i, j + 1, n);
}

int main(){
    int restos[3];
    int modulos[3];

    input(restos, modulos, 3, 0);

    // Hipotese do TCR: modulos coprimos dois a dois.
    if(coprimos(modulos, 0, 1, 3) == 0){
        printf("Os modulos nao sao coprimos.\n");
        return 0;
    }

    if(cabe(modulos[0], modulos[1]) == 0){
        printf("Modulos grandes demais.\n");
        return 0;
    }

    long long produto = (long long)modulos[0] * modulos[1];

    if(cabe(produto, modulos[2]) == 0){
        printf("Modulos grandes demais.\n");
        return 0;
    }

    long long M = produto * modulos[2];
    long long M1 = M / modulos[0];
    long long M2 = M / modulos[1];
    long long M3 = M / modulos[2];
    long long y1 = inverso(M1, modulos[0]);
    long long y2 = inverso(M2, modulos[1]);
    long long y3 = inverso(M3, modulos[2]);

    // x = soma(resto * Mi * yi) mod M.
    long long soma = 0;
    soma = (soma + multiplicar_mod(ajustar(restos[0], modulos[0]), multiplicar_mod(M1, y1, M), M)) % M;
    soma = (soma + multiplicar_mod(ajustar(restos[1], modulos[1]), multiplicar_mod(M2, y2, M), M)) % M;
    soma = (soma + multiplicar_mod(ajustar(restos[2], modulos[2]), multiplicar_mod(M3, y3, M), M)) % M;

    printf("x = %lld (mod %lld)\n", soma, M);
    return 0;
}
