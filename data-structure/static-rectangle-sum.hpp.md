---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/BinaryIndexedTree.hpp
    title: SegmentTree/BinaryIndexedTree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Data-Structure/Rectangle-Sum.test.cpp
    title: test/yosupo/Data-Structure/Rectangle-Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ 1;\r\n  vector<T> d;\r\n};\n#line 2 \"data-structure/static-rectangle-sum.hpp\"\
    \n\ntemplate <class T, class F>\nstruct RectangleSum {\n  struct Point {\n   \
    \ T y,x; F w;\n    bool operator<(const Point &a) const{ return y < a.y; }\n \
    \ };\n  struct Query {\n    T y,x, tx; //[x, tx)\n    int idx = -1; bool add;\n\
    \    bool operator<(const Query &a) const{ return y < a.y; }\n  };\n  vector<Query>\
    \ query;\n  vector<Point> ps;\n  vector<T> posx;\n  int idx = 0;\n  RectangleSum(){}\n\
    \  void add_point(const T &y, const T &x, const F &w){\n    ps.emplace_back((Point){\
    \ y, x, w });\n    posx.emplace_back(x);\n  }\n  void add_rect(const T &ly, const\
    \ T &lx, const T &ry, const T &rx){\n    query.emplace_back((Query){ ly, lx, rx,\
    \ idx, 0 });\n    query.emplace_back((Query){ ry, lx, rx, idx, 1 });\n    idx++;\n\
    \  }\n  inline int get_pos(const T &x) const{\n    return lower_bound(posx.begin(),\
    \ posx.end(), x) - posx.begin();\n  }\n  vector<F> run(){\n    sort(posx.begin(),\
    \ posx.end());\n    posx.erase(unique(posx.begin(), posx.end()), posx.end());\n\
    \    sort(query.begin(), query.end());\n    sort(ps.begin(), ps.end());\n    int\
    \ cur = 0;\n    vector<F> ans(idx);\n    BIT<F> seg(posx.size());\n    for(const\
    \ Query &que : query){\n      while(cur != ps.size() && ps[cur].y < que.y){\n\
    \        seg.add(get_pos(ps[cur].x), ps[cur].w);\n        cur++;\n      }\n  \
    \    int l = get_pos(que.x), r = get_pos(que.tx);\n      const F v = seg.sum(l,\
    \ r);\n      if(que.add) ans[que.idx] += v;\n      else ans[que.idx] -= v;\n \
    \   }\n    return ans;\n  }\n};\n"
  code: "#include \"../SegmentTree/BinaryIndexedTree.hpp\"\n\ntemplate <class T, class\
    \ F>\nstruct RectangleSum {\n  struct Point {\n    T y,x; F w;\n    bool operator<(const\
    \ Point &a) const{ return y < a.y; }\n  };\n  struct Query {\n    T y,x, tx; //[x,\
    \ tx)\n    int idx = -1; bool add;\n    bool operator<(const Query &a) const{\
    \ return y < a.y; }\n  };\n  vector<Query> query;\n  vector<Point> ps;\n  vector<T>\
    \ posx;\n  int idx = 0;\n  RectangleSum(){}\n  void add_point(const T &y, const\
    \ T &x, const F &w){\n    ps.emplace_back((Point){ y, x, w });\n    posx.emplace_back(x);\n\
    \  }\n  void add_rect(const T &ly, const T &lx, const T &ry, const T &rx){\n \
    \   query.emplace_back((Query){ ly, lx, rx, idx, 0 });\n    query.emplace_back((Query){\
    \ ry, lx, rx, idx, 1 });\n    idx++;\n  }\n  inline int get_pos(const T &x) const{\n\
    \    return lower_bound(posx.begin(), posx.end(), x) - posx.begin();\n  }\n  vector<F>\
    \ run(){\n    sort(posx.begin(), posx.end());\n    posx.erase(unique(posx.begin(),\
    \ posx.end()), posx.end());\n    sort(query.begin(), query.end());\n    sort(ps.begin(),\
    \ ps.end());\n    int cur = 0;\n    vector<F> ans(idx);\n    BIT<F> seg(posx.size());\n\
    \    for(const Query &que : query){\n      while(cur != ps.size() && ps[cur].y\
    \ < que.y){\n        seg.add(get_pos(ps[cur].x), ps[cur].w);\n        cur++;\n\
    \      }\n      int l = get_pos(que.x), r = get_pos(que.tx);\n      const F v\
    \ = seg.sum(l, r);\n      if(que.add) ans[que.idx] += v;\n      else ans[que.idx]\
    \ -= v;\n    }\n    return ans;\n  }\n};"
  dependsOn:
  - SegmentTree/BinaryIndexedTree.hpp
  isVerificationFile: false
  path: data-structure/static-rectangle-sum.hpp
  requiredBy: []
  timestamp: '2023-03-31 18:03:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Data-Structure/Rectangle-Sum.test.cpp
documentation_of: data-structure/static-rectangle-sum.hpp
layout: document
redirect_from:
- /library/data-structure/static-rectangle-sum.hpp
- /library/data-structure/static-rectangle-sum.hpp.html
title: data-structure/static-rectangle-sum.hpp
---
