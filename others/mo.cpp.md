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
  bundledCode: "#line 1 \"others/mo.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint value = 0;\nstruct Mo {\n  struct Query { int l,r,b,idx; };\n  vector<int>\
    \ res;\n  vector<Query> d;\n  int width, n, q;\n  Mo(int n, int q) : n(n), q(q),\
    \ width(max(1.0, n/max(1.0, sqrt(q*2.0/3)))), res(q), d(q){}\n  void insert(const\
    \ int &l, const int &r){\n    assert(0 <= l && l <= r && r <= n);\n    static\
    \ int idx = 0;\n    d[idx] = { l, r, l / width, idx };\n    idx++;\n  }\n  void\
    \ build(){\n    sort(d.begin(), d.end(), [&](const Query &a, const Query &b){\n\
    \      if(a.b != b.b) return a.b < b.b;\n      return (a.b & 1) ? a.r > b.r :\
    \ a.r < b.r;\n    });\n    int nl = 0, nr = 0;\n    for(const auto &v : d){\n\
    \      while(nl > v.l) add_left(--nl);\n      while(nr < v.r) add_right(nr++);\n\
    \      while(nl < v.l) del_left(nl++);\n      while(nr > v.r) del_right(--nr);\n\
    \      res[v.idx] = value;\n    }\n  }\n  void add_left(int p);\n  void add_right(int\
    \ p);\n  void del_left(int p);\n  void del_right(int p);\n};\nvoid Mo::add_left(int\
    \ p){\n  \n}\nvoid Mo::add_right(int p){\n\n}\nvoid Mo::del_left(int p){\n\n}\n\
    void Mo::del_right(int p){\n\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nint value = 0;\nstruct\
    \ Mo {\n  struct Query { int l,r,b,idx; };\n  vector<int> res;\n  vector<Query>\
    \ d;\n  int width, n, q;\n  Mo(int n, int q) : n(n), q(q), width(max(1.0, n/max(1.0,\
    \ sqrt(q*2.0/3)))), res(q), d(q){}\n  void insert(const int &l, const int &r){\n\
    \    assert(0 <= l && l <= r && r <= n);\n    static int idx = 0;\n    d[idx]\
    \ = { l, r, l / width, idx };\n    idx++;\n  }\n  void build(){\n    sort(d.begin(),\
    \ d.end(), [&](const Query &a, const Query &b){\n      if(a.b != b.b) return a.b\
    \ < b.b;\n      return (a.b & 1) ? a.r > b.r : a.r < b.r;\n    });\n    int nl\
    \ = 0, nr = 0;\n    for(const auto &v : d){\n      while(nl > v.l) add_left(--nl);\n\
    \      while(nr < v.r) add_right(nr++);\n      while(nl < v.l) del_left(nl++);\n\
    \      while(nr > v.r) del_right(--nr);\n      res[v.idx] = value;\n    }\n  }\n\
    \  void add_left(int p);\n  void add_right(int p);\n  void del_left(int p);\n\
    \  void del_right(int p);\n};\nvoid Mo::add_left(int p){\n  \n}\nvoid Mo::add_right(int\
    \ p){\n\n}\nvoid Mo::del_left(int p){\n\n}\nvoid Mo::del_right(int p){\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: others/mo.cpp
  requiredBy: []
  timestamp: '2022-03-09 15:44:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/mo.cpp
layout: document
redirect_from:
- /library/others/mo.cpp
- /library/others/mo.cpp.html
title: others/mo.cpp
---
