#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../../../template/template.hpp"

#include "../../../SegmentTree/lazysegtree.hpp"
#include "../../../math/mint.hpp"

using mint = Mint<998244353>;

struct Data {
  mint a, len;
};
struct Lazy {
  mint a, b;
};
Data op(const Data &a, const Data &b){
  return { a.a+b.a, a.len+b.len };
}
Data e(){ return { 0, 0 }; }
Data mapping(const Lazy &a, const Data &b){
  return { a.a*b.a + a.b*b.len, b.len };
}
Lazy composition(const Lazy &a, const Lazy &b){
  return { a.a*b.a, a.b*b.a + b.b };
}
Lazy id(){ return { 1, 0 }; }

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  LazySegmentTree<Data,op,e,Lazy,mapping,composition,id> seg(n);
  rep(i, n){
    int a; cin >> a;
    seg.set(i, { a, 1 });
  }
  seg.build();
  rep(_, q){
    int t; cin >> t;
    if(t == 0){
      int l,r,b,c;
      cin >> l >> r >> b >> c;
      seg.update(l, r, { b, c });
    }else{
      int i; cin >> i;
      cout << seg.get(i).a << "\n";
    }
  }
}