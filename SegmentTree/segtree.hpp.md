---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/hld.cpp
    title: data-structure/hld.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegmentTree/segtree.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class T, T(*op)(const T&,const T&), T(*e)()>\nstruct\
    \ SegmentTree {\n  SegmentTree(const int _n) : n(_n){\n    while((1 << log) <\
    \ n) log++;\n    len = 1 << log;\n    d.resize(len * 2, e());\n  }\n  void update(int\
    \ k, const T &x){\n    assert(0 <= k && k < n);\n    k += len;\n    d[k] = x;\n\
    \    while(k > 1){\n      k >>= 1;\n      d[k] = op(d[k*2], d[k*2+1]);\n    }\n\
    \  }\n  void set(const int i, const T &x){\n    assert(0 <= i && i < n);\n   \
    \ d[i + len] = x;\n  }\n  T get(const int i) const{\n    assert(0 <= i && i <\
    \ n);\n    return d[i + len];\n  }\n  void build(){\n    for(int k = len - 1;\
    \ k >= 1; k--)\n      d[k] = op(d[2*k], d[2*k+1]);\n  }\n  T query(int l, int\
    \ r){\n    assert(0 <= l && l <= r && r <= n);\n    l += len; r += len;\n    T\
    \ left = e(), right = e();\n    while(l < r){\n      if(l & 1) left = op(left,\
    \ d[l++]);\n      if(r & 1) right = op(d[--r], right);\n      l >>= 1; r >>= 1;\n\
    \    }\n    return op(left, right);\n  }\n  private:\n  int n = 1, log = 0, len\
    \ = 0;\n  vector<T> d;\n};\n\n/*\nstruct Data {\n  int a;\n};\nData op(const Data\
    \ &a, const Data &b){\n  return { min(a.a, b.a) };\n}\nData e(){\n  return { 0\
    \ };\n}\n*/\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T, T(*op)(const\
    \ T&,const T&), T(*e)()>\nstruct SegmentTree {\n  SegmentTree(const int _n) :\
    \ n(_n){\n    while((1 << log) < n) log++;\n    len = 1 << log;\n    d.resize(len\
    \ * 2, e());\n  }\n  void update(int k, const T &x){\n    assert(0 <= k && k <\
    \ n);\n    k += len;\n    d[k] = x;\n    while(k > 1){\n      k >>= 1;\n     \
    \ d[k] = op(d[k*2], d[k*2+1]);\n    }\n  }\n  void set(const int i, const T &x){\n\
    \    assert(0 <= i && i < n);\n    d[i + len] = x;\n  }\n  T get(const int i)\
    \ const{\n    assert(0 <= i && i < n);\n    return d[i + len];\n  }\n  void build(){\n\
    \    for(int k = len - 1; k >= 1; k--)\n      d[k] = op(d[2*k], d[2*k+1]);\n \
    \ }\n  T query(int l, int r){\n    assert(0 <= l && l <= r && r <= n);\n    l\
    \ += len; r += len;\n    T left = e(), right = e();\n    while(l < r){\n     \
    \ if(l & 1) left = op(left, d[l++]);\n      if(r & 1) right = op(d[--r], right);\n\
    \      l >>= 1; r >>= 1;\n    }\n    return op(left, right);\n  }\n  private:\n\
    \  int n = 1, log = 0, len = 0;\n  vector<T> d;\n};\n\n/*\nstruct Data {\n  int\
    \ a;\n};\nData op(const Data &a, const Data &b){\n  return { min(a.a, b.a) };\n\
    }\nData e(){\n  return { 0 };\n}\n*/"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/segtree.hpp
  requiredBy:
  - data-structure/hld.cpp
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/segtree.hpp
layout: document
redirect_from:
- /library/SegmentTree/segtree.hpp
- /library/SegmentTree/segtree.hpp.html
title: SegmentTree/segtree.hpp
---
