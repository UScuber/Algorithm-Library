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
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"graph/dinic.hpp\"\
    \n\r\ntemplate<class T>\r\nstruct dinic {\r\n  const T INF;\r\n  struct edge {\r\
    \n    int to,rev;\r\n    T cap;\r\n    bool isrev;\r\n    int idx;\r\n  };\r\n\
    \r\n  int n;\r\n  vector<vector<edge>> graph;\r\n  vector<int> min_cost, iter;\r\
    \n\r\n  dinic(int n): INF(numeric_limits<T>::max()), graph(n), n(n){}\r\n\r\n\
    \  void add_edge(int from, int to, T cap, int idx = -1){\r\n    graph[from].emplace_back((edge){to,\
    \ (int)graph[to].size(), cap, false, idx});\r\n    graph[to].emplace_back((edge){from,\
    \ (int)graph[from].size() - 1, 0, true, idx});\r\n  }\r\n  T max_flow(int s, int\
    \ t){\r\n    T flow = 0;\r\n    while(bfs(s, t)){\r\n      iter.assign(n, 0);\r\
    \n      T f = 0;\r\n      while((f = dfs(s, t, INF)) > 0) flow += f;\r\n    }\r\
    \n    return flow;\r\n  }\r\n  private:\r\n  bool bfs(int s, int t){\r\n    min_cost.assign(n,\
    \ -1);\r\n    queue<int> que;\r\n    min_cost[s] = 0;\r\n    que.push(s);\r\n\
    \    while(!que.empty() && min_cost[t] == -1){\r\n      int p = que.front();\r\
    \n      que.pop();\r\n      for(auto &e : graph[p]){\r\n        if(e.cap > 0 &&\
    \ min_cost[e.to] == -1){\r\n          min_cost[e.to] = min_cost[p] + 1;\r\n  \
    \        que.push(e.to);\r\n        }\r\n      }\r\n    }\r\n    return min_cost[t]\
    \ != -1;\r\n  }\r\n  T dfs(int idx, const int t, T flow){\r\n    if(idx == t)\
    \ return flow;\r\n    for(int &i = iter[idx]; i < graph[idx].size(); i++){\r\n\
    \      edge &e = graph[idx][i];\r\n      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]){\r\
    \n        T d = dfs(e.to, t, min(flow, e.cap));\r\n        if(d > 0){\r\n    \
    \      e.cap -= d;\r\n          graph[e.to][e.rev].cap += d;\r\n          return\
    \ d;\r\n        }\r\n      }\r\n    }\r\n    return 0;\r\n  }\r\n  public:\r\n\
    \  void debug(){\r\n    for(int i = 0; i < n; i++){\r\n      for(auto &e : graph[i]){\r\
    \n        if(e.isrev) continue;\r\n        auto &rev_e = graph[e.to][e.rev];\r\
    \n        cout << i << \"->\" << e.to << \" (flow: \" << rev_e.cap << \"/\" <<\
    \ e.cap + rev_e.cap << \")\" << endl;\r\n      }\r\n    }\r\n  }\r\n};\n"
  code: "#include \"template.hpp\"\r\n\r\ntemplate<class T>\r\nstruct dinic {\r\n\
    \  const T INF;\r\n  struct edge {\r\n    int to,rev;\r\n    T cap;\r\n    bool\
    \ isrev;\r\n    int idx;\r\n  };\r\n\r\n  int n;\r\n  vector<vector<edge>> graph;\r\
    \n  vector<int> min_cost, iter;\r\n\r\n  dinic(int n): INF(numeric_limits<T>::max()),\
    \ graph(n), n(n){}\r\n\r\n  void add_edge(int from, int to, T cap, int idx = -1){\r\
    \n    graph[from].emplace_back((edge){to, (int)graph[to].size(), cap, false, idx});\r\
    \n    graph[to].emplace_back((edge){from, (int)graph[from].size() - 1, 0, true,\
    \ idx});\r\n  }\r\n  T max_flow(int s, int t){\r\n    T flow = 0;\r\n    while(bfs(s,\
    \ t)){\r\n      iter.assign(n, 0);\r\n      T f = 0;\r\n      while((f = dfs(s,\
    \ t, INF)) > 0) flow += f;\r\n    }\r\n    return flow;\r\n  }\r\n  private:\r\
    \n  bool bfs(int s, int t){\r\n    min_cost.assign(n, -1);\r\n    queue<int> que;\r\
    \n    min_cost[s] = 0;\r\n    que.push(s);\r\n    while(!que.empty() && min_cost[t]\
    \ == -1){\r\n      int p = que.front();\r\n      que.pop();\r\n      for(auto\
    \ &e : graph[p]){\r\n        if(e.cap > 0 && min_cost[e.to] == -1){\r\n      \
    \    min_cost[e.to] = min_cost[p] + 1;\r\n          que.push(e.to);\r\n      \
    \  }\r\n      }\r\n    }\r\n    return min_cost[t] != -1;\r\n  }\r\n  T dfs(int\
    \ idx, const int t, T flow){\r\n    if(idx == t) return flow;\r\n    for(int &i\
    \ = iter[idx]; i < graph[idx].size(); i++){\r\n      edge &e = graph[idx][i];\r\
    \n      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]){\r\n        T d = dfs(e.to,\
    \ t, min(flow, e.cap));\r\n        if(d > 0){\r\n          e.cap -= d;\r\n   \
    \       graph[e.to][e.rev].cap += d;\r\n          return d;\r\n        }\r\n \
    \     }\r\n    }\r\n    return 0;\r\n  }\r\n  public:\r\n  void debug(){\r\n \
    \   for(int i = 0; i < n; i++){\r\n      for(auto &e : graph[i]){\r\n        if(e.isrev)\
    \ continue;\r\n        auto &rev_e = graph[e.to][e.rev];\r\n        cout << i\
    \ << \"->\" << e.to << \" (flow: \" << rev_e.cap << \"/\" << e.cap + rev_e.cap\
    \ << \")\" << endl;\r\n      }\r\n    }\r\n  }\r\n};"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/dinic.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dinic.hpp
layout: document
redirect_from:
- /library/graph/dinic.hpp
- /library/graph/dinic.hpp.html
title: graph/dinic.hpp
---
