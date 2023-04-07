---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: math/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ os << a.x; }\r\n};\r\n//using mint = Mint<1000000007>;\n#line 2 \"math/comb-modP.hpp\"\
    \n\r\nconstexpr int len = 2000010;\r\nconstexpr int f_size = min(len, mod);\r\n\
    mint fact[f_size], invfact[f_size], inv[f_size];\r\nstruct initializer {\r\n \
    \ initializer(){\r\n    fact[0] = fact[1] = inv[1] = 1;\r\n    invfact[0] = invfact[1]\
    \ = 1;\r\n    for(int i = 2; i < f_size; i++){\r\n      fact[i] = fact[i - 1]\
    \ * i;\r\n      inv[i] = -inv[mod % i] * (mod/i);\r\n      invfact[i] = invfact[i\
    \ - 1] * inv[i];\r\n    }\r\n  }\r\n} initializer;\r\nmint C(int n, int r){\r\n\
    \  assert(0 <= n && n < len);\r\n  mint res = 1;\r\n  while(r){\r\n    int a =\
    \ n % mod;\r\n    int b = r % mod;\r\n    if(a < b) return 0;\r\n    res *= fact[a]\
    \ * invfact[b] * invfact[a - b];\r\n    n /= mod;\r\n    r /= mod;\r\n  }\r\n\
    \  return res;\r\n}\r\nmint H(int n, int r){\r\n  assert(0 < n && 0 <= r);\r\n\
    \  assert(0 < n+r && n+r <= len);\r\n  return C(n + r - 1, r);\r\n}\n"
  code: "#include \"mint.hpp\"\r\n\r\nconstexpr int len = 2000010;\r\nconstexpr int\
    \ f_size = min(len, mod);\r\nmint fact[f_size], invfact[f_size], inv[f_size];\r\
    \nstruct initializer {\r\n  initializer(){\r\n    fact[0] = fact[1] = inv[1] =\
    \ 1;\r\n    invfact[0] = invfact[1] = 1;\r\n    for(int i = 2; i < f_size; i++){\r\
    \n      fact[i] = fact[i - 1] * i;\r\n      inv[i] = -inv[mod % i] * (mod/i);\r\
    \n      invfact[i] = invfact[i - 1] * inv[i];\r\n    }\r\n  }\r\n} initializer;\r\
    \nmint C(int n, int r){\r\n  assert(0 <= n && n < len);\r\n  mint res = 1;\r\n\
    \  while(r){\r\n    int a = n % mod;\r\n    int b = r % mod;\r\n    if(a < b)\
    \ return 0;\r\n    res *= fact[a] * invfact[b] * invfact[a - b];\r\n    n /= mod;\r\
    \n    r /= mod;\r\n  }\r\n  return res;\r\n}\r\nmint H(int n, int r){\r\n  assert(0\
    \ < n && 0 <= r);\r\n  assert(0 < n+r && n+r <= len);\r\n  return C(n + r - 1,\
    \ r);\r\n}"
  dependsOn:
  - math/mint.hpp
  isVerificationFile: false
  path: math/comb-modP.hpp
  requiredBy: []
  timestamp: '2023-03-13 14:46:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/comb-modP.hpp
layout: document
redirect_from:
- /library/math/comb-modP.hpp
- /library/math/comb-modP.hpp.html
title: math/comb-modP.hpp
---
