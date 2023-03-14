#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../../template/template.hpp"

#include "../../math/fps/kitamasa.hpp"

using mint = Mint<998244353>;
using fps = FPS<mint>;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int d; ll K;
  cin >> d >> K;
  fps a(d), c(d+1);
  rep(i, d) cin >> a[i];
  rep(i, d) cin >> c[i+1];
  c = fps{1} - c;
  cout << kitamasa(K, c, a) << "\n";
}