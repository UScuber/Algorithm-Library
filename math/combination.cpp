#include <bits/stdc++.h>
#include "mint.hpp"
using namespace std;

constexpr int len = 2000010;
mint fact[len], invfact[len];
struct initializer {
  initializer(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < len; i++) fact[i] = fact[i - 1] * i;
    invfact[len - 1] = fact[len - 1].inv();
    for(int i = len - 2; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1);
  }
} initializer;
mint C(int n, int r){
  assert(0 <= n && n < len);
  if(n < r) return 0;
  return fact[n] * invfact[n - r] * invfact[r];
}
mint P(int n, int r){
  assert(0 <= n && n < len);
  if(n < r) return 0;
  return fact[n] * invfact[n - r];
}
mint H(int n, int r){
  assert(0 < n && 0 <= r);
  assert(0 < n+r && n+r <= len);
  return fact[n + r - 1] * invfact[n - 1] * invfact[r];
}