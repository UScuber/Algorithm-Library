---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/CumulativeSum2D.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T>\nstruct CumulativeSum2D {\n  CumulativeSum2D(const\
    \ int h, const int w) : h(h), w(w), a(h+1, vector<T>(w+1)){}\n  CumulativeSum2D(const\
    \ vector<vector<T>> &v) : h(v.size()), w(v[0].size()), a(h+1, vector<T>(w+1)){\n\
    \    for(int i = 0; i < h; i++)\n      for(int j = 0; j < w; j++) a[i + 1][j +\
    \ 1] = v[i][j];\n  }\n  void set(const int i, const int j, const T x){\n    assert(0\
    \ <= i && i < h);\n    assert(0 <= j && j < w);\n    a[i + 1][j + 1] += x;\n \
    \ }\n  void build(){\n    for(int i = 0; i < h; i++)\n      for(int j = 0; j <\
    \ w; j++)\n        a[i + 1][j + 1] += a[i + 1][j] + a[i][j + 1] - a[i][j];\n \
    \ }\n  T query(const int ly, const int lx, const int ry, const int rx) const{\n\
    \    assert(0 <= ly && ly <= ry && ry <= h);\n    assert(0 <= lx && lx <= rx &&\
    \ rx <= w);\n    return a[ry][rx] - a[ry][lx] - a[ly][rx] + a[ly][lx];\n  }\n\
    \  private:\n  int h, w;\n  vector<vector<T>> a;\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ CumulativeSum2D {\n  CumulativeSum2D(const int h, const int w) : h(h), w(w),\
    \ a(h+1, vector<T>(w+1)){}\n  CumulativeSum2D(const vector<vector<T>> &v) : h(v.size()),\
    \ w(v[0].size()), a(h+1, vector<T>(w+1)){\n    for(int i = 0; i < h; i++)\n  \
    \    for(int j = 0; j < w; j++) a[i + 1][j + 1] = v[i][j];\n  }\n  void set(const\
    \ int i, const int j, const T x){\n    assert(0 <= i && i < h);\n    assert(0\
    \ <= j && j < w);\n    a[i + 1][j + 1] += x;\n  }\n  void build(){\n    for(int\
    \ i = 0; i < h; i++)\n      for(int j = 0; j < w; j++)\n        a[i + 1][j + 1]\
    \ += a[i + 1][j] + a[i][j + 1] - a[i][j];\n  }\n  T query(const int ly, const\
    \ int lx, const int ry, const int rx) const{\n    assert(0 <= ly && ly <= ry &&\
    \ ry <= h);\n    assert(0 <= lx && lx <= rx && rx <= w);\n    return a[ry][rx]\
    \ - a[ry][lx] - a[ly][rx] + a[ly][lx];\n  }\n  private:\n  int h, w;\n  vector<vector<T>>\
    \ a;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/CumulativeSum2D.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/CumulativeSum2D.cpp
layout: document
redirect_from:
- /library/data-structure/CumulativeSum2D.cpp
- /library/data-structure/CumulativeSum2D.cpp.html
title: data-structure/CumulativeSum2D.cpp
---
