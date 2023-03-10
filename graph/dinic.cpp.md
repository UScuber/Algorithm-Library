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
  bundledCode: "#line 1 \"graph/dinic.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate<class T>\nstruct dinic {\n  const T INF;\n  struct edge {\n\
    \    int to,rev;\n    T cap;\n    bool isrev;\n    int idx;\n  };\n\n  int n;\n\
    \  vector<vector<edge>> graph;\n  vector<int> min_cost, iter;\n\n  dinic(int n):\
    \ INF(numeric_limits<T>::max()), graph(n), n(n){}\n\n  void add_edge(int from,\
    \ int to, T cap, int idx = -1){\n    graph[from].emplace_back((edge){to, (int)graph[to].size(),\
    \ cap, false, idx});\n    graph[to].emplace_back((edge){from, (int)graph[from].size()\
    \ - 1, 0, true, idx});\n  }\n  T max_flow(int s, int t){\n    T flow = 0;\n  \
    \  while(bfs(s, t)){\n      iter.assign(n, 0);\n      T f = 0;\n      while((f\
    \ = dfs(s, t, INF)) > 0) flow += f;\n    }\n    return flow;\n  }\n  private:\n\
    \  bool bfs(int s, int t){\n    min_cost.assign(n, -1);\n    queue<int> que;\n\
    \    min_cost[s] = 0;\n    que.push(s);\n    while(!que.empty() && min_cost[t]\
    \ == -1){\n      int p = que.front();\n      que.pop();\n      for(auto &e : graph[p]){\n\
    \        if(e.cap > 0 && min_cost[e.to] == -1){\n          min_cost[e.to] = min_cost[p]\
    \ + 1;\n          que.push(e.to);\n        }\n      }\n    }\n    return min_cost[t]\
    \ != -1;\n  }\n  T dfs(int idx, const int t, T flow){\n    if(idx == t) return\
    \ flow;\n    for(int &i = iter[idx]; i < graph[idx].size(); i++){\n      edge\
    \ &e = graph[idx][i];\n      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]){\n\
    \        T d = dfs(e.to, t, min(flow, e.cap));\n        if(d > 0){\n         \
    \ e.cap -= d;\n          graph[e.to][e.rev].cap += d;\n          return d;\n \
    \       }\n      }\n    }\n    return 0;\n  }\n  public:\n  void debug(){\n  \
    \  for(int i = 0; i < n; i++){\n      for(auto &e : graph[i]){\n        if(e.isrev)\
    \ continue;\n        auto &rev_e = graph[e.to][e.rev];\n        cout << i << \"\
    ->\" << e.to << \" (flow: \" << rev_e.cap << \"/\" << e.cap + rev_e.cap << \"\
    )\" << endl;\n      }\n    }\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class T>\nstruct\
    \ dinic {\n  const T INF;\n  struct edge {\n    int to,rev;\n    T cap;\n    bool\
    \ isrev;\n    int idx;\n  };\n\n  int n;\n  vector<vector<edge>> graph;\n  vector<int>\
    \ min_cost, iter;\n\n  dinic(int n): INF(numeric_limits<T>::max()), graph(n),\
    \ n(n){}\n\n  void add_edge(int from, int to, T cap, int idx = -1){\n    graph[from].emplace_back((edge){to,\
    \ (int)graph[to].size(), cap, false, idx});\n    graph[to].emplace_back((edge){from,\
    \ (int)graph[from].size() - 1, 0, true, idx});\n  }\n  T max_flow(int s, int t){\n\
    \    T flow = 0;\n    while(bfs(s, t)){\n      iter.assign(n, 0);\n      T f =\
    \ 0;\n      while((f = dfs(s, t, INF)) > 0) flow += f;\n    }\n    return flow;\n\
    \  }\n  private:\n  bool bfs(int s, int t){\n    min_cost.assign(n, -1);\n   \
    \ queue<int> que;\n    min_cost[s] = 0;\n    que.push(s);\n    while(!que.empty()\
    \ && min_cost[t] == -1){\n      int p = que.front();\n      que.pop();\n     \
    \ for(auto &e : graph[p]){\n        if(e.cap > 0 && min_cost[e.to] == -1){\n \
    \         min_cost[e.to] = min_cost[p] + 1;\n          que.push(e.to);\n     \
    \   }\n      }\n    }\n    return min_cost[t] != -1;\n  }\n  T dfs(int idx, const\
    \ int t, T flow){\n    if(idx == t) return flow;\n    for(int &i = iter[idx];\
    \ i < graph[idx].size(); i++){\n      edge &e = graph[idx][i];\n      if(e.cap\
    \ > 0 && min_cost[idx] < min_cost[e.to]){\n        T d = dfs(e.to, t, min(flow,\
    \ e.cap));\n        if(d > 0){\n          e.cap -= d;\n          graph[e.to][e.rev].cap\
    \ += d;\n          return d;\n        }\n      }\n    }\n    return 0;\n  }\n\
    \  public:\n  void debug(){\n    for(int i = 0; i < n; i++){\n      for(auto &e\
    \ : graph[i]){\n        if(e.isrev) continue;\n        auto &rev_e = graph[e.to][e.rev];\n\
    \        cout << i << \"->\" << e.to << \" (flow: \" << rev_e.cap << \"/\" <<\
    \ e.cap + rev_e.cap << \")\" << endl;\n      }\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.cpp
  requiredBy: []
  timestamp: '2021-10-22 23:58:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dinic.cpp
layout: document
redirect_from:
- /library/graph/dinic.cpp
- /library/graph/dinic.cpp.html
title: graph/dinic.cpp
---
