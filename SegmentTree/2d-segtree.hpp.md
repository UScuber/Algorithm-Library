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
  bundledCode: "#line 1 \"SegmentTree/2d-segtree.hpp\"\ntemplate <class T, T(*op)(const\
    \ T&, const T&), const T(*e)()>\r\nstruct SegmentTree2D {\r\n  int h,w, logh,logw;\r\
    \n  vector<vector<T>> d;\r\n  SegmentTree2D() : SegmentTree2D(0, 0){}\r\n  SegmentTree2D(const\
    \ int _h, const int _w){\r\n    h = w = 1;\r\n    logh = logw = 1;\r\n    while((h\
    \ <<= 1) < _h) logh++;\r\n    while((w <<= 1) < _w) logw++;\r\n    d.resize(h\
    \ * 2, vector<T>(w * 2, e()));\r\n  }\r\n  void set(const int i, const int j,\
    \ const T x){\r\n    d[i + h][j + w] += x;\r\n  }\r\n  void build(){\r\n    for(int\
    \ i = 2*h-1; i >= h ; i--){\r\n      for(int j = w - 1; j >= 1; j--)\r\n     \
    \   updateX(i, j);\r\n    }\r\n    for(int i = h-1; i >= 1; i--){\r\n      for(int\
    \ j = 2*w-1; j >= 1; j--)\r\n        updateY(i, j);\r\n    }\r\n  }\r\n  void\
    \ update(int py, int px, const T x){\r\n    assert(0 <= py && py < h);\r\n   \
    \ assert(0 <= px && px < w);\r\n    py += h, px += w;\r\n    d[py][px] += x;\r\
    \n    for(int j = 1; j <= logw; j++){\r\n      updateX(py, px >> j);\r\n    }\r\
    \n    for(int i = 1; i <= logh; i++){\r\n      for(int j = 0; j <= logw; j++){\r\
    \n        updateY(py >> i, px >> j);\r\n      }\r\n    }\r\n  }\r\n  T get(const\
    \ int py, const int px){\r\n    assert(0 <= py && py < h);\r\n    assert(0 <=\
    \ px && px < w);\r\n    return d[py + h][px + w];\r\n  }\r\n  T query(int ly,\
    \ int lx, int ry, int rx){\r\n    assert(0 <= ly && ly <= ry && ry <= h);\r\n\
    \    assert(0 <= lx && lx <= rx && rx <= w);\r\n    T sml = e(), smr = e();\r\n\
    \    ly += h;\r\n    ry += h;\r\n    while(ly < ry){\r\n      if(ly & 1) sml =\
    \ op(sml, query_sub(lx, rx, ly++));\r\n      if(ry & 1) smr = op(query_sub(lx,\
    \ rx, --ry), smr);\r\n      ly >>= 1;\r\n      ry >>= 1;\r\n    }\r\n    return\
    \ op(sml, smr);\r\n  }\r\n  private:\r\n  T query_sub(int lx, int rx, const int\
    \ y){\r\n    T sml = e(), smr = e();\r\n    lx += w;\r\n    rx += w;\r\n    while(lx\
    \ < rx){\r\n      if(lx & 1) sml = op(sml, d[y][lx++]);\r\n      if(rx & 1) smr\
    \ = op(d[y][--rx], smr);\r\n      lx >>= 1;\r\n      rx >>= 1;\r\n    }\r\n  \
    \  return op(sml, smr);\r\n  }\r\n  inline void updateX(const int i, const int\
    \ j){\r\n    d[i][j] = op(d[i][2*j], d[i][2*j+1]);\r\n  }\r\n  inline void updateY(const\
    \ int i, const int j){\r\n    d[i][j] = op(d[2*i][j], d[2*i+1][j]);\r\n  }\r\n\
    };\r\n\r\ntemplate <class T>\r\nT op(const T &a, const T &b){\r\n  return a +\
    \ b;\r\n}\r\ntemplate <class T>\r\nconst T e(){\r\n  return 0;\r\n}\n"
  code: "template <class T, T(*op)(const T&, const T&), const T(*e)()>\r\nstruct SegmentTree2D\
    \ {\r\n  int h,w, logh,logw;\r\n  vector<vector<T>> d;\r\n  SegmentTree2D() :\
    \ SegmentTree2D(0, 0){}\r\n  SegmentTree2D(const int _h, const int _w){\r\n  \
    \  h = w = 1;\r\n    logh = logw = 1;\r\n    while((h <<= 1) < _h) logh++;\r\n\
    \    while((w <<= 1) < _w) logw++;\r\n    d.resize(h * 2, vector<T>(w * 2, e()));\r\
    \n  }\r\n  void set(const int i, const int j, const T x){\r\n    d[i + h][j +\
    \ w] += x;\r\n  }\r\n  void build(){\r\n    for(int i = 2*h-1; i >= h ; i--){\r\
    \n      for(int j = w - 1; j >= 1; j--)\r\n        updateX(i, j);\r\n    }\r\n\
    \    for(int i = h-1; i >= 1; i--){\r\n      for(int j = 2*w-1; j >= 1; j--)\r\
    \n        updateY(i, j);\r\n    }\r\n  }\r\n  void update(int py, int px, const\
    \ T x){\r\n    assert(0 <= py && py < h);\r\n    assert(0 <= px && px < w);\r\n\
    \    py += h, px += w;\r\n    d[py][px] += x;\r\n    for(int j = 1; j <= logw;\
    \ j++){\r\n      updateX(py, px >> j);\r\n    }\r\n    for(int i = 1; i <= logh;\
    \ i++){\r\n      for(int j = 0; j <= logw; j++){\r\n        updateY(py >> i, px\
    \ >> j);\r\n      }\r\n    }\r\n  }\r\n  T get(const int py, const int px){\r\n\
    \    assert(0 <= py && py < h);\r\n    assert(0 <= px && px < w);\r\n    return\
    \ d[py + h][px + w];\r\n  }\r\n  T query(int ly, int lx, int ry, int rx){\r\n\
    \    assert(0 <= ly && ly <= ry && ry <= h);\r\n    assert(0 <= lx && lx <= rx\
    \ && rx <= w);\r\n    T sml = e(), smr = e();\r\n    ly += h;\r\n    ry += h;\r\
    \n    while(ly < ry){\r\n      if(ly & 1) sml = op(sml, query_sub(lx, rx, ly++));\r\
    \n      if(ry & 1) smr = op(query_sub(lx, rx, --ry), smr);\r\n      ly >>= 1;\r\
    \n      ry >>= 1;\r\n    }\r\n    return op(sml, smr);\r\n  }\r\n  private:\r\n\
    \  T query_sub(int lx, int rx, const int y){\r\n    T sml = e(), smr = e();\r\n\
    \    lx += w;\r\n    rx += w;\r\n    while(lx < rx){\r\n      if(lx & 1) sml =\
    \ op(sml, d[y][lx++]);\r\n      if(rx & 1) smr = op(d[y][--rx], smr);\r\n    \
    \  lx >>= 1;\r\n      rx >>= 1;\r\n    }\r\n    return op(sml, smr);\r\n  }\r\n\
    \  inline void updateX(const int i, const int j){\r\n    d[i][j] = op(d[i][2*j],\
    \ d[i][2*j+1]);\r\n  }\r\n  inline void updateY(const int i, const int j){\r\n\
    \    d[i][j] = op(d[2*i][j], d[2*i+1][j]);\r\n  }\r\n};\r\n\r\ntemplate <class\
    \ T>\r\nT op(const T &a, const T &b){\r\n  return a + b;\r\n}\r\ntemplate <class\
    \ T>\r\nconst T e(){\r\n  return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: SegmentTree/2d-segtree.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: SegmentTree/2d-segtree.hpp
layout: document
redirect_from:
- /library/SegmentTree/2d-segtree.hpp
- /library/SegmentTree/2d-segtree.hpp.html
title: SegmentTree/2d-segtree.hpp
---
