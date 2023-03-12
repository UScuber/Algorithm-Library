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
  bundledCode: "#line 1 \"data-structure/HashSet.hpp\"\n#include <chrono>\r\n\r\n\
    template <class Key, int logn = 20>\r\nstruct HashSet {\r\n  using uint = unsigned\
    \ int;\r\n  using ull = unsigned long long;\r\n  private:\r\n  static constexpr\
    \ unsigned int N = 1 << logn;\r\n  Key *keys;\r\n  bitset<N> flag;\r\n  const\
    \ ull r;\r\n  static constexpr uint shift = 64 - logn;\r\n  constexpr ull rng()\
    \ const{\r\n    ull m = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();\r\
    \n    m ^= m >> 16;\r\n    m ^= m << 32;\r\n    return m;\r\n  }\r\n  public:\r\
    \n  HashSet() : keys(new Key[N]), r(rng()){}\r\n  inline constexpr void set(const\
    \ Key i) noexcept{\r\n    uint hash = (ull(i) * r) >> shift;\r\n    while(true){\r\
    \n      if(!flag[hash]){\r\n        keys[hash] = i;\r\n        flag[hash] = 1;\r\
    \n        return;\r\n      }\r\n      if(keys[hash] == i) return;\r\n      hash\
    \ = (hash + 1) & (N - 1);\r\n    }\r\n  }\r\n  inline constexpr bool count(const\
    \ Key i) const noexcept{\r\n    uint hash = (ull(i) * r) >> shift;\r\n    while(true){\r\
    \n      if(!flag[hash]) return false;\r\n      if(keys[hash] == i) return true;\r\
    \n      hash = (hash + 1) & (N - 1);\r\n    }\r\n  }\r\n};\n"
  code: "#include <chrono>\r\n\r\ntemplate <class Key, int logn = 20>\r\nstruct HashSet\
    \ {\r\n  using uint = unsigned int;\r\n  using ull = unsigned long long;\r\n \
    \ private:\r\n  static constexpr unsigned int N = 1 << logn;\r\n  Key *keys;\r\
    \n  bitset<N> flag;\r\n  const ull r;\r\n  static constexpr uint shift = 64 -\
    \ logn;\r\n  constexpr ull rng() const{\r\n    ull m = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();\r\
    \n    m ^= m >> 16;\r\n    m ^= m << 32;\r\n    return m;\r\n  }\r\n  public:\r\
    \n  HashSet() : keys(new Key[N]), r(rng()){}\r\n  inline constexpr void set(const\
    \ Key i) noexcept{\r\n    uint hash = (ull(i) * r) >> shift;\r\n    while(true){\r\
    \n      if(!flag[hash]){\r\n        keys[hash] = i;\r\n        flag[hash] = 1;\r\
    \n        return;\r\n      }\r\n      if(keys[hash] == i) return;\r\n      hash\
    \ = (hash + 1) & (N - 1);\r\n    }\r\n  }\r\n  inline constexpr bool count(const\
    \ Key i) const noexcept{\r\n    uint hash = (ull(i) * r) >> shift;\r\n    while(true){\r\
    \n      if(!flag[hash]) return false;\r\n      if(keys[hash] == i) return true;\r\
    \n      hash = (hash + 1) & (N - 1);\r\n    }\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/HashSet.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/HashSet.hpp
layout: document
redirect_from:
- /library/data-structure/HashSet.hpp
- /library/data-structure/HashSet.hpp.html
title: data-structure/HashSet.hpp
---
