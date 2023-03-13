#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../template/template.hpp"

#include "../../graph/scc.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  vvi root(n);
  rep(i, m){
    int a,b;
    cin >> a >> b;
    root[a].push_back(b);
  }
  scc<vvi> g(root);
  cout << g.group.size() << "\n";
  for(const vi &t : g.group){
    int si = t.size();
    cout << si << " ";
    per(i, si) cout << t[i] << " ";
    cout << "\n";
  }
}