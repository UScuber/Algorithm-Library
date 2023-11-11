---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dijkstra.hpp
    title: graph/dijkstra.hpp
  - icon: ':question:'
    path: graph/template.hpp
    title: Graph Template
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo/Graph/Shortest-Path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <iostream>\r\n#include <cmath>\r\n#include <string>\r\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <tuple>\r\n#include <cstdint>\r\n#include <cstdio>\r\
    \n#include <map>\r\n#include <queue>\r\n#include <set>\r\n#include <stack>\r\n\
    #include <deque>\r\n#include <bitset>\r\n#include <cctype>\r\n#include <climits>\r\
    \n#include <functional>\r\n#include <cassert>\r\n#include <numeric>\r\n#include\
    \ <cstring>\r\n#define rep(i, n) for(int i = 0; i < (n); i++)\r\n#define per(i,\
    \ n) for(int i = (n) - 1; i >= 0; i--)\r\nusing ll = long long;\r\n#define vi\
    \ vector<int>\r\n#define vvi vector<vi>\r\n#define vl vector<ll>\r\n#define pii\
    \ pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define all(a) (a).begin(), (a).end()\r\
    \n#define rall(a) (a).rbegin(), (a).rend()\r\nconstexpr int mod = 1000000007;\r\
    \nusing namespace std;\r\ntemplate<class T, class U>\r\nbool chmax(T &a, const\
    \ U &b){ return a < b ? (a = b, 1) : 0; }\r\ntemplate<class T, class U>\r\nbool\
    \ chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }\n#line 4 \"test/yosupo/Graph/Shortest-Path.test.cpp\"\
    \n\n#line 2 \"graph/template.hpp\"\n\r\n/**\r\n * @brief Graph Template\r\n*/\r\
    \ntemplate <class T>\r\nstruct Edge {\r\n  int from,to;\r\n  T cost;\r\n  int\
    \ idx;\r\n  Edge(){};\r\n  Edge(int f, int t, T c=1, int i=-1) : from(f), to(t),\
    \ cost(c), idx(i){}\r\n  Edge(int t) : to(t), from(-1), cost(1), idx(-1){}\r\n\
    \  operator int() const{ return to; }\r\n  bool operator<(const Edge &e){ return\
    \ cost < e.cost; }\r\n};\r\ntemplate <class T>\r\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\r\n  Graph(){}\r\n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\r\n\
    \  void add_edge(int a, int b, T c=1, int i=-1){\r\n    (*this)[a].push_back({\
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"graph/dijkstra.hpp\"\
    \n\ntemplate <class T, class U = T>\nvoid dijkstra(const Graph<T> &root, const\
    \ int s, vector<U> &dist, vector<int> &prev){\n  const int n = root.size();\n\
    \  dist.assign(n, numeric_limits<U>::max());\n  prev.assign(n, -1);\n  using pui\
    \ = pair<U, int>;\n  priority_queue<pui, vector<pui>, greater<pui>> que;\n  que.push({\
    \ 0, s });\n  while(!que.empty()){\n    U val; int pos;\n    tie(val,pos) = que.top();\n\
    \    que.pop();\n    if(dist[pos] < val) continue;\n    for(const auto &x : root[pos]){\n\
    \      if(chmin(dist[x], val + x.cost)){\n        que.push({ dist[x], x });\n\
    \        prev[x] = pos;\n      }\n    }\n  }\n}\n#line 6 \"test/yosupo/Graph/Shortest-Path.test.cpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios_base::sync_with_stdio(false);\n  int\
    \ n,m,s,t;\n  cin >> n >> m >> s >> t;\n  graph root(n);\n  rep(i, m){\n    int\
    \ a,b,c;\n    cin >> a >> b >> c;\n    root[a].push_back({ a, b, c });\n  }\n\
    \  vl dist;\n  vi prev;\n  dijkstra<int,ll>(root, s, dist, prev);\n\n  if(prev[t]\
    \ == -1){\n    cout << \"-1\\n\";\n    return 0;\n  }\n  int pos = t;\n  vector<pii>\
    \ ans;\n  while(pos != s){\n    ans.push_back({ prev[pos], pos });\n    pos =\
    \ prev[pos];\n  }\n  reverse(all(ans));\n  const int si = ans.size();\n  cout\
    \ << dist[t] << \" \" << si << \"\\n\";\n  for(const auto &x : ans) cout << x.first\
    \ << \" \" << x.second << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../../../template/template.hpp\"\n\n#include \"../../../graph/dijkstra.hpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios_base::sync_with_stdio(false);\n  int\
    \ n,m,s,t;\n  cin >> n >> m >> s >> t;\n  graph root(n);\n  rep(i, m){\n    int\
    \ a,b,c;\n    cin >> a >> b >> c;\n    root[a].push_back({ a, b, c });\n  }\n\
    \  vl dist;\n  vi prev;\n  dijkstra<int,ll>(root, s, dist, prev);\n\n  if(prev[t]\
    \ == -1){\n    cout << \"-1\\n\";\n    return 0;\n  }\n  int pos = t;\n  vector<pii>\
    \ ans;\n  while(pos != s){\n    ans.push_back({ prev[pos], pos });\n    pos =\
    \ prev[pos];\n  }\n  reverse(all(ans));\n  const int si = ans.size();\n  cout\
    \ << dist[t] << \" \" << si << \"\\n\";\n  for(const auto &x : ans) cout << x.first\
    \ << \" \" << x.second << \"\\n\";\n}"
  dependsOn:
  - template/template.hpp
  - graph/dijkstra.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/yosupo/Graph/Shortest-Path.test.cpp
  requiredBy: []
  timestamp: '2023-11-11 17:58:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/Graph/Shortest-Path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Graph/Shortest-Path.test.cpp
- /verify/test/yosupo/Graph/Shortest-Path.test.cpp.html
title: test/yosupo/Graph/Shortest-Path.test.cpp
---
