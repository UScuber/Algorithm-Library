#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include "../../../template/template.hpp"

#include "../../../math/fps/fps.hpp"
#include "../../../math/mint.hpp"

constexpr int Mod = 998244353;
using mint = Mint<Mod>;
using fps = FPS<mint>;

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,t;
  cin >> n >> t;
  vi cnt(t + 1);
  rep(i, n){
    int s; cin >> s;
    cnt[s]++;
  }
  vector<mint> inv(t + 1);
  inv[1] = 1;
  for(int i = 2; i <= t; i++) inv[i] = -inv[Mod % i] * (Mod / i);
  FPS<mint> f(t + 1);
  rep(i, t + 1) if(cnt[i]){
    int num = 1;
    for(int j = i; j <= t; j += i){
      if(num & 1) f[j] += inv[num] * cnt[i];
      else f[j] -= inv[num] * cnt[i];
      num++;
    }
  }
  f = f.exp();
  for(int i = 1; i <= t; i++) cout << f[i] << " \n"[i == t];
}