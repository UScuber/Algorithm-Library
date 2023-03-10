---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/mint.hpp
    title: math/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/combination.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 1 \"math/mint.hpp\"\nusing ll = long long;\n\ntemplate <int mod>\nstruct Mint\
    \ {\n  ll x;\n  constexpr Mint(ll x = 0) : x((x + mod) % mod){}\n  static constexpr\
    \ int get_mod(){ return mod; }\n  constexpr Mint operator-() const{ return Mint(-x);\
    \ }\n  constexpr Mint operator+=(const Mint &a){\n    if((x += a.x) >= mod) x\
    \ -= mod;\n    return *this;\n  }\n  constexpr Mint &operator++(){\n    if(++x\
    \ == mod) x = 0;\n    return *this;\n  }\n  constexpr Mint operator++(int){\n\
    \    Mint temp = *this;\n    if(++x == mod) x = 0;\n    return temp;\n  }\n  constexpr\
    \ Mint &operator-=(const Mint &a){\n    if((x -= a.x) < 0) x += mod;\n    return\
    \ *this;\n  }\n  constexpr Mint &operator--(){\n    if(--x < 0) x += mod;\n  \
    \  return *this;\n  }\n  constexpr Mint operator--(int){\n    Mint temp = *this;\n\
    \    if(--x < 0) x += mod;\n    return temp;\n  }\n  constexpr Mint &operator*=(const\
    \ Mint &a){\n    (x *= a.x) %= mod;\n    return *this;\n  }\n  constexpr Mint\
    \ operator+(const Mint &a) const{ return Mint(*this) += a; }\n  constexpr Mint\
    \ operator-(const Mint &a) const{ return Mint(*this) -= a; }\n  constexpr Mint\
    \ operator*(const Mint &a) const{ return Mint(*this) *= a; }\n  constexpr Mint\
    \ pow(ll t) const{\n    if(!t) return 1;\n    Mint res = 1, v = *this;\n    while(t){\n\
    \      if(t & 1) res *= v;\n      v *= v;\n      t >>= 1;\n    }\n    return res;\n\
    \  }\n  constexpr Mint inv() const{ return pow(mod - 2); }\n  constexpr Mint &operator/=(const\
    \ Mint &a){ return (*this) *= a.inv(); }\n  constexpr Mint operator/(const Mint\
    \ &a) const{ return Mint(*this) /= a; }\n  constexpr bool operator==(const Mint\
    \ &a) const{ return x == a.x; }\n  constexpr bool operator!=(const Mint &a) const{\
    \ return x != a.x; }\n  constexpr bool operator<(const Mint &a) const{ return\
    \ x < a.x; }\n  constexpr bool operator>(const Mint &a) const{ return x > a.x;\
    \ }\n  friend istream &operator>>(istream &is, Mint &a){ return is >> a.x; }\n\
    \  friend ostream &operator<<(ostream &os, const Mint &a){ return os << a.x; }\n\
    };\nusing mint = Mint<1000000007>;\n#line 3 \"math/combination.cpp\"\nusing namespace\
    \ std;\n\nconstexpr int len = 2000010;\nmint fact[len], invfact[len];\nstruct\
    \ initializer {\n  initializer(){\n    fact[0] = fact[1] = 1;\n    for(int i =\
    \ 2; i < len; i++) fact[i] = fact[i - 1] * i;\n    invfact[len - 1] = fact[len\
    \ - 1].inv();\n    for(int i = len - 2; i >= 0; i--) invfact[i] = invfact[i +\
    \ 1] * (i + 1);\n  }\n} initializer;\nmint C(const int n, const int r){\n  assert(0\
    \ <= n && n < len);\n  if(n < r) return 0;\n  return fact[n] * invfact[n - r]\
    \ * invfact[r];\n}\nmint P(const int n, const int r){\n  assert(0 <= n && n <\
    \ len);\n  if(n < r) return 0;\n  return fact[n] * invfact[n - r];\n}\nmint H(const\
    \ int n, const int r){\n  assert(0 < n && 0 <= r);\n  assert(0 < n+r && n+r <=\
    \ len);\n  return fact[n + r - 1] * invfact[n - 1] * invfact[r];\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"mint.hpp\"\nusing namespace std;\n\n\
    constexpr int len = 2000010;\nmint fact[len], invfact[len];\nstruct initializer\
    \ {\n  initializer(){\n    fact[0] = fact[1] = 1;\n    for(int i = 2; i < len;\
    \ i++) fact[i] = fact[i - 1] * i;\n    invfact[len - 1] = fact[len - 1].inv();\n\
    \    for(int i = len - 2; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1);\n\
    \  }\n} initializer;\nmint C(const int n, const int r){\n  assert(0 <= n && n\
    \ < len);\n  if(n < r) return 0;\n  return fact[n] * invfact[n - r] * invfact[r];\n\
    }\nmint P(const int n, const int r){\n  assert(0 <= n && n < len);\n  if(n < r)\
    \ return 0;\n  return fact[n] * invfact[n - r];\n}\nmint H(const int n, const\
    \ int r){\n  assert(0 < n && 0 <= r);\n  assert(0 < n+r && n+r <= len);\n  return\
    \ fact[n + r - 1] * invfact[n - 1] * invfact[r];\n}"
  dependsOn:
  - math/mint.hpp
  isVerificationFile: false
  path: math/combination.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination.cpp
layout: document
redirect_from:
- /library/math/combination.cpp
- /library/math/combination.cpp.html
title: math/combination.cpp
---
