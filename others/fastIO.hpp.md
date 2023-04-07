---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Sample/Many-A+B.test.cpp
    title: test/yosupo/Sample/Many-A+B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/fastIO.hpp\"\nstruct FastIO {\r\n  char tmp_s[20];\r\
    \n  constexpr static int prec = 5;\r\n  #define gc getchar\r\n  template <class\
    \ T>\r\n  inline void read(T &x){\r\n    bool neg = false;\r\n    int c = gc();\r\
    \n    while((c < '0' || c > '9') && c != '-') c = gc();\r\n    if(c == '-') neg\
    \ = true, c = gc();\r\n    x = c^'0'; c = gc();\r\n    while(c >= '0' && c <=\
    \ '9') x = x*10 + (c^'0'), c = gc();\r\n    if(neg) x = -x;\r\n  }\r\n  inline\
    \ void read(double &x){\r\n    bool neg = false;\r\n    int c = gc();\r\n    while((c\
    \ < '0' || c > '9') && c != '-') c = gc();\r\n    if(c == '-') neg = true, c =\
    \ gc();\r\n    x = c^'0'; c = gc();\r\n    while(c >= '0' && c <= '9') x = x*10\
    \ + (c^'0'), c = gc();\r\n    if(c == '.'){\r\n      c = gc();\r\n      double\
    \ dig = 1;\r\n      while(c >= '0' && c <= '9') x += (c^'0')*(dig/=10), c = gc();\r\
    \n    }\r\n    if(neg) x = -x;\r\n  }\r\n  inline void read(string &x){\r\n  \
    \  char c = gc();\r\n    while(c < '!' || '~' < c) c = gc();\r\n    while(c >=\
    \ '!' && '~' >= c) x += c, c = gc();\r\n  }\r\n  inline void read(char &x){\r\n\
    \    x = gc();\r\n    while(x < '!' || '~' < x) x = gc();\r\n  }\r\n  #undef gc\r\
    \n  #define pc putchar\r\n  inline void out(int x){\r\n    if(!x){ pc('0'); return;\
    \ }\r\n    if(x < 0){ pc('-'); x = -x; }\r\n    char *t = tmp_s;\r\n    while(x){\r\
    \n      int y = x / 10;\r\n      *(t++) = (x - y*10) + '0';\r\n      x = y;\r\n\
    \    }\r\n    while(t != tmp_s) pc(*(--t));\r\n  }\r\n  inline void out(ll x){\r\
    \n    if(!x){ pc('0'); return; }\r\n    if(x < 0){ pc('-'); x = -x; }\r\n    char\
    \ *t = tmp_s;\r\n    while(x){\r\n      ll y = x / 10;\r\n      *(t++) = (x -\
    \ y*10) + '0';\r\n      x = y;\r\n    }\r\n    while(t != tmp_s) pc(*(--t));\r\
    \n  }\r\n  inline void out(double x){\r\n    if(x == 0){ pc('0'); return; }\r\n\
    \    if(x < 0){ pc('-'); x = -x; }\r\n    out(ll(x));\r\n    x -= ll(x);\r\n \
    \   pc('.');\r\n    for(int i = 0; i < prec; i++){\r\n      x *= 10;\r\n     \
    \ pc(int(x) + '0');\r\n      x -= int(x);\r\n    }\r\n  }\r\n  inline void out(const\
    \ string &s){\r\n    for(const char &c : s) pc(c);\r\n  }\r\n  inline void out(const\
    \ char &c){ pc(c); }\r\n  #undef pc\r\n  template <class T>\r\n  friend FastIO\
    \ &operator>>(FastIO &io, T &x){\r\n    io.read(x);\r\n    return io;\r\n  }\r\
    \n  template <class T>\r\n  friend FastIO &operator<<(FastIO &io, const T &x){\r\
    \n    io.out(x);\r\n    return io;\r\n  }\r\n};\r\nFastIO io;\r\n#define cin io\r\
    \n#define cout io\n"
  code: "struct FastIO {\r\n  char tmp_s[20];\r\n  constexpr static int prec = 5;\r\
    \n  #define gc getchar\r\n  template <class T>\r\n  inline void read(T &x){\r\n\
    \    bool neg = false;\r\n    int c = gc();\r\n    while((c < '0' || c > '9')\
    \ && c != '-') c = gc();\r\n    if(c == '-') neg = true, c = gc();\r\n    x =\
    \ c^'0'; c = gc();\r\n    while(c >= '0' && c <= '9') x = x*10 + (c^'0'), c =\
    \ gc();\r\n    if(neg) x = -x;\r\n  }\r\n  inline void read(double &x){\r\n  \
    \  bool neg = false;\r\n    int c = gc();\r\n    while((c < '0' || c > '9') &&\
    \ c != '-') c = gc();\r\n    if(c == '-') neg = true, c = gc();\r\n    x = c^'0';\
    \ c = gc();\r\n    while(c >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();\r\
    \n    if(c == '.'){\r\n      c = gc();\r\n      double dig = 1;\r\n      while(c\
    \ >= '0' && c <= '9') x += (c^'0')*(dig/=10), c = gc();\r\n    }\r\n    if(neg)\
    \ x = -x;\r\n  }\r\n  inline void read(string &x){\r\n    char c = gc();\r\n \
    \   while(c < '!' || '~' < c) c = gc();\r\n    while(c >= '!' && '~' >= c) x +=\
    \ c, c = gc();\r\n  }\r\n  inline void read(char &x){\r\n    x = gc();\r\n   \
    \ while(x < '!' || '~' < x) x = gc();\r\n  }\r\n  #undef gc\r\n  #define pc putchar\r\
    \n  inline void out(int x){\r\n    if(!x){ pc('0'); return; }\r\n    if(x < 0){\
    \ pc('-'); x = -x; }\r\n    char *t = tmp_s;\r\n    while(x){\r\n      int y =\
    \ x / 10;\r\n      *(t++) = (x - y*10) + '0';\r\n      x = y;\r\n    }\r\n   \
    \ while(t != tmp_s) pc(*(--t));\r\n  }\r\n  inline void out(ll x){\r\n    if(!x){\
    \ pc('0'); return; }\r\n    if(x < 0){ pc('-'); x = -x; }\r\n    char *t = tmp_s;\r\
    \n    while(x){\r\n      ll y = x / 10;\r\n      *(t++) = (x - y*10) + '0';\r\n\
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
    \ io"
  dependsOn: []
  isVerificationFile: false
  path: others/fastIO.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Sample/Many-A+B.test.cpp
documentation_of: others/fastIO.hpp
layout: document
redirect_from:
- /library/others/fastIO.hpp
- /library/others/fastIO.hpp.html
title: others/fastIO.hpp
---
