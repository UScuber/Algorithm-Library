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
  bundledCode: "#line 1 \"graph/unionfind.hpp\"\nstruct UnionFind {\r\n  private:\r\
    \n  int n;\r\n  public:\r\n  vector<int> d;\r\n  UnionFind(int n): n(n), d(n,\
    \ -1){}\r\n  int root(int x){\r\n    assert(0 <= x && x < n);\r\n    if(d[x] <\
    \ 0) return x;\r\n    return d[x] = root(d[x]);\r\n  }\r\n  bool unite(int x,\
    \ int y){\r\n    x = root(x);\r\n    y = root(y);\r\n    if(x == y) return false;\r\
    \n    if(d[x] > d[y]) swap(x, y);\r\n    d[x] += d[y];\r\n    d[y] = x;\r\n  \
    \  return true;\r\n  }\r\n  bool same(int x, int y){\r\n    return root(x) ==\
    \ root(y);\r\n  }\r\n  int size(int x){\r\n    return -d[root(x)];\r\n  }\r\n\
    };\n"
  code: "struct UnionFind {\r\n  private:\r\n  int n;\r\n  public:\r\n  vector<int>\
    \ d;\r\n  UnionFind(int n): n(n), d(n, -1){}\r\n  int root(int x){\r\n    assert(0\
    \ <= x && x < n);\r\n    if(d[x] < 0) return x;\r\n    return d[x] = root(d[x]);\r\
    \n  }\r\n  bool unite(int x, int y){\r\n    x = root(x);\r\n    y = root(y);\r\
    \n    if(x == y) return false;\r\n    if(d[x] > d[y]) swap(x, y);\r\n    d[x]\
    \ += d[y];\r\n    d[y] = x;\r\n    return true;\r\n  }\r\n  bool same(int x, int\
    \ y){\r\n    return root(x) == root(y);\r\n  }\r\n  int size(int x){\r\n    return\
    \ -d[root(x)];\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/unionfind.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/unionfind.hpp
layout: document
redirect_from:
- /library/graph/unionfind.hpp
- /library/graph/unionfind.hpp.html
title: graph/unionfind.hpp
---
