#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "../../../template/template.hpp"

#include "../../../data-structure/wavelet-matrix-comp.hpp"

int main(){
  int n,q;
  cin >> n >> q;
  vi a(n);
  rep(i, n) cin >> a[i];
  WaveletMatrixComp<int,19> mat(move(a));
  int l,r,x;
  while(q--){
    cin >> l >> r >> x;
    cout << mat.rank(x, r) - mat.rank(x, l) << "\n";
  }
}