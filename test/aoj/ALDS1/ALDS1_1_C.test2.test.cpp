#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C"

#include "../../../template/template.hpp"

#include "../../../math/isprime.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int ans = 0;
  rep(i, n){
    int a; cin >> a;
    if(is_prime(a)) ans++;
  }
  cout << ans << "\n";
}