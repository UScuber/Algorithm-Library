#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"

#include "../../../template/template.hpp"

#include "../../../graph/Weighted-UnionFind.hpp"

int main(){
  int n,q;
  cin >> n >> q;
  UnionFindW<int> tree(n);
  rep(i, q){
    int t; cin >> t;
    if(!t){
      int x,y,z;
      cin >> x >> y >> z;
      tree.merge(x, y, z);
    }else{
      int x,y;
      cin >> x >> y;
      if(!tree.same(x, y)) cout << "?\n";
      else cout << tree.diff(x, y) << "\n";
    }
  }
}