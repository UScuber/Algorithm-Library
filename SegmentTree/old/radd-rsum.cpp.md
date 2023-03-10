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
  bundledCode: "#line 1 \"SegmentTree/old/radd-rsum.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n//\u533A\u9593\u52A0\u7B97\u3001\u533A\u9593\u548C\n\n\
    template<class T> struct segmentTree {\n  segmentTree(int x){\n    while(n < x)\
    \ n *= 2;\n    d.resize(2 * n - 1);\n    lazy.resize(2 * n - 1);\n  }\n  void\
    \ set(int i, T x){\n    assert(0 <= i && i < n);\n    d[i + n - 1] += x;\n  }\n\
    \  void build(){\n    for(int i = n - 2; i >= 0; i--)\n      d[i] = d[i * 2 +\
    \ 1] + d[i * 2 + 2];\n  }\n  void add(int l, int r, T x){\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    add(l, r, x, 0, 0, n);\n  }\n  T sum(int l, int r){\n\
    \    assert(0 <= l && l <= r && r <= n);\n    return sum(l, r, 0, 0, n);\n  }\n\
    \  private:\n  int n = 1;\n  vector<T> d, lazy;\n  void eval(int k, int l, int\
    \ r){\n    d[k] += lazy[k];\n    if(r - l > 1){\n      lazy[2*k+1] += lazy[k]\
    \ / 2;\n      lazy[2*k+2] += lazy[k] / 2;\n    }\n    lazy[k] = 0;\n  }\n  void\
    \ add(int a, int b, T x, int k, int l, int r){\n    eval(k, l, r);\n    if(b <=\
    \ l || r <= a) return;\n    if(a <= l && r <= b) {\n      lazy[k] += (r - l) *\
    \ x;\n      eval(k, l, r);\n    }else{\n      add(a, b, x, 2*k+1, l, (l+r)/2);\n\
    \      add(a, b, x, 2*k+2, (l+r)/2, r);\n      d[k] = d[2*k+1] + d[2*k+2];\n \
    \   }\n  }\n  T sum(int a, int b, T k, int l, int r){\n    eval(k, l, r);\n  \
    \  if(b <= l || r <= a) return 0;\n    if(a <= l && r <= b) return d[k];\n   \
    \ T vlef = sum(a, b, 2*k+1, l, (l+r)/2);\n    T vrig = sum(a, b, 2*k+2, (l+r)/2,\
    \ r);\n    return vlef + vrig;\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//\u533A\u9593\u52A0\u7B97\
    \u3001\u533A\u9593\u548C\n\ntemplate<class T> struct segmentTree {\n  segmentTree(int\
    \ x){\n    while(n < x) n *= 2;\n    d.resize(2 * n - 1);\n    lazy.resize(2 *\
    \ n - 1);\n  }\n  void set(int i, T x){\n    assert(0 <= i && i < n);\n    d[i\
    \ + n - 1] += x;\n  }\n  void build(){\n    for(int i = n - 2; i >= 0; i--)\n\
    \      d[i] = d[i * 2 + 1] + d[i * 2 + 2];\n  }\n  void add(int l, int r, T x){\n\
    \    assert(0 <= l && l <= r && r <= n);\n    add(l, r, x, 0, 0, n);\n  }\n  T\
    \ sum(int l, int r){\n    assert(0 <= l && l <= r && r <= n);\n    return sum(l,\
    \ r, 0, 0, n);\n  }\n  private:\n  int n = 1;\n  vector<T> d, lazy;\n  void eval(int\
    \ k, int l, int r){\n    d[k] += lazy[k];\n    if(r - l > 1){\n      lazy[2*k+1]\
    \ += lazy[k] / 2;\n      lazy[2*k+2] += lazy[k] / 2;\n    }\n    lazy[k] = 0;\n\
    \  }\n  void add(int a, int b, T x, int k, int l, int r){\n    eval(k, l, r);\n\
    \    if(b <= l || r <= a) return;\n    if(a <= l && r <= b) {\n      lazy[k] +=\
    \ (r - l) * x;\n      eval(k, l, r);\n    }else{\n      add(a, b, x, 2*k+1, l,\
    \ (l+r)/2);\n      add(a, b, x, 2*k+2, (l+r)/2, r);\n      d[k] = d[2*k+1] + d[2*k+2];\n\
    \    }\n  }\n  T sum(int a, int b, T k, int l, int r){\n    eval(k, l, r);\n \
    \   if(b <= l || r <= a) return 0;\n    if(a <= l && r <= b) return d[k];\n  \
    \  T vlef = sum(a, b, 2*k+1, l, (l+r)/2);\n    T vrig = sum(a, b, 2*k+2, (l+r)/2,\
    \ r);\n    return vlef + vrig;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/old/radd-rsum.cpp
  requiredBy: []
  timestamp: '2022-02-01 17:39:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/old/radd-rsum.cpp
layout: document
redirect_from:
- /library/SegmentTree/old/radd-rsum.cpp
- /library/SegmentTree/old/radd-rsum.cpp.html
title: SegmentTree/old/radd-rsum.cpp
---
