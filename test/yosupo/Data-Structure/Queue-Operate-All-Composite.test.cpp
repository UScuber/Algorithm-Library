#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../../../template/template.hpp"

#include "../../../data-structure/SWAG.hpp"
#include "../../../math/mint.hpp"
#include "../../../others/fastIO.hpp"

using mint = Mint<998244353>;

//Data: ax+b
struct Data {
  mint a,b;
};
//合成関数 g(f(x))
Data op(const Data &l, const Data &m){
  return { l.a*m.a, l.b*m.a + m.b };
}
const Data e(){
  return { 1, 0 };
}
int main(){
  int q;
  cin >> q;
  SWAG<Data, op, e> sw;
  rep(i, q){
    int t; cin >> t;
    if(t == 0){
      int a,b;
      cin >> a >> b;
      sw.push_back({ a, b });
    }else if(t == 1){
      sw.pop();
    }else{
      int x; cin >> x;
      const Data l = sw.fold(0, sw.size());
      cout << (l.a*x + l.b).x << '\n';
    }
  }
}