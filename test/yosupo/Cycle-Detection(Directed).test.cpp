#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include "../../template/template.hpp"

#include "../../graph/cycle-detect.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  graph root(n);
  rep(i, m){
    int a,b;
    cin >> a >> b;
    root[a].push_back({ a, b, 1, i });
  }
  Cycle cycle(root);
  auto res = cycle.detect();
  if(res.empty()) cout << "-1\n";
  else{
    cout << res.size() << "\n";
    for(auto &x : res) cout << x.idx << "\n";
  }
}