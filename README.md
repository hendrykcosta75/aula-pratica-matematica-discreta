# Aula Prática — Matemática Discreta

Resoluções da lista de exercícios de programação da disciplina **Matemática Discreta**.

- **Instituição:** Universidade Federal de Alagoas (UFAL) — Instituto de Computação
- **Disciplina:** Matemática Discreta
- **Professor:** Bruno Almeida Pimentel
- **Semestre:** 2026.2

## Equipe

- Filipe Sena Oliveira
- Hendryk de Oliveira Costa
- Arthur Cauã Ribeiro Alves
- Artur Almeida
- Kalyl Vinicius de Lima Peixoto

## Sobre a lista

A lista tem 10 questões de programação, todas concluídas. Cada integrante ficou responsável por 2 questões, e cada resolução fica em um arquivo `.c` próprio, com comentários curtos explicando a ideia.

## Status das questões

| #  | Tema                                             | Arquivo                             | Autor    | Status     |
|----|--------------------------------------------------|-------------------------------------|----------|------------|
| 1  | Verificar se um inteiro é primo                  | `questao01_primo.c`                 | Filipe   | Concluída  |
| 2  | Listar o máximo de primos em 60 segundos         | `questao02_primos_60s.c`            | Artur    | Concluída  |
| 3  | Decompor um inteiro em fatores primos            | `questao03_fatores_primos.c`        | Artur    | Concluída  |
| 4  | mdc e mmc a partir dos fatores primos            | `questao04_mdc_mmc.c`               | Arthur   | Concluída  |
| 5  | mdc pelo Algoritmo de Euclides                   | `questao05_mdc_euclides.c`          | Arthur   | Concluída  |
| 6  | Coeficientes `s` e `t` de `mdc(a,b) = s·a + t·b` | `questao06_coeficientes.c`          | Kalyl    | Concluída  |
| 7  | Inverso de `a` módulo `b`                        | `questao07_inverso_modular.c`       | Filipe   | Concluída  |
| 8  | Solução de `ax ≡ b (mod m)`                      | `questao08_congruencia_linear.c`    | Kalyl    | Concluída  |
| 9  | TCR com três congruências                        | `questao9_trc_tres_congruencias.c`  | Hendryk  | Concluída  |
| 10 | TCR generalizado para `n` congruências           | `questao10_trc_n_congruencias.c`    | Hendryk  | Concluída  |

## Compilar e executar

Todas as resoluções usam apenas a biblioteca padrão de C (C11) e leem a entrada por `stdin`.

```bash
gcc -std=c11 -Wall -Wextra -O2 -o q1  questao01_primo.c
gcc -std=c11 -Wall -Wextra -O2 -o q2  questao02_primos_60s.c
gcc -std=c11 -Wall -Wextra -O2 -o q3  questao03_fatores_primos.c
gcc -std=c11 -Wall -Wextra -O2 -o q4  questao04_mdc_mmc.c
gcc -std=c11 -Wall -Wextra -O2 -o q5  questao05_mdc_euclides.c
gcc -std=c11 -Wall -Wextra -O2 -o q6  questao06_coeficientes.c
gcc -std=c11 -Wall -Wextra -O2 -o q7  questao07_inverso_modular.c
gcc -std=c11 -Wall -Wextra -O2 -o q8  questao08_congruencia_linear.c
gcc -std=c11 -Wall -Wextra -O2 -o q9  questao9_trc_tres_congruencias.c
gcc -std=c11 -Wall -Wextra -O2 -o q10 questao10_trc_n_congruencias.c
```

### Exemplos

As entradas de teste ficam em [`exemplos/`](exemplos/), um arquivo por questão:

```bash
./q1  < exemplos/entrada01.txt   # 17 eh primo.
./q2                             # lista primos por 60 segundos
./q3  < exemplos/entrada03.txt   # Fatores primos: 2 x 2 x 2 x 3 x 3 x 5
./q4  < exemplos/entrada04.txt   # MDC = 6 / MMC = 36
./q5  < exemplos/entrada05.txt   # MDC(48,18) = 6
./q6  < exemplos/entrada06.txt   # MDC = 6, s = -1, t = 1
./q7  < exemplos/entrada07.txt   # 5
./q8  < exemplos/entrada08.txt   # Solucao: x = 4 / Quantidade de solucoes: 2
./q9  < exemplos/entrada09.txt   # x = 23 (mod 105)
./q10 < exemplos/entrada10.txt   # x = 3488 (mod 15015)
```

## Como contribuir

1. Crie um branch com o número da questão:

   ```bash
   git checkout -b questao05-mdc-euclides
   ```

2. Nomeie o arquivo no padrão `questaoNN_tema_curto.c`.
3. Compile sem avisos:

   ```bash
   gcc -std=c11 -Wall -Wextra -O2 -o q05 questao05_mdc_euclides.c
   ```

4. Inclua um exemplo de entrada e saída no topo do arquivo.
5. Abra um pull request descrevendo a abordagem e os casos de teste.

Padrões do repositório: C11, sem warnings com `-Wall -Wextra`, entrada por `stdin`, saída legível e comentários curtos em português.

## Licença

Este repositório está sob a licença MIT. Veja [LICENSE](LICENSE).
