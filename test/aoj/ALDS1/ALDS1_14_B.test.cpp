#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B"

#include "../../../template/template.hpp"

#include "../../../string/rolling-hash.hpp"

RollingHash<10000> roliha;
int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string s,t;
  cin >> s >> t;
  const auto sh = roliha.gen(s);
  const auto th = roliha.gen(t);
  for(int i = 0; i + t.size() <= s.size(); i++){
    if(sh.query(i, i+t.size()) == th.query(0, t.size())){
      cout << i << "\n";
    }
  }
}