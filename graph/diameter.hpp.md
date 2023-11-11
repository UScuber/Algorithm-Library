---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/Tree/Tree-Diameter.test.cpp
    title: test/yosupo/Tree/Tree-Diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"graph/diameter.hpp\"\
    \n\r\ntemplate <class T>\r\npair<T, vector<int>> diameter(const Graph<T> &g){\r\
    \n  const int n = g.size();\r\n  vector<T> dist(n);\r\n  vector<int> prev(n, -1);\r\
    \n  function<void(int,int)> dfs = [&](int pos, int par){\r\n    for(auto &x :\
    \ g[pos]) if(x != par){\r\n      dist[x] = dist[pos] + x.cost;\r\n      prev[x]\
    \ = pos;\r\n      dfs(x, pos);\r\n    }\r\n  };\r\n  dfs(0, -1);\r\n  int pos\
    \ = max_element(dist.begin(), dist.end()) - dist.begin();\r\n  dist.assign(n,\
    \ 0); prev.assign(n, -1);\r\n  dfs(pos, -1);\r\n  pos = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\r\n  const T tot = dist[pos];\r\n  vector<int> res;\r\
    \n  for(int i = pos; i != -1; i = prev[i]) res.push_back(i);\r\n  return { tot,\
    \ res };\r\n}\n"
  code: "#include \"template.hpp\"\r\n\r\ntemplate <class T>\r\npair<T, vector<int>>\
    \ diameter(const Graph<T> &g){\r\n  const int n = g.size();\r\n  vector<T> dist(n);\r\
    \n  vector<int> prev(n, -1);\r\n  function<void(int,int)> dfs = [&](int pos, int\
    \ par){\r\n    for(auto &x : g[pos]) if(x != par){\r\n      dist[x] = dist[pos]\
    \ + x.cost;\r\n      prev[x] = pos;\r\n      dfs(x, pos);\r\n    }\r\n  };\r\n\
    \  dfs(0, -1);\r\n  int pos = max_element(dist.begin(), dist.end()) - dist.begin();\r\
    \n  dist.assign(n, 0); prev.assign(n, -1);\r\n  dfs(pos, -1);\r\n  pos = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\r\n  const T tot = dist[pos];\r\n  vector<int> res;\r\
    \n  for(int i = pos; i != -1; i = prev[i]) res.push_back(i);\r\n  return { tot,\
    \ res };\r\n}"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/diameter.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/Tree/Tree-Diameter.test.cpp
documentation_of: graph/diameter.hpp
layout: document
title: "Diameter(\u6728\u306E\u76F4\u5F84)"
---

## 説明

- グラフの直径を求める

```cpp
vector<int> diameter(const Graph<T> &g)
```
