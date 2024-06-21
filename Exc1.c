#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES]; 
int numNodes;                    

void insertEdge(int node1, int node2, int weight) {
    
    if (node1 < 0 || node1 >= numNodes || node2 < 0 || node2 >= numNodes) {
        printf("Erro: Nós fornecidos estão fora do limite válido.\n");
        return;
    }
    
    graph[node1][node2] = weight;
    graph[node2][node1] = weight; 

    printf("Nova rua inserida entre %d e %d com peso %d.\n", node1, node2, weight);
}

int main() {
    int i, j;

    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            graph[i][j] = 0;
        }
    }

    numNodes = 5; 

    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][2] = 2;
    graph[2][1] = 2;
    graph[2][3] = 3;
    graph[3][2] = 3;
    graph[3][4] = 4;
    graph[4][3] = 4;

    printf("Matriz de adjacências inicial:\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    insertEdge(1, 3, 5);

    printf("\nMatriz de adjacências após inserção:\n");
    for (i = 0; i < numNodes; i++) {
        for (j = 0; j < numNodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
