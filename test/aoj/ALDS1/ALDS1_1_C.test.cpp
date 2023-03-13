#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C"

#include "../../../template/template.hpp"

#include "../../../math/eratosthenes.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  range_eratosthenes ss(1, 100000010);
  int n;
  cin >> n;
  int ans = 0;
  rep(i, n){
    int a; cin >> a;
    if(ss.is_prime(a)) ans++;
  }
  cout << ans << "\n";
}