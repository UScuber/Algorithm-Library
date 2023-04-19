#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_G"
#define ERROR 1e-9

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  Circle a,b;
  cin >> a.p >> a.r >> b.p >> b.r;
  Points ans;
  for(const auto &x : tangent(a, b)){
    if(intersect(a, x.a)) ans.push_back(x.a);
    else ans.push_back(x.b);
  }
  sort(ans.begin(), ans.end());
  for(const Point &p : ans) printf("%.10lf %.10lf\n", p.real(), p.imag());
}