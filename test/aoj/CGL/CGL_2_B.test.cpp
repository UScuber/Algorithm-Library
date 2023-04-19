#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_B"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  rep(_, q){
    Segment a,b;
    cin >> a >> b;
    if(intersect(a, b)) cout << "1\n";
    else cout << "0\n";
  }
}