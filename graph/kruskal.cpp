#include <bits/stdc++.h>
#include "template.hpp"
#include "unionfind.hpp"
using namespace std;
using ll = long long;

template <class T>
ll kruskal(vector<Edge<T>> &es, const int n){
  ll res = 0;
  sort(es.begin(), es.end());
  UnionFind tree(n);
  for(const auto &e : es){
    if(!tree.same(e.from, e.to)){
      tree.unite(e.from, e.to);
      res += e.cost;
    }
  }
  return res;
}