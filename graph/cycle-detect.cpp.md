---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/template.hpp
    title: graph/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/cycle-detect.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"graph/template.hpp\"\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ Edge {\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){};\n  Edge(int f, int\
    \ t, T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}\n  Edge(int t) : to(t),\
    \ from(-1), cost(1), idx(-1){}\n  operator int() const{ return to; }\n  bool operator<(const\
    \ Edge &e){ return cost < e.cost; }\n};\ntemplate <class T>\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\n  Graph(){}\n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\n  void\
    \ add_edge(int a, int b, T c=1, int i=-1){\n    (*this)[a].push_back({ a, b, c,\
    \ i });\n  }\n};\nusing graph = Graph<int>;\n#line 3 \"graph/cycle-detect.cpp\"\
    \nusing namespace std;\n\nstruct Cycle {\n  Cycle(const graph &_g) : g(_g){}\n\
    \  vector<Edge<int>> detect(){\n    const int n = g.size();\n    used.assign(n,\
    \ 0);\n    prev.assign(n, -1);\n    for(int i = 0; i < n; i++){\n      if(!used[i]\
    \ && dfs(i)){\n        reverse(cyc.begin(), cyc.end());\n        return cyc;\n\
    \      }\n    }\n    return {};\n  }\n  private:\n  const graph &g;\n  vector<int>\
    \ used;\n  vector<Edge<int>> prev, cyc;\n  bool dfs(int pos){\n    used[pos] =\
    \ 1;\n    for(const auto &x : g[pos]){\n      if(!used[x]){\n        prev[x] =\
    \ x;\n        if(dfs(x)) return true;\n      }else if(used[x] == 1){\n       \
    \ int cur = pos;\n        cyc.push_back(x);\n        while(cur != x){\n      \
    \    cyc.push_back(prev[cur]);\n          cur = prev[cur].from;\n        }\n \
    \       return true;\n      }\n    }\n    used[pos] = 2;\n    return false;\n\
    \  }\n};\n"
  code: "#include <bits/stdc++.h>\n#include \"template.hpp\"\nusing namespace std;\n\
    \nstruct Cycle {\n  Cycle(const graph &_g) : g(_g){}\n  vector<Edge<int>> detect(){\n\
    \    const int n = g.size();\n    used.assign(n, 0);\n    prev.assign(n, -1);\n\
    \    for(int i = 0; i < n; i++){\n      if(!used[i] && dfs(i)){\n        reverse(cyc.begin(),\
    \ cyc.end());\n        return cyc;\n      }\n    }\n    return {};\n  }\n  private:\n\
    \  const graph &g;\n  vector<int> used;\n  vector<Edge<int>> prev, cyc;\n  bool\
    \ dfs(int pos){\n    used[pos] = 1;\n    for(const auto &x : g[pos]){\n      if(!used[x]){\n\
    \        prev[x] = x;\n        if(dfs(x)) return true;\n      }else if(used[x]\
    \ == 1){\n        int cur = pos;\n        cyc.push_back(x);\n        while(cur\
    \ != x){\n          cyc.push_back(prev[cur]);\n          cur = prev[cur].from;\n\
    \        }\n        return true;\n      }\n    }\n    used[pos] = 2;\n    return\
    \ false;\n  }\n};"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/cycle-detect.cpp
  requiredBy: []
  timestamp: '2022-07-19 17:33:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/cycle-detect.cpp
layout: document
redirect_from:
- /library/graph/cycle-detect.cpp
- /library/graph/cycle-detect.cpp.html
title: graph/cycle-detect.cpp
---
