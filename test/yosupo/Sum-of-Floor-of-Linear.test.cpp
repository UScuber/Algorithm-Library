#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "../../template/template.hpp"

#include "../../math/floor-sum.hpp"

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  rep(_, t){
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    cout << floor_sum(n, m, a, b) << "\n";
  }
}