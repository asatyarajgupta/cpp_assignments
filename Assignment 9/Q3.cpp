#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

// For Kruskal's
struct Edge {
  int u, v, w;
};

bool compareEdges(Edge a, Edge b) { return a.w < b.w; }

struct DSU {
  int parent[100];
  DSU(int n) {
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }
  int find(int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent[i]);
  }
  void unite(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j)
      parent[root_i] = root_j;
  }
};

void kruskal(Edge edges[], int E, int V) {
  sort(edges, edges + E, compareEdges);
  DSU dsu(V);
  int mst_weight = 0;
  cout << "Kruskal's MST Edges:" << endl;
  for (int i = 0; i < E; i++) {
    int u = edges[i].u;
    int v = edges[i].v;
    int w = edges[i].w;
    if (dsu.find(u) != dsu.find(v)) {
      dsu.unite(u, v);
      mst_weight += w;
      cout << u << " - " << v << " : " << w << endl;
    }
  }
  cout << "Total Weight: " << mst_weight << endl;
}

// For Prim's
void prim(int adj[10][10], int V) {
  int parent[10];
  int key[10];
  bool mstSet[10];

  for (int i = 0; i < V; i++) {
    key[i] = INT_MAX;
    mstSet[i] = false;
  }

  key[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < V - 1; count++) {
    int min = INT_MAX, u;
    for (int v = 0; v < V; v++)
      if (mstSet[v] == false && key[v] < min)
        min = key[v], u = v;

    mstSet[u] = true;

    for (int v = 0; v < V; v++) {
      if (adj[u][v] && mstSet[v] == false && adj[u][v] < key[v])
        parent[v] = u, key[v] = adj[u][v];
    }
  }

  cout << "\nPrim's MST Edges:" << endl;
  int total_weight = 0;
  for (int i = 1; i < V; i++) {
    cout << parent[i] << " - " << i << " : " << key[i] << endl;
    total_weight += key[i];
  }
  cout << "Total Weight: " << total_weight << endl;
}

int main() {
  int V = 4;
  Edge edges[5];
  // 0-1: 10, 0-2: 6, 0-3: 5, 1-3: 15, 2-3: 4
  edges[0] = (Edge){0, 1, 10};
  edges[1] = (Edge){0, 2, 6};
  edges[2] = (Edge){0, 3, 5};
  edges[3] = (Edge){1, 3, 15};
  edges[4] = (Edge){2, 3, 4};

  kruskal(edges, 5, V);

  int adj[10][10] = {0};
  adj[0][1] = 10;
  adj[1][0] = 10;
  adj[0][2] = 6;
  adj[2][0] = 6;
  adj[0][3] = 5;
  adj[3][0] = 5;
  adj[1][3] = 15;
  adj[3][1] = 15;
  adj[2][3] = 4;
  adj[3][2] = 4;

  prim(adj, V);

  return 0;
}
