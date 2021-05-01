#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct frac{
  //少数を a/b で表す
  ll a,b;
  frac(ll a = 0, ll b = 1) : a(a), b(b){}
  frac &operator*=(const ll &d){
    a *= d;
    return *this;
  }
  frac &operator*=(const frac &d){
    a *= d.a; b *= d.b;
    reduce();
    return *this;
  }
  frac &operator/=(const frac &d){
    a *= d.b; b *= d.a;
    reduce();
    return *this;
  }
  frac &operator+=(const frac &d){
    ll g = gcd(abs(b), abs(d.b));
    ll t = b / g * d.b; //lcm(abs(a), abs(b))
    a = a*d.b/g + d.a*b/g;
    b = t;
    reduce();
    return *this;
  }
  frac &operator-=(const frac &d){
    ll g = gcd(abs(b), abs(d.b));
    ll t = b / g * d.b; //lcm(abs(a), abs(b))
    a = a*d.b/g - d.a*b/g;
    b = t;
    reduce();
    return *this;
  }
  frac operator*(const frac &d){ return frac(*this) *= d; }
  frac operator/(const frac &d){ return frac(*this) /= d; }
  frac operator+(const frac &d){ return frac(*this) += d; }
  frac operator-(const frac &d){ return frac(*this) -= d; }
  void reduce(){
    ll g = gcd(abs(a), abs(b));
    if(a < 0 && b < 0) g = -g;
    a /= g; b /= g;
  }
  ll gcd(ll a, ll b){
    if(a % b == 0) return b;
    return gcd(b, a % b);
  }
  void debug(){ cout << a << "/" << b << "\n"; }
  friend ostream &operator<<(ostream &os, const frac &d){
    printf("%.10lf", (double)d.a / d.b);
    return os;
  }
};