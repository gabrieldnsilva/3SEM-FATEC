# Algoritmos de Escalonamento de Processos

Os algoritmos de escalonamento determinam qual processo será executado pelo processador em um determinado momento. Vamos visualizar os principais algoritmos mencionados.

## FIFO (First In, First Out) / FCFS (First Come, First Served)

No algoritmo FIFO, os processos são executados na ordem exata em que chegam à fila de prontos.

### Exemplo Visual

Considere os seguintes processos:

| Processo | Tempo de Chegada | Tempo de Execução |
| -------- | ---------------- | ----------------- |
| P1       | 0                | 10                |
| P2       | 1                | 5                 |
| P3       | 2                | 8                 |

**Diagrama de Gantt para FIFO:**

```
     P1             P2       P3
0    |--------------|--------|---------> tempo
     0             10       15       23
```

**Análise:**

-   P1 chega em t=0 e executa por 10 unidades de tempo
-   P2 chega em t=1, mas espera P1 terminar, então executa de t=10 até t=15
-   P3 chega em t=2, mas espera P1 e P2 terminarem, então executa de t=15 até t=23

**Tempo Médio de Espera:** (0 + 9 + 13) / 3 = 7.33 unidades de tempo

### Exemplo Visual Adicional

Considere os seguintes processos que chegam todos no mesmo tempo:

| Processo | Tempo de Chegada | Tempo de Execução |
| -------- | ---------------- | ----------------- |
| P1       | 0                | 6                 |
| P2       | 0                | 8                 |
| P3       | 0                | 4                 |
| P4       | 0                | 2                 |
| P5       | 0                | 1                 |

**Diagrama de Gantt para FIFO (assumindo a ordem de chegada P1, P2, P3, P4, P5):**

```
     P1       P2        P3    P4 P5
0    |---------|---------|-----|--|---> tempo
     0         6        14    18  20  21
```

**Análise:**

-   P1 começa em t=0 e termina em t=6
-   P2 começa em t=6 e termina em t=14
-   P3 começa em t=14 e termina em t=18
-   P4 começa em t=18 e termina em t=20
-   P5 começa em t=20 e termina em t=21

**Tempo Médio de Espera:** (0 + 6 + 14 + 18 + 20) / 5 = 11.6 unidades de tempo

## SJF (Shortest Job First) - Não Preemptivo

No algoritmo SJF não preemptivo, o processo com menor tempo de execução é selecionado para execução, mas uma vez iniciado, o processo executa até o fim.

### Exemplo Visual

Usando os mesmos processos do exemplo anterior:

| Processo | Tempo de Chegada | Tempo de Execução |
| -------- | ---------------- | ----------------- |
| P1       | 0                | 10                |
| P2       | 1                | 5                 |
| P3       | 2                | 8                 |

**Diagrama de Gantt para SJF não preemptivo:**

```
     P1             P2       P3
0    |--------------|--------|---------> tempo
     0             10       15       23
```

Neste caso específico, o resultado é idêntico ao FIFO porque P1 já estava em execução quando P2 e P3 chegaram.

**Exemplo com chegadas diferentes:**

| Processo | Tempo de Chegada | Tempo de Execução |
| -------- | ---------------- | ----------------- |
| P1       | 0                | 7                 |
| P2       | 2                | 4                 |
| P3       | 4                | 1                 |
| P4       | 6                | 4                 |

**Diagrama de Gantt para SJF não preemptivo:**

```
     P1             P3  P2       P4
0    |--------------|---|--------|----> tempo
     0              7   8       12    16
```

### Exemplo Visual Adicional

Usando os processos que chegam simultaneamente:

| Processo | Tempo de Chegada | Tempo de Execução |
| -------- | ---------------- | ----------------- |
| P1       | 0                | 6                 |
| P2       | 0                | 8                 |
| P3       | 0                | 4                 |
| P4       | 0                | 2                 |
| P5       | 0                | 1                 |

**Diagrama de Gantt para SJF não preemptivo:**

```
     P5 P4    P3      P1       P2
0    |-|---|-----|------|-------|--> tempo
     0 1   3     7      13      21
```

**Análise:**

-   P5 tem o menor tempo de execução (1), então começa em t=0
-   P4 tem o próximo menor tempo (2), então executa após P5
-   P3 segue com tempo de execução de 4 unidades
-   P1 segue com tempo de execução de 6 unidades
-   P2 tem o maior tempo (8) e é executado por último

