---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling-hash.hpp\"\n#include <chrono>\r\n#include\
    \ <random>\r\nusing ull = unsigned long long;\r\n\r\ntemplate <class T, int max_len>\r\
    \nstruct Hash {\r\n  static constexpr ull m = (1ULL << 61) - 1;\r\n  const ull\
    \ base;\r\n  vector<ull> h;\r\n  const T data;\r\n  Hash(const T &d, const ull\
    \ base, const ull power[]) : data(d), base(base), power(power){}\r\n  inline ull\
    \ query(int l, int r) const{\r\n    assert(max_len >= r - l);\r\n    assert(0\
    \ <= l && l <= r && r <= h.size());\r\n    return add(h[r], m - mul(h[l], power[r\
    \ - l]));\r\n  }\r\n  void combine(const Hash<T, max_len> &a){\r\n    const int\
    \ len = h.size();\r\n    h.insert(h.end(), a.h.begin()+1, a.h.end());\r\n    const\
    \ int tot_len = h.size();\r\n    ull val = h[len - 1];\r\n    for(int i = len;\
    \ i < tot_len; i++){\r\n      val = mul(val, base);\r\n      h[i] = add(val, h[i]);\r\
    \n    }\r\n  }\r\n  inline int size() const noexcept{ return (int)h.size()-1;\
    \ }\r\n  private:\r\n  const ull *power;\r\n  inline ull add(ull a, const ull\
    \ b) const noexcept{\r\n    if((a += b) >= m) a -= m;\r\n    return a;\r\n  }\r\
    \n  inline ull mul(const ull a, const ull b) const noexcept{\r\n    const __uint128_t\
    \ c = (__uint128_t)a * b;\r\n    return add(c >> 61, c & m);\r\n  }\r\n  inline\
    \ ull fma(const ull a, const ull b, const ull c) const noexcept{\r\n    const\
    \ __uint128_t d = (__uint128_t)a * b + c;\r\n    return add(d >> 61, d & m);\r\
    \n  }\r\n};\r\ntemplate <int max_len>\r\nstruct RollingHash {\r\n  static constexpr\
    \ ull m = (1ULL << 61) - 1;\r\n  const ull base;\r\n  RollingHash() : base(rnd()){\r\
    \n    power[0] = 1;\r\n    for(int i = 0; i < max_len; i++){\r\n      power[i\
    \ + 1] = mul(power[i], base);\r\n    }\r\n  }\r\n  Hash<string, max_len> gen(const\
    \ string &s) const{\r\n    const int len = s.size();\r\n    Hash<string, max_len>\
    \ hash(s, base, power);\r\n    hash.h.resize(len + 1);\r\n    for(int i = 0; i\
    \ < len; i++){\r\n      hash.h[i+1] = fma(hash.h[i], base, s[i]);\r\n    }\r\n\
    \    return hash;\r\n  }\r\n  template <class T>\r\n  Hash<vector<T>, max_len>\
    \ gen(const vector<T> &s) const{\r\n    const int len = s.size();\r\n    Hash<vector<T>,\
    \ max_len> hash(s, base, power);\r\n    hash.h.resize(len + 1);\r\n    for(int\
    \ i = 0; i < len; i++){\r\n      hash.h[i+1] = fma(hash.h[i], base, s[i]);\r\n\
    \    }\r\n    return hash;\r\n  }\r\n  ull combine(const ull h1, const ull h2,\
    \ const ull h2_len) const{\r\n    assert(max_len >= h2_len);\r\n    return fma(h1,\
    \ power[h2_len], h2);\r\n  }\r\n  template <class T>\r\n  ull combine(const Hash<T,max_len>\
    \ &a, const int l1, const int r1,\r\n              const Hash<T,max_len> &b, const\
    \ int l2, const int r2) const{\r\n    assert(max_len >= r2 - l2);\r\n    return\
    \ fma(a.query(l1, r1), power[r2-l2], b.query(l2, r2));\r\n  }\r\n  template <class\
    \ T>\r\n  int lcp(const Hash<T,max_len> &a, const int l1, const int r1,\r\n  \
    \        const Hash<T,max_len> &b, const int l2, const int r2) const{\r\n    assert(0\
    \ <= l1 && l1 <= r1 && r1 <= a.size());\r\n    assert(0 <= l2 && l2 <= r2 && r2\
    \ <= b.size());\r\n    const int len = min(r1-l1, r2-l2);\r\n    int left = 0,\
    \ right = len + 1;\r\n    while(left + 1 < right){\r\n      const int mid = (left\
    \ + right) / 2;\r\n      if(a.query(l1, l1+mid) == b.query(l2, l2+mid)) left =\
    \ mid;\r\n      else right = mid;\r\n    }\r\n    return left;\r\n  }\r\n  template\
    \ <class T>\r\n  int strcmp(const Hash<T,max_len> &a, const int l1, const int\
    \ r1\r\n            ,const Hash<T,max_len> &b, const int l2, const int r2) const{\r\
    \n    assert(0 <= l1 && l1 <= r1 && r1 <= a.size());\r\n    assert(0 <= l2 &&\
    \ l2 <= r2 && r2 <= b.size());\r\n    const int pos = lcp(a, l1, r1, b, l2, r2);\r\
    \n    if(pos < min(r1-l1, r2-l2)) return a.data[l1+pos] < b.data[l2+pos] ? 1 :\
    \ -1;\r\n    if(r1-l1 == r2-l2) return 0;\r\n    return r1-l1 < r2-l2 ? 1 : -1;\r\
    \n  }\r\n  private:\r\n  ull power[max_len + 1];\r\n  ull rnd() const{\r\n   \
    \ mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\r\n \
    \   uniform_int_distribution<ull> rand(2, m-1);\r\n    return rand(mt);\r\n  }\r\
    \n  inline ull add(ull a, const ull b) const noexcept{\r\n    if((a += b) >= m)\
    \ a -= m;\r\n    return a;\r\n  }\r\n  inline ull mul(const ull a, const ull b)\
    \ const noexcept{\r\n    const __uint128_t c = (__uint128_t)a * b;\r\n    return\
    \ add(c >> 61, c & m);\r\n  }\r\n  inline ull fma(const ull a, const ull b, const\
    \ ull c) const noexcept{\r\n    const __uint128_t d = (__uint128_t)a * b + c;\r\
    \n    return add(d >> 61, d & m);\r\n  }\r\n};\n"
  code: "#include <chrono>\r\n#include <random>\r\nusing ull = unsigned long long;\r\
    \n\r\ntemplate <class T, int max_len>\r\nstruct Hash {\r\n  static constexpr ull\
    \ m = (1ULL << 61) - 1;\r\n  const ull base;\r\n  vector<ull> h;\r\n  const T\
    \ data;\r\n  Hash(const T &d, const ull base, const ull power[]) : data(d), base(base),\
    \ power(power){}\r\n  inline ull query(int l, int r) const{\r\n    assert(max_len\
    \ >= r - l);\r\n    assert(0 <= l && l <= r && r <= h.size());\r\n    return add(h[r],\
    \ m - mul(h[l], power[r - l]));\r\n  }\r\n  void combine(const Hash<T, max_len>\
    \ &a){\r\n    const int len = h.size();\r\n    h.insert(h.end(), a.h.begin()+1,\
    \ a.h.end());\r\n    const int tot_len = h.size();\r\n    ull val = h[len - 1];\r\
    \n    for(int i = len; i < tot_len; i++){\r\n      val = mul(val, base);\r\n \
    \     h[i] = add(val, h[i]);\r\n    }\r\n  }\r\n  inline int size() const noexcept{\
    \ return (int)h.size()-1; }\r\n  private:\r\n  const ull *power;\r\n  inline ull\
    \ add(ull a, const ull b) const noexcept{\r\n    if((a += b) >= m) a -= m;\r\n\
    \    return a;\r\n  }\r\n  inline ull mul(const ull a, const ull b) const noexcept{\r\
    \n    const __uint128_t c = (__uint128_t)a * b;\r\n    return add(c >> 61, c &\
    \ m);\r\n  }\r\n  inline ull fma(const ull a, const ull b, const ull c) const\
    \ noexcept{\r\n    const __uint128_t d = (__uint128_t)a * b + c;\r\n    return\
    \ add(d >> 61, d & m);\r\n  }\r\n};\r\ntemplate <int max_len>\r\nstruct RollingHash\
    \ {\r\n  static constexpr ull m = (1ULL << 61) - 1;\r\n  const ull base;\r\n \
    \ RollingHash() : base(rnd()){\r\n    power[0] = 1;\r\n    for(int i = 0; i <\
    \ max_len; i++){\r\n      power[i + 1] = mul(power[i], base);\r\n    }\r\n  }\r\
    \n  Hash<string, max_len> gen(const string &s) const{\r\n    const int len = s.size();\r\
    \n    Hash<string, max_len> hash(s, base, power);\r\n    hash.h.resize(len + 1);\r\
    \n    for(int i = 0; i < len; i++){\r\n      hash.h[i+1] = fma(hash.h[i], base,\
    \ s[i]);\r\n    }\r\n    return hash;\r\n  }\r\n  template <class T>\r\n  Hash<vector<T>,\
    \ max_len> gen(const vector<T> &s) const{\r\n    const int len = s.size();\r\n\
    \    Hash<vector<T>, max_len> hash(s, base, power);\r\n    hash.h.resize(len +\
    \ 1);\r\n    for(int i = 0; i < len; i++){\r\n      hash.h[i+1] = fma(hash.h[i],\
    \ base, s[i]);\r\n    }\r\n    return hash;\r\n  }\r\n  ull combine(const ull\
    \ h1, const ull h2, const ull h2_len) const{\r\n    assert(max_len >= h2_len);\r\
    \n    return fma(h1, power[h2_len], h2);\r\n  }\r\n  template <class T>\r\n  ull\
    \ combine(const Hash<T,max_len> &a, const int l1, const int r1,\r\n          \
    \    const Hash<T,max_len> &b, const int l2, const int r2) const{\r\n    assert(max_len\
    \ >= r2 - l2);\r\n    return fma(a.query(l1, r1), power[r2-l2], b.query(l2, r2));\r\
    \n  }\r\n  template <class T>\r\n  int lcp(const Hash<T,max_len> &a, const int\
    \ l1, const int r1,\r\n          const Hash<T,max_len> &b, const int l2, const\
    \ int r2) const{\r\n    assert(0 <= l1 && l1 <= r1 && r1 <= a.size());\r\n   \
    \ assert(0 <= l2 && l2 <= r2 && r2 <= b.size());\r\n    const int len = min(r1-l1,\
    \ r2-l2);\r\n    int left = 0, right = len + 1;\r\n    while(left + 1 < right){\r\
    \n      const int mid = (left + right) / 2;\r\n      if(a.query(l1, l1+mid) ==\
    \ b.query(l2, l2+mid)) left = mid;\r\n      else right = mid;\r\n    }\r\n   \
    \ return left;\r\n  }\r\n  template <class T>\r\n  int strcmp(const Hash<T,max_len>\
    \ &a, const int l1, const int r1\r\n            ,const Hash<T,max_len> &b, const\
    \ int l2, const int r2) const{\r\n    assert(0 <= l1 && l1 <= r1 && r1 <= a.size());\r\
    \n    assert(0 <= l2 && l2 <= r2 && r2 <= b.size());\r\n    const int pos = lcp(a,\
    \ l1, r1, b, l2, r2);\r\n    if(pos < min(r1-l1, r2-l2)) return a.data[l1+pos]\
    \ < b.data[l2+pos] ? 1 : -1;\r\n    if(r1-l1 == r2-l2) return 0;\r\n    return\
    \ r1-l1 < r2-l2 ? 1 : -1;\r\n  }\r\n  private:\r\n  ull power[max_len + 1];\r\n\
    \  ull rnd() const{\r\n    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n    uniform_int_distribution<ull> rand(2, m-1);\r\n    return rand(mt);\r\n\
    \  }\r\n  inline ull add(ull a, const ull b) const noexcept{\r\n    if((a += b)\
    \ >= m) a -= m;\r\n    return a;\r\n  }\r\n  inline ull mul(const ull a, const\
    \ ull b) const noexcept{\r\n    const __uint128_t c = (__uint128_t)a * b;\r\n\
    \    return add(c >> 61, c & m);\r\n  }\r\n  inline ull fma(const ull a, const\
    \ ull b, const ull c) const noexcept{\r\n    const __uint128_t d = (__uint128_t)a\
    \ * b + c;\r\n    return add(d >> 61, d & m);\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling-hash.hpp
layout: document
redirect_from:
- /library/string/rolling-hash.hpp
- /library/string/rolling-hash.hpp.html
title: string/rolling-hash.hpp
---
