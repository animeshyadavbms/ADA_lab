#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices

int minKey(int key[], int visited[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    int totalCost = 0;
    printf("Edge \tWeight\n");

    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("Total cost of MST = %d\n", totalCost);
}

void primMST(int graph[V][V]) {
    int parent[V]; // Stores MST
    int key[V]; // Minimum weights
    int visited[V]; // Visited vertices

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0; // Start from vertex 0
    parent[0] = -1; // Root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    primMST(graph);
    return 0;
}
