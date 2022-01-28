#include <bits/stdc++.h>
#include "template.hpp"
using namespace std;

template <class T, const T&(*op)(const T&, const T&)>
struct bellman_ford {
  bellman_ford(int n): n(n), root(n){ init(); }
  bellman_ford(const Graph<T> &r): root(r), n(r.size()){ init(); }
  private:
  void init(){
    inf = -op(inf, -inf);
    res.resize(n, inf);
  }
  Graph<T> root;
  vector<T> res;
  int n;
  T inf = numeric_limits<T>::max();
  public:
  void solve(int s){
    assert(0 <= s && s < n);
    res[s] = 0;
    for(int i = 1; i < n; i++) for(int j = 0; j < n; j++){
      if(res[j] != inf) for(auto &x : root[j]){
        res[x] = op(res[x], res[j] + x.cost);
      }
    }
    vector<int> loop(n);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
      if(res[j] != inf) for(auto &x : root[j]){
        if(op(res[x] + op(1,-1), res[j] + x.cost) == res[j] + x.cost){
          res[x] = res[j] + x.cost;
          loop[x] = 1;
        }
        if(loop[j]) loop[x] = 1;
      }
    }
    for(int i = 0; i < n; i++) if(loop[i]) res[i] = inf;
  }
  const T &operator[](const int &i) const{
    assert(0 <= i && i < n);
    return res[i];
  }
  bool is_cycle(const int &i) const{
    assert(0 <= i && i < n);
    return res[i] == inf;
  }
};