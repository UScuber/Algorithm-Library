#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A"

#include "../../../template/template.hpp"

#include "../../../graph/dinic.hpp"

int main(){
  int n,m;
  cin >> n >> m;
  dinic<int> g(n);
  rep(i, m){
    int a,b,c;
    cin >> a >> b >> c;
    g.add_edge(a, b, c);
  }
  cout << g.max_flow(0, n-1) << "\n";
}