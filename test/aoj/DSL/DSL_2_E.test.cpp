#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E"

#include "../../../template/template.hpp"

#include "../../../SegmentTree/radd-rmin.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  LazySegmentTree<ll> seg(n);
  rep(i, q){
    int t; cin >> t;
    if(!t){
      int l,r,x;
      cin >> l >> r >> x;
      seg.update(l - 1, r, x);
    }else{
      int x; cin >> x;
      cout << seg.get(x - 1) << "\n";
    }
  }
}