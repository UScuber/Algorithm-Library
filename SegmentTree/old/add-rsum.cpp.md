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
  bundledCode: "#line 1 \"SegmentTree/old/add-rsum.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n//\u4E00\u3064\u306E\u5024\u3092\u52A0\u7B97\u3001\u533A\
    \u9593\u548C\n\ntemplate<class T> struct bit{\n  public:\n  bit(int x){\n    while(x\
    \ > n) n *= 2;\n    d.resize(n);\n  }\n  T sum(int l, int r){\n    assert(0 <=\
    \ l && l <= r && r <= n);\n    return sum(r) - sum(l);\n  }\n  void add(int i,\
    \ T x){\n    assert(0 <= i && i < n);\n    i++;\n    while(i <= n){\n      d[i\
    \ - 1] += x;\n      i += i & -i;\n    }\n  }\n  private:\n  int n = 1;\n  vector<T>\
    \ d;\n  T sum(int i){\n    T tot = 0;\n    while(i > 0){\n      tot += d[i - 1];\n\
    \      i -= i & -i;\n    }\n    return tot;\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//\u4E00\u3064\u306E\u5024\
    \u3092\u52A0\u7B97\u3001\u533A\u9593\u548C\n\ntemplate<class T> struct bit{\n\
    \  public:\n  bit(int x){\n    while(x > n) n *= 2;\n    d.resize(n);\n  }\n \
    \ T sum(int l, int r){\n    assert(0 <= l && l <= r && r <= n);\n    return sum(r)\
    \ - sum(l);\n  }\n  void add(int i, T x){\n    assert(0 <= i && i < n);\n    i++;\n\
    \    while(i <= n){\n      d[i - 1] += x;\n      i += i & -i;\n    }\n  }\n  private:\n\
    \  int n = 1;\n  vector<T> d;\n  T sum(int i){\n    T tot = 0;\n    while(i >\
    \ 0){\n      tot += d[i - 1];\n      i -= i & -i;\n    }\n    return tot;\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/old/add-rsum.cpp
  requiredBy: []
  timestamp: '2022-02-01 17:39:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/old/add-rsum.cpp
layout: document
redirect_from:
- /library/SegmentTree/old/add-rsum.cpp
- /library/SegmentTree/old/add-rsum.cpp.html
title: SegmentTree/old/add-rsum.cpp
---
