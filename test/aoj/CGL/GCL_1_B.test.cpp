#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_B"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  Line l;
  cin >> l;
  int q;
  cin >> q;
  rep(_, q){
    Point p;
    cin >> p;
    const Point res = reflection(l, p);
    printf("%.10lf %.10lf\n", res.real(), res.imag());
  }
}