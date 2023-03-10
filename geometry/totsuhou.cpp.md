---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/totsuhou.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"geometry/template.hpp\"\nusing namespace std;\n\nusing Point = complex<double>;\n\
    constexpr double EPS = 1e-8;\nconst double PI = acos(-1);\nconstexpr double INF\
    \ = 1e10;\n\nbool eq(const double &a, const double &b){\n  return fabs(b - a)\
    \ < EPS;\n}\nPoint operator*(const Point &a, const double &b){\n  return Point(a.real()\
    \ * b, a.imag() * b);\n}\nistream &operator>>(istream &is, Point &p){\n  double\
    \ a,b;\n  is >> a >> b;\n  p = Point(a, b);\n  return is;\n}\nostream &operator<<(ostream\
    \ &os, Point &p){\n  return os << p.real() << \" \" << p.imag();\n}\nnamespace\
    \ std {\n  bool operator<(const Point &a, const Point &b){\n    if(a.real() !=\
    \ b.real()) return a.real() < b.real();\n    return a.imag() < b.imag();\n  }\n\
    };\ndouble cross(const Point &a, const Point &b){\n  return a.real() * b.imag()\
    \ - a.imag() * b.real();\n}\ndouble dot(const Point &a, const Point &b){\n  return\
    \ a.real() * b.real() + a.imag() * b.imag();\n}\n\n//\u76F4\u7DDA\nstruct Line\
    \ {\n  Point a,b;\n  Line(){}\n  Line(Point a, Point b) : a(a), b(b){}\n};\n\n\
    //\u7DDA\u5206\nstruct Segment : Line {\n  Segment(){}\n  Segment(Point a, Point\
    \ b) : Line(a,b){}\n  Segment(Line a) : Line(a){}\n};\n\n//\u5186\nstruct Circle\
    \ {\n  Point p;\n  double r;\n  Circle(){};\n  Circle(Point p, double r) : p(p),\
    \ r(r){}\n};\n#line 3 \"geometry/totsuhou.cpp\"\nusing namespace std;\n\nvector<Point>\
    \ totsuhou(const vector<Point> &pos){\n  int n = pos.size();\n  vector<Point>\
    \ g(2 * n);\n  int k = 0;\n  for(int i = 0; i < n; i++){\n    while(k > 1 && cross(g[k-1]\
    \ - g[k-2], pos[i] - g[k-1]) <= 0) k--;\n    g[k++] = pos[i];\n  }\n  for(int\
    \ i = n - 2, t = k; i >= 0; i--){\n    while(k > t && cross(g[k-1] - g[k-2], pos[i]\
    \ - g[k-1]) <= 0) k--;\n    g[k++] = pos[i];\n  }\n  g.resize(--k);\n  return\
    \ g;\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"template.hpp\"\nusing namespace std;\n\
    \nvector<Point> totsuhou(const vector<Point> &pos){\n  int n = pos.size();\n \
    \ vector<Point> g(2 * n);\n  int k = 0;\n  for(int i = 0; i < n; i++){\n    while(k\
    \ > 1 && cross(g[k-1] - g[k-2], pos[i] - g[k-1]) <= 0) k--;\n    g[k++] = pos[i];\n\
    \  }\n  for(int i = n - 2, t = k; i >= 0; i--){\n    while(k > t && cross(g[k-1]\
    \ - g[k-2], pos[i] - g[k-1]) <= 0) k--;\n    g[k++] = pos[i];\n  }\n  g.resize(--k);\n\
    \  return g;\n}"
  dependsOn:
  - geometry/template.hpp
  isVerificationFile: false
  path: geometry/totsuhou.cpp
  requiredBy: []
  timestamp: '2022-01-28 17:27:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/totsuhou.cpp
layout: document
redirect_from:
- /library/geometry/totsuhou.cpp
- /library/geometry/totsuhou.cpp.html
title: geometry/totsuhou.cpp
---
