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
  bundledCode: "#line 1 \"data-structure/SparseTable.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T, const T&(*op)(const T&,const T&)>\n\
    struct SparseTable {\n  int n;\n  vector<T> a;\n  private:\n  vector<vector<T>>\
    \ d;\n  vector<int> len;\n  T inf = numeric_limits<T>::max();\n  public:\n  SparseTable(const\
    \ int n) : n(n), a(n), len(n + 1){}\n  SparseTable(const vector<T> &a) : a(a),\
    \ n(a.size()), len(a.size() + 1){}\n  T &operator[](const int i){ return a[i];\
    \ }\n  void build(){\n    inf = -op(inf, -inf);\n    int logn = 0;\n    while((1\
    \ << logn) < n) logn++;\n    d.resize(logn + 1, vector<T>(n, inf));\n    d[0]\
    \ = a;\n    for(int i = 0; i < logn; i++){\n      for(int j = 0; j <= n - (1 <<\
    \ i); j++){\n        d[i + 1][j] = op(d[i][j], d[i][j + (1 << i)]);\n      }\n\
    \    }\n    for(int i = 2; i <= n; i++) len[i] = len[i >> 1] + 1;\n  }\n  T query(const\
    \ int l, const int r) const{\n    assert(0 <= l && l <= r && r <= n);\n    if(l\
    \ == r) return inf;\n    const int range = len[r - l];\n    assert(0 <= range\
    \ && range < d.size());\n    return op(d[range][l], d[range][r - (1 << range)]);\n\
    \  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T, const\
    \ T&(*op)(const T&,const T&)>\nstruct SparseTable {\n  int n;\n  vector<T> a;\n\
    \  private:\n  vector<vector<T>> d;\n  vector<int> len;\n  T inf = numeric_limits<T>::max();\n\
    \  public:\n  SparseTable(const int n) : n(n), a(n), len(n + 1){}\n  SparseTable(const\
    \ vector<T> &a) : a(a), n(a.size()), len(a.size() + 1){}\n  T &operator[](const\
    \ int i){ return a[i]; }\n  void build(){\n    inf = -op(inf, -inf);\n    int\
    \ logn = 0;\n    while((1 << logn) < n) logn++;\n    d.resize(logn + 1, vector<T>(n,\
    \ inf));\n    d[0] = a;\n    for(int i = 0; i < logn; i++){\n      for(int j =\
    \ 0; j <= n - (1 << i); j++){\n        d[i + 1][j] = op(d[i][j], d[i][j + (1 <<\
    \ i)]);\n      }\n    }\n    for(int i = 2; i <= n; i++) len[i] = len[i >> 1]\
    \ + 1;\n  }\n  T query(const int l, const int r) const{\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    if(l == r) return inf;\n    const int range = len[r\
    \ - l];\n    assert(0 <= range && range < d.size());\n    return op(d[range][l],\
    \ d[range][r - (1 << range)]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/SparseTable.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/SparseTable.cpp
layout: document
redirect_from:
- /library/data-structure/SparseTable.cpp
- /library/data-structure/SparseTable.cpp.html
title: data-structure/SparseTable.cpp
---
