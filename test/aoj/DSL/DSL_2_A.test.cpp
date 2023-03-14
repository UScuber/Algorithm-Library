#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A"

#include "../../../template/template.hpp"

#include "../../../SegmentTree/seg-rmin.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  SegmentTree<int,min> seg(n);
  while(q--){
    int t,x,y;
    cin >> t >> x >> y;
    if(t == 0){
      seg.update(x, y);
    }else{
      cout << seg.query(x, y+1) << "\n";
    }
  }
}