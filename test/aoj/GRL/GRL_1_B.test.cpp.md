---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman-ford.hpp
    title: graph/bellman-ford.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL/GRL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\
    \n#include <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <utility>\r\
    \n#include <tuple>\r\n#include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\
    \n#include <queue>\r\n#include <set>\r\n#include <stack>\r\n#include <deque>\r\
    \n#include <unordered_map>\r\n#include <unordered_set>\r\n#include <bitset>\r\n\
    #include <cctype>\r\n#include <climits>\r\n#include <functional>\r\n#include <cassert>\r\
    \n#include <numeric>\r\n#define rep(i, n) for(int i = 0; i < (n); i++)\r\n#define\
    \ per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\nusing ll = long long;\r\n#define\
    \ vi vector<int>\r\n#define vvi vector<vi>\r\n#define vl vector<ll>\r\n#define\
    \ pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define all(a) (a).begin(),\
    \ (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\nconstexpr int mod =\
    \ 1000000007;\r\nusing namespace std;\r\ntemplate<class T, class U>\r\nbool chmax(T\
    \ &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\ntemplate<class T, class\
    \ U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }\n#line\
    \ 4 \"test/aoj/GRL/GRL_1_B.test.cpp\"\n\n#line 2 \"graph/template.hpp\"\n\r\n\
    /**\r\n * @brief Graph Template\r\n*/\r\ntemplate <class T>\r\nstruct Edge {\r\
    \n  int from,to;\r\n  T cost;\r\n  int idx;\r\n  Edge(){};\r\n  Edge(int f, int\
    \ t, T c=1, int i=-1) : from(f), to(t), cost(c), idx(i){}\r\n  Edge(int t) : to(t),\
    \ from(-1), cost(1), idx(-1){}\r\n  operator int() const{ return to; }\r\n  bool\
    \ operator<(const Edge &e){ return cost < e.cost; }\r\n};\r\ntemplate <class T>\r\
    \nstruct Graph : vector<vector<Edge<T>>> {\r\n  Graph(){}\r\n  Graph(const int\
    \ &n) : vector<vector<Edge<T>>>(n){}\r\n  void add_edge(int a, int b, T c=1, int\
    \ i=-1){\r\n    (*this)[a].push_back({ a, b, c, i });\r\n  }\r\n};\r\nusing graph\
    \ = Graph<int>;\n#line 2 \"graph/bellman-ford.hpp\"\n\r\ntemplate <class T, const\
    \ T&(*op)(const T&, const T&)>\r\nstruct BellmanFord {\r\n  BellmanFord(const\
    \ Graph<T> &r): root(r), n(r.size()){\r\n    inf = -op(inf, -inf);\r\n    res.assign(n,\
    \ inf);\r\n  }\r\n  void solve(const int s){\r\n    assert(0 <= s && s < n);\r\
    \n    res[s] = 0;\r\n    for(int i = 1; i < n; i++) for(int j = 0; j < n; j++){\r\
    \n      if(res[j] != inf) for(const auto &x : root[j]){\r\n        res[x] = op(res[x],\
    \ res[j] + x.cost);\r\n      }\r\n    }\r\n    vector<int> loop(n);\r\n    for(int\
    \ i = 0; i < n; i++) for(int j = 0; j < n; j++){\r\n      if(res[j] != inf) for(const\
    \ auto &x : root[j]){\r\n        if(op(res[x] + op(1,-1), res[j] + x.cost) ==\
    \ res[j] + x.cost){\r\n          res[x] = res[j] + x.cost;\r\n          loop[x]\
    \ = 1;\r\n        }\r\n        if(loop[j]) loop[x] = 1;\r\n      }\r\n    }\r\n\
    \    for(int i = 0; i < n; i++) if(loop[i]) res[i] = -inf;\r\n  }\r\n  const T\
    \ &operator[](const int i) const{\r\n    assert(0 <= i && i < n);\r\n    return\
    \ res[i];\r\n  }\r\n  bool is_cycle(const int i) const{\r\n    assert(0 <= i &&\
    \ i < n);\r\n    return res[i] == -inf;\r\n  }\r\n  private:\r\n  const Graph<T>\
    \ &root;\r\n  vector<T> res;\r\n  int n;\r\n  T inf = numeric_limits<T>::max()-1;\r\
    \n};\n#line 7 \"test/aoj/GRL/GRL_1_B.test.cpp\"\n\nint main(){\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  int n,m,r;\n  cin >> n >> m >> r;\n  graph\
    \ root(n);\n  rep(i, m){\n    int a,b,c;\n    cin >> a >> b >> c;\n    root[a].push_back({\
    \ a, b, c });\n  }\n  BellmanFord<int,min> bf(root);\n  bf.solve(r);\n  rep(i,\
    \ n) if(bf.is_cycle(i)){\n    cout << \"NEGATIVE CYCLE\\n\";\n    return 0;\n\
    \  }\n  rep(i, n){\n    if(bf[i] > (int)1e9) cout << \"INF\\n\";\n    else cout\
    \ << bf[i] << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../graph/template.hpp\"\
    \n#include \"../../../graph/bellman-ford.hpp\"\n\nint main(){\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  int n,m,r;\n  cin >> n >> m >> r;\n  graph\
    \ root(n);\n  rep(i, m){\n    int a,b,c;\n    cin >> a >> b >> c;\n    root[a].push_back({\
    \ a, b, c });\n  }\n  BellmanFord<int,min> bf(root);\n  bf.solve(r);\n  rep(i,\
    \ n) if(bf.is_cycle(i)){\n    cout << \"NEGATIVE CYCLE\\n\";\n    return 0;\n\
    \  }\n  rep(i, n){\n    if(bf[i] > (int)1e9) cout << \"INF\\n\";\n    else cout\
    \ << bf[i] << \"\\n\";\n  }\n}"
  dependsOn:
  - template/template.hpp
  - graph/template.hpp
  - graph/bellman-ford.hpp
  isVerificationFile: true
  path: test/aoj/GRL/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-03-13 22:02:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_1_B.test.cpp
- /verify/test/aoj/GRL/GRL_1_B.test.cpp.html
title: test/aoj/GRL/GRL_1_B.test.cpp
---
