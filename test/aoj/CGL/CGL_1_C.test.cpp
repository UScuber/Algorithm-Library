#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_C"

#include "../../../template/template.hpp"

#include "../../../geometry/template.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  Point a,b;
  cin >> a >> b;
  int q;
  cin >> q;
  rep(_, q){
    Point c;
    cin >> c;
    const int ans = ccw(a, b, c);
    if(ans == 1) cout << "COUNTER_CLOCKWISE\n";
    if(ans == -1) cout << "CLOCKWISE\n";
    if(ans == 2) cout << "ONLINE_BACK\n";
    if(ans == -2) cout << "ONLINE_FRONT\n";
    if(ans == 0) cout << "ON_SEGMENT\n";
  }
}