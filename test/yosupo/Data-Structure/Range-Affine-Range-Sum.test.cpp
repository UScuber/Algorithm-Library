#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

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
  int t,l,r,b,c;
  rep(_, q){
    cin >> t >> l >> r;
    if(t == 0){
      cin >> b >> c;
      seg.update(l, r, { b, c });
    }else{
      cout << seg.query(l, r).a << "\n";
    }
  }
}