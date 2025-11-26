#include <iostream>
using namespace std;

void dfsUtil(int u, int adj[10][10], bool visited[], int V) {
  visited[u] = true;
  cout << u << " ";

  for (int v = 0; v < V; v++) {
    if (adj[u][v] == 1 && !visited[v]) {
      dfsUtil(v, adj, visited, V);
    }
  }
}

void dfs(int start, int adj[10][10], int V) {
  bool visited[10] = {false};
  cout << "DFS Traversal: ";
  dfsUtil(start, adj, visited, V);
  cout << endl;
}

int main() {
  int V = 5;
  int adj[10][10] = {0};

  adj[0][1] = 1;
  adj[1][0] = 1;
  adj[0][2] = 1;
  adj[2][0] = 1;
  adj[1][3] = 1;
  adj[3][1] = 1;
  adj[1][4] = 1;
  adj[4][1] = 1;

  dfs(0, adj, V);

  return 0;
}
