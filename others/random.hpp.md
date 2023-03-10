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
  bundledCode: "#line 1 \"others/random.hpp\"\nusing ll = long long;\n\ninline unsigned\
    \ int randxor32() noexcept{\n  static unsigned int y = 2463534242;\n  y = y ^\
    \ (y << 13); y = y ^ (y >> 17);\n  return y = y ^ (y << 5);\n}\n// returns random\
    \ [l, r)\ninline int rnd(const int l, const int r) noexcept{\n  return randxor32()\
    \ % (r - l) + l;\n}\n\nunsigned long long randxor64(){\n  static unsigned long\
    \ long x = 88172645463325252ULL;\n  x = x ^ (x << 7);\n  return x = x ^ (x >>\
    \ 9);\n}\n// returns random [l, r)\ninline long long rnd(const ll l, const ll\
    \ r) noexcept{\n  return randxor64() % (r - l) + l;\n}\n"
  code: "using ll = long long;\n\ninline unsigned int randxor32() noexcept{\n  static\
    \ unsigned int y = 2463534242;\n  y = y ^ (y << 13); y = y ^ (y >> 17);\n  return\
    \ y = y ^ (y << 5);\n}\n// returns random [l, r)\ninline int rnd(const int l,\
    \ const int r) noexcept{\n  return randxor32() % (r - l) + l;\n}\n\nunsigned long\
    \ long randxor64(){\n  static unsigned long long x = 88172645463325252ULL;\n \
    \ x = x ^ (x << 7);\n  return x = x ^ (x >> 9);\n}\n// returns random [l, r)\n\
    inline long long rnd(const ll l, const ll r) noexcept{\n  return randxor64() %\
    \ (r - l) + l;\n}"
  dependsOn: []
  isVerificationFile: false
  path: others/random.hpp
  requiredBy: []
  timestamp: '2022-07-13 09:36:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/random.hpp
layout: document
redirect_from:
- /library/others/random.hpp
- /library/others/random.hpp.html
title: others/random.hpp
---
