---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geometry/template.hpp
    title: geometry/template.hpp
  - icon: ':warning:'
    path: geometry/totsuhou.hpp
    title: geometry/totsuhou.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CumulativeSum2D.test.cpp
    title: test/aoj/CumulativeSum2D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/Weighted-UnionFind.test.cpp
    title: test/aoj/Weighted-UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/bellman-ford.test.cpp
    title: test/aoj/bellman-ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/lca.test.cpp
    title: test/aoj/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/slide-min.test.cpp
    title: test/aoj/slide-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Associative-Array.test.cpp
    title: test/yosupo/Associative-Array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Cycle-Detection(Directed).test.cpp
    title: test/yosupo/Cycle-Detection(Directed).test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Queue-Operate-All-Composite.test.cpp
    title: test/yosupo/Queue-Operate-All-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Range-Kth-Smallest.test.cpp
    title: test/yosupo/Range-Kth-Smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Static-RMQ.test.cpp
    title: test/yosupo/Static-RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Static-Range-Frequency.test.cpp
    title: test/yosupo/Static-Range-Frequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Strongly-Connected-Components.test.cpp
    title: test/yosupo/Strongly-Connected-Components.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Tree-Diameter.test.cpp
    title: test/yosupo/Tree-Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.hpp\"\n#include <iostream>\r\n#include\
    \ <cmath>\r\n#include <string>\r\n#include <vector>\r\n#include <algorithm>\r\n\
    #include <utility>\r\n#include <tuple>\r\n#include <cstdint>\r\n#include <cstdio>\r\
    \n#include <map>\r\n#include <queue>\r\n#include <set>\r\n#include <stack>\r\n\
    #include <deque>\r\n#include <unordered_map>\r\n#include <unordered_set>\r\n#include\
    \ <bitset>\r\n#include <cctype>\r\n#include <climits>\r\n#include <functional>\r\
    \n#include <cassert>\r\n#include <numeric>\r\n#define rep(i, n) for(int i = 0;\
    \ i < (n); i++)\r\n#define per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\nusing\
    \ ll = long long;\r\n#define vi vector<int>\r\n#define vvi vector<vi>\r\n#define\
    \ vl vector<ll>\r\n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n\
    #define all(a) (a).begin(), (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\
    \nconstexpr int mod = 1000000007;\r\nusing namespace std;\r\ntemplate<class T,\
    \ class U>\r\nbool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\
    \ntemplate<class T, class U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a\
    \ = b, 1) : 0; }\n"
  code: "#include <iostream>\r\n#include <cmath>\r\n#include <string>\r\n#include\
    \ <vector>\r\n#include <algorithm>\r\n#include <utility>\r\n#include <tuple>\r\
    \n#include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <deque>\r\n#include <unordered_map>\r\
    \n#include <unordered_set>\r\n#include <bitset>\r\n#include <cctype>\r\n#include\
    \ <climits>\r\n#include <functional>\r\n#include <cassert>\r\n#include <numeric>\r\
    \n#define rep(i, n) for(int i = 0; i < (n); i++)\r\n#define per(i, n) for(int\
    \ i = (n) - 1; i >= 0; i--)\r\nusing ll = long long;\r\n#define vi vector<int>\r\
    \n#define vvi vector<vi>\r\n#define vl vector<ll>\r\n#define pii pair<int, int>\r\
    \n#define pll pair<ll, ll>\r\n#define all(a) (a).begin(), (a).end()\r\n#define\
    \ rall(a) (a).rbegin(), (a).rend()\r\nconstexpr int mod = 1000000007;\r\nusing\
    \ namespace std;\r\ntemplate<class T, class U>\r\nbool chmax(T &a, const U &b){\
    \ return a < b ? (a = b, 1) : 0; }\r\ntemplate<class T, class U>\r\nbool chmin(T\
    \ &a, const U &b){ return a > b ? (a = b, 1) : 0; }"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy:
  - geometry/template.hpp
  - geometry/totsuhou.hpp
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Queue-Operate-All-Composite.test.cpp
  - test/yosupo/Cycle-Detection(Directed).test.cpp
  - test/yosupo/Range-Kth-Smallest.test.cpp
  - test/yosupo/Associative-Array.test.cpp
  - test/yosupo/Tree-Diameter.test.cpp
  - test/yosupo/Strongly-Connected-Components.test.cpp
  - test/yosupo/Static-RMQ.test.cpp
  - test/yosupo/Static-Range-Frequency.test.cpp
  - test/aoj/slide-min.test.cpp
  - test/aoj/CumulativeSum2D.test.cpp
  - test/aoj/bellman-ford.test.cpp
  - test/aoj/Weighted-UnionFind.test.cpp
  - test/aoj/lca.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
