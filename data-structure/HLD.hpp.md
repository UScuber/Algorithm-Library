---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: SegmentTree/segtree.hpp
    title: SegmentTree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: Graph Template
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: math/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/template.hpp\"\n\r\n/**\r\n * @brief Graph Template\r\
    \n*/\r\ntemplate <class T>\r\nstruct Edge {\r\n  int from,to;\r\n  T cost;\r\n\
    \  int idx;\r\n  Edge(){};\r\n  Edge(int f, int t, T c=1, int i=-1) : from(f),\
    \ to(t), cost(c), idx(i){}\r\n  Edge(int t) : to(t), from(-1), cost(1), idx(-1){}\r\
    \n  operator int() const{ return to; }\r\n  bool operator<(const Edge &e){ return\
    \ cost < e.cost; }\r\n};\r\ntemplate <class T>\r\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\r\n  Graph(){}\r\n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\r\n\
    \  void add_edge(int a, int b, T c=1, int i=-1){\r\n    (*this)[a].push_back({\
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"math/mint.hpp\"\
    \n\r\ntemplate <int mod>\r\nstruct Mint {\r\n  ll x;\r\n  constexpr Mint(ll x\
    \ = 0) : x((x + mod) % mod){}\r\n  static constexpr int get_mod(){ return mod;\
    \ }\r\n  constexpr Mint operator-() const{ return Mint(-x); }\r\n  constexpr Mint\
    \ operator+=(const Mint &a){\r\n    if((x += a.x) >= mod) x -= mod;\r\n    return\
    \ *this;\r\n  }\r\n  constexpr Mint &operator++(){\r\n    if(++x == mod) x = 0;\r\
    \n    return *this;\r\n  }\r\n  constexpr Mint operator++(int){\r\n    Mint temp\
    \ = *this;\r\n    if(++x == mod) x = 0;\r\n    return temp;\r\n  }\r\n  constexpr\
    \ Mint &operator-=(const Mint &a){\r\n    if((x -= a.x) < 0) x += mod;\r\n   \
    \ return *this;\r\n  }\r\n  constexpr Mint &operator--(){\r\n    if(--x < 0) x\
    \ += mod;\r\n    return *this;\r\n  }\r\n  constexpr Mint operator--(int){\r\n\
    \    Mint temp = *this;\r\n    if(--x < 0) x += mod;\r\n    return temp;\r\n \
    \ }\r\n  constexpr Mint &operator*=(const Mint &a){\r\n    (x *= a.x) %= mod;\r\
    \n    return *this;\r\n  }\r\n  constexpr Mint operator+(const Mint &a) const{\
    \ return Mint(*this) += a; }\r\n  constexpr Mint operator-(const Mint &a) const{\
    \ return Mint(*this) -= a; }\r\n  constexpr Mint operator*(const Mint &a) const{\
    \ return Mint(*this) *= a; }\r\n  constexpr Mint pow(ll t) const{\r\n    if(!t)\
    \ return 1;\r\n    Mint res = 1, v = *this;\r\n    while(t){\r\n      if(t & 1)\
    \ res *= v;\r\n      v *= v;\r\n      t >>= 1;\r\n    }\r\n    return res;\r\n\
    \  }\r\n  constexpr Mint inv() const{ return pow(mod - 2); }\r\n  constexpr Mint\
    \ &operator/=(const Mint &a){ return (*this) *= a.inv(); }\r\n  constexpr Mint\
    \ operator/(const Mint &a) const{ return Mint(*this) /= a; }\r\n  constexpr bool\
    \ operator==(const Mint &a) const{ return x == a.x; }\r\n  constexpr bool operator!=(const\
    \ Mint &a) const{ return x != a.x; }\r\n  constexpr bool operator<(const Mint\
    \ &a) const{ return x < a.x; }\r\n  constexpr bool operator>(const Mint &a) const{\
    \ return x > a.x; }\r\n  friend istream &operator>>(istream &is, Mint &a){ return\
    \ is >> a.x; }\r\n  friend ostream &operator<<(ostream &os, const Mint &a){ return\
    \ os << a.x; }\r\n};\r\n//using mint = Mint<1000000007>;\n#line 1 \"SegmentTree/segtree.hpp\"\
    \ntemplate <class T, T(*op)(const T&,const T&), T(*e)()>\r\nstruct SegmentTree\
    \ {\r\n  SegmentTree(const int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\
    \n    len = 1 << log;\r\n    d.resize(len * 2, e());\r\n  }\r\n  void update(int\
    \ k, const T &x){\r\n    assert(0 <= k && k < n);\r\n    k += len;\r\n    d[k]\
    \ = x;\r\n    while(k > 1){\r\n      k >>= 1;\r\n      d[k] = op(d[k*2], d[k*2+1]);\r\
    \n    }\r\n  }\r\n  void set(const int i, const T &x){\r\n    assert(0 <= i &&\
    \ i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T get(const int i) const{\r\n   \
    \ assert(0 <= i && i < n);\r\n    return d[i + len];\r\n  }\r\n  void build(){\r\
    \n    for(int k = len - 1; k >= 1; k--)\r\n      d[k] = op(d[2*k], d[2*k+1]);\r\
    \n  }\r\n  T query(int l, int r){\r\n    assert(0 <= l && l <= r && r <= n);\r\
    \n    l += len; r += len;\r\n    T left = e(), right = e();\r\n    while(l < r){\r\
    \n      if(l & 1) left = op(left, d[l++]);\r\n      if(r & 1) right = op(d[--r],\
    \ right);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    return op(left, right);\r\
    \n  }\r\n  private:\r\n  int n = 1, log = 0, len = 0;\r\n  vector<T> d;\r\n};\r\
    \n\r\n/*\r\nstruct Data {\r\n  int a;\r\n};\r\nData op(const Data &a, const Data\
    \ &b){\r\n  return { min(a.a, b.a) };\r\n}\r\nData e(){\r\n  return { 0 };\r\n\
    }\r\n*/\n#line 4 \"data-structure/HLD.hpp\"\n\r\ntemplate <class T, T(*op)(const\
    \ T&,const T&), T(*rev_op)(const T&,const T&), T(*e)()>\r\nstruct HLD {\r\n  graph\
    \ root;\r\n  int n, in_cnt = 0;\r\n  vector<int> pre, sh, sz, p;\r\n  SegmentTree<T,op,e>\
    \ seg;\r\n  SegmentTree<T,rev_op,e> rseg;\r\n  HLD(const graph &g) : root(g),\
    \ n(g.size()), pre(n), sh(n), sz(n), p(n), seg(n), rseg(n){\r\n    size(0, -1);\r\
    \n    calc(0, -1, 0);\r\n  }\r\n  void size(int pos, int par){\r\n    sz[pos]\
    \ = 1;\r\n    int mx = -1, idx = -1, cnt = -1;\r\n    for(const int &x : root[pos]){\r\
    \n      cnt++;\r\n      if(x == par) continue;\r\n      size(x, pos);\r\n    \
    \  sz[pos] += sz[x];\r\n      if(chmax(mx, sz[x])) idx = cnt;\r\n    }\r\n   \
    \ if(idx != -1) swap(root[pos][0], root[pos][idx]);\r\n  }\r\n  void calc(int\
    \ pos, int par, int v){\r\n    p[pos] = in_cnt++;\r\n    sh[pos] = v;\r\n    pre[pos]\
    \ = par;\r\n    int cnt = -1;\r\n    for(const int &x : root[pos]){\r\n      cnt++;\r\
    \n      if(x == par) continue;\r\n      if(cnt) calc(x, pos, x);\r\n      else\
    \ calc(x, pos, v);\r\n    }\r\n  }\r\n  void set(int u, const T &x){\r\n    seg.set(p[u],\
    \ x);\r\n    rseg.set(p[u], x);\r\n  }\r\n  void build(){\r\n    seg.build();\r\
    \n    rseg.build();\r\n  }\r\n\r\n  void update(int u, const T &x){\r\n    seg.update(p[u],\
    \ x);\r\n    rseg.update(p[u], x);\r\n  }\r\n  vector<pair<int,int>> query_path(int\
    \ u, int v){\r\n    vector<pair<int,int>> lef, rig;\r\n    while(sh[u] != sh[v]){\r\
    \n      if(p[u] < p[v]){\r\n        rig.emplace_back(p[sh[v]], p[v]);\r\n    \
    \    v = pre[sh[v]];\r\n      }\r\n      else{\r\n        lef.emplace_back(p[u],\
    \ p[sh[u]]);\r\n        u = pre[sh[u]];\r\n      }\r\n    }\r\n    if(p[u] < p[v])\
    \ rig.emplace_back(p[u], p[v]);\r\n    else lef.emplace_back(p[u], p[v]);\r\n\
    \    reverse(all(rig));\r\n    lef.insert(lef.end(), all(rig));\r\n    return\
    \ lef;\r\n  }\r\n  T query(int u, int v){\r\n    T res = e();\r\n    for(const\
    \ auto &x : query_path(u, v)){\r\n      if(x.first <= x.second){\r\n        res\
    \ = op(res, seg.query(x.first, x.second+1));\r\n      }else{\r\n        res =\
    \ op(res, rseg.query(x.second, x.first+1));\r\n      }\r\n    }\r\n    return\
    \ res;\r\n  }\r\n};\r\n\r\nstruct Data {\r\n  mint a,b;\r\n};\r\nData e(){\r\n\
    \  return { 1, 0 };\r\n}\r\nData op(const Data &l, const Data &m){\r\n  return\
    \ { l.a*m.a, l.b*m.a + m.b };\r\n}\r\nData rev_op(const Data &l, const Data &m){\r\
    \n  return { m.a*l.a, m.b*l.a + l.b };\r\n}\r\n"
  code: "#include \"../graph/template.hpp\"\r\n#include \"../math/mint.hpp\"\r\n#include\
    \ \"../SegmentTree/segtree.hpp\"\r\n\r\ntemplate <class T, T(*op)(const T&,const\
    \ T&), T(*rev_op)(const T&,const T&), T(*e)()>\r\nstruct HLD {\r\n  graph root;\r\
    \n  int n, in_cnt = 0;\r\n  vector<int> pre, sh, sz, p;\r\n  SegmentTree<T,op,e>\
    \ seg;\r\n  SegmentTree<T,rev_op,e> rseg;\r\n  HLD(const graph &g) : root(g),\
    \ n(g.size()), pre(n), sh(n), sz(n), p(n), seg(n), rseg(n){\r\n    size(0, -1);\r\
    \n    calc(0, -1, 0);\r\n  }\r\n  void size(int pos, int par){\r\n    sz[pos]\
    \ = 1;\r\n    int mx = -1, idx = -1, cnt = -1;\r\n    for(const int &x : root[pos]){\r\
    \n      cnt++;\r\n      if(x == par) continue;\r\n      size(x, pos);\r\n    \
    \  sz[pos] += sz[x];\r\n      if(chmax(mx, sz[x])) idx = cnt;\r\n    }\r\n   \
    \ if(idx != -1) swap(root[pos][0], root[pos][idx]);\r\n  }\r\n  void calc(int\
    \ pos, int par, int v){\r\n    p[pos] = in_cnt++;\r\n    sh[pos] = v;\r\n    pre[pos]\
    \ = par;\r\n    int cnt = -1;\r\n    for(const int &x : root[pos]){\r\n      cnt++;\r\
    \n      if(x == par) continue;\r\n      if(cnt) calc(x, pos, x);\r\n      else\
    \ calc(x, pos, v);\r\n    }\r\n  }\r\n  void set(int u, const T &x){\r\n    seg.set(p[u],\
    \ x);\r\n    rseg.set(p[u], x);\r\n  }\r\n  void build(){\r\n    seg.build();\r\
    \n    rseg.build();\r\n  }\r\n\r\n  void update(int u, const T &x){\r\n    seg.update(p[u],\
    \ x);\r\n    rseg.update(p[u], x);\r\n  }\r\n  vector<pair<int,int>> query_path(int\
    \ u, int v){\r\n    vector<pair<int,int>> lef, rig;\r\n    while(sh[u] != sh[v]){\r\
    \n      if(p[u] < p[v]){\r\n        rig.emplace_back(p[sh[v]], p[v]);\r\n    \
    \    v = pre[sh[v]];\r\n      }\r\n      else{\r\n        lef.emplace_back(p[u],\
    \ p[sh[u]]);\r\n        u = pre[sh[u]];\r\n      }\r\n    }\r\n    if(p[u] < p[v])\
    \ rig.emplace_back(p[u], p[v]);\r\n    else lef.emplace_back(p[u], p[v]);\r\n\
    \    reverse(all(rig));\r\n    lef.insert(lef.end(), all(rig));\r\n    return\
    \ lef;\r\n  }\r\n  T query(int u, int v){\r\n    T res = e();\r\n    for(const\
    \ auto &x : query_path(u, v)){\r\n      if(x.first <= x.second){\r\n        res\
    \ = op(res, seg.query(x.first, x.second+1));\r\n      }else{\r\n        res =\
    \ op(res, rseg.query(x.second, x.first+1));\r\n      }\r\n    }\r\n    return\
    \ res;\r\n  }\r\n};\r\n\r\nstruct Data {\r\n  mint a,b;\r\n};\r\nData e(){\r\n\
    \  return { 1, 0 };\r\n}\r\nData op(const Data &l, const Data &m){\r\n  return\
    \ { l.a*m.a, l.b*m.a + m.b };\r\n}\r\nData rev_op(const Data &l, const Data &m){\r\
    \n  return { m.a*l.a, m.b*l.a + l.b };\r\n}\r\n"
  dependsOn:
  - graph/template.hpp
  - math/mint.hpp
  - SegmentTree/segtree.hpp
  isVerificationFile: false
  path: data-structure/HLD.hpp
  requiredBy: []
  timestamp: '2023-03-13 14:46:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/HLD.hpp
layout: document
redirect_from:
- /library/data-structure/HLD.hpp
- /library/data-structure/HLD.hpp.html
title: data-structure/HLD.hpp
---
