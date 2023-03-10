---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/hld.cpp
    title: data-structure/hld.cpp
  - icon: ':warning:'
    path: graph/bellman-ford.cpp
    title: graph/bellman-ford.cpp
  - icon: ':warning:'
    path: graph/center.cpp
    title: graph/center.cpp
  - icon: ':warning:'
    path: graph/check-bipartite.cpp
    title: graph/check-bipartite.cpp
  - icon: ':warning:'
    path: graph/cycle-detect.cpp
    title: graph/cycle-detect.cpp
  - icon: ':warning:'
    path: graph/diameter.cpp
    title: graph/diameter.cpp
  - icon: ':warning:'
    path: graph/kruskal.cpp
    title: graph/kruskal.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T>\nstruct Edge {\n  int from,to;\n  T cost;\n  int\
    \ idx;\n  Edge(){};\n  Edge(int f, int t, T c=1, int i=-1) : from(f), to(t), cost(c),\
    \ idx(i){}\n  Edge(int t) : to(t), from(-1), cost(1), idx(-1){}\n  operator int()\
    \ const{ return to; }\n  bool operator<(const Edge &e){ return cost < e.cost;\
    \ }\n};\ntemplate <class T>\nstruct Graph : vector<vector<Edge<T>>> {\n  Graph(){}\n\
    \  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\n  void add_edge(int a,\
    \ int b, T c=1, int i=-1){\n    (*this)[a].push_back({ a, b, c, i });\n  }\n};\n\
    using graph = Graph<int>;\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ Edge {\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){};\n  Edge(int f, int\
    \ t, T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}\n  Edge(int t) : to(t),\
    \ from(-1), cost(1), idx(-1){}\n  operator int() const{ return to; }\n  bool operator<(const\
    \ Edge &e){ return cost < e.cost; }\n};\ntemplate <class T>\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\n  Graph(){}\n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\n  void\
    \ add_edge(int a, int b, T c=1, int i=-1){\n    (*this)[a].push_back({ a, b, c,\
    \ i });\n  }\n};\nusing graph = Graph<int>;"
  dependsOn: []
  isVerificationFile: false
  path: graph/template.hpp
  requiredBy:
  - data-structure/hld.cpp
  - graph/kruskal.cpp
  - graph/check-bipartite.cpp
  - graph/diameter.cpp
  - graph/bellman-ford.cpp
  - graph/cycle-detect.cpp
  - graph/center.cpp
  timestamp: '2022-03-01 22:20:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/template.hpp
layout: document
redirect_from:
- /library/graph/template.hpp
- /library/graph/template.hpp.html
title: graph/template.hpp
---
