---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: others/fastIO.hpp
    title: others/fastIO.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"test/yosupo/Many-A+B.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\
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
    \ 4 \"test/yosupo/Many-A+B.test.cpp\"\n\n#line 1 \"others/fastIO.hpp\"\nstruct\
    \ FastIO {\r\n  char tmp_s[20];\r\n  constexpr static int prec = 5;\r\n  #define\
    \ gc getchar\r\n  template <class T>\r\n  inline void read(T &x){\r\n    bool\
    \ neg = false;\r\n    int c = gc();\r\n    while((c < '0' || c > '9') && c !=\
    \ '-') c = gc();\r\n    if(c == '-') neg = true, c = gc();\r\n    x = c^'0'; c\
    \ = gc();\r\n    while(c >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();\r\n\
    \    if(neg) x = -x;\r\n  }\r\n  inline void read(double &x){\r\n    bool neg\
    \ = false;\r\n    int c = gc();\r\n    while((c < '0' || c > '9') && c != '-')\
    \ c = gc();\r\n    if(c == '-') neg = true, c = gc();\r\n    x = c^'0'; c = gc();\r\
    \n    while(c >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();\r\n    if(c ==\
    \ '.'){\r\n      c = gc();\r\n      double dig = 1;\r\n      while(c >= '0' &&\
    \ c <= '9') x += (c^'0')*(dig/=10), c = gc();\r\n    }\r\n    if(neg) x = -x;\r\
    \n  }\r\n  inline void read(string &x){\r\n    char c = gc();\r\n    while(c <\
    \ '!' || '~' < c) c = gc();\r\n    while(c >= '!' && '~' >= c) x += c, c = gc();\r\
    \n  }\r\n  inline void read(char &x){\r\n    x = gc();\r\n    while(x < '!' ||\
    \ '~' < x) x = gc();\r\n  }\r\n  #undef gc\r\n  #define pc putchar\r\n  inline\
    \ void out(int x){\r\n    if(!x){ pc('0'); return; }\r\n    if(x < 0){ pc('-');\
    \ x = -x; }\r\n    char *t = tmp_s;\r\n    while(x){\r\n      int y = x / 10;\r\
    \n      *(t++) = (x - y*10) + '0';\r\n      x = y;\r\n    }\r\n    while(t !=\
    \ tmp_s) pc(*(--t));\r\n  }\r\n  inline void out(ll x){\r\n    if(!x){ pc('0');\
    \ return; }\r\n    if(x < 0){ pc('-'); x = -x; }\r\n    char *t = tmp_s;\r\n \
    \   while(x){\r\n      ll y = x / 10;\r\n      *(t++) = (x - y*10) + '0';\r\n\
    \      x = y;\r\n    }\r\n    while(t != tmp_s) pc(*(--t));\r\n  }\r\n  inline\
    \ void out(double x){\r\n    if(x == 0){ pc('0'); return; }\r\n    if(x < 0){\
    \ pc('-'); x = -x; }\r\n    out(ll(x));\r\n    x -= ll(x);\r\n    pc('.');\r\n\
    \    for(int i = 0; i < prec; i++){\r\n      x *= 10;\r\n      pc(int(x) + '0');\r\
    \n      x -= int(x);\r\n    }\r\n  }\r\n  inline void out(const string &s){\r\n\
    \    for(const char &c : s) pc(c);\r\n  }\r\n  inline void out(const char &c){\
    \ pc(c); }\r\n  #undef pc\r\n  template <class T>\r\n  friend FastIO &operator>>(FastIO\
    \ &io, T &x){\r\n    io.read(x);\r\n    return io;\r\n  }\r\n  template <class\
    \ T>\r\n  friend FastIO &operator<<(FastIO &io, const T &x){\r\n    io.out(x);\r\
    \n    return io;\r\n  }\r\n};\r\nFastIO io;\r\n#define cin io\r\n#define cout\
    \ io\n#line 6 \"test/yosupo/Many-A+B.test.cpp\"\n\nint main(){\n  int t;\n  cin\
    \ >> t;\n  rep(i, t){\n    ll a,b;\n    cin >> a >> b;\n    cout << a + b << \"\
    \\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include\
    \ \"../../template/template.hpp\"\n\n#include \"../../others/fastIO.hpp\"\n\n\
    int main(){\n  int t;\n  cin >> t;\n  rep(i, t){\n    ll a,b;\n    cin >> a >>\
    \ b;\n    cout << a + b << \"\\n\";\n  }\n}"
  dependsOn:
  - template/template.hpp
  - others/fastIO.hpp
  isVerificationFile: true
  path: test/yosupo/Many-A+B.test.cpp
  requiredBy: []
  timestamp: '2023-03-14 18:00:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Many-A+B.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Many-A+B.test.cpp
- /verify/test/yosupo/Many-A+B.test.cpp.html
title: test/yosupo/Many-A+B.test.cpp
---
