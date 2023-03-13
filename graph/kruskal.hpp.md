---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/UnionFind.hpp
    title: graph/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    };\r\n#line 2 \"graph/kruskal.hpp\"\n\r\ntemplate <class T>\r\nll kruskal(vector<Edge<T>>\
    \ &es, const int n){\r\n  ll res = 0;\r\n  sort(es.begin(), es.end());\r\n  UnionFind\
    \ tree(n);\r\n  for(const auto &e : es){\r\n    if(!tree.same(e.from, e.to)){\r\
    \n      tree.unite(e.from, e.to);\r\n      res += e.cost;\r\n    }\r\n  }\r\n\
    \  return res;\r\n}\n"
  code: "#include \"UnionFind.hpp\"\r\n\r\ntemplate <class T>\r\nll kruskal(vector<Edge<T>>\
    \ &es, const int n){\r\n  ll res = 0;\r\n  sort(es.begin(), es.end());\r\n  UnionFind\
    \ tree(n);\r\n  for(const auto &e : es){\r\n    if(!tree.same(e.from, e.to)){\r\
    \n      tree.unite(e.from, e.to);\r\n      res += e.cost;\r\n    }\r\n  }\r\n\
    \  return res;\r\n}"
  dependsOn:
  - graph/UnionFind.hpp
  isVerificationFile: false
  path: graph/kruskal.hpp
  requiredBy: []
  timestamp: '2023-03-13 15:00:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/kruskal.hpp
layout: document
redirect_from:
- /library/graph/kruskal.hpp
- /library/graph/kruskal.hpp.html
title: graph/kruskal.hpp
---
