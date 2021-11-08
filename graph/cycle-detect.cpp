#include <bits/stdc++.h>
using namespace std;

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

namespace cycle {
  graph g;
  vector<int> used;
  vector<edge<int>> prev, cyc;
  bool dfs(int pos){
    used[pos] = 1;
    for(auto &x : g[pos]){
      if(!used[x]){
        prev[x] = x;
        if(dfs(x)) return true;
      }else if(used[x] == 1){
        int cur = pos;
        cyc.push_back(x);
        while(cur != x){
          cyc.push_back(prev[cur]);
          cur = prev[cur].from;
        }
        return true;
      }
    }
    used[pos] = 2;
    return false;
  }
  vector<edge<int>> detect(const graph &root){
    g = root;
    int n = g.size();
    used.resize(n);
    prev.resize(n, -1);
    for(int i = 0; i < n; i++){
      if(!used[i] && dfs(i)){
        reverse(cyc.begin(), cyc.end());
        return cyc;
      }
    }
    return {};
  }
};