---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/UnionFind.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal\u6CD5(\u6700\u5C0F\u5168\u57DF\u6728)"
  - icon: ':question:'
    path: graph/template.hpp
    title: Graph Template
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL/GRL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\
    \n#include <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <tuple>\r\
    \n#include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <deque>\r\n#include <bitset>\r\
    \n#include <cctype>\r\n#include <climits>\r\n#include <functional>\r\n#include\
    \ <cassert>\r\n#include <numeric>\r\n#include <cstring>\r\n#define rep(i, n) for(int\
    \ i = 0; i < (n); i++)\r\n#define per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\
    \nusing ll = long long;\r\n#define vi vector<int>\r\n#define vvi vector<vi>\r\n\
    #define vl vector<ll>\r\n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\
    \n#define all(a) (a).begin(), (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\
    \nconstexpr int mod = 1000000007;\r\nusing namespace std;\r\ntemplate<class T,\
    \ class U>\r\nbool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\
    \ntemplate<class T, class U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a\
    \ = b, 1) : 0; }\n#line 4 \"test/aoj/GRL/GRL_2_A.test.cpp\"\n\n#line 2 \"graph/template.hpp\"\
    \n\r\n/**\r\n * @brief Graph Template\r\n*/\r\ntemplate <class T>\r\nstruct Edge\
    \ {\r\n  int from,to;\r\n  T cost;\r\n  int idx;\r\n  Edge(){};\r\n  Edge(int\
    \ f, int t, T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}\r\n  Edge(int\
    \ t) : to(t), from(-1), cost(1), idx(-1){}\r\n  operator int() const{ return to;\
    \ }\r\n  bool operator<(const Edge &e){ return cost < e.cost; }\r\n};\r\ntemplate\
    \ <class T>\r\nstruct Graph : vector<vector<Edge<T>>> {\r\n  Graph(){}\r\n  Graph(const\
    \ int &n) : vector<vector<Edge<T>>>(n){}\r\n  void add_edge(int a, int b, T c=1,\
    \ int i=-1){\r\n    (*this)[a].push_back({ a, b, c, i });\r\n  }\r\n};\r\nusing\
    \ graph = Graph<int>;\n#line 1 \"graph/UnionFind.hpp\"\nstruct UnionFind {\r\n\
    \  private:\r\n  int n;\r\n  public:\r\n  vector<int> d;\r\n  UnionFind(int n):\
    \ n(n), d(n, -1){}\r\n  int root(int x){\r\n    assert(0 <= x && x < n);\r\n \
    \   if(d[x] < 0) return x;\r\n    return d[x] = root(d[x]);\r\n  }\r\n  bool unite(int\
    \ x, int y){\r\n    x = root(x);\r\n    y = root(y);\r\n    if(x == y) return\
    \ false;\r\n    if(d[x] > d[y]) swap(x, y);\r\n    d[x] += d[y];\r\n    d[y] =\
    \ x;\r\n    return true;\r\n  }\r\n  bool same(int x, int y){\r\n    return root(x)\
    \ == root(y);\r\n  }\r\n  int size(int x){\r\n    return -d[root(x)];\r\n  }\r\
    \n};\r\n#line 2 \"graph/kruskal.hpp\"\n\r\ntemplate <class T>\r\nll kruskal(vector<Edge<T>>\
    \ &es, const int n){\r\n  ll res = 0;\r\n  sort(es.begin(), es.end());\r\n  UnionFind\
    \ tree(n);\r\n  for(const auto &e : es){\r\n    if(!tree.same(e.from, e.to)){\r\
    \n      tree.unite(e.from, e.to);\r\n      res += e.cost;\r\n    }\r\n  }\r\n\
    \  return res;\r\n}\n#line 7 \"test/aoj/GRL/GRL_2_A.test.cpp\"\n\nint main(){\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,m;\n  cin >> n >>\
    \ m;\n  vector<Edge<int>> es(m);\n  rep(i, m){\n    int a,b,c;\n    cin >> a >>\
    \ b >> c;\n    es[i] = { a, b, c };\n  }\n  cout << kruskal(es, n) << \"\\n\"\
    ;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../graph/template.hpp\"\
    \n#include \"../../../graph/kruskal.hpp\"\n\nint main(){\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  int n,m;\n  cin >> n >> m;\n  vector<Edge<int>>\
    \ es(m);\n  rep(i, m){\n    int a,b,c;\n    cin >> a >> b >> c;\n    es[i] = {\
    \ a, b, c };\n  }\n  cout << kruskal(es, n) << \"\\n\";\n}"
  dependsOn:
  - template/template.hpp
  - graph/template.hpp
  - graph/kruskal.hpp
  - graph/UnionFind.hpp
  isVerificationFile: true
  path: test/aoj/GRL/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2023-11-11 17:58:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_2_A.test.cpp
- /verify/test/aoj/GRL/GRL_2_A.test.cpp.html
title: test/aoj/GRL/GRL_2_A.test.cpp
---
