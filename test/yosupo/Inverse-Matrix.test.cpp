#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "../../template/template.hpp"

#include "../../math/matrix.hpp"
#include "../../math/mint.hpp"

using mint = Mint<998244353>;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  matrix<mint> mat(n);
  rep(i, n) rep(j, n) cin >> mat[i][j];
  mat = mat.inv();
  if(mat.size() == 0) cout << "-1\n";
  else{
    rep(i, n){
      rep(j, n) cout << mat[i][j] << " ";
      cout << "\n";
    }
  }
}