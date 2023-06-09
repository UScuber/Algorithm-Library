---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/JOI/Planetary-Exploration.test.cpp
    title: test/aoj/JOI/Planetary-Exploration.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/CumulativeSum2D.hpp\"\ntemplate <class T>\r\
    \nstruct CumulativeSum2D {\r\n  CumulativeSum2D(const int h, const int w) : h(h),\
    \ w(w), a(h+1, vector<T>(w+1)){}\r\n  CumulativeSum2D(const vector<vector<T>>\
    \ &v) : h(v.size()), w(v[0].size()), a(h+1, vector<T>(w+1)){\r\n    for(int i\
    \ = 0; i < h; i++)\r\n      for(int j = 0; j < w; j++) a[i + 1][j + 1] = v[i][j];\r\
    \n  }\r\n  void set(const int i, const int j, const T x){\r\n    assert(0 <= i\
    \ && i < h);\r\n    assert(0 <= j && j < w);\r\n    a[i + 1][j + 1] += x;\r\n\
    \  }\r\n  void build(){\r\n    for(int i = 0; i < h; i++)\r\n      for(int j =\
    \ 0; j < w; j++)\r\n        a[i + 1][j + 1] += a[i + 1][j] + a[i][j + 1] - a[i][j];\r\
    \n  }\r\n  T query(const int ly, const int lx, const int ry, const int rx) const{\r\
    \n    assert(0 <= ly && ly <= ry && ry <= h);\r\n    assert(0 <= lx && lx <= rx\
    \ && rx <= w);\r\n    return a[ry][rx] - a[ry][lx] - a[ly][rx] + a[ly][lx];\r\n\
    \  }\r\n  private:\r\n  int h, w;\r\n  vector<vector<T>> a;\r\n};\r\n"
  code: "template <class T>\r\nstruct CumulativeSum2D {\r\n  CumulativeSum2D(const\
    \ int h, const int w) : h(h), w(w), a(h+1, vector<T>(w+1)){}\r\n  CumulativeSum2D(const\
    \ vector<vector<T>> &v) : h(v.size()), w(v[0].size()), a(h+1, vector<T>(w+1)){\r\
    \n    for(int i = 0; i < h; i++)\r\n      for(int j = 0; j < w; j++) a[i + 1][j\
    \ + 1] = v[i][j];\r\n  }\r\n  void set(const int i, const int j, const T x){\r\
    \n    assert(0 <= i && i < h);\r\n    assert(0 <= j && j < w);\r\n    a[i + 1][j\
    \ + 1] += x;\r\n  }\r\n  void build(){\r\n    for(int i = 0; i < h; i++)\r\n \
    \     for(int j = 0; j < w; j++)\r\n        a[i + 1][j + 1] += a[i + 1][j] + a[i][j\
    \ + 1] - a[i][j];\r\n  }\r\n  T query(const int ly, const int lx, const int ry,\
    \ const int rx) const{\r\n    assert(0 <= ly && ly <= ry && ry <= h);\r\n    assert(0\
    \ <= lx && lx <= rx && rx <= w);\r\n    return a[ry][rx] - a[ry][lx] - a[ly][rx]\
    \ + a[ly][lx];\r\n  }\r\n  private:\r\n  int h, w;\r\n  vector<vector<T>> a;\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/CumulativeSum2D.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/JOI/Planetary-Exploration.test.cpp
documentation_of: data-structure/CumulativeSum2D.hpp
layout: document
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---

## 説明

- `CumulativeSum2D<T>(h, w)`: Constructor。$O(HW)$
- `CumulativeSum2D<T>(const vector<vector<T>> &v)`: Constructor。$O(HW)$

- `set(i, j, x)`: 値の加算。$O(1)$

- `build()`: 累積和の構築。$O(HW)$

- `query(ly, lx, ry, rx)`: 長方形内($[ly,ry),[lx,rx)$)の和を取得。$O(1)$
