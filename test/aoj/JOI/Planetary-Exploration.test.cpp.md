---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/CumulativeSum2D.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/aoj/JOI/Planetary-Exploration.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\n\n#line 1 \"template/template.hpp\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/aoj/JOI/Planetary-Exploration.test.cpp\"\n\n\
    #line 1 \"data-structure/CumulativeSum2D.hpp\"\ntemplate <class T>\r\nstruct CumulativeSum2D\
    \ {\r\n  CumulativeSum2D(const int h, const int w) : h(h), w(w), a(h+1, vector<T>(w+1)){}\r\
    \n  CumulativeSum2D(const vector<vector<T>> &v) : h(v.size()), w(v[0].size()),\
    \ a(h+1, vector<T>(w+1)){\r\n    for(int i = 0; i < h; i++)\r\n      for(int j\
    \ = 0; j < w; j++) a[i + 1][j + 1] = v[i][j];\r\n  }\r\n  void set(const int i,\
    \ const int j, const T x){\r\n    assert(0 <= i && i < h);\r\n    assert(0 <=\
    \ j && j < w);\r\n    a[i + 1][j + 1] += x;\r\n  }\r\n  void build(){\r\n    for(int\
    \ i = 0; i < h; i++)\r\n      for(int j = 0; j < w; j++)\r\n        a[i + 1][j\
    \ + 1] += a[i + 1][j] + a[i][j + 1] - a[i][j];\r\n  }\r\n  T query(const int ly,\
    \ const int lx, const int ry, const int rx) const{\r\n    assert(0 <= ly && ly\
    \ <= ry && ry <= h);\r\n    assert(0 <= lx && lx <= rx && rx <= w);\r\n    return\
    \ a[ry][rx] - a[ry][lx] - a[ly][rx] + a[ly][lx];\r\n  }\r\n  private:\r\n  int\
    \ h, w;\r\n  vector<vector<T>> a;\r\n};\r\n#line 6 \"test/aoj/JOI/Planetary-Exploration.test.cpp\"\
    \n\nconst string t = \"JOI\";\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int n,m,K;\n  cin >> n >> m >> K;\n  vector<CumulativeSum2D<int>> cnt(3, CumulativeSum2D<int>(n,\
    \ m));\n  rep(i, n){\n    string s; cin >> s;\n    rep(j, m){\n      rep(k, 3)\
    \ if(s[j] == t[k]){\n        cnt[k].set(i, j, 1);\n        break;\n      }\n \
    \   }\n  }\n  rep(i, 3) cnt[i].build();\n  rep(_, K){\n    int a,b,c,d;\n    cin\
    \ >> a >> b >> c >> d;\n    a--; b--;\n    rep(i, 3) cout << cnt[i].query(a, b,\
    \ c, d) << \" \\n\"[i == 2];\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/0560\"\n\n#include\
    \ \"../../../template/template.hpp\"\n\n#include \"../../../data-structure/CumulativeSum2D.hpp\"\
    \n\nconst string t = \"JOI\";\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int n,m,K;\n  cin >> n >> m >> K;\n  vector<CumulativeSum2D<int>> cnt(3, CumulativeSum2D<int>(n,\
    \ m));\n  rep(i, n){\n    string s; cin >> s;\n    rep(j, m){\n      rep(k, 3)\
    \ if(s[j] == t[k]){\n        cnt[k].set(i, j, 1);\n        break;\n      }\n \
    \   }\n  }\n  rep(i, 3) cnt[i].build();\n  rep(_, K){\n    int a,b,c,d;\n    cin\
    \ >> a >> b >> c >> d;\n    a--; b--;\n    rep(i, 3) cout << cnt[i].query(a, b,\
    \ c, d) << \" \\n\"[i == 2];\n  }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/CumulativeSum2D.hpp
  isVerificationFile: true
  path: test/aoj/JOI/Planetary-Exploration.test.cpp
  requiredBy: []
  timestamp: '2023-03-13 22:03:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/JOI/Planetary-Exploration.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/JOI/Planetary-Exploration.test.cpp
- /verify/test/aoj/JOI/Planetary-Exploration.test.cpp.html
title: test/aoj/JOI/Planetary-Exploration.test.cpp
---
