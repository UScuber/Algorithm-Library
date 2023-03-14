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
    \n    while((1 << log) < n) log++;\r\n    len = 1 << log;\r\n    //inf = -op(inf-1,\
    \ -inf+1);\r\n    inf = -op(inf, -inf);\r\n    d.resize(len * 2, inf);\r\n  }\r\
    \n  void update(int k, const T &x){\r\n    assert(0 <= k && k < n);\r\n    k +=\
    \ len;\r\n    d[k] = x;\r\n    while(k > 1){\r\n      k >>= 1;\r\n      d[k] =\
    \ op(d[k*2], d[k*2+1]);\r\n    }\r\n  }\r\n  void set(const int i, const T &x){\r\
    \n    assert(0 <= i && i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T get(const\
    \ int i) const{\r\n    assert(0 <= i && i < n);\r\n    return d[i + len];\r\n\
    \  }\r\n  void build(){\r\n    for(int k = len - 1; k >= 1; k--) d[k] = op(d[2*k],\
    \ d[2*k+1]);\r\n  }\r\n  T query(int l, int r){\r\n    assert(0 <= l && l <= r\
    \ && r <= n);\r\n    l += len; r += len;\r\n    T left = inf, right = inf;\r\n\
    \    while(l < r){\r\n      if(l & 1) left = op(left, d[l++]);\r\n      if(r &\
    \ 1) right = op(d[--r], right);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    return\
    \ op(left, right);\r\n  }\r\n  //min i  (0 <= i < r), (op(a[i], v) == a[i])\r\n\
    \  int min_left(int r, const T v) const{\r\n    assert(0 <= r && r <= n);\r\n\
    \    if(d[1] > v || !r) return r;\r\n    r += len;\r\n    int k = 1;\r\n    for(int\
    \ i = log - 1; i >= 0; i--){\r\n      k <<= 1;\r\n      if(op(d[k]+op(1,-1),v)==v){\r\
    \n        k++;\r\n        if(k > (r >> i) || op(d[k]+op(1,-1),v)==v) return r\
    \ - len;\r\n      }\r\n    }\r\n    return k - len;\r\n  }\r\n  //max i  (0 <=\
    \ i < r), (op(a[i], v) == a[i])\r\n  int min_right(const int l, const int r, const\
    \ T &x) const{\r\n    assert(0 <= l && l <= r && r <= n);\r\n    return min_right_sub(l,\
    \ r, x, 1, 0, len);\r\n  }\r\n  //min i  (l <= i < r), (op(a[i], v) == a[i])\r\
    \n  int min_left(const int l, const int r, const T &x) const{\r\n    assert(0\
    \ <= l && l <= r && r <= n);\r\n    return min_left_sub(l, r, x, 1, 0, len);\r\
    \n  }\r\n  private:\r\n  T inf = numeric_limits<T>::max();\r\n  int n = 1, log\
    \ = 0, len = 0;\r\n  vector<T> d;\r\n  //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070\
    return a-1\r\n  int min_right_sub(int a, int b, const T &x, int k, int l, int\
    \ r) const{\r\n    if(op(d[k]+op(1,-1),x)==x || r <= a || b <= l) return a - 1;\r\
    \n    if(k >= len) return k - len;\r\n\r\n    int vrig = min_right_sub(a, b, x,\
    \ 2*k+1, (l+r)/2, r);\r\n    if(vrig != a - 1) return vrig;\r\n    return min_right_sub(a,\
    \ b, x, 2*k, l, (l+r)/2);\r\n  }\r\n  //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070\
    return b\r\n  int min_left_sub(int a, int b, const T &x, int k, int l, int r)\
    \ const{\r\n    if(op(d[k]+op(1,-1),x)==x || r <= a || b <= l) return b;\r\n \
    \   if(k >= len) return k - len;\r\n\r\n    int vlef = min_left_sub(a, b, x, 2*k,\
    \ l, (l+r)/2);\r\n    if(vlef != b) return vlef;\r\n    return min_left_sub(a,\
    \ b, x, 2*k+1, (l+r)/2, r);\r\n  }\r\n};\n"
  code: "template<class T, const T&(*op)(const T&,const T&)>\r\nstruct SegmentTree\
    \ {\r\n  SegmentTree(const int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\
    \n    len = 1 << log;\r\n    //inf = -op(inf-1, -inf+1);\r\n    inf = -op(inf,\
    \ -inf);\r\n    d.resize(len * 2, inf);\r\n  }\r\n  void update(int k, const T\
    \ &x){\r\n    assert(0 <= k && k < n);\r\n    k += len;\r\n    d[k] = x;\r\n \
    \   while(k > 1){\r\n      k >>= 1;\r\n      d[k] = op(d[k*2], d[k*2+1]);\r\n\
    \    }\r\n  }\r\n  void set(const int i, const T &x){\r\n    assert(0 <= i &&\
    \ i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T get(const int i) const{\r\n   \
    \ assert(0 <= i && i < n);\r\n    return d[i + len];\r\n  }\r\n  void build(){\r\
    \n    for(int k = len - 1; k >= 1; k--) d[k] = op(d[2*k], d[2*k+1]);\r\n  }\r\n\
    \  T query(int l, int r){\r\n    assert(0 <= l && l <= r && r <= n);\r\n    l\
    \ += len; r += len;\r\n    T left = inf, right = inf;\r\n    while(l < r){\r\n\
    \      if(l & 1) left = op(left, d[l++]);\r\n      if(r & 1) right = op(d[--r],\
    \ right);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    return op(left, right);\r\
    \n  }\r\n  //min i  (0 <= i < r), (op(a[i], v) == a[i])\r\n  int min_left(int\
    \ r, const T v) const{\r\n    assert(0 <= r && r <= n);\r\n    if(d[1] > v ||\
    \ !r) return r;\r\n    r += len;\r\n    int k = 1;\r\n    for(int i = log - 1;\
    \ i >= 0; i--){\r\n      k <<= 1;\r\n      if(op(d[k]+op(1,-1),v)==v){\r\n   \
    \     k++;\r\n        if(k > (r >> i) || op(d[k]+op(1,-1),v)==v) return r - len;\r\
    \n      }\r\n    }\r\n    return k - len;\r\n  }\r\n  //max i  (0 <= i < r), (op(a[i],\
    \ v) == a[i])\r\n  int min_right(const int l, const int r, const T &x) const{\r\
    \n    assert(0 <= l && l <= r && r <= n);\r\n    return min_right_sub(l, r, x,\
    \ 1, 0, len);\r\n  }\r\n  //min i  (l <= i < r), (op(a[i], v) == a[i])\r\n  int\
    \ min_left(const int l, const int r, const T &x) const{\r\n    assert(0 <= l &&\
    \ l <= r && r <= n);\r\n    return min_left_sub(l, r, x, 1, 0, len);\r\n  }\r\n\
    \  private:\r\n  T inf = numeric_limits<T>::max();\r\n  int n = 1, log = 0, len\
    \ = 0;\r\n  vector<T> d;\r\n  //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070return\
    \ a-1\r\n  int min_right_sub(int a, int b, const T &x, int k, int l, int r) const{\r\
    \n    if(op(d[k]+op(1,-1),x)==x || r <= a || b <= l) return a - 1;\r\n    if(k\
    \ >= len) return k - len;\r\n\r\n    int vrig = min_right_sub(a, b, x, 2*k+1,\
    \ (l+r)/2, r);\r\n    if(vrig != a - 1) return vrig;\r\n    return min_right_sub(a,\
    \ b, x, 2*k, l, (l+r)/2);\r\n  }\r\n  //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070\
    return b\r\n  int min_left_sub(int a, int b, const T &x, int k, int l, int r)\
    \ const{\r\n    if(op(d[k]+op(1,-1),x)==x || r <= a || b <= l) return b;\r\n \
    \   if(k >= len) return k - len;\r\n\r\n    int vlef = min_left_sub(a, b, x, 2*k,\
    \ l, (l+r)/2);\r\n    if(vlef != b) return vlef;\r\n    return min_left_sub(a,\
    \ b, x, 2*k+1, (l+r)/2, r);\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/seg-rmin.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
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
