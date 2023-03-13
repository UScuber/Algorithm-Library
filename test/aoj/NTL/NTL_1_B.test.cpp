#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B"

#include "../../../template/template.hpp"

#include "../../../math/modpow.hpp"

int main(){
  int n,m;
  cin >> n >> m;
  cout << modPow(n, m, mod) << "\n";
}