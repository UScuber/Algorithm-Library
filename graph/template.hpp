#pragma once

/**
 * @brief Graph Template
*/
template <class T>
struct Edge {
  int from,to;
  T cost;
  int idx;
  Edge(){};
  Edge(int f, int t, T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}
  Edge(int t) : to(t), from(-1), cost(1), idx(-1){}
  operator int() const{ return to; }
  bool operator<(const Edge &e){ return cost < e.cost; }
};
template <class T>
struct Graph : vector<vector<Edge<T>>> {
  Graph(){}
  Graph(const int &n) : vector<vector<Edge<T>>>(n){}
  void add_edge(int a, int b, T c=1, int i=-1){
    (*this)[a].push_back({ a, b, c, i });
  }
};
using graph = Graph<int>;