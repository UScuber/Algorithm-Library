---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/segtree.hpp
    title: SegmentTree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/HLD.hpp
    title: data-structure/HLD.hpp
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: Graph Template
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\r\n\r\
    \n#line 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\
    \n#include <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <utility>\r\
    \n#include <tuple>\r\n#include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\
    \n#include <queue>\r\n#include <set>\r\n#include <stack>\r\n#include <deque>\r\
    \n#include <unordered_map>\r\n#include <unordered_set>\r\n#include <bitset>\r\n\
    #include <cctype>\r\n#include <climits>\r\n#include <functional>\r\n#include <cassert>\r\
    \n#include <numeric>\r\n#define rep(i, n) for(int i = 0; i < (n); i++)\r\n#define\
    \ per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\nusing ll = long long;\r\n#define\
    \ vi vector<int>\r\n#define vvi vector<vi>\r\n#define vl vector<ll>\r\n#define\
    \ pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define all(a) (a).begin(),\
    \ (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\nconstexpr int mod =\
    \ 1000000007;\r\nusing namespace std;\r\ntemplate<class T, class U>\r\nbool chmax(T\
    \ &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\ntemplate<class T, class\
    \ U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }\n#line\
    \ 4 \"test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp\"\n\r\n#line 2 \"\
    graph/template.hpp\"\n\r\n/**\r\n * @brief Graph Template\r\n*/\r\ntemplate <class\
    \ T>\r\nstruct Edge {\r\n  int from,to;\r\n  T cost;\r\n  int idx;\r\n  Edge(){};\r\
    \n  Edge(int f, int t, T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}\r\n\
    \  Edge(int t) : to(t), from(-1), cost(1), idx(-1){}\r\n  operator int() const{\
    \ return to; }\r\n  bool operator<(const Edge &e){ return cost < e.cost; }\r\n\
    };\r\ntemplate <class T>\r\nstruct Graph : vector<vector<Edge<T>>> {\r\n  Graph(){}\r\
    \n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\r\n  void add_edge(int\
    \ a, int b, T c=1, int i=-1){\r\n    (*this)[a].push_back({ a, b, c, i });\r\n\
    \  }\r\n};\r\nusing graph = Graph<int>;\n#line 1 \"SegmentTree/segtree.hpp\"\n\
    template <class T, T(*op)(const T&,const T&), T(*e)()>\r\nstruct SegmentTree {\r\
    \n  SegmentTree(const int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\n\
    \    len = 1 << log;\r\n    d.resize(len * 2, e());\r\n  }\r\n  void update(int\
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
    \n  }\r\n  template <class F>\r\n  int max_right(int l, F f) const{\r\n    assert(0\
    \ <= l && l <= n);\r\n    assert(f(e()));\r\n    if(l == n) return n;\r\n    l\
    \ += len;\r\n    T sm = e();\r\n    do {\r\n      l /= l & -l;\r\n      if(!f(op(sm,\
    \ d[l]))){\r\n        while(l < len){\r\n          l <<= 1;\r\n          if(f(op(sm,\
    \ d[l]))){\r\n            sm = op(sm, d[l]);\r\n            l++;\r\n         \
    \ }\r\n        }\r\n        return l - len;\r\n      }\r\n      sm = op(sm, d[l]);\r\
    \n      l++;\r\n    }while(l & (l - 1));\r\n    return n;\r\n  }\r\n  template\
    \ <class F>\r\n  int min_left(int r, F f) const{\r\n    assert(0 <= r && r <=\
    \ n);\r\n    assert(f(e()));\r\n    if(r == 0) return 0;\r\n    r += len;\r\n\
    \    T sm = e();\r\n    do {\r\n      r /= r & -r;\r\n      if(r > 1) r--;\r\n\
    \      if(!f(op(d[r], sm))){\r\n        while(r < len){\r\n          r = r * 2\
    \ + 1;\r\n          if(f(op(d[r], sm))){\r\n            sm = op(d[r], sm);\r\n\
    \            r--;\r\n          }\r\n        }\r\n        return r + 1 - len;\r\
    \n      }\r\n      sm = op(d[r], sm);\r\n    }while(r & (r - 1));\r\n    return\
    \ 0;\r\n  }\r\n  private:\r\n  int n = 1, log = 0, len = 0;\r\n  vector<T> d;\r\
    \n};\n#line 3 \"data-structure/HLD.hpp\"\n\r\ntemplate <class T, T(*op)(const\
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
    \ res;\r\n  }\r\n  T get(const int i){ return seg.get(p[i]); }\r\n};\n#line 6\
    \ \"test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp\"\n\r\nusing Data\
    \ = ll;\r\n\r\nData e(){ return 0; }\r\nData op(const Data &a, const Data &b){\r\
    \n  return a + b;\r\n}\r\nData rev_op(const Data &a, const Data &b){\r\n  return\
    \ a + b;\r\n}\r\n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  int n,q;\r\n  cin >> n >> q;\r\n  vi a(n);\r\n  rep(i, n) cin >> a[i];\r\n\
    \  graph root(n);\r\n  rep(i, n - 1){\r\n    int a,b;\r\n    cin >> a >> b;\r\n\
    \    root[a].push_back(b);\r\n    root[b].push_back(a);\r\n  }\r\n  HLD<Data,op,rev_op,e>\
    \ hld(root);\r\n  rep(i, n) hld.set(i, a[i]);\r\n  hld.build();\r\n  int t,p,x,u,v;\r\
    \n  rep(_, q){\r\n    cin >> t;\r\n    if(t == 0){\r\n      cin >> p >> x;\r\n\
    \      hld.update(p, hld.get(p) + x);\r\n    }else{\r\n      cin >> u >> v;\r\n\
    \      cout << hld.query(u, v) << \"\\n\";\r\n    }\r\n  }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\r\
    \n\r\n#include \"../../../template/template.hpp\"\r\n\r\n#include \"../../../data-structure/HLD.hpp\"\
    \r\n\r\nusing Data = ll;\r\n\r\nData e(){ return 0; }\r\nData op(const Data &a,\
    \ const Data &b){\r\n  return a + b;\r\n}\r\nData rev_op(const Data &a, const\
    \ Data &b){\r\n  return a + b;\r\n}\r\n\r\nint main(){\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  int n,q;\r\n  cin >> n >> q;\r\n  vi a(n);\r\
    \n  rep(i, n) cin >> a[i];\r\n  graph root(n);\r\n  rep(i, n - 1){\r\n    int\
    \ a,b;\r\n    cin >> a >> b;\r\n    root[a].push_back(b);\r\n    root[b].push_back(a);\r\
    \n  }\r\n  HLD<Data,op,rev_op,e> hld(root);\r\n  rep(i, n) hld.set(i, a[i]);\r\
    \n  hld.build();\r\n  int t,p,x,u,v;\r\n  rep(_, q){\r\n    cin >> t;\r\n    if(t\
    \ == 0){\r\n      cin >> p >> x;\r\n      hld.update(p, hld.get(p) + x);\r\n \
    \   }else{\r\n      cin >> u >> v;\r\n      cout << hld.query(u, v) << \"\\n\"\
    ;\r\n    }\r\n  }\r\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/HLD.hpp
  - graph/template.hpp
  - SegmentTree/segtree.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-07-10 18:11:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
- /verify/test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp.html
title: test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
---
