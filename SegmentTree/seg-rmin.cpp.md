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
  bundledCode: "#line 1 \"SegmentTree/seg-rmin.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate<class T, const T&(*op)(const T&,const T&)>\nstruct\
    \ SegmentTree {\n  SegmentTree(const int _n) : n(_n){\n    while((1 << log) <\
    \ n) log++;\n    len = 1 << log;\n    //inf = -op(inf-1, -inf+1);\n    inf = -op(inf,\
    \ -inf);\n    d.resize(len * 2, inf);\n  }\n  void update(int k, const T &x){\n\
    \    assert(0 <= k && k < n);\n    k += len;\n    d[k] = x;\n    while(k > 1){\n\
    \      k >>= 1;\n      d[k] = op(d[k*2], d[k*2+1]);\n    }\n  }\n  void set(const\
    \ int i, const T &x){\n    assert(0 <= i && i < n);\n    d[i + len] = x;\n  }\n\
    \  T get(const int i) const{\n    assert(0 <= i && i < n);\n    return d[i + len];\n\
    \  }\n  void build(){\n    for(int k = len - 1; k >= 1; k--) d[k] = op(d[2*k],\
    \ d[2*k+1]);\n  }\n  T query(int l, int r){\n    assert(0 <= l && l <= r && r\
    \ <= n);\n    l += len; r += len;\n    T left = inf, right = inf;\n    while(l\
    \ < r){\n      if(l & 1) left = op(left, d[l++]);\n      if(r & 1) right = op(d[--r],\
    \ right);\n      l >>= 1; r >>= 1;\n    }\n    return op(left, right);\n  }\n\
    \  //min i  (0 <= i < r), (op(a[i], v) == a[i])\n  int min_left(int r, const T\
    \ v) const{\n    assert(0 <= r && r <= n);\n    if(d[1] > v || !r) return r;\n\
    \    r += len;\n    int k = 1;\n    for(int i = log - 1; i >= 0; i--){\n     \
    \ k <<= 1;\n      if(op(d[k]+op(1,-1),v)==v){\n        k++;\n        if(k > (r\
    \ >> i) || op(d[k]+op(1,-1),v)==v) return r - len;\n      }\n    }\n    return\
    \ k - len;\n  }\n  //max i  (0 <= i < r), (op(a[i], v) == a[i])\n  int min_right(const\
    \ int l, const int r, const T &x) const{\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    return min_right_sub(l, r, x, 1, 0, len);\n  }\n  //min i  (l <= i\
    \ < r), (op(a[i], v) == a[i])\n  int min_left(const int l, const int r, const\
    \ T &x) const{\n    assert(0 <= l && l <= r && r <= n);\n    return min_left_sub(l,\
    \ r, x, 1, 0, len);\n  }\n  private:\n  T inf = numeric_limits<T>::max();\n  int\
    \ n = 1, log = 0, len = 0;\n  vector<T> d;\n  //\u7BC4\u56F2\u5916\u3067\u3042\
    \u308C\u3070return a-1\n  int min_right_sub(int a, int b, const T &x, int k, int\
    \ l, int r) const{\n    if(op(d[k]+op(1,-1),x)==x || r <= a || b <= l) return\
    \ a - 1;\n    if(k >= len) return k - len;\n\n    int vrig = min_right_sub(a,\
    \ b, x, 2*k+1, (l+r)/2, r);\n    if(vrig != a - 1) return vrig;\n    return min_right_sub(a,\
    \ b, x, 2*k, l, (l+r)/2);\n  }\n  //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070\
    return b\n  int min_left_sub(int a, int b, const T &x, int k, int l, int r) const{\n\
    \    if(op(d[k]+op(1,-1),x)==x || r <= a || b <= l) return b;\n    if(k >= len)\
    \ return k - len;\n\n    int vlef = min_left_sub(a, b, x, 2*k, l, (l+r)/2);\n\
    \    if(vlef != b) return vlef;\n    return min_left_sub(a, b, x, 2*k+1, (l+r)/2,\
    \ r);\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class T, const\
    \ T&(*op)(const T&,const T&)>\nstruct SegmentTree {\n  SegmentTree(const int _n)\
    \ : n(_n){\n    while((1 << log) < n) log++;\n    len = 1 << log;\n    //inf =\
    \ -op(inf-1, -inf+1);\n    inf = -op(inf, -inf);\n    d.resize(len * 2, inf);\n\
    \  }\n  void update(int k, const T &x){\n    assert(0 <= k && k < n);\n    k +=\
    \ len;\n    d[k] = x;\n    while(k > 1){\n      k >>= 1;\n      d[k] = op(d[k*2],\
    \ d[k*2+1]);\n    }\n  }\n  void set(const int i, const T &x){\n    assert(0 <=\
    \ i && i < n);\n    d[i + len] = x;\n  }\n  T get(const int i) const{\n    assert(0\
    \ <= i && i < n);\n    return d[i + len];\n  }\n  void build(){\n    for(int k\
    \ = len - 1; k >= 1; k--) d[k] = op(d[2*k], d[2*k+1]);\n  }\n  T query(int l,\
    \ int r){\n    assert(0 <= l && l <= r && r <= n);\n    l += len; r += len;\n\
    \    T left = inf, right = inf;\n    while(l < r){\n      if(l & 1) left = op(left,\
    \ d[l++]);\n      if(r & 1) right = op(d[--r], right);\n      l >>= 1; r >>= 1;\n\
    \    }\n    return op(left, right);\n  }\n  //min i  (0 <= i < r), (op(a[i], v)\
    \ == a[i])\n  int min_left(int r, const T v) const{\n    assert(0 <= r && r <=\
    \ n);\n    if(d[1] > v || !r) return r;\n    r += len;\n    int k = 1;\n    for(int\
    \ i = log - 1; i >= 0; i--){\n      k <<= 1;\n      if(op(d[k]+op(1,-1),v)==v){\n\
    \        k++;\n        if(k > (r >> i) || op(d[k]+op(1,-1),v)==v) return r - len;\n\
    \      }\n    }\n    return k - len;\n  }\n  //max i  (0 <= i < r), (op(a[i],\
    \ v) == a[i])\n  int min_right(const int l, const int r, const T &x) const{\n\
    \    assert(0 <= l && l <= r && r <= n);\n    return min_right_sub(l, r, x, 1,\
    \ 0, len);\n  }\n  //min i  (l <= i < r), (op(a[i], v) == a[i])\n  int min_left(const\
    \ int l, const int r, const T &x) const{\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    return min_left_sub(l, r, x, 1, 0, len);\n  }\n  private:\n  T inf\
    \ = numeric_limits<T>::max();\n  int n = 1, log = 0, len = 0;\n  vector<T> d;\n\
    \  //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070return a-1\n  int min_right_sub(int\
    \ a, int b, const T &x, int k, int l, int r) const{\n    if(op(d[k]+op(1,-1),x)==x\
    \ || r <= a || b <= l) return a - 1;\n    if(k >= len) return k - len;\n\n   \
    \ int vrig = min_right_sub(a, b, x, 2*k+1, (l+r)/2, r);\n    if(vrig != a - 1)\
    \ return vrig;\n    return min_right_sub(a, b, x, 2*k, l, (l+r)/2);\n  }\n  //\u7BC4\
    \u56F2\u5916\u3067\u3042\u308C\u3070return b\n  int min_left_sub(int a, int b,\
    \ const T &x, int k, int l, int r) const{\n    if(op(d[k]+op(1,-1),x)==x || r\
    \ <= a || b <= l) return b;\n    if(k >= len) return k - len;\n\n    int vlef\
    \ = min_left_sub(a, b, x, 2*k, l, (l+r)/2);\n    if(vlef != b) return vlef;\n\
    \    return min_left_sub(a, b, x, 2*k+1, (l+r)/2, r);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/seg-rmin.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/seg-rmin.cpp
layout: document
redirect_from:
- /library/SegmentTree/seg-rmin.cpp
- /library/SegmentTree/seg-rmin.cpp.html
title: SegmentTree/seg-rmin.cpp
---
