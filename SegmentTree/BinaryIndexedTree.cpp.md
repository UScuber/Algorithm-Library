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
  bundledCode: "#line 1 \"SegmentTree/BinaryIndexedTree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T>\nstruct Bit {\n  Bit(const int _n =\
    \ 0) : n(_n), d(n){}\n  Bit(const vector<T> &v) : d(v), n(v.size()){\n    for(int\
    \ i = 1; i <= n; i++){\n      const int j = i + (i & -i);\n      if(j <= n) d[j\
    \ - 1] += d[i - 1];\n    }\n  }\n  T sum(const int l, const int r) const{\n  \
    \  assert(0 <= l && l <= r && r <= n);\n    return sum(r) - sum(l);\n  }\n  T\
    \ sum(int i) const{\n    T tot = 0;\n    while(i > 0){\n      tot += d[i - 1];\n\
    \      i -= i & -i;\n    }\n    return tot;\n  }\n  void add(int i, const T &x){\n\
    \    assert(0 <= i && i < n);\n    i++;\n    while(i <= n){\n      d[i - 1] +=\
    \ x;\n      i += i & -i;\n    }\n  }\n  private:\n  int n = 1;\n  vector<T> d;\n\
    };\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T>\nstruct\
    \ Bit {\n  Bit(const int _n = 0) : n(_n), d(n){}\n  Bit(const vector<T> &v) :\
    \ d(v), n(v.size()){\n    for(int i = 1; i <= n; i++){\n      const int j = i\
    \ + (i & -i);\n      if(j <= n) d[j - 1] += d[i - 1];\n    }\n  }\n  T sum(const\
    \ int l, const int r) const{\n    assert(0 <= l && l <= r && r <= n);\n    return\
    \ sum(r) - sum(l);\n  }\n  T sum(int i) const{\n    T tot = 0;\n    while(i >\
    \ 0){\n      tot += d[i - 1];\n      i -= i & -i;\n    }\n    return tot;\n  }\n\
    \  void add(int i, const T &x){\n    assert(0 <= i && i < n);\n    i++;\n    while(i\
    \ <= n){\n      d[i - 1] += x;\n      i += i & -i;\n    }\n  }\n  private:\n \
    \ int n = 1;\n  vector<T> d;\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/BinaryIndexedTree.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/BinaryIndexedTree.cpp
layout: document
redirect_from:
- /library/SegmentTree/BinaryIndexedTree.cpp
- /library/SegmentTree/BinaryIndexedTree.cpp.html
title: SegmentTree/BinaryIndexedTree.cpp
---
