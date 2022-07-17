#include <bits/stdc++.h>
using namespace std;

template <class graph>
struct lca {
  const graph &G;
  vector<vector<int>> parent;
  vector<int> dep;
  int log = 1;
  lca(const graph &G, int root = 0) : G(G){
    init(root);
  }
  void init(int root = 0){
    const int V = G.size();
    while((1 << log) < V) log++;
    parent.assign(log, vector<int>(V, -1));
    dep.assign(V, -1);
    dfs(root, -1, 0);
    for(int k = 0; k + 1 < log; k++){
      for(int v = 0; v < V; v++){
        if(parent[k][v] < 0) parent[k + 1][v] = -1;
        else parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
  void dfs(int v, int p, int d){
    parent[0][v] = p;
    dep[v] = d;
    for(auto &e : G[v]){
      if(e != p) dfs(e, v, d + 1);
    }
  }
  int query(int u, int v) const{
    if(dep[u] < dep[v]) swap(u, v);
    for(int k = 0; k < log; k++){
      if((dep[u] - dep[v]) >> k & 1) u = parent[k][u];
    }
    if(u == v) return u;
    for(int k = log - 1; k >= 0; k--){
      if(parent[k][u] != parent[k][v]){
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
  int dist(int u, int v) const{
    return dep[u] + dep[v] - dep[query(u, v)] * 2;
  }
  int jump(int u, int v, int d) const{
    const int lc = query(u, v);
    const int l = dep[u] - dep[lc];
    const int r = dep[v] - dep[lc];
    assert(0 <= d && d <= l + r);
    if(l < d){
      d = l + r - d;
      swap(u, v);
    }
    for(int k = 0; k < log; k++){
      if(d >> k & 1) u = parent[k][u];
    }
    return u;
  }
};