#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_D"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  int q;
  cin >> q;
  rep(_, q){
    Segment a,b;
    cin >> a >> b;
    printf("%.10lf\n", distance(a, b));
  }
}