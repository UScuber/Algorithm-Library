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
  bundledCode: "#line 1 \"string/rolling-hash.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n\n#line 7 \"string/rolling-hash.cpp\"\
    \nusing ull = unsigned long long;\ntemplate <class T, int max_len>\nstruct Hash\
    \ {\n  static constexpr ull m = (1ULL << 61) - 1;\n  const ull base;\n  vector<ull>\
    \ h;\n  const T data;\n  Hash(const T &d, const ull base, const ull power[]) :\
    \ data(d), base(base), power(power){}\n  inline ull query(int l, int r) const{\n\
    \    assert(max_len >= r - l);\n    assert(0 <= l && l <= r && r <= h.size());\n\
    \    return add(h[r], m - mul(h[l], power[r - l]));\n  }\n  void combine(const\
    \ Hash<T, max_len> &a){\n    const int len = h.size();\n    h.insert(h.end(),\
    \ a.h.begin()+1, a.h.end());\n    const int tot_len = h.size();\n    ull val =\
    \ h[len - 1];\n    for(int i = len; i < tot_len; i++){\n      val = mul(val, base);\n\
    \      h[i] = add(val, h[i]);\n    }\n  }\n  inline int size() const noexcept{\
    \ return (int)h.size()-1; }\n  private:\n  const ull *power;\n  inline ull add(ull\
    \ a, const ull b) const noexcept{\n    if((a += b) >= m) a -= m;\n    return a;\n\
    \  }\n  inline ull mul(const ull a, const ull b) const noexcept{\n    const __uint128_t\
    \ c = (__uint128_t)a * b;\n    return add(c >> 61, c & m);\n  }\n  inline ull\
    \ fma(const ull a, const ull b, const ull c) const noexcept{\n    const __uint128_t\
    \ d = (__uint128_t)a * b + c;\n    return add(d >> 61, d & m);\n  }\n};\ntemplate\
    \ <int max_len>\nstruct RollingHash {\n  static constexpr ull m = (1ULL << 61)\
    \ - 1;\n  const ull base;\n  RollingHash() : base(rnd()){\n    power[0] = 1;\n\
    \    for(int i = 0; i < max_len; i++){\n      power[i + 1] = mul(power[i], base);\n\
    \    }\n  }\n  Hash<string, max_len> gen(const string &s) const{\n    const int\
    \ len = s.size();\n    Hash<string, max_len> hash(s, base, power);\n    hash.h.resize(len\
    \ + 1);\n    for(int i = 0; i < len; i++){\n      hash.h[i+1] = fma(hash.h[i],\
    \ base, s[i]);\n    }\n    return hash;\n  }\n  template <class T>\n  Hash<vector<T>,\
    \ max_len> gen(const vector<T> &s) const{\n    const int len = s.size();\n   \
    \ Hash<vector<T>, max_len> hash(s, base, power);\n    hash.h.resize(len + 1);\n\
    \    for(int i = 0; i < len; i++){\n      hash.h[i+1] = fma(hash.h[i], base, s[i]);\n\
    \    }\n    return hash;\n  }\n  ull combine(const ull h1, const ull h2, const\
    \ ull h2_len) const{\n    assert(max_len >= h2_len);\n    return fma(h1, power[h2_len],\
    \ h2);\n  }\n  template <class T>\n  ull combine(const Hash<T,max_len> &a, const\
    \ int l1, const int r1,\n              const Hash<T,max_len> &b, const int l2,\
    \ const int r2) const{\n    assert(max_len >= r2 - l2);\n    return fma(a.query(l1,\
    \ r1), power[r2-l2], b.query(l2, r2));\n  }\n  template <class T>\n  int lcp(const\
    \ Hash<T,max_len> &a, const int l1, const int r1,\n          const Hash<T,max_len>\
    \ &b, const int l2, const int r2) const{\n    assert(0 <= l1 && l1 <= r1 && r1\
    \ <= a.size());\n    assert(0 <= l2 && l2 <= r2 && r2 <= b.size());\n    const\
    \ int len = min(r1-l1, r2-l2);\n    int left = 0, right = len + 1;\n    while(left\
    \ + 1 < right){\n      const int mid = (left + right) / 2;\n      if(a.query(l1,\
    \ l1+mid) == b.query(l2, l2+mid)) left = mid;\n      else right = mid;\n    }\n\
    \    return left;\n  }\n  template <class T>\n  int strcmp(const Hash<T,max_len>\
    \ &a, const int l1, const int r1\n            ,const Hash<T,max_len> &b, const\
    \ int l2, const int r2) const{\n    assert(0 <= l1 && l1 <= r1 && r1 <= a.size());\n\
    \    assert(0 <= l2 && l2 <= r2 && r2 <= b.size());\n    const int pos = lcp(a,\
    \ l1, r1, b, l2, r2);\n    if(pos < min(r1-l1, r2-l2)) return a.data[l1+pos] <\
    \ b.data[l2+pos] ? 1 : -1;\n    if(r1-l1 == r2-l2) return 0;\n    return r1-l1\
    \ < r2-l2 ? 1 : -1;\n  }\n  private:\n  ull power[max_len + 1];\n  ull rnd() const{\n\
    \    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    uniform_int_distribution<ull> rand(2, m-1);\n    return rand(mt);\n  }\n\
    \  inline ull add(ull a, const ull b) const noexcept{\n    if((a += b) >= m) a\
    \ -= m;\n    return a;\n  }\n  inline ull mul(const ull a, const ull b) const\
    \ noexcept{\n    const __uint128_t c = (__uint128_t)a * b;\n    return add(c >>\
    \ 61, c & m);\n  }\n  inline ull fma(const ull a, const ull b, const ull c) const\
    \ noexcept{\n    const __uint128_t d = (__uint128_t)a * b + c;\n    return add(d\
    \ >> 61, d & m);\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    #include <chrono>\n#include <random>\nusing ull = unsigned long long;\ntemplate\
    \ <class T, int max_len>\nstruct Hash {\n  static constexpr ull m = (1ULL << 61)\
    \ - 1;\n  const ull base;\n  vector<ull> h;\n  const T data;\n  Hash(const T &d,\
    \ const ull base, const ull power[]) : data(d), base(base), power(power){}\n \
    \ inline ull query(int l, int r) const{\n    assert(max_len >= r - l);\n    assert(0\
    \ <= l && l <= r && r <= h.size());\n    return add(h[r], m - mul(h[l], power[r\
    \ - l]));\n  }\n  void combine(const Hash<T, max_len> &a){\n    const int len\
    \ = h.size();\n    h.insert(h.end(), a.h.begin()+1, a.h.end());\n    const int\
    \ tot_len = h.size();\n    ull val = h[len - 1];\n    for(int i = len; i < tot_len;\
    \ i++){\n      val = mul(val, base);\n      h[i] = add(val, h[i]);\n    }\n  }\n\
    \  inline int size() const noexcept{ return (int)h.size()-1; }\n  private:\n \
    \ const ull *power;\n  inline ull add(ull a, const ull b) const noexcept{\n  \
    \  if((a += b) >= m) a -= m;\n    return a;\n  }\n  inline ull mul(const ull a,\
    \ const ull b) const noexcept{\n    const __uint128_t c = (__uint128_t)a * b;\n\
    \    return add(c >> 61, c & m);\n  }\n  inline ull fma(const ull a, const ull\
    \ b, const ull c) const noexcept{\n    const __uint128_t d = (__uint128_t)a *\
    \ b + c;\n    return add(d >> 61, d & m);\n  }\n};\ntemplate <int max_len>\nstruct\
    \ RollingHash {\n  static constexpr ull m = (1ULL << 61) - 1;\n  const ull base;\n\
    \  RollingHash() : base(rnd()){\n    power[0] = 1;\n    for(int i = 0; i < max_len;\
    \ i++){\n      power[i + 1] = mul(power[i], base);\n    }\n  }\n  Hash<string,\
    \ max_len> gen(const string &s) const{\n    const int len = s.size();\n    Hash<string,\
    \ max_len> hash(s, base, power);\n    hash.h.resize(len + 1);\n    for(int i =\
    \ 0; i < len; i++){\n      hash.h[i+1] = fma(hash.h[i], base, s[i]);\n    }\n\
    \    return hash;\n  }\n  template <class T>\n  Hash<vector<T>, max_len> gen(const\
    \ vector<T> &s) const{\n    const int len = s.size();\n    Hash<vector<T>, max_len>\
    \ hash(s, base, power);\n    hash.h.resize(len + 1);\n    for(int i = 0; i < len;\
    \ i++){\n      hash.h[i+1] = fma(hash.h[i], base, s[i]);\n    }\n    return hash;\n\
    \  }\n  ull combine(const ull h1, const ull h2, const ull h2_len) const{\n   \
    \ assert(max_len >= h2_len);\n    return fma(h1, power[h2_len], h2);\n  }\n  template\
    \ <class T>\n  ull combine(const Hash<T,max_len> &a, const int l1, const int r1,\n\
    \              const Hash<T,max_len> &b, const int l2, const int r2) const{\n\
    \    assert(max_len >= r2 - l2);\n    return fma(a.query(l1, r1), power[r2-l2],\
    \ b.query(l2, r2));\n  }\n  template <class T>\n  int lcp(const Hash<T,max_len>\
    \ &a, const int l1, const int r1,\n          const Hash<T,max_len> &b, const int\
    \ l2, const int r2) const{\n    assert(0 <= l1 && l1 <= r1 && r1 <= a.size());\n\
    \    assert(0 <= l2 && l2 <= r2 && r2 <= b.size());\n    const int len = min(r1-l1,\
    \ r2-l2);\n    int left = 0, right = len + 1;\n    while(left + 1 < right){\n\
    \      const int mid = (left + right) / 2;\n      if(a.query(l1, l1+mid) == b.query(l2,\
    \ l2+mid)) left = mid;\n      else right = mid;\n    }\n    return left;\n  }\n\
    \  template <class T>\n  int strcmp(const Hash<T,max_len> &a, const int l1, const\
    \ int r1\n            ,const Hash<T,max_len> &b, const int l2, const int r2) const{\n\
    \    assert(0 <= l1 && l1 <= r1 && r1 <= a.size());\n    assert(0 <= l2 && l2\
    \ <= r2 && r2 <= b.size());\n    const int pos = lcp(a, l1, r1, b, l2, r2);\n\
    \    if(pos < min(r1-l1, r2-l2)) return a.data[l1+pos] < b.data[l2+pos] ? 1 :\
    \ -1;\n    if(r1-l1 == r2-l2) return 0;\n    return r1-l1 < r2-l2 ? 1 : -1;\n\
    \  }\n  private:\n  ull power[max_len + 1];\n  ull rnd() const{\n    mt19937_64\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n    uniform_int_distribution<ull>\
    \ rand(2, m-1);\n    return rand(mt);\n  }\n  inline ull add(ull a, const ull\
    \ b) const noexcept{\n    if((a += b) >= m) a -= m;\n    return a;\n  }\n  inline\
    \ ull mul(const ull a, const ull b) const noexcept{\n    const __uint128_t c =\
    \ (__uint128_t)a * b;\n    return add(c >> 61, c & m);\n  }\n  inline ull fma(const\
    \ ull a, const ull b, const ull c) const noexcept{\n    const __uint128_t d =\
    \ (__uint128_t)a * b + c;\n    return add(d >> 61, d & m);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.cpp
  requiredBy: []
  timestamp: '2023-01-09 23:36:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling-hash.cpp
layout: document
redirect_from:
- /library/string/rolling-hash.cpp
- /library/string/rolling-hash.cpp.html
title: string/rolling-hash.cpp
---
