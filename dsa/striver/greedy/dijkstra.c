// C program to implement Dijkstra's Shortest Path Algorithm

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10
#define INF 9999

int minDistance(int dist[], bool visited[], int n) {
    int min = INF, min_index;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void printSolution(int dist[], int parent[], int n, int src) {
    printf("\nVertex\t Distance\tPath");
    for (int i = 0; i < n; i++) {
        if (i != src) {
            printf("\n%d -> %d \t %d\t\t%d", src, i, dist[i], src);
            printPath(parent, i);
        }
    }
    printf("\n");
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    bool visited[MAX];
    int parent[MAX];
    
    // Initialize distances and visited array
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;
        
        // Update distance of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF && 
                dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    
    printSolution(dist, parent, n, src);
}

int main() {
    int n, src;
    int graph[MAX][MAX];
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("\nEnter the adjacency matrix:\n");
    printf("(Enter %d for no direct edge, 0 for self-loop)\n", INF);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Edge [%d][%d]: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("\nEnter source vertex: ");
    scanf("%d", &src);
    
    if (src < 0 || src >= n) {
        printf("Invalid source vertex!\n");
        return 1;
    }
    
    printf("\nDijkstra's Shortest Path Algorithm\n");
    printf("===================================\n");
    dijkstra(graph, n, src);
    
    return 0;
}
