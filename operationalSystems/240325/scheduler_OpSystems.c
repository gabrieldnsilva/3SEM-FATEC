#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_TIME 100

typedef struct
{
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

typedef struct
{
    int process_id;
    int time;
} GanttChart;

void sort_by_arrival_time(Process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (processes[j].arrival_time > processes[j + 1].arrival_time)
            {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int find_shortest_job(Process processes[], int n, int current_time)
{
    int shortest_job_index = -1;
    int min_burst_time = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0)
        {
            if (processes[i].remaining_time < min_burst_time)
            {
                min_burst_time = processes[i].remaining_time;
                shortest_job_index = i;
            }
        }
    }

    return shortest_job_index;
}

void fifo_scheduling(Process processes[], int n, GanttChart chart[], int *chart_size)
{
    sort_by_arrival_time(processes, n);

    int current_time = 0;
    *chart_size = 0;

    for (int i = 0; i < n; i++)
    {
        if (current_time < processes[i].arrival_time)
        {
            current_time = processes[i].arrival_time;
        }

        chart[*chart_size].process_id = processes[i].id;
        chart[*chart_size].time = current_time;
        (*chart_size)++;

        current_time += processes[i].burst_time;

        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    chart[*chart_size].process_id = -1;
    chart[*chart_size].time = current_time;
    (*chart_size)++;
}

// SLF Scheduling

// SLRT Scheduling

void draw_gantt_chart(GanttChart chart[], int size)
{
    printf("\n Diagrama de Gantt\n\n");

    printf(" ");

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < chart[i + 1].time - chart[i].time; j++)
        {
            printf("-");
        }

        printf(" ");
    }
    printf("\n|");

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < chart[i + 1].time - chart[i].time - 1; j++)
        {
            if (j == (chart[i + 1].time - chart[i].time - 1) / 2)
            {
                if (chart[i].process_id == -1)
                {
                    printf(" ");
                }
                else
                {
                    printf("P%d", chart[i].process_id);
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("|");
    }
    printf("\n ");

    // Desenhar a linha inferior
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < chart[i + 1].time - chart[i].time; j++)
        {
            printf("-");
        }
        printf(" ");
    }
    printf("\n");

    // Desenhar os tempos
    for (int i = 0; i < size; i++)
    {
        printf("%d", chart[i].time);

        // Alinhar os números de tempo
        if (i < size - 1)
        {
            int spaces = chart[i + 1].time - chart[i].time;
            for (int j = 0; j < spaces; j++)
            {
                printf(" ");
            }
        }
    }
    printf("\n\n");
}

void display_metrics(Process processes[], int n)
{
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("\nMétricas dos Processos:\n");
    printf("+----+----------------+----------------+----------------+----------------+----------------+\n");
    printf("| ID | Tempo Chegada  | Tempo Execução | Tempo Conclusão| Tempo Retorno  | Tempo Espera   |\n");
    printf("+----+----------------+----------------+----------------+----------------+----------------+\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %2d | %14d | %14d | %14d | %14d | %14d |\n",
               processes[i].id,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);

        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("+----+----------------+----------------+----------------+----------------+----------------+\n");
    printf("\nTempo médio de espera: %.2f\n", avg_waiting_time);
    printf("Tempo médio de retorno: %.2f\n", avg_turnaround_time);
}

int main()
{
    Process processes[MAX_PROCESSES];
    GanttChart chart[MAX_TIME * 2];
    int chart_size = 0;
    int n, choice;

    printf("Simulador de Algoritmos de Escalonamento de Processos\n");
    printf("----------------------------------------------------\n\n");

    printf("Digite o número de processos (maximo %d):", MAX_PROCESSES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESSES)
    {
        printf("Número de processos inválido\n");
        return 1;
    }

    printf("\nDigite os detalhes de cada processo:\n");
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("\nProcesso P%d:\n", processes[i].id);
        printf("Tempo de chegada: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Tempo de Execução: ");
        scanf("%d", &processes[i].burst_time);

        if (processes[i].arrival_time < 0 || processes[i].burst_time <= 0)
        {
            printf("Valores inválidos! Tente novamente.\n");
            i--;
            continue;
        }
    }

    do
    {

        printf("\nEscolha o algoritmo de escalonamento:\n");
        printf("1. FIFO (First In - First Out)\n");
        printf("2. SJF (Shortest Job First) - Não preempeptivo [EM CONSTRUÇÃO]\n");
        printf("3. SRTF (Shortest Remaining Time First)  - SJF Preempeptivo [EM CONSTRUÇÃO]\n");
        printf("0. Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &choice);

        Process temp_processes[MAX_PROCESSES];
        for (int i = 0; i < n; i++)
        {
            temp_processes[i] = processes[i];
            temp_processes[i].remaining_time = processes[i].burst_time;
        }

        switch (choice)
        {
        case 1:
            printf("\nExecutando algoritmo FIFO...\n");
            fifo_scheduling(temp_processes, n, chart, &chart_size);
            draw_gantt_chart(chart, chart_size);
            display_metrics(temp_processes, n);
            break;

        case 2:
            printf("Em construção");
            break;

        case 3:
            printf("Em construção");
            break;

        case 0:
            printf("\nEncerrando o programa...\n");
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (choice != 0);

    return 0;
}