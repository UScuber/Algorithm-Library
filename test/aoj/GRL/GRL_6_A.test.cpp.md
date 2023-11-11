---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/fordfulkerson.hpp
    title: graph/fordfulkerson.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL/GRL_6_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/aoj/GRL/GRL_6_A.test.cpp\"\n\n#line 1 \"graph/fordfulkerson.hpp\"\
    \ntemplate <class T>\r\nstruct maxflow {\r\n  struct edge {\r\n    int to,rev;\
    \ T cap;\r\n  };\r\n  maxflow(int n) : n(n), G(n), used(n){}\r\n  maxflow(const\
    \ vector<vector<edge>> &g): n(g.size()), G(g){}\r\n  void add_edge(int from, int\
    \ to, T cap){\r\n    G[from].push_back({to, (int)G[to].size(), cap});\r\n    G[to].push_back({from,\
    \ (int)G[from].size()-1, 0});\r\n  }\r\n  T max_flow(int s, int t){\r\n    T flow\
    \ = 0;\r\n    while(true){\r\n      used.assign(n, false);\r\n      T f = dfs(s,\
    \ t, mod);\r\n      if(f == 0) return flow;\r\n      flow += f;\r\n    }\r\n \
    \ }\r\n  private:\r\n  int n;\r\n  vector<vector<edge>> G;\r\n  vector<bool> used;\r\
    \n\r\n  T dfs(int v, int t, T f){\r\n    if(v == t) return f;\r\n    used[v] =\
    \ true;\r\n    for(edge &e : G[v]){\r\n      if(!used[e.to] && e.cap > 0){\r\n\
    \        T d = dfs(e.to, t, min(f, e.cap));\r\n        if(d > 0){\r\n        \
    \  e.cap -= d;\r\n          G[e.to][e.rev].cap += d;\r\n          return d;\r\n\
    \        }\r\n      }\r\n    }\r\n    return 0;\r\n  }\r\n};\n#line 6 \"test/aoj/GRL/GRL_6_A.test.cpp\"\
    \n\nint main(){\n  int n,m;\n  cin >> n >> m;\n  maxflow<int> g(n);\n  rep(i,\
    \ m){\n    int a,b,c;\n    cin >> a >> b >> c;\n    g.add_edge(a, b, c);\n  }\n\
    \  cout << g.max_flow(0, n-1) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_6_A\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../graph/fordfulkerson.hpp\"\
    \n\nint main(){\n  int n,m;\n  cin >> n >> m;\n  maxflow<int> g(n);\n  rep(i,\
    \ m){\n    int a,b,c;\n    cin >> a >> b >> c;\n    g.add_edge(a, b, c);\n  }\n\
    \  cout << g.max_flow(0, n-1) << \"\\n\";\n}"
  dependsOn:
  - template/template.hpp
  - graph/fordfulkerson.hpp
  isVerificationFile: true
  path: test/aoj/GRL/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2023-11-11 17:58:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL/GRL_6_A.test.cpp
- /verify/test/aoj/GRL/GRL_6_A.test.cpp.html
title: test/aoj/GRL/GRL_6_A.test.cpp
---
