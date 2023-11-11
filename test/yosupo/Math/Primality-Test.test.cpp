#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../../../template/template.hpp"

#include "../../../math/isprime.hpp"
#include "../../../others/fastIO.hpp"

int main(){
  int q;
  cin >> q;
  rep(_, q){
    ll n; cin >> n;
    if(is_prime(n)) cout << "Yes\n";
    else cout << "No\n";
  }
}