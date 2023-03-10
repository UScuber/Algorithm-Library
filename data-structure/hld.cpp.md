---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: SegmentTree/segtree.hpp
    title: SegmentTree/segtree.hpp
  - icon: ':warning:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':warning:'
    path: math/mint.hpp
    title: math/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/hld.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"graph/template.hpp\"\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ Edge {\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){};\n  Edge(int f, int\
    \ t, T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}\n  Edge(int t) : to(t),\
    \ from(-1), cost(1), idx(-1){}\n  operator int() const{ return to; }\n  bool operator<(const\
    \ Edge &e){ return cost < e.cost; }\n};\ntemplate <class T>\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\n  Graph(){}\n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\n  void\
    \ add_edge(int a, int b, T c=1, int i=-1){\n    (*this)[a].push_back({ a, b, c,\
    \ i });\n  }\n};\nusing graph = Graph<int>;\n#line 1 \"math/mint.hpp\"\nusing\
    \ ll = long long;\n\ntemplate <int mod>\nstruct Mint {\n  ll x;\n  constexpr Mint(ll\
    \ x = 0) : x((x + mod) % mod){}\n  static constexpr int get_mod(){ return mod;\
    \ }\n  constexpr Mint operator-() const{ return Mint(-x); }\n  constexpr Mint\
    \ operator+=(const Mint &a){\n    if((x += a.x) >= mod) x -= mod;\n    return\
    \ *this;\n  }\n  constexpr Mint &operator++(){\n    if(++x == mod) x = 0;\n  \
    \  return *this;\n  }\n  constexpr Mint operator++(int){\n    Mint temp = *this;\n\
    \    if(++x == mod) x = 0;\n    return temp;\n  }\n  constexpr Mint &operator-=(const\
    \ Mint &a){\n    if((x -= a.x) < 0) x += mod;\n    return *this;\n  }\n  constexpr\
    \ Mint &operator--(){\n    if(--x < 0) x += mod;\n    return *this;\n  }\n  constexpr\
    \ Mint operator--(int){\n    Mint temp = *this;\n    if(--x < 0) x += mod;\n \
    \   return temp;\n  }\n  constexpr Mint &operator*=(const Mint &a){\n    (x *=\
    \ a.x) %= mod;\n    return *this;\n  }\n  constexpr Mint operator+(const Mint\
    \ &a) const{ return Mint(*this) += a; }\n  constexpr Mint operator-(const Mint\
    \ &a) const{ return Mint(*this) -= a; }\n  constexpr Mint operator*(const Mint\
    \ &a) const{ return Mint(*this) *= a; }\n  constexpr Mint pow(ll t) const{\n \
    \   if(!t) return 1;\n    Mint res = 1, v = *this;\n    while(t){\n      if(t\
    \ & 1) res *= v;\n      v *= v;\n      t >>= 1;\n    }\n    return res;\n  }\n\
    \  constexpr Mint inv() const{ return pow(mod - 2); }\n  constexpr Mint &operator/=(const\
    \ Mint &a){ return (*this) *= a.inv(); }\n  constexpr Mint operator/(const Mint\
    \ &a) const{ return Mint(*this) /= a; }\n  constexpr bool operator==(const Mint\
    \ &a) const{ return x == a.x; }\n  constexpr bool operator!=(const Mint &a) const{\
    \ return x != a.x; }\n  constexpr bool operator<(const Mint &a) const{ return\
    \ x < a.x; }\n  constexpr bool operator>(const Mint &a) const{ return x > a.x;\
    \ }\n  friend istream &operator>>(istream &is, Mint &a){ return is >> a.x; }\n\
    \  friend ostream &operator<<(ostream &os, const Mint &a){ return os << a.x; }\n\
    };\nusing mint = Mint<1000000007>;\n#line 2 \"SegmentTree/segtree.hpp\"\nusing\
    \ namespace std;\n\ntemplate <class T, T(*op)(const T&,const T&), T(*e)()>\nstruct\
    \ SegmentTree {\n  SegmentTree(const int _n) : n(_n){\n    while((1 << log) <\
    \ n) log++;\n    len = 1 << log;\n    d.resize(len * 2, e());\n  }\n  void update(int\
    \ k, const T &x){\n    assert(0 <= k && k < n);\n    k += len;\n    d[k] = x;\n\
    \    while(k > 1){\n      k >>= 1;\n      d[k] = op(d[k*2], d[k*2+1]);\n    }\n\
    \  }\n  void set(const int i, const T &x){\n    assert(0 <= i && i < n);\n   \
    \ d[i + len] = x;\n  }\n  T get(const int i) const{\n    assert(0 <= i && i <\
    \ n);\n    return d[i + len];\n  }\n  void build(){\n    for(int k = len - 1;\
    \ k >= 1; k--)\n      d[k] = op(d[2*k], d[2*k+1]);\n  }\n  T query(int l, int\
    \ r){\n    assert(0 <= l && l <= r && r <= n);\n    l += len; r += len;\n    T\
    \ left = e(), right = e();\n    while(l < r){\n      if(l & 1) left = op(left,\
    \ d[l++]);\n      if(r & 1) right = op(d[--r], right);\n      l >>= 1; r >>= 1;\n\
    \    }\n    return op(left, right);\n  }\n  private:\n  int n = 1, log = 0, len\
    \ = 0;\n  vector<T> d;\n};\n\n/*\nstruct Data {\n  int a;\n};\nData op(const Data\
    \ &a, const Data &b){\n  return { min(a.a, b.a) };\n}\nData e(){\n  return { 0\
    \ };\n}\n*/\n#line 5 \"data-structure/hld.cpp\"\nusing namespace std;\n\ntemplate\
    \ <class T, T(*op)(const T&,const T&), T(*rev_op)(const T&,const T&), T(*e)()>\n\
    struct HLD {\n  graph root;\n  int n, in_cnt = 0;\n  vector<int> pre, sh, sz,\
    \ p;\n  SegmentTree<T,op,e> seg;\n  SegmentTree<T,rev_op,e> rseg;\n  HLD(const\
    \ graph &g) : root(g), n(g.size()), pre(n), sh(n), sz(n), p(n), seg(n), rseg(n){\n\
    \    size(0, -1);\n    calc(0, -1, 0);\n  }\n  void size(int pos, int par){\n\
    \    sz[pos] = 1;\n    int mx = -1, idx = -1, cnt = -1;\n    for(const int &x\
    \ : root[pos]){\n      cnt++;\n      if(x == par) continue;\n      size(x, pos);\n\
    \      sz[pos] += sz[x];\n      if(chmax(mx, sz[x])) idx = cnt;\n    }\n    if(idx\
    \ != -1) swap(root[pos][0], root[pos][idx]);\n  }\n  void calc(int pos, int par,\
    \ int v){\n    p[pos] = in_cnt++;\n    sh[pos] = v;\n    pre[pos] = par;\n   \
    \ int cnt = -1;\n    for(const int &x : root[pos]){\n      cnt++;\n      if(x\
    \ == par) continue;\n      if(cnt) calc(x, pos, x);\n      else calc(x, pos, v);\n\
    \    }\n  }\n  void set(int u, const T &x){\n    seg.set(p[u], x);\n    rseg.set(p[u],\
    \ x);\n  }\n  void build(){\n    seg.build();\n    rseg.build();\n  }\n\n  void\
    \ update(int u, const T &x){\n    seg.update(p[u], x);\n    rseg.update(p[u],\
    \ x);\n  }\n  vector<pair<int,int>> query_path(int u, int v){\n    vector<pair<int,int>>\
    \ lef, rig;\n    while(sh[u] != sh[v]){\n      if(p[u] < p[v]){\n        rig.emplace_back(p[sh[v]],\
    \ p[v]);\n        v = pre[sh[v]];\n      }\n      else{\n        lef.emplace_back(p[u],\
    \ p[sh[u]]);\n        u = pre[sh[u]];\n      }\n    }\n    if(p[u] < p[v]) rig.emplace_back(p[u],\
    \ p[v]);\n    else lef.emplace_back(p[u], p[v]);\n    reverse(all(rig));\n   \
    \ lef.insert(lef.end(), all(rig));\n    return lef;\n  }\n  T query(int u, int\
    \ v){\n    T res = e();\n    for(const auto &x : query_path(u, v)){\n      if(x.first\
    \ <= x.second){\n        res = op(res, seg.query(x.first, x.second+1));\n    \
    \  }else{\n        res = op(res, rseg.query(x.second, x.first+1));\n      }\n\
    \    }\n    return res;\n  }\n};\n\nstruct Data {\n  mint a,b;\n};\nData e(){\n\
    \  return { 1, 0 };\n}\nData op(const Data &l, const Data &m){\n  return { l.a*m.a,\
    \ l.b*m.a + m.b };\n}\nData rev_op(const Data &l, const Data &m){\n  return {\
    \ m.a*l.a, m.b*l.a + l.b };\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"../graph/template.hpp\"\n#include \"\
    ../math/mint.hpp\"\n#include \"../SegmentTree/segtree.hpp\"\nusing namespace std;\n\
    \ntemplate <class T, T(*op)(const T&,const T&), T(*rev_op)(const T&,const T&),\
    \ T(*e)()>\nstruct HLD {\n  graph root;\n  int n, in_cnt = 0;\n  vector<int> pre,\
    \ sh, sz, p;\n  SegmentTree<T,op,e> seg;\n  SegmentTree<T,rev_op,e> rseg;\n  HLD(const\
    \ graph &g) : root(g), n(g.size()), pre(n), sh(n), sz(n), p(n), seg(n), rseg(n){\n\
    \    size(0, -1);\n    calc(0, -1, 0);\n  }\n  void size(int pos, int par){\n\
    \    sz[pos] = 1;\n    int mx = -1, idx = -1, cnt = -1;\n    for(const int &x\
    \ : root[pos]){\n      cnt++;\n      if(x == par) continue;\n      size(x, pos);\n\
    \      sz[pos] += sz[x];\n      if(chmax(mx, sz[x])) idx = cnt;\n    }\n    if(idx\
    \ != -1) swap(root[pos][0], root[pos][idx]);\n  }\n  void calc(int pos, int par,\
    \ int v){\n    p[pos] = in_cnt++;\n    sh[pos] = v;\n    pre[pos] = par;\n   \
    \ int cnt = -1;\n    for(const int &x : root[pos]){\n      cnt++;\n      if(x\
    \ == par) continue;\n      if(cnt) calc(x, pos, x);\n      else calc(x, pos, v);\n\
    \    }\n  }\n  void set(int u, const T &x){\n    seg.set(p[u], x);\n    rseg.set(p[u],\
    \ x);\n  }\n  void build(){\n    seg.build();\n    rseg.build();\n  }\n\n  void\
    \ update(int u, const T &x){\n    seg.update(p[u], x);\n    rseg.update(p[u],\
    \ x);\n  }\n  vector<pair<int,int>> query_path(int u, int v){\n    vector<pair<int,int>>\
    \ lef, rig;\n    while(sh[u] != sh[v]){\n      if(p[u] < p[v]){\n        rig.emplace_back(p[sh[v]],\
    \ p[v]);\n        v = pre[sh[v]];\n      }\n      else{\n        lef.emplace_back(p[u],\
    \ p[sh[u]]);\n        u = pre[sh[u]];\n      }\n    }\n    if(p[u] < p[v]) rig.emplace_back(p[u],\
    \ p[v]);\n    else lef.emplace_back(p[u], p[v]);\n    reverse(all(rig));\n   \
    \ lef.insert(lef.end(), all(rig));\n    return lef;\n  }\n  T query(int u, int\
    \ v){\n    T res = e();\n    for(const auto &x : query_path(u, v)){\n      if(x.first\
    \ <= x.second){\n        res = op(res, seg.query(x.first, x.second+1));\n    \
    \  }else{\n        res = op(res, rseg.query(x.second, x.first+1));\n      }\n\
    \    }\n    return res;\n  }\n};\n\nstruct Data {\n  mint a,b;\n};\nData e(){\n\
    \  return { 1, 0 };\n}\nData op(const Data &l, const Data &m){\n  return { l.a*m.a,\
    \ l.b*m.a + m.b };\n}\nData rev_op(const Data &l, const Data &m){\n  return {\
    \ m.a*l.a, m.b*l.a + l.b };\n}\n"
  dependsOn:
  - graph/template.hpp
  - math/mint.hpp
  - SegmentTree/segtree.hpp
  isVerificationFile: false
  path: data-structure/hld.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/hld.cpp
layout: document
redirect_from:
- /library/data-structure/hld.cpp
- /library/data-structure/hld.cpp.html
title: data-structure/hld.cpp
---
