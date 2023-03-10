---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/lca.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class graph>\nstruct lca {\n  const graph &G;\n  vector<vector<int>>\
    \ parent;\n  vector<int> dep;\n  int log = 1;\n  lca(const graph &G, int root\
    \ = 0) : G(G){\n    init(root);\n  }\n  void init(int root = 0){\n    const int\
    \ n = G.size();\n    dep.assign(n, -1);\n    parent.assign(1, vector<int>(n, -1));\n\
    \    queue<int> que({ root });\n    dep[root] = 0;\n    int max_dep = 0;\n   \
    \ while(!que.empty()){\n      const int pos = que.front();\n      que.pop();\n\
    \      max_dep = max(max_dep, dep[pos]);\n      for(const auto &x : G[pos]){\n\
    \        if(dep[x] == -1){\n          dep[x] = dep[pos] + 1;\n          parent[0][x]\
    \ = pos;\n          que.push(x);\n        }\n      }\n    }\n    while((1 << log)\
    \ <= max_dep) log++;\n    parent.resize(log, vector<int>(n, -1));\n    for(int\
    \ k = 0; k < log - 1; k++){\n      for(int v = 0; v < n; v++){\n        if(parent[k][v]\
    \ < 0) parent[k + 1][v] = -1;\n        else parent[k + 1][v] = parent[k][parent[k][v]];\n\
    \      }\n    }\n  }\n  int query(int u, int v) const{\n    if(dep[u] < dep[v])\
    \ swap(u, v);\n    const int sub = dep[u] - dep[v];\n    for(int k = 0; k < log;\
    \ k++){\n      if(!(sub >> k)) break;\n      if(sub >> k & 1) u = parent[k][u];\n\
    \    }\n    if(u == v) return u;\n    for(int k = __lg(dep[u]); k >= 0; k--){\n\
    \      if(parent[k][u] != parent[k][v]){\n        u = parent[k][u];\n        v\
    \ = parent[k][v];\n      }\n    }\n    return parent[0][u];\n  }\n  int dist(const\
    \ int u, const int v) const{\n    return dep[u] + dep[v] - dep[query(u, v)] *\
    \ 2;\n  }\n  int jump(int u, int v, const int d) const{\n    const int lc = query(u,\
    \ v);\n    const int l = dep[u] - dep[lc];\n    const int r = dep[v] - dep[lc];\n\
    \    assert(0 <= d && d <= l + r);\n    if(l < d){\n      d = l + r - d;\n   \
    \   swap(u, v);\n    }\n    for(int k = 0; k < log; k++){\n      if(!(d >> k))\
    \ break;\n      if(d >> k & 1) u = parent[k][u];\n    }\n    return u;\n  }\n\
    };\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class graph>\n\
    struct lca {\n  const graph &G;\n  vector<vector<int>> parent;\n  vector<int>\
    \ dep;\n  int log = 1;\n  lca(const graph &G, int root = 0) : G(G){\n    init(root);\n\
    \  }\n  void init(int root = 0){\n    const int n = G.size();\n    dep.assign(n,\
    \ -1);\n    parent.assign(1, vector<int>(n, -1));\n    queue<int> que({ root });\n\
    \    dep[root] = 0;\n    int max_dep = 0;\n    while(!que.empty()){\n      const\
    \ int pos = que.front();\n      que.pop();\n      max_dep = max(max_dep, dep[pos]);\n\
    \      for(const auto &x : G[pos]){\n        if(dep[x] == -1){\n          dep[x]\
    \ = dep[pos] + 1;\n          parent[0][x] = pos;\n          que.push(x);\n   \
    \     }\n      }\n    }\n    while((1 << log) <= max_dep) log++;\n    parent.resize(log,\
    \ vector<int>(n, -1));\n    for(int k = 0; k < log - 1; k++){\n      for(int v\
    \ = 0; v < n; v++){\n        if(parent[k][v] < 0) parent[k + 1][v] = -1;\n   \
    \     else parent[k + 1][v] = parent[k][parent[k][v]];\n      }\n    }\n  }\n\
    \  int query(int u, int v) const{\n    if(dep[u] < dep[v]) swap(u, v);\n    const\
    \ int sub = dep[u] - dep[v];\n    for(int k = 0; k < log; k++){\n      if(!(sub\
    \ >> k)) break;\n      if(sub >> k & 1) u = parent[k][u];\n    }\n    if(u ==\
    \ v) return u;\n    for(int k = __lg(dep[u]); k >= 0; k--){\n      if(parent[k][u]\
    \ != parent[k][v]){\n        u = parent[k][u];\n        v = parent[k][v];\n  \
    \    }\n    }\n    return parent[0][u];\n  }\n  int dist(const int u, const int\
    \ v) const{\n    return dep[u] + dep[v] - dep[query(u, v)] * 2;\n  }\n  int jump(int\
    \ u, int v, const int d) const{\n    const int lc = query(u, v);\n    const int\
    \ l = dep[u] - dep[lc];\n    const int r = dep[v] - dep[lc];\n    assert(0 <=\
    \ d && d <= l + r);\n    if(l < d){\n      d = l + r - d;\n      swap(u, v);\n\
    \    }\n    for(int k = 0; k < log; k++){\n      if(!(d >> k)) break;\n      if(d\
    \ >> k & 1) u = parent[k][u];\n    }\n    return u;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/lca.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/lca.cpp
layout: document
redirect_from:
- /library/graph/lca.cpp
- /library/graph/lca.cpp.html
title: graph/lca.cpp
---
