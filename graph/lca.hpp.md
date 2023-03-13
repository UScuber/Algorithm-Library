---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_5_C.test.cpp
    title: test/aoj/GRL/GRL_5_C.test.cpp
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
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"graph/lca.hpp\"\
    \n\r\ntemplate <class graph>\r\nstruct lca {\r\n  const graph &G;\r\n  vector<vector<int>>\
    \ parent;\r\n  vector<int> dep;\r\n  int log = 1;\r\n  lca(const graph &G, int\
    \ root = 0) : G(G){\r\n    init(root);\r\n  }\r\n  void init(int root = 0){\r\n\
    \    const int n = G.size();\r\n    dep.assign(n, -1);\r\n    parent.assign(1,\
    \ vector<int>(n, -1));\r\n    queue<int> que({ root });\r\n    dep[root] = 0;\r\
    \n    int max_dep = 0;\r\n    while(!que.empty()){\r\n      const int pos = que.front();\r\
    \n      que.pop();\r\n      max_dep = max(max_dep, dep[pos]);\r\n      for(const\
    \ auto &x : G[pos]){\r\n        if(dep[x] == -1){\r\n          dep[x] = dep[pos]\
    \ + 1;\r\n          parent[0][x] = pos;\r\n          que.push(x);\r\n        }\r\
    \n      }\r\n    }\r\n    while((1 << log) <= max_dep) log++;\r\n    parent.resize(log,\
    \ vector<int>(n, -1));\r\n    for(int k = 0; k < log - 1; k++){\r\n      for(int\
    \ v = 0; v < n; v++){\r\n        if(parent[k][v] < 0) parent[k + 1][v] = -1;\r\
    \n        else parent[k + 1][v] = parent[k][parent[k][v]];\r\n      }\r\n    }\r\
    \n  }\r\n  int query(int u, int v) const{\r\n    if(dep[u] < dep[v]) swap(u, v);\r\
    \n    const int sub = dep[u] - dep[v];\r\n    for(int k = 0; k < log; k++){\r\n\
    \      if(!(sub >> k)) break;\r\n      if(sub >> k & 1) u = parent[k][u];\r\n\
    \    }\r\n    if(u == v) return u;\r\n    for(int k = __lg(dep[u]); k >= 0; k--){\r\
    \n      if(parent[k][u] != parent[k][v]){\r\n        u = parent[k][u];\r\n   \
    \     v = parent[k][v];\r\n      }\r\n    }\r\n    return parent[0][u];\r\n  }\r\
    \n  int dist(const int u, const int v) const{\r\n    return dep[u] + dep[v] -\
    \ dep[query(u, v)] * 2;\r\n  }\r\n  int jump(int u, int v, const int d) const{\r\
    \n    const int lc = query(u, v);\r\n    const int l = dep[u] - dep[lc];\r\n \
    \   const int r = dep[v] - dep[lc];\r\n    assert(0 <= d && d <= l + r);\r\n \
    \   if(l < d){\r\n      d = l + r - d;\r\n      swap(u, v);\r\n    }\r\n    for(int\
    \ k = 0; k < log; k++){\r\n      if(!(d >> k)) break;\r\n      if(d >> k & 1)\
    \ u = parent[k][u];\r\n    }\r\n    return u;\r\n  }\r\n};\n"
  code: "#include \"template.hpp\"\r\n\r\ntemplate <class graph>\r\nstruct lca {\r\
    \n  const graph &G;\r\n  vector<vector<int>> parent;\r\n  vector<int> dep;\r\n\
    \  int log = 1;\r\n  lca(const graph &G, int root = 0) : G(G){\r\n    init(root);\r\
    \n  }\r\n  void init(int root = 0){\r\n    const int n = G.size();\r\n    dep.assign(n,\
    \ -1);\r\n    parent.assign(1, vector<int>(n, -1));\r\n    queue<int> que({ root\
    \ });\r\n    dep[root] = 0;\r\n    int max_dep = 0;\r\n    while(!que.empty()){\r\
    \n      const int pos = que.front();\r\n      que.pop();\r\n      max_dep = max(max_dep,\
    \ dep[pos]);\r\n      for(const auto &x : G[pos]){\r\n        if(dep[x] == -1){\r\
    \n          dep[x] = dep[pos] + 1;\r\n          parent[0][x] = pos;\r\n      \
    \    que.push(x);\r\n        }\r\n      }\r\n    }\r\n    while((1 << log) <=\
    \ max_dep) log++;\r\n    parent.resize(log, vector<int>(n, -1));\r\n    for(int\
    \ k = 0; k < log - 1; k++){\r\n      for(int v = 0; v < n; v++){\r\n        if(parent[k][v]\
    \ < 0) parent[k + 1][v] = -1;\r\n        else parent[k + 1][v] = parent[k][parent[k][v]];\r\
    \n      }\r\n    }\r\n  }\r\n  int query(int u, int v) const{\r\n    if(dep[u]\
    \ < dep[v]) swap(u, v);\r\n    const int sub = dep[u] - dep[v];\r\n    for(int\
    \ k = 0; k < log; k++){\r\n      if(!(sub >> k)) break;\r\n      if(sub >> k &\
    \ 1) u = parent[k][u];\r\n    }\r\n    if(u == v) return u;\r\n    for(int k =\
    \ __lg(dep[u]); k >= 0; k--){\r\n      if(parent[k][u] != parent[k][v]){\r\n \
    \       u = parent[k][u];\r\n        v = parent[k][v];\r\n      }\r\n    }\r\n\
    \    return parent[0][u];\r\n  }\r\n  int dist(const int u, const int v) const{\r\
    \n    return dep[u] + dep[v] - dep[query(u, v)] * 2;\r\n  }\r\n  int jump(int\
    \ u, int v, const int d) const{\r\n    const int lc = query(u, v);\r\n    const\
    \ int l = dep[u] - dep[lc];\r\n    const int r = dep[v] - dep[lc];\r\n    assert(0\
    \ <= d && d <= l + r);\r\n    if(l < d){\r\n      d = l + r - d;\r\n      swap(u,\
    \ v);\r\n    }\r\n    for(int k = 0; k < log; k++){\r\n      if(!(d >> k)) break;\r\
    \n      if(d >> k & 1) u = parent[k][u];\r\n    }\r\n    return u;\r\n  }\r\n\
    };"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/lca.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_5_C.test.cpp
documentation_of: graph/lca.hpp
layout: document
redirect_from:
- /library/graph/lca.hpp
- /library/graph/lca.hpp.html
title: graph/lca.hpp
---
