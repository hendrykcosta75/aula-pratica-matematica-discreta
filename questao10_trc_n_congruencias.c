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

// Soma modular sem estourar 64 bits.
long long somar_mod(long long a, long long m, long long t, long long modulo){
    return (long long)(((__int128)a + (__int128)m * t) % modulo);
}

// Verifica se a*b cabe em long long.
int cabe(long long a, long long b){
    return a <= 9223372036854775807LL / b;
}

// Combina x = a (mod m) com as congruencias de indice em diante.
int combinar(int restos[], int modulos[], int n, int indice, long long a, long long m, long long resultado[]){
    if(indice == n){
        resultado[0] = a;
        resultado[1] = m;
        return 1;
    }

    long long g = mdc(m, modulos[indice]);
    long long diferenca = ajustar(restos[indice], modulos[indice]) - a;

    // Sem solucao quando a diferenca nao e divisivel pelo mdc.
    if(diferenca % g != 0){
        return 0;
    }

    long long reduzido = m / g;
    long long modulo_reduzido = modulos[indice] / g;
    long long t = 0;

    if(modulo_reduzido != 1){
        long long inverso_parcial = inverso(ajustar(reduzido, modulo_reduzido), modulo_reduzido);
        t = multiplicar_mod(ajustar(diferenca / g, modulo_reduzido), inverso_parcial, modulo_reduzido);
    }

    if(cabe(reduzido, modulos[indice]) == 0){
        return -1;
    }

    long long novo_modulo = reduzido * modulos[indice];
    long long novo_resto = somar_mod(a, m, t, novo_modulo);

    // Segue para a proxima congruencia.
    return combinar(restos, modulos, n, indice + 1, novo_resto, novo_modulo, resultado);
}

int main(){
    int n;
    if(scanf("%d", &n) != 1 || n < 1){
        printf("Entrada invalida.\n");
        return 0;
    }

    int restos[n];
    int modulos[n];
    input(restos, modulos, n, 0);

    long long resultado[2];
    long long primeiro_resto = ajustar(restos[0], modulos[0]);
    int estado = combinar(restos, modulos, n, 1, primeiro_resto, modulos[0], resultado);

    if(estado == 0){
        printf("Sem solucao.\n");
        return 0;
    }

    if(estado == -1){
        printf("Modulos grandes demais.\n");
        return 0;
    }

    printf("x = %lld (mod %lld)\n", resultado[0], resultado[1]);
    return 0;
}
