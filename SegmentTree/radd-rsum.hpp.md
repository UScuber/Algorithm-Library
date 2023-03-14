---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL/DSL_2_G.test.cpp
    title: test/aoj/DSL/DSL_2_G.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegmentTree/radd-rsum.hpp\"\ntemplate <class T>\r\nstruct\
    \ LazySegmentTree {\r\n  LazySegmentTree(const int _n) : n(_n){\r\n    while((1\
    \ << log) < n) log++;\r\n    len = 1 << log;\r\n    d.assign(len * 2, 0);\r\n\
    \    lazy.assign(len, 0);\r\n    si.assign(len * 2, 1);\r\n    for(int i = len\
    \ - 1; i >= 1; i--) si[i] = si[i<<1] << 1;\r\n  }\r\n  void set(const int i, const\
    \ T &x){\r\n    assert(0 <= i && i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T\
    \ get(int p){\r\n    assert(0 <= p && p < n);\r\n    p += len;\r\n    for(int\
    \ i = log; i >= 1; i--) push(p >> i);\r\n    return d[p];\r\n  }\r\n  void build(){\r\
    \n    for(int i = len - 1; i >= 1; i--) update(i);\r\n  }\r\n  void update(int\
    \ l, int r, const T &x){\r\n    assert(0 <= l && l <= r && r <= n);\r\n    l +=\
    \ len; r += len;\r\n    const int l_ctz = __builtin_ctz(l);\r\n    const int r_ctz\
    \ = __builtin_ctz(r);\r\n    for(int i = log; i > l_ctz; i--) push(l >> i);\r\n\
    \    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\r\n    const int lt\
    \ = l, rt = r;\r\n    while(l < r){\r\n      if(l & 1) apply(l++, x);\r\n    \
    \  if(r & 1) apply(--r, x);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    l = lt;\
    \ r = rt;\r\n    for(int i = l_ctz + 1; i <= log; i++) update(l >> i);\r\n   \
    \ for(int i = r_ctz + 1; i <= log; i++) update((r - 1) >> i);\r\n  }\r\n  T query(int\
    \ l, int r){\r\n    assert(0 <= l && l <= r && r <= n);\r\n    l += len; r +=\
    \ len;\r\n    const int l_ctz = __builtin_ctz(l);\r\n    const int r_ctz = __builtin_ctz(r);\r\
    \n    for(int i = log; i > l_ctz; i--) push(l >> i);\r\n    for(int i = log; i\
    \ > r_ctz; i--) push((r - 1) >> i);\r\n    T res = 0;\r\n    while(l < r){\r\n\
    \      if(l & 1) res += d[l++];\r\n      if(r & 1) res += d[--r];\r\n      l >>=\
    \ 1; r >>= 1;\r\n    }\r\n    return res;\r\n  }\r\n  private:\r\n  vector<T>\
    \ d, lazy;\r\n  vector<int> si;\r\n  int n = 1, log = 0, len = 0;\r\n  inline\
    \ void update(const int k){ d[k] = d[2*k] + d[2*k+1]; }\r\n  inline void apply(const\
    \ int k, const T &x){\r\n    d[k] += x * si[k];\r\n    if(k < len) lazy[k] +=\
    \ x;\r\n  }\r\n  inline void push(const int k){\r\n    if(!lazy[k]) return;\r\n\
    \    apply(2*k, lazy[k]);\r\n    apply(2*k+1, lazy[k]);\r\n    lazy[k] = 0;\r\n\
    \  }\r\n};\n"
  code: "template <class T>\r\nstruct LazySegmentTree {\r\n  LazySegmentTree(const\
    \ int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\n    len = 1 << log;\r\
    \n    d.assign(len * 2, 0);\r\n    lazy.assign(len, 0);\r\n    si.assign(len *\
    \ 2, 1);\r\n    for(int i = len - 1; i >= 1; i--) si[i] = si[i<<1] << 1;\r\n \
    \ }\r\n  void set(const int i, const T &x){\r\n    assert(0 <= i && i < n);\r\n\
    \    d[i + len] = x;\r\n  }\r\n  T get(int p){\r\n    assert(0 <= p && p < n);\r\
    \n    p += len;\r\n    for(int i = log; i >= 1; i--) push(p >> i);\r\n    return\
    \ d[p];\r\n  }\r\n  void build(){\r\n    for(int i = len - 1; i >= 1; i--) update(i);\r\
    \n  }\r\n  void update(int l, int r, const T &x){\r\n    assert(0 <= l && l <=\
    \ r && r <= n);\r\n    l += len; r += len;\r\n    const int l_ctz = __builtin_ctz(l);\r\
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
    \ res = 0;\r\n    while(l < r){\r\n      if(l & 1) res += d[l++];\r\n      if(r\
    \ & 1) res += d[--r];\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    return res;\r\
    \n  }\r\n  private:\r\n  vector<T> d, lazy;\r\n  vector<int> si;\r\n  int n =\
    \ 1, log = 0, len = 0;\r\n  inline void update(const int k){ d[k] = d[2*k] + d[2*k+1];\
    \ }\r\n  inline void apply(const int k, const T &x){\r\n    d[k] += x * si[k];\r\
    \n    if(k < len) lazy[k] += x;\r\n  }\r\n  inline void push(const int k){\r\n\
    \    if(!lazy[k]) return;\r\n    apply(2*k, lazy[k]);\r\n    apply(2*k+1, lazy[k]);\r\
    \n    lazy[k] = 0;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/radd-rsum.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL/DSL_2_G.test.cpp
documentation_of: SegmentTree/radd-rsum.hpp
layout: document
redirect_from:
- /library/SegmentTree/radd-rsum.hpp
- /library/SegmentTree/radd-rsum.hpp.html
title: SegmentTree/radd-rsum.hpp
---
