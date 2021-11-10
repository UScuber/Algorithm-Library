#include <bits/stdc++.h>
#include <complex>
using namespace std;

using Point = complex<double>;
constexpr double EPS = 1e-8;
constexpr double PI = acos(-1);

bool eq(const double &a, const double &b){
  return fabs(b - a) < EPS;
}
Point operator*(const Point &a, const double &b){
  return Point(a.real() * b, a.imag() * b);
}
istream &operator>>(istream &is, Point &p){
  double a,b;
  is >> a >> b;
  p = Point(a, b);
  return is;
}
ostream &operator<<(ostream &os, Point &p){
  return os << p.real() << " " << p.imag();
}
namespace std {
  bool operator<(const Point &a, const Point &b){
    if(a.real() != b.real()) return a.real() < b.real();
    return a.imag() < b.imag();
  }
};
double cross(const Point &a, const Point &b){
  return a.real() * b.imag() - a.imag() * b.real();
}
double dot(const Point &a, const Point &b){
  return a.real() * b.real() + a.imag() * b.imag();
}

struct Line {
  Point a,b;
  Line(){}
  Line(Point a, Point b) : a(a), b(b){}
};

struct Circle {
  Point p;
  double r;
  Circle(){};
  Circle(Point p, Real r) : p(p), r(r){}
};