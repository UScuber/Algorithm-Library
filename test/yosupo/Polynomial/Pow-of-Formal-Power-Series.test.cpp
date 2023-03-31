#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "../../../template/template.hpp"

#include "../../../math/fps/fps.hpp"
#include "../../../math/mint.hpp"

using mint = Mint<998244353>;
using fps = FPS<mint>;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n; ll m;
  cin >> n >> m;
  fps a(n);
  rep(i, n) cin >> a[i];
  const fps b = a.pow(m);
  rep(i, n) cout << b[i] << " \n"[i == n - 1];
}