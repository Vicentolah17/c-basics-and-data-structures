#include <stdio.h>

#define MAX 10

typedef struct {
    int pid;
    int chegada;
    int duracao;
    int prioridade;
    int restante;
    int fim;
    int executado;
} Processo;

int main() {
    int n, tempo = 0, concluidos = 0, i;
    Processo processos[MAX];

    printf("Quantos processos? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        processos[i].pid = i + 1;
        printf("Processo %d - Tempo de chegada: ", processos[i].pid);
        scanf("%d", &processos[i].chegada);
        printf("Processo %d - Tempo de duracao: ", processos[i].pid);
        scanf("%d", &processos[i].duracao);
        printf("Processo %d - Prioridade (menor valor = maior prioridade): ", processos[i].pid);
        scanf("%d", &processos[i].prioridade);
        processos[i].restante = processos[i].duracao;
        processos[i].executado = 0;
        processos[i].fim = -1;
    }

    printf("\n--- Escalonamento por Prioridade Preemptivo ---\n");

    int atual = -1; 

    while (concluidos < n) {
        int melhor = -1;
        for(i = 0; i < n; i++)
            if (!processos[i].executado && processos[i].chegada <= tempo && processos[i].restante > 0)
                if (melhor == -1 || processos[i].prioridade < processos[melhor].prioridade)
                    melhor = i;

        if (melhor == -1) { 
            tempo++;
            continue;
        }

        if (atual != melhor) {
            printf("Tempo %d: Processo %d (prioridade %d) assume a CPU\n", tempo, processos[melhor].pid, processos[melhor].prioridade);
            atual = melhor;
        }

        processos[melhor].restante--;
        tempo++;

        if (processos[melhor].restante == 0) {
            processos[melhor].fim = tempo;
            processos[melhor].executado = 1;
            concluidos++;
            printf("Processo %d terminou no tempo %d\n", processos[melhor].pid, tempo);
            atual = -1;
        }
    }

    printf("\nTempos de finalizacao:\n");
    for(i = 0; i < n; i++)
        printf("Processo %d: Fim = %d\n", processos[i].pid, processos[i].fim);

    return 0;
}
