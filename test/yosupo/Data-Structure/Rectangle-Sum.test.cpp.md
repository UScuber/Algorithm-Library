---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: SegmentTree/BinaryIndexedTree.hpp
    title: SegmentTree/BinaryIndexedTree.hpp
  - icon: ':x:'
    path: data-structure/static-rectangle-sum.hpp
    title: data-structure/static-rectangle-sum.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Rectangle-Sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 1 \"template/template.hpp\"\
    \n#include <iostream>\r\n#include <cmath>\r\n#include <string>\r\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <tuple>\r\n#include <cstdint>\r\n#include <cstdio>\r\
    \n#include <map>\r\n#include <queue>\r\n#include <set>\r\n#include <stack>\r\n\
    #include <deque>\r\n#include <bitset>\r\n#include <cctype>\r\n#include <climits>\r\
    \n#include <functional>\r\n#include <cassert>\r\n#include <numeric>\r\n#include\
    \ <cstring>\r\n#define rep(i, n) for(int i = 0; i < (n); i++)\r\n#define per(i,\
    \ n) for(int i = (n) - 1; i >= 0; i--)\r\nusing ll = long long;\r\n#define vi\
    \ vector<int>\r\n#define vvi vector<vi>\r\n#define vl vector<ll>\r\n#define pii\
    \ pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define all(a) (a).begin(), (a).end()\r\
    \n#define rall(a) (a).rbegin(), (a).rend()\r\nconstexpr int mod = 1000000007;\r\
    \nusing namespace std;\r\ntemplate<class T, class U>\r\nbool chmax(T &a, const\
    \ U &b){ return a < b ? (a = b, 1) : 0; }\r\ntemplate<class T, class U>\r\nbool\
    \ chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }\n#line 4 \"test/yosupo/Data-Structure/Rectangle-Sum.test.cpp\"\
    \n\n#line 1 \"SegmentTree/BinaryIndexedTree.hpp\"\ntemplate <class T>\r\nstruct\
    \ BIT {\r\n  BIT(const int _n = 0) : n(_n), d(n){}\r\n  BIT(const vector<T> &v)\
    \ : d(v), n(v.size()){\r\n    for(int i = 1; i <= n; i++){\r\n      const int\
    \ j = i + (i & -i);\r\n      if(j <= n) d[j - 1] += d[i - 1];\r\n    }\r\n  }\r\
    \n  T sum(const int l, const int r) const{\r\n    assert(0 <= l && l <= r && r\
    \ <= n);\r\n    return sum(r) - sum(l);\r\n  }\r\n  T sum(int i) const{\r\n  \
    \  T tot = 0;\r\n    while(i > 0){\r\n      tot += d[i - 1];\r\n      i -= i &\
    \ -i;\r\n    }\r\n    return tot;\r\n  }\r\n  void add(int i, const T &x){\r\n\
    \    assert(0 <= i && i < n);\r\n    i++;\r\n    while(i <= n){\r\n      d[i -\
    \ 1] += x;\r\n      i += i & -i;\r\n    }\r\n  }\r\n  private:\r\n  int n = 1;\r\
    \n  vector<T> d;\r\n};\n#line 2 \"data-structure/static-rectangle-sum.hpp\"\n\n\
    template <class T, class F>\nstruct RectangleSum {\n  struct Point {\n    T y,x;\
    \ F w;\n    bool operator<(const Point &a) const{ return y < a.y; }\n  };\n  struct\
    \ Query {\n    T y,x, tx; //[x, tx)\n    int idx = -1; bool add;\n    bool operator<(const\
    \ Query &a) const{ return y < a.y; }\n  };\n  vector<Query> query;\n  vector<Point>\
    \ ps;\n  vector<T> posx;\n  int idx = 0;\n  RectangleSum(){}\n  void add_point(const\
    \ T &y, const T &x, const F &w){\n    ps.emplace_back((Point){ y, x, w });\n \
    \   posx.emplace_back(x);\n  }\n  void add_rect(const T &ly, const T &lx, const\
    \ T &ry, const T &rx){\n    query.emplace_back((Query){ ly, lx, rx, idx, 0 });\n\
    \    query.emplace_back((Query){ ry, lx, rx, idx, 1 });\n    idx++;\n  }\n  inline\
    \ int get_pos(const T &x) const{\n    return lower_bound(posx.begin(), posx.end(),\
    \ x) - posx.begin();\n  }\n  vector<F> run(){\n    sort(posx.begin(), posx.end());\n\
    \    posx.erase(unique(posx.begin(), posx.end()), posx.end());\n    sort(query.begin(),\
    \ query.end());\n    sort(ps.begin(), ps.end());\n    int cur = 0;\n    vector<F>\
    \ ans(idx);\n    BIT<F> seg(posx.size());\n    for(const Query &que : query){\n\
    \      while(cur != ps.size() && ps[cur].y < que.y){\n        seg.add(get_pos(ps[cur].x),\
    \ ps[cur].w);\n        cur++;\n      }\n      int l = get_pos(que.x), r = get_pos(que.tx);\n\
    \      const F v = seg.sum(l, r);\n      if(que.add) ans[que.idx] += v;\n    \
    \  else ans[que.idx] -= v;\n    }\n    return ans;\n  }\n};\n#line 6 \"test/yosupo/Data-Structure/Rectangle-Sum.test.cpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n\
    \  cin >> n >> q;\n  RectangleSum<int,ll> rs;\n  rep(i, n){\n    int x,y,w;\n\
    \    cin >> x >> y >> w;\n    rs.add_point(x, y, w);\n  }\n  rep(i, q){\n    int\
    \ l,d,r,u;\n    cin >> l >> d >> r >> u;\n    rs.add_rect(l, d, r, u);\n  }\n\
    \  for(const auto &x : rs.run()) cout << x << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../../../template/template.hpp\"\n\n#include \"../../../data-structure/static-rectangle-sum.hpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n\
    \  cin >> n >> q;\n  RectangleSum<int,ll> rs;\n  rep(i, n){\n    int x,y,w;\n\
    \    cin >> x >> y >> w;\n    rs.add_point(x, y, w);\n  }\n  rep(i, q){\n    int\
    \ l,d,r,u;\n    cin >> l >> d >> r >> u;\n    rs.add_rect(l, d, r, u);\n  }\n\
    \  for(const auto &x : rs.run()) cout << x << \"\\n\";\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/static-rectangle-sum.hpp
  - SegmentTree/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Rectangle-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-11 17:58:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Rectangle-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Rectangle-Sum.test.cpp
- /verify/test/yosupo/Data-Structure/Rectangle-Sum.test.cpp.html
title: test/yosupo/Data-Structure/Rectangle-Sum.test.cpp
---
