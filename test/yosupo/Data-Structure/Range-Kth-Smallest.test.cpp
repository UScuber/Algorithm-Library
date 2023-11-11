#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../../template/template.hpp"

#include "../../../data-structure/wavelet-matrix-comp.hpp"
#include "../../../others/fastIO.hpp"

int main(){
  int n,q;
  cin >> n >> q;
  vi a(n);
  rep(i, n) cin >> a[i];
  WaveletMatrixComp<int,19> mat(move(a));
  int l,r,k;
  while(q--){
    cin >> l >> r >> k;
    cout << mat.kth_smallest(l, r, k) << '\n';
  }
}