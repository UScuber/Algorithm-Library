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
  bundledCode: "#line 1 \"SegmentTree/RangeMex.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate<class T>\nstruct SegmentTree {\n  SegmentTree(int\
    \ _n) : n(_n){\n    while((1 << log) < n) log++;\n    len = 1 << log;\n    d.assign(len\
    \ * 2, -1);\n  }\n  void update(int k, const T &x){\n    assert(0 <= k && k <\
    \ n);\n    k += len;\n    d[k] = x;\n    while(k > 1){\n      k >>= 1;\n     \
    \ d[k] = min(d[k*2], d[k*2+1]);\n    }\n  }\n  int min_left(int l, int r, const\
    \ T &x) const{\n    assert(0 <= l && l <= r && r <= n);\n    return min_left_sub(l,\
    \ r, x, 1, 0, len);\n  }\n  private:\n  const T inf = numeric_limits<T>::max()\
    \ - 1;\n  int n = 1, log = 0, len = 0;\n  vector<T> d;\n  //\u7BC4\u56F2\u5916\
    \u3067\u3042\u308C\u3070return b\n  int min_left_sub(int a, int b, const T &x,\
    \ int k, int l, int r) const{\n    if(d[k] > x || r <= a || b <= l) return b;\n\
    \    if(k >= len) return k - len;\n    int vlef = min_left_sub(a, b, x, 2*k, l,\
    \ (l+r)/2);\n    if(vlef != b) return vlef;\n    return min_left_sub(a, b, x,\
    \ 2*k+1, (l+r)/2, r);\n  }\n};\nstruct RangeMexQuery {\n  RangeMexQuery(const\
    \ vector<int> &a) : d(a), n(a.size()), root(a.size()){}\n  //add_query [l, r)\
    \ 0-indexed\n  void add_query(const int &l, const int &r){\n    assert(0 <= l\
    \ && l <= r && r <= n);\n    root[r-1].emplace_back(l, idx);\n    idx++;\n  }\n\
    \  void build(){\n    SegmentTree<int> seg(n + 1);\n    res.assign(idx, -1);\n\
    \    for(int i = 0; i < n; i++){\n      seg.update(d[i], i);\n      for(auto &x\
    \ : root[i]){\n        int pos = seg.min_left(0, n+1, x.first-1);\n        res[x.second]\
    \ = pos;\n      }\n    }\n  }\n  vector<int> &get(){ return res; }\n  private:\n\
    \  vector<int> d, res;\n  vector<vector<pair<int,int>>> root;\n  int n, idx =\
    \ 0;\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate<class T>\nstruct\
    \ SegmentTree {\n  SegmentTree(int _n) : n(_n){\n    while((1 << log) < n) log++;\n\
    \    len = 1 << log;\n    d.assign(len * 2, -1);\n  }\n  void update(int k, const\
    \ T &x){\n    assert(0 <= k && k < n);\n    k += len;\n    d[k] = x;\n    while(k\
    \ > 1){\n      k >>= 1;\n      d[k] = min(d[k*2], d[k*2+1]);\n    }\n  }\n  int\
    \ min_left(int l, int r, const T &x) const{\n    assert(0 <= l && l <= r && r\
    \ <= n);\n    return min_left_sub(l, r, x, 1, 0, len);\n  }\n  private:\n  const\
    \ T inf = numeric_limits<T>::max() - 1;\n  int n = 1, log = 0, len = 0;\n  vector<T>\
    \ d;\n  //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070return b\n  int min_left_sub(int\
    \ a, int b, const T &x, int k, int l, int r) const{\n    if(d[k] > x || r <= a\
    \ || b <= l) return b;\n    if(k >= len) return k - len;\n    int vlef = min_left_sub(a,\
    \ b, x, 2*k, l, (l+r)/2);\n    if(vlef != b) return vlef;\n    return min_left_sub(a,\
    \ b, x, 2*k+1, (l+r)/2, r);\n  }\n};\nstruct RangeMexQuery {\n  RangeMexQuery(const\
    \ vector<int> &a) : d(a), n(a.size()), root(a.size()){}\n  //add_query [l, r)\
    \ 0-indexed\n  void add_query(const int &l, const int &r){\n    assert(0 <= l\
    \ && l <= r && r <= n);\n    root[r-1].emplace_back(l, idx);\n    idx++;\n  }\n\
    \  void build(){\n    SegmentTree<int> seg(n + 1);\n    res.assign(idx, -1);\n\
    \    for(int i = 0; i < n; i++){\n      seg.update(d[i], i);\n      for(auto &x\
    \ : root[i]){\n        int pos = seg.min_left(0, n+1, x.first-1);\n        res[x.second]\
    \ = pos;\n      }\n    }\n  }\n  vector<int> &get(){ return res; }\n  private:\n\
    \  vector<int> d, res;\n  vector<vector<pair<int,int>>> root;\n  int n, idx =\
    \ 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/RangeMex.cpp
  requiredBy: []
  timestamp: '2022-03-23 22:41:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/RangeMex.cpp
layout: document
redirect_from:
- /library/SegmentTree/RangeMex.cpp
- /library/SegmentTree/RangeMex.cpp.html
title: SegmentTree/RangeMex.cpp
---
