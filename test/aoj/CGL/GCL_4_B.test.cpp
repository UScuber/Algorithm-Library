#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_B"
#define ERROR 1e-9

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  int n;
  cin >> n;
  Polygon p(n);
  rep(i, n) cin >> p[i];
  printf("%.10lf\n", convex_diameter(p));
}