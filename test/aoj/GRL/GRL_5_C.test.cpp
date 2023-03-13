#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"

#include "../../../template/template.hpp"

#include "../../../graph/lca.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vvi root(n);
  rep(i, n){
    int k, c;
    cin >> k;
    rep(j, k){
      cin >> c;
      root[i].push_back(c);
    }
  }
  lca<vvi> g(root);
  int q;
  cin >> q;
  rep(i, q){
    int u,v;
    cin >> u >> v;
    cout << g.query(u, v) << "\n";
  }
}