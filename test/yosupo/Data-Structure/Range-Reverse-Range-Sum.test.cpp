#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include "../../../template/template.hpp"

#include "../../../data-structure/Treap.hpp"
#include "../../../others/fastIO.hpp"

int main(){
  int n,q;
  cin >> n >> q;
  SumAddQuery<ll,ll> tr;
  rep(i, n){
    int a;
    cin >> a;
    tr.insert(i, a);
  }
  rep(_, q){
    int t,l,r;
    cin >> t >> l >> r;
    if(t == 0){
      tr.reverse(l, r);
    }else{
      cout << tr.query(l, r) << '\n';
    }
  }
}