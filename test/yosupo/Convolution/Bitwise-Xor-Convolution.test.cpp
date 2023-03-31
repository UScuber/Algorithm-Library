#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include "../../../template/template.hpp"

#include "../../../math/convolution/xor-convolution.hpp"
#include "../../../math/mint.hpp"

using mint = Mint<998244353>;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  n = 1 << n;
  vector<mint> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  const auto res = xor_convolution(a, b);
  rep(i, n) cout << res[i] << " \n"[i == n - 1];
}