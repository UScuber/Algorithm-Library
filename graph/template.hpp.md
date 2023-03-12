---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/HLD.hpp
    title: data-structure/HLD.hpp
  - icon: ':warning:'
    path: graph/bellman-ford.hpp
    title: graph/bellman-ford.hpp
  - icon: ':warning:'
    path: graph/center.hpp
    title: graph/center.hpp
  - icon: ':warning:'
    path: graph/cycle-detect.hpp
    title: graph/cycle-detect.hpp
  - icon: ':warning:'
    path: graph/diameter.hpp
    title: graph/diameter.hpp
  - icon: ':warning:'
    path: graph/dinic.hpp
    title: graph/dinic.hpp
  - icon: ':warning:'
    path: graph/lca.hpp
    title: graph/lca.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Graph Template
    links: []
  bundledCode: "#line 2 \"graph/template.hpp\"\n\r\n/**\r\n * @brief Graph Template\r\
    \n*/\r\ntemplate <class T>\r\nstruct Edge {\r\n  int from,to;\r\n  T cost;\r\n\
    \  int idx;\r\n  Edge(){};\r\n  Edge(int f, int t, T c=1, int i=-1) : from(f),\
    \ to(t), cost(c), idx(i){}\r\n  Edge(int t) : to(t), from(-1), cost(1), idx(-1){}\r\
    \n  operator int() const{ return to; }\r\n  bool operator<(const Edge &e){ return\
    \ cost < e.cost; }\r\n};\r\ntemplate <class T>\r\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\r\n  Graph(){}\r\n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\r\n\
    \  void add_edge(int a, int b, T c=1, int i=-1){\r\n    (*this)[a].push_back({\
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n"
  code: "#pragma once\r\n\r\n/**\r\n * @brief Graph Template\r\n*/\r\ntemplate <class\
    \ T>\r\nstruct Edge {\r\n  int from,to;\r\n  T cost;\r\n  int idx;\r\n  Edge(){};\r\
    \n  Edge(int f, int t, T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}\r\n\
    \  Edge(int t) : to(t), from(-1), cost(1), idx(-1){}\r\n  operator int() const{\
    \ return to; }\r\n  bool operator<(const Edge &e){ return cost < e.cost; }\r\n\
    };\r\ntemplate <class T>\r\nstruct Graph : vector<vector<Edge<T>>> {\r\n  Graph(){}\r\
    \n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\r\n  void add_edge(int\
    \ a, int b, T c=1, int i=-1){\r\n    (*this)[a].push_back({ a, b, c, i });\r\n\
    \  }\r\n};\r\nusing graph = Graph<int>;"
  dependsOn: []
  isVerificationFile: false
  path: graph/template.hpp
  requiredBy:
  - data-structure/HLD.hpp
  - graph/center.hpp
  - graph/diameter.hpp
  - graph/cycle-detect.hpp
  - graph/dinic.hpp
  - graph/lca.hpp
  - graph/bellman-ford.hpp
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/template.hpp
layout: document
redirect_from:
- /library/graph/template.hpp
- /library/graph/template.hpp.html
title: Graph Template
---
