---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Static-RMQ.test.cpp
    title: test/yosupo/Data-Structure/Static-RMQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/SparseTable.hpp\"\ntemplate <class T, const\
    \ T&(*op)(const T&,const T&)>\r\nstruct SparseTable {\r\n  int n;\r\n  vector<T>\
    \ a;\r\n  private:\r\n  vector<vector<T>> d;\r\n  vector<int> len;\r\n  T inf\
    \ = numeric_limits<T>::max();\r\n  public:\r\n  SparseTable(const int n) : n(n),\
    \ a(n), len(n + 1){}\r\n  SparseTable(const vector<T> &a) : a(a), n(a.size()),\
    \ len(a.size() + 1){}\r\n  T &operator[](const int i){ return a[i]; }\r\n  void\
    \ build(){\r\n    inf = -op(inf, -inf);\r\n    int logn = 0;\r\n    while((1 <<\
    \ logn) < n) logn++;\r\n    d.resize(logn + 1, vector<T>(n, inf));\r\n    d[0]\
    \ = a;\r\n    for(int i = 0; i < logn; i++){\r\n      for(int j = 0; j <= n -\
    \ (1 << i); j++){\r\n        d[i + 1][j] = op(d[i][j], d[i][j + (1 << i)]);\r\n\
    \      }\r\n    }\r\n    for(int i = 2; i <= n; i++) len[i] = len[i >> 1] + 1;\r\
    \n  }\r\n  T query(const int l, const int r) const{\r\n    assert(0 <= l && l\
    \ <= r && r <= n);\r\n    if(l == r) return inf;\r\n    const int range = len[r\
    \ - l];\r\n    assert(0 <= range && range < d.size());\r\n    return op(d[range][l],\
    \ d[range][r - (1 << range)]);\r\n  }\r\n};\n"
  code: "template <class T, const T&(*op)(const T&,const T&)>\r\nstruct SparseTable\
    \ {\r\n  int n;\r\n  vector<T> a;\r\n  private:\r\n  vector<vector<T>> d;\r\n\
    \  vector<int> len;\r\n  T inf = numeric_limits<T>::max();\r\n  public:\r\n  SparseTable(const\
    \ int n) : n(n), a(n), len(n + 1){}\r\n  SparseTable(const vector<T> &a) : a(a),\
    \ n(a.size()), len(a.size() + 1){}\r\n  T &operator[](const int i){ return a[i];\
    \ }\r\n  void build(){\r\n    inf = -op(inf, -inf);\r\n    int logn = 0;\r\n \
    \   while((1 << logn) < n) logn++;\r\n    d.resize(logn + 1, vector<T>(n, inf));\r\
    \n    d[0] = a;\r\n    for(int i = 0; i < logn; i++){\r\n      for(int j = 0;\
    \ j <= n - (1 << i); j++){\r\n        d[i + 1][j] = op(d[i][j], d[i][j + (1 <<\
    \ i)]);\r\n      }\r\n    }\r\n    for(int i = 2; i <= n; i++) len[i] = len[i\
    \ >> 1] + 1;\r\n  }\r\n  T query(const int l, const int r) const{\r\n    assert(0\
    \ <= l && l <= r && r <= n);\r\n    if(l == r) return inf;\r\n    const int range\
    \ = len[r - l];\r\n    assert(0 <= range && range < d.size());\r\n    return op(d[range][l],\
    \ d[range][r - (1 << range)]);\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/SparseTable.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Data-Structure/Static-RMQ.test.cpp
documentation_of: data-structure/SparseTable.hpp
layout: document
redirect_from:
- /library/data-structure/SparseTable.hpp
- /library/data-structure/SparseTable.hpp.html
title: data-structure/SparseTable.hpp
---
