---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix-comp.hpp
    title: data-structure/wavelet-matrix-comp.hpp
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet-matrix.hpp
    title: data-structure/wavelet-matrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Range-Kth-Smallest.test.cpp
    title: test/yosupo/Range-Kth-Smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Static-Range-Frequency.test.cpp
    title: test/yosupo/Static-Range-Frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/bitvector.hpp\"\nstruct BitVector {\r\n \
    \ using uint = unsigned int;\r\n  static constexpr int w = 32;\r\n  #define rem(k)\
    \ ((k) & (w - 1))\r\n  int len, blocks;\r\n  vector<uint> bit, sum;\r\n  BitVector(){}\r\
    \n  BitVector(const int len) : len(len), blocks((len+w-1)/w){\r\n    bit.assign(blocks,\
    \ 0);\r\n    sum.assign(blocks, 0);\r\n  }\r\n  inline void set(const int k, const\
    \ int b = 1) noexcept{\r\n    if(b) bit[k / w] |= 1U << rem(k);\r\n    else bit[k\
    \ / w] &= ~(1U << rem(k));\r\n  }\r\n  void build(){\r\n    sum[0] = 0;\r\n  \
    \  for(int i = 1; i < blocks; i++){\r\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i\
    \ - 1]);\r\n    }\r\n  }\r\n  int operator[](const int k) const{\r\n    return\
    \ bit[k / w] >> rem(k) & 1;\r\n  }\r\n  inline int rank(const int k) const noexcept{\r\
    \n    return sum[k / w] + __builtin_popcount(bit[k / w] & ((1U << rem(k)) - 1));\r\
    \n  }\r\n  inline int rank(const int val, const int k) const noexcept{\r\n   \
    \ return val ? rank(k) : k - rank(k);\r\n  }\r\n  #undef rem\r\n};\n"
  code: "struct BitVector {\r\n  using uint = unsigned int;\r\n  static constexpr\
    \ int w = 32;\r\n  #define rem(k) ((k) & (w - 1))\r\n  int len, blocks;\r\n  vector<uint>\
    \ bit, sum;\r\n  BitVector(){}\r\n  BitVector(const int len) : len(len), blocks((len+w-1)/w){\r\
    \n    bit.assign(blocks, 0);\r\n    sum.assign(blocks, 0);\r\n  }\r\n  inline\
    \ void set(const int k, const int b = 1) noexcept{\r\n    if(b) bit[k / w] |=\
    \ 1U << rem(k);\r\n    else bit[k / w] &= ~(1U << rem(k));\r\n  }\r\n  void build(){\r\
    \n    sum[0] = 0;\r\n    for(int i = 1; i < blocks; i++){\r\n      sum[i] = sum[i\
    \ - 1] + __builtin_popcount(bit[i - 1]);\r\n    }\r\n  }\r\n  int operator[](const\
    \ int k) const{\r\n    return bit[k / w] >> rem(k) & 1;\r\n  }\r\n  inline int\
    \ rank(const int k) const noexcept{\r\n    return sum[k / w] + __builtin_popcount(bit[k\
    \ / w] & ((1U << rem(k)) - 1));\r\n  }\r\n  inline int rank(const int val, const\
    \ int k) const noexcept{\r\n    return val ? rank(k) : k - rank(k);\r\n  }\r\n\
    \  #undef rem\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bitvector.hpp
  requiredBy:
  - data-structure/wavelet-matrix-comp.hpp
  - data-structure/wavelet-matrix.hpp
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Static-Range-Frequency.test.cpp
  - test/yosupo/Range-Kth-Smallest.test.cpp
documentation_of: data-structure/bitvector.hpp
layout: document
redirect_from:
- /library/data-structure/bitvector.hpp
- /library/data-structure/bitvector.hpp.html
title: data-structure/bitvector.hpp
---
