#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int n;

// Queue implementation
int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1)
        return -1;
    int x = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return x;
}

int isEmpty() {
    return front == -1;
}

void topologicalSort() {
    int i, j;
    
    // Step 1: Initialize indegree array
    for (i = 0; i < n; i++)
        indegree[i] = 0;

    // Step 2: Calculate indegree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Step 3: Enqueue all vertices with indegree 0
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;
    int topo[MAX];

    // Step 4: Process queue
    while (!isEmpty()) {
        int u = dequeue();
        topo[count++] = u;

        for (i = 0; i < n; i++) {
            if (adj[u][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Step 5: Check for cycle
    if (count != n) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    // Print result
    printf("Topological Order:\n");
    for (i = 0; i < n; i++)
        printf("%d ", topo[i]);
    printf("\n");
}

int main() {
    int i, j, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v) for directed graph:\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topologicalSort();

    return 0;
}
