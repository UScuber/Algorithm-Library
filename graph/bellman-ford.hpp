#include "template.hpp"

template <class T, const T&(*op)(const T&, const T&)>
struct BellmanFord {
  BellmanFord(const Graph<T> &r): root(r), n(r.size()){
    inf = -op(inf, -inf);
    res.assign(n, inf);
  }
  void solve(const int s){
    assert(0 <= s && s < n);
    res[s] = 0;
    for(int i = 1; i < n; i++) for(int j = 0; j < n; j++){
      if(res[j] != inf) for(const auto &x : root[j]){
        res[x] = op(res[x], res[j] + x.cost);
      }
    }
    vector<int> loop(n);
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
      if(res[j] != inf) for(const auto &x : root[j]){
        if(op(res[x] + op(1,-1), res[j] + x.cost) == res[j] + x.cost){
          res[x] = res[j] + x.cost;
          loop[x] = 1;
        }
        if(loop[j]) loop[x] = 1;
      }
    }
    for(int i = 0; i < n; i++) if(loop[i]) res[i] = -inf;
  }
  const T &operator[](const int i) const{
    assert(0 <= i && i < n);
    return res[i];
  }
  bool is_cycle(const int i) const{
    assert(0 <= i && i < n);
    return res[i] == -inf;
  }
  private:
  const Graph<T> &root;
  vector<T> res;
  int n;
  T inf = numeric_limits<T>::max()-1;
};