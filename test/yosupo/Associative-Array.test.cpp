#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"

#include "../../template/template.hpp"

#include "../../data-structure/HashMap.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  HashMap<ll,ll> cnt;
  int t; ll k,v;
  rep(i, q){
    cin >> t;
    if(t == 0){
      cin >> k >> v;
      cnt[k] = v;
    }else{
      cin >> k;
      cout << cnt[k] << "\n";
    }
  }
}