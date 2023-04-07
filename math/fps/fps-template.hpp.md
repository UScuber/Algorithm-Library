---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/ntt.hpp
    title: math/convolution/ntt.hpp
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: math/mint.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/fps/fps-arbitrary-mod.hpp
    title: math/fps/fps-arbitrary-mod.hpp
  - icon: ':heavy_check_mark:'
    path: math/fps/fps.hpp
    title: math/fps/fps.hpp
  - icon: ':heavy_check_mark:'
    path: math/fps/kitamasa.hpp
    title: math/fps/kitamasa.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Convolution/Convolution(Mod1e9+7)2.test.cpp
    title: test/yosupo/Convolution/Convolution(Mod1e9+7)2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Kth-term-of-Linearly-Recurrent-Sequence.test.cpp
    title: test/yosupo/Math/Kth-term-of-Linearly-Recurrent-Sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Subset-Sum.test.cpp
    title: test/yosupo/Math/Subset-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
    title: test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/convolution/ntt.hpp\"\ntemplate <class mint>\r\nstruct\
    \ NTT {\r\n  static constexpr uint32_t get_pr(){\r\n    const uint32_t _mod =\
    \ mint::get_mod();\r\n    using u64 = uint64_t;\r\n    u64 ds[32] = {};\r\n  \
    \  int idx = 0;\r\n    u64 m = _mod - 1;\r\n    for(u64 i = 2; i * i <= m; i++){\r\
    \n      if(m % i == 0){\r\n        ds[idx++] = i;\r\n        while(m % i == 0)\
    \ m /= i;\r\n      }\r\n    }\r\n    if(m != 1) ds[idx++] = m;\r\n    uint32_t\
    \ _pr = 2;\r\n    while(true){\r\n      int flg = 1;\r\n      for(int i = 0; i\
    \ < idx; i++){\r\n        u64 a = _pr, b = (_mod - 1) / ds[i], r = 1;\r\n    \
    \    while(b){\r\n          if(b & 1) r = r * a % _mod;\r\n          a = a * a\
    \ % _mod;\r\n          b >>= 1;\r\n        }\r\n        if(r == 1){\r\n      \
    \    flg = 0;\r\n          break;\r\n        }\r\n      }\r\n      if(flg == 1)\
    \ break;\r\n      _pr++;\r\n    }\r\n    return _pr;\r\n  };\r\n  static constexpr\
    \ uint32_t mod = mint::get_mod();\r\n  static constexpr uint32_t pr = get_pr();\r\
    \n  static constexpr int level = __builtin_ctzll(mod - 1);\r\n  mint dw[level],\
    \ dy[level];\r\n  void setwy(const int k){\r\n    mint w[level], y[level];\r\n\
    \    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\r\n    y[k - 1] = w[k - 1].inv();\r\
    \n    for(int i = k - 2; i > 0; i--)\r\n      w[i] = w[i + 1] * w[i + 1], y[i]\
    \ = y[i + 1] * y[i + 1];\r\n    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2]\
    \ = y[2];\r\n    for(int i = 3; i < k; i++){\r\n      dw[i] = dw[i - 1] * y[i\
    \ - 2] * w[i];\r\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\r\n    }\r\n  }\r\
    \n  NTT(){ setwy(level); }\r\n  void fft4(vector<mint> &a, const int k){\r\n \
    \   if((int)a.size() <= 1) return;\r\n    if(k == 1){\r\n      mint a1 = a[1];\r\
    \n      a[1] = a[0] - a[1];\r\n      a[0] = a[0] + a1;\r\n      return;\r\n  \
    \  }\r\n    if(k & 1){\r\n      int v = 1 << (k - 1);\r\n      for(int j = 0;\
    \ j < v; j++) {\r\n        mint ajv = a[j + v];\r\n        a[j + v] = a[j] - ajv;\r\
    \n        a[j] += ajv;\r\n      }\r\n    }\r\n    int u = 1 << (2 + (k & 1));\r\
    \n    int v = 1 << (k - 2 - (k & 1));\r\n    const mint one = mint(1);\r\n   \
    \ mint imag = dw[1];\r\n    while(v) {\r\n      // jh = 0\r\n      {\r\n     \
    \   int j0 = 0;\r\n        int j1 = v;\r\n        int j2 = j1 + v;\r\n       \
    \ int j3 = j2 + v;\r\n        for(; j0 < v; j0++, j1++, j2++, j3++){\r\n     \
    \     const mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\r\n         \
    \ const mint t0p2 = t0 + t2, t1p3 = t1 + t3;\r\n          const mint t0m2 = t0\
    \ - t2, t1m3 = (t1 - t3) * imag;\r\n          a[j0] = t0p2 + t1p3, a[j1] = t0p2\
    \ - t1p3;\r\n          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\r\n        }\r\
    \n      }\r\n      // jh >= 1\r\n      mint ww = one, xx = one * dw[2], wx = one;\r\
    \n      for(int jh = 4; jh < u;){\r\n        ww = xx * xx, wx = ww * xx;\r\n \
    \       int j0 = jh * v;\r\n        int je = j0 + v;\r\n        int j2 = je +\
    \ v;\r\n        for(; j0 < je; j0++, j2++){\r\n          const mint t0 = a[j0],\
    \ t1 = a[j0 + v] * xx, t2 = a[j2] * ww, t3 = a[j2 + v] * wx;\r\n          const\
    \ mint t0p2 = t0 + t2, t1p3 = t1 + t3;\r\n          const mint t0m2 = t0 - t2,\
    \ t1m3 = (t1 - t3) * imag;\r\n          a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2\
    \ - t1p3;\r\n          a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;\r\n     \
    \   }\r\n        xx *= dw[__builtin_ctzll((jh += 4))];\r\n      }\r\n      u <<=\
    \ 2;\r\n      v >>= 2;\r\n    }\r\n  }\r\n  void ifft4(vector<mint> &a, const\
    \ int k){\r\n    if((int)a.size() <= 1) return;\r\n    if(k == 1){\r\n      mint\
    \ a1 = a[1];\r\n      a[1] = a[0] - a[1];\r\n      a[0] = a[0] + a1;\r\n     \
    \ return;\r\n    }\r\n    int u = 1 << (k - 2);\r\n    int v = 1;\r\n    const\
    \ mint one = mint(1);\r\n    mint imag = dy[1];\r\n    while(u){\r\n      // jh\
    \ = 0\r\n      {\r\n        int j0 = 0;\r\n        int j1 = v;\r\n        int\
    \ j2 = v + v;\r\n        int j3 = j2 + v;\r\n        for(; j0 < v; j0++, j1++,\
    \ j2++, j3++){\r\n          const mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3\
    \ = a[j3];\r\n          const mint t0p1 = t0 + t1, t2p3 = t2 + t3;\r\n       \
    \   const mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;\r\n          a[j0] = t0p1\
    \ + t2p3, a[j2] = t0p1 - t2p3;\r\n          a[j1] = t0m1 + t2m3, a[j3] = t0m1\
    \ - t2m3;\r\n        }\r\n      }\r\n      // jh >= 1\r\n      mint ww = one,\
    \ xx = one * dy[2], yy = one;\r\n      u <<= 2;\r\n      for(int jh = 4; jh <\
    \ u;){\r\n        ww = xx * xx, yy = xx * imag;\r\n        int j0 = jh * v;\r\n\
    \        int je = j0 + v;\r\n        int j2 = je + v;\r\n        for(; j0 < je;\
    \ j0++, j2++){\r\n          const mint t0 = a[j0], t1 = a[j0 + v], t2 = a[j2],\
    \ t3 = a[j2 + v];\r\n          const mint t0p1 = t0 + t1, t2p3 = t2 + t3;\r\n\
    \          const mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\r\n      \
    \    a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;\r\n          a[j0 + v] =\
    \ t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;\r\n        }\r\n        xx *= dy[__builtin_ctzll(jh\
    \ += 4)];\r\n      }\r\n      u >>= 4;\r\n      v <<= 2;\r\n    }\r\n    if(k\
    \ & 1){\r\n      u = 1 << (k - 1);\r\n      for(int j = 0; j < u; j++){\r\n  \
    \      mint ajv = a[j] - a[j + u];\r\n        a[j] += a[j + u];\r\n        a[j\
    \ + u] = ajv;\r\n      }\r\n    }\r\n  }\r\n  void ntt(vector<mint> &a){\r\n \
    \   if((int)a.size() <= 1) return;\r\n    fft4(a, __builtin_ctz(a.size()));\r\n\
    \  }\r\n  void intt(vector<mint> &a){\r\n    if((int)a.size() <= 1) return;\r\n\
    \    ifft4(a, __builtin_ctz(a.size()));\r\n    const mint iv = mint(a.size()).inv();\r\
    \n    for(auto &x : a) x *= iv;\r\n  }\r\n  vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b){\r\n    const int l = a.size() + b.size() - 1;\r\n\
    \    if(min<int>(a.size(), b.size()) <= 40){\r\n      vector<mint> s(l);\r\n \
    \     for(int i = 0; i < (int)a.size(); i++)\r\n        for(int j = 0; j < (int)b.size();\
    \ j++) s[i + j] += a[i] * b[j];\r\n      return s;\r\n    }\r\n    int k = 2,\
    \ M = 4;\r\n    while(M < l) M <<= 1, k++;\r\n    setwy(k);\r\n    vector<mint>\
    \ s(M), t(M);\r\n    for(int i = 0; i < (int)a.size(); i++) s[i] = a[i];\r\n \
    \   for(int i = 0; i < (int)b.size(); i++) t[i] = b[i];\r\n    fft4(s, k);\r\n\
    \    fft4(t, k);\r\n    for(int i = 0; i < M; i++) s[i] *= t[i];\r\n    ifft4(s,\
    \ k);\r\n    s.resize(l);\r\n    const mint invm = mint(M).inv();\r\n    for(int\
    \ i = 0; i < l; i++) s[i] *= invm;\r\n    return s;\r\n  }\r\n  void ntt_doubling(vector<mint>\
    \ &a){\r\n    const int M = (int)a.size();\r\n    auto b = a;\r\n    intt(b);\r\
    \n    mint r = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\r\n \
    \   for(int i = 0; i < M; i++) b[i] *= r, r *= zeta;\r\n    ntt(b);\r\n    copy(begin(b),\
    \ end(b), back_inserter(a));\r\n  }\r\n};\n#line 2 \"math/mint.hpp\"\n\r\ntemplate\
    \ <int mod>\r\nstruct Mint {\r\n  ll x;\r\n  constexpr Mint(ll x = 0) : x((x +\
    \ mod) % mod){}\r\n  static constexpr int get_mod(){ return mod; }\r\n  constexpr\
    \ Mint operator-() const{ return Mint(-x); }\r\n  constexpr Mint operator+=(const\
    \ Mint &a){\r\n    if((x += a.x) >= mod) x -= mod;\r\n    return *this;\r\n  }\r\
    \n  constexpr Mint &operator++(){\r\n    if(++x == mod) x = 0;\r\n    return *this;\r\
    \n  }\r\n  constexpr Mint operator++(int){\r\n    Mint temp = *this;\r\n    if(++x\
    \ == mod) x = 0;\r\n    return temp;\r\n  }\r\n  constexpr Mint &operator-=(const\
    \ Mint &a){\r\n    if((x -= a.x) < 0) x += mod;\r\n    return *this;\r\n  }\r\n\
    \  constexpr Mint &operator--(){\r\n    if(--x < 0) x += mod;\r\n    return *this;\r\
    \n  }\r\n  constexpr Mint operator--(int){\r\n    Mint temp = *this;\r\n    if(--x\
    \ < 0) x += mod;\r\n    return temp;\r\n  }\r\n  constexpr Mint &operator*=(const\
    \ Mint &a){\r\n    (x *= a.x) %= mod;\r\n    return *this;\r\n  }\r\n  constexpr\
    \ Mint operator+(const Mint &a) const{ return Mint(*this) += a; }\r\n  constexpr\
    \ Mint operator-(const Mint &a) const{ return Mint(*this) -= a; }\r\n  constexpr\
    \ Mint operator*(const Mint &a) const{ return Mint(*this) *= a; }\r\n  constexpr\
    \ Mint pow(ll t) const{\r\n    if(!t) return 1;\r\n    Mint res = 1, v = *this;\r\
    \n    while(t){\r\n      if(t & 1) res *= v;\r\n      v *= v;\r\n      t >>= 1;\r\
    \n    }\r\n    return res;\r\n  }\r\n  constexpr Mint inv() const{ return pow(mod\
    \ - 2); }\r\n  constexpr Mint &operator/=(const Mint &a){ return (*this) *= a.inv();\
    \ }\r\n  constexpr Mint operator/(const Mint &a) const{ return Mint(*this) /=\
    \ a; }\r\n  constexpr bool operator==(const Mint &a) const{ return x == a.x; }\r\
    \n  constexpr bool operator!=(const Mint &a) const{ return x != a.x; }\r\n  constexpr\
    \ bool operator<(const Mint &a) const{ return x < a.x; }\r\n  constexpr bool operator>(const\
    \ Mint &a) const{ return x > a.x; }\r\n  friend istream &operator>>(istream &is,\
    \ Mint &a){ return is >> a.x; }\r\n  friend ostream &operator<<(ostream &os, const\
    \ Mint &a){ return os << a.x; }\r\n};\r\n//using mint = Mint<1000000007>;\n#line\
    \ 3 \"math/fps/fps-template.hpp\"\n\r\ntemplate <class mint>\r\nstruct FPS : vector<mint>\
    \ {\r\n  using vector<mint>::vector;\r\n  FPS &operator+=(const FPS &r){\r\n \
    \   if(r.size() > this->size()) this->resize(r.size());\r\n    for(int i = 0;\
    \ i < (int)r.size(); i++) (*this)[i] += r[i];\r\n    return *this;\r\n  }\r\n\
    \  FPS &operator+=(const mint &r){\r\n    if(this->empty()) this->resize(1);\r\
    \n    (*this)[0] += r;\r\n    return *this;\r\n  }\r\n  FPS &operator-=(const\
    \ FPS &r){\r\n    if(r.size() > this->size()) this->resize(r.size());\r\n    for(int\
    \ i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\r\n    return *this;\r\n\
    \  }\r\n  FPS &operator-=(const mint &r){\r\n    if(this->empty()) this->resize(1);\r\
    \n    (*this)[0] -= r;\r\n    return *this;\r\n  }\r\n  FPS &operator*=(const\
    \ mint &v){\r\n    for(int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;\r\
    \n    return *this;\r\n  }\r\n  FPS &operator/=(const FPS &r){\r\n    if(this->size()\
    \ < r.size()){\r\n      this->clear();\r\n      return *this;\r\n    }\r\n   \
    \ const int n = this->size() - r.size() + 1;\r\n    if((int)r.size() <= 64){\r\
    \n      FPS f(*this), g(r);\r\n      g.shrink();\r\n      const mint coeff = g.back().inv();\r\
    \n      for(auto &x : g) x *= coeff;\r\n      const int deg = (int)f.size() -\
    \ (int)g.size() + 1;\r\n      const int gs = g.size();\r\n      FPS quo(deg);\r\
    \n      for(int i = deg - 1; i >= 0; i--){\r\n        quo[i] = f[i + gs - 1];\r\
    \n        for(int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];\r\n      }\r\n\
    \      *this = quo * coeff;\r\n      this->resize(n, mint(0));\r\n      return\
    \ *this;\r\n    }\r\n    return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\r\
    \n  }\r\n  FPS &operator%=(const FPS &r){\r\n    *this -= *this / r * r;\r\n \
    \   shrink();\r\n    return *this;\r\n  }\r\n  FPS operator+(const FPS &r) const{\
    \ return FPS(*this) += r; }\r\n  FPS operator+(const mint &v) const{ return FPS(*this)\
    \ += v; }\r\n  FPS operator-(const FPS &r) const{ return FPS(*this) -= r; }\r\n\
    \  FPS operator-(const mint &v) const{ return FPS(*this) -= v; }\r\n  FPS operator*(const\
    \ FPS &r) const{ return FPS(*this) *= r; }\r\n  FPS operator*(const mint &v) const{\
    \ return FPS(*this) *= v; }\r\n  FPS operator/(const FPS &r) const{ return FPS(*this)\
    \ /= r; }\r\n  FPS operator%(const FPS &r) const{ return FPS(*this) %= r; }\r\n\
    \  FPS operator-() const{\r\n    FPS ret(this->size());\r\n    for(int i = 0;\
    \ i < (int)this->size(); i++) ret[i] = -(*this)[i];\r\n    return ret;\r\n  }\r\
    \n  void shrink(){\r\n    while(this->size() && this->back() == mint(0)) this->pop_back();\r\
    \n  }\r\n  FPS rev() const{\r\n    FPS ret(*this);\r\n    reverse(begin(ret),\
    \ end(ret));\r\n    return ret;\r\n  }\r\n  FPS dot(FPS r) const{\r\n    FPS ret(min(this->size(),\
    \ r.size()));\r\n    for(int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\r\n    return ret;\r\n  }\r\n  FPS pre(int sz) const{\r\n    return\
    \ FPS(begin(*this), begin(*this) + min((int)this->size(), sz));\r\n  }\r\n  FPS\
    \ operator>>(int sz) const{\r\n    if((int)this->size() <= sz) return {};\r\n\
    \    FPS ret(*this);\r\n    ret.erase(ret.begin(), ret.begin() + sz);\r\n    return\
    \ ret;\r\n  }\r\n  FPS operator<<(int sz) const{\r\n    FPS ret(*this);\r\n  \
    \  ret.insert(ret.begin(), sz, mint(0));\r\n    return ret;\r\n  }\r\n  FPS diff()\
    \ const{\r\n    const int n = (int)this->size();\r\n    FPS ret(max(0, n - 1));\r\
    \n    mint one(1), coeff(1);\r\n    for(int i = 1; i < n; i++){\r\n      ret[i\
    \ - 1] = (*this)[i] * coeff;\r\n      coeff += one;\r\n    }\r\n    return ret;\r\
    \n  }\r\n  FPS integral() const{\r\n    const int n = (int)this->size();\r\n \
    \   FPS ret(n + 1);\r\n    ret[0] = mint(0);\r\n    if(n > 0) ret[1] = mint(1);\r\
    \n    auto mod = mint::get_mod();\r\n    for(int i = 2; i <= n; i++) ret[i] =\
    \ (-ret[mod % i]) * (mod / i);\r\n    for(int i = 0; i < n; i++) ret[i + 1] *=\
    \ (*this)[i];\r\n    return ret;\r\n  }\r\n  mint eval(mint x) const{\r\n    mint\
    \ r = 0, w = 1;\r\n    for(auto &v : *this) r += w * v, w *= x;\r\n    return\
    \ r;\r\n  }\r\n  FPS log(int deg = -1) const{\r\n    assert((*this)[0] == mint(1));\r\
    \n    if(deg == -1) deg = (int)this->size();\r\n    return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\r\n  }\r\n  FPS pow(int64_t k, int deg = -1) const{\r\n   \
    \ const int n = (int)this->size();\r\n    if(deg == -1) deg = n;\r\n    if(k ==\
    \ 0){\r\n      FPS ret(deg);\r\n      if(deg) ret[0] = 1;\r\n      return ret;\r\
    \n    }\r\n    for(int i = 0; i < n; i++){\r\n      if((*this)[i] != mint(0)){\r\
    \n        const mint rev = mint(1) / (*this)[i];\r\n        FPS ret = (((*this\
    \ * rev) >> i).log(deg) * k).exp(deg);\r\n        ret *= (*this)[i].pow(k);\r\n\
    \        ret = (ret << (i * k)).pre(deg);\r\n        if((int)ret.size() < deg)\
    \ ret.resize(deg, mint(0));\r\n        return ret;\r\n      }\r\n      if(__int128_t(i\
    \ + 1) * k >= deg) return FPS(deg, mint(0));\r\n    }\r\n    return FPS(deg, mint(0));\r\
    \n  }\r\n  static void *ntt_ptr;\r\n  static void set_fft();\r\n  FPS &operator*=(const\
    \ FPS &r);\r\n  void ntt();\r\n  void intt();\r\n  void ntt_doubling();\r\n  static\
    \ int ntt_pr();\r\n  FPS inv(int deg = -1) const;\r\n  FPS exp(int deg = -1) const;\r\
    \n};\r\ntemplate <class mint>\r\nvoid *FPS<mint>::ntt_ptr = nullptr;\n"
  code: "#include \"../convolution/ntt.hpp\"\r\n#include \"../mint.hpp\"\r\n\r\ntemplate\
    \ <class mint>\r\nstruct FPS : vector<mint> {\r\n  using vector<mint>::vector;\r\
    \n  FPS &operator+=(const FPS &r){\r\n    if(r.size() > this->size()) this->resize(r.size());\r\
    \n    for(int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\r\n    return\
    \ *this;\r\n  }\r\n  FPS &operator+=(const mint &r){\r\n    if(this->empty())\
    \ this->resize(1);\r\n    (*this)[0] += r;\r\n    return *this;\r\n  }\r\n  FPS\
    \ &operator-=(const FPS &r){\r\n    if(r.size() > this->size()) this->resize(r.size());\r\
    \n    for(int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];\r\n    return\
    \ *this;\r\n  }\r\n  FPS &operator-=(const mint &r){\r\n    if(this->empty())\
    \ this->resize(1);\r\n    (*this)[0] -= r;\r\n    return *this;\r\n  }\r\n  FPS\
    \ &operator*=(const mint &v){\r\n    for(int k = 0; k < (int)this->size(); k++)\
    \ (*this)[k] *= v;\r\n    return *this;\r\n  }\r\n  FPS &operator/=(const FPS\
    \ &r){\r\n    if(this->size() < r.size()){\r\n      this->clear();\r\n      return\
    \ *this;\r\n    }\r\n    const int n = this->size() - r.size() + 1;\r\n    if((int)r.size()\
    \ <= 64){\r\n      FPS f(*this), g(r);\r\n      g.shrink();\r\n      const mint\
    \ coeff = g.back().inv();\r\n      for(auto &x : g) x *= coeff;\r\n      const\
    \ int deg = (int)f.size() - (int)g.size() + 1;\r\n      const int gs = g.size();\r\
    \n      FPS quo(deg);\r\n      for(int i = deg - 1; i >= 0; i--){\r\n        quo[i]\
    \ = f[i + gs - 1];\r\n        for(int j = 0; j < gs; j++) f[i + j] -= quo[i] *\
    \ g[j];\r\n      }\r\n      *this = quo * coeff;\r\n      this->resize(n, mint(0));\r\
    \n      return *this;\r\n    }\r\n    return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\r\
    \n  }\r\n  FPS &operator%=(const FPS &r){\r\n    *this -= *this / r * r;\r\n \
    \   shrink();\r\n    return *this;\r\n  }\r\n  FPS operator+(const FPS &r) const{\
    \ return FPS(*this) += r; }\r\n  FPS operator+(const mint &v) const{ return FPS(*this)\
    \ += v; }\r\n  FPS operator-(const FPS &r) const{ return FPS(*this) -= r; }\r\n\
    \  FPS operator-(const mint &v) const{ return FPS(*this) -= v; }\r\n  FPS operator*(const\
    \ FPS &r) const{ return FPS(*this) *= r; }\r\n  FPS operator*(const mint &v) const{\
    \ return FPS(*this) *= v; }\r\n  FPS operator/(const FPS &r) const{ return FPS(*this)\
    \ /= r; }\r\n  FPS operator%(const FPS &r) const{ return FPS(*this) %= r; }\r\n\
    \  FPS operator-() const{\r\n    FPS ret(this->size());\r\n    for(int i = 0;\
    \ i < (int)this->size(); i++) ret[i] = -(*this)[i];\r\n    return ret;\r\n  }\r\
    \n  void shrink(){\r\n    while(this->size() && this->back() == mint(0)) this->pop_back();\r\
    \n  }\r\n  FPS rev() const{\r\n    FPS ret(*this);\r\n    reverse(begin(ret),\
    \ end(ret));\r\n    return ret;\r\n  }\r\n  FPS dot(FPS r) const{\r\n    FPS ret(min(this->size(),\
    \ r.size()));\r\n    for(int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i]\
    \ * r[i];\r\n    return ret;\r\n  }\r\n  FPS pre(int sz) const{\r\n    return\
    \ FPS(begin(*this), begin(*this) + min((int)this->size(), sz));\r\n  }\r\n  FPS\
    \ operator>>(int sz) const{\r\n    if((int)this->size() <= sz) return {};\r\n\
    \    FPS ret(*this);\r\n    ret.erase(ret.begin(), ret.begin() + sz);\r\n    return\
    \ ret;\r\n  }\r\n  FPS operator<<(int sz) const{\r\n    FPS ret(*this);\r\n  \
    \  ret.insert(ret.begin(), sz, mint(0));\r\n    return ret;\r\n  }\r\n  FPS diff()\
    \ const{\r\n    const int n = (int)this->size();\r\n    FPS ret(max(0, n - 1));\r\
    \n    mint one(1), coeff(1);\r\n    for(int i = 1; i < n; i++){\r\n      ret[i\
    \ - 1] = (*this)[i] * coeff;\r\n      coeff += one;\r\n    }\r\n    return ret;\r\
    \n  }\r\n  FPS integral() const{\r\n    const int n = (int)this->size();\r\n \
    \   FPS ret(n + 1);\r\n    ret[0] = mint(0);\r\n    if(n > 0) ret[1] = mint(1);\r\
    \n    auto mod = mint::get_mod();\r\n    for(int i = 2; i <= n; i++) ret[i] =\
    \ (-ret[mod % i]) * (mod / i);\r\n    for(int i = 0; i < n; i++) ret[i + 1] *=\
    \ (*this)[i];\r\n    return ret;\r\n  }\r\n  mint eval(mint x) const{\r\n    mint\
    \ r = 0, w = 1;\r\n    for(auto &v : *this) r += w * v, w *= x;\r\n    return\
    \ r;\r\n  }\r\n  FPS log(int deg = -1) const{\r\n    assert((*this)[0] == mint(1));\r\
    \n    if(deg == -1) deg = (int)this->size();\r\n    return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\r\n  }\r\n  FPS pow(int64_t k, int deg = -1) const{\r\n   \
    \ const int n = (int)this->size();\r\n    if(deg == -1) deg = n;\r\n    if(k ==\
    \ 0){\r\n      FPS ret(deg);\r\n      if(deg) ret[0] = 1;\r\n      return ret;\r\
    \n    }\r\n    for(int i = 0; i < n; i++){\r\n      if((*this)[i] != mint(0)){\r\
    \n        const mint rev = mint(1) / (*this)[i];\r\n        FPS ret = (((*this\
    \ * rev) >> i).log(deg) * k).exp(deg);\r\n        ret *= (*this)[i].pow(k);\r\n\
    \        ret = (ret << (i * k)).pre(deg);\r\n        if((int)ret.size() < deg)\
    \ ret.resize(deg, mint(0));\r\n        return ret;\r\n      }\r\n      if(__int128_t(i\
    \ + 1) * k >= deg) return FPS(deg, mint(0));\r\n    }\r\n    return FPS(deg, mint(0));\r\
    \n  }\r\n  static void *ntt_ptr;\r\n  static void set_fft();\r\n  FPS &operator*=(const\
    \ FPS &r);\r\n  void ntt();\r\n  void intt();\r\n  void ntt_doubling();\r\n  static\
    \ int ntt_pr();\r\n  FPS inv(int deg = -1) const;\r\n  FPS exp(int deg = -1) const;\r\
    \n};\r\ntemplate <class mint>\r\nvoid *FPS<mint>::ntt_ptr = nullptr;"
  dependsOn:
  - math/convolution/ntt.hpp
  - math/mint.hpp
  isVerificationFile: false
  path: math/fps/fps-template.hpp
  requiredBy:
  - math/fps/fps.hpp
  - math/fps/kitamasa.hpp
  - math/fps/fps-arbitrary-mod.hpp
  timestamp: '2023-03-13 14:46:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Convolution/Convolution(Mod1e9+7)2.test.cpp
  - test/yosupo/Math/Kth-term-of-Linearly-Recurrent-Sequence.test.cpp
  - test/yosupo/Math/Subset-Sum.test.cpp
  - test/yosupo/Polynomial/Pow-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Log-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Inv-of-Formal-Power-Series.test.cpp
  - test/yosupo/Polynomial/Exp-of-Formal-Power-Series.test.cpp
documentation_of: math/fps/fps-template.hpp
layout: document
redirect_from:
- /library/math/fps/fps-template.hpp
- /library/math/fps/fps-template.hpp.html
title: math/fps/fps-template.hpp
---
