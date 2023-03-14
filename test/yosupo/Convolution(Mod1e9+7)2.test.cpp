#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod_1000000007"

#include "../../template/template.hpp"

#include "../../math/fps/fps-arbitrary-mod.hpp"
#include "../../math/mint.hpp"

using mint = Mint<1000000007>;
using fps = FPS<mint>;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  fps a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  for(const auto &x : a * b) cout << x << " ";
  cout << "\n";
}