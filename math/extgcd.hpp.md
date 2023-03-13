---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL/NTL_1_E.test.cpp
    title: test/aoj/NTL/NTL_1_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/extgcd.hpp\"\nll ext_gcd(ll a, ll b, ll &x, ll &y){\n\
    \  ll d = a;\n  if(b){\n    d = ext_gcd(b, a % b, y, x);\n    y -= (a / b) * x;\n\
    \  }else{ x = 1; y = 0; }\n  return d;\n}\n"
  code: "ll ext_gcd(ll a, ll b, ll &x, ll &y){\n  ll d = a;\n  if(b){\n    d = ext_gcd(b,\
    \ a % b, y, x);\n    y -= (a / b) * x;\n  }else{ x = 1; y = 0; }\n  return d;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/extgcd.hpp
  requiredBy: []
  timestamp: '2023-03-13 22:17:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL/NTL_1_E.test.cpp
documentation_of: math/extgcd.hpp
layout: document
redirect_from:
- /library/math/extgcd.hpp
- /library/math/extgcd.hpp.html
title: math/extgcd.hpp
---
