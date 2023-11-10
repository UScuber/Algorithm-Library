#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../../template/template.hpp"

#include "../../../graph/dijkstra.hpp"

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n,m,s,t;
  cin >> n >> m >> s >> t;
  graph root(n);
  rep(i, m){
    int a,b,c;
    cin >> a >> b >> c;
    root[a].push_back({ a, b, c });
  }
  vl dist;
  vi prev;
  dijkstra<int,ll>(root, s, dist, prev);

  if(prev[t] == -1){
    cout << "-1\n";
    return 0;
  }
  int pos = t;
  vector<pii> ans;
  while(pos != s){
    ans.push_back({ prev[pos], pos });
    pos = prev[pos];
  }
  reverse(all(ans));
  const int si = ans.size();
  cout << dist[t] << " " << si << "\n";
  for(const auto &x : ans) cout << x.first << " " << x.second << "\n";
}