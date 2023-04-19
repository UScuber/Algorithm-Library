#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_4_C"
#define ERROR 1e-8

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  int n;
  cin >> n;
  Polygon p(n);
  rep(i, n) cin >> p[i];
  int q;
  cin >> q;
  rep(_, q){
    Line l;
    cin >> l;
    printf("%.10lf\n", area(convex_cut(p, l)));
  }
}