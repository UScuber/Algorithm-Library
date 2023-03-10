---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/template.hpp
    title: graph/template.hpp
  - icon: ':warning:'
    path: graph/unionfind.hpp
    title: graph/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/check-bipartite.cpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"graph/unionfind.hpp\"\nusing namespace std;\n\n//Union Find\nstruct\
    \ UnionFind {\n  private:\n  int n;\n  public:\n  vector<int> d;\n  UnionFind(int\
    \ n): n(n), d(n, -1){}\n  int root(int x){\n    assert(0 <= x && x < n);\n   \
    \ if(d[x] < 0) return x;\n    return d[x] = root(d[x]);\n  }\n  bool unite(int\
    \ x, int y){\n    x = root(x);\n    y = root(y);\n    if(x == y) return false;\n\
    \    if(d[x] > d[y]) swap(x, y);\n    d[x] += d[y];\n    d[y] = x;\n    return\
    \ true;\n  }\n  bool same(int x, int y){\n    return root(x) == root(y);\n  }\n\
    \  int size(int x){\n    return -d[root(x)];\n  }\n};\n\n\n\n\n//\u91CD\u307F\u4ED8\
    \u304DUnion Find\ntemplate <class T>\nstruct UnionFindW {\n  vector<int> par,\
    \ rank;\n  vector<T> diff_weight;\n\n  UnionFindW(int n = 1, T sum_unity = 0)\
    \ : n(n), par(n), rank(n), diff_weight(n){\n    for(int i = 0; i < n; i++) par[i]\
    \ = i, rank[i] = 0, diff_weight[i] = sum_unity;\n  }\n  int root(int x){\n   \
    \ assert(0 <= x && x < n);\n    if(par[x] == x){\n      return x;\n    }else{\n\
    \      const int r = root(par[x]);\n      diff_weight[x] += diff_weight[par[x]];\n\
    \      return par[x] = r;\n    }\n  }\n  T weight(int x){\n    root(x);\n    return\
    \ diff_weight[x];\n  }\n  bool same(int x, int y){\n    return root(x) == root(y);\n\
    \  }\n  bool merge(int x, int y, T w){\n    w += weight(x); w -= weight(y);\n\
    \    x = root(x); y = root(y);\n    if(x == y) return false;\n    if(rank[x] <\
    \ rank[y]) swap(x, y), w = -w;\n    if(rank[x] == rank[y]) ++rank[x];\n    par[y]\
    \ = x;\n    diff_weight[y] = w;\n    return true;\n  }\n  T diff(int x, int y){\n\
    \    return weight(y) - weight(x);\n  }\n  private:\n  int n;\n};\n\n\n\n//Undo\u4ED8\
    \u304DUnionFind\nstruct UndoUnionFind {\n  private:\n  int n;\n  stack<pair<int,int>>\
    \ hist;\n  public:\n  vector<int> d;\n  UndoUnionFind(int n): n(n), d(n, -1){}\n\
    \  int root(int x){\n    assert(0 <= x && x < n);\n    if(d[x] < 0) return x;\n\
    \    return d[x] = root(d[x]);\n  }\n  bool unite(int x, int y){\n    x = root(x);\n\
    \    y = root(y);\n    hist.emplace(x, d[x]);\n    hist.emplace(y, d[y]);\n  \
    \  if(x == y) return false;\n    if(d[x] > d[y]) swap(x, y);\n    d[x] += d[y];\n\
    \    d[y] = x;\n    return true;\n  }\n  bool same(int x, int y){\n    return\
    \ root(x) == root(y);\n  }\n  int size(int x){\n    return -d[root(x)];\n  }\n\
    \  void undo(){\n    assert(!hist.empty());\n    d[hist.top().first] = hist.top().second;\n\
    \    hist.pop();\n    d[hist.top().first] = hist.top().second;\n    hist.pop();\n\
    \  }\n  void snapshot(){\n    while(!hist.empty()) hist.pop();\n  }\n  void rollback(){\n\
    \    while(!hist.empty()) undo();\n  }\n};\n#line 2 \"graph/template.hpp\"\nusing\
    \ namespace std;\n\ntemplate <class T>\nstruct Edge {\n  int from,to;\n  T cost;\n\
    \  int idx;\n  Edge(){};\n  Edge(int f, int t, T c=1, int i=-1) : from(f), to(t),\
    \ cost(c), idx(i){}\n  Edge(int t) : to(t), from(-1), cost(1), idx(-1){}\n  operator\
    \ int() const{ return to; }\n  bool operator<(const Edge &e){ return cost < e.cost;\
    \ }\n};\ntemplate <class T>\nstruct Graph : vector<vector<Edge<T>>> {\n  Graph(){}\n\
    \  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\n  void add_edge(int a,\
    \ int b, T c=1, int i=-1){\n    (*this)[a].push_back({ a, b, c, i });\n  }\n};\n\
    using graph = Graph<int>;\n#line 4 \"graph/check-bipartite.cpp\"\nusing namespace\
    \ std;\n\ntemplate <class T>\nbool is_bipartite(const Graph<T> &g){\n  const int\
    \ n = g.size();\n  UnionFind tree(n * 2);\n  for(int i = 0; i < n; i++) for(const\
    \ auto &x : g[i]){\n    tree.unite(x.from, x.to+n);\n    tree.unite(x.from+n,\
    \ x.to);\n  }\n  for(int i = 0; i < n; i++) for(const auto &x : g[i]){\n    if(tree.same(x.from,\
    \ x.to+n)) return false;\n  }\n  return true;\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"unionfind.hpp\"\n#include \"template.hpp\"\
    \nusing namespace std;\n\ntemplate <class T>\nbool is_bipartite(const Graph<T>\
    \ &g){\n  const int n = g.size();\n  UnionFind tree(n * 2);\n  for(int i = 0;\
    \ i < n; i++) for(const auto &x : g[i]){\n    tree.unite(x.from, x.to+n);\n  \
    \  tree.unite(x.from+n, x.to);\n  }\n  for(int i = 0; i < n; i++) for(const auto\
    \ &x : g[i]){\n    if(tree.same(x.from, x.to+n)) return false;\n  }\n  return\
    \ true;\n}"
  dependsOn:
  - graph/unionfind.hpp
  - graph/template.hpp
  isVerificationFile: false
  path: graph/check-bipartite.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/check-bipartite.cpp
layout: document
redirect_from:
- /library/graph/check-bipartite.cpp
- /library/graph/check-bipartite.cpp.html
title: graph/check-bipartite.cpp
---
