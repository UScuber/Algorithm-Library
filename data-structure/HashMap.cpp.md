---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/HashMap.cpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"data-structure/HashMap.cpp\"\nusing namespace std;\n\ntemplate <class\
    \ Key, class Val, int logn = 20, Val initval = Val()>\nstruct HashMap {\n  using\
    \ uint = unsigned int;\n  using ull = unsigned long long;\n  private:\n  static\
    \ constexpr unsigned int N = 1 << logn;\n  Key *keys;\n  Val *vals;\n  bitset<N>\
    \ flag;\n  const ull r;\n  static constexpr uint shift = 64 - logn;\n  constexpr\
    \ ull rng() const{\n    ull m = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n  }\n  public:\n  HashMap()\
    \ : keys(new Key[N]), vals(new Val[N]), r(rng()){}\n  inline constexpr Val &operator[](const\
    \ Key i) noexcept{\n    uint hash = (ull(i) * r) >> shift;\n    while(true){\n\
    \      if(!flag[hash]){\n        keys[hash] = i;\n        flag[hash] = 1;\n  \
    \      return vals[hash] = initval;\n      }\n      if(keys[hash] == i) return\
    \ vals[hash];\n      hash = (hash + 1) & (N - 1);\n    }\n  }\n  inline constexpr\
    \ bool count(const Key i) const noexcept{\n    uint hash = (ull(i) * r) >> shift;\n\
    \    while(true){\n      if(!flag[hash]) return false;\n      if(keys[hash] ==\
    \ i) return true;\n      hash = (hash + 1) & (N - 1);\n    }\n  }\n};\n"
  code: "#include <bits/stdc++.h>\n#include <chrono>\nusing namespace std;\n\ntemplate\
    \ <class Key, class Val, int logn = 20, Val initval = Val()>\nstruct HashMap {\n\
    \  using uint = unsigned int;\n  using ull = unsigned long long;\n  private:\n\
    \  static constexpr unsigned int N = 1 << logn;\n  Key *keys;\n  Val *vals;\n\
    \  bitset<N> flag;\n  const ull r;\n  static constexpr uint shift = 64 - logn;\n\
    \  constexpr ull rng() const{\n    ull m = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \    m ^= m >> 16;\n    m ^= m << 32;\n    return m;\n  }\n  public:\n  HashMap()\
    \ : keys(new Key[N]), vals(new Val[N]), r(rng()){}\n  inline constexpr Val &operator[](const\
    \ Key i) noexcept{\n    uint hash = (ull(i) * r) >> shift;\n    while(true){\n\
    \      if(!flag[hash]){\n        keys[hash] = i;\n        flag[hash] = 1;\n  \
    \      return vals[hash] = initval;\n      }\n      if(keys[hash] == i) return\
    \ vals[hash];\n      hash = (hash + 1) & (N - 1);\n    }\n  }\n  inline constexpr\
    \ bool count(const Key i) const noexcept{\n    uint hash = (ull(i) * r) >> shift;\n\
    \    while(true){\n      if(!flag[hash]) return false;\n      if(keys[hash] ==\
    \ i) return true;\n      hash = (hash + 1) & (N - 1);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/HashMap.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/HashMap.cpp
layout: document
redirect_from:
- /library/data-structure/HashMap.cpp
- /library/data-structure/HashMap.cpp.html
title: data-structure/HashMap.cpp
---
