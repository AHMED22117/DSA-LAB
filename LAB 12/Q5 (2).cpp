#include <iostream>
using namespace std;

const int N = 6;

int adjMatrix[N][N];
int adjList[N][N]; 
int adjCount[N];

bool visited[N];

void addEdge(int u, int v) {
    adjMatrix[u][v] = adjMatrix[v][u] = 1;

    adjList[u][adjCount[u]++] = v;
    adjList[v][adjCount[v]++] = u;
}

void BFS(int start) {
    bool vis[N] = { false };
    int q[50], front = 0, rear = 0;

    q[rear++] = start;
    vis[start] = true;

    while (front < rear) {
        int u = q[front++];
        cout << u << " ";

        for (int i = 0; i < adjCount[u]; i++) {
            int v = adjList[u][i];
            if (!vis[v]) {
                vis[v] = true;
                q[rear++] = v;
            }
        }
    }
}

void DFSRec(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adjCount[u]; i++) {
        int v = adjList[u][i];
        if (!visited[v])
            DFSRec(v);
    }
}

int main() {
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(2, 5);
    addEdge(3, 5);
    addEdge(4, 5);

    cout << "Adjacency Matrix:\n";
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }

    cout << "\nAdjacency List:\n";
    for (int i = 1; i <= 5; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjCount[i]; j++)
            cout << adjList[i][j] << " ";
        cout << endl;
    }

    cout << "\nBFS from 1: ";
    BFS(1);

    cout << "\nDFS from 1: ";
    for (int i = 0; i < N; i++) visited[i] = false;
    DFSRec(1);

    return 0;
}
