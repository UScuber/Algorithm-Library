---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: "Longest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
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
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"test/yosupo/Tree/Jump-on-Tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#line 1 \"template/template.hpp\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Tree/Jump-on-Tree.test.cpp\"\n\n#line\
    \ 1 \"graph/lca.hpp\"\ntemplate <class graph>\r\nstruct lca {\r\n  const graph\
    \ &G;\r\n  vector<vector<int>> parent;\r\n  vector<int> dep;\r\n  int log = 1;\r\
    \n  lca(const graph &G, int root = 0) : G(G){\r\n    init(root);\r\n  }\r\n  void\
    \ init(int root = 0){\r\n    const int n = G.size();\r\n    dep.assign(n, -1);\r\
    \n    parent.assign(1, vector<int>(n, -1));\r\n    queue<int> que({ root });\r\
    \n    dep[root] = 0;\r\n    int max_dep = 0;\r\n    while(!que.empty()){\r\n \
    \     const int pos = que.front();\r\n      que.pop();\r\n      max_dep = max(max_dep,\
    \ dep[pos]);\r\n      for(const auto &x : G[pos]){\r\n        if(dep[x] == -1){\r\
    \n          dep[x] = dep[pos] + 1;\r\n          parent[0][x] = pos;\r\n      \
    \    que.push(x);\r\n        }\r\n      }\r\n    }\r\n    while((1 << log) <=\
    \ max_dep) log++;\r\n    parent.resize(log, vector<int>(n, -1));\r\n    for(int\
    \ k = 0; k < log - 1; k++){\r\n      for(int v = 0; v < n; v++){\r\n        if(parent[k][v]\
    \ < 0) parent[k + 1][v] = -1;\r\n        else parent[k + 1][v] = parent[k][parent[k][v]];\r\
    \n      }\r\n    }\r\n  }\r\n  int query(int u, int v) const{\r\n    if(dep[u]\
    \ < dep[v]) swap(u, v);\r\n    const int sub = dep[u] - dep[v];\r\n    for(int\
    \ k = 0; k < log; k++){\r\n      if(!(sub >> k)) break;\r\n      if(sub >> k &\
    \ 1) u = parent[k][u];\r\n    }\r\n    if(u == v) return u;\r\n    for(int k =\
    \ __lg(dep[u]); k >= 0; k--){\r\n      if(parent[k][u] != parent[k][v]){\r\n \
    \       u = parent[k][u];\r\n        v = parent[k][v];\r\n      }\r\n    }\r\n\
    \    return parent[0][u];\r\n  }\r\n  int dist(const int u, const int v) const{\r\
    \n    return dep[u] + dep[v] - dep[query(u, v)] * 2;\r\n  }\r\n  int jump(int\
    \ u, int v, int d) const{\r\n    const int lc = query(u, v);\r\n    const int\
    \ l = dep[u] - dep[lc];\r\n    const int r = dep[v] - dep[lc];\r\n    if(d < 0\
    \ || d > l + r) return -1;\r\n    if(l < d){\r\n      d = l + r - d;\r\n     \
    \ swap(u, v);\r\n    }\r\n    for(int k = 0; k < log; k++){\r\n      if(!(d >>\
    \ k)) break;\r\n      if(d >> k & 1) u = parent[k][u];\r\n    }\r\n    return\
    \ u;\r\n  }\r\n};\n#line 6 \"test/yosupo/Tree/Jump-on-Tree.test.cpp\"\n\nint main(){\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n  cin >> n >>\
    \ q;\n  vvi root(n);\n  rep(i, n - 1){\n    int a,b;\n    cin >> a >> b;\n   \
    \ root[a].push_back(b);\n    root[b].push_back(a);\n  }\n  const lca<vvi> g(root);\n\
    \  rep(_, q){\n    int s,t,k;\n    cin >> s >> t >> k;\n    cout << g.jump(s,\
    \ t, k) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include\
    \ \"../../../template/template.hpp\"\n\n#include \"../../../graph/lca.hpp\"\n\n\
    int main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n\
    \  cin >> n >> q;\n  vvi root(n);\n  rep(i, n - 1){\n    int a,b;\n    cin >>\
    \ a >> b;\n    root[a].push_back(b);\n    root[b].push_back(a);\n  }\n  const\
    \ lca<vvi> g(root);\n  rep(_, q){\n    int s,t,k;\n    cin >> s >> t >> k;\n \
    \   cout << g.jump(s, t, k) << \"\\n\";\n  }\n}"
  dependsOn:
  - template/template.hpp
  - graph/lca.hpp
  isVerificationFile: true
  path: test/yosupo/Tree/Jump-on-Tree.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 19:15:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Tree/Jump-on-Tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Tree/Jump-on-Tree.test.cpp
- /verify/test/yosupo/Tree/Jump-on-Tree.test.cpp.html
title: test/yosupo/Tree/Jump-on-Tree.test.cpp
---
