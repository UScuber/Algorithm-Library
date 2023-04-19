#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_E"
#define ERROR 1e-8

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  Circle a,b;
  cin >> a.p >> a.r >> b.p >> b.r;
  auto ans = crosspoint(a, b);
  if(ans.first > ans.second) swap(ans.first, ans.second);
  printf("%.10lf %.10lf %.10lf %.10lf\n", ans.first.real(), ans.first.imag(), ans.second.real(), ans.second.imag());
}