---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/Graph/Strongly-Connected-Components.test.cpp
    title: test/yosupo/Graph/Strongly-Connected-Components.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/scc.hpp\"\ntemplate <class graph>\r\nstruct scc {\r\
    \n  scc(const graph &g): root(g), n(g.size()){ init(); }\r\n  void init(){\r\n\
    \    rroot.resize(n);\r\n    used.resize(n);\r\n    ord.resize(n);\r\n    comp.resize(n,\
    \ -1);\r\n    build();\r\n  }\r\n  void build(){\r\n    for(int i = 0; i < n;\
    \ i++){\r\n      for(const auto &x : root[i])\r\n        rroot[x].push_back(i);\r\
    \n    }\r\n    for(int i = 0; i < n; i++) dfs(i);\r\n    reverse(ord.begin(),\
    \ ord.end());\r\n    int cnt = 0;\r\n    for(const auto &x : ord) if(comp[x] ==\
    \ -1){\r\n      rdfs(x, cnt);\r\n      cnt++;\r\n    }\r\n    dag.resize(cnt);\r\
    \n    group.resize(cnt);\r\n    for(int i = 0; i < n; i++){\r\n      for(const\
    \ auto &x : root[i]){\r\n        const int a = comp[i], b = comp[x];\r\n     \
    \   if(a == b) continue;\r\n        dag[a].push_back(b);\r\n      }\r\n    }\r\
    \n    for(int i = 0; i < n; i++){\r\n      group[comp[i]].push_back(i);\r\n  \
    \  }\r\n  }\r\n  int operator[](int i) const{\r\n    return comp[i];\r\n  }\r\n\
    \  vector<vector<int>> group, dag;\r\n  private:\r\n  int n = 0;\r\n  const graph\
    \ &root;\r\n  graph rroot; //rev\r\n  vector<int> used, ord, comp;\r\n  void dfs(int\
    \ pos){\r\n    if(used[pos]) return;\r\n    used[pos] = 1;\r\n    for(const auto\
    \ &x : root[pos]) dfs(x);\r\n    ord.push_back(pos);\r\n  }\r\n  void rdfs(int\
    \ pos, const int cnt){\r\n    if(comp[pos] != -1) return;\r\n    comp[pos] = cnt;\r\
    \n    for(const auto &x : rroot[pos]) rdfs(x, cnt);\r\n  }\r\n};\n"
  code: "template <class graph>\r\nstruct scc {\r\n  scc(const graph &g): root(g),\
    \ n(g.size()){ init(); }\r\n  void init(){\r\n    rroot.resize(n);\r\n    used.resize(n);\r\
    \n    ord.resize(n);\r\n    comp.resize(n, -1);\r\n    build();\r\n  }\r\n  void\
    \ build(){\r\n    for(int i = 0; i < n; i++){\r\n      for(const auto &x : root[i])\r\
    \n        rroot[x].push_back(i);\r\n    }\r\n    for(int i = 0; i < n; i++) dfs(i);\r\
    \n    reverse(ord.begin(), ord.end());\r\n    int cnt = 0;\r\n    for(const auto\
    \ &x : ord) if(comp[x] == -1){\r\n      rdfs(x, cnt);\r\n      cnt++;\r\n    }\r\
    \n    dag.resize(cnt);\r\n    group.resize(cnt);\r\n    for(int i = 0; i < n;\
    \ i++){\r\n      for(const auto &x : root[i]){\r\n        const int a = comp[i],\
    \ b = comp[x];\r\n        if(a == b) continue;\r\n        dag[a].push_back(b);\r\
    \n      }\r\n    }\r\n    for(int i = 0; i < n; i++){\r\n      group[comp[i]].push_back(i);\r\
    \n    }\r\n  }\r\n  int operator[](int i) const{\r\n    return comp[i];\r\n  }\r\
    \n  vector<vector<int>> group, dag;\r\n  private:\r\n  int n = 0;\r\n  const graph\
    \ &root;\r\n  graph rroot; //rev\r\n  vector<int> used, ord, comp;\r\n  void dfs(int\
    \ pos){\r\n    if(used[pos]) return;\r\n    used[pos] = 1;\r\n    for(const auto\
    \ &x : root[pos]) dfs(x);\r\n    ord.push_back(pos);\r\n  }\r\n  void rdfs(int\
    \ pos, const int cnt){\r\n    if(comp[pos] != -1) return;\r\n    comp[pos] = cnt;\r\
    \n    for(const auto &x : rroot[pos]) rdfs(x, cnt);\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/Graph/Strongly-Connected-Components.test.cpp
documentation_of: graph/scc.hpp
layout: document
title: "SCC(Stronly Connected Components)(\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\
  )"
---

## 説明

- dag[i]: 分解後の頂点と辺からなるグラフ(DAG)
- group[i]: 分解後のグループiに入る頂点集合
- comp[i]: iが入っている成分のグループの番号

- Constructor
```cpp
scc(const graph &g);
```
