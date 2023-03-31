---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_A.test.cpp
    title: test/aoj/DSL/DSL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegmentTree/seg-rmin.hpp\"\ntemplate<class T, const T&(*op)(const\
    \ T&,const T&)>\r\nstruct SegmentTree {\r\n  SegmentTree(const int _n) : n(_n){\r\
    \n    while((1 << log) < n) log++;\r\n    len = 1 << log;\r\n    d.assign(len\
    \ * 2, inf);\r\n  }\r\n  void update(int k, const T &x){\r\n    assert(0 <= k\
    \ && k < n);\r\n    k += len;\r\n    d[k] = x;\r\n    while(k > 1){\r\n      k\
    \ >>= 1;\r\n      d[k] = op(d[k*2], d[k*2+1]);\r\n    }\r\n  }\r\n  void set(const\
    \ int i, const T &x){\r\n    assert(0 <= i && i < n);\r\n    d[i + len] = x;\r\
    \n  }\r\n  T get(const int i) const{\r\n    assert(0 <= i && i < n);\r\n    return\
    \ d[i + len];\r\n  }\r\n  void build(){\r\n    for(int k = len - 1; k >= 1; k--)\
    \ d[k] = op(d[2*k], d[2*k+1]);\r\n  }\r\n  T query(int l, int r){\r\n    assert(0\
    \ <= l && l <= r && r <= n);\r\n    l += len; r += len;\r\n    T left = inf, right\
    \ = inf;\r\n    while(l < r){\r\n      if(l & 1) left = op(left, d[l++]);\r\n\
    \      if(r & 1) right = op(d[--r], right);\r\n      l >>= 1; r >>= 1;\r\n   \
    \ }\r\n    return op(left, right);\r\n  }\r\n  template <class F>\r\n  int max_right(int\
    \ l, F f) const{\r\n    assert(0 <= l && l <= n);\r\n    assert(f(inf));\r\n \
    \   if(l == n) return n;\r\n    l += len;\r\n    T sm = inf;\r\n    do {\r\n \
    \     l /= l & -l;\r\n      if(!f(op(sm, d[l]))){\r\n        while(l < len){\r\
    \n          l <<= 1;\r\n          if(f(op(sm, d[l]))){\r\n            sm = op(sm,\
    \ d[l]);\r\n            l++;\r\n          }\r\n        }\r\n        return l -\
    \ len;\r\n      }\r\n      sm = op(sm, d[l]);\r\n      l++;\r\n    }while(l &\
    \ (l - 1));\r\n    return n;\r\n  }\r\n  template <class F>\r\n  int min_left(int\
    \ r, F f) const{\r\n    assert(0 <= r && r <= n);\r\n    assert(f(inf));\r\n \
    \   if(r == 0) return 0;\r\n    r += len;\r\n    T sm = inf;\r\n    do {\r\n \
    \     r /= r & -r;\r\n      if(r > 1) r--;\r\n      if(!f(op(d[r], sm))){\r\n\
    \        while(r < len){\r\n          r = r * 2 + 1;\r\n          if(f(op(d[r],\
    \ sm))){\r\n            sm = op(d[r], sm);\r\n            r--;\r\n          }\r\
    \n        }\r\n        return r + 1 - len;\r\n      }\r\n      sm = op(d[r], sm);\r\
    \n    }while(r & (r - 1));\r\n    return 0;\r\n  }\r\n  private:\r\n  const T\
    \ inf = -op(numeric_limits<T>::max(), -numeric_limits<T>::max());\r\n  int n =\
    \ 1, log = 0, len = 0;\r\n  vector<T> d;\r\n};\n"
  code: "template<class T, const T&(*op)(const T&,const T&)>\r\nstruct SegmentTree\
    \ {\r\n  SegmentTree(const int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\
    \n    len = 1 << log;\r\n    d.assign(len * 2, inf);\r\n  }\r\n  void update(int\
    \ k, const T &x){\r\n    assert(0 <= k && k < n);\r\n    k += len;\r\n    d[k]\
    \ = x;\r\n    while(k > 1){\r\n      k >>= 1;\r\n      d[k] = op(d[k*2], d[k*2+1]);\r\
    \n    }\r\n  }\r\n  void set(const int i, const T &x){\r\n    assert(0 <= i &&\
    \ i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T get(const int i) const{\r\n   \
    \ assert(0 <= i && i < n);\r\n    return d[i + len];\r\n  }\r\n  void build(){\r\
    \n    for(int k = len - 1; k >= 1; k--) d[k] = op(d[2*k], d[2*k+1]);\r\n  }\r\n\
    \  T query(int l, int r){\r\n    assert(0 <= l && l <= r && r <= n);\r\n    l\
    \ += len; r += len;\r\n    T left = inf, right = inf;\r\n    while(l < r){\r\n\
    \      if(l & 1) left = op(left, d[l++]);\r\n      if(r & 1) right = op(d[--r],\
    \ right);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    return op(left, right);\r\
    \n  }\r\n  template <class F>\r\n  int max_right(int l, F f) const{\r\n    assert(0\
    \ <= l && l <= n);\r\n    assert(f(inf));\r\n    if(l == n) return n;\r\n    l\
    \ += len;\r\n    T sm = inf;\r\n    do {\r\n      l /= l & -l;\r\n      if(!f(op(sm,\
    \ d[l]))){\r\n        while(l < len){\r\n          l <<= 1;\r\n          if(f(op(sm,\
    \ d[l]))){\r\n            sm = op(sm, d[l]);\r\n            l++;\r\n         \
    \ }\r\n        }\r\n        return l - len;\r\n      }\r\n      sm = op(sm, d[l]);\r\
    \n      l++;\r\n    }while(l & (l - 1));\r\n    return n;\r\n  }\r\n  template\
    \ <class F>\r\n  int min_left(int r, F f) const{\r\n    assert(0 <= r && r <=\
    \ n);\r\n    assert(f(inf));\r\n    if(r == 0) return 0;\r\n    r += len;\r\n\
    \    T sm = inf;\r\n    do {\r\n      r /= r & -r;\r\n      if(r > 1) r--;\r\n\
    \      if(!f(op(d[r], sm))){\r\n        while(r < len){\r\n          r = r * 2\
    \ + 1;\r\n          if(f(op(d[r], sm))){\r\n            sm = op(d[r], sm);\r\n\
    \            r--;\r\n          }\r\n        }\r\n        return r + 1 - len;\r\
    \n      }\r\n      sm = op(d[r], sm);\r\n    }while(r & (r - 1));\r\n    return\
    \ 0;\r\n  }\r\n  private:\r\n  const T inf = -op(numeric_limits<T>::max(), -numeric_limits<T>::max());\r\
    \n  int n = 1, log = 0, len = 0;\r\n  vector<T> d;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/seg-rmin.hpp
  requiredBy: []
  timestamp: '2023-03-31 18:03:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL/DSL_2_A.test.cpp
documentation_of: SegmentTree/seg-rmin.hpp
layout: document
redirect_from:
- /library/SegmentTree/seg-rmin.hpp
- /library/SegmentTree/seg-rmin.hpp.html
title: SegmentTree/seg-rmin.hpp
---
