#include "template.hpp"

template <class T>
pair<T, vector<int>> diameter(const Graph<T> &g){
  const int n = g.size();
  vector<T> dist(n);
  vector<int> prev(n, -1);
  function<void(int,int)> dfs = [&](int pos, int par){
    for(auto &x : g[pos]) if(x != par){
      dist[x] = dist[pos] + x.cost;
      prev[x] = pos;
      dfs(x, pos);
    }
  };
  dfs(0, -1);
  int pos = max_element(dist.begin(), dist.end()) - dist.begin();
  dist.assign(n, 0); prev.assign(n, -1);
  dfs(pos, -1);
  pos = max_element(dist.begin(), dist.end()) - dist.begin();
  const T tot = dist[pos];
  vector<int> res;
  for(int i = pos; i != -1; i = prev[i]) res.push_back(i);
  return { tot, res };
}