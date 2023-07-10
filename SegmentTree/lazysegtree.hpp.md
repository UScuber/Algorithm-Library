---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
    title: test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
    title: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"SegmentTree/lazysegtree.hpp\"\ntemplate <class T, T(*op)(const\
    \ T&,const T&), T(*e)(), class F,\r\n          T(*mapping)(const F&,const T&),\
    \ F(*composition)(const F&,const F&), F(*id)()>\r\nstruct LazySegmentTree {\r\n\
    \  LazySegmentTree(const int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\
    \n    len = 1 << log;\r\n    d.assign(len * 2, e());\r\n    lazy.assign(len, id());\r\
    \n  }\r\n  void set(const int i, const T &x){\r\n    assert(0 <= i && i < n);\r\
    \n    d[i + len] = x;\r\n  }\r\n  T get(int p){\r\n    assert(0 <= p && p < n);\r\
    \n    p += len;\r\n    for(int i = log; i >= 1; i--) push(p >> i);\r\n    return\
    \ d[p];\r\n  }\r\n  void build(){\r\n    for(int i = len - 1; i >= 1; i--) update(i);\r\
    \n  }\r\n  void update(int l, int r, const F &x){\r\n    assert(0 <= l && l <=\
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
    \ left = e(), right = e();\r\n    while(l < r){\r\n      if(l & 1) left = op(left,\
    \ d[l++]);\r\n      if(r & 1) right = op(d[--r], right);\r\n      l >>= 1; r >>=\
    \ 1;\r\n    }\r\n    return op(left, right);\r\n  }\r\n  template <class G>\r\n\
    \  int max_right(int l, G g){\r\n    assert(0 <= l && l <= n);\r\n    assert(g(e()));\r\
    \n    if(l == n) return n;\r\n    l += len;\r\n    for(int i = log; i >= 1; i--)\
    \ push(l >> i);\r\n    T sm = e();\r\n    do {\r\n      l /= l & -l;\r\n     \
    \ if(!g(op(sm, d[l]))){\r\n        while(l < len){\r\n          push(l);\r\n \
    \         l <<= 1;\r\n          if(g(op(sm, d[l]))){\r\n            sm = op(sm,\
    \ d[l]);\r\n            l++;\r\n          }\r\n        }\r\n        return l -\
    \ len;\r\n      }\r\n      sm = op(sm, d[l]);\r\n      l++;\r\n    }while(l &\
    \ (l - 1));\r\n    return n;\r\n  }\r\n  template <class G>\r\n  int min_left(int\
    \ r, G g){\r\n    assert(0 <= r && r <= n);\r\n    assert(g(e()));\r\n    if(r\
    \ == 0) return 0;\r\n    r += len;\r\n    for(int i = log; i >= 1; i--) push((r\
    \ - 1) >> i);\r\n    T sm = e();\r\n    do {\r\n      r /= r & -r;\r\n      if(r\
    \ > 1) r--;\r\n      if(!g(op(d[r], sm))){\r\n        while(r < len){\r\n    \
    \      push(r);\r\n          r = r * 2 + 1;\r\n          if(g(op(d[r], sm))){\r\
    \n            sm = op(d[r], sm);\r\n            r--;\r\n          }\r\n      \
    \  }\r\n        return r + 1 - len;\r\n      }\r\n      sm = op(d[r], sm);\r\n\
    \    }while(r & (r - 1));\r\n    return 0;\r\n  }\r\n  private:\r\n  vector<T>\
    \ d;\r\n  vector<F> lazy;\r\n  int n = 1, log = 0, len = 0;\r\n  inline void update(const\
    \ int k){ d[k] = op(d[2*k], d[2*k+1]); }\r\n  inline void apply(const int k, const\
    \ F &x){\r\n    d[k] = mapping(x, d[k]);\r\n    if(k < len) lazy[k] = composition(lazy[k],\
    \ x);\r\n  }\r\n  inline void push(const int k){\r\n    apply(2*k, lazy[k]);\r\
    \n    apply(2*k+1, lazy[k]);\r\n    lazy[k] = id();\r\n  }\r\n};\n"
  code: "template <class T, T(*op)(const T&,const T&), T(*e)(), class F,\r\n     \
    \     T(*mapping)(const F&,const T&), F(*composition)(const F&,const F&), F(*id)()>\r\
    \nstruct LazySegmentTree {\r\n  LazySegmentTree(const int _n) : n(_n){\r\n   \
    \ while((1 << log) < n) log++;\r\n    len = 1 << log;\r\n    d.assign(len * 2,\
    \ e());\r\n    lazy.assign(len, id());\r\n  }\r\n  void set(const int i, const\
    \ T &x){\r\n    assert(0 <= i && i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T\
    \ get(int p){\r\n    assert(0 <= p && p < n);\r\n    p += len;\r\n    for(int\
    \ i = log; i >= 1; i--) push(p >> i);\r\n    return d[p];\r\n  }\r\n  void build(){\r\
    \n    for(int i = len - 1; i >= 1; i--) update(i);\r\n  }\r\n  void update(int\
    \ l, int r, const F &x){\r\n    assert(0 <= l && l <= r && r <= n);\r\n    l +=\
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
    \ > r_ctz; i--) push((r - 1) >> i);\r\n    T left = e(), right = e();\r\n    while(l\
    \ < r){\r\n      if(l & 1) left = op(left, d[l++]);\r\n      if(r & 1) right =\
    \ op(d[--r], right);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    return op(left,\
    \ right);\r\n  }\r\n  template <class G>\r\n  int max_right(int l, G g){\r\n \
    \   assert(0 <= l && l <= n);\r\n    assert(g(e()));\r\n    if(l == n) return\
    \ n;\r\n    l += len;\r\n    for(int i = log; i >= 1; i--) push(l >> i);\r\n \
    \   T sm = e();\r\n    do {\r\n      l /= l & -l;\r\n      if(!g(op(sm, d[l]))){\r\
    \n        while(l < len){\r\n          push(l);\r\n          l <<= 1;\r\n    \
    \      if(g(op(sm, d[l]))){\r\n            sm = op(sm, d[l]);\r\n            l++;\r\
    \n          }\r\n        }\r\n        return l - len;\r\n      }\r\n      sm =\
    \ op(sm, d[l]);\r\n      l++;\r\n    }while(l & (l - 1));\r\n    return n;\r\n\
    \  }\r\n  template <class G>\r\n  int min_left(int r, G g){\r\n    assert(0 <=\
    \ r && r <= n);\r\n    assert(g(e()));\r\n    if(r == 0) return 0;\r\n    r +=\
    \ len;\r\n    for(int i = log; i >= 1; i--) push((r - 1) >> i);\r\n    T sm =\
    \ e();\r\n    do {\r\n      r /= r & -r;\r\n      if(r > 1) r--;\r\n      if(!g(op(d[r],\
    \ sm))){\r\n        while(r < len){\r\n          push(r);\r\n          r = r *\
    \ 2 + 1;\r\n          if(g(op(d[r], sm))){\r\n            sm = op(d[r], sm);\r\
    \n            r--;\r\n          }\r\n        }\r\n        return r + 1 - len;\r\
    \n      }\r\n      sm = op(d[r], sm);\r\n    }while(r & (r - 1));\r\n    return\
    \ 0;\r\n  }\r\n  private:\r\n  vector<T> d;\r\n  vector<F> lazy;\r\n  int n =\
    \ 1, log = 0, len = 0;\r\n  inline void update(const int k){ d[k] = op(d[2*k],\
    \ d[2*k+1]); }\r\n  inline void apply(const int k, const F &x){\r\n    d[k] =\
    \ mapping(x, d[k]);\r\n    if(k < len) lazy[k] = composition(lazy[k], x);\r\n\
    \  }\r\n  inline void push(const int k){\r\n    apply(2*k, lazy[k]);\r\n    apply(2*k+1,\
    \ lazy[k]);\r\n    lazy[k] = id();\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/lazysegtree.hpp
  requiredBy: []
  timestamp: '2023-07-10 18:11:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
  - test/yosupo/Data-Structure/Range-Affine-Point-Get.test.cpp
documentation_of: SegmentTree/lazysegtree.hpp
layout: document
redirect_from:
- /library/SegmentTree/lazysegtree.hpp
- /library/SegmentTree/lazysegtree.hpp.html
title: SegmentTree/lazysegtree.hpp
---
