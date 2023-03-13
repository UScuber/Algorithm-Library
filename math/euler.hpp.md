---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL/NTL_1_D.test.cpp
    title: test/aoj/NTL/NTL_1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/euler.hpp\"\nll euler(ll n){\n  ll res = n, k = n;\n\
    \  for(ll i = 2; i*i <= k; i++){\n    if(n % i) continue;\n    res = res / i *\
    \ (i - 1);\n    while(n % i == 0) n /= i;\n  }\n  if(n != 1) res = res / n * (n\
    \ - 1);\n  return res;\n}\n"
  code: "ll euler(ll n){\n  ll res = n, k = n;\n  for(ll i = 2; i*i <= k; i++){\n\
    \    if(n % i) continue;\n    res = res / i * (i - 1);\n    while(n % i == 0)\
    \ n /= i;\n  }\n  if(n != 1) res = res / n * (n - 1);\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/euler.hpp
  requiredBy: []
  timestamp: '2023-03-13 22:17:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL/NTL_1_D.test.cpp
documentation_of: math/euler.hpp
layout: document
redirect_from:
- /library/math/euler.hpp
- /library/math/euler.hpp.html
title: math/euler.hpp
---
