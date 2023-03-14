#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_F"

#include "../../../template/template.hpp"

#include "../../../SegmentTree/rupdate-rmin.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  LazySegmentTree<int> seg(n);
  while(q--){
    int t; cin >> t;
    if(t == 0){
      int l,r,x;
      cin >> l >> r >> x;
      seg.update(l, r+1, x);
    }else{
      int l,r;
      cin >> l >> r;
      cout << seg.query(l, r+1) << "\n";
    }
  }
}