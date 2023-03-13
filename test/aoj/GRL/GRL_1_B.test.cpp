#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B"

#include "../../../template/template.hpp"

#include "../../../graph/template.hpp"
#include "../../../graph/bellman-ford.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,m,r;
  cin >> n >> m >> r;
  graph root(n);
  rep(i, m){
    int a,b,c;
    cin >> a >> b >> c;
    root[a].push_back({ a, b, c });
  }
  BellmanFord<int,min> bf(root);
  bf.solve(r);
  rep(i, n) if(bf.is_cycle(i)){
    cout << "NEGATIVE CYCLE\n";
    return 0;
  }
  rep(i, n){
    if(bf[i] > (int)1e9) cout << "INF\n";
    else cout << bf[i] << "\n";
  }
}