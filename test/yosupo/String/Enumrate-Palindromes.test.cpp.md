---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/manacher.hpp
    title: string/manacher.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/yosupo/String/Enumrate-Palindromes.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\r\n\r\n#line\
    \ 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\n#include\
    \ <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <utility>\r\
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
    \ 4 \"test/yosupo/String/Enumrate-Palindromes.test.cpp\"\n\r\n#line 1 \"string/manacher.hpp\"\
    \nvector<int> manacher(const string &s){\r\n  const int len = s.size();\r\n  vector<int>\
    \ r(len);\r\n  int i = 0, j = 0;\r\n  while(i < len){\r\n    while(i-j >= 0 &&\
    \ i+j < len && s[i-j] == s[i+j]) j++;\r\n    r[i] = j;\r\n    int k = 1;\r\n \
    \   while(i-k >= 0 && k+r[i-k] < j) r[i+k] = r[i-k], k++;\r\n    i += k; j -=\
    \ k;\r\n  }\r\n  return r;\r\n}\n#line 6 \"test/yosupo/String/Enumrate-Palindromes.test.cpp\"\
    \n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n\
    \  char c;\r\n  string s = \"$\";\r\n  while((c = getchar()) != 10){\r\n    s\
    \ += c;\r\n    s += '$';\r\n  }\r\n  const vi res = manacher(s);\r\n  const int\
    \ l = res.size();\r\n  for(int i = 1; i < l-1; i++){\r\n    if(i & 1) cout <<\
    \ (res[i]-1)/2*2+1 << \" \";\r\n    else cout << (res[i]-1)/2*2 << \" \";\r\n\
    \  }\r\n  cout << \"\\n\";\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \r\n\r\n#include \"../../../template/template.hpp\"\r\n\r\n#include \"../../../string/manacher.hpp\"\
    \r\n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  char c;\r\n  string s = \"$\";\r\n  while((c = getchar()) != 10){\r\n    s\
    \ += c;\r\n    s += '$';\r\n  }\r\n  const vi res = manacher(s);\r\n  const int\
    \ l = res.size();\r\n  for(int i = 1; i < l-1; i++){\r\n    if(i & 1) cout <<\
    \ (res[i]-1)/2*2+1 << \" \";\r\n    else cout << (res[i]-1)/2*2 << \" \";\r\n\
    \  }\r\n  cout << \"\\n\";\r\n}"
  dependsOn:
  - template/template.hpp
  - string/manacher.hpp
  isVerificationFile: true
  path: test/yosupo/String/Enumrate-Palindromes.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 19:15:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/String/Enumrate-Palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/String/Enumrate-Palindromes.test.cpp
- /verify/test/yosupo/String/Enumrate-Palindromes.test.cpp.html
title: test/yosupo/String/Enumrate-Palindromes.test.cpp
---
