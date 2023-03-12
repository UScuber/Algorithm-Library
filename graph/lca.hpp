#include "template.hpp"

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
    const int n = G.size();
    dep.assign(n, -1);
    parent.assign(1, vector<int>(n, -1));
    queue<int> que({ root });
    dep[root] = 0;
    int max_dep = 0;
    while(!que.empty()){
      const int pos = que.front();
      que.pop();
      max_dep = max(max_dep, dep[pos]);
      for(const auto &x : G[pos]){
        if(dep[x] == -1){
          dep[x] = dep[pos] + 1;
          parent[0][x] = pos;
          que.push(x);
        }
      }
    }
    while((1 << log) <= max_dep) log++;
    parent.resize(log, vector<int>(n, -1));
    for(int k = 0; k < log - 1; k++){
      for(int v = 0; v < n; v++){
        if(parent[k][v] < 0) parent[k + 1][v] = -1;
        else parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
  int query(int u, int v) const{
    if(dep[u] < dep[v]) swap(u, v);
    const int sub = dep[u] - dep[v];
    for(int k = 0; k < log; k++){
      if(!(sub >> k)) break;
      if(sub >> k & 1) u = parent[k][u];
    }
    if(u == v) return u;
    for(int k = __lg(dep[u]); k >= 0; k--){
      if(parent[k][u] != parent[k][v]){
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
  int dist(const int u, const int v) const{
    return dep[u] + dep[v] - dep[query(u, v)] * 2;
  }
  int jump(int u, int v, const int d) const{
    const int lc = query(u, v);
    const int l = dep[u] - dep[lc];
    const int r = dep[v] - dep[lc];
    assert(0 <= d && d <= l + r);
    if(l < d){
      d = l + r - d;
      swap(u, v);
    }
    for(int k = 0; k < log; k++){
      if(!(d >> k)) break;
      if(d >> k & 1) u = parent[k][u];
    }
    return u;
  }
};