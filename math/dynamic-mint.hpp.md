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
  bundledCode: "#line 1 \"math/dynamic-mint.hpp\"\nusing ull = unsigned long long;\n\
    unsigned int mod;\null bar;\n\nstruct mint {\n  using uint = unsigned int;\n \
    \ uint x;\n  mint(const uint &x = 0) : x((x+mod)%mod){}\n  mint operator-() const{\
    \ return mint(mod - x); }\n  mint operator+=(const mint &a){\n    if((x += a.x)\
    \ >= mod) x -= mod;\n    return *this;\n  }\n  mint &operator++(){\n    if(++x\
    \ == mod) x = 0;\n    return *this;\n  }\n  mint operator++(int){\n    mint res\
    \ = *this;\n    ++*this;\n    return res;\n  }\n  mint &operator-=(const mint\
    \ &a){\n    if(x >= a.x) x -= a.x;\n    else x += mod - a.x;\n    return *this;\n\
    \  }\n  mint &operator--(){\n    if(!x) x = mod - 1;\n    else x--;\n    return\
    \ *this;\n  }\n  mint operator--(int){\n    mint res = *this;\n    --*this;\n\
    \    return res;\n  }\n  mint &operator*=(const mint &a){\n    ull z = (ull)x\
    \ * a.x;\n    ull t = (ull)(((unsigned __int128)z * bar) >> 64);\n    x = (uint)(z\
    \ - t*mod);\n    if(mod <= x) x += mod;\n    return *this;\n  }\n  mint operator+(const\
    \ mint &a) const{ return mint(*this) += a; }\n  mint operator-(const mint &a)\
    \ const{ return mint(*this) -= a; }\n  mint operator*(const mint &a) const{ return\
    \ mint(*this) *= a; }\n  mint pow(ull t) const{\n    if(!t) return 1;\n    mint\
    \ res = 1, v = *this;\n    while(t){\n      if(t & 1) res *= v;\n      v *= v;\n\
    \      t >>= 1;\n    }\n    return res;\n  }\n  mint &operator/=(const mint &a){\
    \ x /= a.x; return *this; }\n  mint operator/(const mint &a) const{ return mint(*this)\
    \ /= a; }\n  bool operator==(const mint &a) const{ return x == a.x; }\n  bool\
    \ operator!=(const mint &a) const{ return x != a.x; }\n  bool operator<(const\
    \ mint &a) const{ return x < a.x; }\n  bool operator>(const mint &a) const{ return\
    \ x > a.x; }\n  friend istream &operator>>(istream &is, mint &a){ return is >>\
    \ a.x; }\n  friend ostream &operator<<(ostream &os, const mint &a){ return os\
    \ << a.x; }\n};\nvoid init(){\n  bar = (ull)-1 / mod + 1;\n}\n"
  code: "using ull = unsigned long long;\nunsigned int mod;\null bar;\n\nstruct mint\
    \ {\n  using uint = unsigned int;\n  uint x;\n  mint(const uint &x = 0) : x((x+mod)%mod){}\n\
    \  mint operator-() const{ return mint(mod - x); }\n  mint operator+=(const mint\
    \ &a){\n    if((x += a.x) >= mod) x -= mod;\n    return *this;\n  }\n  mint &operator++(){\n\
    \    if(++x == mod) x = 0;\n    return *this;\n  }\n  mint operator++(int){\n\
    \    mint res = *this;\n    ++*this;\n    return res;\n  }\n  mint &operator-=(const\
    \ mint &a){\n    if(x >= a.x) x -= a.x;\n    else x += mod - a.x;\n    return\
    \ *this;\n  }\n  mint &operator--(){\n    if(!x) x = mod - 1;\n    else x--;\n\
    \    return *this;\n  }\n  mint operator--(int){\n    mint res = *this;\n    --*this;\n\
    \    return res;\n  }\n  mint &operator*=(const mint &a){\n    ull z = (ull)x\
    \ * a.x;\n    ull t = (ull)(((unsigned __int128)z * bar) >> 64);\n    x = (uint)(z\
    \ - t*mod);\n    if(mod <= x) x += mod;\n    return *this;\n  }\n  mint operator+(const\
    \ mint &a) const{ return mint(*this) += a; }\n  mint operator-(const mint &a)\
    \ const{ return mint(*this) -= a; }\n  mint operator*(const mint &a) const{ return\
    \ mint(*this) *= a; }\n  mint pow(ull t) const{\n    if(!t) return 1;\n    mint\
    \ res = 1, v = *this;\n    while(t){\n      if(t & 1) res *= v;\n      v *= v;\n\
    \      t >>= 1;\n    }\n    return res;\n  }\n  mint &operator/=(const mint &a){\
    \ x /= a.x; return *this; }\n  mint operator/(const mint &a) const{ return mint(*this)\
    \ /= a; }\n  bool operator==(const mint &a) const{ return x == a.x; }\n  bool\
    \ operator!=(const mint &a) const{ return x != a.x; }\n  bool operator<(const\
    \ mint &a) const{ return x < a.x; }\n  bool operator>(const mint &a) const{ return\
    \ x > a.x; }\n  friend istream &operator>>(istream &is, mint &a){ return is >>\
    \ a.x; }\n  friend ostream &operator<<(ostream &os, const mint &a){ return os\
    \ << a.x; }\n};\nvoid init(){\n  bar = (ull)-1 / mod + 1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/dynamic-mint.hpp
  requiredBy: []
  timestamp: '2022-03-01 14:17:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dynamic-mint.hpp
layout: document
redirect_from:
- /library/math/dynamic-mint.hpp
- /library/math/dynamic-mint.hpp.html
title: math/dynamic-mint.hpp
---
