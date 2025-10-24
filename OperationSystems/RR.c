#include <stdio.h>
#define MAX 10

typedef struct {
    int pid;
    int chegada;
    int duracao;
    int restante;
    int fim;
    int executado;
} Processo;

int main() {
    int n, quantum, tempo = 0, concluidos = 0, i;
    Processo processos[MAX];

    printf("Quantos processos? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        processos[i].pid = i + 1;
        printf("Processo %d - Tempo de chegada: ", processos[i].pid);
        scanf("%d", &processos[i].chegada);
        printf("Processo %d - Tempo de duracao: ", processos[i].pid);
        scanf("%d", &processos[i].duracao);
        processos[i].restante = processos[i].duracao;
        processos[i].executado = 0;
        processos[i].fim = -1;
    }

    printf("Quantum: ");
    scanf("%d", &quantum);

    printf("\n--- Escalonamento Round Robin ---\n");
    int todosChegaram = 0;
    int fila[MAX], front = 0, rear = 0;
    int emFila[MAX] = {0};

    //add processos tempo 0
    for(i = 0; i < n; i++)
        if (processos[i].chegada <= tempo) {
            fila[rear++] = i;
            emFila[i] = 1;
        }

    while (concluidos < n) {
        if (front == rear) { //  vazia
            tempo++;
            for(i = 0; i < n; i++)
                if (!processos[i].executado && !emFila[i] && processos[i].chegada <= tempo) {
                    fila[rear++] = i;
                    emFila[i] = 1;
                }
            continue;
        }
        int idx = fila[front++];
        if (processos[idx].executado) continue;

        
        int exec = (processos[idx].restante < quantum) ? processos[idx].restante : quantum;
        printf("Processo %d executa de %d ate %d\n", processos[idx].pid, tempo, tempo+exec);
        tempo += exec;
        processos[idx].restante -= exec;

        // checa processos
        for(i = 0; i < n; i++)
            if (!processos[i].executado && !emFila[i] && processos[i].chegada <= tempo) {
                fila[rear++] = i;
                emFila[i] = 1;
            }

        if (processos[idx].restante == 0) {
            processos[idx].fim = tempo;
            processos[idx].executado = 1;
            concluidos++;
        } else {
            fila[rear++] = idx; // final da fila
        }
    }

    printf("\nTempos de finalizacao:\n");
    for(i = 0; i < n; i++) {
        printf("Processo %d: Fim = %d\n", processos[i].pid, processos[i].fim);
    }

    return 0;
}
