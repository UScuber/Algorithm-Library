#include <bits/stdc++.h>
#include "unionfind.hpp"
#include "template.hpp"
using namespace std;

template <class T>
bool is_bipartite(const Graph<T> &g){
  const int n = g.size();
  UnionFind tree(n * 2);
  for(int i = 0; i < n; i++) for(auto &x : g[i]){
    tree.unite(x.from, x.to+n);
    tree.unite(x.from+n, x.to);
  }
  for(int i = 0; i < n; i++) for(auto &x : g[i]){
    if(tree.same(x.from, x.to+n)) return false;
  }
  return true;
}