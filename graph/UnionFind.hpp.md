---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/check-bipartite.hpp
    title: graph/check-bipartite.hpp
  - icon: ':warning:'
    path: graph/kruskal.hpp
    title: graph/kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Unionfind.test.cpp
    title: test/yosupo/Unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/UnionFind.hpp\"\nstruct UnionFind {\r\n  private:\r\
    \n  int n;\r\n  public:\r\n  vector<int> d;\r\n  UnionFind(int n): n(n), d(n,\
    \ -1){}\r\n  int root(int x){\r\n    assert(0 <= x && x < n);\r\n    if(d[x] <\
    \ 0) return x;\r\n    return d[x] = root(d[x]);\r\n  }\r\n  bool unite(int x,\
    \ int y){\r\n    x = root(x);\r\n    y = root(y);\r\n    if(x == y) return false;\r\
    \n    if(d[x] > d[y]) swap(x, y);\r\n    d[x] += d[y];\r\n    d[y] = x;\r\n  \
    \  return true;\r\n  }\r\n  bool same(int x, int y){\r\n    return root(x) ==\
    \ root(y);\r\n  }\r\n  int size(int x){\r\n    return -d[root(x)];\r\n  }\r\n\
    };\r\n"
  code: "struct UnionFind {\r\n  private:\r\n  int n;\r\n  public:\r\n  vector<int>\
    \ d;\r\n  UnionFind(int n): n(n), d(n, -1){}\r\n  int root(int x){\r\n    assert(0\
    \ <= x && x < n);\r\n    if(d[x] < 0) return x;\r\n    return d[x] = root(d[x]);\r\
    \n  }\r\n  bool unite(int x, int y){\r\n    x = root(x);\r\n    y = root(y);\r\
    \n    if(x == y) return false;\r\n    if(d[x] > d[y]) swap(x, y);\r\n    d[x]\
    \ += d[y];\r\n    d[y] = x;\r\n    return true;\r\n  }\r\n  bool same(int x, int\
    \ y){\r\n    return root(x) == root(y);\r\n  }\r\n  int size(int x){\r\n    return\
    \ -d[root(x)];\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/UnionFind.hpp
  requiredBy:
  - graph/kruskal.hpp
  - graph/check-bipartite.hpp
  timestamp: '2023-03-13 15:00:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Unionfind.test.cpp
documentation_of: graph/UnionFind.hpp
layout: document
redirect_from:
- /library/graph/UnionFind.hpp
- /library/graph/UnionFind.hpp.html
title: graph/UnionFind.hpp
---
