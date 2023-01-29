#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100
#define UNDEFINED -1

int n, m, start;
int graph[MAX][MAX];
int dist[MAX];
int parent[MAX];
bool used[MAX];

void dijkstra(int start) 
{
    for (int i = 0; i < n; i++) 
    {
        dist[i] = INT_MAX;
        parent[i] = UNDEFINED;
        used[i] = false;
    }
    dist[start] = 0;
    for (int i = 0; i < n; i++) 
    {
        int v = UNDEFINED;
        for (int j = 0; j < n; j++) 
        {
            if (!used[j] && (v == UNDEFINED || dist[j] < dist[v])) 
            {
                v = j;
            }
        }
        if (dist[v] == INT_MAX) break;
        used[v] = true;
        for (int u = 0; u < n; u++) 
        {
            if (graph[v][u] != 0 && dist[v] + graph[v][u] < dist[u]) 
            {
                dist[u] = dist[v] + graph[v][u];
                parent[u] = v;
            }
        }
    }
}

void printPath(int u) 
{
    if (parent[u] == UNDEFINED) 
    {
        printf("%d ", u);
        return;
    }
    printPath(parent[u]);
    printf("%d ", u);
}

int main() 
{
    printf("Podaj liczbę wierzchołków, liczbę krawędzi i wierzchołek startowy.\n");
    scanf("%d %d %d", &n, &m, &start);
    printf("Podaj numer wierzchołka początkowego, numer wierzchołka końcowego i wagę połączenia pomiędzy tymi wierzchołkami.\n");
    for (int i = 0; i < m; i++) 
    {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph[a][b] = w;
    }
    dijkstra(start);
    for (int i = 0; i < n; i++) 
    {
        if (i == start) continue;
        printf("Najkrótsza ścieżka od %d do %d to: ", start, i);
        printPath(i);
        printf("\n");
    }
    return 0;
}