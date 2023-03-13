---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL/NTL_1_B.test.cpp
    title: test/aoj/NTL/NTL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modpow.hpp\"\nll modPow(ll a, ll n, ll p){\n  a %=\
    \ p;\n  ll res = 1;\n  while(n){\n    if(n & 1) (res *= a) %= p;\n    (a *= a)\
    \ %= p;\n    n >>= 1;\n  }\n  return res;\n}\n"
  code: "ll modPow(ll a, ll n, ll p){\n  a %= p;\n  ll res = 1;\n  while(n){\n   \
    \ if(n & 1) (res *= a) %= p;\n    (a *= a) %= p;\n    n >>= 1;\n  }\n  return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/modpow.hpp
  requiredBy: []
  timestamp: '2023-03-13 22:17:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL/NTL_1_B.test.cpp
documentation_of: math/modpow.hpp
layout: document
redirect_from:
- /library/math/modpow.hpp
- /library/math/modpow.hpp.html
title: math/modpow.hpp
---
