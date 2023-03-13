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
  bundledCode: "#line 1 \"SegmentTree/BinaryIndexedTree.hpp\"\ntemplate <class T>\r\
    \nstruct BIT {\r\n  BIT(const int _n = 0) : n(_n), d(n){}\r\n  BIT(const vector<T>\
    \ &v) : d(v), n(v.size()){\r\n    for(int i = 1; i <= n; i++){\r\n      const\
    \ int j = i + (i & -i);\r\n      if(j <= n) d[j - 1] += d[i - 1];\r\n    }\r\n\
    \  }\r\n  T sum(const int l, const int r) const{\r\n    assert(0 <= l && l <=\
    \ r && r <= n);\r\n    return sum(r) - sum(l);\r\n  }\r\n  T sum(int i) const{\r\
    \n    T tot = 0;\r\n    while(i > 0){\r\n      tot += d[i - 1];\r\n      i -=\
    \ i & -i;\r\n    }\r\n    return tot;\r\n  }\r\n  void add(int i, const T &x){\r\
    \n    assert(0 <= i && i < n);\r\n    i++;\r\n    while(i <= n){\r\n      d[i\
    \ - 1] += x;\r\n      i += i & -i;\r\n    }\r\n  }\r\n  private:\r\n  int n =\
    \ 1;\r\n  vector<T> d;\r\n};\n"
  code: "template <class T>\r\nstruct BIT {\r\n  BIT(const int _n = 0) : n(_n), d(n){}\r\
    \n  BIT(const vector<T> &v) : d(v), n(v.size()){\r\n    for(int i = 1; i <= n;\
    \ i++){\r\n      const int j = i + (i & -i);\r\n      if(j <= n) d[j - 1] += d[i\
    \ - 1];\r\n    }\r\n  }\r\n  T sum(const int l, const int r) const{\r\n    assert(0\
    \ <= l && l <= r && r <= n);\r\n    return sum(r) - sum(l);\r\n  }\r\n  T sum(int\
    \ i) const{\r\n    T tot = 0;\r\n    while(i > 0){\r\n      tot += d[i - 1];\r\
    \n      i -= i & -i;\r\n    }\r\n    return tot;\r\n  }\r\n  void add(int i, const\
    \ T &x){\r\n    assert(0 <= i && i < n);\r\n    i++;\r\n    while(i <= n){\r\n\
    \      d[i - 1] += x;\r\n      i += i & -i;\r\n    }\r\n  }\r\n  private:\r\n\
    \  int n = 1;\r\n  vector<T> d;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2023-03-13 21:50:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/SegmentTree/BinaryIndexedTree.hpp
- /library/SegmentTree/BinaryIndexedTree.hpp.html
title: SegmentTree/BinaryIndexedTree.hpp
---
