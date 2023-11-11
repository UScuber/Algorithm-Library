---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/cycle-detect.hpp
    title: "Cycle Detect(\u30B5\u30A4\u30AF\u30EB\u691C\u51FA)"
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
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "#line 1 \"test/yosupo/Graph/Cycle-Detection(Directed).test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#line 1\
    \ \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\n#include\
    \ <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <tuple>\r\n\
    #include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\
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
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Graph/Cycle-Detection(Directed).test.cpp\"\
    \n\n#line 2 \"graph/template.hpp\"\n\r\n/**\r\n * @brief Graph Template\r\n*/\r\
    \ntemplate <class T>\r\nstruct Edge {\r\n  int from,to;\r\n  T cost;\r\n  int\
    \ idx;\r\n  Edge(){};\r\n  Edge(int f, int t, T c=1, int i=-1) : from(f), to(t),\
    \ cost(c), idx(i){}\r\n  Edge(int t) : to(t), from(-1), cost(1), idx(-1){}\r\n\
    \  operator int() const{ return to; }\r\n  bool operator<(const Edge &e){ return\
    \ cost < e.cost; }\r\n};\r\ntemplate <class T>\r\nstruct Graph : vector<vector<Edge<T>>>\
    \ {\r\n  Graph(){}\r\n  Graph(const int &n) : vector<vector<Edge<T>>>(n){}\r\n\
    \  void add_edge(int a, int b, T c=1, int i=-1){\r\n    (*this)[a].push_back({\
    \ a, b, c, i });\r\n  }\r\n};\r\nusing graph = Graph<int>;\n#line 2 \"graph/cycle-detect.hpp\"\
    \n\r\nstruct Cycle {\r\n  Cycle(const graph &_g) : g(_g){}\r\n  vector<Edge<int>>\
    \ detect(){\r\n    const int n = g.size();\r\n    used.assign(n, 0);\r\n    prev.assign(n,\
    \ -1);\r\n    for(int i = 0; i < n; i++){\r\n      if(!used[i] && dfs(i)){\r\n\
    \        reverse(cyc.begin(), cyc.end());\r\n        return cyc;\r\n      }\r\n\
    \    }\r\n    return {};\r\n  }\r\n  private:\r\n  const graph &g;\r\n  vector<int>\
    \ used;\r\n  vector<Edge<int>> prev, cyc;\r\n  bool dfs(int pos){\r\n    used[pos]\
    \ = 1;\r\n    for(const auto &x : g[pos]){\r\n      if(!used[x]){\r\n        prev[x]\
    \ = x;\r\n        if(dfs(x)) return true;\r\n      }else if(used[x] == 1){\r\n\
    \        int cur = pos;\r\n        cyc.push_back(x);\r\n        while(cur != x){\r\
    \n          cyc.push_back(prev[cur]);\r\n          cur = prev[cur].from;\r\n \
    \       }\r\n        return true;\r\n      }\r\n    }\r\n    used[pos] = 2;\r\n\
    \    return false;\r\n  }\r\n};\n#line 6 \"test/yosupo/Graph/Cycle-Detection(Directed).test.cpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,m;\n\
    \  cin >> n >> m;\n  graph root(n);\n  rep(i, m){\n    int a,b;\n    cin >> a\
    \ >> b;\n    root[a].push_back({ a, b, 1, i });\n  }\n  Cycle cycle(root);\n \
    \ auto res = cycle.detect();\n  if(res.empty()) cout << \"-1\\n\";\n  else{\n\
    \    cout << res.size() << \"\\n\";\n    for(auto &x : res) cout << x.idx << \"\
    \\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\
    \ \"../../../template/template.hpp\"\n\n#include \"../../../graph/cycle-detect.hpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,m;\n\
    \  cin >> n >> m;\n  graph root(n);\n  rep(i, m){\n    int a,b;\n    cin >> a\
    \ >> b;\n    root[a].push_back({ a, b, 1, i });\n  }\n  Cycle cycle(root);\n \
    \ auto res = cycle.detect();\n  if(res.empty()) cout << \"-1\\n\";\n  else{\n\
    \    cout << res.size() << \"\\n\";\n    for(auto &x : res) cout << x.idx << \"\
    \\n\";\n  }\n}"
  dependsOn:
  - template/template.hpp
  - graph/cycle-detect.hpp
  - graph/template.hpp
  isVerificationFile: true
  path: test/yosupo/Graph/Cycle-Detection(Directed).test.cpp
  requiredBy: []
  timestamp: '2023-11-11 17:58:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/Graph/Cycle-Detection(Directed).test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Graph/Cycle-Detection(Directed).test.cpp
- /verify/test/yosupo/Graph/Cycle-Detection(Directed).test.cpp.html
title: test/yosupo/Graph/Cycle-Detection(Directed).test.cpp
---
