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
  bundledCode: "#line 1 \"SegmentTree/lazysegtree.hpp\"\n#include <bits/stdc++.h>\n\
    using ll = long long;\nusing namespace std;\n\ntemplate <class T, T(*op)(const\
    \ T&,const T&), T(*e)(), class F,\n          T(*mapping)(const F&,const T&), F(*composition)(const\
    \ F&,const F&), F(*id)()>\nstruct LazySegmentTree {\n  LazySegmentTree(const int\
    \ _n) : n(_n){\n    while((1 << log) < n) log++;\n    len = 1 << log;\n    d.assign(len\
    \ * 2, e());\n    lazy.assign(len, id());\n  }\n  void set(const int i, const\
    \ T &x){\n    assert(0 <= i && i < n);\n    d[i + len] = x;\n  }\n  T get(int\
    \ p){\n    assert(0 <= p && p < n);\n    p += len;\n    for(int i = log; i >=\
    \ 1; i--) push(p >> i);\n    return d[p];\n  }\n  void build(){\n    for(int i\
    \ = len - 1; i >= 1; i--) update(i);\n  }\n  void update(int l, int r, const F\
    \ &x){\n    assert(0 <= l && l <= r && r <= n);\n    l += len; r += len;\n   \
    \ const int l_ctz = __builtin_ctz(l);\n    const int r_ctz = __builtin_ctz(r);\n\
    \    for(int i = log; i > l_ctz; i--) push(l >> i);\n    for(int i = log; i >\
    \ r_ctz; i--) push((r - 1) >> i);\n    const int lt = l, rt = r;\n    while(l\
    \ < r){\n      if(l & 1) apply(l++, x);\n      if(r & 1) apply(--r, x);\n    \
    \  l >>= 1; r >>= 1;\n    }\n    l = lt; r = rt;\n    for(int i = l_ctz + 1; i\
    \ <= log; i++) update(l >> i);\n    for(int i = r_ctz + 1; i <= log; i++) update((r\
    \ - 1) >> i);\n  }\n  T query(int l, int r){\n    assert(0 <= l && l <= r && r\
    \ <= n);\n    l += len; r += len;\n    const int l_ctz = __builtin_ctz(l);\n \
    \   const int r_ctz = __builtin_ctz(r);\n    for(int i = log; i > l_ctz; i--)\
    \ push(l >> i);\n    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\n  \
    \  T left = e(), right = e();\n    while(l < r){\n      if(l & 1) left = op(left,\
    \ d[l++]);\n      if(r & 1) right = op(d[--r], right);\n      l >>= 1; r >>= 1;\n\
    \    }\n    return op(left, right);\n  }\n  private:\n  vector<T> d;\n  vector<F>\
    \ lazy;\n  int n = 1, log = 0, len = 0;\n  inline void update(const int k){ d[k]\
    \ = op(d[2*k], d[2*k+1]); }\n  inline void apply(const int k, const F &x){\n \
    \   d[k] = mapping(x, d[k]);\n    if(k < len) lazy[k] = composition(lazy[k], x);\n\
    \  }\n  inline void push(const int k){\n    apply(2*k, lazy[k]);\n    apply(2*k+1,\
    \ lazy[k]);\n    lazy[k] = id();\n  }\n};\n\n/*\nstruct Data {\n  ll a, len;\n\
    };\nstruct Lazy {\n  ll a, b;\n};\nData op(const Data &a, const Data &b){\n  return\
    \ { a.a+b.a, a.len+b.len };\n}\nData e(){\n  return { 0, 0 };\n}\nData mapping(const\
    \ Lazy &a, const Data &b){\n  return { a.a*b.a + a.b*b.len, b.len };\n}\nLazy\
    \ composition(const Lazy &a, const Lazy &b){\n  return { a.a*b.a, a.b*b.a + b.b\
    \ };\n}\nLazy id(){\n  return { 1, 0 };\n}\n*/\n"
  code: "#include <bits/stdc++.h>\nusing ll = long long;\nusing namespace std;\n\n\
    template <class T, T(*op)(const T&,const T&), T(*e)(), class F,\n          T(*mapping)(const\
    \ F&,const T&), F(*composition)(const F&,const F&), F(*id)()>\nstruct LazySegmentTree\
    \ {\n  LazySegmentTree(const int _n) : n(_n){\n    while((1 << log) < n) log++;\n\
    \    len = 1 << log;\n    d.assign(len * 2, e());\n    lazy.assign(len, id());\n\
    \  }\n  void set(const int i, const T &x){\n    assert(0 <= i && i < n);\n   \
    \ d[i + len] = x;\n  }\n  T get(int p){\n    assert(0 <= p && p < n);\n    p +=\
    \ len;\n    for(int i = log; i >= 1; i--) push(p >> i);\n    return d[p];\n  }\n\
    \  void build(){\n    for(int i = len - 1; i >= 1; i--) update(i);\n  }\n  void\
    \ update(int l, int r, const F &x){\n    assert(0 <= l && l <= r && r <= n);\n\
    \    l += len; r += len;\n    const int l_ctz = __builtin_ctz(l);\n    const int\
    \ r_ctz = __builtin_ctz(r);\n    for(int i = log; i > l_ctz; i--) push(l >> i);\n\
    \    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\n    const int lt =\
    \ l, rt = r;\n    while(l < r){\n      if(l & 1) apply(l++, x);\n      if(r &\
    \ 1) apply(--r, x);\n      l >>= 1; r >>= 1;\n    }\n    l = lt; r = rt;\n   \
    \ for(int i = l_ctz + 1; i <= log; i++) update(l >> i);\n    for(int i = r_ctz\
    \ + 1; i <= log; i++) update((r - 1) >> i);\n  }\n  T query(int l, int r){\n \
    \   assert(0 <= l && l <= r && r <= n);\n    l += len; r += len;\n    const int\
    \ l_ctz = __builtin_ctz(l);\n    const int r_ctz = __builtin_ctz(r);\n    for(int\
    \ i = log; i > l_ctz; i--) push(l >> i);\n    for(int i = log; i > r_ctz; i--)\
    \ push((r - 1) >> i);\n    T left = e(), right = e();\n    while(l < r){\n   \
    \   if(l & 1) left = op(left, d[l++]);\n      if(r & 1) right = op(d[--r], right);\n\
    \      l >>= 1; r >>= 1;\n    }\n    return op(left, right);\n  }\n  private:\n\
    \  vector<T> d;\n  vector<F> lazy;\n  int n = 1, log = 0, len = 0;\n  inline void\
    \ update(const int k){ d[k] = op(d[2*k], d[2*k+1]); }\n  inline void apply(const\
    \ int k, const F &x){\n    d[k] = mapping(x, d[k]);\n    if(k < len) lazy[k] =\
    \ composition(lazy[k], x);\n  }\n  inline void push(const int k){\n    apply(2*k,\
    \ lazy[k]);\n    apply(2*k+1, lazy[k]);\n    lazy[k] = id();\n  }\n};\n\n/*\n\
    struct Data {\n  ll a, len;\n};\nstruct Lazy {\n  ll a, b;\n};\nData op(const\
    \ Data &a, const Data &b){\n  return { a.a+b.a, a.len+b.len };\n}\nData e(){\n\
    \  return { 0, 0 };\n}\nData mapping(const Lazy &a, const Data &b){\n  return\
    \ { a.a*b.a + a.b*b.len, b.len };\n}\nLazy composition(const Lazy &a, const Lazy\
    \ &b){\n  return { a.a*b.a, a.b*b.a + b.b };\n}\nLazy id(){\n  return { 1, 0 };\n\
    }\n*/"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/lazysegtree.hpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/lazysegtree.hpp
layout: document
redirect_from:
- /library/SegmentTree/lazysegtree.hpp
- /library/SegmentTree/lazysegtree.hpp.html
title: SegmentTree/lazysegtree.hpp
---
