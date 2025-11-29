#include <iostream>
using namespace std;

const int INF = 99999;
const int N = 7;

int graph[N][N];

int minDist(int dist[], bool visited[]) {
    int min = INF, idx = -1;
    for (int i = 1; i < N; i++)
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            idx = i;
        }
    return idx;
}

void dijkstra(int src) {
    int dist[N];
    bool visited[N] = { false };

    for (int i = 1; i < N; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int count = 1; count < N; count++) {
        int u = minDist(dist, visited);
        visited[u] = true;

        for (int v = 1; v < N; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    cout << "Shortest distance B to E = " << dist[5] << endl;
}

int main() {

    graph[2][1] = graph[1][2] = 4;   // B-A
    graph[2][3] = graph[3][2] = 9;   // B-C
    graph[3][4] = graph[4][3] = 6;   // C-D
    graph[3][5] = graph[5][3] = 14;  // C-E
    graph[5][6] = graph[6][5] = 3;   // E-F
    graph[6][4] = graph[4][6] = 4;   // F-D
    graph[1][4] = graph[4][1] = 8;   // A-D

    dijkstra(2); // Start B (node 2)
    return 0;
}
