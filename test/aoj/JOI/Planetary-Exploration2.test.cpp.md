---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/2d-segtree.hpp
    title: SegmentTree/2d-segtree.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/0560
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/0560
  bundledCode: "#line 1 \"test/aoj/JOI/Planetary-Exploration2.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <iostream>\r\n#include <cmath>\r\n#include <string>\r\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <utility>\r\n#include <tuple>\r\n#include <cstdint>\r\
    \n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\n#include <set>\r\n\
    #include <stack>\r\n#include <deque>\r\n#include <unordered_map>\r\n#include <unordered_set>\r\
    \n#include <bitset>\r\n#include <cctype>\r\n#include <climits>\r\n#include <functional>\r\
    \n#include <cassert>\r\n#include <numeric>\r\n#define rep(i, n) for(int i = 0;\
    \ i < (n); i++)\r\n#define per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\nusing\
    \ ll = long long;\r\n#define vi vector<int>\r\n#define vvi vector<vi>\r\n#define\
    \ vl vector<ll>\r\n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n\
    #define all(a) (a).begin(), (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\
    \nconstexpr int mod = 1000000007;\r\nusing namespace std;\r\ntemplate<class T,\
    \ class U>\r\nbool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\
    \ntemplate<class T, class U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a\
    \ = b, 1) : 0; }\n#line 4 \"test/aoj/JOI/Planetary-Exploration2.test.cpp\"\n\n\
    #line 1 \"SegmentTree/2d-segtree.hpp\"\ntemplate <class T, T(*op)(const T&,const\
    \ T&), T(*e)()>\r\nstruct SegmentTree2D {\r\n  int h,w, logh,logw;\r\n  vector<vector<T>>\
    \ d;\r\n  SegmentTree2D() : SegmentTree2D(0, 0){}\r\n  SegmentTree2D(const int\
    \ _h, const int _w){\r\n    h = w = 1;\r\n    logh = logw = 1;\r\n    while((h\
    \ <<= 1) < _h) logh++;\r\n    while((w <<= 1) < _w) logw++;\r\n    d.assign(h\
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
    };\n#line 6 \"test/aoj/JOI/Planetary-Exploration2.test.cpp\"\n\nusing Data = int;\n\
    Data op(const Data &a, const Data &b){ return a + b; }\nData e(){ return 0; }\n\
    using Seg2D = SegmentTree2D<Data,op,e>;\n\nconst string t = \"JOI\";\nint main(){\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,m,K;\n  cin >> n\
    \ >> m >> K;\n  vector<Seg2D> cnt(3, Seg2D(n, m));\n  rep(i, n){\n    string s;\
    \ cin >> s;\n    rep(j, m){\n      rep(k, 3) if(s[j] == t[k]){\n        cnt[k].set(i,\
    \ j, 1);\n        break;\n      }\n    }\n  }\n  rep(i, 3) cnt[i].build();\n \
    \ rep(_, K){\n    int a,b,c,d;\n    cin >> a >> b >> c >> d;\n    a--; b--;\n\
    \    rep(i, 3) cout << cnt[i].query(a, b, c, d) << \" \\n\"[i == 2];\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\n\n#include\
    \ \"../../../template/template.hpp\"\n\n#include \"../../../SegmentTree/2d-segtree.hpp\"\
    \n\nusing Data = int;\nData op(const Data &a, const Data &b){ return a + b; }\n\
    Data e(){ return 0; }\nusing Seg2D = SegmentTree2D<Data,op,e>;\n\nconst string\
    \ t = \"JOI\";\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int n,m,K;\n  cin >> n >> m >> K;\n  vector<Seg2D> cnt(3, Seg2D(n, m));\n \
    \ rep(i, n){\n    string s; cin >> s;\n    rep(j, m){\n      rep(k, 3) if(s[j]\
    \ == t[k]){\n        cnt[k].set(i, j, 1);\n        break;\n      }\n    }\n  }\n\
    \  rep(i, 3) cnt[i].build();\n  rep(_, K){\n    int a,b,c,d;\n    cin >> a >>\
    \ b >> c >> d;\n    a--; b--;\n    rep(i, 3) cout << cnt[i].query(a, b, c, d)\
    \ << \" \\n\"[i == 2];\n  }\n}"
  dependsOn:
  - template/template.hpp
  - SegmentTree/2d-segtree.hpp
  isVerificationFile: true
  path: test/aoj/JOI/Planetary-Exploration2.test.cpp
  requiredBy: []
  timestamp: '2023-03-14 17:58:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/JOI/Planetary-Exploration2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/JOI/Planetary-Exploration2.test.cpp
- /verify/test/aoj/JOI/Planetary-Exploration2.test.cpp.html
title: test/aoj/JOI/Planetary-Exploration2.test.cpp
---