**Tempo Médio de Espera:** (0 + 13 + 3 + 1 + 0) / 5 = 3.4 unidades de tempo

## SJF (Shortest Job First) - Preemptivo (SRTF)

No algoritmo SJF preemptivo, também conhecido como SRTF (Shortest Remaining Time First), o processo com o menor tempo restante é selecionado para execução, e pode ser interrompido se chegar um processo com tempo de execução menor.

### Exemplo Visual

Usando os processos:

| Processo | Tempo de Chegada | Tempo de Execução |
| -------- | ---------------- | ----------------- |
| P1       | 0                | 7                 |
| P2       | 2                | 4                 |
| P3       | 4                | 1                 |
| P4       | 6                | 4                 |

**Diagrama de Gantt para SJF preemptivo (SRTF):**

```
     P1       P2       P3  P2       P4
0    |---------|---------|---|-------|----> tempo
     0         2         4   5       9    13
```

**Análise:**

-   P1 começa em t=0
-   P2 chega em t=2 com tempo menor que o restante de P1, então P1 é interrompido
-   P3 chega em t=4 com tempo menor que o restante de P2, então P2 é interrompido
-   P3 termina em t=5, P2 retoma (com 3 unidades restantes)
-   P4 chega em t=6, mas não interrompe P2 porque o tempo restante de P2 (2) é menor
-   P2 termina em t=9, então P4 executa
-   P1 executa por último com suas 5 unidades restantes

### Exemplo Visual Adicional

Usando os processos com chegadas simultâneas:

| Processo | Tempo de Chegada | Tempo de Execução |
| -------- | ---------------- | ----------------- |
| P1       | 0                | 6                 |
| P2       | 0                | 8                 |
| P3       | 0                | 4                 |
| P4       | 0                | 2                 |
| P5       | 0                | 1                 |

**Diagrama de Gantt para SJF preemptivo (SRTF):**

```
     P5 P4    P3      P1       P2
0    |-|---|-----|------|-------|--> tempo
     0 1   3     7      13      21
```

**Análise:**

-   Como todos os processos chegam ao mesmo tempo (t=0), o SRTF escolhe sempre o processo com menor tempo restante para execução
-   A ordem será a mesma do SJF não preemptivo, pois não há chegadas posteriores que causariam preempções
-   O processo P5 executa primeiro por ter o menor tempo (1)
-   O processo P4 executa em seguida (tempo 2)
-   O processo P3 vem depois (tempo 4)
-   O processo P1 segue (tempo 6)
-   O processo P2 executa por último (tempo 8)

**Tempo Médio de Espera:** (0 + 13 + 3 + 1 + 0) / 5 = 3.4 unidades de tempo

**Nota:** Neste exemplo específico onde todos os processos chegam simultaneamente, o SJF preemptivo (SRTF) se comporta exatamente como o SJF não preemptivo, pois não há novas chegadas que gerariam preempções.

## Comparação Visual

### Média de Tempo de Espera

| Algoritmo             | Vantagens                        | Desvantagens                         |
| --------------------- | -------------------------------- | ------------------------------------ |
| FIFO                  | Simples de implementar           | Efeito comboio (convoy effect)       |
|                       | Sem starvation                   | Tempos de espera podem ser longos    |
| SJF Não Preemptivo    | Minimiza o tempo médio de espera | Pode causar starvation               |
|                       | Bom para lotes de trabalho       | Precisa conhecer o tempo de execução |
| SJF Preemptivo (SRTF) | Menor tempo médio de espera      | Maior sobrecarga de context switch   |
|                       | Responsivo a processos curtos    | Pode causar starvation               |

### Representação Gráfica da Eficiência

```
Eficiência (Tempo médio de espera) →
↑ Melhor
│
│   ┌───┐
│   │   │
│   │   │     ┌───┐
│   │   │     │   │
│   │   │     │   │     ┌───┐
│   │   │     │   │     │   │
└───┴───┴─────┴───┴─────┴───┴─────→
    SRTF      SJF       FIFO
```

## Implementação Prática

Para visualizar esses algoritmos em funcionamento, você pode usar ferramentas de simulação como:

1. Simuladores online
2. Ferramentas de visualização como o Gantt Project
3. Implementações em linguagens de programação

## Referências

-   Sistemas Operacionais Modernos - Andrew S. Tanenbaum
-   Operating System Concepts - Silberschatz, Galvin, Gagne
