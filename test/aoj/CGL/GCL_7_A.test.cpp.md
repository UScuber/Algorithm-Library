---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_A
  bundledCode: "#line 1 \"test/aoj/CGL/GCL_7_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_A\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\
    \n#include <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <tuple>\r\
    \n#include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <deque>\r\n#include <bitset>\r\
    \n#include <cctype>\r\n#include <climits>\r\n#include <functional>\r\n#include\
    \ <cassert>\r\n#include <numeric>\r\n#include <cstring>\r\n#define rep(i, n) for(int\
    \ i = 0; i < (n); i++)\r\n#define per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\
    \nusing ll = long long;\r\n#define vi vector<int>\r\n#define vvi vector<vi>\r\n\
    #define vl vector<ll>\r\n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\
    \n#define all(a) (a).begin(), (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\
    \nconstexpr int mod = 1000000007;\r\nusing namespace std;\r\ntemplate<class T,\
    \ class U>\r\nbool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\
    \ntemplate<class T, class U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a\
    \ = b, 1) : 0; }\n#line 4 \"test/aoj/CGL/GCL_7_A.test.cpp\"\n\n#line 1 \"geometry/template.hpp\"\
    \nusing Real = double;\r\n\r\nconstexpr Real EPS = 1e-10;\r\nconstexpr Real PI\
    \ = 3.141592653589793238462643383279L;\r\nconstexpr Real INF = 1e18;\r\n\r\ninline\
    \ constexpr bool eq(const Real &a, const Real &b){\r\n  return fabs(b - a) < EPS;\r\
    \n}\r\n\r\nstruct Point {\r\n  constexpr Point(const Real &_x=0, const Real &_y=0)\
    \ : x(_x), y(_y){}\r\n  constexpr Real &real(){ return x; }\r\n  constexpr Real\
    \ &imag(){ return y; }\r\n  constexpr Real real() const{ return x; }\r\n  constexpr\
    \ Real imag() const{ return y; }\r\n  constexpr Point operator-() const{ return\
    \ Point(-x, -y); }\r\n  constexpr Point &operator+=(const Point &p){ x += p.real();\
    \ y += p.imag(); return *this; }\r\n  constexpr Point &operator-=(const Point\
    \ &p){ x -= p.real(); y -= p.imag(); return *this; }\r\n  constexpr Point &operator*=(const\
    \ Real &a){ x *= a; y *= a; return *this; }\r\n  constexpr Point &operator*=(const\
    \ Point &p){ return *this = *this * p; }\r\n  constexpr Point &operator/=(const\
    \ Real &a){ assert(!eq(a, 0.0)); x /= a; y /= a; return *this; }\r\n  constexpr\
    \ Point operator+(const Point &p) const{ return Point(*this) += p; }\r\n  constexpr\
    \ Point operator-(const Point &p) const{ return Point(*this) -= p; }\r\n  constexpr\
    \ Point operator*(const Real &p) const{ return Point(*this) *= p; }\r\n  constexpr\
    \ Point operator*(const Point &p) const{ return Point(x*p.x - y*p.y, y*p.x + x*p.y);\
    \ }\r\n  constexpr Point operator/(const Real &p) const{ return Point(*this) /=\
    \ p; }\r\n  constexpr bool operator==(const Point &p) const{ return eq(x, p.real())\
    \ && eq(y, p.imag()); }\r\n  constexpr bool operator!=(const Point &p) const{\
    \ return !(*this == p); }\r\n  constexpr bool operator<(const Point &p) const{\r\
    \n    if(x != p.real()) return x < p.real();\r\n    return y < p.imag();\r\n \
    \ }\r\n  constexpr bool operator>(const Point &p) const{\r\n    if(x != p.real())\
    \ return x > p.real();\r\n    return y > p.imag();\r\n  }\r\n  constexpr Real\
    \ norm() const{ return x*x + y*y; }\r\n  constexpr Real abs() const{ return sqrt(norm());\
    \ }\r\n  constexpr Point conj() const{ return Point(x, -y); }\r\n  constexpr Real\
    \ arg() const{ return atan2(y, x); }\r\n  friend istream &operator>>(istream &is,\
    \ Point &p){ return is >> p.real() >> p.imag(); }\r\n  friend ostream &operator<<(ostream\
    \ &os, const Point &p){ return os << p.real() << \" \" << p.imag(); }\r\nprivate:\r\
    \n  Real x,y;\r\n};\r\n\r\nPoint polar(const Real &r, const Real &theta){\r\n\
    \  return Point(r*cos(theta), r*sin(theta));\r\n}\r\nconstexpr Real real(const\
    \ Point &p){ return p.real(); }\r\nconstexpr Real imag(const Point &p){ return\
    \ p.imag(); }\r\nconstexpr Real norm(const Point &p){ return p.norm(); }\r\nconstexpr\
    \ Real abs(const Point &p){ return p.abs(); }\r\nconstexpr Point conj(const Point\
    \ &p){ return p.conj(); }\r\nconstexpr Real arg(const Point &p){ return p.arg();\
    \ }\r\ninline constexpr Real cross(const Point &a, const Point &b){\r\n  return\
    \ a.real() * b.imag() - a.imag() * b.real();\r\n}\r\ninline constexpr Real dot(const\
    \ Point &a, const Point &b){\r\n  return a.real() * b.real() + a.imag() * b.imag();\r\
    \n}\r\nconstexpr Point rotate(const Point &p, const Real &theta){\r\n  return\
    \ Point(cos(theta)*p.real() - sin(theta)*p.imag(), sin(theta)*p.real() + cos(theta)*p.imag());\r\
    \n}\r\nconstexpr Real rad2deg(const Real &theta){ return theta*180.0/PI; }\r\n\
    constexpr Real deg2rad(const Real &theta){ return theta*PI/180.0; }\r\n\r\n//\
    \ calc <ABC\r\nconstexpr Real get_angle(const Point &a, const Point &b, const\
    \ Point &c){\r\n  Real alpha = arg(b - a), beta = arg(c - b);\r\n  if(alpha >\
    \ beta) swap(alpha, beta);\r\n  const Real theta = beta - alpha;\r\n  return min(theta,\
    \ PI*2 - theta);\r\n}\r\nconstexpr int type(const Point &a){\r\n  if(eq(a.real(),\
    \ 0) && eq(a.imag(), 0)) return 0;\r\n  if(a.imag() > -EPS || (eq(a.imag(), 0)\
    \ && a.real() < EPS)) return 1;\r\n  return -1;\r\n}\r\n\r\nstruct Line {\r\n\
    \  Point a,b;\r\n  constexpr Line(){}\r\n  constexpr Line(const Point &_a, const\
    \ Point &_b) : a(_a), b(_b){}\r\n  constexpr Line(const Real &A, const Real &B,\
    \ const Real &C){\r\n    if(eq(A, 0)) a = Point(0, C/B), b = Point(1, C/B);\r\n\
    \    else if(eq(B, 0)) a = Point(C/A, 0), b = Point(C/A, 1);\r\n    else a = Point(0,\
    \ C/B), b = Point(C/A, 0);\r\n  }\r\n  friend istream &operator>>(istream &is,\
    \ Line &l){ return is >> l.a >> l.b; }\r\n  friend ostream &operator<<(ostream\
    \ &os, const Line &l){ return os << l.a << \" to \" << l.b; }\r\n};\r\n\r\nstruct\
    \ Segment {\r\n  Point a,b;\r\n  constexpr Segment(){}\r\n  constexpr Segment(const\
    \ Point &_a, const Point &_b) : a(_a), b(_b){}\r\n  friend istream &operator>>(istream\
    \ &is, Segment &l){ return is >> l.a >> l.b; }\r\n  friend ostream &operator<<(ostream\
    \ &os, const Segment &l){ return os << l.a << \" to \" << l.b; }\r\n};\r\n\r\n\
    struct Circle {\r\n  Point p;\r\n  Real r;\r\n  Circle(){}\r\n  constexpr Circle(const\
    \ Point &_p, const Real &_r) : p(_p), r(_r){}\r\n};\r\n\r\nusing Points = vector<Point>;\r\
    \nusing Lines = vector<Line>;\r\nusing Segments = vector<Segment>;\r\nusing Polygon\
    \ = vector<Point>;\r\n\r\n// \u70B9\u306E\u56DE\u8EE2\u65B9\u5411\r\nconstexpr\
    \ int ccw(const Point &a, Point b, Point c){\r\n  b -= a, c -= a;\r\n  if(cross(b,\
    \ c) > EPS) return +1;  // \"a \u2192 b \u3067 \u53CD\u6642\u8A08\u65B9\u5411\u306B\
    \u304A\u308C\u3066 c\"\r\n  if(cross(b, c) < -EPS) return -1; // \"a \u2192 b\
    \ \u3067 \u6642\u8A08\u65B9\u5411\u306B\u304A\u308C\u3066 c\"\r\n  if(dot(b, c)\
    \ < 0) return +2;      // \"c -- a -- b\u3067\u4E00\u76F4\u7DDA\u4E0A\"\r\n  if(norm(b)\
    \ < norm(c)) return -2;  // \"a -- b -- c\u3067\u4E00\u76F4\u7DDA\u4E0A\"\r\n\
    \  return 0;                         // \"a -- c -- b\u3067\u4E00\u76F4\u7DDA\u4E0A\
    \"\r\n}\r\n// \u504F\u89D2\r\nconstexpr bool is_large(const Point &a, const Point\
    \ &b){\r\n  if(type(a) != type(b)) return type(a) < type(b);\r\n  return cross(a,\
    \ b) > 0;\r\n}\r\n// \u5E73\u884C\r\nconstexpr bool parallel(const Line &a, const\
    \ Line &b){\r\n  return eq(cross(a.b - a.a, b.b - b.a), 0);\r\n}\r\n// \u5782\u76F4\
    \r\nconstexpr bool orthogonal(const Line &a, const Line &b){ \r\n  return eq(dot(a.a\
    \ - a.b, b.a - b.b), 0);\r\n}\r\n// \u76F4\u7DDA l \u306B p \u304B\u3089\u5782\
    \u7DDA\u3092\u5F15\u3044\u305F\u4EA4\u70B9\u3092\u6C42\u3081\u308B\r\nconstexpr\
    \ Point projection(const Line &l, const Point &p){\r\n  const Real t = dot(p -\
    \ l.a, l.a - l.b) / norm(l.a - l.b);\r\n  return l.a + (l.a - l.b) * t;\r\n}\r\
    \nconstexpr Point projection(const Segment &s, const Point &p){\r\n  const Real\
    \ t = dot(p - s.a, s.a - s.b) / norm(s.a - s.b);\r\n  return s.a + (s.a - s.b)\
    \ * t;\r\n}\r\n// \u76F4\u7DDA l \u3092\u5BFE\u79F0\u8EF8\u3068\u3057\u3066\u70B9\
    \ p \u3068\u7DDA\u5BFE\u79F0\u306B\u3042\u308B\u70B9\u3092\u6C42\u3081\u308B\r\
    \nconstexpr Point reflection(const Line &l, const Point &p){\r\n  return p + (projection(l,\
    \ p) - p) * 2;\r\n}\r\nconstexpr Point projection(const Point &p, const Line &l){\
    \ return projection(l, p); }\r\nconstexpr Point projection(const Point &p, const\
    \ Segment &s){ return projection(s, p); }\r\nconstexpr Point reflection(const\
    \ Point &p, const Line &l){ return projection(l, p); }\r\n\r\n// \u4EA4\u5DEE\u5224\
    \u5B9A\r\nconstexpr bool intersect(const Line &l, const Point &p){\r\n  return\
    \ abs(ccw(l.a, l.b, p)) != 1;\r\n}\r\nconstexpr bool intersect(const Line &l,\
    \ const Line &m){\r\n  return abs(cross(l.b - l.a, m.b - m.a)) > EPS || abs(cross(l.b\
    \ - l.a, m.b - l.a)) < EPS;\r\n}\r\nconstexpr bool intersect(const Segment &s,\
    \ const Point &p){\r\n  return ccw(s.a, s.b, p) == 0;\r\n}\r\nconstexpr bool intersect(const\
    \ Line &l, const Segment &s){\r\n  return cross(l.b - l.a, s.a - l.a) * cross(l.b\
    \ - l.a, s.b - l.a) < EPS;\r\n}\r\n\r\nconstexpr Real distance(const Line &l,\
    \ const Point &p);\r\nconstexpr bool intersect(const Circle &c, const Line &l){\r\
    \n  return distance(l, c.p) <= c.r + EPS;\r\n}\r\nconstexpr bool intersect(const\
    \ Circle &c, const Point &p){\r\n  return abs(abs(p - c.p) - c.r) < EPS;\r\n}\r\
    \nconstexpr bool intersect(const Segment &s, const Segment &t){\r\n  return ccw(s.a,\
    \ s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b)\
    \ <= 0;\r\n}\r\nconstexpr bool intersect(const Point &p, const Line &l){ return\
    \ intersect(l, p); }\r\nconstexpr bool intersect(const Point &p, const Segment\
    \ &s){ return intersect(s, p); }\r\nconstexpr bool intersect(const Segment &s,\
    \ const Line &l){ return intersect(l, s); }\r\nconstexpr bool intersect(const\
    \ Line &l, const Circle &c){ return intersect(c, l); }\r\nconstexpr bool intersect(const\
    \ Point &p, const Circle &c){ return intersect(c, p); }\r\n\r\nconstexpr Real\
    \ distance(const Point &a, const Point &b){\r\n  return abs(a - b);\r\n}\r\nconstexpr\
    \ Real distance(const Line &l, const Point &p){\r\n  return abs(cross(l.b-l.a,\
    \ p-l.a) / abs(l.b - l.a));\r\n}\r\nconstexpr Real distance(const Line &l, const\
    \ Line &m){\r\n  return intersect(l, m) ? 0 : distance(l, m.a);\r\n}\r\nconstexpr\
    \ Real distance(const Segment &s, const Point &p){\r\n  if(dot(s.b-s.a, p-s.a)\
    \ < 0) return abs(p - s.a);\r\n  if(dot(s.a-s.b, p-s.b) < 0) return abs(p - s.b);\r\
    \n  return distance(Line(s.a, s.b), p);\r\n}\r\nconstexpr Real distance(const\
    \ Segment &a, const Segment &b){\r\n  if(intersect(a, b)) return 0;\r\n  return\
    \ min({ distance(a, b.a), distance(a, b.b), distance(b, a.a), distance(b, a.b)\
    \ });\r\n}\r\nconstexpr Real distance(const Line &l, const Segment &s){\r\n  if(intersect(l,\
    \ s)) return 0;\r\n  return min(distance(l, s.a), distance(l, s.b));\r\n}\r\n\
    constexpr Real distance(const Point &p, const Line &l){ return distance(l, p);\
    \ }\r\nconstexpr Real distance(const Point &p, const Segment &s){ return distance(s,\
    \ p); }\r\nconstexpr Real distance(const Segment &s, const Line &l){ return distance(l,\
    \ s); }\r\n\r\n// \u4EA4\u5DEE\u3059\u308B\u6570\r\nconstexpr int intersect(const\
    \ Circle &c, const Segment &s){\r\n  if(norm(projection(s, c.p) - c.p) - c.r*c.r\
    \ > EPS) return 0;\r\n  const Real d1 = abs(c.p - s.a), d2 = abs(c.p - s.b);\r\
    \n  if(d1 < c.r + EPS && d2 < c.r + EPS) return 0;\r\n  if((d1 < c.r - EPS &&\
    \ d2 > c.r + EPS) || (d1 > c.r + EPS && d2 < c.r - EPS)) return 1;\r\n  const\
    \ Point h = projection(s, c.p);\r\n  if(dot(s.a - h, s.b - h) < 0) return 2;\r\
    \n  return 0;\r\n}\r\nconstexpr int intersect(const Segment &s, const Circle &c){\
    \ return intersect(c, s); }\r\n//\u5171\u901A\u63A5\u7DDA\u306E\u6570\r\nconstexpr\
    \ int intersect(Circle c1, Circle c2){\r\n  if(c1.r < c2.r) swap(c1, c2);\r\n\
    \  const Real d = abs(c1.p - c2.p);\r\n  if(c1.r + c2.r < d) return 4; //\u96E2\
    \u308C\u3066\u3044\u308B\r\n  if(eq(c1.r + c2.r, d)) return 3; //\u5916\u63A5\r\
    \n  if(c1.r - c2.r < d) return 2; //2\u70B9\u3067\u4EA4\u308F\u308B\r\n  if(eq(c1.r\
    \ - c2.r, d)) return 1; //\u5185\u63A5\r\n  return 0; //\u5185\u5305\r\n}\r\n\r\
    \n//\u4EA4\u70B9\u306E\u5EA7\u6A19\r\nconstexpr Point crosspoint(const Line &l,\
    \ const Line &m){\r\n  const Real A = cross(l.b - l.a, m.b - m.a);\r\n  const\
    \ Real B = cross(l.b - l.a, l.b - m.a);\r\n  if(eq(abs(A), 0.0) && eq(abs(B),\
    \ 0.0)) return m.a;\r\n  if(eq(abs(A), 0.0)) throw \"no crosspoint\";\r\n  return\
    \ m.a + (m.b - m.a) * (B/A);\r\n}\r\nconstexpr Point crosspoint(const Segment\
    \ &l, const Segment &m){\r\n  if(!intersect(l, m)) throw \"no crosspoint\";\r\n\
    \  return crosspoint(Line(l.a, l.b), Line(m.a, m.b));\r\n}\r\n///////////\r\n\
    Points crosspoint(const Circle &c, const Line &l){\r\n  const Point pr = projection(l,\
    \ c.p);\r\n  const Real d = distance(l, c.p) - c.r;\r\n  if(d > 0) return {};\r\
    \n  if(eq(d, 0)) return { pr };\r\n  const Point e = (l.b - l.a) / abs(l.b - l.a);\r\
    \n  const Real base = sqrt(c.r*c.r - norm(pr - c.p));\r\n  return { pr - e*base,\
    \ pr + e*base };\r\n}\r\n///////////\r\nPoints crosspoint(const Circle &c, const\
    \ Segment &s){\r\n  const Line aa(s.a, s.b);\r\n  const Points res = crosspoint(c,\
    \ aa);\r\n  if(res.empty() || intersect(c, s) == 2) return res;\r\n  if(dot(s.a\
    \ - res[0], s.b - res[0]) < 0) return { res[0] };\r\n  return { res.back() };\r\
    \n}\r\n\r\n///////////\r\n//\u4E2D\u5FC3\u306F\u7570\u306A\u308B\u5EA7\u6A19,\u4E00\
    \u3064\u306E\u4EA4\u70B9\u306E\u5834\u5408\u306F\u540C\u3058\u5EA7\u6A19\u3092\
    \u4E8C\u3064\u51FA\u529B\u3059\u308B\r\npair<Point,Point> crosspoint(const Circle\
    \ &c1, const Circle &c2){\r\n  const Real d = abs(c1.p - c2.p);\r\n  const Real\
    \ a = acos((c1.r*c1.r + d*d - c2.r*c2.r) / (c1.r*d*2));\r\n  const Real t = arg(c2.p\
    \ - c1.p);\r\n  const Point p1 = c1.p + polar(c1.r, t + a);\r\n  const Point p2\
    \ = c1.p + polar(c1.r, t - a);\r\n  return { p1, p2 };\r\n}\r\n//\u70B9 p \u3092\
    \u901A\u308B\u5186 c \u306E\u63A5\u7DDA, \u70B9\u306F\u5186\u306E\u5185\u90E8\
    ,\u5186\u4E0A\u306B\u306A\u3044\r\npair<Point,Point> tangent(const Circle &c1,\
    \ const Point &p2){\r\n  return crosspoint(c1, Circle(p2, sqrt(norm(c1.p - p2)\
    \ - c1.r*c1.r)));\r\n}\r\n// \u5186 c1, c2 \u306E\u5171\u901A\u63A5\u7DDA\r\n\
    Lines tangent(Circle c1, Circle c2){\r\n  Lines res;\r\n  if(c1.r < c2.r) swap(c1,\
    \ c2);\r\n  const Real g = norm(c1.p - c2.p);\r\n  if(eq(g, 0)) return res;\r\n\
    \  const Point u = (c2.p - c1.p) / sqrt(g);\r\n  const Point v = rotate(u, PI\
    \ * 0.5);\r\n  for(const int s : { -1,1 }){\r\n    const Real h = (c1.r + s*c2.r)\
    \ / sqrt(g);\r\n    if(eq(1 - h*h, 0)){\r\n      res.emplace_back(c1.p + u*c1.r,\
    \ c1.p + (u + v)*c1.r);\r\n    }else if(1 - h*h > 0){\r\n      const Point uu\
    \ = u*h, vv = v*sqrt(1 - h*h);\r\n      res.emplace_back(c1.p + (uu + vv)*c1.r,\
    \ c2.p - (uu + vv)*c2.r*s);\r\n      res.emplace_back(c1.p + (uu - vv)*c1.r, c2.p\
    \ - (uu - vv)*c2.r*s);\r\n    }\r\n  }\r\n  return res;\r\n}\r\n\r\nbool is_convex(const\
    \ Polygon &p){\r\n  const int n = p.size();\r\n  for(int i = 0; i < n; i++){\r\
    \n    if(ccw(p[i ? i-1 : n-1], p[i], p[i < n-1 ? i+1 : 0]) == -1) return false;\r\
    \n  }\r\n  return true;\r\n}\r\n// \u51F8\u5305\r\nPolygon convex_hull(Polygon\
    \ &p){\r\n  const int n = p.size();\r\n  int k = 0;\r\n  if(n <= 2) return p;\r\
    \n  sort(p.begin(), p.end());\r\n  Points ch(n*2);\r\n  for(int i = 0; i < n;\
    \ ch[k++] = p[i++]){\r\n    while(k >= 2 && cross(ch[k-1] - ch[k-2], p[i] - ch[k-1])\
    \ < EPS) k--;\r\n  }\r\n  for(int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]){\r\
    \n    while(k >= t && cross(ch[k-1] - ch[k-2], p[i] - ch[k-1]) < EPS) k--;\r\n\
    \  }\r\n  ch.resize(k - 1);\r\n  return ch;\r\n}\r\n\r\n// \u591A\u89D2\u5F62\u3068\
    \u70B9\u306E\u5305\u542B\u5224\u5B9A\r\nenum {\r\n  OUT, ON, IN\r\n};\r\nint contains(const\
    \ Polygon &Q, const Point &p){\r\n  const int n = Q.size();\r\n  bool in = false;\r\
    \n  for(int i = 0; i < n; i++){\r\n    Point a = Q[i] - p, b = Q[i < n-1 ? i+1\
    \ : 0] - p;\r\n    if(a.imag() > b.imag()) swap(a, b);\r\n    if(a.imag() <= 0\
    \ && 0 < b.imag() && cross(a, b) < 0) in = !in;\r\n    if(cross(a, b) == 0 &&\
    \ dot(a, b) <= 0) return ON;\r\n  }\r\n  return in ? IN : OUT;\r\n}\r\n\r\n//\
    \ \u76F4\u7DDA l.a-l.b \u3067\u5207\u65AD\u3057\u305D\u306E\u5DE6\u5074\u306B\u3067\
    \u304D\u308B\u51F8\u591A\u89D2\u5F62\u3092\u8FD4\u3059\r\nPolygon convex_cut(const\
    \ Polygon &U, const Line &l){\r\n  const int n = U.size();\r\n  Polygon res;\r\
    \n  for(int i = 0; i < n; i++){\r\n    const Point now = U[i], nxt = U[i < n-1\
    \ ? i+1 : 0];\r\n    if(ccw(l.a, l.b, now) != -1) res.push_back(now);\r\n    if(ccw(l.a,\
    \ l.b, now) * ccw(l.a, l.b, nxt) < 0){\r\n      res.push_back(crosspoint(Line(now,\
    \ nxt), l));\r\n    }\r\n  }\r\n  return res;\r\n}\r\n\r\n// \u591A\u89D2\u5F62\
    \u306E\u9762\u7A4D\r\nReal area(const Polygon &p){\r\n  const int n = p.size();\r\
    \n  Real A = 0;\r\n  for(int i = 0; i < n; i++){\r\n    A += cross(p[i], p[i <\
    \ n-1 ? i+1 : 0]);\r\n  }\r\n  return A * 0.5;\r\n}\r\n\r\n// \u5186\u3068\u591A\
    \u89D2\u5F62\u306E\u5171\u901A\u90E8\u5206\u306E\u9762\u7A4D\r\nReal area(const\
    \ Polygon &p, const Circle &c){\r\n  const int n = p.size();\r\n  if(n < 3) return\
    \ 0;\r\n  function<Real(Circle, Point, Point)> cross_area = [&](const Circle &c,\
    \ const Point &a, const Point &b){\r\n    const Point va = c.p - a, vb = c.p -\
    \ b;\r\n    const Real f = cross(va, vb);\r\n    Real res = 0;\r\n    if(eq(f,\
    \ 0)) return res;\r\n    if(max(abs(va), abs(vb)) < c.r + EPS) return f;\r\n \
    \   if(distance(Segment(a, b), c.p) > c.r - EPS) return c.r*c.r * arg(vb*conj(va));\r\
    \n    const Points u = crosspoint(c, Segment(a, b));\r\n    assert(!u.empty());\r\
    \n    Points tot{ a, u.front(), u.back(), b };\r\n    for(int i = 0; i + 1 < (int)tot.size();\
    \ i++){\r\n      res += cross_area(c, tot[i], tot[i + 1]);\r\n    }\r\n    return\
    \ res;\r\n  };\r\n  Real A = 0;\r\n  for(int i = 0; i < n; i++){\r\n    A += cross_area(c,\
    \ p[i], p[i < n-1 ? i+1 : 0]);\r\n  }\r\n  return A * 0.5;\r\n}\r\nReal area(const\
    \ Circle &a, const Circle &b){\r\n  Real d = abs(a.p - b.p);\r\n  if(d + EPS >=\
    \ a.r + b.r) return 0;\r\n  if(d <= abs(a.r - b.r)) return PI * min(a.r,b.r)*min(a.r,b.r);\r\
    \n  d *= d;\r\n  const Real p1 = a.r*a.r - b.r*b.r + d;\r\n  const Real p2 = b.r*b.r\
    \ - a.r*a.r + d;\r\n  const Real temp = sqrt(4*d*a.r*a.r - p1*p1);\r\n  const\
    \ Real s1 = a.r*a.r * atan2(temp, p1);\r\n  const Real s2 = b.r*b.r * atan2(sqrt(d\
    \ * b.r*b.r*4 - p2*p2), p2);\r\n  return s1 + s2 - temp * 0.5;\r\n}\r\n\r\n//\
    \ \u51F8\u591A\u89D2\u5F62\u306E\u76F4\u5F84(\u6700\u9060\u9802\u70B9\u5BFE\u9593\
    \u8DDD\u96E2)\r\nReal convex_diameter(const Polygon &p){\r\n  const int n = p.size();\r\
    \n  int is = 0, js = 0;\r\n  for(int i = 1; i < n; i++){\r\n    if(p[i].imag()\
    \ > p[is].imag()) is = i;\r\n    if(p[i].imag() < p[js].imag()) js = i;\r\n  }\r\
    \n  Real maxdis = norm(p[is] - p[js]);\r\n  int maxi = is, maxj = js, i = is,\
    \ j = js;\r\n  do {\r\n    if(cross(p[i < n-1 ? i+1 : 0] - p[i], p[j < n-1 ? j+1\
    \ : 0] - p[j]) >= 0){\r\n      if(++j >= n) j = 0;\r\n    }else{\r\n      if(++i\
    \ >= n) i = 0;\r\n    }\r\n    if(norm(p[i] - p[j]) > maxdis){\r\n      maxdis\
    \ = norm(p[i] - p[j]);\r\n      maxi = i;\r\n      maxj = j;\r\n    }\r\n  } while(i\
    \ != is || j != js);\r\n  return sqrt(maxdis);\r\n}\r\n\r\n// \u6700\u8FD1\u70B9\
    \u5BFE\r\nReal closest_pair(Points ps){\r\n  if(ps.size() <= 1) throw 0;\r\n \
    \ sort(ps.begin(), ps.end());\r\n  auto compare_y = [&](const Point &a, const\
    \ Point &b){\r\n    return imag(a) < imag(b);\r\n  };\r\n  vector<Point> beet(ps.size());\r\
    \n  function<Real(int,int)> rec = [&](int left, int right){\r\n    if(right -\
    \ left <= 1) return INF;\r\n    const int mid = (left + right) / 2;\r\n    const\
    \ Real x = real(ps[mid]);\r\n    Real res = min(rec(left, mid), rec(mid, right));\r\
    \n    inplace_merge(ps.begin()+left, ps.begin()+mid, ps.begin()+right, compare_y);\r\
    \n    int ptr = 0;\r\n    for(int i = left; i < right; i++){\r\n      if(abs(real(ps[i])\
    \ - x) >= res) continue;\r\n      for(int j = 0; j < ptr; j++){\r\n        const\
    \ Point luz = ps[i] - beet[ptr - j - 1];\r\n        if(imag(luz) >= res) break;\r\
    \n        res = min(res, abs(luz));\r\n      }\r\n      beet[ptr++] = ps[i];\r\
    \n    }\r\n    return res;\r\n  };\r\n  return rec(0, (int)ps.size());\r\n}\r\n\
    \r\n//a==b\u306E\u5224\u5B9A O(n^3logn)\r\nbool equal(Points a, Points b){\r\n\
    \  const int n = a.size();\r\n  if(n != (int)b.size()) return false;\r\n  if(n\
    \ == 1) return true;\r\n  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){\r\
    \n    if(i == j) continue;\r\n    if(norm(a[1]-a[0]) != norm(b[j]-b[i])) continue;\r\
    \n    auto move = [&](Points p, const Point &o, const Point &r){\r\n      for(int\
    \ i = 0; i < n; i++){\r\n        p[i] -= o;\r\n        p[i] *= r;\r\n      }\r\
    \n      sort(p.begin(), p.end());\r\n      return p;\r\n    };\r\n    vector<Point>\
    \ res_a = move(a, a[0], b[j]-b[i]);\r\n    vector<Point> res_b = move(b, b[i],\
    \ a[1]-a[0]);\r\n    if(res_a == res_b) return true;\r\n  }\r\n  return false;\r\
    \n}\n#line 6 \"test/aoj/CGL/GCL_7_A.test.cpp\"\n\nint main(){\n  Circle a,b;\n\
    \  cin >> a.p >> a.r >> b.p >> b.r;\n  cout << intersect(a, b) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/CGL_7_A\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../geometry/template.hpp\"\
    \n\nint main(){\n  Circle a,b;\n  cin >> a.p >> a.r >> b.p >> b.r;\n  cout <<\
    \ intersect(a, b) << \"\\n\";\n}"
  dependsOn:
  - template/template.hpp
  - geometry/template.hpp
  isVerificationFile: true
  path: test/aoj/CGL/GCL_7_A.test.cpp
  requiredBy: []
  timestamp: '2023-11-11 17:58:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL/GCL_7_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL/GCL_7_A.test.cpp
- /verify/test/aoj/CGL/GCL_7_A.test.cpp.html
title: test/aoj/CGL/GCL_7_A.test.cpp
---
