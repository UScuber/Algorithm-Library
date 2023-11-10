#include "template.hpp"

template <class T, class U = T>
void dijkstra(const Graph<T> &root, const int s, vector<U> &dist, vector<int> &prev){
  const int n = root.size();
  dist.assign(n, numeric_limits<U>::max());
  prev.assign(n, -1);
  using pui = pair<U, int>;
  priority_queue<pui, vector<pui>, greater<pui>> que;
  que.push({ 0, s });
  while(!que.empty()){
    U val; int pos;
    tie(val,pos) = que.top();
    que.pop();
    if(dist[pos] < val) continue;
    for(const auto &x : root[pos]){
      if(chmin(dist[x], val + x.cost)){
        que.push({ dist[x], x });
        prev[x] = pos;
      }
    }
  }
}