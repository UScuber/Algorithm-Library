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
  bundledCode: "#line 1 \"SegmentTree/RangeMex.hpp\"\ntemplate<class T>\r\nstruct\
    \ SegmentTree {\r\n  SegmentTree(int _n) : n(_n){\r\n    while((1 << log) < n)\
    \ log++;\r\n    len = 1 << log;\r\n    d.assign(len * 2, -1);\r\n  }\r\n  void\
    \ update(int k, const T &x){\r\n    assert(0 <= k && k < n);\r\n    k += len;\r\
    \n    d[k] = x;\r\n    while(k > 1){\r\n      k >>= 1;\r\n      d[k] = min(d[k*2],\
    \ d[k*2+1]);\r\n    }\r\n  }\r\n  int min_left(int l, int r, const T &x) const{\r\
    \n    assert(0 <= l && l <= r && r <= n);\r\n    return min_left_sub(l, r, x,\
    \ 1, 0, len);\r\n  }\r\n  private:\r\n  const T inf = numeric_limits<T>::max()\
    \ - 1;\r\n  int n = 1, log = 0, len = 0;\r\n  vector<T> d;\r\n  //\u7BC4\u56F2\
    \u5916\u3067\u3042\u308C\u3070return b\r\n  int min_left_sub(int a, int b, const\
    \ T &x, int k, int l, int r) const{\r\n    if(d[k] > x || r <= a || b <= l) return\
    \ b;\r\n    if(k >= len) return k - len;\r\n    int vlef = min_left_sub(a, b,\
    \ x, 2*k, l, (l+r)/2);\r\n    if(vlef != b) return vlef;\r\n    return min_left_sub(a,\
    \ b, x, 2*k+1, (l+r)/2, r);\r\n  }\r\n};\r\nstruct RangeMexQuery {\r\n  RangeMexQuery(const\
    \ vector<int> &a) : d(a), n(a.size()), root(a.size()){}\r\n  //add_query [l, r)\
    \ 0-indexed\r\n  void add_query(const int &l, const int &r){\r\n    assert(0 <=\
    \ l && l <= r && r <= n);\r\n    root[r-1].emplace_back(l, idx);\r\n    idx++;\r\
    \n  }\r\n  void build(){\r\n    SegmentTree<int> seg(n + 1);\r\n    res.assign(idx,\
    \ -1);\r\n    for(int i = 0; i < n; i++){\r\n      seg.update(d[i], i);\r\n  \
    \    for(auto &x : root[i]){\r\n        int pos = seg.min_left(0, n+1, x.first-1);\r\
    \n        res[x.second] = pos;\r\n      }\r\n    }\r\n  }\r\n  vector<int> &get(){\
    \ return res; }\r\n  private:\r\n  vector<int> d, res;\r\n  vector<vector<pair<int,int>>>\
    \ root;\r\n  int n, idx = 0;\r\n};\n"
  code: "template<class T>\r\nstruct SegmentTree {\r\n  SegmentTree(int _n) : n(_n){\r\
    \n    while((1 << log) < n) log++;\r\n    len = 1 << log;\r\n    d.assign(len\
    \ * 2, -1);\r\n  }\r\n  void update(int k, const T &x){\r\n    assert(0 <= k &&\
    \ k < n);\r\n    k += len;\r\n    d[k] = x;\r\n    while(k > 1){\r\n      k >>=\
    \ 1;\r\n      d[k] = min(d[k*2], d[k*2+1]);\r\n    }\r\n  }\r\n  int min_left(int\
    \ l, int r, const T &x) const{\r\n    assert(0 <= l && l <= r && r <= n);\r\n\
    \    return min_left_sub(l, r, x, 1, 0, len);\r\n  }\r\n  private:\r\n  const\
    \ T inf = numeric_limits<T>::max() - 1;\r\n  int n = 1, log = 0, len = 0;\r\n\
    \  vector<T> d;\r\n  //\u7BC4\u56F2\u5916\u3067\u3042\u308C\u3070return b\r\n\
    \  int min_left_sub(int a, int b, const T &x, int k, int l, int r) const{\r\n\
    \    if(d[k] > x || r <= a || b <= l) return b;\r\n    if(k >= len) return k -\
    \ len;\r\n    int vlef = min_left_sub(a, b, x, 2*k, l, (l+r)/2);\r\n    if(vlef\
    \ != b) return vlef;\r\n    return min_left_sub(a, b, x, 2*k+1, (l+r)/2, r);\r\
    \n  }\r\n};\r\nstruct RangeMexQuery {\r\n  RangeMexQuery(const vector<int> &a)\
    \ : d(a), n(a.size()), root(a.size()){}\r\n  //add_query [l, r) 0-indexed\r\n\
    \  void add_query(const int &l, const int &r){\r\n    assert(0 <= l && l <= r\
    \ && r <= n);\r\n    root[r-1].emplace_back(l, idx);\r\n    idx++;\r\n  }\r\n\
    \  void build(){\r\n    SegmentTree<int> seg(n + 1);\r\n    res.assign(idx, -1);\r\
    \n    for(int i = 0; i < n; i++){\r\n      seg.update(d[i], i);\r\n      for(auto\
    \ &x : root[i]){\r\n        int pos = seg.min_left(0, n+1, x.first-1);\r\n   \
    \     res[x.second] = pos;\r\n      }\r\n    }\r\n  }\r\n  vector<int> &get(){\
    \ return res; }\r\n  private:\r\n  vector<int> d, res;\r\n  vector<vector<pair<int,int>>>\
    \ root;\r\n  int n, idx = 0;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/RangeMex.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/RangeMex.hpp
layout: document
redirect_from:
- /library/SegmentTree/RangeMex.hpp
- /library/SegmentTree/RangeMex.hpp.html
title: SegmentTree/RangeMex.hpp
---
