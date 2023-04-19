#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_F"
#define ERROR 1e-9

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  Point p;
  Circle c;
  cin >> p >> c.p >> c.r;
  auto ans = tangent(c, p);
  if(ans.first > ans.second) swap(ans.first, ans.second);
  printf("%.10lf %.10lf\n%.10lf %.10lf\n", ans.first.real(), ans.first.imag(), ans.second.real(), ans.second.imag());
}