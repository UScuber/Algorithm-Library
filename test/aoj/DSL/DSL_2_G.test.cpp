#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G"

#include "../../../template/template.hpp"

#include "../../../SegmentTree/radd-rsum.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  LazySegmentTree<ll> seg(n);
  while(q--){
    int t; cin >> t;
    if(t == 0){
      int l,r,x;
      cin >> l >> r >> x;
      seg.update(l-1, r, x);
    }else{
      int l,r;
      cin >> l >> r;
      cout << seg.query(l-1, r) << "\n";
    }
  }
}