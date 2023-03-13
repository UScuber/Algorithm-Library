#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../template/template.hpp"

#include "../../SegmentTree/segtree.hpp"
#include "../../math/mint.hpp"

using mint = Mint<998244353>;

struct Data {
  mint a,b;
};
Data op(const Data &l, const Data &m){
  return { l.a*m.a, l.b*m.a + m.b };
}
Data e(){
  return { 1, 0 };
}

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  SegmentTree<Data,op,e> seg(n);
  rep(i, n){
    int a,b;
    cin >> a >> b;
    seg.set(i, { a, b });
  }
  seg.build();
  rep(i, q){
    int t,l,r,x;
    cin >> t >> l >> r >> x;
    if(t == 0){
      seg.update(l, { r,x });
    }else{
      const Data res = seg.query(l, r);
      cout << res.a*x + res.b << "\n";
    }
  }
}