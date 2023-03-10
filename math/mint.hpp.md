---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/hld.cpp
    title: data-structure/hld.cpp
  - icon: ':warning:'
    path: math/comb-modP.cpp
    title: math/comb-modP.cpp
  - icon: ':warning:'
    path: math/combination.cpp
    title: math/combination.cpp
  - icon: ':warning:'
    path: math/convolution/convolution-arbitrary-mod.cpp
    title: math/convolution/convolution-arbitrary-mod.cpp
  - icon: ':warning:'
    path: math/fps/fps-arbitrary-mod.hpp
    title: math/fps/fps-arbitrary-mod.hpp
  - icon: ':warning:'
    path: math/fps/fps-template.hpp
    title: math/fps/fps-template.hpp
  - icon: ':warning:'
    path: math/fps/fps.hpp
    title: math/fps/fps.hpp
  - icon: ':warning:'
    path: math/fps/kitamasa.cpp
    title: math/fps/kitamasa.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/mint.hpp\"\nusing ll = long long;\n\ntemplate <int\
    \ mod>\nstruct Mint {\n  ll x;\n  constexpr Mint(ll x = 0) : x((x + mod) % mod){}\n\
    \  static constexpr int get_mod(){ return mod; }\n  constexpr Mint operator-()\
    \ const{ return Mint(-x); }\n  constexpr Mint operator+=(const Mint &a){\n   \
    \ if((x += a.x) >= mod) x -= mod;\n    return *this;\n  }\n  constexpr Mint &operator++(){\n\
    \    if(++x == mod) x = 0;\n    return *this;\n  }\n  constexpr Mint operator++(int){\n\
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
    };\nusing mint = Mint<1000000007>;\n"
  code: "using ll = long long;\n\ntemplate <int mod>\nstruct Mint {\n  ll x;\n  constexpr\
    \ Mint(ll x = 0) : x((x + mod) % mod){}\n  static constexpr int get_mod(){ return\
    \ mod; }\n  constexpr Mint operator-() const{ return Mint(-x); }\n  constexpr\
    \ Mint operator+=(const Mint &a){\n    if((x += a.x) >= mod) x -= mod;\n    return\
    \ *this;\n  }\n  constexpr Mint &operator++(){\n    if(++x == mod) x = 0;\n  \
    \  return *this;\n  }\n  constexpr Mint operator++(int){\n    Mint temp = *this;\n\
    \    if(++x == mod) x = 0;\n    return temp;\n  }\n  constexpr Mint &operator-=(const\
    \ Mint &a){\n    if((x -= a.x) < 0) x += mod;\n    return *this;\n  }\n  constexpr\
    \ Mint &operator--(){\n    if(--x < 0) x += mod;\n    return *this;\n  }\n  constexpr\
    \ Mint operator--(int){\n    Mint temp = *this;\n    if(--x < 0) x += mod;\n \
    \   return temp;\n  }\n  constexpr Mint &operator*=(const Mint &a){\n    (x *=\
    \ a.x) %= mod;\n    return *this;\n  }\n  constexpr Mint operator+(const Mint\
    \ &a) const{ return Mint(*this) += a; }\n  constexpr Mint operator-(const Mint\
    \ &a) const{ return Mint(*this) -= a; }\n  constexpr Mint operator*(const Mint\
    \ &a) const{ return Mint(*this) *= a; }\n  constexpr Mint pow(ll t) const{\n \
    \   if(!t) return 1;\n    Mint res = 1, v = *this;\n    while(t){\n      if(t\
    \ & 1) res *= v;\n      v *= v;\n      t >>= 1;\n    }\n    return res;\n  }\n\
    \  constexpr Mint inv() const{ return pow(mod - 2); }\n  constexpr Mint &operator/=(const\
    \ Mint &a){ return (*this) *= a.inv(); }\n  constexpr Mint operator/(const Mint\
    \ &a) const{ return Mint(*this) /= a; }\n  constexpr bool operator==(const Mint\
    \ &a) const{ return x == a.x; }\n  constexpr bool operator!=(const Mint &a) const{\
    \ return x != a.x; }\n  constexpr bool operator<(const Mint &a) const{ return\
    \ x < a.x; }\n  constexpr bool operator>(const Mint &a) const{ return x > a.x;\
    \ }\n  friend istream &operator>>(istream &is, Mint &a){ return is >> a.x; }\n\
    \  friend ostream &operator<<(ostream &os, const Mint &a){ return os << a.x; }\n\
    };\nusing mint = Mint<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: math/mint.hpp
  requiredBy:
  - data-structure/hld.cpp
  - math/comb-modP.cpp
  - math/fps/fps.hpp
  - math/fps/fps-template.hpp
  - math/fps/kitamasa.cpp
  - math/fps/fps-arbitrary-mod.hpp
  - math/combination.cpp
  - math/convolution/convolution-arbitrary-mod.cpp
  timestamp: '2022-09-15 18:23:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mint.hpp
layout: document
redirect_from:
- /library/math/mint.hpp
- /library/math/mint.hpp.html
title: math/mint.hpp
---
