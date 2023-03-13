#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../template/template.hpp"

#include "../../graph/UnionFind.hpp"

int main(){
  int n,q;
  scanf("%d%d", &n, &q);
  UnionFind tree(n);
  rep(i, q){
    int t,a,b;
    scanf("%d%d%d", &t, &a, &b);
    if(!t) tree.unite(a, b);
    else cout << tree.same(a, b) << "\n";
  }
}