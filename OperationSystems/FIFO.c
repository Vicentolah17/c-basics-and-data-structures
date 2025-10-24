#include <stdio.h>

#define MAX 10

typedef struct {
    int pid;    // identificador 
    int chegada;       
    int tempExecucao;       
    int inicio;        
    int fim;          
} Processo;

int main() {
    int n, tempo = 0;
    Processo fila[MAX];

    printf("Quantos processos? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        fila[i].pid = i + 1;
        printf("Processo %d - Tempo de chegada: ", fila[i].pid);
        scanf("%d", &fila[i].chegada);
        printf("Processo %d - Tempo de duracao: ", fila[i].pid);
        scanf("%d", &fila[i].tempExecucao);
    }

    printf("\n--- Escalonamento FIFO ---\n");
    for(int i = 0; i < n; i++) {
        if (tempo < fila[i].chegada)
            tempo = fila[i].chegada; 

        fila[i].inicio = tempo;
        fila[i].fim = tempo + fila[i].tempExecucao;
        tempo = fila[i].fim;

        printf("Processo %d: Inicio = %d, Fim = %d\n", fila[i].pid, fila[i].inicio, fila[i].fim);
    }

    return 0;
}
