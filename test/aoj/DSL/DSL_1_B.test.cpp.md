---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/Weighted-UnionFind.hpp
    title: "Weighted-UnionFind(\u91CD\u307F\u4ED8\u304DUnionFind)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B
  bundledCode: "#line 1 \"test/aoj/DSL/DSL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\
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
    \ 4 \"test/aoj/DSL/DSL_1_B.test.cpp\"\n\n#line 1 \"graph/Weighted-UnionFind.hpp\"\
    \ntemplate <class T>\r\nstruct UnionFindW {\r\n  vector<int> par, rank;\r\n  vector<T>\
    \ diff_weight;\r\n\r\n  UnionFindW(int n = 1, T sum_unity = 0) : n(n), par(n),\
    \ rank(n), diff_weight(n){\r\n    for(int i = 0; i < n; i++) par[i] = i, rank[i]\
    \ = 0, diff_weight[i] = sum_unity;\r\n  }\r\n  int root(int x){\r\n    assert(0\
    \ <= x && x < n);\r\n    if(par[x] == x){\r\n      return x;\r\n    }else{\r\n\
    \      const int r = root(par[x]);\r\n      diff_weight[x] += diff_weight[par[x]];\r\
    \n      return par[x] = r;\r\n    }\r\n  }\r\n  T weight(int x){\r\n    root(x);\r\
    \n    return diff_weight[x];\r\n  }\r\n  bool same(int x, int y){\r\n    return\
    \ root(x) == root(y);\r\n  }\r\n  bool merge(int x, int y, T w){\r\n    w += weight(x);\
    \ w -= weight(y);\r\n    x = root(x); y = root(y);\r\n    if(x == y) return false;\r\
    \n    if(rank[x] < rank[y]) swap(x, y), w = -w;\r\n    if(rank[x] == rank[y])\
    \ ++rank[x];\r\n    par[y] = x;\r\n    diff_weight[y] = w;\r\n    return true;\r\
    \n  }\r\n  T diff(int x, int y){\r\n    return weight(y) - weight(x);\r\n  }\r\
    \n  private:\r\n  int n;\r\n};\n#line 6 \"test/aoj/DSL/DSL_1_B.test.cpp\"\n\n\
    int main(){\n  int n,q;\n  cin >> n >> q;\n  UnionFindW<int> tree(n);\n  rep(i,\
    \ q){\n    int t; cin >> t;\n    if(!t){\n      int x,y,z;\n      cin >> x >>\
    \ y >> z;\n      tree.merge(x, y, z);\n    }else{\n      int x,y;\n      cin >>\
    \ x >> y;\n      if(!tree.same(x, y)) cout << \"?\\n\";\n      else cout << tree.diff(x,\
    \ y) << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../graph/Weighted-UnionFind.hpp\"\
    \n\nint main(){\n  int n,q;\n  cin >> n >> q;\n  UnionFindW<int> tree(n);\n  rep(i,\
    \ q){\n    int t; cin >> t;\n    if(!t){\n      int x,y,z;\n      cin >> x >>\
    \ y >> z;\n      tree.merge(x, y, z);\n    }else{\n      int x,y;\n      cin >>\
    \ x >> y;\n      if(!tree.same(x, y)) cout << \"?\\n\";\n      else cout << tree.diff(x,\
    \ y) << \"\\n\";\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - graph/Weighted-UnionFind.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-03-13 22:02:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_1_B.test.cpp
- /verify/test/aoj/DSL/DSL_1_B.test.cpp.html
title: test/aoj/DSL/DSL_1_B.test.cpp
---
