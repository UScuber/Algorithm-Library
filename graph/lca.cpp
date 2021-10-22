#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct lca {
  using graph = vector<vector<int>>;
  vector<vector<int>> parent; //parent[k][u]:= u の 2^k 先の親
  vector<int> dist; //root からの距離
  lca(const graph &G, int root = 0){
    init(G, root);
  }
  void init(const graph &G, int root = 0){
    int V = G.size();
    int K = 1;
    while ((1 << K) < V) K++;
    parent.assign(K, vector<int>(V, -1));
    dist.assign(V, -1);
    dfs(G, root, -1, 0);
    for (int k = 0; k + 1 < K; k++) {
      for (int v = 0; v < V; v++) {
        if (parent[k][v] < 0) {
          parent[k + 1][v] = -1;
        }else{
          parent[k + 1][v] = parent[k][parent[k][v]];
        }
      }
    }
  }
  //根からの距離と1つ先の頂点を求める
  void dfs(const graph &G, int v, int p, int d) {
    parent[0][v] = p;
    dist[v] = d;
    for (auto e : G[v]) {
      if (e != p) dfs(G, e, v, d + 1);
    }
  }
  int query(int u, int v) {
    if (dist[u] < dist[v]) swap(u, v);  //u の方が深いとする
    int K = parent.size();
    //LCA までの距離を同じにする
    for (int k = 0; k < K; k++) {
      if ((dist[u] - dist[v]) >> k & 1) {
        u = parent[k][u];
      }
    }
    //二分探索で LCA を求める
    if (u == v) return u;
    for (int k = K - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};