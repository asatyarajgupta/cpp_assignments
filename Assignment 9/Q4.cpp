#include <climits>
#include <iostream>
using namespace std;

int minDistance(int dist[], bool sptSet[], int V) {
  int min = INT_MAX, min_index;
  for (int v = 0; v < V; v++)
    if (sptSet[v] == false && dist[v] <= min)
      min = dist[v], min_index = v;
  return min_index;
}

void dijkstra(int adj[10][10], int V, int src) {
  int dist[10];
  bool sptSet[10];

  for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;

  dist[src] = 0;

  for (int count = 0; count < V - 1; count++) {
    int u = minDistance(dist, sptSet, V);
    sptSet[u] = true;

    for (int v = 0; v < V; v++)
      if (!sptSet[v] && adj[u][v] && dist[u] != INT_MAX &&
          dist[u] + adj[u][v] < dist[v])
        dist[v] = dist[u] + adj[u][v];
  }

  cout << "Vertex Distance from Source " << src << endl;
  for (int i = 0; i < V; i++)
    cout << i << "\t\t" << dist[i] << endl;
}

int main() {
  int V = 5;
  int adj[10][10] = {0};

  // 0-1 (9), 0-2 (6), 0-3 (5), 0-4 (3)
  // 2-1 (2), 2-3 (4)
  adj[0][1] = 9;
  adj[1][0] = 9;
  adj[0][2] = 6;
  adj[2][0] = 6;
  adj[0][3] = 5;
  adj[3][0] = 5;
  adj[0][4] = 3;
  adj[4][0] = 3;

  adj[2][1] = 2;
  adj[1][2] = 2;
  adj[2][3] = 4;
  adj[3][2] = 4;

  dijkstra(adj, V, 0);

  return 0;
}
