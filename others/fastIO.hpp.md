---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/Sample/Many-A+B(128bit).test.cpp
    title: test/yosupo/Sample/Many-A+B(128bit).test.cpp
  - icon: ':x:'
    path: test/yosupo/Sample/Many-A+B.test.cpp
    title: test/yosupo/Sample/Many-A+B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/fastIO.hpp\"\nnamespace FastIO {\r\nstruct PreCalc\
    \ {\r\n  char num[10000 * 4];\r\n  constexpr PreCalc() : num(){\r\n    for(int\
    \ i = 0; i < 10000; i++){\r\n      int t = i;\r\n      for(int j = 3; j >= 0;\
    \ j--){\r\n        num[i*4 + j] = (t % 10) + '0';\r\n        t /= 10;\r\n    \
    \  }\r\n    }\r\n  }\r\n};\r\nstatic constexpr PreCalc pr;\r\nstruct FastIO {\r\
    \n  template <class T>\r\n  using enable_if_integer = enable_if_t<is_integral<T>::value\
    \ || is_same<T, __int128_t>::value || is_same<T, __uint128_t>::value>;\r\n  static\
    \ constexpr int buf_size = 1 << 20;\r\n  static constexpr int rem = 1 << 6;\r\n\
    \  char in_buf[buf_size], *in_cur = in_buf + buf_size;\r\n  char out_buf[buf_size],\
    \ *out_cur = out_buf;\r\n  FastIO(){ load(); }\r\n  ~FastIO(){ flush(); }\r\n\
    \  void load(){\r\n    const int len = in_buf + buf_size - in_cur;\r\n    memmove(in_buf,\
    \ in_cur, len);\r\n    in_cur = in_buf;\r\n    fread(in_buf + len, 1, buf_size\
    \ - len, stdin);\r\n  }\r\n  void flush(){\r\n    fwrite(out_buf, 1, out_cur -\
    \ out_buf, stdout);\r\n    out_cur = out_buf;\r\n  }\r\n  void through(){\r\n\
    \    if(in_cur - in_buf >= buf_size - rem) load();\r\n    while(*in_cur <= ' ')\
    \ in_cur++;\r\n    assert(in_buf <= in_cur && in_cur < in_buf + buf_size);\r\n\
    \  }\r\n  #define gc() (*in_cur++)\r\n  template <class T, enable_if_integer<T>*\
    \ = nullptr>\r\n  inline void read(T &x){\r\n    through();\r\n    bool neg =\
    \ false;\r\n    int c = gc();\r\n    if(c == '-') neg = true, c = gc();\r\n  \
    \  x = c^'0'; c = gc();\r\n    while(c >= '0' && c <= '9') x = x*10 + (c^'0'),\
    \ c = gc();\r\n    if(neg) x = -x;\r\n  }\r\n  inline void read(string &x){\r\n\
    \    through();\r\n    x.clear();\r\n    while(true){\r\n      char *p = in_cur;\r\
    \n      while(*p > ' ' && p - in_buf < buf_size - rem) p++;\r\n      copy(in_cur,\
    \ p, back_inserter(x));\r\n      in_cur = p;\r\n      if(*p <= ' ') break;\r\n\
    \      load();\r\n    }\r\n  }\r\n  inline void read(char &x){\r\n    through();\r\
    \n    x = gc();\r\n  }\r\n  #undef gc\r\n  #define pc(c) *out_cur++ = (c)\r\n\
    \  template <class T, enable_if_integer<T>* = nullptr>\r\n  inline void out(T\
    \ x){\r\n    static constexpr int tmp_size = sizeof(T)*5/2;\r\n    static char\
    \ tmp[tmp_size];\r\n    if(out_cur - out_buf >= buf_size - rem) flush();\r\n \
    \   if(!x){ pc('0'); return; }\r\n    if(x < 0){ pc('-'); x = -x; }\r\n    int\
    \ idx = tmp_size;\r\n    while(x >= 10000){\r\n      idx -= 4;\r\n      memcpy(tmp\
    \ + idx, pr.num + (x % 10000)*4, 4);\r\n      x /= 10000;\r\n    }\r\n    if(x\
    \ < 100){\r\n      if(x < 10){\r\n        pc(x + '0');\r\n      }else{\r\n   \
    \     pc(x/10 + '0');\r\n        pc(x%10 + '0');\r\n      }\r\n    }else{\r\n\
    \      if(x < 1000){\r\n        memcpy(out_cur, pr.num + x*4 + 1, 3);\r\n    \
    \    out_cur += 3;\r\n      }else{\r\n        memcpy(out_cur, pr.num + x*4, 4);\r\
    \n        out_cur += 4;\r\n      }\r\n    }\r\n    memcpy(out_cur, tmp + idx,\
    \ tmp_size - idx);\r\n    out_cur += tmp_size - idx;\r\n  }\r\n  inline void out(const\
    \ string &s){\r\n    flush();\r\n    fwrite(s.c_str(), 1, s.size(), stdout);\r\
    \n  }\r\n  inline void out(const char c){\r\n    if(out_cur - out_buf >= buf_size\
    \ - rem) flush();\r\n    pc(c);\r\n  }\r\n  #undef pc\r\n  template <class T>\r\
    \n  friend FastIO &operator>>(FastIO &io, T &x){\r\n    io.read(x);\r\n    return\
    \ io;\r\n  }\r\n  template <class T>\r\n  friend FastIO &operator<<(FastIO &io,\
    \ const T &x){\r\n    io.out(x);\r\n    return io;\r\n  }\r\n};\r\nFastIO io;\r\
    \n} // namespace FastIO\r\nusing FastIO::io;\r\n#define cin io\r\n#define cout\
    \ io\n"
  code: "namespace FastIO {\r\nstruct PreCalc {\r\n  char num[10000 * 4];\r\n  constexpr\
    \ PreCalc() : num(){\r\n    for(int i = 0; i < 10000; i++){\r\n      int t = i;\r\
    \n      for(int j = 3; j >= 0; j--){\r\n        num[i*4 + j] = (t % 10) + '0';\r\
    \n        t /= 10;\r\n      }\r\n    }\r\n  }\r\n};\r\nstatic constexpr PreCalc\
    \ pr;\r\nstruct FastIO {\r\n  template <class T>\r\n  using enable_if_integer\
    \ = enable_if_t<is_integral<T>::value || is_same<T, __int128_t>::value || is_same<T,\
    \ __uint128_t>::value>;\r\n  static constexpr int buf_size = 1 << 20;\r\n  static\
    \ constexpr int rem = 1 << 6;\r\n  char in_buf[buf_size], *in_cur = in_buf + buf_size;\r\
    \n  char out_buf[buf_size], *out_cur = out_buf;\r\n  FastIO(){ load(); }\r\n \
    \ ~FastIO(){ flush(); }\r\n  void load(){\r\n    const int len = in_buf + buf_size\
    \ - in_cur;\r\n    memmove(in_buf, in_cur, len);\r\n    in_cur = in_buf;\r\n \
    \   fread(in_buf + len, 1, buf_size - len, stdin);\r\n  }\r\n  void flush(){\r\
    \n    fwrite(out_buf, 1, out_cur - out_buf, stdout);\r\n    out_cur = out_buf;\r\
    \n  }\r\n  void through(){\r\n    if(in_cur - in_buf >= buf_size - rem) load();\r\
    \n    while(*in_cur <= ' ') in_cur++;\r\n    assert(in_buf <= in_cur && in_cur\
    \ < in_buf + buf_size);\r\n  }\r\n  #define gc() (*in_cur++)\r\n  template <class\
    \ T, enable_if_integer<T>* = nullptr>\r\n  inline void read(T &x){\r\n    through();\r\
    \n    bool neg = false;\r\n    int c = gc();\r\n    if(c == '-') neg = true, c\
    \ = gc();\r\n    x = c^'0'; c = gc();\r\n    while(c >= '0' && c <= '9') x = x*10\
    \ + (c^'0'), c = gc();\r\n    if(neg) x = -x;\r\n  }\r\n  inline void read(string\
    \ &x){\r\n    through();\r\n    x.clear();\r\n    while(true){\r\n      char *p\
    \ = in_cur;\r\n      while(*p > ' ' && p - in_buf < buf_size - rem) p++;\r\n \
    \     copy(in_cur, p, back_inserter(x));\r\n      in_cur = p;\r\n      if(*p <=\
    \ ' ') break;\r\n      load();\r\n    }\r\n  }\r\n  inline void read(char &x){\r\
    \n    through();\r\n    x = gc();\r\n  }\r\n  #undef gc\r\n  #define pc(c) *out_cur++\
    \ = (c)\r\n  template <class T, enable_if_integer<T>* = nullptr>\r\n  inline void\
    \ out(T x){\r\n    static constexpr int tmp_size = sizeof(T)*5/2;\r\n    static\
    \ char tmp[tmp_size];\r\n    if(out_cur - out_buf >= buf_size - rem) flush();\r\
    \n    if(!x){ pc('0'); return; }\r\n    if(x < 0){ pc('-'); x = -x; }\r\n    int\
    \ idx = tmp_size;\r\n    while(x >= 10000){\r\n      idx -= 4;\r\n      memcpy(tmp\
    \ + idx, pr.num + (x % 10000)*4, 4);\r\n      x /= 10000;\r\n    }\r\n    if(x\
    \ < 100){\r\n      if(x < 10){\r\n        pc(x + '0');\r\n      }else{\r\n   \
    \     pc(x/10 + '0');\r\n        pc(x%10 + '0');\r\n      }\r\n    }else{\r\n\
    \      if(x < 1000){\r\n        memcpy(out_cur, pr.num + x*4 + 1, 3);\r\n    \
    \    out_cur += 3;\r\n      }else{\r\n        memcpy(out_cur, pr.num + x*4, 4);\r\
    \n        out_cur += 4;\r\n      }\r\n    }\r\n    memcpy(out_cur, tmp + idx,\
    \ tmp_size - idx);\r\n    out_cur += tmp_size - idx;\r\n  }\r\n  inline void out(const\
    \ string &s){\r\n    flush();\r\n    fwrite(s.c_str(), 1, s.size(), stdout);\r\
    \n  }\r\n  inline void out(const char c){\r\n    if(out_cur - out_buf >= buf_size\
    \ - rem) flush();\r\n    pc(c);\r\n  }\r\n  #undef pc\r\n  template <class T>\r\
    \n  friend FastIO &operator>>(FastIO &io, T &x){\r\n    io.read(x);\r\n    return\
    \ io;\r\n  }\r\n  template <class T>\r\n  friend FastIO &operator<<(FastIO &io,\
    \ const T &x){\r\n    io.out(x);\r\n    return io;\r\n  }\r\n};\r\nFastIO io;\r\
    \n} // namespace FastIO\r\nusing FastIO::io;\r\n#define cin io\r\n#define cout\
    \ io"
  dependsOn: []
  isVerificationFile: false
  path: others/fastIO.hpp
  requiredBy: []
  timestamp: '2023-11-12 00:39:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/Sample/Many-A+B(128bit).test.cpp
  - test/yosupo/Sample/Many-A+B.test.cpp
documentation_of: others/fastIO.hpp
layout: document
redirect_from:
- /library/others/fastIO.hpp
- /library/others/fastIO.hpp.html
title: others/fastIO.hpp
---
