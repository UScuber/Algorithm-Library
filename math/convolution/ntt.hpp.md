---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/convolution/convolution-arbitrary-mod.hpp
    title: math/convolution/convolution-arbitrary-mod.hpp
  - icon: ':warning:'
    path: math/convolution/convolution.hpp
    title: math/convolution/convolution.hpp
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
    path: math/fps/kitamasa.hpp
    title: math/fps/kitamasa.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ end(b), back_inserter(a));\r\n  }\r\n};\n"
  code: "template <class mint>\r\nstruct NTT {\r\n  static constexpr uint32_t get_pr(){\r\
    \n    const uint32_t _mod = mint::get_mod();\r\n    using u64 = uint64_t;\r\n\
    \    u64 ds[32] = {};\r\n    int idx = 0;\r\n    u64 m = _mod - 1;\r\n    for(u64\
    \ i = 2; i * i <= m; i++){\r\n      if(m % i == 0){\r\n        ds[idx++] = i;\r\
    \n        while(m % i == 0) m /= i;\r\n      }\r\n    }\r\n    if(m != 1) ds[idx++]\
    \ = m;\r\n    uint32_t _pr = 2;\r\n    while(true){\r\n      int flg = 1;\r\n\
    \      for(int i = 0; i < idx; i++){\r\n        u64 a = _pr, b = (_mod - 1) /\
    \ ds[i], r = 1;\r\n        while(b){\r\n          if(b & 1) r = r * a % _mod;\r\
    \n          a = a * a % _mod;\r\n          b >>= 1;\r\n        }\r\n        if(r\
    \ == 1){\r\n          flg = 0;\r\n          break;\r\n        }\r\n      }\r\n\
    \      if(flg == 1) break;\r\n      _pr++;\r\n    }\r\n    return _pr;\r\n  };\r\
    \n  static constexpr uint32_t mod = mint::get_mod();\r\n  static constexpr uint32_t\
    \ pr = get_pr();\r\n  static constexpr int level = __builtin_ctzll(mod - 1);\r\
    \n  mint dw[level], dy[level];\r\n  void setwy(const int k){\r\n    mint w[level],\
    \ y[level];\r\n    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\r\n    y[k -\
    \ 1] = w[k - 1].inv();\r\n    for(int i = k - 2; i > 0; i--)\r\n      w[i] = w[i\
    \ + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];\r\n    dw[1] = w[1], dy[1] = y[1],\
    \ dw[2] = w[2], dy[2] = y[2];\r\n    for(int i = 3; i < k; i++){\r\n      dw[i]\
    \ = dw[i - 1] * y[i - 2] * w[i];\r\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\r\
    \n    }\r\n  }\r\n  NTT(){ setwy(level); }\r\n  void fft4(vector<mint> &a, const\
    \ int k){\r\n    if((int)a.size() <= 1) return;\r\n    if(k == 1){\r\n      mint\
    \ a1 = a[1];\r\n      a[1] = a[0] - a[1];\r\n      a[0] = a[0] + a1;\r\n     \
    \ return;\r\n    }\r\n    if(k & 1){\r\n      int v = 1 << (k - 1);\r\n      for(int\
    \ j = 0; j < v; j++) {\r\n        mint ajv = a[j + v];\r\n        a[j + v] = a[j]\
    \ - ajv;\r\n        a[j] += ajv;\r\n      }\r\n    }\r\n    int u = 1 << (2 +\
    \ (k & 1));\r\n    int v = 1 << (k - 2 - (k & 1));\r\n    const mint one = mint(1);\r\
    \n    mint imag = dw[1];\r\n    while(v) {\r\n      // jh = 0\r\n      {\r\n \
    \       int j0 = 0;\r\n        int j1 = v;\r\n        int j2 = j1 + v;\r\n   \
    \     int j3 = j2 + v;\r\n        for(; j0 < v; j0++, j1++, j2++, j3++){\r\n \
    \         const mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\r\n     \
    \     const mint t0p2 = t0 + t2, t1p3 = t1 + t3;\r\n          const mint t0m2\
    \ = t0 - t2, t1m3 = (t1 - t3) * imag;\r\n          a[j0] = t0p2 + t1p3, a[j1]\
    \ = t0p2 - t1p3;\r\n          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\r\n  \
    \      }\r\n      }\r\n      // jh >= 1\r\n      mint ww = one, xx = one * dw[2],\
    \ wx = one;\r\n      for(int jh = 4; jh < u;){\r\n        ww = xx * xx, wx = ww\
    \ * xx;\r\n        int j0 = jh * v;\r\n        int je = j0 + v;\r\n        int\
    \ j2 = je + v;\r\n        for(; j0 < je; j0++, j2++){\r\n          const mint\
    \ t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2] * ww, t3 = a[j2 + v] * wx;\r\n \
    \         const mint t0p2 = t0 + t2, t1p3 = t1 + t3;\r\n          const mint t0m2\
    \ = t0 - t2, t1m3 = (t1 - t3) * imag;\r\n          a[j0] = t0p2 + t1p3, a[j0 +\
    \ v] = t0p2 - t1p3;\r\n          a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;\r\
    \n        }\r\n        xx *= dw[__builtin_ctzll((jh += 4))];\r\n      }\r\n  \
    \    u <<= 2;\r\n      v >>= 2;\r\n    }\r\n  }\r\n  void ifft4(vector<mint> &a,\
    \ const int k){\r\n    if((int)a.size() <= 1) return;\r\n    if(k == 1){\r\n \
    \     mint a1 = a[1];\r\n      a[1] = a[0] - a[1];\r\n      a[0] = a[0] + a1;\r\
    \n      return;\r\n    }\r\n    int u = 1 << (k - 2);\r\n    int v = 1;\r\n  \
    \  const mint one = mint(1);\r\n    mint imag = dy[1];\r\n    while(u){\r\n  \
    \    // jh = 0\r\n      {\r\n        int j0 = 0;\r\n        int j1 = v;\r\n  \
    \      int j2 = v + v;\r\n        int j3 = j2 + v;\r\n        for(; j0 < v; j0++,\
    \ j1++, j2++, j3++){\r\n          const mint t0 = a[j0], t1 = a[j1], t2 = a[j2],\
    \ t3 = a[j3];\r\n          const mint t0p1 = t0 + t1, t2p3 = t2 + t3;\r\n    \
    \      const mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;\r\n          a[j0]\
    \ = t0p1 + t2p3, a[j2] = t0p1 - t2p3;\r\n          a[j1] = t0m1 + t2m3, a[j3]\
    \ = t0m1 - t2m3;\r\n        }\r\n      }\r\n      // jh >= 1\r\n      mint ww\
    \ = one, xx = one * dy[2], yy = one;\r\n      u <<= 2;\r\n      for(int jh = 4;\
    \ jh < u;){\r\n        ww = xx * xx, yy = xx * imag;\r\n        int j0 = jh *\
    \ v;\r\n        int je = j0 + v;\r\n        int j2 = je + v;\r\n        for(;\
    \ j0 < je; j0++, j2++){\r\n          const mint t0 = a[j0], t1 = a[j0 + v], t2\
    \ = a[j2], t3 = a[j2 + v];\r\n          const mint t0p1 = t0 + t1, t2p3 = t2 +\
    \ t3;\r\n          const mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\r\n\
    \          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;\r\n          a[j0\
    \ + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;\r\n        }\r\n       \
    \ xx *= dy[__builtin_ctzll(jh += 4)];\r\n      }\r\n      u >>= 4;\r\n      v\
    \ <<= 2;\r\n    }\r\n    if(k & 1){\r\n      u = 1 << (k - 1);\r\n      for(int\
    \ j = 0; j < u; j++){\r\n        mint ajv = a[j] - a[j + u];\r\n        a[j] +=\
    \ a[j + u];\r\n        a[j + u] = ajv;\r\n      }\r\n    }\r\n  }\r\n  void ntt(vector<mint>\
    \ &a){\r\n    if((int)a.size() <= 1) return;\r\n    fft4(a, __builtin_ctz(a.size()));\r\
    \n  }\r\n  void intt(vector<mint> &a){\r\n    if((int)a.size() <= 1) return;\r\
    \n    ifft4(a, __builtin_ctz(a.size()));\r\n    const mint iv = mint(a.size()).inv();\r\
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
    \ end(b), back_inserter(a));\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/ntt.hpp
  requiredBy:
  - math/fps/kitamasa.hpp
  - math/fps/fps.hpp
  - math/fps/fps-template.hpp
  - math/fps/fps-arbitrary-mod.hpp
  - math/convolution/convolution-arbitrary-mod.hpp
  - math/convolution/convolution.hpp
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/ntt.hpp
layout: document
redirect_from:
- /library/math/convolution/ntt.hpp
- /library/math/convolution/ntt.hpp.html
title: math/convolution/ntt.hpp
---
