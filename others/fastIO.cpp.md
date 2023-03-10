---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/fastIO.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nstruct FastIO {\n  char tmp_s[20];\n  constexpr\
    \ static int prec = 5;\n  #define gc getchar\n  template <class T>\n  inline void\
    \ read(T &x){\n    bool neg = false;\n    int c = gc();\n    while((c < '0' ||\
    \ c > '9') && c != '-') c = gc();\n    if(c == '-') neg = true, c = gc();\n  \
    \  x = c^'0'; c = gc();\n    while(c >= '0' && c <= '9') x = x*10 + (c^'0'), c\
    \ = gc();\n    if(neg) x = -x;\n  }\n  inline void read(double &x){\n    bool\
    \ neg = false;\n    int c = gc();\n    while((c < '0' || c > '9') && c != '-')\
    \ c = gc();\n    if(c == '-') neg = true, c = gc();\n    x = c^'0'; c = gc();\n\
    \    while(c >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();\n    if(c == '.'){\n\
    \      c = gc();\n      double dig = 1;\n      while(c >= '0' && c <= '9') x +=\
    \ (c^'0')*(dig/=10), c = gc();\n    }\n    if(neg) x = -x;\n  }\n  inline void\
    \ read(string &x){\n    char c = gc();\n    while(c < '!' || '~' < c) c = gc();\n\
    \    while(c >= '!' && '~' >= c) x += c, c = gc();\n  }\n  inline void read(char\
    \ &x){\n    x = gc();\n    while(x < '!' || '~' < x) x = gc();\n  }\n  #undef\
    \ gc\n  #define pc putchar\n  inline void out(int x){\n    if(!x){ pc('0'); return;\
    \ }\n    if(x < 0){ pc('-'); x = -x; }\n    char *t = tmp_s;\n    while(x){\n\
    \      int y = x / 10;\n      *(t++) = (x - y*10) + '0';\n      x = y;\n    }\n\
    \    while(t != tmp_s) pc(*(--t));\n  }\n  inline void out(ll x){\n    if(!x){\
    \ pc('0'); return; }\n    if(x < 0){ pc('-'); x = -x; }\n    char *t = tmp_s;\n\
    \    while(x){\n      ll y = x / 10;\n      *(t++) = (x - y*10) + '0';\n     \
    \ x = y;\n    }\n    while(t != tmp_s) pc(*(--t));\n  }\n  inline void out(double\
    \ x){\n    if(x == 0){ pc('0'); return; }\n    if(x < 0){ pc('-'); x = -x; }\n\
    \    out(ll(x));\n    x -= ll(x);\n    pc('.');\n    for(int i = 0; i < prec;\
    \ i++){\n      x *= 10;\n      pc(int(x) + '0');\n      x -= int(x);\n    }\n\
    \  }\n  inline void out(const string &s){\n    for(const char &c : s) pc(c);\n\
    \  }\n  inline void out(const char &c){ pc(c); }\n  #undef pc\n  template <class\
    \ T>\n  friend FastIO &operator>>(FastIO &io, T &x){\n    io.read(x);\n    return\
    \ io;\n  }\n  template <class T>\n  friend FastIO &operator<<(FastIO &io, const\
    \ T &x){\n    io.out(x);\n    return io;\n  }\n};\nFastIO io;\n#define cin io\n\
    #define cout io\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    struct FastIO {\n  char tmp_s[20];\n  constexpr static int prec = 5;\n  #define\
    \ gc getchar\n  template <class T>\n  inline void read(T &x){\n    bool neg =\
    \ false;\n    int c = gc();\n    while((c < '0' || c > '9') && c != '-') c = gc();\n\
    \    if(c == '-') neg = true, c = gc();\n    x = c^'0'; c = gc();\n    while(c\
    \ >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();\n    if(neg) x = -x;\n  }\n\
    \  inline void read(double &x){\n    bool neg = false;\n    int c = gc();\n  \
    \  while((c < '0' || c > '9') && c != '-') c = gc();\n    if(c == '-') neg = true,\
    \ c = gc();\n    x = c^'0'; c = gc();\n    while(c >= '0' && c <= '9') x = x*10\
    \ + (c^'0'), c = gc();\n    if(c == '.'){\n      c = gc();\n      double dig =\
    \ 1;\n      while(c >= '0' && c <= '9') x += (c^'0')*(dig/=10), c = gc();\n  \
    \  }\n    if(neg) x = -x;\n  }\n  inline void read(string &x){\n    char c = gc();\n\
    \    while(c < '!' || '~' < c) c = gc();\n    while(c >= '!' && '~' >= c) x +=\
    \ c, c = gc();\n  }\n  inline void read(char &x){\n    x = gc();\n    while(x\
    \ < '!' || '~' < x) x = gc();\n  }\n  #undef gc\n  #define pc putchar\n  inline\
    \ void out(int x){\n    if(!x){ pc('0'); return; }\n    if(x < 0){ pc('-'); x\
    \ = -x; }\n    char *t = tmp_s;\n    while(x){\n      int y = x / 10;\n      *(t++)\
    \ = (x - y*10) + '0';\n      x = y;\n    }\n    while(t != tmp_s) pc(*(--t));\n\
    \  }\n  inline void out(ll x){\n    if(!x){ pc('0'); return; }\n    if(x < 0){\
    \ pc('-'); x = -x; }\n    char *t = tmp_s;\n    while(x){\n      ll y = x / 10;\n\
    \      *(t++) = (x - y*10) + '0';\n      x = y;\n    }\n    while(t != tmp_s)\
    \ pc(*(--t));\n  }\n  inline void out(double x){\n    if(x == 0){ pc('0'); return;\
    \ }\n    if(x < 0){ pc('-'); x = -x; }\n    out(ll(x));\n    x -= ll(x);\n   \
    \ pc('.');\n    for(int i = 0; i < prec; i++){\n      x *= 10;\n      pc(int(x)\
    \ + '0');\n      x -= int(x);\n    }\n  }\n  inline void out(const string &s){\n\
    \    for(const char &c : s) pc(c);\n  }\n  inline void out(const char &c){ pc(c);\
    \ }\n  #undef pc\n  template <class T>\n  friend FastIO &operator>>(FastIO &io,\
    \ T &x){\n    io.read(x);\n    return io;\n  }\n  template <class T>\n  friend\
    \ FastIO &operator<<(FastIO &io, const T &x){\n    io.out(x);\n    return io;\n\
    \  }\n};\nFastIO io;\n#define cin io\n#define cout io"
  dependsOn: []
  isVerificationFile: false
  path: others/fastIO.cpp
  requiredBy: []
  timestamp: '2022-02-11 19:16:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/fastIO.cpp
layout: document
redirect_from:
- /library/others/fastIO.cpp
- /library/others/fastIO.cpp.html
title: others/fastIO.cpp
---
