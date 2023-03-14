#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"

#include "../../../template/template.hpp"

#include "../../../SegmentTree/BinaryIndexedTree.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  BIT<int> seg(n);
  while(q--){
    int t,x,y;
    cin >> t >> x >> y;
    x--;
    if(t == 0){
      seg.add(x, y);
    }else{
      cout << seg.sum(x, y) << "\n";
    }
  }
}