---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/check-bipartite.cpp
    title: graph/check-bipartite.cpp
  - icon: ':warning:'
    path: graph/kruskal.cpp
    title: graph/kruskal.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/unionfind.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n//Union Find\nstruct UnionFind {\n  private:\n  int n;\n  public:\n\
    \  vector<int> d;\n  UnionFind(int n): n(n), d(n, -1){}\n  int root(int x){\n\
    \    assert(0 <= x && x < n);\n    if(d[x] < 0) return x;\n    return d[x] = root(d[x]);\n\
    \  }\n  bool unite(int x, int y){\n    x = root(x);\n    y = root(y);\n    if(x\
    \ == y) return false;\n    if(d[x] > d[y]) swap(x, y);\n    d[x] += d[y];\n  \
    \  d[y] = x;\n    return true;\n  }\n  bool same(int x, int y){\n    return root(x)\
    \ == root(y);\n  }\n  int size(int x){\n    return -d[root(x)];\n  }\n};\n\n\n\
    \n\n//\u91CD\u307F\u4ED8\u304DUnion Find\ntemplate <class T>\nstruct UnionFindW\
    \ {\n  vector<int> par, rank;\n  vector<T> diff_weight;\n\n  UnionFindW(int n\
    \ = 1, T sum_unity = 0) : n(n), par(n), rank(n), diff_weight(n){\n    for(int\
    \ i = 0; i < n; i++) par[i] = i, rank[i] = 0, diff_weight[i] = sum_unity;\n  }\n\
    \  int root(int x){\n    assert(0 <= x && x < n);\n    if(par[x] == x){\n    \
    \  return x;\n    }else{\n      const int r = root(par[x]);\n      diff_weight[x]\
    \ += diff_weight[par[x]];\n      return par[x] = r;\n    }\n  }\n  T weight(int\
    \ x){\n    root(x);\n    return diff_weight[x];\n  }\n  bool same(int x, int y){\n\
    \    return root(x) == root(y);\n  }\n  bool merge(int x, int y, T w){\n    w\
    \ += weight(x); w -= weight(y);\n    x = root(x); y = root(y);\n    if(x == y)\
    \ return false;\n    if(rank[x] < rank[y]) swap(x, y), w = -w;\n    if(rank[x]\
    \ == rank[y]) ++rank[x];\n    par[y] = x;\n    diff_weight[y] = w;\n    return\
    \ true;\n  }\n  T diff(int x, int y){\n    return weight(y) - weight(x);\n  }\n\
    \  private:\n  int n;\n};\n\n\n\n//Undo\u4ED8\u304DUnionFind\nstruct UndoUnionFind\
    \ {\n  private:\n  int n;\n  stack<pair<int,int>> hist;\n  public:\n  vector<int>\
    \ d;\n  UndoUnionFind(int n): n(n), d(n, -1){}\n  int root(int x){\n    assert(0\
    \ <= x && x < n);\n    if(d[x] < 0) return x;\n    return d[x] = root(d[x]);\n\
    \  }\n  bool unite(int x, int y){\n    x = root(x);\n    y = root(y);\n    hist.emplace(x,\
    \ d[x]);\n    hist.emplace(y, d[y]);\n    if(x == y) return false;\n    if(d[x]\
    \ > d[y]) swap(x, y);\n    d[x] += d[y];\n    d[y] = x;\n    return true;\n  }\n\
    \  bool same(int x, int y){\n    return root(x) == root(y);\n  }\n  int size(int\
    \ x){\n    return -d[root(x)];\n  }\n  void undo(){\n    assert(!hist.empty());\n\
    \    d[hist.top().first] = hist.top().second;\n    hist.pop();\n    d[hist.top().first]\
    \ = hist.top().second;\n    hist.pop();\n  }\n  void snapshot(){\n    while(!hist.empty())\
    \ hist.pop();\n  }\n  void rollback(){\n    while(!hist.empty()) undo();\n  }\n\
    };\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//Union Find\nstruct UnionFind\
    \ {\n  private:\n  int n;\n  public:\n  vector<int> d;\n  UnionFind(int n): n(n),\
    \ d(n, -1){}\n  int root(int x){\n    assert(0 <= x && x < n);\n    if(d[x] <\
    \ 0) return x;\n    return d[x] = root(d[x]);\n  }\n  bool unite(int x, int y){\n\
    \    x = root(x);\n    y = root(y);\n    if(x == y) return false;\n    if(d[x]\
    \ > d[y]) swap(x, y);\n    d[x] += d[y];\n    d[y] = x;\n    return true;\n  }\n\
    \  bool same(int x, int y){\n    return root(x) == root(y);\n  }\n  int size(int\
    \ x){\n    return -d[root(x)];\n  }\n};\n\n\n\n\n//\u91CD\u307F\u4ED8\u304DUnion\
    \ Find\ntemplate <class T>\nstruct UnionFindW {\n  vector<int> par, rank;\n  vector<T>\
    \ diff_weight;\n\n  UnionFindW(int n = 1, T sum_unity = 0) : n(n), par(n), rank(n),\
    \ diff_weight(n){\n    for(int i = 0; i < n; i++) par[i] = i, rank[i] = 0, diff_weight[i]\
    \ = sum_unity;\n  }\n  int root(int x){\n    assert(0 <= x && x < n);\n    if(par[x]\
    \ == x){\n      return x;\n    }else{\n      const int r = root(par[x]);\n   \
    \   diff_weight[x] += diff_weight[par[x]];\n      return par[x] = r;\n    }\n\
    \  }\n  T weight(int x){\n    root(x);\n    return diff_weight[x];\n  }\n  bool\
    \ same(int x, int y){\n    return root(x) == root(y);\n  }\n  bool merge(int x,\
    \ int y, T w){\n    w += weight(x); w -= weight(y);\n    x = root(x); y = root(y);\n\
    \    if(x == y) return false;\n    if(rank[x] < rank[y]) swap(x, y), w = -w;\n\
    \    if(rank[x] == rank[y]) ++rank[x];\n    par[y] = x;\n    diff_weight[y] =\
    \ w;\n    return true;\n  }\n  T diff(int x, int y){\n    return weight(y) - weight(x);\n\
    \  }\n  private:\n  int n;\n};\n\n\n\n//Undo\u4ED8\u304DUnionFind\nstruct UndoUnionFind\
    \ {\n  private:\n  int n;\n  stack<pair<int,int>> hist;\n  public:\n  vector<int>\
    \ d;\n  UndoUnionFind(int n): n(n), d(n, -1){}\n  int root(int x){\n    assert(0\
    \ <= x && x < n);\n    if(d[x] < 0) return x;\n    return d[x] = root(d[x]);\n\
    \  }\n  bool unite(int x, int y){\n    x = root(x);\n    y = root(y);\n    hist.emplace(x,\
    \ d[x]);\n    hist.emplace(y, d[y]);\n    if(x == y) return false;\n    if(d[x]\
    \ > d[y]) swap(x, y);\n    d[x] += d[y];\n    d[y] = x;\n    return true;\n  }\n\
    \  bool same(int x, int y){\n    return root(x) == root(y);\n  }\n  int size(int\
    \ x){\n    return -d[root(x)];\n  }\n  void undo(){\n    assert(!hist.empty());\n\
    \    d[hist.top().first] = hist.top().second;\n    hist.pop();\n    d[hist.top().first]\
    \ = hist.top().second;\n    hist.pop();\n  }\n  void snapshot(){\n    while(!hist.empty())\
    \ hist.pop();\n  }\n  void rollback(){\n    while(!hist.empty()) undo();\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: graph/unionfind.hpp
  requiredBy:
  - graph/kruskal.cpp
  - graph/check-bipartite.cpp
  timestamp: '2022-12-06 01:04:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/unionfind.hpp
layout: document
redirect_from:
- /library/graph/unionfind.hpp
- /library/graph/unionfind.hpp.html
title: graph/unionfind.hpp
---
