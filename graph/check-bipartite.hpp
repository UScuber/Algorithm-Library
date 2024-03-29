#include "template.hpp"
#include "UnionFind.hpp"

template <class T>
bool is_bipartite(const Graph<T> &g){
  const int n = g.size();
  UnionFind tree(n * 2);
  for(int i = 0; i < n; i++) for(const auto &x : g[i]){
    tree.unite(x.from, x.to+n);
    tree.unite(x.from+n, x.to);
  }
  for(int i = 0; i < n; i++) for(const auto &x : g[i]){
    if(tree.same(x.from, x.to+n)) return false;
  }
  return true;
}