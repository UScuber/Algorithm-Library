---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/UnionFind.hpp
    title: graph/UnionFind.hpp
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: Graph Template
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
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 1 \"graph/UnionFind.hpp\"\
    \nstruct UnionFind {\r\n  private:\r\n  int n;\r\n  public:\r\n  vector<int> d;\r\
    \n  UnionFind(int n): n(n), d(n, -1){}\r\n  int root(int x){\r\n    assert(0 <=\
    \ x && x < n);\r\n    if(d[x] < 0) return x;\r\n    return d[x] = root(d[x]);\r\
    \n  }\r\n  bool unite(int x, int y){\r\n    x = root(x);\r\n    y = root(y);\r\
    \n    if(x == y) return false;\r\n    if(d[x] > d[y]) swap(x, y);\r\n    d[x]\
    \ += d[y];\r\n    d[y] = x;\r\n    return true;\r\n  }\r\n  bool same(int x, int\
    \ y){\r\n    return root(x) == root(y);\r\n  }\r\n  int size(int x){\r\n    return\
    \ -d[root(x)];\r\n  }\r\n};\r\n#line 3 \"graph/check-bipartite.hpp\"\n\r\ntemplate\
    \ <class T>\r\nbool is_bipartite(const Graph<T> &g){\r\n  const int n = g.size();\r\
    \n  UnionFind tree(n * 2);\r\n  for(int i = 0; i < n; i++) for(const auto &x :\
    \ g[i]){\r\n    tree.unite(x.from, x.to+n);\r\n    tree.unite(x.from+n, x.to);\r\
    \n  }\r\n  for(int i = 0; i < n; i++) for(const auto &x : g[i]){\r\n    if(tree.same(x.from,\
    \ x.to+n)) return false;\r\n  }\r\n  return true;\r\n}\n"
  code: "#include \"template.hpp\"\r\n#include \"UnionFind.hpp\"\r\n\r\ntemplate <class\
    \ T>\r\nbool is_bipartite(const Graph<T> &g){\r\n  const int n = g.size();\r\n\
    \  UnionFind tree(n * 2);\r\n  for(int i = 0; i < n; i++) for(const auto &x :\
    \ g[i]){\r\n    tree.unite(x.from, x.to+n);\r\n    tree.unite(x.from+n, x.to);\r\
    \n  }\r\n  for(int i = 0; i < n; i++) for(const auto &x : g[i]){\r\n    if(tree.same(x.from,\
    \ x.to+n)) return false;\r\n  }\r\n  return true;\r\n}"
  dependsOn:
  - graph/template.hpp
  - graph/UnionFind.hpp
  isVerificationFile: false
  path: graph/check-bipartite.hpp
  requiredBy: []
  timestamp: '2023-03-13 15:00:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/check-bipartite.hpp
layout: document
redirect_from:
- /library/graph/check-bipartite.hpp
- /library/graph/check-bipartite.hpp.html
title: graph/check-bipartite.hpp
---
