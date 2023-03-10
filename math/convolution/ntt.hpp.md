---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/convolution/convolution-arbitrary-mod.cpp
    title: math/convolution/convolution-arbitrary-mod.cpp
  - icon: ':warning:'
    path: math/convolution/convolution.cpp
    title: math/convolution/convolution.cpp
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
    \ back_inserter(a));\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class mint>\n\
    struct NTT {\n  static constexpr uint32_t get_pr(){\n    const uint32_t _mod =\
    \ mint::get_mod();\n    using u64 = uint64_t;\n    u64 ds[32] = {};\n    int idx\
    \ = 0;\n    u64 m = _mod - 1;\n    for(u64 i = 2; i * i <= m; i++){\n      if(m\
    \ % i == 0){\n        ds[idx++] = i;\n        while(m % i == 0) m /= i;\n    \
    \  }\n    }\n    if(m != 1) ds[idx++] = m;\n    uint32_t _pr = 2;\n    while(true){\n\
    \      int flg = 1;\n      for(int i = 0; i < idx; i++){\n        u64 a = _pr,\
    \ b = (_mod - 1) / ds[i], r = 1;\n        while(b){\n          if(b & 1) r = r\
    \ * a % _mod;\n          a = a * a % _mod;\n          b >>= 1;\n        }\n  \
    \      if(r == 1){\n          flg = 0;\n          break;\n        }\n      }\n\
    \      if(flg == 1) break;\n      _pr++;\n    }\n    return _pr;\n  };\n  static\
    \ constexpr uint32_t mod = mint::get_mod();\n  static constexpr uint32_t pr =\
    \ get_pr();\n  static constexpr int level = __builtin_ctzll(mod - 1);\n  mint\
    \ dw[level], dy[level];\n  void setwy(const int k){\n    mint w[level], y[level];\n\
    \    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n    y[k - 1] = w[k - 1].inv();\n\
    \    for(int i = k - 2; i > 0; i--)\n      w[i] = w[i + 1] * w[i + 1], y[i] =\
    \ y[i + 1] * y[i + 1];\n    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] =\
    \ y[2];\n    for(int i = 3; i < k; i++){\n      dw[i] = dw[i - 1] * y[i - 2] *\
    \ w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n    }\n  }\n  NTT(){ setwy(level);\
    \ }\n  void fft4(vector<mint> &a, const int k){\n    if((int)a.size() <= 1) return;\n\
    \    if(k == 1){\n      mint a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0]\
    \ = a[0] + a1;\n      return;\n    }\n    if(k & 1){\n      int v = 1 << (k -\
    \ 1);\n      for(int j = 0; j < v; j++) {\n        mint ajv = a[j + v];\n    \
    \    a[j + v] = a[j] - ajv;\n        a[j] += ajv;\n      }\n    }\n    int u =\
    \ 1 << (2 + (k & 1));\n    int v = 1 << (k - 2 - (k & 1));\n    const mint one\
    \ = mint(1);\n    mint imag = dw[1];\n    while(v) {\n      // jh = 0\n      {\n\
    \        int j0 = 0;\n        int j1 = v;\n        int j2 = j1 + v;\n        int\
    \ j3 = j2 + v;\n        for(; j0 < v; j0++, j1++, j2++, j3++){\n          const\
    \ mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n          const mint t0p2\
    \ = t0 + t2, t1p3 = t1 + t3;\n          const mint t0m2 = t0 - t2, t1m3 = (t1\
    \ - t3) * imag;\n          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;\n       \
    \   a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;\n        }\n      }\n      // jh\
    \ >= 1\n      mint ww = one, xx = one * dw[2], wx = one;\n      for(int jh = 4;\
    \ jh < u;){\n        ww = xx * xx, wx = ww * xx;\n        int j0 = jh * v;\n \
    \       int je = j0 + v;\n        int j2 = je + v;\n        for(; j0 < je; j0++,\
    \ j2++){\n          const mint t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2] * ww,\
    \ t3 = a[j2 + v] * wx;\n          const mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n\
    \          const mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;\n          a[j0]\
    \ = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;\n          a[j2] = t0m2 + t1m3, a[j2\
    \ + v] = t0m2 - t1m3;\n        }\n        xx *= dw[__builtin_ctzll((jh += 4))];\n\
    \      }\n      u <<= 2;\n      v >>= 2;\n    }\n  }\n  void ifft4(vector<mint>\
    \ &a, const int k){\n    if((int)a.size() <= 1) return;\n    if(k == 1){\n   \
    \   mint a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n    \
    \  return;\n    }\n    int u = 1 << (k - 2);\n    int v = 1;\n    const mint one\
    \ = mint(1);\n    mint imag = dy[1];\n    while(u){\n      // jh = 0\n      {\n\
    \        int j0 = 0;\n        int j1 = v;\n        int j2 = v + v;\n        int\
    \ j3 = j2 + v;\n        for(; j0 < v; j0++, j1++, j2++, j3++){\n          const\
    \ mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];\n          const mint t0p1\
    \ = t0 + t1, t2p3 = t2 + t3;\n          const mint t0m1 = t0 - t1, t2m3 = (t2\
    \ - t3) * imag;\n          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;\n       \
    \   a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;\n        }\n      }\n      // jh\
    \ >= 1\n      mint ww = one, xx = one * dy[2], yy = one;\n      u <<= 2;\n   \
    \   for(int jh = 4; jh < u;){\n        ww = xx * xx, yy = xx * imag;\n       \
    \ int j0 = jh * v;\n        int je = j0 + v;\n        int j2 = je + v;\n     \
    \   for(; j0 < je; j0++, j2++){\n          const mint t0 = a[j0], t1 = a[j0 +\
    \ v], t2 = a[j2], t3 = a[j2 + v];\n          const mint t0p1 = t0 + t1, t2p3 =\
    \ t2 + t3;\n          const mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\n\
    \          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;\n          a[j0 +\
    \ v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;\n        }\n        xx *=\
    \ dy[__builtin_ctzll(jh += 4)];\n      }\n      u >>= 4;\n      v <<= 2;\n   \
    \ }\n    if(k & 1){\n      u = 1 << (k - 1);\n      for(int j = 0; j < u; j++){\n\
    \        mint ajv = a[j] - a[j + u];\n        a[j] += a[j + u];\n        a[j +\
    \ u] = ajv;\n      }\n    }\n  }\n  void ntt(vector<mint> &a){\n    if((int)a.size()\
    \ <= 1) return;\n    fft4(a, __builtin_ctz(a.size()));\n  }\n  void intt(vector<mint>\
    \ &a){\n    if((int)a.size() <= 1) return;\n    ifft4(a, __builtin_ctz(a.size()));\n\
    \    const mint iv = mint(a.size()).inv();\n    for(auto &x : a) x *= iv;\n  }\n\
    \  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b){\n    const\
    \ int l = a.size() + b.size() - 1;\n    if(min<int>(a.size(), b.size()) <= 40){\n\
    \      vector<mint> s(l);\n      for(int i = 0; i < (int)a.size(); i++)\n    \
    \    for(int j = 0; j < (int)b.size(); j++) s[i + j] += a[i] * b[j];\n      return\
    \ s;\n    }\n    int k = 2, M = 4;\n    while(M < l) M <<= 1, k++;\n    setwy(k);\n\
    \    vector<mint> s(M), t(M);\n    for(int i = 0; i < (int)a.size(); i++) s[i]\
    \ = a[i];\n    for(int i = 0; i < (int)b.size(); i++) t[i] = b[i];\n    fft4(s,\
    \ k);\n    fft4(t, k);\n    for(int i = 0; i < M; i++) s[i] *= t[i];\n    ifft4(s,\
    \ k);\n    s.resize(l);\n    const mint invm = mint(M).inv();\n    for(int i =\
    \ 0; i < l; i++) s[i] *= invm;\n    return s;\n  }\n  void ntt_doubling(vector<mint>\
    \ &a){\n    const int M = (int)a.size();\n    auto b = a;\n    intt(b);\n    mint\
    \ r = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\n    for(int i\
    \ = 0; i < M; i++) b[i] *= r, r *= zeta;\n    ntt(b);\n    copy(begin(b), end(b),\
    \ back_inserter(a));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/ntt.hpp
  requiredBy:
  - math/fps/fps.hpp
  - math/fps/fps-template.hpp
  - math/fps/kitamasa.cpp
  - math/fps/fps-arbitrary-mod.hpp
  - math/convolution/convolution-arbitrary-mod.cpp
  - math/convolution/convolution.cpp
  timestamp: '2022-09-15 18:24:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/ntt.hpp
layout: document
redirect_from:
- /library/math/convolution/ntt.hpp
- /library/math/convolution/ntt.hpp.html
title: math/convolution/ntt.hpp
---
