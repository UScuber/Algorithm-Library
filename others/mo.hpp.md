---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Static-Range-Inversions-Query.test.cpp
    title: test/yosupo/Static-Range-Inversions-Query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"others/mo.hpp\"\nll value = 0;\r\nstruct Mo {\r\n  struct\
    \ Query { int l,r,b,idx; };\r\n  vector<ll> res;\r\n  vector<Query> d;\r\n  int\
    \ width, n, q;\r\n  Mo(int n, int q) : n(n), q(q), width(max(1.0, n/max(1.0, sqrt(q*2.0/3)))),\
    \ res(q), d(q){}\r\n  void insert(const int &l, const int &r){\r\n    assert(0\
    \ <= l && l <= r && r <= n);\r\n    static int idx = 0;\r\n    d[idx] = { l, r,\
    \ l / width, idx };\r\n    idx++;\r\n  }\r\n  void build(){\r\n    sort(d.begin(),\
    \ d.end(), [&](const Query &a, const Query &b){\r\n      if(a.b != b.b) return\
    \ a.b < b.b;\r\n      return (a.b & 1) ? a.r > b.r : a.r < b.r;\r\n    });\r\n\
    \    int nl = 0, nr = 0;\r\n    for(const auto &v : d){\r\n      while(nl > v.l)\
    \ add_left(--nl);\r\n      while(nr < v.r) add_right(nr++);\r\n      while(nl\
    \ < v.l) del_left(nl++);\r\n      while(nr > v.r) del_right(--nr);\r\n      res[v.idx]\
    \ = value;\r\n    }\r\n  }\r\n  void add_left(int p);\r\n  void add_right(int\
    \ p);\r\n  void del_left(int p);\r\n  void del_right(int p);\r\n};\n"
  code: "ll value = 0;\r\nstruct Mo {\r\n  struct Query { int l,r,b,idx; };\r\n  vector<ll>\
    \ res;\r\n  vector<Query> d;\r\n  int width, n, q;\r\n  Mo(int n, int q) : n(n),\
    \ q(q), width(max(1.0, n/max(1.0, sqrt(q*2.0/3)))), res(q), d(q){}\r\n  void insert(const\
    \ int &l, const int &r){\r\n    assert(0 <= l && l <= r && r <= n);\r\n    static\
    \ int idx = 0;\r\n    d[idx] = { l, r, l / width, idx };\r\n    idx++;\r\n  }\r\
    \n  void build(){\r\n    sort(d.begin(), d.end(), [&](const Query &a, const Query\
    \ &b){\r\n      if(a.b != b.b) return a.b < b.b;\r\n      return (a.b & 1) ? a.r\
    \ > b.r : a.r < b.r;\r\n    });\r\n    int nl = 0, nr = 0;\r\n    for(const auto\
    \ &v : d){\r\n      while(nl > v.l) add_left(--nl);\r\n      while(nr < v.r) add_right(nr++);\r\
    \n      while(nl < v.l) del_left(nl++);\r\n      while(nr > v.r) del_right(--nr);\r\
    \n      res[v.idx] = value;\r\n    }\r\n  }\r\n  void add_left(int p);\r\n  void\
    \ add_right(int p);\r\n  void del_left(int p);\r\n  void del_right(int p);\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: others/mo.hpp
  requiredBy: []
  timestamp: '2023-03-14 01:17:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Static-Range-Inversions-Query.test.cpp
documentation_of: others/mo.hpp
layout: document
redirect_from:
- /library/others/mo.hpp
- /library/others/mo.hpp.html
title: others/mo.hpp
---
