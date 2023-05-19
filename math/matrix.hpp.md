---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
    title: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Matrix/Inverse-Matrix.test.cpp
    title: test/yosupo/Matrix/Inverse-Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Matrix/Matrix-Product.test.cpp
    title: test/yosupo/Matrix/Matrix-Product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/matrix.hpp\"\ntemplate <class T>\r\nstruct matrix {\r\
    \n  int n,m;\r\n  private:\r\n  vector<vector<T>> a;\r\n  public:\r\n  matrix(const\
    \ int n) : n(n), m(n), a(n, vector<T>(n)){}\r\n  matrix(const int n, const int\
    \ m) : n(n), m(m), a(n, vector<T>(m)){}\r\n  matrix(const vector<vector<T>> &d)\
    \ : a(d), n(d.size()), m(d[0].size()){}\r\n  vector<T> &operator[](const int i){\
    \ return a[i]; }\r\n  matrix &operator*=(const matrix &b){\r\n    assert(m ==\
    \ b.n);\r\n    vector<vector<T>> c(n, vector<T>(b.m));\r\n    for(int i = 0; i\
    \ < n; i++) for(int j = 0; j < m; j++)\r\n    for(int k = 0; k < b.m; k++){\r\n\
    \      c[i][k] += a[i][j] * b.a[j][k];\r\n    }\r\n    a = c;\r\n    return *this;\r\
    \n  }\r\n  matrix &operator+=(const matrix &b){\r\n    assert(n == b.n && m ==\
    \ b.m);\r\n    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)\r\n     \
    \ a[i][j] += b.a[i][j];\r\n    return *this;\r\n  }\r\n  matrix &operator-=(const\
    \ matrix &b){\r\n    assert(n == b.n && m == b.m);\r\n    for(int i = 0; i < n;\
    \ i++) for(int j = 0; j < m; j++)\r\n      a[i][j] -= b.a[i][j];\r\n    return\
    \ *this;\r\n  }\r\n  matrix operator*(const matrix &b) const{ return matrix(*this)\
    \ *= b; }\r\n  matrix operator+(const matrix &b) const{ return matrix(*this) +=\
    \ b; }\r\n  matrix operator-(const matrix &b) const{ return matrix(*this) -= b;\
    \ }\r\n  matrix pow(ll t) const{\r\n    assert(n == m);\r\n    matrix<T> b(n),\
    \ c = *this;\r\n    for(int i = 0; i < n; i++) b[i][i] = 1;\r\n    while(t > 0){\r\
    \n      if(t & 1) b *= c;\r\n      c *= c;\r\n      t >>= 1;\r\n    }\r\n    return\
    \ b;\r\n  }\r\n  T det() const{\r\n    assert(n == m);\r\n    matrix b = *this;\r\
    \n    T res(1);\r\n    bool flip = false;\r\n    for(int i = 0; i < n; i++){\r\
    \n      for(int j = i + 1; j < n; j++){\r\n        while(b[j][i] > 0){\r\n   \
    \       swap(b[i], b[j]);\r\n          flip ^= 1;\r\n          const T d = b[j][i]\
    \ / b[i][i];\r\n          for(int k = i; k < n; k++){\r\n            b[j][k] -=\
    \ b[i][k] * d;\r\n          }\r\n        }\r\n      }\r\n      if(b[i][i] == 0)\
    \ return 0;\r\n      res *= b[i][i];\r\n    }\r\n    if(flip) res = -res;\r\n\
    \    return res;\r\n  }\r\n  matrix inv(){\r\n    assert(n == m);\r\n    matrix\
    \ b(n), c = *this;\r\n    for(int i = 0; i < n; i++) b[i][i] = 1;\r\n    int r\
    \ = 0;\r\n    for(int i = 0; i < n && r < n; i++){\r\n      if(c[r][i] == 0){\r\
    \n        T max_val = 0; int mx_pos;\r\n        for(int j = r+1; j < n; j++){\r\
    \n          if(max_val < c[j][i]) max_val = c[j][i], mx_pos = j;\r\n        }\r\
    \n        if(max_val == 0) return false;\r\n        swap(c[r], c[mx_pos]); swap(b[r],\
    \ b[mx_pos]);\r\n      }     \r\n      T d = T(1) / c[r][i];\r\n      for(int\
    \ j = 0; j < n; j++) c[r][j] *= d, b[r][j] *= d;\r\n      for(int j = 0; j < n;\
    \ j++){\r\n        T v = c[j][i];\r\n        if(j == r || c[j][i] == 0) continue;\r\
    \n        for(int k = 0; k < n; k++){\r\n          c[j][k] -= c[r][k] * v;\r\n\
    \          b[j][k] -= b[r][k] * v;\r\n        }\r\n      }\r\n      r++;\r\n \
    \   }\r\n    return b;\r\n  }\r\n  int size() const{ return n; }\r\n  void debug(){\r\
    \n    for(int i = 0; i < n; i++){\r\n      for(int j = 0; j < n; j++) cerr <<\
    \ a[i][j] << \" \";\r\n      cerr << \"\\n\";\r\n    }\r\n  }\r\n};\n"
  code: "template <class T>\r\nstruct matrix {\r\n  int n,m;\r\n  private:\r\n  vector<vector<T>>\
    \ a;\r\n  public:\r\n  matrix(const int n) : n(n), m(n), a(n, vector<T>(n)){}\r\
    \n  matrix(const int n, const int m) : n(n), m(m), a(n, vector<T>(m)){}\r\n  matrix(const\
    \ vector<vector<T>> &d) : a(d), n(d.size()), m(d[0].size()){}\r\n  vector<T> &operator[](const\
    \ int i){ return a[i]; }\r\n  matrix &operator*=(const matrix &b){\r\n    assert(m\
    \ == b.n);\r\n    vector<vector<T>> c(n, vector<T>(b.m));\r\n    for(int i = 0;\
    \ i < n; i++) for(int j = 0; j < m; j++)\r\n    for(int k = 0; k < b.m; k++){\r\
    \n      c[i][k] += a[i][j] * b.a[j][k];\r\n    }\r\n    a = c;\r\n    return *this;\r\
    \n  }\r\n  matrix &operator+=(const matrix &b){\r\n    assert(n == b.n && m ==\
    \ b.m);\r\n    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)\r\n     \
    \ a[i][j] += b.a[i][j];\r\n    return *this;\r\n  }\r\n  matrix &operator-=(const\
    \ matrix &b){\r\n    assert(n == b.n && m == b.m);\r\n    for(int i = 0; i < n;\
    \ i++) for(int j = 0; j < m; j++)\r\n      a[i][j] -= b.a[i][j];\r\n    return\
    \ *this;\r\n  }\r\n  matrix operator*(const matrix &b) const{ return matrix(*this)\
    \ *= b; }\r\n  matrix operator+(const matrix &b) const{ return matrix(*this) +=\
    \ b; }\r\n  matrix operator-(const matrix &b) const{ return matrix(*this) -= b;\
    \ }\r\n  matrix pow(ll t) const{\r\n    assert(n == m);\r\n    matrix<T> b(n),\
    \ c = *this;\r\n    for(int i = 0; i < n; i++) b[i][i] = 1;\r\n    while(t > 0){\r\
    \n      if(t & 1) b *= c;\r\n      c *= c;\r\n      t >>= 1;\r\n    }\r\n    return\
    \ b;\r\n  }\r\n  T det() const{\r\n    assert(n == m);\r\n    matrix b = *this;\r\
    \n    T res(1);\r\n    bool flip = false;\r\n    for(int i = 0; i < n; i++){\r\
    \n      for(int j = i + 1; j < n; j++){\r\n        while(b[j][i] > 0){\r\n   \
    \       swap(b[i], b[j]);\r\n          flip ^= 1;\r\n          const T d = b[j][i]\
    \ / b[i][i];\r\n          for(int k = i; k < n; k++){\r\n            b[j][k] -=\
    \ b[i][k] * d;\r\n          }\r\n        }\r\n      }\r\n      if(b[i][i] == 0)\
    \ return 0;\r\n      res *= b[i][i];\r\n    }\r\n    if(flip) res = -res;\r\n\
    \    return res;\r\n  }\r\n  matrix inv(){\r\n    assert(n == m);\r\n    matrix\
    \ b(n), c = *this;\r\n    for(int i = 0; i < n; i++) b[i][i] = 1;\r\n    int r\
    \ = 0;\r\n    for(int i = 0; i < n && r < n; i++){\r\n      if(c[r][i] == 0){\r\
    \n        T max_val = 0; int mx_pos;\r\n        for(int j = r+1; j < n; j++){\r\
    \n          if(max_val < c[j][i]) max_val = c[j][i], mx_pos = j;\r\n        }\r\
    \n        if(max_val == 0) return false;\r\n        swap(c[r], c[mx_pos]); swap(b[r],\
    \ b[mx_pos]);\r\n      }     \r\n      T d = T(1) / c[r][i];\r\n      for(int\
    \ j = 0; j < n; j++) c[r][j] *= d, b[r][j] *= d;\r\n      for(int j = 0; j < n;\
    \ j++){\r\n        T v = c[j][i];\r\n        if(j == r || c[j][i] == 0) continue;\r\
    \n        for(int k = 0; k < n; k++){\r\n          c[j][k] -= c[r][k] * v;\r\n\
    \          b[j][k] -= b[r][k] * v;\r\n        }\r\n      }\r\n      r++;\r\n \
    \   }\r\n    return b;\r\n  }\r\n  int size() const{ return n; }\r\n  void debug(){\r\
    \n    for(int i = 0; i < n; i++){\r\n      for(int j = 0; j < n; j++) cerr <<\
    \ a[i][j] << \" \";\r\n      cerr << \"\\n\";\r\n    }\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Matrix/Matrix-Product.test.cpp
  - test/yosupo/Matrix/Inverse-Matrix.test.cpp
  - test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
