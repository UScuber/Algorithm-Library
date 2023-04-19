#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_5_A"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  int n;
  cin >> n;
  Polygon p(n);
  rep(i, n) cin >> p[i];
  printf("%.10lf\n", closest_pair(p));
}