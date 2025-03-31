#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_TIME 100

// Estrutura para representar um processo
typedef struct
{
    int id;              // ID do processo
    int arrival_time;    // Tempo de chegada
    int burst_time;      // Tempo de execução total
    int remaining_time;  // Tempo restante (para SRTF)
    int waiting_time;    // Tempo de espera
    int turnaround_time; // Tempo de retorno
    int completion_time; // Tempo de conclusão
} Process;

// Estrutura para representar o diagrama de Gantt
typedef struct
{
    int process_id; // ID do processo em execução no tempo t
    int time;       // Tempo atual
} GanttChart;

// Função para ordenar processos por tempo de chegada
void sort_by_arrival_time(Process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
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

// Função auxiliar para encontrar o índice do processo com menor tempo de execução
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

// Algoritmo FIFO (First In, First Out)
void fifo_scheduling(Process processes[], int n, GanttChart chart[], int *chart_size)
{
    // Ordenar processos por tempo de chegada
    sort_by_arrival_time(processes, n);

    int current_time = 0;
    *chart_size = 0;

    for (int i = 0; i < n; i++)
    {
        // Se o tempo atual for menor que o tempo de chegada do processo, avançar o tempo
        if (current_time < processes[i].arrival_time)
        {
            current_time = processes[i].arrival_time;
        }

        // Registrar o início da execução no diagrama de Gantt
        chart[*chart_size].process_id = processes[i].id;
        chart[*chart_size].time = current_time;
        (*chart_size)++;

        // Atualizar o tempo atual após executar o processo
        current_time += processes[i].burst_time;

        // Calcular métricas para este processo
        processes[i].completion_time = current_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    // Adicionar o ponto final do diagrama de Gantt
    chart[*chart_size].process_id = -1;
    chart[*chart_size].time = current_time;
    (*chart_size)++;
}

// Algoritmo SJF (Shortest Job First) - Não preemptivo
void sjf_scheduling(Process processes[], int n, GanttChart chart[], int *chart_size)
{
    // Inicializar remaining_time com burst_time
    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
    }

    int current_time = 0;
    int completed = 0;
    *chart_size = 0;
    int prev_process = -1;

    // Encontrar o primeiro tempo de chegada mínimo
    int min_arrival = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrival_time < min_arrival)
        {
            min_arrival = processes[i].arrival_time;
        }
    }
    current_time = min_arrival;

    while (completed < n)
    {
        int shortest_job = -1;
        int min_burst = INT_MAX;

        // Encontrar o próximo processo com menor tempo de execução
        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0)
            {
                if (processes[i].burst_time < min_burst)
                {
                    min_burst = processes[i].burst_time;
                    shortest_job = i;
                }
            }
        }

        // Se não encontrou um processo elegível, avance o tempo
        if (shortest_job == -1)
        {
            current_time++;
            continue;
        }

        // Se é um novo processo, adiciona ao diagrama de Gantt
        if (prev_process != processes[shortest_job].id)
        {
            chart[*chart_size].process_id = processes[shortest_job].id;
            chart[*chart_size].time = current_time;
            (*chart_size)++;
            prev_process = processes[shortest_job].id;
        }

        // Execute o processo até o fim
        current_time += processes[shortest_job].burst_time;
        processes[shortest_job].remaining_time = 0;
        completed++;

        // Calcular métricas para este processo
        processes[shortest_job].completion_time = current_time;
        processes[shortest_job].turnaround_time = processes[shortest_job].completion_time - processes[shortest_job].arrival_time;
        processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - processes[shortest_job].burst_time;
    }

    // Adicionar o ponto final do diagrama de Gantt
    chart[*chart_size].process_id = -1;
    chart[*chart_size].time = current_time;
    (*chart_size)++;
}

