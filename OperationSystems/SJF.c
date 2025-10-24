#include <stdio.h>

#define MAX 10

typedef struct {
    int pid;
    int chegada;
    int duracao;
    int inicio;
    int fim;
    int executado;
} Processo;

int main() {
    int n, tempo = 0, concluidos = 0, menor, i, idx;
    Processo processos[MAX];

    printf("Quantos processos? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        processos[i].pid = i + 1;
        printf("Processo %d - Tempo de chegada: ", processos[i].pid);
        scanf("%d", &processos[i].chegada);
        printf("Processo %d - Tempo de duracao: ", processos[i].pid);
        scanf("%d", &processos[i].duracao);
        processos[i].executado = 0;
    }

    printf("\n--- Escalonamento SJF ---\n");
    while (concluidos < n) {
        menor = 99999;
        idx = -1;
        for (i = 0; i < n; i++) {
            if (!processos[i].executado && processos[i].chegada <= tempo && processos[i].duracao < menor) {
                menor = processos[i].duracao;
                idx = i;
            }
        }
        if (idx == -1) {
            tempo++; // CPU ociosa, avança tempo
            continue;
        }
        processos[idx].inicio = tempo;
        processos[idx].fim = tempo + processos[idx].duracao;
        tempo = processos[idx].fim;
        processos[idx].executado = 1;
        concluidos++;
        printf("Processo %d: Inicio = %d, Fim = %d\n", processos[idx].pid, processos[idx].inicio, processos[idx].fim);
    }

    return 0;
}
