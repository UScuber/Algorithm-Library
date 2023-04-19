#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_C"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  int q;
  cin >> q;
  rep(_, q){
    Segment a,b;
    cin >> a >> b;
    const Point res = crosspoint(a, b);
    printf("%.10lf %.10lf\n", res.real(), res.imag());
  }
}