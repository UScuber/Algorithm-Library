---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL/NTL_1_C.test.cpp
    title: test/aoj/NTL/NTL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/gcdlcm.hpp\"\ntemplate<class T>\nT gcd(T a, T b){\n\
    \  if(!b) return a;\n  return gcd(b, a % b);\n}\n\ntemplate<class T>\nT lcm(T\
    \ a, T b){\n  return a / gcd(a, b) * b;\n}\n"
  code: "template<class T>\nT gcd(T a, T b){\n  if(!b) return a;\n  return gcd(b,\
    \ a % b);\n}\n\ntemplate<class T>\nT lcm(T a, T b){\n  return a / gcd(a, b) *\
    \ b;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/gcdlcm.hpp
  requiredBy: []
  timestamp: '2023-03-13 22:17:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL/NTL_1_C.test.cpp
documentation_of: math/gcdlcm.hpp
layout: document
redirect_from:
- /library/math/gcdlcm.hpp
- /library/math/gcdlcm.hpp.html
title: math/gcdlcm.hpp
---
