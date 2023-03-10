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
  bundledCode: "#line 1 \"SegmentTree/2d-segtree.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T, T(*op)(const T&, const T&), const T(*e)()>\n\
    struct SegmentTree2D {\n  int h,w, logh,logw;\n  vector<vector<T>> d;\n  SegmentTree2D()\
    \ : SegmentTree2D(0, 0){}\n  SegmentTree2D(const int _h, const int _w){\n    h\
    \ = w = 1;\n    logh = logw = 1;\n    while((h <<= 1) < _h) logh++;\n    while((w\
    \ <<= 1) < _w) logw++;\n    d.resize(h * 2, vector<T>(w * 2, e()));\n  }\n  void\
    \ set(const int i, const int j, const T x){\n    d[i + h][j + w] += x;\n  }\n\
    \  void build(){\n    for(int i = 2*h-1; i >= h ; i--){\n      for(int j = w -\
    \ 1; j >= 1; j--)\n        updateX(i, j);\n    }\n    for(int i = h-1; i >= 1;\
    \ i--){\n      for(int j = 2*w-1; j >= 1; j--)\n        updateY(i, j);\n    }\n\
    \  }\n  void update(int py, int px, const T x){\n    assert(0 <= py && py < h);\n\
    \    assert(0 <= px && px < w);\n    py += h, px += w;\n    d[py][px] += x;\n\
    \    for(int j = 1; j <= logw; j++){\n      updateX(py, px >> j);\n    }\n   \
    \ for(int i = 1; i <= logh; i++){\n      for(int j = 0; j <= logw; j++){\n   \
    \     updateY(py >> i, px >> j);\n      }\n    }\n  }\n  T get(const int py, const\
    \ int px){\n    assert(0 <= py && py < h);\n    assert(0 <= px && px < w);\n \
    \   return d[py + h][px + w];\n  }\n  T query(int ly, int lx, int ry, int rx){\n\
    \    assert(0 <= ly && ly <= ry && ry <= h);\n    assert(0 <= lx && lx <= rx &&\
    \ rx <= w);\n    T sml = e(), smr = e();\n    ly += h;\n    ry += h;\n    while(ly\
    \ < ry){\n      if(ly & 1) sml = op(sml, query_sub(lx, rx, ly++));\n      if(ry\
    \ & 1) smr = op(query_sub(lx, rx, --ry), smr);\n      ly >>= 1;\n      ry >>=\
    \ 1;\n    }\n    return op(sml, smr);\n  }\n  private:\n  T query_sub(int lx,\
    \ int rx, const int y){\n    T sml = e(), smr = e();\n    lx += w;\n    rx +=\
    \ w;\n    while(lx < rx){\n      if(lx & 1) sml = op(sml, d[y][lx++]);\n     \
    \ if(rx & 1) smr = op(d[y][--rx], smr);\n      lx >>= 1;\n      rx >>= 1;\n  \
    \  }\n    return op(sml, smr);\n  }\n  inline void updateX(const int i, const\
    \ int j){\n    d[i][j] = op(d[i][2*j], d[i][2*j+1]);\n  }\n  inline void updateY(const\
    \ int i, const int j){\n    d[i][j] = op(d[2*i][j], d[2*i+1][j]);\n  }\n};\n\n\
    template <class T>\nT op(const T &a, const T &b){\n  return a + b;\n}\ntemplate\
    \ <class T>\nconst T e(){\n  return 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T, T(*op)(const\
    \ T&, const T&), const T(*e)()>\nstruct SegmentTree2D {\n  int h,w, logh,logw;\n\
    \  vector<vector<T>> d;\n  SegmentTree2D() : SegmentTree2D(0, 0){}\n  SegmentTree2D(const\
    \ int _h, const int _w){\n    h = w = 1;\n    logh = logw = 1;\n    while((h <<=\
    \ 1) < _h) logh++;\n    while((w <<= 1) < _w) logw++;\n    d.resize(h * 2, vector<T>(w\
    \ * 2, e()));\n  }\n  void set(const int i, const int j, const T x){\n    d[i\
    \ + h][j + w] += x;\n  }\n  void build(){\n    for(int i = 2*h-1; i >= h ; i--){\n\
    \      for(int j = w - 1; j >= 1; j--)\n        updateX(i, j);\n    }\n    for(int\
    \ i = h-1; i >= 1; i--){\n      for(int j = 2*w-1; j >= 1; j--)\n        updateY(i,\
    \ j);\n    }\n  }\n  void update(int py, int px, const T x){\n    assert(0 <=\
    \ py && py < h);\n    assert(0 <= px && px < w);\n    py += h, px += w;\n    d[py][px]\
    \ += x;\n    for(int j = 1; j <= logw; j++){\n      updateX(py, px >> j);\n  \
    \  }\n    for(int i = 1; i <= logh; i++){\n      for(int j = 0; j <= logw; j++){\n\
    \        updateY(py >> i, px >> j);\n      }\n    }\n  }\n  T get(const int py,\
    \ const int px){\n    assert(0 <= py && py < h);\n    assert(0 <= px && px < w);\n\
    \    return d[py + h][px + w];\n  }\n  T query(int ly, int lx, int ry, int rx){\n\
    \    assert(0 <= ly && ly <= ry && ry <= h);\n    assert(0 <= lx && lx <= rx &&\
    \ rx <= w);\n    T sml = e(), smr = e();\n    ly += h;\n    ry += h;\n    while(ly\
    \ < ry){\n      if(ly & 1) sml = op(sml, query_sub(lx, rx, ly++));\n      if(ry\
    \ & 1) smr = op(query_sub(lx, rx, --ry), smr);\n      ly >>= 1;\n      ry >>=\
    \ 1;\n    }\n    return op(sml, smr);\n  }\n  private:\n  T query_sub(int lx,\
    \ int rx, const int y){\n    T sml = e(), smr = e();\n    lx += w;\n    rx +=\
    \ w;\n    while(lx < rx){\n      if(lx & 1) sml = op(sml, d[y][lx++]);\n     \
    \ if(rx & 1) smr = op(d[y][--rx], smr);\n      lx >>= 1;\n      rx >>= 1;\n  \
    \  }\n    return op(sml, smr);\n  }\n  inline void updateX(const int i, const\
    \ int j){\n    d[i][j] = op(d[i][2*j], d[i][2*j+1]);\n  }\n  inline void updateY(const\
    \ int i, const int j){\n    d[i][j] = op(d[2*i][j], d[2*i+1][j]);\n  }\n};\n\n\
    template <class T>\nT op(const T &a, const T &b){\n  return a + b;\n}\ntemplate\
    \ <class T>\nconst T e(){\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/2d-segtree.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/2d-segtree.cpp
layout: document
redirect_from:
- /library/SegmentTree/2d-segtree.cpp
- /library/SegmentTree/2d-segtree.cpp.html
title: SegmentTree/2d-segtree.cpp
---
