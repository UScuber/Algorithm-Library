#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../../template/template.hpp"

#include "../../../graph/UnionFind.hpp"
#include "../../../others/fastIO.hpp"

int main(){
  int n,q;
  cin >> n >> q;
  UnionFind tree(n);
  rep(i, q){
    int t,a,b;
    cin >> t >> a >> b;
    if(!t) tree.unite(a, b);
    else cout << tree.same(a, b) << '\n';
  }
}