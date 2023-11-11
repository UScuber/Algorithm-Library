---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Graph/Shortest-Path.test.cpp
    title: test/yosupo/Graph/Shortest-Path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"graph/dijkstra.hpp\"\
    \n\ntemplate <class T, class U = T>\nvoid dijkstra(const Graph<T> &root, const\
    \ int s, vector<U> &dist, vector<int> &prev){\n  const int n = root.size();\n\
    \  dist.assign(n, numeric_limits<U>::max());\n  prev.assign(n, -1);\n  using pui\
    \ = pair<U, int>;\n  priority_queue<pui, vector<pui>, greater<pui>> que;\n  que.push({\
    \ 0, s });\n  while(!que.empty()){\n    U val; int pos;\n    tie(val,pos) = que.top();\n\
    \    que.pop();\n    if(dist[pos] < val) continue;\n    for(const auto &x : root[pos]){\n\
    \      if(chmin(dist[x], val + x.cost)){\n        que.push({ dist[x], x });\n\
    \        prev[x] = pos;\n      }\n    }\n  }\n}\n"
  code: "#include \"template.hpp\"\n\ntemplate <class T, class U = T>\nvoid dijkstra(const\
    \ Graph<T> &root, const int s, vector<U> &dist, vector<int> &prev){\n  const int\
    \ n = root.size();\n  dist.assign(n, numeric_limits<U>::max());\n  prev.assign(n,\
    \ -1);\n  using pui = pair<U, int>;\n  priority_queue<pui, vector<pui>, greater<pui>>\
    \ que;\n  que.push({ 0, s });\n  while(!que.empty()){\n    U val; int pos;\n \
    \   tie(val,pos) = que.top();\n    que.pop();\n    if(dist[pos] < val) continue;\n\
    \    for(const auto &x : root[pos]){\n      if(chmin(dist[x], val + x.cost)){\n\
    \        que.push({ dist[x], x });\n        prev[x] = pos;\n      }\n    }\n \
    \ }\n}"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2023-11-10 15:24:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Graph/Shortest-Path.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
redirect_from:
- /library/graph/dijkstra.hpp
- /library/graph/dijkstra.hpp.html
title: graph/dijkstra.hpp
---
