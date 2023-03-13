#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D"

#include "../../../template/template.hpp"

#include "../../../data-structure/slide-min.hpp"

int main(){
  int n,k;
  cin >> n >> k;
  vi a(n);
  rep(i, n) cin >> a[i];
  const auto res = slide_min(a, k);
  rep(i, n-k+1) cout << res[i] << " \n"[i == n - k];
}