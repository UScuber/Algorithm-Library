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
  bundledCode: "#line 1 \"math/floor-sum.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\null floor_sum_unsigned(ull\
    \ n, ull m, ull a, ull b){\n  ull ans = 0;\n  while(true){\n    if(a >= m){\n\
    \      ans += n * (n - 1) / 2 * (a / m);\n      a %= m;\n    }\n    if(b >= m){\n\
    \      ans += n * (b / m);\n      b %= m;\n    }\n    const ull y_max = a * n\
    \ + b;\n    if(y_max < m) break;\n    n = y_max / m;\n    b = y_max % m;\n   \
    \ swap(m, a);\n  }\n  return ans;\n}\nll floor_sum(const ll n, const ll m, ll\
    \ a, ll b){\n  assert(0 <= n && n < (1LL << 32));\n  assert(1 <= m && m < (1LL\
    \ << 32));\n  ull ans = 0;\n  if(a < 0){\n    const ull a2 = (a % m + m) % m;\n\
    \    ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);\n    a = a2;\n  }\n  if(b\
    \ < 0){\n    const ull b2 = (b % m + m) % m;\n    ans -= 1ULL * n * ((b2 - b)\
    \ / m);\n    b = b2;\n  }\n  return ans + floor_sum_unsigned(n, m, a, b);\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\null floor_sum_unsigned(ull n, ull m, ull a,\
    \ ull b){\n  ull ans = 0;\n  while(true){\n    if(a >= m){\n      ans += n * (n\
    \ - 1) / 2 * (a / m);\n      a %= m;\n    }\n    if(b >= m){\n      ans += n *\
    \ (b / m);\n      b %= m;\n    }\n    const ull y_max = a * n + b;\n    if(y_max\
    \ < m) break;\n    n = y_max / m;\n    b = y_max % m;\n    swap(m, a);\n  }\n\
    \  return ans;\n}\nll floor_sum(const ll n, const ll m, ll a, ll b){\n  assert(0\
    \ <= n && n < (1LL << 32));\n  assert(1 <= m && m < (1LL << 32));\n  ull ans =\
    \ 0;\n  if(a < 0){\n    const ull a2 = (a % m + m) % m;\n    ans -= 1ULL * n *\
    \ (n - 1) / 2 * ((a2 - a) / m);\n    a = a2;\n  }\n  if(b < 0){\n    const ull\
    \ b2 = (b % m + m) % m;\n    ans -= 1ULL * n * ((b2 - b) / m);\n    b = b2;\n\
    \  }\n  return ans + floor_sum_unsigned(n, m, a, b);\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/floor-sum.cpp
  requiredBy: []
  timestamp: '2023-01-04 15:18:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/floor-sum.cpp
layout: document
redirect_from:
- /library/math/floor-sum.cpp
- /library/math/floor-sum.cpp.html
title: math/floor-sum.cpp
---
