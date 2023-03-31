#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D"

#include "../../../template/template.hpp"

#include "../../../SegmentTree/rupdate-rmin.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  LazySegmentTree<int,min> seg(n);
  rep(i, q){
    int t; cin >> t;
    if(!t){
      int l,r,x;
      cin >> l >> r >> x;
      seg.update(l, r + 1, x);
    }else{
      int x; cin >> x;
      cout << seg.get(x) << "\n";
    }
  }
}