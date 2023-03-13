#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../../template/template.hpp"

#include "../../math/convolution/convolution-arbitrary-mod.hpp"
#include "../../math/mint.hpp"

using mint = Mint<1000000007>;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  vector<mint> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  for(auto x : convolution(a, b)) cout << x.x << ' ';
  cout << '\n';
}