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
  bundledCode: "#line 1 \"math/dynamic-mint.hpp\"\nusing ull = unsigned long long;\r\
    \n\r\nunsigned int mod;\r\null bar;\r\n\r\nstruct mint {\r\n  using uint = unsigned\
    \ int;\r\n  uint x;\r\n  mint(const uint &x = 0) : x((x+mod)%mod){}\r\n  mint\
    \ operator-() const{ return mint(mod - x); }\r\n  mint operator+=(const mint &a){\r\
    \n    if((x += a.x) >= mod) x -= mod;\r\n    return *this;\r\n  }\r\n  mint &operator++(){\r\
    \n    if(++x == mod) x = 0;\r\n    return *this;\r\n  }\r\n  mint operator++(int){\r\
    \n    mint res = *this;\r\n    ++*this;\r\n    return res;\r\n  }\r\n  mint &operator-=(const\
    \ mint &a){\r\n    if(x >= a.x) x -= a.x;\r\n    else x += mod - a.x;\r\n    return\
    \ *this;\r\n  }\r\n  mint &operator--(){\r\n    if(!x) x = mod - 1;\r\n    else\
    \ x--;\r\n    return *this;\r\n  }\r\n  mint operator--(int){\r\n    mint res\
    \ = *this;\r\n    --*this;\r\n    return res;\r\n  }\r\n  mint &operator*=(const\
    \ mint &a){\r\n    ull z = (ull)x * a.x;\r\n    ull t = (ull)(((unsigned __int128)z\
    \ * bar) >> 64);\r\n    x = (uint)(z - t*mod);\r\n    if(mod <= x) x += mod;\r\
    \n    return *this;\r\n  }\r\n  mint operator+(const mint &a) const{ return mint(*this)\
    \ += a; }\r\n  mint operator-(const mint &a) const{ return mint(*this) -= a; }\r\
    \n  mint operator*(const mint &a) const{ return mint(*this) *= a; }\r\n  mint\
    \ pow(ull t) const{\r\n    if(!t) return 1;\r\n    mint res = 1, v = *this;\r\n\
    \    while(t){\r\n      if(t & 1) res *= v;\r\n      v *= v;\r\n      t >>= 1;\r\
    \n    }\r\n    return res;\r\n  }\r\n  mint &operator/=(const mint &a){ x /= a.x;\
    \ return *this; }\r\n  mint operator/(const mint &a) const{ return mint(*this)\
    \ /= a; }\r\n  bool operator==(const mint &a) const{ return x == a.x; }\r\n  bool\
    \ operator!=(const mint &a) const{ return x != a.x; }\r\n  bool operator<(const\
    \ mint &a) const{ return x < a.x; }\r\n  bool operator>(const mint &a) const{\
    \ return x > a.x; }\r\n  friend istream &operator>>(istream &is, mint &a){ return\
    \ is >> a.x; }\r\n  friend ostream &operator<<(ostream &os, const mint &a){ return\
    \ os << a.x; }\r\n};\r\nvoid init(){\r\n  bar = (ull)-1 / mod + 1;\r\n}\n"
  code: "using ull = unsigned long long;\r\n\r\nunsigned int mod;\r\null bar;\r\n\r\
    \nstruct mint {\r\n  using uint = unsigned int;\r\n  uint x;\r\n  mint(const uint\
    \ &x = 0) : x((x+mod)%mod){}\r\n  mint operator-() const{ return mint(mod - x);\
    \ }\r\n  mint operator+=(const mint &a){\r\n    if((x += a.x) >= mod) x -= mod;\r\
    \n    return *this;\r\n  }\r\n  mint &operator++(){\r\n    if(++x == mod) x =\
    \ 0;\r\n    return *this;\r\n  }\r\n  mint operator++(int){\r\n    mint res =\
    \ *this;\r\n    ++*this;\r\n    return res;\r\n  }\r\n  mint &operator-=(const\
    \ mint &a){\r\n    if(x >= a.x) x -= a.x;\r\n    else x += mod - a.x;\r\n    return\
    \ *this;\r\n  }\r\n  mint &operator--(){\r\n    if(!x) x = mod - 1;\r\n    else\
    \ x--;\r\n    return *this;\r\n  }\r\n  mint operator--(int){\r\n    mint res\
    \ = *this;\r\n    --*this;\r\n    return res;\r\n  }\r\n  mint &operator*=(const\
    \ mint &a){\r\n    ull z = (ull)x * a.x;\r\n    ull t = (ull)(((unsigned __int128)z\
    \ * bar) >> 64);\r\n    x = (uint)(z - t*mod);\r\n    if(mod <= x) x += mod;\r\
    \n    return *this;\r\n  }\r\n  mint operator+(const mint &a) const{ return mint(*this)\
    \ += a; }\r\n  mint operator-(const mint &a) const{ return mint(*this) -= a; }\r\
    \n  mint operator*(const mint &a) const{ return mint(*this) *= a; }\r\n  mint\
    \ pow(ull t) const{\r\n    if(!t) return 1;\r\n    mint res = 1, v = *this;\r\n\
    \    while(t){\r\n      if(t & 1) res *= v;\r\n      v *= v;\r\n      t >>= 1;\r\
    \n    }\r\n    return res;\r\n  }\r\n  mint &operator/=(const mint &a){ x /= a.x;\
    \ return *this; }\r\n  mint operator/(const mint &a) const{ return mint(*this)\
    \ /= a; }\r\n  bool operator==(const mint &a) const{ return x == a.x; }\r\n  bool\
    \ operator!=(const mint &a) const{ return x != a.x; }\r\n  bool operator<(const\
    \ mint &a) const{ return x < a.x; }\r\n  bool operator>(const mint &a) const{\
    \ return x > a.x; }\r\n  friend istream &operator>>(istream &is, mint &a){ return\
    \ is >> a.x; }\r\n  friend ostream &operator<<(ostream &os, const mint &a){ return\
    \ os << a.x; }\r\n};\r\nvoid init(){\r\n  bar = (ull)-1 / mod + 1;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/dynamic-mint.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dynamic-mint.hpp
layout: document
redirect_from:
- /library/math/dynamic-mint.hpp
- /library/math/dynamic-mint.hpp.html
title: math/dynamic-mint.hpp
---
