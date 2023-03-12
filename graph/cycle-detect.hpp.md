---
data:
  _extendedDependsOn:
  - icon: ':warning:'
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
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"graph/cycle-detect.hpp\"\
    \n\r\nstruct Cycle {\r\n  Cycle(const graph &_g) : g(_g){}\r\n  vector<Edge<int>>\
    \ detect(){\r\n    const int n = g.size();\r\n    used.assign(n, 0);\r\n    prev.assign(n,\
    \ -1);\r\n    for(int i = 0; i < n; i++){\r\n      if(!used[i] && dfs(i)){\r\n\
    \        reverse(cyc.begin(), cyc.end());\r\n        return cyc;\r\n      }\r\n\
    \    }\r\n    return {};\r\n  }\r\n  private:\r\n  const graph &g;\r\n  vector<int>\
    \ used;\r\n  vector<Edge<int>> prev, cyc;\r\n  bool dfs(int pos){\r\n    used[pos]\
    \ = 1;\r\n    for(const auto &x : g[pos]){\r\n      if(!used[x]){\r\n        prev[x]\
    \ = x;\r\n        if(dfs(x)) return true;\r\n      }else if(used[x] == 1){\r\n\
    \        int cur = pos;\r\n        cyc.push_back(x);\r\n        while(cur != x){\r\
    \n          cyc.push_back(prev[cur]);\r\n          cur = prev[cur].from;\r\n \
    \       }\r\n        return true;\r\n      }\r\n    }\r\n    used[pos] = 2;\r\n\
    \    return false;\r\n  }\r\n};\n"
  code: "#include \"template.hpp\"\r\n\r\nstruct Cycle {\r\n  Cycle(const graph &_g)\
    \ : g(_g){}\r\n  vector<Edge<int>> detect(){\r\n    const int n = g.size();\r\n\
    \    used.assign(n, 0);\r\n    prev.assign(n, -1);\r\n    for(int i = 0; i < n;\
    \ i++){\r\n      if(!used[i] && dfs(i)){\r\n        reverse(cyc.begin(), cyc.end());\r\
    \n        return cyc;\r\n      }\r\n    }\r\n    return {};\r\n  }\r\n  private:\r\
    \n  const graph &g;\r\n  vector<int> used;\r\n  vector<Edge<int>> prev, cyc;\r\
    \n  bool dfs(int pos){\r\n    used[pos] = 1;\r\n    for(const auto &x : g[pos]){\r\
    \n      if(!used[x]){\r\n        prev[x] = x;\r\n        if(dfs(x)) return true;\r\
    \n      }else if(used[x] == 1){\r\n        int cur = pos;\r\n        cyc.push_back(x);\r\
    \n        while(cur != x){\r\n          cyc.push_back(prev[cur]);\r\n        \
    \  cur = prev[cur].from;\r\n        }\r\n        return true;\r\n      }\r\n \
    \   }\r\n    used[pos] = 2;\r\n    return false;\r\n  }\r\n};"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/cycle-detect.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/cycle-detect.hpp
layout: document
redirect_from:
- /library/graph/cycle-detect.hpp
- /library/graph/cycle-detect.hpp.html
title: graph/cycle-detect.hpp
---
