#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_2_A"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  rep(_, q){
    Line a,b;
    cin >> a >> b;
    if(parallel(a, b)) cout << "2\n";
    else if(orthogonal(a, b)) cout << "1\n";
    else cout << "0\n";
  }
}