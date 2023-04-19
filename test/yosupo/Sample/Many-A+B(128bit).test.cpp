#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include "../../../template/template.hpp"

#include "../../../others/int128.hpp"

int main(){
  int t;
  cin >> t;
  rep(i, t){
    lll a,b;
    cin >> a >> b;
    cout << a + b << "\n";
  }
}