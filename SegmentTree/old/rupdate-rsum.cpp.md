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
  bundledCode: "#line 1 \"SegmentTree/old/rupdate-rsum.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n//\u533A\u9593\u306E\u66F4\u65B0\u3001\u533A\u9593\u548C\
    \n\ntemplate <class T> struct segmentTree {\n  segmentTree(int x){\n    while(n\
    \ < x) n *= 2;\n    d.resize(n*2 - 1);\n    lazy.resize(n*2 - 1, inf);\n    si.resize(n*2\
    \ - 1);\n    si[0] = n;\n    for(int i = 1; i < n*2 - 1; i++) si[i] = si[(i-1)\
    \ / 2] / 2;\n  }\n  void set(int i, T x){\n    assert(0 <= i && i < n);\n    d[i\
    \ + n - 1] = x;\n  }\n  void build(){\n    for(int i = n - 2; i >= 0; i--)\n \
    \     d[i] = d[i*2+1] + d[i*2+2];\n  }\n  void update(int l, int r, T x){\n  \
    \  assert(0 <= l && l <= r && r <= n);\n    update_sub(l, r, 0, 0, n, x);\n  }\n\
    \  T query(int l, int r){\n    assert(0 <= l && l <= r && r <= n);\n    return\
    \ query_sub(l, r, 0, 0, n);\n  }\n  private:\n  vector<T> d, lazy, si;\n  int\
    \ n = 1;\n  const T inf = numeric_limits<T>::max();\n  void eval(int k){\n   \
    \ if(lazy[k] == inf) return;\n    if(k < n - 1){\n      lazy[2*k+1] = lazy[k];\n\
    \      lazy[2*k+2] = lazy[k];\n    }\n    d[k] = lazy[k] * si[k];\n    lazy[k]\
    \ = inf;\n  }\n  void update_sub(int a, int b, int k, int l, int r, T x){\n  \
    \  eval(k);\n    if(r <= a || b <= l) return;\n    if(a <= l && r <= b){\n   \
    \   lazy[k] = x;\n      eval(k);\n    }else{\n      update_sub(a, b, 2*k+1, l,\
    \ (l+r)/2, x);\n      update_sub(a, b, 2*k+2, (l+r)/2, r, x);\n      d[k] = d[2*k+1]\
    \ + d[2*k+2];\n    }\n  }\n  T query_sub(int a, int b, int k, int l, int r){\n\
    \    eval(k);\n    if(r <= a || b <= l) return 0;\n    if(a <= l && r <= b) return\
    \ d[k];\n    else{\n      T vlef = query_sub(a, b, k*2+1, l, (l+r)/2);\n     \
    \ T vrig = query_sub(a, b, k*2+2, (l+r)/2, r);\n      return vlef + vrig;\n  \
    \  }\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//\u533A\u9593\u306E\u66F4\
    \u65B0\u3001\u533A\u9593\u548C\n\ntemplate <class T> struct segmentTree {\n  segmentTree(int\
    \ x){\n    while(n < x) n *= 2;\n    d.resize(n*2 - 1);\n    lazy.resize(n*2 -\
    \ 1, inf);\n    si.resize(n*2 - 1);\n    si[0] = n;\n    for(int i = 1; i < n*2\
    \ - 1; i++) si[i] = si[(i-1) / 2] / 2;\n  }\n  void set(int i, T x){\n    assert(0\
    \ <= i && i < n);\n    d[i + n - 1] = x;\n  }\n  void build(){\n    for(int i\
    \ = n - 2; i >= 0; i--)\n      d[i] = d[i*2+1] + d[i*2+2];\n  }\n  void update(int\
    \ l, int r, T x){\n    assert(0 <= l && l <= r && r <= n);\n    update_sub(l,\
    \ r, 0, 0, n, x);\n  }\n  T query(int l, int r){\n    assert(0 <= l && l <= r\
    \ && r <= n);\n    return query_sub(l, r, 0, 0, n);\n  }\n  private:\n  vector<T>\
    \ d, lazy, si;\n  int n = 1;\n  const T inf = numeric_limits<T>::max();\n  void\
    \ eval(int k){\n    if(lazy[k] == inf) return;\n    if(k < n - 1){\n      lazy[2*k+1]\
    \ = lazy[k];\n      lazy[2*k+2] = lazy[k];\n    }\n    d[k] = lazy[k] * si[k];\n\
    \    lazy[k] = inf;\n  }\n  void update_sub(int a, int b, int k, int l, int r,\
    \ T x){\n    eval(k);\n    if(r <= a || b <= l) return;\n    if(a <= l && r <=\
    \ b){\n      lazy[k] = x;\n      eval(k);\n    }else{\n      update_sub(a, b,\
    \ 2*k+1, l, (l+r)/2, x);\n      update_sub(a, b, 2*k+2, (l+r)/2, r, x);\n    \
    \  d[k] = d[2*k+1] + d[2*k+2];\n    }\n  }\n  T query_sub(int a, int b, int k,\
    \ int l, int r){\n    eval(k);\n    if(r <= a || b <= l) return 0;\n    if(a <=\
    \ l && r <= b) return d[k];\n    else{\n      T vlef = query_sub(a, b, k*2+1,\
    \ l, (l+r)/2);\n      T vrig = query_sub(a, b, k*2+2, (l+r)/2, r);\n      return\
    \ vlef + vrig;\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/old/rupdate-rsum.cpp
  requiredBy: []
  timestamp: '2022-02-01 17:39:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/old/rupdate-rsum.cpp
layout: document
redirect_from:
- /library/SegmentTree/old/rupdate-rsum.cpp
- /library/SegmentTree/old/rupdate-rsum.cpp.html
title: SegmentTree/old/rupdate-rsum.cpp
---
