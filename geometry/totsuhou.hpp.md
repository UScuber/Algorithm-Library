---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/template.hpp\"\n#include <complex>\r\n#line 1 \"\
    template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\n#include <string>\r\
    \n#include <vector>\r\n#include <algorithm>\r\n#include <utility>\r\n#include\
    \ <tuple>\r\n#include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\n#include\
    \ <queue>\r\n#include <set>\r\n#include <stack>\r\n#include <deque>\r\n#include\
    \ <unordered_map>\r\n#include <unordered_set>\r\n#include <bitset>\r\n#include\
    \ <cctype>\r\n#include <climits>\r\n#include <functional>\r\n#include <cassert>\r\
    \n#include <numeric>\r\n#define rep(i, n) for(int i = 0; i < (n); i++)\r\n#define\
    \ per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\nusing ll = long long;\r\n#define\
    \ vi vector<int>\r\n#define vvi vector<vi>\r\n#define vl vector<ll>\r\n#define\
    \ pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define all(a) (a).begin(),\
    \ (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\nconstexpr int mod =\
    \ 1000000007;\r\nusing namespace std;\r\ntemplate<class T, class U>\r\nbool chmax(T\
    \ &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\ntemplate<class T, class\
    \ U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }\n#line\
    \ 3 \"geometry/template.hpp\"\n\r\nusing Point = complex<double>;\r\nconstexpr\
    \ double EPS = 1e-8;\r\nconst double PI = acos(-1);\r\nconstexpr double INF =\
    \ 1e10;\r\n\r\nbool eq(const double &a, const double &b){\r\n  return fabs(b -\
    \ a) < EPS;\r\n}\r\nPoint operator*(const Point &a, const double &b){\r\n  return\
    \ Point(a.real() * b, a.imag() * b);\r\n}\r\nistream &operator>>(istream &is,\
    \ Point &p){\r\n  double a,b;\r\n  is >> a >> b;\r\n  p = Point(a, b);\r\n  return\
    \ is;\r\n}\r\nostream &operator<<(ostream &os, Point &p){\r\n  return os << p.real()\
    \ << \" \" << p.imag();\r\n}\r\nnamespace std {\r\n  bool operator<(const Point\
    \ &a, const Point &b){\r\n    if(a.real() != b.real()) return a.real() < b.real();\r\
    \n    return a.imag() < b.imag();\r\n  }\r\n};\r\ndouble cross(const Point &a,\
    \ const Point &b){\r\n  return a.real() * b.imag() - a.imag() * b.real();\r\n\
    }\r\ndouble dot(const Point &a, const Point &b){\r\n  return a.real() * b.real()\
    \ + a.imag() * b.imag();\r\n}\r\n\r\n//\u76F4\u7DDA\r\nstruct Line {\r\n  Point\
    \ a,b;\r\n  Line(){}\r\n  Line(Point a, Point b) : a(a), b(b){}\r\n};\r\n\r\n\
    //\u7DDA\u5206\r\nstruct Segment : Line {\r\n  Segment(){}\r\n  Segment(Point\
    \ a, Point b) : Line(a,b){}\r\n  Segment(Line a) : Line(a){}\r\n};\r\n\r\n//\u5186\
    \r\nstruct Circle {\r\n  Point p;\r\n  double r;\r\n  Circle(){};\r\n  Circle(Point\
    \ p, double r) : p(p), r(r){}\r\n};\n#line 2 \"geometry/totsuhou.hpp\"\n\r\nvector<Point>\
    \ totsuhou(const vector<Point> &pos){\r\n  int n = pos.size();\r\n  vector<Point>\
    \ g(2 * n);\r\n  int k = 0;\r\n  for(int i = 0; i < n; i++){\r\n    while(k >\
    \ 1 && cross(g[k-1] - g[k-2], pos[i] - g[k-1]) <= 0) k--;\r\n    g[k++] = pos[i];\r\
    \n  }\r\n  for(int i = n - 2, t = k; i >= 0; i--){\r\n    while(k > t && cross(g[k-1]\
    \ - g[k-2], pos[i] - g[k-1]) <= 0) k--;\r\n    g[k++] = pos[i];\r\n  }\r\n  g.resize(--k);\r\
    \n  return g;\r\n}\n"
  code: "#include \"template.hpp\"\r\n\r\nvector<Point> totsuhou(const vector<Point>\
    \ &pos){\r\n  int n = pos.size();\r\n  vector<Point> g(2 * n);\r\n  int k = 0;\r\
    \n  for(int i = 0; i < n; i++){\r\n    while(k > 1 && cross(g[k-1] - g[k-2], pos[i]\
    \ - g[k-1]) <= 0) k--;\r\n    g[k++] = pos[i];\r\n  }\r\n  for(int i = n - 2,\
    \ t = k; i >= 0; i--){\r\n    while(k > t && cross(g[k-1] - g[k-2], pos[i] - g[k-1])\
    \ <= 0) k--;\r\n    g[k++] = pos[i];\r\n  }\r\n  g.resize(--k);\r\n  return g;\r\
    \n}"
  dependsOn:
  - geometry/template.hpp
  - template/template.hpp
  isVerificationFile: false
  path: geometry/totsuhou.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/totsuhou.hpp
layout: document
redirect_from:
- /library/geometry/totsuhou.hpp
- /library/geometry/totsuhou.hpp.html
title: geometry/totsuhou.hpp
---
