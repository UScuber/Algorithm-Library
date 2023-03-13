#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_C"

#include "../../../template/template.hpp"

#include "../../../math/gcdlcm.hpp"

int main(){
  int n;
  cin >> n;
  int ans = 1;
  rep(i, n){
    int a; cin >> a;
    ans = lcm(ans, a);
  }
  cout << ans << "\n";
}