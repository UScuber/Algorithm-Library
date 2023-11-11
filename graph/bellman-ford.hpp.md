---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/template.hpp
    title: Graph Template
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL/GRL_1_B.test.cpp
    title: test/aoj/GRL/GRL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"graph/bellman-ford.hpp\"\
    \n\r\ntemplate <class T, const T&(*op)(const T&, const T&)>\r\nstruct BellmanFord\
    \ {\r\n  BellmanFord(const Graph<T> &r): root(r), n(r.size()){\r\n    inf = -op(inf,\
    \ -inf);\r\n    res.assign(n, inf);\r\n  }\r\n  void solve(const int s){\r\n \
    \   assert(0 <= s && s < n);\r\n    res[s] = 0;\r\n    for(int i = 1; i < n; i++)\
    \ for(int j = 0; j < n; j++){\r\n      if(res[j] != inf) for(const auto &x : root[j]){\r\
    \n        res[x] = op(res[x], res[j] + x.cost);\r\n      }\r\n    }\r\n    vector<int>\
    \ loop(n);\r\n    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){\r\n \
    \     if(res[j] != inf) for(const auto &x : root[j]){\r\n        if(op(res[x]\
    \ + op(1,-1), res[j] + x.cost) == res[j] + x.cost){\r\n          res[x] = res[j]\
    \ + x.cost;\r\n          loop[x] = 1;\r\n        }\r\n        if(loop[j]) loop[x]\
    \ = 1;\r\n      }\r\n    }\r\n    for(int i = 0; i < n; i++) if(loop[i]) res[i]\
    \ = -inf;\r\n  }\r\n  const T &operator[](const int i) const{\r\n    assert(0\
    \ <= i && i < n);\r\n    return res[i];\r\n  }\r\n  bool is_cycle(const int i)\
    \ const{\r\n    assert(0 <= i && i < n);\r\n    return res[i] == -inf;\r\n  }\r\
    \n  private:\r\n  const Graph<T> &root;\r\n  vector<T> res;\r\n  int n;\r\n  T\
    \ inf = numeric_limits<T>::max()-1;\r\n};\n"
  code: "#include \"template.hpp\"\r\n\r\ntemplate <class T, const T&(*op)(const T&,\
    \ const T&)>\r\nstruct BellmanFord {\r\n  BellmanFord(const Graph<T> &r): root(r),\
    \ n(r.size()){\r\n    inf = -op(inf, -inf);\r\n    res.assign(n, inf);\r\n  }\r\
    \n  void solve(const int s){\r\n    assert(0 <= s && s < n);\r\n    res[s] = 0;\r\
    \n    for(int i = 1; i < n; i++) for(int j = 0; j < n; j++){\r\n      if(res[j]\
    \ != inf) for(const auto &x : root[j]){\r\n        res[x] = op(res[x], res[j]\
    \ + x.cost);\r\n      }\r\n    }\r\n    vector<int> loop(n);\r\n    for(int i\
    \ = 0; i < n; i++) for(int j = 0; j < n; j++){\r\n      if(res[j] != inf) for(const\
    \ auto &x : root[j]){\r\n        if(op(res[x] + op(1,-1), res[j] + x.cost) ==\
    \ res[j] + x.cost){\r\n          res[x] = res[j] + x.cost;\r\n          loop[x]\
    \ = 1;\r\n        }\r\n        if(loop[j]) loop[x] = 1;\r\n      }\r\n    }\r\n\
    \    for(int i = 0; i < n; i++) if(loop[i]) res[i] = -inf;\r\n  }\r\n  const T\
    \ &operator[](const int i) const{\r\n    assert(0 <= i && i < n);\r\n    return\
    \ res[i];\r\n  }\r\n  bool is_cycle(const int i) const{\r\n    assert(0 <= i &&\
    \ i < n);\r\n    return res[i] == -inf;\r\n  }\r\n  private:\r\n  const Graph<T>\
    \ &root;\r\n  vector<T> res;\r\n  int n;\r\n  T inf = numeric_limits<T>::max()-1;\r\
    \n};"
  dependsOn:
  - graph/template.hpp
  isVerificationFile: false
  path: graph/bellman-ford.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL/GRL_1_B.test.cpp
documentation_of: graph/bellman-ford.hpp
layout: document
title: "Bellman Ford\u6CD5"
---

## 説明

- ベルマンフォード法
- 負のコストを含めた最短経路を求める
- O(NM)

- Constructor
```cpp
BellmanFord<T, const T&(*op)(const T&, const T&)>(const Graph<T> &r);
```

- 頂点sを始点として最短経路を求める
```cpp
void solve(int s)
```

- i までの最短距離を`変数名[i]`で取得
- 負閉路の場合はinfが出力される
```cpp
const T &operator[](const int i)
```

- 負閉路判定
```cpp
bool is_cycle(const int i)
```