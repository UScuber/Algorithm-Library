#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../template/template.hpp"

#include "../../string/z-algorithm.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  for(const int x : z_algo(s)) cout << x << " ";
  cout << "\n";
}