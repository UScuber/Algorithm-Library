#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_I"
#define ERROR 1e-9

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  Circle a,b;
  cin >> a.p >> a.r >> b.p >> b.r;
  printf("%.10lf\n", area(a, b));
}