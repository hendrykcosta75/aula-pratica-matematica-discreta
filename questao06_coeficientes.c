#include <stdio.h>

// Euclides estendido: devolve mdc(a,b) e os coeficientes s e t
// tais que s*a + t*b = mdc(a,b).
int ee(int a, int b, int *s, int *t) {
    int x, y, m;

    if (b == 0) {
        *s = 1;
        *t = 0;
        return a;
    }

    m = ee(b, a % b, &x, &y);

    *s = y;
    *t = x - (a / b) * y;

    return m;
}

int main() {
    int a, b, s, t, m;

    printf("Digite dois numeros: ");
    if (scanf("%d %d", &a, &b) != 2) {
        return 1;
    }

    m = ee(a, b, &s, &t);

    printf("MDC = %d\n", m);
    printf("s = %d\n", s);
    printf("t = %d\n", t);
    printf("%d = %d * %d + %d * %d\n", m, s, a, t, b);

    return 0;
}
