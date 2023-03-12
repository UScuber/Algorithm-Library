---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/HLD.hpp
    title: data-structure/HLD.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegmentTree/segtree.hpp\"\ntemplate <class T, T(*op)(const\
    \ T&,const T&), T(*e)()>\r\nstruct SegmentTree {\r\n  SegmentTree(const int _n)\
    \ : n(_n){\r\n    while((1 << log) < n) log++;\r\n    len = 1 << log;\r\n    d.resize(len\
    \ * 2, e());\r\n  }\r\n  void update(int k, const T &x){\r\n    assert(0 <= k\
    \ && k < n);\r\n    k += len;\r\n    d[k] = x;\r\n    while(k > 1){\r\n      k\
    \ >>= 1;\r\n      d[k] = op(d[k*2], d[k*2+1]);\r\n    }\r\n  }\r\n  void set(const\
    \ int i, const T &x){\r\n    assert(0 <= i && i < n);\r\n    d[i + len] = x;\r\
    \n  }\r\n  T get(const int i) const{\r\n    assert(0 <= i && i < n);\r\n    return\
    \ d[i + len];\r\n  }\r\n  void build(){\r\n    for(int k = len - 1; k >= 1; k--)\r\
    \n      d[k] = op(d[2*k], d[2*k+1]);\r\n  }\r\n  T query(int l, int r){\r\n  \
    \  assert(0 <= l && l <= r && r <= n);\r\n    l += len; r += len;\r\n    T left\
    \ = e(), right = e();\r\n    while(l < r){\r\n      if(l & 1) left = op(left,\
    \ d[l++]);\r\n      if(r & 1) right = op(d[--r], right);\r\n      l >>= 1; r >>=\
    \ 1;\r\n    }\r\n    return op(left, right);\r\n  }\r\n  private:\r\n  int n =\
    \ 1, log = 0, len = 0;\r\n  vector<T> d;\r\n};\r\n\r\n/*\r\nstruct Data {\r\n\
    \  int a;\r\n};\r\nData op(const Data &a, const Data &b){\r\n  return { min(a.a,\
    \ b.a) };\r\n}\r\nData e(){\r\n  return { 0 };\r\n}\r\n*/\n"
  code: "template <class T, T(*op)(const T&,const T&), T(*e)()>\r\nstruct SegmentTree\
    \ {\r\n  SegmentTree(const int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\
    \n    len = 1 << log;\r\n    d.resize(len * 2, e());\r\n  }\r\n  void update(int\
    \ k, const T &x){\r\n    assert(0 <= k && k < n);\r\n    k += len;\r\n    d[k]\
    \ = x;\r\n    while(k > 1){\r\n      k >>= 1;\r\n      d[k] = op(d[k*2], d[k*2+1]);\r\
    \n    }\r\n  }\r\n  void set(const int i, const T &x){\r\n    assert(0 <= i &&\
    \ i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T get(const int i) const{\r\n   \
    \ assert(0 <= i && i < n);\r\n    return d[i + len];\r\n  }\r\n  void build(){\r\
    \n    for(int k = len - 1; k >= 1; k--)\r\n      d[k] = op(d[2*k], d[2*k+1]);\r\
    \n  }\r\n  T query(int l, int r){\r\n    assert(0 <= l && l <= r && r <= n);\r\
    \n    l += len; r += len;\r\n    T left = e(), right = e();\r\n    while(l < r){\r\
    \n      if(l & 1) left = op(left, d[l++]);\r\n      if(r & 1) right = op(d[--r],\
    \ right);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    return op(left, right);\r\
    \n  }\r\n  private:\r\n  int n = 1, log = 0, len = 0;\r\n  vector<T> d;\r\n};\r\
    \n\r\n/*\r\nstruct Data {\r\n  int a;\r\n};\r\nData op(const Data &a, const Data\
    \ &b){\r\n  return { min(a.a, b.a) };\r\n}\r\nData e(){\r\n  return { 0 };\r\n\
    }\r\n*/"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/segtree.hpp
  requiredBy:
  - data-structure/HLD.hpp
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/segtree.hpp
layout: document
redirect_from:
- /library/SegmentTree/segtree.hpp
- /library/SegmentTree/segtree.hpp.html
title: SegmentTree/segtree.hpp
---
