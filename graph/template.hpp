#include <bits/stdc++.h>
using namespace std;

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