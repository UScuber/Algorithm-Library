---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegmentTree/rupdate-rmin.hpp\"\ntemplate <class T>\r\nstruct\
    \ LazySegmentTree {\r\n  LazySegmentTree(const int _n) : n(_n){\r\n    while((1\
    \ << log) < n) log++;\r\n    len = 1 << log;\r\n    d.assign(len * 2, inf);\r\n\
    \    lazy.assign(len, inf);\r\n  }\r\n  void set(const int i, const T &x){\r\n\
    \    assert(0 <= i && i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T get(int p){\r\
    \n    assert(0 <= p && p < n);\r\n    p += len;\r\n    for(int i = log; i >= 1;\
    \ i--) push(p >> i);\r\n    return d[p];\r\n  }\r\n  void build(){\r\n    for(int\
    \ i = len - 1; i >= 1; i--) update(i);\r\n  }\r\n  void update(int l, int r, const\
    \ T &x){\r\n    assert(0 <= l && l <= r && r <= n);\r\n    l += len; r += len;\r\
    \n    const int l_ctz = __builtin_ctz(l);\r\n    const int r_ctz = __builtin_ctz(r);\r\
    \n    for(int i = log; i > l_ctz; i--) push(l >> i);\r\n    for(int i = log; i\
    \ > r_ctz; i--) push((r - 1) >> i);\r\n    const int lt = l, rt = r;\r\n    while(l\
    \ < r){\r\n      if(l & 1) apply(l++, x);\r\n      if(r & 1) apply(--r, x);\r\n\
    \      l >>= 1; r >>= 1;\r\n    }\r\n    l = lt; r = rt;\r\n    for(int i = l_ctz\
    \ + 1; i <= log; i++) update(l >> i);\r\n    for(int i = r_ctz + 1; i <= log;\
    \ i++) update((r - 1) >> i);\r\n  }\r\n  T query(int l, int r){\r\n    assert(0\
    \ <= l && l <= r && r <= n);\r\n    l += len; r += len;\r\n    const int l_ctz\
    \ = __builtin_ctz(l);\r\n    const int r_ctz = __builtin_ctz(r);\r\n    for(int\
    \ i = log; i > l_ctz; i--) push(l >> i);\r\n    for(int i = log; i > r_ctz; i--)\
    \ push((r - 1) >> i);\r\n    T left = inf, right = inf;\r\n    while(l < r){\r\
    \n      if(l & 1) left = min(left, d[l++]);\r\n      if(r & 1) right = min(d[--r],\
    \ right);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    return min(left, right);\r\
    \n  }\r\n  private:\r\n  vector<T> d, lazy;\r\n  const T inf = numeric_limits<T>::max();\r\
    \n  int n = 1, log = 0, len = 0;\r\n  inline void update(const int k){ d[k] =\
    \ min(d[2*k], d[2*k+1]); }\r\n  inline void apply(const int k, const T &x){\r\n\
    \    d[k] = x;\r\n    if(k < len) lazy[k] = x;\r\n  }\r\n  inline void push(const\
    \ int k){\r\n    if(lazy[k] == inf) return;\r\n    apply(2*k, lazy[k]);\r\n  \
    \  apply(2*k+1, lazy[k]);\r\n    lazy[k] = inf;\r\n  }\r\n};\n"
  code: "template <class T>\r\nstruct LazySegmentTree {\r\n  LazySegmentTree(const\
    \ int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\n    len = 1 << log;\r\
    \n    d.assign(len * 2, inf);\r\n    lazy.assign(len, inf);\r\n  }\r\n  void set(const\
    \ int i, const T &x){\r\n    assert(0 <= i && i < n);\r\n    d[i + len] = x;\r\
    \n  }\r\n  T get(int p){\r\n    assert(0 <= p && p < n);\r\n    p += len;\r\n\
    \    for(int i = log; i >= 1; i--) push(p >> i);\r\n    return d[p];\r\n  }\r\n\
    \  void build(){\r\n    for(int i = len - 1; i >= 1; i--) update(i);\r\n  }\r\n\
    \  void update(int l, int r, const T &x){\r\n    assert(0 <= l && l <= r && r\
    \ <= n);\r\n    l += len; r += len;\r\n    const int l_ctz = __builtin_ctz(l);\r\
    \n    const int r_ctz = __builtin_ctz(r);\r\n    for(int i = log; i > l_ctz; i--)\
    \ push(l >> i);\r\n    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\r\n\
    \    const int lt = l, rt = r;\r\n    while(l < r){\r\n      if(l & 1) apply(l++,\
    \ x);\r\n      if(r & 1) apply(--r, x);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n\
    \    l = lt; r = rt;\r\n    for(int i = l_ctz + 1; i <= log; i++) update(l >>\
    \ i);\r\n    for(int i = r_ctz + 1; i <= log; i++) update((r - 1) >> i);\r\n \
    \ }\r\n  T query(int l, int r){\r\n    assert(0 <= l && l <= r && r <= n);\r\n\
    \    l += len; r += len;\r\n    const int l_ctz = __builtin_ctz(l);\r\n    const\
    \ int r_ctz = __builtin_ctz(r);\r\n    for(int i = log; i > l_ctz; i--) push(l\
    \ >> i);\r\n    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\r\n    T\
    \ left = inf, right = inf;\r\n    while(l < r){\r\n      if(l & 1) left = min(left,\
    \ d[l++]);\r\n      if(r & 1) right = min(d[--r], right);\r\n      l >>= 1; r\
    \ >>= 1;\r\n    }\r\n    return min(left, right);\r\n  }\r\n  private:\r\n  vector<T>\
    \ d, lazy;\r\n  const T inf = numeric_limits<T>::max();\r\n  int n = 1, log =\
    \ 0, len = 0;\r\n  inline void update(const int k){ d[k] = min(d[2*k], d[2*k+1]);\
    \ }\r\n  inline void apply(const int k, const T &x){\r\n    d[k] = x;\r\n    if(k\
    \ < len) lazy[k] = x;\r\n  }\r\n  inline void push(const int k){\r\n    if(lazy[k]\
    \ == inf) return;\r\n    apply(2*k, lazy[k]);\r\n    apply(2*k+1, lazy[k]);\r\n\
    \    lazy[k] = inf;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/rupdate-rmin.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/rupdate-rmin.hpp
layout: document
redirect_from:
- /library/SegmentTree/rupdate-rmin.hpp
- /library/SegmentTree/rupdate-rmin.hpp.html
title: SegmentTree/rupdate-rmin.hpp
---
