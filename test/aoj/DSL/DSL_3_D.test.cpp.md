---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/slide-min.hpp
    title: data-structure/slide-min.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL/DSL_3_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/aoj/DSL/DSL_3_D.test.cpp\"\n\n#line 1 \"data-structure/slide-min.hpp\"\
    \ntemplate <class T>\r\nvector<T> slide_min(const vector<T> &a, int k){\r\n  int\
    \ n = (int)a.size();\r\n  deque<T> que;\r\n  vector<T> res(n);\r\n  for(int i\
    \ = 0; i < n + k - 1; i++){\r\n    while(!que.empty() && i < n && a[que.back()]\
    \ >= a[i]){\r\n      que.pop_back();\r\n    }\r\n    que.push_back(i);\r\n   \
    \ if(i - k + 1 >= 0){\r\n      res[i - k + 1] = a[que.front()];\r\n      if(que.front()\
    \ == i - k + 1) que.pop_front();\r\n    }\r\n  }\r\n  return res;\r\n}\n#line\
    \ 6 \"test/aoj/DSL/DSL_3_D.test.cpp\"\n\nint main(){\n  int n,k;\n  cin >> n >>\
    \ k;\n  vi a(n);\n  rep(i, n) cin >> a[i];\n  const auto res = slide_min(a, k);\n\
    \  rep(i, n-k+1) cout << res[i] << \" \\n\"[i == n - k];\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../data-structure/slide-min.hpp\"\
    \n\nint main(){\n  int n,k;\n  cin >> n >> k;\n  vi a(n);\n  rep(i, n) cin >>\
    \ a[i];\n  const auto res = slide_min(a, k);\n  rep(i, n-k+1) cout << res[i] <<\
    \ \" \\n\"[i == n - k];\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/slide-min.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_3_D.test.cpp
  requiredBy: []
  timestamp: '2023-11-11 17:58:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_3_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_3_D.test.cpp
- /verify/test/aoj/DSL/DSL_3_D.test.cpp.html
title: test/aoj/DSL/DSL_3_D.test.cpp
---
