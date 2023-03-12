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
  bundledCode: "#line 1 \"others/random.hpp\"\ninline unsigned int randxor32() noexcept{\r\
    \n  static unsigned int y = 2463534242;\r\n  y = y ^ (y << 13); y = y ^ (y >>\
    \ 17);\r\n  return y = y ^ (y << 5);\r\n}\r\n// returns random [l, r)\r\ninline\
    \ int rnd(const int l, const int r) noexcept{\r\n  return randxor32() % (r - l)\
    \ + l;\r\n}\r\n\r\nunsigned long long randxor64(){\r\n  static unsigned long long\
    \ x = 88172645463325252ULL;\r\n  x = x ^ (x << 7);\r\n  return x = x ^ (x >> 9);\r\
    \n}\r\n// returns random [l, r)\r\ninline long long rnd(const ll l, const ll r)\
    \ noexcept{\r\n  return randxor64() % (r - l) + l;\r\n}\n"
  code: "inline unsigned int randxor32() noexcept{\r\n  static unsigned int y = 2463534242;\r\
    \n  y = y ^ (y << 13); y = y ^ (y >> 17);\r\n  return y = y ^ (y << 5);\r\n}\r\
    \n// returns random [l, r)\r\ninline int rnd(const int l, const int r) noexcept{\r\
    \n  return randxor32() % (r - l) + l;\r\n}\r\n\r\nunsigned long long randxor64(){\r\
    \n  static unsigned long long x = 88172645463325252ULL;\r\n  x = x ^ (x << 7);\r\
    \n  return x = x ^ (x >> 9);\r\n}\r\n// returns random [l, r)\r\ninline long long\
    \ rnd(const ll l, const ll r) noexcept{\r\n  return randxor64() % (r - l) + l;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: others/random.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/random.hpp
layout: document
redirect_from:
- /library/others/random.hpp
- /library/others/random.hpp.html
title: others/random.hpp
---
