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
  bundledCode: "#line 1 \"SegmentTree/radd-rmin.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T>\nstruct LazySegmentTree {\n  LazySegmentTree(const\
    \ int _n) : n(_n){\n    while((1 << log) < n) log++;\n    len = 1 << log;\n  \
    \  d.assign(len * 2, 0);\n    lazy.assign(len, 0);\n  }\n  void set(const int\
    \ i, const T &x){\n    assert(0 <= i && i < n);\n    d[i + len] = x;\n  }\n  T\
    \ get(int p){\n    assert(0 <= p && p < n);\n    p += len;\n    for(int i = log;\
    \ i >= 1; i--) push(p >> i);\n    return d[p];\n  }\n  void build(){\n    for(int\
    \ i = len - 1; i >= 1; i--) update(i);\n  }\n  void update(int l, int r, const\
    \ T &x){\n    assert(0 <= l && l <= r && r <= n);\n    l += len; r += len;\n \
    \   const int l_ctz = __builtin_ctz(l);\n    const int r_ctz = __builtin_ctz(r);\n\
    \    for(int i = log; i > l_ctz; i--) push(l >> i);\n    for(int i = log; i >\
    \ r_ctz; i--) push((r - 1) >> i);\n    const int lt = l, rt = r;\n    while(l\
    \ < r){\n      if(l & 1) apply(l++, x);\n      if(r & 1) apply(--r, x);\n    \
    \  l >>= 1; r >>= 1;\n    }\n    l = lt; r = rt;\n    for(int i = l_ctz + 1; i\
    \ <= log; i++) update(l >> i);\n    for(int i = r_ctz + 1; i <= log; i++) update((r\
    \ - 1) >> i);\n  }\n  T query(int l, int r){\n    assert(0 <= l && l <= r && r\
    \ <= n);\n    l += len; r += len;\n    const int l_ctz = __builtin_ctz(l);\n \
    \   const int r_ctz = __builtin_ctz(r);\n    for(int i = log; i > l_ctz; i--)\
    \ push(l >> i);\n    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\n  \
    \  T left = inf, right = inf;\n    while(l < r){\n      if(l & 1) left = min(left,\
    \ d[l++]);\n      if(r & 1) right = min(d[--r], right);\n      l >>= 1; r >>=\
    \ 1;\n    }\n    return min(left, right);\n  }\n  private:\n  vector<T> d, lazy;\n\
    \  int n = 1, log = 0, len = 0;\n  const T inf = numeric_limits<T>::max();\n \
    \ inline void update(const int k){ d[k] = min(d[2*k], d[2*k+1]); }\n  inline void\
    \ apply(const int k, const T &x){\n    d[k] += x;\n    if(k < len) lazy[k] +=\
    \ x;\n  }\n  inline void push(const int k){\n    if(!lazy[k]) return;\n    apply(2*k,\
    \ lazy[k]);\n    apply(2*k+1, lazy[k]);\n    lazy[k] = 0;\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ LazySegmentTree {\n  LazySegmentTree(const int _n) : n(_n){\n    while((1 <<\
    \ log) < n) log++;\n    len = 1 << log;\n    d.assign(len * 2, 0);\n    lazy.assign(len,\
    \ 0);\n  }\n  void set(const int i, const T &x){\n    assert(0 <= i && i < n);\n\
    \    d[i + len] = x;\n  }\n  T get(int p){\n    assert(0 <= p && p < n);\n   \
    \ p += len;\n    for(int i = log; i >= 1; i--) push(p >> i);\n    return d[p];\n\
    \  }\n  void build(){\n    for(int i = len - 1; i >= 1; i--) update(i);\n  }\n\
    \  void update(int l, int r, const T &x){\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    l += len; r += len;\n    const int l_ctz = __builtin_ctz(l);\n    const\
    \ int r_ctz = __builtin_ctz(r);\n    for(int i = log; i > l_ctz; i--) push(l >>\
    \ i);\n    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\n    const int\
    \ lt = l, rt = r;\n    while(l < r){\n      if(l & 1) apply(l++, x);\n      if(r\
    \ & 1) apply(--r, x);\n      l >>= 1; r >>= 1;\n    }\n    l = lt; r = rt;\n \
    \   for(int i = l_ctz + 1; i <= log; i++) update(l >> i);\n    for(int i = r_ctz\
    \ + 1; i <= log; i++) update((r - 1) >> i);\n  }\n  T query(int l, int r){\n \
    \   assert(0 <= l && l <= r && r <= n);\n    l += len; r += len;\n    const int\
    \ l_ctz = __builtin_ctz(l);\n    const int r_ctz = __builtin_ctz(r);\n    for(int\
    \ i = log; i > l_ctz; i--) push(l >> i);\n    for(int i = log; i > r_ctz; i--)\
    \ push((r - 1) >> i);\n    T left = inf, right = inf;\n    while(l < r){\n   \
    \   if(l & 1) left = min(left, d[l++]);\n      if(r & 1) right = min(d[--r], right);\n\
    \      l >>= 1; r >>= 1;\n    }\n    return min(left, right);\n  }\n  private:\n\
    \  vector<T> d, lazy;\n  int n = 1, log = 0, len = 0;\n  const T inf = numeric_limits<T>::max();\n\
    \  inline void update(const int k){ d[k] = min(d[2*k], d[2*k+1]); }\n  inline\
    \ void apply(const int k, const T &x){\n    d[k] += x;\n    if(k < len) lazy[k]\
    \ += x;\n  }\n  inline void push(const int k){\n    if(!lazy[k]) return;\n   \
    \ apply(2*k, lazy[k]);\n    apply(2*k+1, lazy[k]);\n    lazy[k] = 0;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/radd-rmin.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/radd-rmin.cpp
layout: document
redirect_from:
- /library/SegmentTree/radd-rmin.cpp
- /library/SegmentTree/radd-rmin.cpp.html
title: SegmentTree/radd-rmin.cpp
---
