#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../../template/template.hpp"

#include "../../../data-structure/static-rectangle-sum.hpp"
#include "../../../others/fastIO.hpp"

int main(){
  int n,q;
  cin >> n >> q;
  RectangleSum<int,ll> rs;
  rep(i, n){
    int x,y,w;
    cin >> x >> y >> w;
    rs.add_point(x, y, w);
  }
  rep(i, q){
    int l,d,r,u;
    cin >> l >> d >> r >> u;
    rs.add_rect(l, d, r, u);
  }
  for(const auto &x : rs.run()) cout << x << '\n';
}