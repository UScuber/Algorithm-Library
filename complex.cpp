#include <bits/stdc++.h>
using namespace std;

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