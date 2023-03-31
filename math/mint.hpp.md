---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/comb-modP.hpp
    title: math/comb-modP.hpp
  - icon: ':warning:'
    path: math/combination.hpp
    title: math/combination.hpp
  - icon: ':heavy_check_mark:'
    path: math/convolution/convolution-arbitrary-mod.hpp
    title: math/convolution/convolution-arbitrary-mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/fps/fps-arbitrary-mod.hpp
    title: math/fps/fps-arbitrary-mod.hpp
  - icon: ':question:'
    path: math/fps/fps-template.hpp
    title: math/fps/fps-template.hpp
  - icon: ':question:'
    path: math/fps/fps.hpp
    title: math/fps/fps.hpp
  - icon: ':heavy_check_mark:'
    path: math/fps/kitamasa.hpp
    title: math/fps/kitamasa.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
    title: test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
    title: test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Convolution(Mod1e9+7).test.cpp
    title: test/yosupo/Convolution/Convolution(Mod1e9+7).test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Convolution(Mod1e9+7)2.test.cpp
    title: test/yosupo/Convolution/Convolution(Mod1e9+7)2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Convolution.test.cpp
    title: test/yosupo/Convolution/Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Point-Set-Range-Composite.test.cpp
    title: test/yosupo/Data-Structure/Point-Set-Range-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
    title: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
    title: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
    title: test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Kth-term-of-Linearly-Recurrent-Sequence.test.cpp
    title: test/yosupo/Math/Kth-term-of-Linearly-Recurrent-Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Subset-Sum.test.cpp
    title: test/yosupo/Math/Subset-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
    title: test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Matrix/Inverse-Matrix.test.cpp
    title: test/yosupo/Matrix/Inverse-Matrix.test.cpp
  - icon: ':x:'
    path: test/yosupo/Matrix/Matrix-Product.test.cpp
    title: test/yosupo/Matrix/Matrix-Product.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - icon: ':x:'
    path: test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mint.hpp\"\n\r\ntemplate <int mod>\r\nstruct Mint {\r\
    \n  ll x;\r\n  constexpr Mint(ll x = 0) : x((x + mod) % mod){}\r\n  static constexpr\
    \ int get_mod(){ return mod; }\r\n  constexpr Mint operator-() const{ return Mint(-x);\
    \ }\r\n  constexpr Mint operator+=(const Mint &a){\r\n    if((x += a.x) >= mod)\
    \ x -= mod;\r\n    return *this;\r\n  }\r\n  constexpr Mint &operator++(){\r\n\
    \    if(++x == mod) x = 0;\r\n    return *this;\r\n  }\r\n  constexpr Mint operator++(int){\r\
    \n    Mint temp = *this;\r\n    if(++x == mod) x = 0;\r\n    return temp;\r\n\
    \  }\r\n  constexpr Mint &operator-=(const Mint &a){\r\n    if((x -= a.x) < 0)\
    \ x += mod;\r\n    return *this;\r\n  }\r\n  constexpr Mint &operator--(){\r\n\
    \    if(--x < 0) x += mod;\r\n    return *this;\r\n  }\r\n  constexpr Mint operator--(int){\r\
    \n    Mint temp = *this;\r\n    if(--x < 0) x += mod;\r\n    return temp;\r\n\
    \  }\r\n  constexpr Mint &operator*=(const Mint &a){\r\n    (x *= a.x) %= mod;\r\
    \n    return *this;\r\n  }\r\n  constexpr Mint operator+(const Mint &a) const{\
    \ return Mint(*this) += a; }\r\n  constexpr Mint operator-(const Mint &a) const{\
    \ return Mint(*this) -= a; }\r\n  constexpr Mint operator*(const Mint &a) const{\
    \ return Mint(*this) *= a; }\r\n  constexpr Mint pow(ll t) const{\r\n    if(!t)\
    \ return 1;\r\n    Mint res = 1, v = *this;\r\n    while(t){\r\n      if(t & 1)\
    \ res *= v;\r\n      v *= v;\r\n      t >>= 1;\r\n    }\r\n    return res;\r\n\
    \  }\r\n  constexpr Mint inv() const{ return pow(mod - 2); }\r\n  constexpr Mint\
    \ &operator/=(const Mint &a){ return (*this) *= a.inv(); }\r\n  constexpr Mint\
    \ operator/(const Mint &a) const{ return Mint(*this) /= a; }\r\n  constexpr bool\
    \ operator==(const Mint &a) const{ return x == a.x; }\r\n  constexpr bool operator!=(const\
    \ Mint &a) const{ return x != a.x; }\r\n  constexpr bool operator<(const Mint\
    \ &a) const{ return x < a.x; }\r\n  constexpr bool operator>(const Mint &a) const{\
    \ return x > a.x; }\r\n  friend istream &operator>>(istream &is, Mint &a){ return\
    \ is >> a.x; }\r\n  friend ostream &operator<<(ostream &os, const Mint &a){ return\
    \ os << a.x; }\r\n};\r\n//using mint = Mint<1000000007>;\n"
  code: "#pragma once\r\n\r\ntemplate <int mod>\r\nstruct Mint {\r\n  ll x;\r\n  constexpr\
    \ Mint(ll x = 0) : x((x + mod) % mod){}\r\n  static constexpr int get_mod(){ return\
    \ mod; }\r\n  constexpr Mint operator-() const{ return Mint(-x); }\r\n  constexpr\
    \ Mint operator+=(const Mint &a){\r\n    if((x += a.x) >= mod) x -= mod;\r\n \
    \   return *this;\r\n  }\r\n  constexpr Mint &operator++(){\r\n    if(++x == mod)\
    \ x = 0;\r\n    return *this;\r\n  }\r\n  constexpr Mint operator++(int){\r\n\
    \    Mint temp = *this;\r\n    if(++x == mod) x = 0;\r\n    return temp;\r\n \
    \ }\r\n  constexpr Mint &operator-=(const Mint &a){\r\n    if((x -= a.x) < 0)\
    \ x += mod;\r\n    return *this;\r\n  }\r\n  constexpr Mint &operator--(){\r\n\
    \    if(--x < 0) x += mod;\r\n    return *this;\r\n  }\r\n  constexpr Mint operator--(int){\r\
    \n    Mint temp = *this;\r\n    if(--x < 0) x += mod;\r\n    return temp;\r\n\
    \  }\r\n  constexpr Mint &operator*=(const Mint &a){\r\n    (x *= a.x) %= mod;\r\
    \n    return *this;\r\n  }\r\n  constexpr Mint operator+(const Mint &a) const{\
    \ return Mint(*this) += a; }\r\n  constexpr Mint operator-(const Mint &a) const{\
    \ return Mint(*this) -= a; }\r\n  constexpr Mint operator*(const Mint &a) const{\
    \ return Mint(*this) *= a; }\r\n  constexpr Mint pow(ll t) const{\r\n    if(!t)\
    \ return 1;\r\n    Mint res = 1, v = *this;\r\n    while(t){\r\n      if(t & 1)\
    \ res *= v;\r\n      v *= v;\r\n      t >>= 1;\r\n    }\r\n    return res;\r\n\
    \  }\r\n  constexpr Mint inv() const{ return pow(mod - 2); }\r\n  constexpr Mint\
    \ &operator/=(const Mint &a){ return (*this) *= a.inv(); }\r\n  constexpr Mint\
    \ operator/(const Mint &a) const{ return Mint(*this) /= a; }\r\n  constexpr bool\
    \ operator==(const Mint &a) const{ return x == a.x; }\r\n  constexpr bool operator!=(const\
    \ Mint &a) const{ return x != a.x; }\r\n  constexpr bool operator<(const Mint\
    \ &a) const{ return x < a.x; }\r\n  constexpr bool operator>(const Mint &a) const{\
    \ return x > a.x; }\r\n  friend istream &operator>>(istream &is, Mint &a){ return\
    \ is >> a.x; }\r\n  friend ostream &operator<<(ostream &os, const Mint &a){ return\
    \ os << a.x; }\r\n};\r\n//using mint = Mint<1000000007>;"
  dependsOn: []
  isVerificationFile: false
  path: math/mint.hpp
  requiredBy:
  - math/comb-modP.hpp
  - math/fps/fps-arbitrary-mod.hpp
  - math/fps/kitamasa.hpp
  - math/fps/fps.hpp
  - math/fps/fps-template.hpp
  - math/convolution/convolution-arbitrary-mod.hpp
  - math/combination.hpp
  timestamp: '2023-03-13 14:46:41+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/Convolution/Convolution(Mod1e9+7).test.cpp
  - test/yosupo/Convolution/Convolution.test.cpp
  - test/yosupo/Convolution/Convolution(Mod1e9+7)2.test.cpp
  - test/yosupo/Convolution/Bitwise-And-Convolution.test.cpp
  - test/yosupo/Convolution/Bitwise-Xor-Convolution.test.cpp
  - test/yosupo/Matrix/Matrix-Product.test.cpp
  - test/yosupo/Matrix/Determinant-of-Matrix.test.cpp
  - test/yosupo/Matrix/Inverse-Matrix.test.cpp
  - test/yosupo/Math/Subset-Sum.test.cpp
  - test/yosupo/Math/Kth-term-of-Linearly-Recurrent-Sequence.test.cpp
  - test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
  - test/yosupo/Data-Structure/Vertex-Set-Path-Composite.test.cpp
  - test/yosupo/Data-Structure/Point-Set-Range-Composite.test.cpp
  - test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
documentation_of: math/mint.hpp
layout: document
redirect_from:
- /library/math/mint.hpp
- /library/math/mint.hpp.html
title: math/mint.hpp
---
