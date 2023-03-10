---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/convolution/ntt.hpp
    title: math/convolution/ntt.hpp
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
  bundledCode: "#line 1 \"math/convolution/ntt.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class mint>\nstruct NTT {\n  static constexpr uint32_t\
    \ get_pr(){\n    const uint32_t _mod = mint::get_mod();\n    using u64 = uint64_t;\n\
    \    u64 ds[32] = {};\n    int idx = 0;\n    u64 m = _mod - 1;\n    for(u64 i\
    \ = 2; i * i <= m; i++){\n      if(m % i == 0){\n        ds[idx++] = i;\n    \
    \    while(m % i == 0) m /= i;\n      }\n    }\n    if(m != 1) ds[idx++] = m;\n\
    \    uint32_t _pr = 2;\n    while(true){\n      int flg = 1;\n      for(int i\
    \ = 0; i < idx; i++){\n        u64 a = _pr, b = (_mod - 1) / ds[i], r = 1;\n \
    \       while(b){\n          if(b & 1) r = r * a % _mod;\n          a = a * a\
    \ % _mod;\n          b >>= 1;\n        }\n        if(r == 1){\n          flg =\
    \ 0;\n          break;\n        }\n      }\n      if(flg == 1) break;\n      _pr++;\n\
    \    }\n    return _pr;\n  };\n  static constexpr uint32_t mod = mint::get_mod();\n\
    \  static constexpr uint32_t pr = get_pr();\n  static constexpr int level = __builtin_ctzll(mod\
    \ - 1);\n  mint dw[level], dy[level];\n  void setwy(const int k){\n    mint w[level],\
    \ y[level];\n    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n    y[k - 1]\
    \ = w[k - 1].inv();\n    for(int i = k - 2; i > 0; i--)\n      w[i] = w[i + 1]\
    \ * w[i + 1], y[i] = y[i + 1] * y[i + 1];\n    dw[1] = w[1], dy[1] = y[1], dw[2]\
    \ = w[2], dy[2] = y[2];\n    for(int i = 3; i < k; i++){\n      dw[i] = dw[i -\
    \ 1] * y[i - 2] * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n    }\n \
    \ }\n  NTT(){ setwy(level); }\n  void fft4(vector<mint> &a, const int k){\n  \
    \  if((int)a.size() <= 1) return;\n    if(k == 1){\n      mint a1 = a[1];\n  \
    \    a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n    if(k\
    \ & 1){\n      int v = 1 << (k - 1);\n      for(int j = 0; j < v; j++) {\n   \
    \     mint ajv = a[j + v];\n        a[j + v] = a[j] - ajv;\n        a[j] += ajv;\n\
    \      }\n    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 << (k - 2 - (k\
    \ & 1));\n    const mint one = mint(1);\n    mint imag = dw[1];\n    while(v)\
    \ {\n      // jh = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n    \
    \    int j2 = j1 + v;\n        int j3 = j2 + v;\n        for(; j0 < v; j0++, j1++,\
    \ j2++, j3++){\n          const mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 =\
    \ a[j3];\n          const mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n          const\
    \ mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;\n          a[j0] = t0p2 + t1p3,\
    \ a[j1] = t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n\
    \        }\n      }\n      // jh >= 1\n      mint ww = one, xx = one * dw[2],\
    \ wx = one;\n      for(int jh = 4; jh < u;){\n        ww = xx * xx, wx = ww *\
    \ xx;\n        int j0 = jh * v;\n        int je = j0 + v;\n        int j2 = je\
    \ + v;\n        for(; j0 < je; j0++, j2++){\n          const mint t0 = a[j0],\
    \ t1 = a[j0 + v] * xx, t2 = a[j2] * ww, t3 = a[j2 + v] * wx;\n          const\
    \ mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n          const mint t0m2 = t0 - t2, t1m3\
    \ = (t1 - t3) * imag;\n          a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;\n\
    \          a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;\n        }\n        xx\
    \ *= dw[__builtin_ctzll((jh += 4))];\n      }\n      u <<= 2;\n      v >>= 2;\n\
    \    }\n  }\n  void ifft4(vector<mint> &a, const int k){\n    if((int)a.size()\
    \ <= 1) return;\n    if(k == 1){\n      mint a1 = a[1];\n      a[1] = a[0] - a[1];\n\
    \      a[0] = a[0] + a1;\n      return;\n    }\n    int u = 1 << (k - 2);\n  \
    \  int v = 1;\n    const mint one = mint(1);\n    mint imag = dy[1];\n    while(u){\n\
    \      // jh = 0\n      {\n        int j0 = 0;\n        int j1 = v;\n        int\
    \ j2 = v + v;\n        int j3 = j2 + v;\n        for(; j0 < v; j0++, j1++, j2++,\
    \ j3++){\n          const mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n\
    \          const mint t0p1 = t0 + t1, t2p3 = t2 + t3;\n          const mint t0m1\
    \ = t0 - t1, t2m3 = (t2 - t3) * imag;\n          a[j0] = t0p1 + t2p3, a[j2] =\
    \ t0p1 - t2p3;\n          a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;\n        }\n\
    \      }\n      // jh >= 1\n      mint ww = one, xx = one * dy[2], yy = one;\n\
    \      u <<= 2;\n      for(int jh = 4; jh < u;){\n        ww = xx * xx, yy = xx\
    \ * imag;\n        int j0 = jh * v;\n        int je = j0 + v;\n        int j2\
    \ = je + v;\n        for(; j0 < je; j0++, j2++){\n          const mint t0 = a[j0],\
    \ t1 = a[j0 + v], t2 = a[j2], t3 = a[j2 + v];\n          const mint t0p1 = t0\
    \ + t1, t2p3 = t2 + t3;\n          const mint t0m1 = (t0 - t1) * xx, t2m3 = (t2\
    \ - t3) * yy;\n          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;\n  \
    \        a[j0 + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;\n        }\n\
    \        xx *= dy[__builtin_ctzll(jh += 4)];\n      }\n      u >>= 4;\n      v\
    \ <<= 2;\n    }\n    if(k & 1){\n      u = 1 << (k - 1);\n      for(int j = 0;\
    \ j < u; j++){\n        mint ajv = a[j] - a[j + u];\n        a[j] += a[j + u];\n\
    \        a[j + u] = ajv;\n      }\n    }\n  }\n  void ntt(vector<mint> &a){\n\
    \    if((int)a.size() <= 1) return;\n    fft4(a, __builtin_ctz(a.size()));\n \
    \ }\n  void intt(vector<mint> &a){\n    if((int)a.size() <= 1) return;\n    ifft4(a,\
    \ __builtin_ctz(a.size()));\n    const mint iv = mint(a.size()).inv();\n    for(auto\
    \ &x : a) x *= iv;\n  }\n  vector<mint> multiply(const vector<mint> &a, const\
    \ vector<mint> &b){\n    const int l = a.size() + b.size() - 1;\n    if(min<int>(a.size(),\
    \ b.size()) <= 40){\n      vector<mint> s(l);\n      for(int i = 0; i < (int)a.size();\
    \ i++)\n        for(int j = 0; j < (int)b.size(); j++) s[i + j] += a[i] * b[j];\n\
    \      return s;\n    }\n    int k = 2, M = 4;\n    while(M < l) M <<= 1, k++;\n\
    \    setwy(k);\n    vector<mint> s(M), t(M);\n    for(int i = 0; i < (int)a.size();\
    \ i++) s[i] = a[i];\n    for(int i = 0; i < (int)b.size(); i++) t[i] = b[i];\n\
    \    fft4(s, k);\n    fft4(t, k);\n    for(int i = 0; i < M; i++) s[i] *= t[i];\n\
    \    ifft4(s, k);\n    s.resize(l);\n    const mint invm = mint(M).inv();\n  \
    \  for(int i = 0; i < l; i++) s[i] *= invm;\n    return s;\n  }\n  void ntt_doubling(vector<mint>\
    \ &a){\n    const int M = (int)a.size();\n    auto b = a;\n    intt(b);\n    mint\
    \ r = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\n    for(int i\
    \ = 0; i < M; i++) b[i] *= r, r *= zeta;\n    ntt(b);\n    copy(begin(b), end(b),\
    \ back_inserter(a));\n  }\n};\n#line 1 \"math/mint.hpp\"\nusing ll = long long;\n\
    \ntemplate <int mod>\nstruct Mint {\n  ll x;\n  constexpr Mint(ll x = 0) : x((x\
    \ + mod) % mod){}\n  static constexpr int get_mod(){ return mod; }\n  constexpr\
    \ Mint operator-() const{ return Mint(-x); }\n  constexpr Mint operator+=(const\
    \ Mint &a){\n    if((x += a.x) >= mod) x -= mod;\n    return *this;\n  }\n  constexpr\
    \ Mint &operator++(){\n    if(++x == mod) x = 0;\n    return *this;\n  }\n  constexpr\
    \ Mint operator++(int){\n    Mint temp = *this;\n    if(++x == mod) x = 0;\n \
    \   return temp;\n  }\n  constexpr Mint &operator-=(const Mint &a){\n    if((x\
    \ -= a.x) < 0) x += mod;\n    return *this;\n  }\n  constexpr Mint &operator--(){\n\
    \    if(--x < 0) x += mod;\n    return *this;\n  }\n  constexpr Mint operator--(int){\n\
    \    Mint temp = *this;\n    if(--x < 0) x += mod;\n    return temp;\n  }\n  constexpr\
    \ Mint &operator*=(const Mint &a){\n    (x *= a.x) %= mod;\n    return *this;\n\
    \  }\n  constexpr Mint operator+(const Mint &a) const{ return Mint(*this) += a;\
    \ }\n  constexpr Mint operator-(const Mint &a) const{ return Mint(*this) -= a;\
    \ }\n  constexpr Mint operator*(const Mint &a) const{ return Mint(*this) *= a;\
    \ }\n  constexpr Mint pow(ll t) const{\n    if(!t) return 1;\n    Mint res = 1,\
    \ v = *this;\n    while(t){\n      if(t & 1) res *= v;\n      v *= v;\n      t\
    \ >>= 1;\n    }\n    return res;\n  }\n  constexpr Mint inv() const{ return pow(mod\
    \ - 2); }\n  constexpr Mint &operator/=(const Mint &a){ return (*this) *= a.inv();\
    \ }\n  constexpr Mint operator/(const Mint &a) const{ return Mint(*this) /= a;\
    \ }\n  constexpr bool operator==(const Mint &a) const{ return x == a.x; }\n  constexpr\
    \ bool operator!=(const Mint &a) const{ return x != a.x; }\n  constexpr bool operator<(const\
    \ Mint &a) const{ return x < a.x; }\n  constexpr bool operator>(const Mint &a)\
    \ const{ return x > a.x; }\n  friend istream &operator>>(istream &is, Mint &a){\
    \ return is >> a.x; }\n  friend ostream &operator<<(ostream &os, const Mint &a){\
    \ return os << a.x; }\n};\nusing mint = Mint<1000000007>;\n#line 3 \"math/convolution/convolution-arbitrary-mod.cpp\"\
    \n\nnamespace ArbitraryNTT {\nusing u128 = __uint128_t;\nconstexpr int m0 = 167772161;\n\
    constexpr int m1 = 469762049;\nconstexpr int m2 = 754974721;\nusing mint0 = Mint<m0>;\n\
    using mint1 = Mint<m1>;\nusing mint2 = Mint<m2>;\nconstexpr int r01 = mint1(m0).inv().x;\n\
    constexpr int r02 = mint2(m0).inv().x;\nconstexpr int r12 = mint2(m1).inv().x;\n\
    constexpr int r02r12 = ll(r02) * r12 % m2;\nconstexpr ll w1 = m0;\nconstexpr ll\
    \ w2 = ll(m0) * m1;\n\ntemplate <class T, class submint>\nvector<submint> mul(const\
    \ vector<T> &a, const vector<T> &b){\n  static NTT<submint> ntt;\n  vector<submint>\
    \ s(a.size()), t(b.size());\n  for(int i = 0; i < (int)a.size(); i++) s[i] = ll(a[i]\
    \ % submint::get_mod());\n  for(int i = 0; i < (int)b.size(); i++) t[i] = ll(b[i]\
    \ % submint::get_mod());\n  return ntt.multiply(s, t);\n}\ntemplate <class T>\n\
    vector<int> multiply(const vector<T> &s, const vector<T> &t, const int mod){\n\
    \  const auto d0 = mul<T, mint0>(s, t);\n  const auto d1 = mul<T, mint1>(s, t);\n\
    \  const auto d2 = mul<T, mint2>(s, t);\n  const int n = d0.size();\n  vector<int>\
    \ ret(n);\n  const int W1 = w1 % mod;\n  const int W2 = w2 % mod;\n  for(int i\
    \ = 0; i < n; i++){\n    const int n1 = d1[i].x, n2 = d2[i].x, a = d0[i].x;\n\
    \    const int b = ll(n1 + m1 - a) * r01 % m1;\n    const int c = (ll(n2 + m2\
    \ - a) * r02r12 + ll(m2 - b) * r12) % m2;\n    ret[i] = (ll(a) + ll(b) * W1 +\
    \ ll(c) * W2) % mod;\n  }\n  return ret;\n}\ntemplate <class mint>\nvector<mint>\
    \ multiply(const vector<mint> &a, const vector<mint> &b){\n  if(a.size() == 0\
    \ && b.size() == 0) return {};\n  if(min<int>(a.size(), b.size()) < 128){\n  \
    \  vector<mint> ret(a.size() + b.size() - 1);\n    for(int i = 0; i < (int)a.size();\
    \ i++)\n      for(int j = 0; j < (int)b.size(); j++) ret[i + j] += a[i] * b[j];\n\
    \    return ret;\n  }\n  vector<int> s(a.size()), t(b.size());\n  for(int i =\
    \ 0; i < (int)a.size(); i++) s[i] = a[i].x;\n  for(int i = 0; i < (int)b.size();\
    \ i++) t[i] = b[i].x;\n  vector<int> u = multiply<int>(s, t, mint::get_mod());\n\
    \  vector<mint> ret(u.size());\n  for(int i = 0; i < (int)u.size(); i++) ret[i]\
    \ = mint(u[i]);\n  return ret;\n}\nvector<ll> multiply_ll(const vector<ll> &s,\
    \ const vector<ll> &t){\n  const auto d0 = mul<ll, mint0>(s, t);\n  const auto\
    \ d1 = mul<ll, mint1>(s, t);\n  const auto d2 = mul<ll, mint2>(s, t);\n  const\
    \ int n = d0.size();\n  vector<ll> ret(n);\n  const ll W1 = w1;\n  const ll W2\
    \ = w2;\n  for(int i = 0; i < n; i++){\n    const ll n1 = d1[i].x, n2 = d2[i].x,\
    \ a = d0[i].x;\n    const ll b = ll(n1 + m1 - a) * r01 % m1;\n    const ll c =\
    \ (ll(n2 + m2 - a) * r02r12 + ll(m2 - b) * r12) % m2;\n    ret[i] = (ll(a) + ll(b)\
    \ * W1 + ll(c) * W2);\n  }\n  return ret;\n}\n} // namespace ArbitraryNTT\ntemplate\
    \ <class mint>\nvector<mint> convolution(const vector<mint> &a, const vector<mint>\
    \ &b){\n  return ArbitraryNTT::multiply(a, b);\n}\nvector<ll> convolution_ll(const\
    \ vector<ll> &a, const vector<ll> &b){\n  return ArbitraryNTT::multiply_ll(a,\
    \ b);\n}\n"
  code: "#include \"ntt.hpp\"\n#include \"../mint.hpp\"\n\nnamespace ArbitraryNTT\
    \ {\nusing u128 = __uint128_t;\nconstexpr int m0 = 167772161;\nconstexpr int m1\
    \ = 469762049;\nconstexpr int m2 = 754974721;\nusing mint0 = Mint<m0>;\nusing\
    \ mint1 = Mint<m1>;\nusing mint2 = Mint<m2>;\nconstexpr int r01 = mint1(m0).inv().x;\n\
    constexpr int r02 = mint2(m0).inv().x;\nconstexpr int r12 = mint2(m1).inv().x;\n\
    constexpr int r02r12 = ll(r02) * r12 % m2;\nconstexpr ll w1 = m0;\nconstexpr ll\
    \ w2 = ll(m0) * m1;\n\ntemplate <class T, class submint>\nvector<submint> mul(const\
    \ vector<T> &a, const vector<T> &b){\n  static NTT<submint> ntt;\n  vector<submint>\
    \ s(a.size()), t(b.size());\n  for(int i = 0; i < (int)a.size(); i++) s[i] = ll(a[i]\
    \ % submint::get_mod());\n  for(int i = 0; i < (int)b.size(); i++) t[i] = ll(b[i]\
    \ % submint::get_mod());\n  return ntt.multiply(s, t);\n}\ntemplate <class T>\n\
    vector<int> multiply(const vector<T> &s, const vector<T> &t, const int mod){\n\
    \  const auto d0 = mul<T, mint0>(s, t);\n  const auto d1 = mul<T, mint1>(s, t);\n\
    \  const auto d2 = mul<T, mint2>(s, t);\n  const int n = d0.size();\n  vector<int>\
    \ ret(n);\n  const int W1 = w1 % mod;\n  const int W2 = w2 % mod;\n  for(int i\
    \ = 0; i < n; i++){\n    const int n1 = d1[i].x, n2 = d2[i].x, a = d0[i].x;\n\
    \    const int b = ll(n1 + m1 - a) * r01 % m1;\n    const int c = (ll(n2 + m2\
    \ - a) * r02r12 + ll(m2 - b) * r12) % m2;\n    ret[i] = (ll(a) + ll(b) * W1 +\
    \ ll(c) * W2) % mod;\n  }\n  return ret;\n}\ntemplate <class mint>\nvector<mint>\
    \ multiply(const vector<mint> &a, const vector<mint> &b){\n  if(a.size() == 0\
    \ && b.size() == 0) return {};\n  if(min<int>(a.size(), b.size()) < 128){\n  \
    \  vector<mint> ret(a.size() + b.size() - 1);\n    for(int i = 0; i < (int)a.size();\
    \ i++)\n      for(int j = 0; j < (int)b.size(); j++) ret[i + j] += a[i] * b[j];\n\
    \    return ret;\n  }\n  vector<int> s(a.size()), t(b.size());\n  for(int i =\
    \ 0; i < (int)a.size(); i++) s[i] = a[i].x;\n  for(int i = 0; i < (int)b.size();\
    \ i++) t[i] = b[i].x;\n  vector<int> u = multiply<int>(s, t, mint::get_mod());\n\
    \  vector<mint> ret(u.size());\n  for(int i = 0; i < (int)u.size(); i++) ret[i]\
    \ = mint(u[i]);\n  return ret;\n}\nvector<ll> multiply_ll(const vector<ll> &s,\
    \ const vector<ll> &t){\n  const auto d0 = mul<ll, mint0>(s, t);\n  const auto\
    \ d1 = mul<ll, mint1>(s, t);\n  const auto d2 = mul<ll, mint2>(s, t);\n  const\
    \ int n = d0.size();\n  vector<ll> ret(n);\n  const ll W1 = w1;\n  const ll W2\
    \ = w2;\n  for(int i = 0; i < n; i++){\n    const ll n1 = d1[i].x, n2 = d2[i].x,\
    \ a = d0[i].x;\n    const ll b = ll(n1 + m1 - a) * r01 % m1;\n    const ll c =\
    \ (ll(n2 + m2 - a) * r02r12 + ll(m2 - b) * r12) % m2;\n    ret[i] = (ll(a) + ll(b)\
    \ * W1 + ll(c) * W2);\n  }\n  return ret;\n}\n} // namespace ArbitraryNTT\ntemplate\
    \ <class mint>\nvector<mint> convolution(const vector<mint> &a, const vector<mint>\
    \ &b){\n  return ArbitraryNTT::multiply(a, b);\n}\nvector<ll> convolution_ll(const\
    \ vector<ll> &a, const vector<ll> &b){\n  return ArbitraryNTT::multiply_ll(a,\
    \ b);\n}"
  dependsOn:
  - math/convolution/ntt.hpp
  - math/mint.hpp
  isVerificationFile: false
  path: math/convolution/convolution-arbitrary-mod.cpp
  requiredBy: []
  timestamp: '2022-09-15 18:24:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/convolution-arbitrary-mod.cpp
layout: document
redirect_from:
- /library/math/convolution/convolution-arbitrary-mod.cpp
- /library/math/convolution/convolution-arbitrary-mod.cpp.html
title: math/convolution/convolution-arbitrary-mod.cpp
---
