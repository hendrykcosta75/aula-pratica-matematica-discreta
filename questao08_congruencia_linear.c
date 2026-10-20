#include <stdio.h>

// Euclides estendido: devolve mdc(a,b) e s, t com s*a + t*b = mdc(a,b).
int ee(int a, int b, int *s, int *t) {
    int x, y, d;

    if (b == 0) {
        *s = 1;
        *t = 0;
        return a;
    }

    d = ee(b, a % b, &x, &y);

    *s = y;
    *t = x - (a / b) * y;

    return d;
}

int main() {
    int a, b, m, s, t, d, x;

    printf("Digite a, b e m: ");
    if (scanf("%d %d %d", &a, &b, &m) != 3) {
        return 1;
    }

    if (m <= 0) {
        printf("Modulo invalido.\n");
        return 0;
    }

    // Reduz a ao intervalo [0, m); assim o mdc sai sempre positivo.
    a = ((a % m) + m) % m;

    d = ee(a, m, &s, &t);

    // Ha solucao quando o mdc divide b.
    if (b % d != 0) {
        printf("Nao existe solucao.\n");
    } else {
        x = (s * (b / d)) % m;

        if (x < 0)
            x += m;

        printf("Solucao: x = %d\n", x);

        // Quando d > 1 existem d solucoes distintas modulo m.
        if (d > 1)
            printf("Quantidade de solucoes: %d\n", d);
    }

    return 0;
}
