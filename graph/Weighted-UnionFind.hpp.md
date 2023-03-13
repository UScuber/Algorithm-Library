---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/Weighted-UnionFind.test.cpp
    title: test/aoj/Weighted-UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Weighted-UnionFind.hpp\"\ntemplate <class T>\r\nstruct\
    \ UnionFindW {\r\n  vector<int> par, rank;\r\n  vector<T> diff_weight;\r\n\r\n\
    \  UnionFindW(int n = 1, T sum_unity = 0) : n(n), par(n), rank(n), diff_weight(n){\r\
    \n    for(int i = 0; i < n; i++) par[i] = i, rank[i] = 0, diff_weight[i] = sum_unity;\r\
    \n  }\r\n  int root(int x){\r\n    assert(0 <= x && x < n);\r\n    if(par[x] ==\
    \ x){\r\n      return x;\r\n    }else{\r\n      const int r = root(par[x]);\r\n\
    \      diff_weight[x] += diff_weight[par[x]];\r\n      return par[x] = r;\r\n\
    \    }\r\n  }\r\n  T weight(int x){\r\n    root(x);\r\n    return diff_weight[x];\r\
    \n  }\r\n  bool same(int x, int y){\r\n    return root(x) == root(y);\r\n  }\r\
    \n  bool merge(int x, int y, T w){\r\n    w += weight(x); w -= weight(y);\r\n\
    \    x = root(x); y = root(y);\r\n    if(x == y) return false;\r\n    if(rank[x]\
    \ < rank[y]) swap(x, y), w = -w;\r\n    if(rank[x] == rank[y]) ++rank[x];\r\n\
    \    par[y] = x;\r\n    diff_weight[y] = w;\r\n    return true;\r\n  }\r\n  T\
    \ diff(int x, int y){\r\n    return weight(y) - weight(x);\r\n  }\r\n  private:\r\
    \n  int n;\r\n};\n"
  code: "template <class T>\r\nstruct UnionFindW {\r\n  vector<int> par, rank;\r\n\
    \  vector<T> diff_weight;\r\n\r\n  UnionFindW(int n = 1, T sum_unity = 0) : n(n),\
    \ par(n), rank(n), diff_weight(n){\r\n    for(int i = 0; i < n; i++) par[i] =\
    \ i, rank[i] = 0, diff_weight[i] = sum_unity;\r\n  }\r\n  int root(int x){\r\n\
    \    assert(0 <= x && x < n);\r\n    if(par[x] == x){\r\n      return x;\r\n \
    \   }else{\r\n      const int r = root(par[x]);\r\n      diff_weight[x] += diff_weight[par[x]];\r\
    \n      return par[x] = r;\r\n    }\r\n  }\r\n  T weight(int x){\r\n    root(x);\r\
    \n    return diff_weight[x];\r\n  }\r\n  bool same(int x, int y){\r\n    return\
    \ root(x) == root(y);\r\n  }\r\n  bool merge(int x, int y, T w){\r\n    w += weight(x);\
    \ w -= weight(y);\r\n    x = root(x); y = root(y);\r\n    if(x == y) return false;\r\
    \n    if(rank[x] < rank[y]) swap(x, y), w = -w;\r\n    if(rank[x] == rank[y])\
    \ ++rank[x];\r\n    par[y] = x;\r\n    diff_weight[y] = w;\r\n    return true;\r\
    \n  }\r\n  T diff(int x, int y){\r\n    return weight(y) - weight(x);\r\n  }\r\
    \n  private:\r\n  int n;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/Weighted-UnionFind.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/Weighted-UnionFind.test.cpp
documentation_of: graph/Weighted-UnionFind.hpp
layout: document
redirect_from:
- /library/graph/Weighted-UnionFind.hpp
- /library/graph/Weighted-UnionFind.hpp.html
title: graph/Weighted-UnionFind.hpp
---
