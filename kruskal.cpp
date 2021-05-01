#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct edge{
  int u, v;
  ll cost;
  bool friend operator<(const edge &e1, const edge &e2){
    return e1.cost < e2.cost;
  }
};
struct UnionFind {
  vector<int> d;
  UnionFind(int n) : d(n, -1){}
  int root(int x){
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y){
    x = root(x);
    y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  int size(int x){
    return -d[root(x)];
  }
};
int kruskal(vector<edge> &es){
  int n;
  ll res = 0;
  sort(es.begin(), es.end());
  UnionFind tree(n);
  for(edge e : es){
    if(!tree.same(e.u, e.v)){
      tree.unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}