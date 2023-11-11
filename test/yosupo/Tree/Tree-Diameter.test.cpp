#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../../template/template.hpp"

#include "../../../graph/diameter.hpp"
#include "../../../others/fastIO.hpp"

int main(){
  int n;
  cin >> n;
  Graph<ll> root(n);
  rep(i, n - 1){
    int a,b,c;
    cin >> a >> b >> c;
    root[a].push_back({ a, b, c });
    root[b].push_back({ b, a, c });
  }
  const auto res = diameter(root);
  const int m = res.second.size();
  cout << res.first << ' ' << m << '\n';
  rep(i, m) cout << res.second[i] << " \n"[i == m - 1];
}