#include "mint.hpp"

constexpr int len = 2000010;
constexpr int f_size = min(len, mod);
mint fact[f_size], invfact[f_size], inv[f_size];
struct initializer {
  initializer(){
    fact[0] = fact[1] = inv[1] = 1;
    invfact[0] = invfact[1] = 1;
    for(int i = 2; i < f_size; i++){
      fact[i] = fact[i - 1] * i;
      inv[i] = -inv[mod % i] * (mod/i);
      invfact[i] = invfact[i - 1] * inv[i];
    }
  }
} initializer;
mint C(int n, int r){
  assert(0 <= n && n < len);
  mint res = 1;
  while(r){
    int a = n % mod;
    int b = r % mod;
    if(a < b) return 0;
    res *= fact[a] * invfact[b] * invfact[a - b];
    n /= mod;
    r /= mod;
  }
  return res;
}
mint H(int n, int r){
  assert(0 < n && 0 <= r);
  assert(0 < n+r && n+r <= len);
  return C(n + r - 1, r);
}