---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Sum-of-Floor-of-Linear.test.cpp
    title: test/yosupo/Sum-of-Floor-of-Linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/floor-sum.hpp\"\nusing ull = unsigned long long;\r\n\
    \r\null floor_sum_unsigned(ull n, ull m, ull a, ull b){\r\n  ull ans = 0;\r\n\
    \  while(true){\r\n    if(a >= m){\r\n      ans += n * (n - 1) / 2 * (a / m);\r\
    \n      a %= m;\r\n    }\r\n    if(b >= m){\r\n      ans += n * (b / m);\r\n \
    \     b %= m;\r\n    }\r\n    const ull y_max = a * n + b;\r\n    if(y_max < m)\
    \ break;\r\n    n = y_max / m;\r\n    b = y_max % m;\r\n    swap(m, a);\r\n  }\r\
    \n  return ans;\r\n}\r\nll floor_sum(const ll n, const ll m, ll a, ll b){\r\n\
    \  assert(0 <= n && n < (1LL << 32));\r\n  assert(1 <= m && m < (1LL << 32));\r\
    \n  ull ans = 0;\r\n  if(a < 0){\r\n    const ull a2 = (a % m + m) % m;\r\n  \
    \  ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);\r\n    a = a2;\r\n  }\r\n \
    \ if(b < 0){\r\n    const ull b2 = (b % m + m) % m;\r\n    ans -= 1ULL * n * ((b2\
    \ - b) / m);\r\n    b = b2;\r\n  }\r\n  return ans + floor_sum_unsigned(n, m,\
    \ a, b);\r\n}\n"
  code: "using ull = unsigned long long;\r\n\r\null floor_sum_unsigned(ull n, ull\
    \ m, ull a, ull b){\r\n  ull ans = 0;\r\n  while(true){\r\n    if(a >= m){\r\n\
    \      ans += n * (n - 1) / 2 * (a / m);\r\n      a %= m;\r\n    }\r\n    if(b\
    \ >= m){\r\n      ans += n * (b / m);\r\n      b %= m;\r\n    }\r\n    const ull\
    \ y_max = a * n + b;\r\n    if(y_max < m) break;\r\n    n = y_max / m;\r\n   \
    \ b = y_max % m;\r\n    swap(m, a);\r\n  }\r\n  return ans;\r\n}\r\nll floor_sum(const\
    \ ll n, const ll m, ll a, ll b){\r\n  assert(0 <= n && n < (1LL << 32));\r\n \
    \ assert(1 <= m && m < (1LL << 32));\r\n  ull ans = 0;\r\n  if(a < 0){\r\n   \
    \ const ull a2 = (a % m + m) % m;\r\n    ans -= 1ULL * n * (n - 1) / 2 * ((a2\
    \ - a) / m);\r\n    a = a2;\r\n  }\r\n  if(b < 0){\r\n    const ull b2 = (b %\
    \ m + m) % m;\r\n    ans -= 1ULL * n * ((b2 - b) / m);\r\n    b = b2;\r\n  }\r\
    \n  return ans + floor_sum_unsigned(n, m, a, b);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/floor-sum.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Sum-of-Floor-of-Linear.test.cpp
documentation_of: math/floor-sum.hpp
layout: document
redirect_from:
- /library/math/floor-sum.hpp
- /library/math/floor-sum.hpp.html
title: math/floor-sum.hpp
---
