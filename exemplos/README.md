# Exemplos de entrada

Um arquivo por questão, no formato que cada programa lê do `stdin`. A questão 2 não tem arquivo: ela roda por 60 segundos e não recebe entrada.

| Arquivo | Questão | Conteúdo | Saída esperada |
|---------|---------|----------|----------------|
| `entrada01.txt` | 1 | `17` | `17 eh primo.` |
| `entrada03.txt` | 3 | `360` | `Fatores primos: 2 x 2 x 2 x 3 x 3 x 5` |
| `entrada04.txt` | 4 | `12 18` | `MDC = 6` e `MMC = 36` |
| `entrada05.txt` | 5 | `48 18` | `MDC(48,18) = 6` |
| `entrada06.txt` | 6 | `12 18` | `MDC = 6`, `s = -1`, `t = 1` |
| `entrada07.txt` | 7 | `3 7` | `5` |
| `entrada08.txt` | 8 | `4 6 10` | `Solucao: x = 4` e `Quantidade de solucoes: 2` |
| `entrada09.txt` | 9 | três pares `a m` | `x = 23 (mod 105)` |
| `entrada10.txt` | 10 | `5` e cinco pares `a m` | `x = 3488 (mod 15015)` |

## Como usar

```bash
gcc -std=c11 -Wall -Wextra -O2 -o q1 questao01_primo.c
./q1 < exemplos/entrada01.txt
```

Os comandos de todas as questões estão no [README principal](../README.md#exemplos).
