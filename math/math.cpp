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


pair<ll, ll> crt(ll b1, ll m1, ll b2, ll m2){
  ll p, q;
  ll d = ext_gcd(m1, m2, p, q); // p is inv of m1/d (mod. m2/d)
  if((b2 - b1) % d != 0) return make_pair(0, -1);
  ll m = m1 * (m2/d); // lcm of (m1, m2)
  ll tmp = (b2 - b1) / d * p % (m2/d);
  ll r = ((b1 + m1 * tmp) % m + m) % m;
  return make_pair(r, m);
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