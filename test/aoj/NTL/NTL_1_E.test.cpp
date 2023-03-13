#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E"

#include "../../../template/template.hpp"

#include "../../../math/extgcd.hpp"

int main(){
  ll a,b;
  cin >> a >> b;
  ll x,y;
  ext_gcd(a, b, x, y);
  cout << x << " " << y << "\n";
}