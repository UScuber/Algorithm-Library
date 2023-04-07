---
data:
  _extendedDependsOn:
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
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"graph/center.hpp\"\
    \n#include <functional>\r\n\r\ntemplate <class graph>\r\npair<vector<int>, int>\
    \ find_centor(const graph &g){\r\n  const int n = g.size();\r\n  vector<int> dist(n),\
    \ prev(n, -1);\r\n  function<void(int,int)> dfs = [&](int pos, int par){\r\n \
    \   for(const auto &x : g[pos]) if(x != par){\r\n      dist[x] = dist[pos] + 1;\r\
    \n      prev[x] = pos;\r\n      dfs(x, pos);\r\n    }\r\n  };\r\n  dfs(0, -1);\r\
    \n  int pos = max_element(dist.begin(), dist.end()) - dist.begin();\r\n  dist.assign(n,\
    \ 0); prev.assign(n, -1);\r\n  dfs(pos, -1);\r\n  pos = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\r\n  const int longest = dist[pos];\r\n  int max_dist\
    \ = longest;\r\n  vector<int> res;\r\n  for(int i = pos; i != -1; i = prev[i]){\r\
    \n    if(max_dist == longest/2 || max_dist == (longest+1)/2) res.push_back(i);\r\
    \n    max_dist--;\r\n  }\r\n  return { res, longest };\r\n}\n"
  code: "#include \"template.hpp\"\r\n#include <functional>\r\n\r\ntemplate <class\
    \ graph>\r\npair<vector<int>, int> find_centor(const graph &g){\r\n  const int\
    \ n = g.size();\r\n  vector<int> dist(n), prev(n, -1);\r\n  function<void(int,int)>\
    \ dfs = [&](int pos, int par){\r\n    for(const auto &x : g[pos]) if(x != par){\r\
    \n      dist[x] = dist[pos] + 1;\r\n      prev[x] = pos;\r\n      dfs(x, pos);\r\
    \n    }\r\n  };\r\n  dfs(0, -1);\r\n  int pos = max_element(dist.begin(), dist.end())\
    \ - dist.begin();\r\n  dist.assign(n, 0); prev.assign(n, -1);\r\n  dfs(pos, -1);\r\
    \n  pos = max_element(dist.begin(), dist.end()) - dist.begin();\r\n  const int\
    \ longest = dist[pos];\r\n  int max_dist = longest;\r\n  vector<int> res;\r\n\
    \  for(int i = pos; i != -1; i = prev[i]){\r\n    if(max_dist == longest/2 ||\
    \ max_dist == (longest+1)/2) res.push_back(i);\r\n    max_dist--;\r\n  }\r\n \
    \ return { res, longest };\r\n}"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/center.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/center.hpp
layout: document
redirect_from:
- /library/graph/center.hpp
- /library/graph/center.hpp.html
title: graph/center.hpp
---
