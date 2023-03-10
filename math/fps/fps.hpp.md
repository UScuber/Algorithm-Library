---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/convolution/ntt.hpp
    title: math/convolution/ntt.hpp
  - icon: ':warning:'
    path: math/fps/fps-template.hpp
    title: math/fps/fps-template.hpp
  - icon: ':warning:'
    path: math/mint.hpp
    title: math/mint.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/fps/kitamasa.cpp
    title: math/fps/kitamasa.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
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
    \ return os << a.x; }\n};\nusing mint = Mint<1000000007>;\n#line 3 \"math/fps/fps-template.hpp\"\
    \n\ntemplate <class mint>\nstruct FPS : vector<mint> {\n  using vector<mint>::vector;\n\
    \  FPS &operator+=(const FPS &r){\n    if(r.size() > this->size()) this->resize(r.size());\n\
    \    for(int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];\n    return *this;\n\
    \  }\n  FPS &operator+=(const mint &r){\n    if(this->empty()) this->resize(1);\n\
    \    (*this)[0] += r;\n    return *this;\n  }\n  FPS &operator-=(const FPS &r){\n\
    \    if(r.size() > this->size()) this->resize(r.size());\n    for(int i = 0; i\
    \ < (int)r.size(); i++) (*this)[i] -= r[i];\n    return *this;\n  }\n  FPS &operator-=(const\
    \ mint &r){\n    if(this->empty()) this->resize(1);\n    (*this)[0] -= r;\n  \
    \  return *this;\n  }\n  FPS &operator*=(const mint &v){\n    for(int k = 0; k\
    \ < (int)this->size(); k++) (*this)[k] *= v;\n    return *this;\n  }\n  FPS &operator/=(const\
    \ FPS &r){\n    if(this->size() < r.size()){\n      this->clear();\n      return\
    \ *this;\n    }\n    const int n = this->size() - r.size() + 1;\n    if((int)r.size()\
    \ <= 64){\n      FPS f(*this), g(r);\n      g.shrink();\n      const mint coeff\
    \ = g.back().inv();\n      for(auto &x : g) x *= coeff;\n      const int deg =\
    \ (int)f.size() - (int)g.size() + 1;\n      const int gs = g.size();\n      FPS\
    \ quo(deg);\n      for(int i = deg - 1; i >= 0; i--){\n        quo[i] = f[i +\
    \ gs - 1];\n        for(int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];\n \
    \     }\n      *this = quo * coeff;\n      this->resize(n, mint(0));\n      return\
    \ *this;\n    }\n    return *this = ((*this).rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \  }\n  FPS &operator%=(const FPS &r){\n    *this -= *this / r * r;\n    shrink();\n\
    \    return *this;\n  }\n  FPS operator+(const FPS &r) const{ return FPS(*this)\
    \ += r; }\n  FPS operator+(const mint &v) const{ return FPS(*this) += v; }\n \
    \ FPS operator-(const FPS &r) const{ return FPS(*this) -= r; }\n  FPS operator-(const\
    \ mint &v) const{ return FPS(*this) -= v; }\n  FPS operator*(const FPS &r) const{\
    \ return FPS(*this) *= r; }\n  FPS operator*(const mint &v) const{ return FPS(*this)\
    \ *= v; }\n  FPS operator/(const FPS &r) const{ return FPS(*this) /= r; }\n  FPS\
    \ operator%(const FPS &r) const{ return FPS(*this) %= r; }\n  FPS operator-()\
    \ const{\n    FPS ret(this->size());\n    for(int i = 0; i < (int)this->size();\
    \ i++) ret[i] = -(*this)[i];\n    return ret;\n  }\n  void shrink(){\n    while(this->size()\
    \ && this->back() == mint(0)) this->pop_back();\n  }\n  FPS rev() const{\n   \
    \ FPS ret(*this);\n    reverse(begin(ret), end(ret));\n    return ret;\n  }\n\
    \  FPS dot(FPS r) const{\n    FPS ret(min(this->size(), r.size()));\n    for(int\
    \ i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];\n    return ret;\n\
    \  }\n  FPS pre(int sz) const{\n    return FPS(begin(*this), begin(*this) + min((int)this->size(),\
    \ sz));\n  }\n  FPS operator>>(int sz) const{\n    if((int)this->size() <= sz)\
    \ return {};\n    FPS ret(*this);\n    ret.erase(ret.begin(), ret.begin() + sz);\n\
    \    return ret;\n  }\n  FPS operator<<(int sz) const{\n    FPS ret(*this);\n\
    \    ret.insert(ret.begin(), sz, mint(0));\n    return ret;\n  }\n  FPS diff()\
    \ const{\n    const int n = (int)this->size();\n    FPS ret(max(0, n - 1));\n\
    \    mint one(1), coeff(1);\n    for(int i = 1; i < n; i++){\n      ret[i - 1]\
    \ = (*this)[i] * coeff;\n      coeff += one;\n    }\n    return ret;\n  }\n  FPS\
    \ integral() const{\n    const int n = (int)this->size();\n    FPS ret(n + 1);\n\
    \    ret[0] = mint(0);\n    if(n > 0) ret[1] = mint(1);\n    auto mod = mint::get_mod();\n\
    \    for(int i = 2; i <= n; i++) ret[i] = (-ret[mod % i]) * (mod / i);\n    for(int\
    \ i = 0; i < n; i++) ret[i + 1] *= (*this)[i];\n    return ret;\n  }\n  mint eval(mint\
    \ x) const{\n    mint r = 0, w = 1;\n    for(auto &v : *this) r += w * v, w *=\
    \ x;\n    return r;\n  }\n  FPS log(int deg = -1) const{\n    assert((*this)[0]\
    \ == mint(1));\n    if(deg == -1) deg = (int)this->size();\n    return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n  }\n  FPS pow(int64_t k, int deg\
    \ = -1) const{\n    const int n = (int)this->size();\n    if(deg == -1) deg =\
    \ n;\n    if(k == 0){\n      FPS ret(deg);\n      if(deg) ret[0] = 1;\n      return\
    \ ret;\n    }\n    for(int i = 0; i < n; i++){\n      if((*this)[i] != mint(0)){\n\
    \        const mint rev = mint(1) / (*this)[i];\n        FPS ret = (((*this *\
    \ rev) >> i).log(deg) * k).exp(deg);\n        ret *= (*this)[i].pow(k);\n    \
    \    ret = (ret << (i * k)).pre(deg);\n        if((int)ret.size() < deg) ret.resize(deg,\
    \ mint(0));\n        return ret;\n      }\n      if(__int128_t(i + 1) * k >= deg)\
    \ return FPS(deg, mint(0));\n    }\n    return FPS(deg, mint(0));\n  }\n  static\
    \ void *ntt_ptr;\n  static void set_fft();\n  FPS &operator*=(const FPS &r);\n\
    \  void ntt();\n  void intt();\n  void ntt_doubling();\n  static int ntt_pr();\n\
    \  FPS inv(int deg = -1) const;\n  FPS exp(int deg = -1) const;\n};\ntemplate\
    \ <class mint>\nvoid *FPS<mint>::ntt_ptr = nullptr;\n#line 2 \"math/fps/fps.hpp\"\
    \n\ntemplate <class mint>\nvoid FPS<mint>::set_fft(){ if(!ntt_ptr) ntt_ptr = new\
    \ NTT<mint>; }\ntemplate <class mint>\nFPS<mint> &FPS<mint>::operator*=(const\
    \ FPS<mint> &r){\n  if(this->empty() || r.empty()){\n    this->clear();\n    return\
    \ *this;\n  }\n  set_fft();\n  const auto ret = static_cast<NTT<mint>*>(ntt_ptr)->multiply(*this,\
    \ r);\n  return *this = FPS<mint>(ret.begin(), ret.end());\n}\ntemplate <class\
    \ mint>\nvoid FPS<mint>::ntt(){\n  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->ntt(*this);\n\
    }\ntemplate <class mint>\nvoid FPS<mint>::intt(){\n  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->intt(*this);\n\
    }\ntemplate <class mint>\nvoid FPS<mint>::ntt_doubling(){\n  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->ntt_doubling(*this);\n\
    }\ntemplate <class mint>\nint FPS<mint>::ntt_pr(){\n  set_fft();\n  return static_cast<NTT<mint>*>(ntt_ptr)->pr;\n\
    }\ntemplate <class mint>\nFPS<mint> FPS<mint>::inv(int deg) const{\n  assert((*this)[0]\
    \ != mint(0));\n  if(deg == -1) deg = (int)this->size();\n  FPS<mint> res(deg);\n\
    \  res[0] = { mint(1) / (*this)[0] };\n  for(int d = 1; d < deg; d <<= 1){\n \
    \   FPS<mint> f(2 * d), g(2 * d);\n    for(int j = 0; j < min((int)this->size(),\
    \ 2 * d); j++) f[j] = (*this)[j];\n    for(int j = 0; j < d; j++) g[j] = res[j];\n\
    \    f.ntt();\n    g.ntt();\n    for(int j = 0; j < 2 * d; j++) f[j] *= g[j];\n\
    \    f.intt();\n    for(int j = 0; j < d; j++) f[j] = 0;\n    f.ntt();\n    for(int\
    \ j = 0; j < 2 * d; j++) f[j] *= g[j];\n    f.intt();\n    for(int j = d; j <\
    \ min(2 * d, deg); j++) res[j] = -f[j];\n  }\n  return res.pre(deg);\n}\ntemplate\
    \ <class mint>\nFPS<mint> FPS<mint>::exp(int deg) const{\n  using fps = FPS<mint>;\n\
    \  assert((*this).size() == 0 || (*this)[0] == mint(0));\n  if(deg == -1) deg\
    \ = this->size();\n  fps inv;\n  inv.reserve(deg + 1);\n  inv.push_back(mint(0));\n\
    \  inv.push_back(mint(1));\n  auto inplace_integral = [&](fps &F) -> void {\n\
    \    const int n = (int)F.size();\n    const auto mod = mint::get_mod();\n   \
    \ while((int)inv.size() <= n){\n      const int i = inv.size();\n      inv.push_back((-inv[mod\
    \ % i]) * (mod / i));\n    }\n    F.insert(begin(F), mint(0));\n    for(int i\
    \ = 1; i <= n; i++) F[i] *= inv[i];\n  };\n  auto inplace_diff = [](fps& F) ->\
    \ void {\n    if(F.empty()) return;\n    F.erase(begin(F));\n    mint coeff =\
    \ 1;\n    const mint one = 1;\n    for(int i = 0; i < (int)F.size(); i++){\n \
    \     F[i] *= coeff;\n      coeff += one;\n    }\n  };\n  fps b{ 1, 1 < (int)this->size()\
    \ ? (*this)[1] : 0 }, c{ 1 }, z1, z2{ 1, 1 };\n  for(int m = 2; m < deg; m *=\
    \ 2){\n    auto y = b;\n    y.resize(2 * m);\n    y.ntt();\n    z1 = z2;\n   \
    \ fps z(m);\n    for(int i = 0; i < m; i++) z[i] = y[i] * z1[i];\n    z.intt();\n\
    \    fill(begin(z), begin(z) + m / 2, mint(0));\n    z.ntt();\n    for(int i =\
    \ 0; i < m; i++) z[i] *= -z1[i];\n    z.intt();\n    c.insert(end(c), begin(z)\
    \ + m / 2, end(z));\n    z2 = c;\n    z2.resize(2 * m);\n    z2.ntt();\n    fps\
    \ x(begin(*this), begin(*this) + min<int>(this->size(), m));\n    x.resize(m);\n\
    \    inplace_diff(x);\n    x.push_back(mint(0));\n    x.ntt();\n    for(int i\
    \ = 0; i < m; i++) x[i] *= y[i];\n    x.intt();\n    x -= b.diff();\n    x.resize(2\
    \ * m);\n    for(int i = 0; i < m - 1; i++) x[m + i] = x[i], x[i] = mint(0);\n\
    \    x.ntt();\n    for(int i = 0; i < 2 * m; i++) x[i] *= z2[i];\n    x.intt();\n\
    \    x.pop_back();\n    inplace_integral(x);\n    for(int i = m; i < min<int>(this->size(),\
    \ 2 * m); i++) x[i] += (*this)[i];\n    fill(begin(x), begin(x) + m, mint(0));\n\
    \    x.ntt();\n    for(int i = 0; i < 2 * m; i++) x[i] *= y[i];\n    x.intt();\n\
    \    b.insert(end(b), begin(x) + m, end(x));\n  }\n  return fps{ begin(b), begin(b)\
    \ + deg };\n}\n"
  code: "#include \"fps-template.hpp\"\n\ntemplate <class mint>\nvoid FPS<mint>::set_fft(){\
    \ if(!ntt_ptr) ntt_ptr = new NTT<mint>; }\ntemplate <class mint>\nFPS<mint> &FPS<mint>::operator*=(const\
    \ FPS<mint> &r){\n  if(this->empty() || r.empty()){\n    this->clear();\n    return\
    \ *this;\n  }\n  set_fft();\n  const auto ret = static_cast<NTT<mint>*>(ntt_ptr)->multiply(*this,\
    \ r);\n  return *this = FPS<mint>(ret.begin(), ret.end());\n}\ntemplate <class\
    \ mint>\nvoid FPS<mint>::ntt(){\n  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->ntt(*this);\n\
    }\ntemplate <class mint>\nvoid FPS<mint>::intt(){\n  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->intt(*this);\n\
    }\ntemplate <class mint>\nvoid FPS<mint>::ntt_doubling(){\n  set_fft();\n  static_cast<NTT<mint>*>(ntt_ptr)->ntt_doubling(*this);\n\
    }\ntemplate <class mint>\nint FPS<mint>::ntt_pr(){\n  set_fft();\n  return static_cast<NTT<mint>*>(ntt_ptr)->pr;\n\
    }\ntemplate <class mint>\nFPS<mint> FPS<mint>::inv(int deg) const{\n  assert((*this)[0]\
    \ != mint(0));\n  if(deg == -1) deg = (int)this->size();\n  FPS<mint> res(deg);\n\
    \  res[0] = { mint(1) / (*this)[0] };\n  for(int d = 1; d < deg; d <<= 1){\n \
    \   FPS<mint> f(2 * d), g(2 * d);\n    for(int j = 0; j < min((int)this->size(),\
    \ 2 * d); j++) f[j] = (*this)[j];\n    for(int j = 0; j < d; j++) g[j] = res[j];\n\
    \    f.ntt();\n    g.ntt();\n    for(int j = 0; j < 2 * d; j++) f[j] *= g[j];\n\
    \    f.intt();\n    for(int j = 0; j < d; j++) f[j] = 0;\n    f.ntt();\n    for(int\
    \ j = 0; j < 2 * d; j++) f[j] *= g[j];\n    f.intt();\n    for(int j = d; j <\
    \ min(2 * d, deg); j++) res[j] = -f[j];\n  }\n  return res.pre(deg);\n}\ntemplate\
    \ <class mint>\nFPS<mint> FPS<mint>::exp(int deg) const{\n  using fps = FPS<mint>;\n\
    \  assert((*this).size() == 0 || (*this)[0] == mint(0));\n  if(deg == -1) deg\
    \ = this->size();\n  fps inv;\n  inv.reserve(deg + 1);\n  inv.push_back(mint(0));\n\
    \  inv.push_back(mint(1));\n  auto inplace_integral = [&](fps &F) -> void {\n\
    \    const int n = (int)F.size();\n    const auto mod = mint::get_mod();\n   \
    \ while((int)inv.size() <= n){\n      const int i = inv.size();\n      inv.push_back((-inv[mod\
    \ % i]) * (mod / i));\n    }\n    F.insert(begin(F), mint(0));\n    for(int i\
    \ = 1; i <= n; i++) F[i] *= inv[i];\n  };\n  auto inplace_diff = [](fps& F) ->\
    \ void {\n    if(F.empty()) return;\n    F.erase(begin(F));\n    mint coeff =\
    \ 1;\n    const mint one = 1;\n    for(int i = 0; i < (int)F.size(); i++){\n \
    \     F[i] *= coeff;\n      coeff += one;\n    }\n  };\n  fps b{ 1, 1 < (int)this->size()\
    \ ? (*this)[1] : 0 }, c{ 1 }, z1, z2{ 1, 1 };\n  for(int m = 2; m < deg; m *=\
    \ 2){\n    auto y = b;\n    y.resize(2 * m);\n    y.ntt();\n    z1 = z2;\n   \
    \ fps z(m);\n    for(int i = 0; i < m; i++) z[i] = y[i] * z1[i];\n    z.intt();\n\
    \    fill(begin(z), begin(z) + m / 2, mint(0));\n    z.ntt();\n    for(int i =\
    \ 0; i < m; i++) z[i] *= -z1[i];\n    z.intt();\n    c.insert(end(c), begin(z)\
    \ + m / 2, end(z));\n    z2 = c;\n    z2.resize(2 * m);\n    z2.ntt();\n    fps\
    \ x(begin(*this), begin(*this) + min<int>(this->size(), m));\n    x.resize(m);\n\
    \    inplace_diff(x);\n    x.push_back(mint(0));\n    x.ntt();\n    for(int i\
    \ = 0; i < m; i++) x[i] *= y[i];\n    x.intt();\n    x -= b.diff();\n    x.resize(2\
    \ * m);\n    for(int i = 0; i < m - 1; i++) x[m + i] = x[i], x[i] = mint(0);\n\
    \    x.ntt();\n    for(int i = 0; i < 2 * m; i++) x[i] *= z2[i];\n    x.intt();\n\
    \    x.pop_back();\n    inplace_integral(x);\n    for(int i = m; i < min<int>(this->size(),\
    \ 2 * m); i++) x[i] += (*this)[i];\n    fill(begin(x), begin(x) + m, mint(0));\n\
    \    x.ntt();\n    for(int i = 0; i < 2 * m; i++) x[i] *= y[i];\n    x.intt();\n\
    \    b.insert(end(b), begin(x) + m, end(x));\n  }\n  return fps{ begin(b), begin(b)\
    \ + deg };\n}"
  dependsOn:
  - math/fps/fps-template.hpp
  - math/convolution/ntt.hpp
  - math/mint.hpp
  isVerificationFile: false
  path: math/fps/fps.hpp
  requiredBy:
  - math/fps/kitamasa.cpp
  timestamp: '2022-09-15 18:24:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fps/fps.hpp
layout: document
redirect_from:
- /library/math/fps/fps.hpp
- /library/math/fps/fps.hpp.html
title: math/fps/fps.hpp
---
