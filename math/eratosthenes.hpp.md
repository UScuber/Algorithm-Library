---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1/ALDS1_1_C.test.cpp
    title: test/aoj/ALDS1/ALDS1_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/eratosthenes.hpp\"\nstruct range_eratosthenes {\r\n\
    \  private:\r\n  ll L,R,M;\r\n  static constexpr int Max_range = 100000010; //10^8\r\
    \n  bitset<Max_range> small, large;\r\n  public:\r\n  range_eratosthenes(const\
    \ ll L, const ll R) : L(L), R(R), M(sqrt(R)+1){\r\n    assert(M <= Max_range &&\
    \ R - L <= Max_range);\r\n    for(ll i = 2; i < M; i++){\r\n      if(small[i])\
    \ continue;\r\n      for(ll j = i+i; j < M; j += i) small[j] = 1;\r\n      for(ll\
    \ j = max(2LL, (L+i-1)/i)*i; j < R; j += i)\r\n        large[j - L] = 1;\r\n \
    \   }\r\n  }\r\n  bool is_prime(const ll n) const{\r\n    assert(L <= n && n <\
    \ R);\r\n    return !large[n - L];\r\n  }\r\n};\n"
  code: "struct range_eratosthenes {\r\n  private:\r\n  ll L,R,M;\r\n  static constexpr\
    \ int Max_range = 100000010; //10^8\r\n  bitset<Max_range> small, large;\r\n \
    \ public:\r\n  range_eratosthenes(const ll L, const ll R) : L(L), R(R), M(sqrt(R)+1){\r\
    \n    assert(M <= Max_range && R - L <= Max_range);\r\n    for(ll i = 2; i < M;\
    \ i++){\r\n      if(small[i]) continue;\r\n      for(ll j = i+i; j < M; j += i)\
    \ small[j] = 1;\r\n      for(ll j = max(2LL, (L+i-1)/i)*i; j < R; j += i)\r\n\
    \        large[j - L] = 1;\r\n    }\r\n  }\r\n  bool is_prime(const ll n) const{\r\
    \n    assert(L <= n && n < R);\r\n    return !large[n - L];\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2023-03-13 22:02:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1/ALDS1_1_C.test.cpp
documentation_of: math/eratosthenes.hpp
layout: document
redirect_from:
- /library/math/eratosthenes.hpp
- /library/math/eratosthenes.hpp.html
title: math/eratosthenes.hpp
---
