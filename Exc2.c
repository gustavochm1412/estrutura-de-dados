#include <stdio.h>
#include <stdlib.h>

struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

struct AdjList {
    struct AdjListNode *head;  
};

struct Graph {
    int V;                   
    struct AdjList* array;   
};

struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void removeEdge(struct Graph* graph, int src, int dest) {
    
    if (src < 0 || src >= graph->V || dest < 0 || dest >= graph->V) {
        printf("Erro: Vértices fornecidos estão fora do limite válido.\n");
        return;
    }

    struct AdjListNode *prev, *curr;
    prev = NULL;
    curr = graph->array[src].head;

    while (curr != NULL && curr->dest != dest) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Erro: Aresta de %d para %d não encontrada.\n", src, dest);
        return;
    }

    if (prev == NULL)
        graph->array[src].head = curr->next;
    else
        prev->next = curr->next;

    free(curr);

    prev = NULL;
    curr = graph->array[dest].head;

    while (curr != NULL && curr->dest != src) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Erro: Aresta de %d para %d não encontrada.\n", dest, src);
        return;
    }

    if (prev == NULL)
        graph->array[dest].head = curr->next;
    else
        prev->next = curr->next;

    free(curr);

    printf("Aresta entre %d e %d removida com sucesso.\n", src, dest);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    removeEdge(graph, 1, 3);

    printf("Lista de adjacências do grafo após remoção:\n");
    for (int v = 0; v < V; ++v) {
        struct AdjListNode* temp = graph->array[v].head;
        printf("Lista de adjacências do vértice %d: ", v);
        while (temp) {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    return 0;
}
