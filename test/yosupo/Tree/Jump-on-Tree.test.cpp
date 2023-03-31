#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include "../../../template/template.hpp"

#include "../../../graph/lca.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  vvi root(n);
  rep(i, n - 1){
    int a,b;
    cin >> a >> b;
    root[a].push_back(b);
    root[b].push_back(a);
  }
  const lca<vvi> g(root);
  rep(_, q){
    int s,t,k;
    cin >> s >> t >> k;
    cout << g.jump(s, t, k) << "\n";
  }
}