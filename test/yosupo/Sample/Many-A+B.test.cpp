#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include "../../../template/template.hpp"

#include "../../../others/fastIO.hpp"

int main(){
  int t;
  cin >> t;
  rep(i, t){
    unsigned long long a,b;
    cin >> a >> b;
    cout << a + b << '\n';
  }
}