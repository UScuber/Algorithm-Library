#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../../template/template.hpp"

#include "../../../data-structure/HLD.hpp"

using Data = ll;

Data e(){ return 0; }
Data op(const Data &a, const Data &b){
  return a + b;
}
Data rev_op(const Data &a, const Data &b){
  return a + b;
}

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  vi a(n);
  rep(i, n) cin >> a[i];
  graph root(n);
  rep(i, n - 1){
    int a,b;
    cin >> a >> b;
    root[a].push_back(b);
    root[b].push_back(a);
  }
  HLD<Data,op,rev_op,e> hld(root);
  rep(i, n) hld.set(i, a[i]);
  hld.build();
  int t,p,x,u,v;
  rep(_, q){
    cin >> t;
    if(t == 0){
      cin >> p >> x;
      hld.update(p, hld.get(p) + x);
    }else{
      cin >> u >> v;
      cout << hld.query(u, v) << "\n";
    }
  }
}