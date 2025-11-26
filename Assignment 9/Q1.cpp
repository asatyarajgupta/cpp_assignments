#include <iostream>
#include <queue>
using namespace std;

void bfs(int start, int adj[10][10], int V) {
  bool visited[10] = {false};
  queue<int> q;

  visited[start] = true;
  q.push(start);

  cout << "BFS Traversal: ";
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cout << u << " ";

    for (int v = 0; v < V; v++) {
      if (adj[u][v] == 1 && !visited[v]) {
        visited[v] = true;
        q.push(v);
      }
    }
  }
  cout << endl;
}

int main() {
  int V = 5;
  int adj[10][10] = {0};

  // Edges: 0-1, 0-2, 1-3, 1-4, 2-0, 3-1, 4-1
  adj[0][1] = 1;
  adj[1][0] = 1;
  adj[0][2] = 1;
  adj[2][0] = 1;
  adj[1][3] = 1;
  adj[3][1] = 1;
  adj[1][4] = 1;
  adj[4][1] = 1;

  bfs(0, adj, V);

  return 0;
}
