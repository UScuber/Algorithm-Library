---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/diameter.hpp
    title: graph/diameter.hpp
  - icon: ':heavy_check_mark:'
    path: graph/template.hpp
    title: Graph Template
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/yosupo/Tree/Tree-Diameter.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <iostream>\r\n#include <cmath>\r\n#include <string>\r\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <utility>\r\n#include <tuple>\r\n#include <cstdint>\r\
    \n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\n#include <set>\r\n\
    #include <stack>\r\n#include <deque>\r\n#include <unordered_map>\r\n#include <unordered_set>\r\
    \n#include <bitset>\r\n#include <cctype>\r\n#include <climits>\r\n#include <functional>\r\
    \n#include <cassert>\r\n#include <numeric>\r\n#define rep(i, n) for(int i = 0;\
    \ i < (n); i++)\r\n#define per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\nusing\
    \ ll = long long;\r\n#define vi vector<int>\r\n#define vvi vector<vi>\r\n#define\
    \ vl vector<ll>\r\n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n\
    #define all(a) (a).begin(), (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\
    \nconstexpr int mod = 1000000007;\r\nusing namespace std;\r\ntemplate<class T,\
    \ class U>\r\nbool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\
    \ntemplate<class T, class U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a\
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Tree/Tree-Diameter.test.cpp\"\n\n#line\
    \ 2 \"graph/template.hpp\"\n\r\n/**\r\n * @brief Graph Template\r\n*/\r\ntemplate\
    \ <class T>\r\nstruct Edge {\r\n  int from,to;\r\n  T cost;\r\n  int idx;\r\n\
    \  Edge(){};\r\n  Edge(int f, int t, T c=1, int i=-1) : from(f), to(t), cost(c),\
    \ idx(i){}\r\n  Edge(int t) : to(t), from(-1), cost(1), idx(-1){}\r\n  operator\
    \ int() const{ return to; }\r\n  bool operator<(const Edge &e){ return cost <\
    \ e.cost; }\r\n};\r\ntemplate <class T>\r\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\r\n  Graph(){}\r\n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\r\n\
    \  void add_edge(int a, int b, T c=1, int i=-1){\r\n    (*this)[a].push_back({\
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"graph/diameter.hpp\"\
    \n\r\ntemplate <class T>\r\npair<T, vector<int>> diameter(const Graph<T> &g){\r\
    \n  const int n = g.size();\r\n  vector<T> dist(n);\r\n  vector<int> prev(n, -1);\r\
    \n  function<void(int,int)> dfs = [&](int pos, int par){\r\n    for(auto &x :\
    \ g[pos]) if(x != par){\r\n      dist[x] = dist[pos] + x.cost;\r\n      prev[x]\
    \ = pos;\r\n      dfs(x, pos);\r\n    }\r\n  };\r\n  dfs(0, -1);\r\n  int pos\
    \ = max_element(dist.begin(), dist.end()) - dist.begin();\r\n  dist.assign(n,\
    \ 0); prev.assign(n, -1);\r\n  dfs(pos, -1);\r\n  pos = max_element(dist.begin(),\
    \ dist.end()) - dist.begin();\r\n  const T tot = dist[pos];\r\n  vector<int> res;\r\
    \n  for(int i = pos; i != -1; i = prev[i]) res.push_back(i);\r\n  return { tot,\
    \ res };\r\n}\n#line 6 \"test/yosupo/Tree/Tree-Diameter.test.cpp\"\n\nint main(){\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n;\n  cin >> n;\n\
    \  Graph<ll> root(n);\n  rep(i, n - 1){\n    int a,b,c;\n    cin >> a >> b >>\
    \ c;\n    root[a].push_back({ a, b, c });\n    root[b].push_back({ b, a, c });\n\
    \  }\n  const auto res = diameter(root);\n  int m = res.second.size();\n  cout\
    \ << res.first << \" \" << m << \"\\n\";\n  rep(i, m) cout << res.second[i] <<\
    \ \" \\n\"[i == m - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../../../template/template.hpp\"\n\n#include \"../../../graph/diameter.hpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n;\n\
    \  cin >> n;\n  Graph<ll> root(n);\n  rep(i, n - 1){\n    int a,b,c;\n    cin\
    \ >> a >> b >> c;\n    root[a].push_back({ a, b, c });\n    root[b].push_back({\
    \ b, a, c });\n  }\n  const auto res = diameter(root);\n  int m = res.second.size();\n\
    \  cout << res.first << \" \" << m << \"\\n\";\n  rep(i, m) cout << res.second[i]\
    \ << \" \\n\"[i == m - 1];\n}"
  dependsOn:
  - template/template.hpp
  - graph/diameter.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/yosupo/Tree/Tree-Diameter.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 19:15:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Tree/Tree-Diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Tree/Tree-Diameter.test.cpp
- /verify/test/yosupo/Tree/Tree-Diameter.test.cpp.html
title: test/yosupo/Tree/Tree-Diameter.test.cpp
---
