---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/fordfulkerson.hpp\"\ntemplate <class T>\r\nstruct\
    \ maxflow {\r\n  struct edge {\r\n    int to,rev; T cap;\r\n  };\r\n  maxflow(int\
    \ n) : n(n), G(n), used(n){}\r\n  maxflow(const vector<vector<edge>> &g): n(g.size()),\
    \ G(g){}\r\n  void add_edge(int from, int to, T cap){\r\n    G[from].push_back({to,\
    \ (int)G[to].size(), cap});\r\n    G[to].push_back({from, (int)G[from].size()-1,\
    \ 0});\r\n  }\r\n  T max_flow(int s, int t){\r\n    T flow = 0;\r\n    while(true){\r\
    \n      used.assign(n, false);\r\n      T f = dfs(s, t, mod);\r\n      if(f ==\
    \ 0) return flow;\r\n      flow += f;\r\n    }\r\n  }\r\n  private:\r\n  int n;\r\
    \n  vector<vector<edge>> G;\r\n  vector<bool> used;\r\n\r\n  T dfs(int v, int\
    \ t, T f){\r\n    if(v == t) return f;\r\n    used[v] = true;\r\n    for(edge\
    \ &e : G[v]){\r\n      if(!used[e.to] && e.cap > 0){\r\n        T d = dfs(e.to,\
    \ t, min(f, e.cap));\r\n        if(d > 0){\r\n          e.cap -= d;\r\n      \
    \    G[e.to][e.rev].cap += d;\r\n          return d;\r\n        }\r\n      }\r\
    \n    }\r\n    return 0;\r\n  }\r\n};\n"
  code: "template <class T>\r\nstruct maxflow {\r\n  struct edge {\r\n    int to,rev;\
    \ T cap;\r\n  };\r\n  maxflow(int n) : n(n), G(n), used(n){}\r\n  maxflow(const\
    \ vector<vector<edge>> &g): n(g.size()), G(g){}\r\n  void add_edge(int from, int\
    \ to, T cap){\r\n    G[from].push_back({to, (int)G[to].size(), cap});\r\n    G[to].push_back({from,\
    \ (int)G[from].size()-1, 0});\r\n  }\r\n  T max_flow(int s, int t){\r\n    T flow\
    \ = 0;\r\n    while(true){\r\n      used.assign(n, false);\r\n      T f = dfs(s,\
    \ t, mod);\r\n      if(f == 0) return flow;\r\n      flow += f;\r\n    }\r\n \
    \ }\r\n  private:\r\n  int n;\r\n  vector<vector<edge>> G;\r\n  vector<bool> used;\r\
    \n\r\n  T dfs(int v, int t, T f){\r\n    if(v == t) return f;\r\n    used[v] =\
    \ true;\r\n    for(edge &e : G[v]){\r\n      if(!used[e.to] && e.cap > 0){\r\n\
    \        T d = dfs(e.to, t, min(f, e.cap));\r\n        if(d > 0){\r\n        \
    \  e.cap -= d;\r\n          G[e.to][e.rev].cap += d;\r\n          return d;\r\n\
    \        }\r\n      }\r\n    }\r\n    return 0;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/fordfulkerson.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/fordfulkerson.hpp
layout: document
redirect_from:
- /library/graph/fordfulkerson.hpp
- /library/graph/fordfulkerson.hpp.html
title: graph/fordfulkerson.hpp
---
