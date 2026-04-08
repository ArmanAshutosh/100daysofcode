#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Graph
struct Node* adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void DFS(int v) {
    visited[v] = 1;

    struct Node* temp = adj[v;
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }

    // Push after visiting all neighbors
    push(v);
}

// Topological Sort
void topologicalSort(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    // Print stack (reverse order)
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    int n, m, u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Topological Ordering:\n");
    topologicalSort(n);

    return 0;
}
