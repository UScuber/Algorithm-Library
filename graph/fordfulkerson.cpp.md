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
  bundledCode: "#line 1 \"graph/fordfulkerson.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class T>\nstruct maxflow {\n  struct edge {\n  \
    \  int to,rev; T cap;\n  };\n  maxflow(int n) : n(n), G(n), used(n){}\n  maxflow(const\
    \ vector<vector<edge>> &g): n(g.size()), G(g){}\n  void add_edge(int from, int\
    \ to, T cap){\n    G[from].push_back({to, (int)G[to].size(), cap});\n    G[to].push_back({from,\
    \ (int)G[from].size()-1, 0});\n  }\n  T max_flow(int s, int t){\n    T flow =\
    \ 0;\n    while(true){\n      used.assign(n, false);\n      T f = dfs(s, t, mod);\n\
    \      if(f == 0) return flow;\n      flow += f;\n    }\n  }\n  private:\n  int\
    \ n;\n  vector<vector<edge>> G;\n  vector<bool> used;\n\n  T dfs(int v, int t,\
    \ T f){\n    if(v == t) return f;\n    used[v] = true;\n    for(edge &e : G[v]){\n\
    \      if(!used[e.to] && e.cap > 0){\n        T d = dfs(e.to, t, min(f, e.cap));\n\
    \        if(d > 0){\n          e.cap -= d;\n          G[e.to][e.rev].cap += d;\n\
    \          return d;\n        }\n      }\n    }\n    return 0;\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ maxflow {\n  struct edge {\n    int to,rev; T cap;\n  };\n  maxflow(int n) :\
    \ n(n), G(n), used(n){}\n  maxflow(const vector<vector<edge>> &g): n(g.size()),\
    \ G(g){}\n  void add_edge(int from, int to, T cap){\n    G[from].push_back({to,\
    \ (int)G[to].size(), cap});\n    G[to].push_back({from, (int)G[from].size()-1,\
    \ 0});\n  }\n  T max_flow(int s, int t){\n    T flow = 0;\n    while(true){\n\
    \      used.assign(n, false);\n      T f = dfs(s, t, mod);\n      if(f == 0) return\
    \ flow;\n      flow += f;\n    }\n  }\n  private:\n  int n;\n  vector<vector<edge>>\
    \ G;\n  vector<bool> used;\n\n  T dfs(int v, int t, T f){\n    if(v == t) return\
    \ f;\n    used[v] = true;\n    for(edge &e : G[v]){\n      if(!used[e.to] && e.cap\
    \ > 0){\n        T d = dfs(e.to, t, min(f, e.cap));\n        if(d > 0){\n    \
    \      e.cap -= d;\n          G[e.to][e.rev].cap += d;\n          return d;\n\
    \        }\n      }\n    }\n    return 0;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/fordfulkerson.cpp
  requiredBy: []
  timestamp: '2021-10-22 23:58:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/fordfulkerson.cpp
layout: document
redirect_from:
- /library/graph/fordfulkerson.cpp
- /library/graph/fordfulkerson.cpp.html
title: graph/fordfulkerson.cpp
---
