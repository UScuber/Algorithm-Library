#include <bits/stdc++.h>
using ll = long long;
using namespace std;

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