---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/euler.hpp
    title: math/euler.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL/NTL_1_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/aoj/NTL/NTL_1_D.test.cpp\"\n\n#line 1 \"math/euler.hpp\"\
    \nll euler(ll n){\n  ll res = n, k = n;\n  for(ll i = 2; i*i <= k; i++){\n   \
    \ if(n % i) continue;\n    res = res / i * (i - 1);\n    while(n % i == 0) n /=\
    \ i;\n  }\n  if(n != 1) res = res / n * (n - 1);\n  return res;\n}\n#line 6 \"\
    test/aoj/NTL/NTL_1_D.test.cpp\"\n\nint main(){\n  int n;\n  cin >> n;\n  cout\
    \ << euler(n) << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../math/euler.hpp\"\
    \n\nint main(){\n  int n;\n  cin >> n;\n  cout << euler(n) << \"\\n\";\n}"
  dependsOn:
  - template/template.hpp
  - math/euler.hpp
  isVerificationFile: true
  path: test/aoj/NTL/NTL_1_D.test.cpp
  requiredBy: []
  timestamp: '2023-11-11 17:58:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL/NTL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL/NTL_1_D.test.cpp
- /verify/test/aoj/NTL/NTL_1_D.test.cpp.html
title: test/aoj/NTL/NTL_1_D.test.cpp
---
