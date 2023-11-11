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
  bundledCode: "#line 1 \"SegmentTree/old/rupdate-rmin.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n//\u533A\u9593\u66F4\u65B0\u3001\u533A\u9593\u306E\u6700\
    \u5C0F\u5024/\u6700\u5927\u5024\n\ntemplate<class T, const T&(*op)(const T&,const\
    \ T&)>\nstruct segmentTree {\n  segmentTree(int x){\n    while(x > n) n *= 2;\n\
    \    inf = -op(inf-1, -inf+1);\n    d.resize(2*n - 1, inf);\n    lazy.resize(2*n\
    \ - 1, inf);\n  }\n  void set(int i, T x){\n    assert(0 <= i && i < n);\n   \
    \ d[i + n - 1] = x;\n  }\n  void build(){\n    for(int k = n - 2; k >= 0; k--)\n\
    \      d[k] = min(d[k * 2 + 1], d[k * 2 + 2]);\n  }\n  void update(int l, int\
    \ r, T x){\n    assert(0 <= l && l <= r && r <= n);\n    update(l, r, x, 0, 0,\
    \ n);\n  }\n  T query(int l, int r){\n    assert(0 <= l && l <= r && r <= n);\n\
    \    return query_sub(l, r, 0, 0, n);\n  }\n  int min_right(int l, int r, T x){\n\
    \    assert(0 <= l && l <= r && r <= n);\n    return min_right_sub(l, r, x, 0,\
    \ 0, n);\n  }\n  int min_left(int l, int r, T x){\n    assert(0 <= l && l <= r\
    \ && r <= n);\n    return min_left_sub(l, r, x, 0, 0, n);\n  }\n  private:\n \
    \ T inf = numeric_limits<T>::max();\n  int n = 1;\n  vector<T> d, lazy;\n  void\
    \ eval(int k){\n    if(lazy[k] == inf) return;\n    if(k < n - 1){\n      lazy[k\
    \ * 2 + 1] = lazy[k];\n      lazy[k * 2 + 2] = lazy[k];\n    }\n    d[k] = lazy[k];\n\
    \    lazy[k] = inf;\n  }\n  void update(int a, int b, T x, int k, int l, int r){\n\
    \    eval(k);\n    if(a <= l && r <= b){\n      lazy[k] = x;\n      eval(k);\n\
    \    }else if(a < r && l < b){\n      update(a, b, x, k*2 + 1, l, (l+r)/2);\n\
    \      update(a, b, x, k*2 + 2, (l+r)/2, r);\n      d[k] = op(d[k * 2 + 1], d[k\
    \ * 2 + 2]);\n    }\n  }\n  T query_sub(int a, int b, int k, int l, int r){\n\
    \    eval(k);\n    if(r <= a || b <= l) return inf;\n    if(a <= l && r <= b)\
    \ return d[k];\n    T vlef = query_sub(a, b, k*2 + 1, l, (r+l)/2);\n    T vrig\
    \ = query_sub(a, b, k*2 + 2, (r+l)/2, r);\n    return op(vlef, vrig);\n  }\n \
    \ //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070return a-1\n  int min_right_sub(int\
    \ a, int b, T x, int k, int l, int r){\n    eval(k);\n    if(op(d[k]+op(1,-1),x)==x\
    \ || r <= a || b <= l) return a - 1;\n    if(k >= n - 1) return k - (n - 1);\n\
    \n    int vrig = min_right_sub(a, b, x, 2*k+2, (l+r)/2, r);\n    if(vrig != a\
    \ - 1) return vrig;\n    return min_right_sub(a, b, x, 2*k+1, l, (l+r)/2);\n \
    \ }\n  //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070return b\n  int min_left_sub(int\
    \ a, int b, T x, int k, int l, int r){\n    eval(k);\n    if(op(d[k]+op(1,-1),x)==x\
    \ || r <= a || b <= l) return b;\n    if(k >= n - 1) return k - (n - 1);\n\n \
    \   int vlef = min_left_sub(a, b, x, 2*k+1, l, (l+r)/2);\n    if(vlef != b) return\
    \ vlef;\n    return min_left_sub(a, b, x, 2*k+2, (l+r)/2, r);\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n//\u533A\u9593\u66F4\u65B0\
    \u3001\u533A\u9593\u306E\u6700\u5C0F\u5024/\u6700\u5927\u5024\n\ntemplate<class\
    \ T, const T&(*op)(const T&,const T&)>\nstruct segmentTree {\n  segmentTree(int\
    \ x){\n    while(x > n) n *= 2;\n    inf = -op(inf-1, -inf+1);\n    d.resize(2*n\
    \ - 1, inf);\n    lazy.resize(2*n - 1, inf);\n  }\n  void set(int i, T x){\n \
    \   assert(0 <= i && i < n);\n    d[i + n - 1] = x;\n  }\n  void build(){\n  \
    \  for(int k = n - 2; k >= 0; k--)\n      d[k] = min(d[k * 2 + 1], d[k * 2 + 2]);\n\
    \  }\n  void update(int l, int r, T x){\n    assert(0 <= l && l <= r && r <= n);\n\
    \    update(l, r, x, 0, 0, n);\n  }\n  T query(int l, int r){\n    assert(0 <=\
    \ l && l <= r && r <= n);\n    return query_sub(l, r, 0, 0, n);\n  }\n  int min_right(int\
    \ l, int r, T x){\n    assert(0 <= l && l <= r && r <= n);\n    return min_right_sub(l,\
    \ r, x, 0, 0, n);\n  }\n  int min_left(int l, int r, T x){\n    assert(0 <= l\
    \ && l <= r && r <= n);\n    return min_left_sub(l, r, x, 0, 0, n);\n  }\n  private:\n\
    \  T inf = numeric_limits<T>::max();\n  int n = 1;\n  vector<T> d, lazy;\n  void\
    \ eval(int k){\n    if(lazy[k] == inf) return;\n    if(k < n - 1){\n      lazy[k\
    \ * 2 + 1] = lazy[k];\n      lazy[k * 2 + 2] = lazy[k];\n    }\n    d[k] = lazy[k];\n\
    \    lazy[k] = inf;\n  }\n  void update(int a, int b, T x, int k, int l, int r){\n\
    \    eval(k);\n    if(a <= l && r <= b){\n      lazy[k] = x;\n      eval(k);\n\
    \    }else if(a < r && l < b){\n      update(a, b, x, k*2 + 1, l, (l+r)/2);\n\
    \      update(a, b, x, k*2 + 2, (l+r)/2, r);\n      d[k] = op(d[k * 2 + 1], d[k\
    \ * 2 + 2]);\n    }\n  }\n  T query_sub(int a, int b, int k, int l, int r){\n\
    \    eval(k);\n    if(r <= a || b <= l) return inf;\n    if(a <= l && r <= b)\
    \ return d[k];\n    T vlef = query_sub(a, b, k*2 + 1, l, (r+l)/2);\n    T vrig\
    \ = query_sub(a, b, k*2 + 2, (r+l)/2, r);\n    return op(vlef, vrig);\n  }\n \
    \ //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070return a-1\n  int min_right_sub(int\
    \ a, int b, T x, int k, int l, int r){\n    eval(k);\n    if(op(d[k]+op(1,-1),x)==x\
    \ || r <= a || b <= l) return a - 1;\n    if(k >= n - 1) return k - (n - 1);\n\
    \n    int vrig = min_right_sub(a, b, x, 2*k+2, (l+r)/2, r);\n    if(vrig != a\
    \ - 1) return vrig;\n    return min_right_sub(a, b, x, 2*k+1, l, (l+r)/2);\n \
    \ }\n  //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070return b\n  int min_left_sub(int\
    \ a, int b, T x, int k, int l, int r){\n    eval(k);\n    if(op(d[k]+op(1,-1),x)==x\
    \ || r <= a || b <= l) return b;\n    if(k >= n - 1) return k - (n - 1);\n\n \
    \   int vlef = min_left_sub(a, b, x, 2*k+1, l, (l+r)/2);\n    if(vlef != b) return\
    \ vlef;\n    return min_left_sub(a, b, x, 2*k+2, (l+r)/2, r);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/old/rupdate-rmin.cpp
  requiredBy: []
  timestamp: '2022-02-01 17:39:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/old/rupdate-rmin.cpp
layout: document
redirect_from:
- /library/SegmentTree/old/rupdate-rmin.cpp
- /library/SegmentTree/old/rupdate-rmin.cpp.html
title: SegmentTree/old/rupdate-rmin.cpp
---