#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../template/template.hpp"

#include "../../math/mint.hpp"
#include "../../math/matrix.hpp"

using mint = Mint<998244353>;

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  matrix<mint> a(n);
  rep(i, n) rep(j, n) cin >> a[i][j];
  cout << a.det() << "\n";
}