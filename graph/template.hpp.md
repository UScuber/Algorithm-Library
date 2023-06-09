---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/HLD.hpp
    title: data-structure/HLD.hpp
  - icon: ':heavy_check_mark:'
    path: graph/bellman-ford.hpp
    title: "Bellman Ford\u6CD5"
  - icon: ':warning:'
    path: graph/center.hpp
    title: "\u6728\u306E\u4E2D\u5FC3"
  - icon: ':warning:'
    path: graph/check-bipartite.hpp
    title: graph/check-bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: graph/cycle-detect.hpp
    title: "Cycle Detect(\u30B5\u30A4\u30AF\u30EB\u691C\u51FA)"
  - icon: ':heavy_check_mark:'
    path: graph/diameter.hpp
    title: "Diameter(\u6728\u306E\u76F4\u5F84)"
  - icon: ':heavy_check_mark:'
    path: graph/dinic.hpp
    title: graph/dinic.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_1_B.test.cpp
    title: test/aoj/GRL/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_2_A.test.cpp
    title: test/aoj/GRL/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_6_A2.test.cpp
    title: test/aoj/GRL/GRL_6_A2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Graph/Cycle-Detection(Directed).test.cpp
    title: test/yosupo/Graph/Cycle-Detection(Directed).test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Tree/Tree-Diameter.test.cpp
    title: test/yosupo/Tree/Tree-Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - graph/diameter.hpp
  - graph/check-bipartite.hpp
  - graph/bellman-ford.hpp
  - graph/cycle-detect.hpp
  - graph/dinic.hpp
  - graph/center.hpp
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_6_A2.test.cpp
  - test/aoj/GRL/GRL_1_B.test.cpp
  - test/aoj/GRL/GRL_2_A.test.cpp
  - test/yosupo/Tree/Tree-Diameter.test.cpp
  - test/yosupo/Data-Structure/Vertex-Add-Path-Sum.test.cpp
  - test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - test/yosupo/Graph/Cycle-Detection(Directed).test.cpp
documentation_of: graph/template.hpp
layout: document
redirect_from:
- /library/graph/template.hpp
- /library/graph/template.hpp.html
title: Graph Template
---
