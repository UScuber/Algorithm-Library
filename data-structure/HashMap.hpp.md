---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Associative-Array.test.cpp
    title: test/yosupo/Data-Structure/Associative-Array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/HashMap.hpp\"\n#include <chrono>\r\n\r\n\
    template <class Key, class Val, int logn = 20, Val initval = Val()>\r\nstruct\
    \ HashMap {\r\n  using uint = unsigned int;\r\n  using ull = unsigned long long;\r\
    \n  private:\r\n  static constexpr unsigned int N = 1 << logn;\r\n  Key *keys;\r\
    \n  Val *vals;\r\n  bitset<N> flag;\r\n  const ull r;\r\n  static constexpr uint\
    \ shift = 64 - logn;\r\n  constexpr ull rng() const{\r\n    ull m = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();\r\
    \n    m ^= m >> 16;\r\n    m ^= m << 32;\r\n    return m;\r\n  }\r\n  public:\r\
    \n  HashMap() : keys(new Key[N]), vals(new Val[N]), r(rng()){}\r\n  inline constexpr\
    \ Val &operator[](const Key i) noexcept{\r\n    uint hash = (ull(i) * r) >> shift;\r\
    \n    while(true){\r\n      if(!flag[hash]){\r\n        keys[hash] = i;\r\n  \
    \      flag[hash] = 1;\r\n        return vals[hash] = initval;\r\n      }\r\n\
    \      if(keys[hash] == i) return vals[hash];\r\n      hash = (hash + 1) & (N\
    \ - 1);\r\n    }\r\n  }\r\n  inline constexpr bool count(const Key i) const noexcept{\r\
    \n    uint hash = (ull(i) * r) >> shift;\r\n    while(true){\r\n      if(!flag[hash])\
    \ return false;\r\n      if(keys[hash] == i) return true;\r\n      hash = (hash\
    \ + 1) & (N - 1);\r\n    }\r\n  }\r\n};\n"
  code: "#include <chrono>\r\n\r\ntemplate <class Key, class Val, int logn = 20, Val\
    \ initval = Val()>\r\nstruct HashMap {\r\n  using uint = unsigned int;\r\n  using\
    \ ull = unsigned long long;\r\n  private:\r\n  static constexpr unsigned int N\
    \ = 1 << logn;\r\n  Key *keys;\r\n  Val *vals;\r\n  bitset<N> flag;\r\n  const\
    \ ull r;\r\n  static constexpr uint shift = 64 - logn;\r\n  constexpr ull rng()\
    \ const{\r\n    ull m = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();\r\
    \n    m ^= m >> 16;\r\n    m ^= m << 32;\r\n    return m;\r\n  }\r\n  public:\r\
    \n  HashMap() : keys(new Key[N]), vals(new Val[N]), r(rng()){}\r\n  inline constexpr\
    \ Val &operator[](const Key i) noexcept{\r\n    uint hash = (ull(i) * r) >> shift;\r\
    \n    while(true){\r\n      if(!flag[hash]){\r\n        keys[hash] = i;\r\n  \
    \      flag[hash] = 1;\r\n        return vals[hash] = initval;\r\n      }\r\n\
    \      if(keys[hash] == i) return vals[hash];\r\n      hash = (hash + 1) & (N\
    \ - 1);\r\n    }\r\n  }\r\n  inline constexpr bool count(const Key i) const noexcept{\r\
    \n    uint hash = (ull(i) * r) >> shift;\r\n    while(true){\r\n      if(!flag[hash])\
    \ return false;\r\n      if(keys[hash] == i) return true;\r\n      hash = (hash\
    \ + 1) & (N - 1);\r\n    }\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/HashMap.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Data-Structure/Associative-Array.test.cpp
documentation_of: data-structure/HashMap.hpp
layout: document
title: HashMap
---

## 説明

- `HashMap<Key,Val,logn,initval>`: Constructor

- `operator[](i)`: $i$にあたる場所の値を取得

- `count(i)`: すでに値が代入されているかの判定
