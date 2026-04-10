#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Structure for graph
struct Graph {
    int V;
    struct Node* adj[MAX];
};

// Min Heap Node
struct MinHeapNode {
    int vertex;
    int dist;
};

// Min Heap
struct MinHeap {
    int size;
    struct MinHeapNode heap[MAX];
};

// Function to create new node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

// Swap heap nodes
void swap(struct MinHeapNode* a, struct MinHeapNode* b) {
    struct MinHeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify
void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
        smallest = left;

    if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

// Extract min
struct MinHeapNode extractMin(struct MinHeap* h) {
    struct MinHeapNode root = h->heap[0];
    h->heap[0] = h->heap[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

// Decrease key
void decreaseKey(struct MinHeap* h, int v, int dist) {
    for (int i = 0; i < h->size; i++) {
        if (h->heap[i].vertex == v) {
            h->heap[i].dist = dist;
            while (i && h->heap[i].dist < h->heap[(i - 1) / 2].dist) {
                swap(&h->heap[i], &h->heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
            break;
        }
    }
}

// Check if empty
int isEmpty(struct MinHeap* h) {
    return h->size == 0;
}

// Dijkstra function
void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[MAX];

    struct MinHeap* h = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    h->size = V;

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        h->heap[i].vertex = i;
        h->heap[i].dist = INT_MAX;
    }

    dist[src] = 0;
    h->heap[src].dist = 0;

    // Build heap
    for (int i = (V - 1) / 2; i >= 0; i--)
        heapify(h, i);

    while (!isEmpty(h)) {
        struct MinHeapNode minNode = extractMin(h);
        int u = minNode.vertex;

        struct Node* temp = graph->adj[u];
        while (temp != NULL) {
            int v = temp->vertex;

            if (dist[u] != INT_MAX && dist[u] + temp->weight < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                decreaseKey(h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

// Main function
int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Graph* graph = createGraph(V);

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(graph, u, v, w); // directed
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
