#define PROBLEM "https://judge.yosupo.jp/problem/primarity_test"

#include "../../../template/template.hpp"

#include "../../../math/isprime.hpp"

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int q;
  cin >> q;
  rep(_, q){
    ll n; cin >> n;
    if(is_prime(n)) cout << "Yes\n";
    else cout << "No\n";
  }
}