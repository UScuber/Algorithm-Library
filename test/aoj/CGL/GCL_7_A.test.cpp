#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_A"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  Circle a,b;
  cin >> a.p >> a.r >> b.p >> b.r;
  cout << intersect(a, b) << "\n";
}