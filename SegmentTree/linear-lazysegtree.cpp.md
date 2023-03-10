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
  bundledCode: "#line 1 \"SegmentTree/linear-lazysegtree.cpp\"\n#include <bits/stdc++.h>\n\
    using ll = long long;\nusing namespace std;\n\ntemplate <class T>\nstruct LazySegmentTree\
    \ {\n  struct Lazy {\n    T s,p;\n  };\n  LazySegmentTree(const int _n) : n(_n){\n\
    \    while((1 << log) < n) log++;\n    len = 1 << log;\n    d.assign(len * 2,\
    \ 0);\n    lazy.assign(len, {0,0});\n    si = new int[len * 2];\n    si[1] = len;\n\
    \    for(int i = 2; i < len * 2; i++) si[i] = si[i>>1]>>1;\n  }\n  ~LazySegmentTree(){\
    \ delete si; }\n  void set(const int i, const T &x){\n    assert(0 <= i && i <\
    \ n);\n    d[i + len] = x;\n  }\n  T get(int p){\n    assert(0 <= p && p < n);\n\
    \    p += len;\n    for(int i = log; i >= 1; i--) push(p >> i);\n    return d[p];\n\
    \  }\n  void build(){\n    for(int i = len - 1; i >= 1; i--) update(i);\n  }\n\
    \  void update(int l, int r, const Lazy &x){\n    assert(0 <= l && l <= r && r\
    \ <= n);\n    l += len; r += len;\n    const int l_ctz = __builtin_ctz(l);\n \
    \   const int r_ctz = __builtin_ctz(r);\n    for(int i = log; i > l_ctz; i--)\
    \ push(l >> i);\n    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\n  \
    \  const int lt = l, rt = r;\n    int L = l - len, R = r - len;\n    while(l <\
    \ r){\n      if(l & 1){\n        apply(l, x, L-lt+len);\n        L += si[l++];\n\
    \      }\n      if(r & 1){\n        R -= si[--r];\n        apply(r, x, R-lt+len);\n\
    \      }\n      l >>= 1; r >>= 1;\n    }\n    l = lt; r = rt;\n    for(int i =\
    \ l_ctz + 1; i <= log; i++) update(l >> i);\n    for(int i = r_ctz + 1; i <= log;\
    \ i++) update((r - 1) >> i);\n  }\n  T query(int l, int r){\n    assert(0 <= l\
    \ && l <= r && r <= n);\n    l += len; r += len;\n    const int l_ctz = __builtin_ctz(l);\n\
    \    const int r_ctz = __builtin_ctz(r);\n    for(int i = log; i > l_ctz; i--)\
    \ push(l >> i);\n    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\n  \
    \  T res = 0;\n    while(l < r){\n      if(l & 1) res += d[l++];\n      if(r &\
    \ 1) res += d[--r];\n      l >>= 1; r >>= 1;\n    }\n    return res;\n  }\n  private:\n\
    \  vector<T> d;\n  vector<Lazy> lazy;\n  int *si;\n  int n = 1, log = 0, len =\
    \ 0;\n  inline void update(const int k){ d[k] = d[2*k] + d[2*k+1]; }\n  inline\
    \ void apply(const int k, const Lazy &x, const int r){\n    const T tot = (x.s*2+x.p*(r*2+si[k]-1))*si[k]\
    \ / 2;\n    d[k] += tot;\n    if(k < len){\n      lazy[k].s += x.s + x.p*r;\n\
    \      lazy[k].p += x.p;\n    }\n  }\n  inline void push(const int k){\n    if(lazy[k].s\
    \ == 0 && lazy[k].p == 0) return;\n    apply(2*k, lazy[k], 0);\n    apply(2*k+1,\
    \ lazy[k], si[2*k+1]);\n    lazy[k] = { 0, 0 };\n  }\n};\n\nint main(){\n  int\
    \ n,q;\n  cin >> n >> q;\n  LazySegmentTree<ll> seg(n);\n  for(int i = 0; i <\
    \ q; i++){\n    int t; cin >> t;\n    //update: (l <= i < r)  a[i] = a[i] + s\
    \ + p*(i - l)\n    if(t == 0){\n      int l,r; ll s,p;\n      cin >> l >> r >>\
    \ s >> p;\n      l--;\n      seg.update(l, r, { s, p });\n    }\n    //query:\
    \ a[l]+a[l+1]+...+a[r-2]+a[r-1]\n    else{\n      int l,r;\n      cin >> l >>\
    \ r;\n      l--;\n      cout << seg.query(l, r) << \"\\n\";\n    }\n  }\n}\n"
  code: "#include <bits/stdc++.h>\nusing ll = long long;\nusing namespace std;\n\n\
    template <class T>\nstruct LazySegmentTree {\n  struct Lazy {\n    T s,p;\n  };\n\
    \  LazySegmentTree(const int _n) : n(_n){\n    while((1 << log) < n) log++;\n\
    \    len = 1 << log;\n    d.assign(len * 2, 0);\n    lazy.assign(len, {0,0});\n\
    \    si = new int[len * 2];\n    si[1] = len;\n    for(int i = 2; i < len * 2;\
    \ i++) si[i] = si[i>>1]>>1;\n  }\n  ~LazySegmentTree(){ delete si; }\n  void set(const\
    \ int i, const T &x){\n    assert(0 <= i && i < n);\n    d[i + len] = x;\n  }\n\
    \  T get(int p){\n    assert(0 <= p && p < n);\n    p += len;\n    for(int i =\
    \ log; i >= 1; i--) push(p >> i);\n    return d[p];\n  }\n  void build(){\n  \
    \  for(int i = len - 1; i >= 1; i--) update(i);\n  }\n  void update(int l, int\
    \ r, const Lazy &x){\n    assert(0 <= l && l <= r && r <= n);\n    l += len; r\
    \ += len;\n    const int l_ctz = __builtin_ctz(l);\n    const int r_ctz = __builtin_ctz(r);\n\
    \    for(int i = log; i > l_ctz; i--) push(l >> i);\n    for(int i = log; i >\
    \ r_ctz; i--) push((r - 1) >> i);\n    const int lt = l, rt = r;\n    int L =\
    \ l - len, R = r - len;\n    while(l < r){\n      if(l & 1){\n        apply(l,\
    \ x, L-lt+len);\n        L += si[l++];\n      }\n      if(r & 1){\n        R -=\
    \ si[--r];\n        apply(r, x, R-lt+len);\n      }\n      l >>= 1; r >>= 1;\n\
    \    }\n    l = lt; r = rt;\n    for(int i = l_ctz + 1; i <= log; i++) update(l\
    \ >> i);\n    for(int i = r_ctz + 1; i <= log; i++) update((r - 1) >> i);\n  }\n\
    \  T query(int l, int r){\n    assert(0 <= l && l <= r && r <= n);\n    l += len;\
    \ r += len;\n    const int l_ctz = __builtin_ctz(l);\n    const int r_ctz = __builtin_ctz(r);\n\
    \    for(int i = log; i > l_ctz; i--) push(l >> i);\n    for(int i = log; i >\
    \ r_ctz; i--) push((r - 1) >> i);\n    T res = 0;\n    while(l < r){\n      if(l\
    \ & 1) res += d[l++];\n      if(r & 1) res += d[--r];\n      l >>= 1; r >>= 1;\n\
    \    }\n    return res;\n  }\n  private:\n  vector<T> d;\n  vector<Lazy> lazy;\n\
    \  int *si;\n  int n = 1, log = 0, len = 0;\n  inline void update(const int k){\
    \ d[k] = d[2*k] + d[2*k+1]; }\n  inline void apply(const int k, const Lazy &x,\
    \ const int r){\n    const T tot = (x.s*2+x.p*(r*2+si[k]-1))*si[k] / 2;\n    d[k]\
    \ += tot;\n    if(k < len){\n      lazy[k].s += x.s + x.p*r;\n      lazy[k].p\
    \ += x.p;\n    }\n  }\n  inline void push(const int k){\n    if(lazy[k].s == 0\
    \ && lazy[k].p == 0) return;\n    apply(2*k, lazy[k], 0);\n    apply(2*k+1, lazy[k],\
    \ si[2*k+1]);\n    lazy[k] = { 0, 0 };\n  }\n};\n\nint main(){\n  int n,q;\n \
    \ cin >> n >> q;\n  LazySegmentTree<ll> seg(n);\n  for(int i = 0; i < q; i++){\n\
    \    int t; cin >> t;\n    //update: (l <= i < r)  a[i] = a[i] + s + p*(i - l)\n\
    \    if(t == 0){\n      int l,r; ll s,p;\n      cin >> l >> r >> s >> p;\n   \
    \   l--;\n      seg.update(l, r, { s, p });\n    }\n    //query: a[l]+a[l+1]+...+a[r-2]+a[r-1]\n\
    \    else{\n      int l,r;\n      cin >> l >> r;\n      l--;\n      cout << seg.query(l,\
    \ r) << \"\\n\";\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/linear-lazysegtree.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/linear-lazysegtree.cpp
layout: document
redirect_from:
- /library/SegmentTree/linear-lazysegtree.cpp
- /library/SegmentTree/linear-lazysegtree.cpp.html
title: SegmentTree/linear-lazysegtree.cpp
---
