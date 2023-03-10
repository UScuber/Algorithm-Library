---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/center.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"\
    graph/template.hpp\"\nusing namespace std;\n\ntemplate <class T>\nstruct Edge\
    \ {\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){};\n  Edge(int f, int t,\
    \ T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}\n  Edge(int t) : to(t),\
    \ from(-1), cost(1), idx(-1){}\n  operator int() const{ return to; }\n  bool operator<(const\
    \ Edge &e){ return cost < e.cost; }\n};\ntemplate <class T>\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\n  Graph(){}\n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\n  void\
    \ add_edge(int a, int b, T c=1, int i=-1){\n    (*this)[a].push_back({ a, b, c,\
    \ i });\n  }\n};\nusing graph = Graph<int>;\n#line 3 \"graph/center.cpp\"\nusing\
    \ namespace std;\n\n#line 6 \"graph/center.cpp\"\ntemplate <class graph>\npair<vector<int>,\
    \ int> find_centor(const graph &g){\n  const int n = g.size();\n  vector<int>\
    \ dist(n), prev(n, -1);\n  function<void(int,int)> dfs = [&](int pos, int par){\n\
    \    for(const auto &x : g[pos]) if(x != par){\n      dist[x] = dist[pos] + 1;\n\
    \      prev[x] = pos;\n      dfs(x, pos);\n    }\n  };\n  dfs(0, -1);\n  int pos\
    \ = max_element(dist.begin(), dist.end()) - dist.begin();\n  dist.assign(n, 0);\
    \ prev.assign(n, -1);\n  dfs(pos, -1);\n  pos = max_element(dist.begin(), dist.end())\
    \ - dist.begin();\n  const int longest = dist[pos];\n  int max_dist = longest;\n\
    \  vector<int> res;\n  for(int i = pos; i != -1; i = prev[i]){\n    if(max_dist\
    \ == longest/2 || max_dist == (longest+1)/2) res.push_back(i);\n    max_dist--;\n\
    \  }\n  return { res, longest };\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"template.hpp\"\nusing namespace std;\n\
    \n#include <functional>\ntemplate <class graph>\npair<vector<int>, int> find_centor(const\
    \ graph &g){\n  const int n = g.size();\n  vector<int> dist(n), prev(n, -1);\n\
    \  function<void(int,int)> dfs = [&](int pos, int par){\n    for(const auto &x\
    \ : g[pos]) if(x != par){\n      dist[x] = dist[pos] + 1;\n      prev[x] = pos;\n\
    \      dfs(x, pos);\n    }\n  };\n  dfs(0, -1);\n  int pos = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\n  dist.assign(n, 0); prev.assign(n, -1);\n  dfs(pos,\
    \ -1);\n  pos = max_element(dist.begin(), dist.end()) - dist.begin();\n  const\
    \ int longest = dist[pos];\n  int max_dist = longest;\n  vector<int> res;\n  for(int\
    \ i = pos; i != -1; i = prev[i]){\n    if(max_dist == longest/2 || max_dist ==\
    \ (longest+1)/2) res.push_back(i);\n    max_dist--;\n  }\n  return { res, longest\
    \ };\n}"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/center.cpp
  requiredBy: []
  timestamp: '2022-07-19 13:01:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/center.cpp
layout: document
redirect_from:
- /library/graph/center.cpp
- /library/graph/center.cpp.html
title: graph/center.cpp
---
