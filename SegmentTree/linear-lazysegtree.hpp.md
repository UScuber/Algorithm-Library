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
  bundledCode: "#line 1 \"SegmentTree/linear-lazysegtree.hpp\"\ntemplate <class T>\r\
    \nstruct LazySegmentTree {\r\n  struct Lazy {\r\n    T s,p;\r\n  };\r\n  LazySegmentTree(const\
    \ int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\n    len = 1 << log;\r\
    \n    d.assign(len * 2, 0);\r\n    lazy.assign(len, {0,0});\r\n    si = new int[len\
    \ * 2];\r\n    si[1] = len;\r\n    for(int i = 2; i < len * 2; i++) si[i] = si[i>>1]>>1;\r\
    \n  }\r\n  ~LazySegmentTree(){ delete si; }\r\n  void set(const int i, const T\
    \ &x){\r\n    assert(0 <= i && i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T get(int\
    \ p){\r\n    assert(0 <= p && p < n);\r\n    p += len;\r\n    for(int i = log;\
    \ i >= 1; i--) push(p >> i);\r\n    return d[p];\r\n  }\r\n  void build(){\r\n\
    \    for(int i = len - 1; i >= 1; i--) update(i);\r\n  }\r\n  void update(int\
    \ l, int r, const Lazy &x){\r\n    assert(0 <= l && l <= r && r <= n);\r\n   \
    \ l += len; r += len;\r\n    const int l_ctz = __builtin_ctz(l);\r\n    const\
    \ int r_ctz = __builtin_ctz(r);\r\n    for(int i = log; i > l_ctz; i--) push(l\
    \ >> i);\r\n    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\r\n    const\
    \ int lt = l, rt = r;\r\n    int L = l - len, R = r - len;\r\n    while(l < r){\r\
    \n      if(l & 1){\r\n        apply(l, x, L-lt+len);\r\n        L += si[l++];\r\
    \n      }\r\n      if(r & 1){\r\n        R -= si[--r];\r\n        apply(r, x,\
    \ R-lt+len);\r\n      }\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    l = lt; r =\
    \ rt;\r\n    for(int i = l_ctz + 1; i <= log; i++) update(l >> i);\r\n    for(int\
    \ i = r_ctz + 1; i <= log; i++) update((r - 1) >> i);\r\n  }\r\n  T query(int\
    \ l, int r){\r\n    assert(0 <= l && l <= r && r <= n);\r\n    l += len; r +=\
    \ len;\r\n    const int l_ctz = __builtin_ctz(l);\r\n    const int r_ctz = __builtin_ctz(r);\r\
    \n    for(int i = log; i > l_ctz; i--) push(l >> i);\r\n    for(int i = log; i\
    \ > r_ctz; i--) push((r - 1) >> i);\r\n    T res = 0;\r\n    while(l < r){\r\n\
    \      if(l & 1) res += d[l++];\r\n      if(r & 1) res += d[--r];\r\n      l >>=\
    \ 1; r >>= 1;\r\n    }\r\n    return res;\r\n  }\r\n  private:\r\n  vector<T>\
    \ d;\r\n  vector<Lazy> lazy;\r\n  int *si;\r\n  int n = 1, log = 0, len = 0;\r\
    \n  inline void update(const int k){ d[k] = d[2*k] + d[2*k+1]; }\r\n  inline void\
    \ apply(const int k, const Lazy &x, const int r){\r\n    const T tot = (x.s*2+x.p*(r*2+si[k]-1))*si[k]\
    \ / 2;\r\n    d[k] += tot;\r\n    if(k < len){\r\n      lazy[k].s += x.s + x.p*r;\r\
    \n      lazy[k].p += x.p;\r\n    }\r\n  }\r\n  inline void push(const int k){\r\
    \n    if(lazy[k].s == 0 && lazy[k].p == 0) return;\r\n    apply(2*k, lazy[k],\
    \ 0);\r\n    apply(2*k+1, lazy[k], si[2*k+1]);\r\n    lazy[k] = { 0, 0 };\r\n\
    \  }\r\n};\r\n\r\nint main(){\r\n  int n,q;\r\n  cin >> n >> q;\r\n  LazySegmentTree<ll>\
    \ seg(n);\r\n  for(int i = 0; i < q; i++){\r\n    int t; cin >> t;\r\n    //update:\
    \ (l <= i < r)  a[i] = a[i] + s + p*(i - l)\r\n    if(t == 0){\r\n      int l,r;\
    \ ll s,p;\r\n      cin >> l >> r >> s >> p;\r\n      l--;\r\n      seg.update(l,\
    \ r, { s, p });\r\n    }\r\n    //query: a[l]+a[l+1]+...+a[r-2]+a[r-1]\r\n   \
    \ else{\r\n      int l,r;\r\n      cin >> l >> r;\r\n      l--;\r\n      cout\
    \ << seg.query(l, r) << \"\\n\";\r\n    }\r\n  }\r\n}\n"
  code: "template <class T>\r\nstruct LazySegmentTree {\r\n  struct Lazy {\r\n   \
    \ T s,p;\r\n  };\r\n  LazySegmentTree(const int _n) : n(_n){\r\n    while((1 <<\
    \ log) < n) log++;\r\n    len = 1 << log;\r\n    d.assign(len * 2, 0);\r\n   \
    \ lazy.assign(len, {0,0});\r\n    si = new int[len * 2];\r\n    si[1] = len;\r\
    \n    for(int i = 2; i < len * 2; i++) si[i] = si[i>>1]>>1;\r\n  }\r\n  ~LazySegmentTree(){\
    \ delete si; }\r\n  void set(const int i, const T &x){\r\n    assert(0 <= i &&\
    \ i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T get(int p){\r\n    assert(0 <=\
    \ p && p < n);\r\n    p += len;\r\n    for(int i = log; i >= 1; i--) push(p >>\
    \ i);\r\n    return d[p];\r\n  }\r\n  void build(){\r\n    for(int i = len - 1;\
    \ i >= 1; i--) update(i);\r\n  }\r\n  void update(int l, int r, const Lazy &x){\r\
    \n    assert(0 <= l && l <= r && r <= n);\r\n    l += len; r += len;\r\n    const\
    \ int l_ctz = __builtin_ctz(l);\r\n    const int r_ctz = __builtin_ctz(r);\r\n\
    \    for(int i = log; i > l_ctz; i--) push(l >> i);\r\n    for(int i = log; i\
    \ > r_ctz; i--) push((r - 1) >> i);\r\n    const int lt = l, rt = r;\r\n    int\
    \ L = l - len, R = r - len;\r\n    while(l < r){\r\n      if(l & 1){\r\n     \
    \   apply(l, x, L-lt+len);\r\n        L += si[l++];\r\n      }\r\n      if(r &\
    \ 1){\r\n        R -= si[--r];\r\n        apply(r, x, R-lt+len);\r\n      }\r\n\
    \      l >>= 1; r >>= 1;\r\n    }\r\n    l = lt; r = rt;\r\n    for(int i = l_ctz\
    \ + 1; i <= log; i++) update(l >> i);\r\n    for(int i = r_ctz + 1; i <= log;\
    \ i++) update((r - 1) >> i);\r\n  }\r\n  T query(int l, int r){\r\n    assert(0\
    \ <= l && l <= r && r <= n);\r\n    l += len; r += len;\r\n    const int l_ctz\
    \ = __builtin_ctz(l);\r\n    const int r_ctz = __builtin_ctz(r);\r\n    for(int\
    \ i = log; i > l_ctz; i--) push(l >> i);\r\n    for(int i = log; i > r_ctz; i--)\
    \ push((r - 1) >> i);\r\n    T res = 0;\r\n    while(l < r){\r\n      if(l & 1)\
    \ res += d[l++];\r\n      if(r & 1) res += d[--r];\r\n      l >>= 1; r >>= 1;\r\
    \n    }\r\n    return res;\r\n  }\r\n  private:\r\n  vector<T> d;\r\n  vector<Lazy>\
    \ lazy;\r\n  int *si;\r\n  int n = 1, log = 0, len = 0;\r\n  inline void update(const\
    \ int k){ d[k] = d[2*k] + d[2*k+1]; }\r\n  inline void apply(const int k, const\
    \ Lazy &x, const int r){\r\n    const T tot = (x.s*2+x.p*(r*2+si[k]-1))*si[k]\
    \ / 2;\r\n    d[k] += tot;\r\n    if(k < len){\r\n      lazy[k].s += x.s + x.p*r;\r\
    \n      lazy[k].p += x.p;\r\n    }\r\n  }\r\n  inline void push(const int k){\r\
    \n    if(lazy[k].s == 0 && lazy[k].p == 0) return;\r\n    apply(2*k, lazy[k],\
    \ 0);\r\n    apply(2*k+1, lazy[k], si[2*k+1]);\r\n    lazy[k] = { 0, 0 };\r\n\
    \  }\r\n};\r\n\r\nint main(){\r\n  int n,q;\r\n  cin >> n >> q;\r\n  LazySegmentTree<ll>\
    \ seg(n);\r\n  for(int i = 0; i < q; i++){\r\n    int t; cin >> t;\r\n    //update:\
    \ (l <= i < r)  a[i] = a[i] + s + p*(i - l)\r\n    if(t == 0){\r\n      int l,r;\
    \ ll s,p;\r\n      cin >> l >> r >> s >> p;\r\n      l--;\r\n      seg.update(l,\
    \ r, { s, p });\r\n    }\r\n    //query: a[l]+a[l+1]+...+a[r-2]+a[r-1]\r\n   \
    \ else{\r\n      int l,r;\r\n      cin >> l >> r;\r\n      l--;\r\n      cout\
    \ << seg.query(l, r) << \"\\n\";\r\n    }\r\n  }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/linear-lazysegtree.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/linear-lazysegtree.hpp
layout: document
redirect_from:
- /library/SegmentTree/linear-lazysegtree.hpp
- /library/SegmentTree/linear-lazysegtree.hpp.html
title: SegmentTree/linear-lazysegtree.hpp
---
