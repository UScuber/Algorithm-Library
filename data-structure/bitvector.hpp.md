---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/wavelet-matrix.cpp
    title: data-structure/wavelet-matrix.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/bitvector.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct BitVector {\n  using uint = unsigned int;\n  static\
    \ constexpr int w = 32;\n  #define rem(k) ((k) & (w - 1))\n  int len, blocks;\n\
    \  vector<uint> bit, sum;\n  BitVector(){}\n  BitVector(const int len) : len(len),\
    \ blocks((len+w-1)/w){\n    bit.assign(blocks, 0);\n    sum.assign(blocks, 0);\n\
    \  }\n  inline void set(const int k, const int b = 1) noexcept{\n    if(b) bit[k\
    \ / w] |= 1U << rem(k);\n    else bit[k / w] &= ~(1U << rem(k));\n  }\n  void\
    \ build(){\n    sum[0] = 0;\n    for(int i = 1; i < blocks; i++){\n      sum[i]\
    \ = sum[i - 1] + __builtin_popcount(bit[i - 1]);\n    }\n  }\n  int operator[](const\
    \ int k) const{\n    return bit[k / w] >> rem(k) & 1;\n  }\n  inline int rank(const\
    \ int k) const noexcept{\n    return sum[k / w] + __builtin_popcount(bit[k / w]\
    \ & ((1U << rem(k)) - 1));\n  }\n  inline int rank(const int val, const int k)\
    \ const noexcept{\n    return val ? rank(k) : k - rank(k);\n  }\n  #undef rem\n\
    };\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct BitVector {\n  using\
    \ uint = unsigned int;\n  static constexpr int w = 32;\n  #define rem(k) ((k)\
    \ & (w - 1))\n  int len, blocks;\n  vector<uint> bit, sum;\n  BitVector(){}\n\
    \  BitVector(const int len) : len(len), blocks((len+w-1)/w){\n    bit.assign(blocks,\
    \ 0);\n    sum.assign(blocks, 0);\n  }\n  inline void set(const int k, const int\
    \ b = 1) noexcept{\n    if(b) bit[k / w] |= 1U << rem(k);\n    else bit[k / w]\
    \ &= ~(1U << rem(k));\n  }\n  void build(){\n    sum[0] = 0;\n    for(int i =\
    \ 1; i < blocks; i++){\n      sum[i] = sum[i - 1] + __builtin_popcount(bit[i -\
    \ 1]);\n    }\n  }\n  int operator[](const int k) const{\n    return bit[k / w]\
    \ >> rem(k) & 1;\n  }\n  inline int rank(const int k) const noexcept{\n    return\
    \ sum[k / w] + __builtin_popcount(bit[k / w] & ((1U << rem(k)) - 1));\n  }\n \
    \ inline int rank(const int val, const int k) const noexcept{\n    return val\
    \ ? rank(k) : k - rank(k);\n  }\n  #undef rem\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bitvector.hpp
  requiredBy:
  - data-structure/wavelet-matrix.cpp
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/bitvector.hpp
layout: document
redirect_from:
- /library/data-structure/bitvector.hpp
- /library/data-structure/bitvector.hpp.html
title: data-structure/bitvector.hpp
---
