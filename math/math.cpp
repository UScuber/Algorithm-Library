#include <bits/stdc++.h>
using ll = long long;
using namespace std;


template<class T>
T gcd(T a, T b){
  if(!b) return a;
  return gcd(b, a % b);
}

template<class T>
T lcm(T a, T b){
  return a / gcd(a, b) * b;
}


ll modPow(ll a, ll n, ll p){
  a %= p;
  ll res = 1;
  while(n){
    if(n & 1) (res *= a) %= p;
    (a *= a) %= p;
    n >>= 1;
  }
  return res;
}


ll ext_gcd(ll a, ll b, ll &x, ll &y){
  ll d = a;
  if(b){
    d = ext_gcd(b, a % b, y, x);
    y -= (a / b) * x;
  }else{ x = 1; y = 0; }
  return d;
}


pair<ll, ll> crt(const vector<ll> &r,const vector<ll> &m){
  assert(r.size() == m.size());
  const int n = (int)r.size();
  ll r0 = 0, m0 = 1;
  for(int i = 0; i < n; i++){
    assert(1 <= m[i]);
    ll r1 = (r[i] % m[i] + m[i]) % m[i], m1 = m[i];
    if(m0 < m1){
      swap(r0, r1);
      swap(m0, m1);
    }
    if(m0 % m1 == 0){
      if(r0 % m1 != r1) return { 0, 0 };
      continue;
    }
    ll im, tmp;
    const ll g = ext_gcd(m0, m1, im, tmp);
    const ll u1 = (m1 / g);
    if((r1 - r0) % g) return { 0, 0 };
    const ll x = (r1 - r0) / g % u1 * im % u1;
    r0 += x * m0;
    m0 *= u1;
    if(r0 < 0) r0 += m0;
  }
  return { r0, m0 };
}


ll euler(ll n){
  ll res = n, k = n;
  for(ll i = 2; i*i <= k; i++){
    if(n % i) continue;
    res = res / i * (i - 1);
    while(n % i == 0) n /= i;
  }
  if(n != 1) res = res / n * (n - 1);
  return res;
}