#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* template */
template <class T>
struct edge {
  int from,to;
  T cost;
  int idx;
  edge(){};
  edge(int f, int t, T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}
  edge(int t) : to(t), from(-1), cost(1), idx(-1){}
  operator int() const{ return to; }
  bool operator<(const edge &e){ return cost < e.cost; }
};
template <class T>
struct Graph : vector<vector<edge<T>>> {
  Graph(){}
  Graph(const int &n) : vector<vector<edge<T>>>(n){}
  void add_edge(int a, int b, T c=1, int i=-1){
    (*this)[a].push_back({ a, b, c, i });
  }
};
using graph = Graph<int>;
/* template */

/* unionfind */
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
/* unionfind */


template <class T>
ll kruskal(vector<edge<T>> &es, int V){
  ll res = 0;
  sort(es.begin(), es.end());
  UnionFind tree(V);
  for(auto &e : es){
    if(!tree.same(e.from, e.to)){
      tree.unite(e.from, e.to);
      res += e.cost;
    }
  }
  return res;
}