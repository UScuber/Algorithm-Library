---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: others/int128.hpp
    title: others/int128.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb_128bit
    links:
    - https://judge.yosupo.jp/problem/many_aplusb_128bit
  bundledCode: "#line 1 \"test/yosupo/Sample/Many-A+B(128bit).test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb_128bit\"\n\n#line 1 \"\
    template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\n#include <string>\r\
    \n#include <vector>\r\n#include <algorithm>\r\n#include <utility>\r\n#include\
    \ <tuple>\r\n#include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\n#include\
    \ <queue>\r\n#include <set>\r\n#include <stack>\r\n#include <deque>\r\n#include\
    \ <unordered_map>\r\n#include <unordered_set>\r\n#include <bitset>\r\n#include\
    \ <cctype>\r\n#include <climits>\r\n#include <functional>\r\n#include <cassert>\r\
    \n#include <numeric>\r\n#define rep(i, n) for(int i = 0; i < (n); i++)\r\n#define\
    \ per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\nusing ll = long long;\r\n#define\
    \ vi vector<int>\r\n#define vvi vector<vi>\r\n#define vl vector<ll>\r\n#define\
    \ pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define all(a) (a).begin(),\
    \ (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\nconstexpr int mod =\
    \ 1000000007;\r\nusing namespace std;\r\ntemplate<class T, class U>\r\nbool chmax(T\
    \ &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\ntemplate<class T, class\
    \ U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }\n#line\
    \ 4 \"test/yosupo/Sample/Many-A+B(128bit).test.cpp\"\n\n#line 1 \"others/int128.hpp\"\
    \nusing lll = __int128;\r\nostream &operator<<(ostream &os, lll x){\r\n  #define\
    \ pc(c) os.put(c)\r\n  char tmp_s[40];\r\n  if(!x){ pc('0'); return os; }\r\n\
    \  if(x < 0){ pc('-'); x = -x; }\r\n  char *t = tmp_s;\r\n  while(x){\r\n    const\
    \ lll y = x / 10;\r\n    *(t++) = (x - y*10) + '0';\r\n    x = y;\r\n  }\r\n \
    \ while(t != tmp_s) pc(*(--t));\r\n  return os;\r\n  #undef pc\r\n}\r\nistream\
    \ &operator>>(istream &is, lll &x){\r\n  #define gc(c) is.get(c)\r\n  bool neg\
    \ = false;\r\n  char c;\r\n  gc(c);\r\n  while((c < '0' || c > '9') && c != '-')\
    \ gc(c);\r\n  if(c == '-') neg = true, gc(c);\r\n  x = c^'0'; gc(c);\r\n  while(c\
    \ >= '0' && c <= '9') x = x*10 + (c^'0'), gc(c);\r\n  if(neg) x = -x;\r\n  return\
    \ is;\r\n  #undef gc\r\n}\n#line 6 \"test/yosupo/Sample/Many-A+B(128bit).test.cpp\"\
    \n\nint main(){\n  int t;\n  cin >> t;\n  rep(i, t){\n    lll a,b;\n    cin >>\
    \ a >> b;\n    cout << a + b << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb_128bit\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../others/int128.hpp\"\
    \n\nint main(){\n  int t;\n  cin >> t;\n  rep(i, t){\n    lll a,b;\n    cin >>\
    \ a >> b;\n    cout << a + b << \"\\n\";\n  }\n}"
  dependsOn:
  - template/template.hpp
  - others/int128.hpp
  isVerificationFile: true
  path: test/yosupo/Sample/Many-A+B(128bit).test.cpp
  requiredBy: []
  timestamp: '2023-04-19 16:35:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Sample/Many-A+B(128bit).test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Sample/Many-A+B(128bit).test.cpp
- /verify/test/yosupo/Sample/Many-A+B(128bit).test.cpp.html
title: test/yosupo/Sample/Many-A+B(128bit).test.cpp
---
