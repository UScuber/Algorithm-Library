#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_H"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  int n;
  Circle c;
  cin >> n >> c.r;
  Polygon p(n);
  rep(i, n) cin >> p[i];
  printf("%.10lf\n", area(p, c));
}