// Algoritmo SRTF (Shortest Remaining Time First) - SJF preemptivo
void srtf_scheduling(Process processes[], int n, GanttChart chart[], int *chart_size)
{
    // Inicializar remaining_time com burst_time
    for (int i = 0; i < n; i++)
    {
        processes[i].remaining_time = processes[i].burst_time;
    }

    int current_time = 0;
    int completed = 0;
    *chart_size = 0;
    int prev_process = -1;

    // Encontrar o primeiro tempo de chegada mínimo
    int min_arrival = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrival_time < min_arrival)
        {
            min_arrival = processes[i].arrival_time;
        }
    }
    current_time = min_arrival;

    while (completed < n)
    {
        int shortest_job = find_shortest_job(processes, n, current_time);

        // Se não encontrou um processo elegível, avance o tempo
        if (shortest_job == -1)
        {
            current_time++;
            continue;
        }

        // Se é um novo processo (ou retomada após preempção), adiciona ao diagrama de Gantt
        if (prev_process != processes[shortest_job].id)
        {
            chart[*chart_size].process_id = processes[shortest_job].id;
            chart[*chart_size].time = current_time;
            (*chart_size)++;
            prev_process = processes[shortest_job].id;
        }

        // Executar o processo por uma unidade de tempo
        processes[shortest_job].remaining_time--;
        current_time++;

        // Verificar se o processo terminou
        if (processes[shortest_job].remaining_time == 0)
        {
            completed++;

            // Calcular métricas para este processo
            processes[shortest_job].completion_time = current_time;
            processes[shortest_job].turnaround_time = processes[shortest_job].completion_time - processes[shortest_job].arrival_time;
            processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - processes[shortest_job].burst_time;
        }
    }

    // Adicionar o ponto final do diagrama de Gantt
    chart[*chart_size].process_id = -1;
    chart[*chart_size].time = current_time;
    (*chart_size)++;
}

// Função para desenhar o diagrama de Gantt no terminal
void draw_gantt_chart(GanttChart chart[], int size)
{
    printf("\nDiagrama de Gantt:\n\n");

    // Desenhar a linha superior
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

    // Desenhar os IDs dos processos
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

// Função para calcular e exibir métricas
void display_metrics(Process processes[], int n)
{
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    printf("\nMétricas dos processos:\n");
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
    GanttChart chart[MAX_TIME * 2]; // Espaço suficiente para todos os pontos do Gantt
    int chart_size = 0;
    int n, choice;

    printf("Simulador de Algoritmos de Escalonamento de Processos\n");
    printf("----------------------------------------------------\n\n");

    // Entrada de dados: número de processos
    printf("Digite o número de processos (máximo %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESSES)
    {
        printf("Número de processos inválido!\n");
        return 1;
    }

    // Entrada de dados: detalhes de cada processo
    printf("\nDigite os detalhes de cada processo:\n");
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("\nProcesso P%d:\n", processes[i].id);
        printf("Tempo de chegada: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Tempo de execução: ");
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
        // Menu de seleção do algoritmo
        printf("\nEscolha o algoritmo de escalonamento:\n");
        printf("1. FIFO (First In, First Out)\n");
        printf("2. SJF (Shortest Job First) - Não preemptivo\n");
        printf("3. SRTF (Shortest Remaining Time First) - SJF preemptivo\n");
        printf("0. Sair\n");
        printf("Sua escolha: ");
        scanf("%d", &choice);

        // Criar cópias dos processos para preservar os dados originais
        Process temp_processes[MAX_PROCESSES];
        for (int i = 0; i < n; i++)
        {
            temp_processes[i] = processes[i];
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
            printf("\nExecutando algoritmo SJF (não preemptivo)...\n");
            sjf_scheduling(temp_processes, n, chart, &chart_size);
            draw_gantt_chart(chart, chart_size);
            display_metrics(temp_processes, n);
            break;

        case 3:
            printf("\nExecutando algoritmo SRTF (SJF preemptivo)...\n");
            srtf_scheduling(temp_processes, n, chart, &chart_size);
            draw_gantt_chart(chart, chart_size);
            display_metrics(temp_processes, n);
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
