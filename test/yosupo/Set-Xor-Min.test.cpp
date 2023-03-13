#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../template/template.hpp"

#include "../../data-structure/binarytrie.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  BinaryTrie<int, 30> bt;
  bt.reserve(q);
  rep(_, q){
    int t,x;
    cin >> t >> x;
    if(t == 0){
      if(!bt.count(x)) bt.insert(x);
    }else if(t == 1){
      if(bt.count(x)) bt.erase(x);
    }else{
      cout << bt.min(x) << "\n";
    }
  }
}