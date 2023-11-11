#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../../template/template.hpp"

#include "../../../SegmentTree/BinaryIndexedTree.hpp"
#include "../../../others/fastIO.hpp"

int main(){
  int n,q;
  cin >> n >> q;
  BIT<ll> seg(n);
  rep(i, n){
    int a; cin >> a;
    seg.add(i, a);
  }
  rep(i, q){
    int t,a,b;
    cin >> t >> a >> b;
    if(t == 0) seg.add(a, b);
    else cout << seg.sum(a, b) << '\n';
  }
}