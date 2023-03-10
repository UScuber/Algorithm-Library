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
  bundledCode: "#line 1 \"graph/bellman-ford.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"graph/template.hpp\"\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ Edge {\n  int from,to;\n  T cost;\n  int idx;\n  Edge(){};\n  Edge(int f, int\
    \ t, T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}\n  Edge(int t) : to(t),\
    \ from(-1), cost(1), idx(-1){}\n  operator int() const{ return to; }\n  bool operator<(const\
    \ Edge &e){ return cost < e.cost; }\n};\ntemplate <class T>\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\n  Graph(){}\n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\n  void\
    \ add_edge(int a, int b, T c=1, int i=-1){\n    (*this)[a].push_back({ a, b, c,\
    \ i });\n  }\n};\nusing graph = Graph<int>;\n#line 3 \"graph/bellman-ford.cpp\"\
    \nusing namespace std;\n\ntemplate <class T, const T&(*op)(const T&, const T&)>\n\
    struct BellmanFord {\n  BellmanFord(const Graph<T> &r): root(r), n(r.size()){\n\
    \    inf = -op(inf, -inf);\n    res.assign(n, inf);\n  }\n  void solve(const int\
    \ s){\n    assert(0 <= s && s < n);\n    res[s] = 0;\n    for(int i = 1; i < n;\
    \ i++) for(int j = 0; j < n; j++){\n      if(res[j] != inf) for(const auto &x\
    \ : root[j]){\n        res[x] = op(res[x], res[j] + x.cost);\n      }\n    }\n\
    \    vector<int> loop(n);\n    for(int i = 0; i < n; i++) for(int j = 0; j < n;\
    \ j++){\n      if(res[j] != inf) for(const auto &x : root[j]){\n        if(op(res[x]\
    \ + op(1,-1), res[j] + x.cost) == res[j] + x.cost){\n          res[x] = res[j]\
    \ + x.cost;\n          loop[x] = 1;\n        }\n        if(loop[j]) loop[x] =\
    \ 1;\n      }\n    }\n    for(int i = 0; i < n; i++) if(loop[i]) res[i] = inf;\n\
    \  }\n  const T &operator[](const int i) const{\n    assert(0 <= i && i < n);\n\
    \    return res[i];\n  }\n  bool is_cycle(const int i) const{\n    assert(0 <=\
    \ i && i < n);\n    return res[i] == inf;\n  }\n  private:\n  const Graph<T> &root;\n\
    \  vector<T> res;\n  int n;\n  T inf = numeric_limits<T>::max()-1;\n};\n"
  code: "#include <bits/stdc++.h>\n#include \"template.hpp\"\nusing namespace std;\n\
    \ntemplate <class T, const T&(*op)(const T&, const T&)>\nstruct BellmanFord {\n\
    \  BellmanFord(const Graph<T> &r): root(r), n(r.size()){\n    inf = -op(inf, -inf);\n\
    \    res.assign(n, inf);\n  }\n  void solve(const int s){\n    assert(0 <= s &&\
    \ s < n);\n    res[s] = 0;\n    for(int i = 1; i < n; i++) for(int j = 0; j <\
    \ n; j++){\n      if(res[j] != inf) for(const auto &x : root[j]){\n        res[x]\
    \ = op(res[x], res[j] + x.cost);\n      }\n    }\n    vector<int> loop(n);\n \
    \   for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){\n      if(res[j] !=\
    \ inf) for(const auto &x : root[j]){\n        if(op(res[x] + op(1,-1), res[j]\
    \ + x.cost) == res[j] + x.cost){\n          res[x] = res[j] + x.cost;\n      \
    \    loop[x] = 1;\n        }\n        if(loop[j]) loop[x] = 1;\n      }\n    }\n\
    \    for(int i = 0; i < n; i++) if(loop[i]) res[i] = inf;\n  }\n  const T &operator[](const\
    \ int i) const{\n    assert(0 <= i && i < n);\n    return res[i];\n  }\n  bool\
    \ is_cycle(const int i) const{\n    assert(0 <= i && i < n);\n    return res[i]\
    \ == inf;\n  }\n  private:\n  const Graph<T> &root;\n  vector<T> res;\n  int n;\n\
    \  T inf = numeric_limits<T>::max()-1;\n};"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/bellman-ford.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bellman-ford.cpp
layout: document
redirect_from:
- /library/graph/bellman-ford.cpp
- /library/graph/bellman-ford.cpp.html
title: graph/bellman-ford.cpp
---
