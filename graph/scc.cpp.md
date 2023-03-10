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
  bundledCode: "#line 1 \"graph/scc.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n//dag:\u7E2E\u7D04\u5F8C\u306E\u9802\u70B9\u3068\u8FBA\u304B\u3089\u306A\
    \u308BDAG, comp:\u5404\u9802\u70B9\u304C\u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\
    \u5206\u306E\u9802\u70B9\u756A\u53F7, group:\u5404\u5F37\u9023\u7D50\u6210\u5206\
    \u306B\u3064\u3044\u3066, \u305D\u308C\u306B\u5C5E\u3059\u308B\u9802\u70B9\u304C\
    \u683C\u7D0D\u3055\u308C\u308B.\ntemplate <class graph>\nstruct scc {\n  scc(const\
    \ graph &g): root(g), n(g.size()){ init(); }\n  void init(){\n    rroot.resize(n);\n\
    \    used.resize(n);\n    ord.resize(n);\n    comp.resize(n, -1);\n    build();\n\
    \  }\n  void build(){\n    for(int i = 0; i < n; i++){\n      for(const auto &x\
    \ : root[i])\n        rroot[x].push_back(i);\n    }\n    for(int i = 0; i < n;\
    \ i++) dfs(i);\n    reverse(ord.begin(), ord.end());\n    int cnt = 0;\n    for(const\
    \ auto &x : ord) if(comp[x] == -1){\n      rdfs(x, cnt);\n      cnt++;\n    }\n\
    \    dag.resize(cnt);\n    group.resize(cnt);\n    for(int i = 0; i < n; i++){\n\
    \      for(const auto &x : root[i]){\n        const int a = comp[i], b = comp[x];\n\
    \        if(a == b) continue;\n        dag[a].push_back(b);\n      }\n    }\n\
    \    for(int i = 0; i < n; i++){\n      group[comp[i]].push_back(i);\n    }\n\
    \  }\n  int operator[](int i) const{\n    return comp[i];\n  }\n  vector<vector<int>>\
    \ group, dag;\n  private:\n  int n = 0;\n  const graph &root;\n  graph rroot;\
    \ //rev\n  vector<int> used, ord, comp;\n  void dfs(int pos){\n    if(used[pos])\
    \ return;\n    used[pos] = 1;\n    for(const auto &x : root[pos]) dfs(x);\n  \
    \  ord.push_back(pos);\n  }\n  void rdfs(int pos, const int cnt){\n    if(comp[pos]\
    \ != -1) return;\n    comp[pos] = cnt;\n    for(const auto &x : rroot[pos]) rdfs(x,\
    \ cnt);\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//dag:\u7E2E\u7D04\u5F8C\
    \u306E\u9802\u70B9\u3068\u8FBA\u304B\u3089\u306A\u308BDAG, comp:\u5404\u9802\u70B9\
    \u304C\u5C5E\u3059\u308B\u5F37\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\
    \u53F7, group:\u5404\u5F37\u9023\u7D50\u6210\u5206\u306B\u3064\u3044\u3066, \u305D\
    \u308C\u306B\u5C5E\u3059\u308B\u9802\u70B9\u304C\u683C\u7D0D\u3055\u308C\u308B\
    .\ntemplate <class graph>\nstruct scc {\n  scc(const graph &g): root(g), n(g.size()){\
    \ init(); }\n  void init(){\n    rroot.resize(n);\n    used.resize(n);\n    ord.resize(n);\n\
    \    comp.resize(n, -1);\n    build();\n  }\n  void build(){\n    for(int i =\
    \ 0; i < n; i++){\n      for(const auto &x : root[i])\n        rroot[x].push_back(i);\n\
    \    }\n    for(int i = 0; i < n; i++) dfs(i);\n    reverse(ord.begin(), ord.end());\n\
    \    int cnt = 0;\n    for(const auto &x : ord) if(comp[x] == -1){\n      rdfs(x,\
    \ cnt);\n      cnt++;\n    }\n    dag.resize(cnt);\n    group.resize(cnt);\n \
    \   for(int i = 0; i < n; i++){\n      for(const auto &x : root[i]){\n       \
    \ const int a = comp[i], b = comp[x];\n        if(a == b) continue;\n        dag[a].push_back(b);\n\
    \      }\n    }\n    for(int i = 0; i < n; i++){\n      group[comp[i]].push_back(i);\n\
    \    }\n  }\n  int operator[](int i) const{\n    return comp[i];\n  }\n  vector<vector<int>>\
    \ group, dag;\n  private:\n  int n = 0;\n  const graph &root;\n  graph rroot;\
    \ //rev\n  vector<int> used, ord, comp;\n  void dfs(int pos){\n    if(used[pos])\
    \ return;\n    used[pos] = 1;\n    for(const auto &x : root[pos]) dfs(x);\n  \
    \  ord.push_back(pos);\n  }\n  void rdfs(int pos, const int cnt){\n    if(comp[pos]\
    \ != -1) return;\n    comp[pos] = cnt;\n    for(const auto &x : rroot[pos]) rdfs(x,\
    \ cnt);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc.cpp
  requiredBy: []
  timestamp: '2022-07-19 13:17:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc.cpp
layout: document
redirect_from:
- /library/graph/scc.cpp
- /library/graph/scc.cpp.html
title: graph/scc.cpp
---
