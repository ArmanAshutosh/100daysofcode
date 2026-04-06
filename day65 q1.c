#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS function with parent tracking
int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {  // if edge exists
            if (!visited[i]) {
                if (dfs(i, node))
                    return 1;
            }
            else if (i != parent) {
                // visited and not parent → cycle found
                return 1;
            }
        }
    }
    return 0;
}

int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int m, u, v;

    scanf("%d", &n);   // number of vertices
    scanf("%d", &m);   // number of edges

    // initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
