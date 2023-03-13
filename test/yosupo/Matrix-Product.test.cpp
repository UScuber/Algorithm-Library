#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../../template/template.hpp"

#include "../../math/mint.hpp"
#include "../../math/matrix.hpp"

using mint = Mint<998244353>;

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n,m,k;
  cin >> n >> m >> k;
  matrix<mint> a(n, m), b(m, k);
  rep(i, n) rep(j, m) cin >> a[i][j];
  rep(i, m) rep(j, k) cin >> b[i][j];
  a *= b;
  rep(i, n){
    rep(j, k) cout << a[i][j] << " ";
    cout << "\n";
  }
}