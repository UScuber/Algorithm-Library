#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../../../template/template.hpp"

#include "../../../string/manacher.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  char c;
  string s = "$";
  while((c = getchar()) != 10){
    s += c;
    s += '$';
  }
  const vi res = manacher(s);
  const int l = res.size();
  for(int i = 1; i < l-1; i++){
    if(i & 1) cout << (res[i]-1)/2*2+1 << " ";
    else cout << (res[i]-1)/2*2 << " ";
  }
  cout << "\n";
}