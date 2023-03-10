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
  bundledCode: "#line 1 \"math/matrix.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T>\nstruct matrix {\n  int n,m;\n  private:\n  vector<vector<T>>\
    \ a;\n  public:\n  matrix(const int n) : n(n), m(n), a(n, vector<T>(n)){}\n  matrix(const\
    \ int n, const int m) : n(n), m(m), a(n, vector<T>(m)){}\n  matrix(const vector<vector<T>>\
    \ &d) : a(d), n(d.size()), m(d[0].size()){}\n  vector<T> &operator[](const int\
    \ i){ return a[i]; }\n  matrix &operator*=(const matrix &b){\n    assert(m ==\
    \ b.n);\n    vector<vector<T>> c(n, vector<T>(b.m));\n    for(int i = 0; i < n;\
    \ i++) for(int j = 0; j < m; j++)\n    for(int k = 0; k < b.m; k++){\n      c[i][k]\
    \ += a[i][j] * b.a[j][k];\n    }\n    a = c;\n    return *this;\n  }\n  matrix\
    \ &operator+=(const matrix &b){\n    assert(n == b.n && m == b.m);\n    for(int\
    \ i = 0; i < n; i++) for(int j = 0; j < m; j++)\n      a[i][j] += b.a[i][j];\n\
    \    return *this;\n  }\n  matrix &operator-=(const matrix &b){\n    assert(n\
    \ == b.n && m == b.m);\n    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)\n\
    \      a[i][j] -= b.a[i][j];\n    return *this;\n  }\n  matrix operator*(const\
    \ matrix &b) const{ return matrix(*this) *= b; }\n  matrix operator+(const matrix\
    \ &b) const{ return matrix(*this) += b; }\n  matrix operator-(const matrix &b)\
    \ const{ return matrix(*this) -= b; }\n  matrix pow(ll t) const{\n    assert(n\
    \ == m);\n    matrix<T> b(n), c = *this;\n    for(int i = 0; i < n; i++) b[i][i]\
    \ = 1;\n    while(t > 0){\n      if(t & 1) b *= c;\n      c *= c;\n      t >>=\
    \ 1;\n    }\n    return b;\n  }\n  T det() const{\n    assert(n == m);\n    matrix\
    \ b = *this;\n    T res(1);\n    bool flip = false;\n    for(int i = 0; i < n;\
    \ i++){\n      for(int j = i + 1; j < n; j++){\n        while(b[j][i] > 0){\n\
    \          swap(b[i], b[j]);\n          flip ^= 1;\n          const T d = b[j][i]\
    \ / b[i][i];\n          for(int k = i; k < n; k++){\n            b[j][k] -= b[i][k]\
    \ * d;\n          }\n        }\n      }\n      if(b[i][i] == 0) return 0;\n  \
    \    res *= b[i][i];\n    }\n    if(flip) res = -res;\n    return res;\n  }\n\
    \  matrix inv(){\n    assert(n == m);\n    matrix b(n), c = *this;\n    for(int\
    \ i = 0; i < n; i++) b[i][i] = 1;\n    int r = 0;\n    for(int i = 0; i < n &&\
    \ r < n; i++){\n      if(c[r][i] == 0){\n        T max_val = 0; int mx_pos;\n\
    \        for(int j = r+1; j < n; j++){\n          if(max_val < c[j][i]) max_val\
    \ = c[j][i], mx_pos = j;\n        }\n        if(max_val == 0) return false;\n\
    \        swap(c[r], c[mx_pos]); swap(b[r], b[mx_pos]);\n      }     \n      T\
    \ d = T(1) / c[r][i];\n      for(int j = 0; j < n; j++) c[r][j] *= d, b[r][j]\
    \ *= d;\n      for(int j = 0; j < n; j++){\n        T v = c[j][i];\n        if(j\
    \ == r || c[j][i] == 0) continue;\n        for(int k = 0; k < n; k++){\n     \
    \     c[j][k] -= c[r][k] * v;\n          b[j][k] -= b[r][k] * v;\n        }\n\
    \      }\n      r++;\n    }\n    return b;\n  }\n  int size() const{ return n;\
    \ }\n  void debug(){\n    for(int i = 0; i < n; i++){\n      for(int j = 0; j\
    \ < n; j++) cerr << a[i][j] << \" \";\n      cerr << \"\\n\";\n    }\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ matrix {\n  int n,m;\n  private:\n  vector<vector<T>> a;\n  public:\n  matrix(const\
    \ int n) : n(n), m(n), a(n, vector<T>(n)){}\n  matrix(const int n, const int m)\
    \ : n(n), m(m), a(n, vector<T>(m)){}\n  matrix(const vector<vector<T>> &d) : a(d),\
    \ n(d.size()), m(d[0].size()){}\n  vector<T> &operator[](const int i){ return\
    \ a[i]; }\n  matrix &operator*=(const matrix &b){\n    assert(m == b.n);\n   \
    \ vector<vector<T>> c(n, vector<T>(b.m));\n    for(int i = 0; i < n; i++) for(int\
    \ j = 0; j < m; j++)\n    for(int k = 0; k < b.m; k++){\n      c[i][k] += a[i][j]\
    \ * b.a[j][k];\n    }\n    a = c;\n    return *this;\n  }\n  matrix &operator+=(const\
    \ matrix &b){\n    assert(n == b.n && m == b.m);\n    for(int i = 0; i < n; i++)\
    \ for(int j = 0; j < m; j++)\n      a[i][j] += b.a[i][j];\n    return *this;\n\
    \  }\n  matrix &operator-=(const matrix &b){\n    assert(n == b.n && m == b.m);\n\
    \    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)\n      a[i][j] -= b.a[i][j];\n\
    \    return *this;\n  }\n  matrix operator*(const matrix &b) const{ return matrix(*this)\
    \ *= b; }\n  matrix operator+(const matrix &b) const{ return matrix(*this) +=\
    \ b; }\n  matrix operator-(const matrix &b) const{ return matrix(*this) -= b;\
    \ }\n  matrix pow(ll t) const{\n    assert(n == m);\n    matrix<T> b(n), c = *this;\n\
    \    for(int i = 0; i < n; i++) b[i][i] = 1;\n    while(t > 0){\n      if(t &\
    \ 1) b *= c;\n      c *= c;\n      t >>= 1;\n    }\n    return b;\n  }\n  T det()\
    \ const{\n    assert(n == m);\n    matrix b = *this;\n    T res(1);\n    bool\
    \ flip = false;\n    for(int i = 0; i < n; i++){\n      for(int j = i + 1; j <\
    \ n; j++){\n        while(b[j][i] > 0){\n          swap(b[i], b[j]);\n       \
    \   flip ^= 1;\n          const T d = b[j][i] / b[i][i];\n          for(int k\
    \ = i; k < n; k++){\n            b[j][k] -= b[i][k] * d;\n          }\n      \
    \  }\n      }\n      if(b[i][i] == 0) return 0;\n      res *= b[i][i];\n    }\n\
    \    if(flip) res = -res;\n    return res;\n  }\n  matrix inv(){\n    assert(n\
    \ == m);\n    matrix b(n), c = *this;\n    for(int i = 0; i < n; i++) b[i][i]\
    \ = 1;\n    int r = 0;\n    for(int i = 0; i < n && r < n; i++){\n      if(c[r][i]\
    \ == 0){\n        T max_val = 0; int mx_pos;\n        for(int j = r+1; j < n;\
    \ j++){\n          if(max_val < c[j][i]) max_val = c[j][i], mx_pos = j;\n    \
    \    }\n        if(max_val == 0) return false;\n        swap(c[r], c[mx_pos]);\
    \ swap(b[r], b[mx_pos]);\n      }     \n      T d = T(1) / c[r][i];\n      for(int\
    \ j = 0; j < n; j++) c[r][j] *= d, b[r][j] *= d;\n      for(int j = 0; j < n;\
    \ j++){\n        T v = c[j][i];\n        if(j == r || c[j][i] == 0) continue;\n\
    \        for(int k = 0; k < n; k++){\n          c[j][k] -= c[r][k] * v;\n    \
    \      b[j][k] -= b[r][k] * v;\n        }\n      }\n      r++;\n    }\n    return\
    \ b;\n  }\n  int size() const{ return n; }\n  void debug(){\n    for(int i = 0;\
    \ i < n; i++){\n      for(int j = 0; j < n; j++) cerr << a[i][j] << \" \";\n \
    \     cerr << \"\\n\";\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.cpp
layout: document
redirect_from:
- /library/math/matrix.cpp
- /library/math/matrix.cpp.html
title: math/matrix.cpp
---
