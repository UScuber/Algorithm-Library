---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modpow.hpp
    title: math/modpow.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL/NTL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B\"\
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
    \ 4 \"test/aoj/NTL/NTL_1_B.test.cpp\"\n\n#line 1 \"math/modpow.hpp\"\nll modPow(ll\
    \ a, ll n, ll p){\n  a %= p;\n  ll res = 1;\n  while(n){\n    if(n & 1) (res *=\
    \ a) %= p;\n    (a *= a) %= p;\n    n >>= 1;\n  }\n  return res;\n}\n#line 6 \"\
    test/aoj/NTL/NTL_1_B.test.cpp\"\n\nint main(){\n  int n,m;\n  cin >> n >> m;\n\
    \  cout << modPow(n, m, mod) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_B\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../math/modpow.hpp\"\
    \n\nint main(){\n  int n,m;\n  cin >> n >> m;\n  cout << modPow(n, m, mod) <<\
    \ \"\\n\";\n}"
  dependsOn:
  - template/template.hpp
  - math/modpow.hpp
  isVerificationFile: true
  path: test/aoj/NTL/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-03-13 22:17:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL/NTL_1_B.test.cpp
- /verify/test/aoj/NTL/NTL_1_B.test.cpp.html
title: test/aoj/NTL/NTL_1_B.test.cpp
---
