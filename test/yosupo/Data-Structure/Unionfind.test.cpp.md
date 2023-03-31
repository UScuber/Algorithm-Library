---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/UnionFind.hpp
    title: graph/UnionFind.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"template/template.hpp\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Data-Structure/Unionfind.test.cpp\"\n\n\
    #line 1 \"graph/UnionFind.hpp\"\nstruct UnionFind {\r\n  private:\r\n  int n;\r\
    \n  public:\r\n  vector<int> d;\r\n  UnionFind(int n): n(n), d(n, -1){}\r\n  int\
    \ root(int x){\r\n    assert(0 <= x && x < n);\r\n    if(d[x] < 0) return x;\r\
    \n    return d[x] = root(d[x]);\r\n  }\r\n  bool unite(int x, int y){\r\n    x\
    \ = root(x);\r\n    y = root(y);\r\n    if(x == y) return false;\r\n    if(d[x]\
    \ > d[y]) swap(x, y);\r\n    d[x] += d[y];\r\n    d[y] = x;\r\n    return true;\r\
    \n  }\r\n  bool same(int x, int y){\r\n    return root(x) == root(y);\r\n  }\r\
    \n  int size(int x){\r\n    return -d[root(x)];\r\n  }\r\n};\r\n#line 6 \"test/yosupo/Data-Structure/Unionfind.test.cpp\"\
    \n\nint main(){\n  int n,q;\n  scanf(\"%d%d\", &n, &q);\n  UnionFind tree(n);\n\
    \  rep(i, q){\n    int t,a,b;\n    scanf(\"%d%d%d\", &t, &a, &b);\n    if(!t)\
    \ tree.unite(a, b);\n    else cout << tree.same(a, b) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../../template/template.hpp\"\n\n#include \"../../../graph/UnionFind.hpp\"\
    \n\nint main(){\n  int n,q;\n  scanf(\"%d%d\", &n, &q);\n  UnionFind tree(n);\n\
    \  rep(i, q){\n    int t,a,b;\n    scanf(\"%d%d%d\", &t, &a, &b);\n    if(!t)\
    \ tree.unite(a, b);\n    else cout << tree.same(a, b) << \"\\n\";\n  }\n}"
  dependsOn:
  - template/template.hpp
  - graph/UnionFind.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Unionfind.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 19:15:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Unionfind.test.cpp
- /verify/test/yosupo/Data-Structure/Unionfind.test.cpp.html
title: test/yosupo/Data-Structure/Unionfind.test.cpp
---
