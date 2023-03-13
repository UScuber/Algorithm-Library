#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A"

#include "../../../template/template.hpp"

#include "../../../graph/template.hpp"
#include "../../../graph/kruskal.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  vector<Edge<int>> es(m);
  rep(i, m){
    int a,b,c;
    cin >> a >> b >> c;
    es[i] = { a, b, c };
  }
  cout << kruskal(es, n) << "\n";
}