#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_B"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  Polygon p(n);
  rep(i, n) cin >> p[i];
  if(is_convex(p)) cout << "1\n";
  else cout << "0\n";
}