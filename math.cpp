#include <bits/stdc++.h>
using ll = long long;
using namespace std;


template<class T>
T gcd(T a, T b){
  if(a % b == 0) return b;
  return gcd(b, a % b);
}

template<class T>
T lcm(T a, T b){
  return a / gcd(a, b) * b;
}

ll modPow(ll a, ll n, ll p){
  if(!n) return 1;
  if(n == 1) return a % p;
  if(n & 1) return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
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

struct complex {
  double re,img;
  complex(double re = 0, double img = 0) : re(re), img(img){}
  complex &operator+=(const complex &c){
    re += c.re; img += c.img;
    return *this;
  }
  complex &operator-=(const complex &c){
    re -= c.re; img -= c.img;
    return *this;
  }
  complex &operator*=(const complex &c){
    double t = re*c.re - img*c.img;
    img = img*c.re + re*c.img;
    re = t;
    return *this;
  }
  complex &operator/=(const complex &c){ return (*this) *= c.inv(); }
  complex operator+(const complex &c) const{ return complex(*this) += c; }
  complex operator-(const complex &c) const{ return complex(*this) -= c; }
  complex operator*(const complex &c) const{ return complex(*this) *= c; }
  complex operator/(const complex &c) const{ return complex(*this) /= c; }
  complex inv() const{
    double t = re*re + img*img;
    return complex(re / t, -img / t);
  }
  friend ostream &operator<<(ostream &os, const complex &c){
    printf("%.10lf+%.10lfi\n", c.re, c.img);
    return os;
  }
};