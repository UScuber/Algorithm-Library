#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include "../../../template/template.hpp"

#include "../../../data-structure/Treap.hpp"
#include "../../../math/mint.hpp"
#include "../../../others/fastIO.hpp"

using mint = Mint<998244353>;

int main(){
  int n,q;
  cin >> n >> q;
  SumAffineQuery<mint> tree;
  int t,l,r,i;
  mint a,b,c,x;
  rep(i, n){
    cin >> a.x;
    tree.insert(i, a);
  }
  rep(_, q){
    cin >> t;
    if(t == 0){
      cin >> i >> x.x;
      tree.insert(i, x);
    }else if(t == 1){
      cin >> i;
      tree.erase(i);
    }else if(t == 2){
      cin >> l >> r;
      tree.reverse(l, r);
    }else if(t == 3){
      cin >> l >> r >> b.x >> c.x;
      tree.update(l, r, { b, c });
    }else{
      cin >> l >> r;
      cout << tree.query(l, r).x << '\n';
    }
  }
}