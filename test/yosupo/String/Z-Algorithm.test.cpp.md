---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/z-algorithm.hpp
    title: string/z-algorithm.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/String/Z-Algorithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n\r\n#line 1 \"template/template.hpp\"\
    \n#include <iostream>\r\n#include <cmath>\r\n#include <string>\r\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <tuple>\r\n#include <cstdint>\r\n#include <cstdio>\r\
    \n#include <map>\r\n#include <queue>\r\n#include <set>\r\n#include <stack>\r\n\
    #include <deque>\r\n#include <bitset>\r\n#include <cctype>\r\n#include <climits>\r\
    \n#include <functional>\r\n#include <cassert>\r\n#include <numeric>\r\n#include\
    \ <cstring>\r\n#define rep(i, n) for(int i = 0; i < (n); i++)\r\n#define per(i,\
    \ n) for(int i = (n) - 1; i >= 0; i--)\r\nusing ll = long long;\r\n#define vi\
    \ vector<int>\r\n#define vvi vector<vi>\r\n#define vl vector<ll>\r\n#define pii\
    \ pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define all(a) (a).begin(), (a).end()\r\
    \n#define rall(a) (a).rbegin(), (a).rend()\r\nconstexpr int mod = 1000000007;\r\
    \nusing namespace std;\r\ntemplate<class T, class U>\r\nbool chmax(T &a, const\
    \ U &b){ return a < b ? (a = b, 1) : 0; }\r\ntemplate<class T, class U>\r\nbool\
    \ chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }\n#line 4 \"test/yosupo/String/Z-Algorithm.test.cpp\"\
    \n\r\n#line 1 \"string/z-algorithm.hpp\"\nvector<int> z_algo(const string &s){\r\
    \n  const int n = s.size();\r\n  vector<int> z(n);\r\n  z[0] = n;\r\n  int i =\
    \ 1, j = 0;\r\n  while(i < n){\r\n    while(i + j < n && s[j] == s[i + j]) j++;\r\
    \n    z[i] = j;\r\n    if(!j){\r\n      i++;\r\n      continue;\r\n    }\r\n \
    \   int k = 1;\r\n    while(k < j && z[k] + k < j) z[i + k++] = z[k];\r\n    i\
    \ += k;\r\n    j -= k;\r\n  }\r\n  return z;\r\n}\n#line 6 \"test/yosupo/String/Z-Algorithm.test.cpp\"\
    \n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n\
    \  string s;\r\n  cin >> s;\r\n  for(const int x : z_algo(s)) cout << x << \"\
    \ \";\r\n  cout << \"\\n\";\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\r\n\r\n#include\
    \ \"../../../template/template.hpp\"\r\n\r\n#include \"../../../string/z-algorithm.hpp\"\
    \r\n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  string s;\r\n  cin >> s;\r\n  for(const int x : z_algo(s)) cout << x << \"\
    \ \";\r\n  cout << \"\\n\";\r\n}"
  dependsOn:
  - template/template.hpp
  - string/z-algorithm.hpp
  isVerificationFile: true
  path: test/yosupo/String/Z-Algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-11-11 17:58:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/String/Z-Algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/String/Z-Algorithm.test.cpp
- /verify/test/yosupo/String/Z-Algorithm.test.cpp.html
title: test/yosupo/String/Z-Algorithm.test.cpp
---
