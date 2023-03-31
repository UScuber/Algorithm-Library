#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../../../template/template.hpp"

#include "../../../data-structure/HLD.hpp"
#include "../../../math/mint.hpp"

using mint = Mint<998244353>;

struct Data {
  mint a,b;
};
Data e(){
  return { 1, 0 };
}
Data op(const Data &l, const Data &m){
  return { l.a*m.a, l.b*m.a + m.b };
}
Data rev_op(const Data &l, const Data &m){
  return { m.a*l.a, m.b*l.a + l.b };
}

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  vi a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  graph root(n);
  rep(i, n - 1){
    int a,b;
    cin >> a >> b;
    root[a].push_back(b);
    root[b].push_back(a);
  }
  HLD<Data,op,rev_op,e> hld(root);
  rep(i, n) hld.set(i, { a[i], b[i] });
  hld.build();
  int t,p,c,d,u,v,x;
  rep(_, q){
    cin >> t;
    if(t == 0){
      cin >> p >> c >> d;
      hld.update(p, { c, d });
    }else{
      cin >> u >> v >> x;
      const Data res = hld.query(u, v);
      const mint ans = res.a * x + res.b;
      cout << ans << "\n";
    }
  }
}