---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: graph/scc.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/Graph/Strongly-Connected-Components.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#line 1 \"template/template.hpp\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Graph/Strongly-Connected-Components.test.cpp\"\
    \n\n#line 1 \"graph/scc.hpp\"\ntemplate <class graph>\r\nstruct scc {\r\n  scc(const\
    \ graph &g): root(g), n(g.size()){ init(); }\r\n  void init(){\r\n    rroot.resize(n);\r\
    \n    used.resize(n);\r\n    ord.resize(n);\r\n    comp.resize(n, -1);\r\n   \
    \ build();\r\n  }\r\n  void build(){\r\n    for(int i = 0; i < n; i++){\r\n  \
    \    for(const auto &x : root[i])\r\n        rroot[x].push_back(i);\r\n    }\r\
    \n    for(int i = 0; i < n; i++) dfs(i);\r\n    reverse(ord.begin(), ord.end());\r\
    \n    int cnt = 0;\r\n    for(const auto &x : ord) if(comp[x] == -1){\r\n    \
    \  rdfs(x, cnt);\r\n      cnt++;\r\n    }\r\n    dag.resize(cnt);\r\n    group.resize(cnt);\r\
    \n    for(int i = 0; i < n; i++){\r\n      for(const auto &x : root[i]){\r\n \
    \       const int a = comp[i], b = comp[x];\r\n        if(a == b) continue;\r\n\
    \        dag[a].push_back(b);\r\n      }\r\n    }\r\n    for(int i = 0; i < n;\
    \ i++){\r\n      group[comp[i]].push_back(i);\r\n    }\r\n  }\r\n  int operator[](int\
    \ i) const{\r\n    return comp[i];\r\n  }\r\n  vector<vector<int>> group, dag;\r\
    \n  private:\r\n  int n = 0;\r\n  const graph &root;\r\n  graph rroot; //rev\r\
    \n  vector<int> used, ord, comp;\r\n  void dfs(int pos){\r\n    if(used[pos])\
    \ return;\r\n    used[pos] = 1;\r\n    for(const auto &x : root[pos]) dfs(x);\r\
    \n    ord.push_back(pos);\r\n  }\r\n  void rdfs(int pos, const int cnt){\r\n \
    \   if(comp[pos] != -1) return;\r\n    comp[pos] = cnt;\r\n    for(const auto\
    \ &x : rroot[pos]) rdfs(x, cnt);\r\n  }\r\n};\n#line 6 \"test/yosupo/Graph/Strongly-Connected-Components.test.cpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,m;\n\
    \  cin >> n >> m;\n  vvi root(n);\n  rep(i, m){\n    int a,b;\n    cin >> a >>\
    \ b;\n    root[a].push_back(b);\n  }\n  scc<vvi> g(root);\n  cout << g.group.size()\
    \ << \"\\n\";\n  for(const vi &t : g.group){\n    int si = t.size();\n    cout\
    \ << si << \" \";\n    per(i, si) cout << t[i] << \" \";\n    cout << \"\\n\"\
    ;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../../template/template.hpp\"\
    \n\n#include \"../../../graph/scc.hpp\"\n\nint main(){\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  int n,m;\n  cin >> n >> m;\n  vvi root(n);\n\
    \  rep(i, m){\n    int a,b;\n    cin >> a >> b;\n    root[a].push_back(b);\n \
    \ }\n  scc<vvi> g(root);\n  cout << g.group.size() << \"\\n\";\n  for(const vi\
    \ &t : g.group){\n    int si = t.size();\n    cout << si << \" \";\n    per(i,\
    \ si) cout << t[i] << \" \";\n    cout << \"\\n\";\n  }\n}"
  dependsOn:
  - template/template.hpp
  - graph/scc.hpp
  isVerificationFile: true
  path: test/yosupo/Graph/Strongly-Connected-Components.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 19:15:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Graph/Strongly-Connected-Components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Graph/Strongly-Connected-Components.test.cpp
- /verify/test/yosupo/Graph/Strongly-Connected-Components.test.cpp.html
title: test/yosupo/Graph/Strongly-Connected-Components.test.cpp
---
