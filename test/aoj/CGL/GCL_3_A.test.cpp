#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_3_A"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  int n;
  cin >> n;
  Polygon p(n);
  rep(i, n) cin >> p[i];
  printf("%.1lf\n", area(p));
}