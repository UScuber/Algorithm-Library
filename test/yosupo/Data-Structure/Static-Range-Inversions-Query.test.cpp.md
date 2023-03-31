---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/BinaryIndexedTree.hpp
    title: SegmentTree/BinaryIndexedTree.hpp
  - icon: ':heavy_check_mark:'
    path: others/mo.hpp
    title: others/mo.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Static-Range-Inversions-Query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\
    \n#include <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <utility>\r\
    \n#include <tuple>\r\n#include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\
    \n#include <queue>\r\n#include <set>\r\n#include <stack>\r\n#include <deque>\r\
    \n#include <unordered_map>\r\n#include <unordered_set>\r\n#include <bitset>\r\n\
    #include <cctype>\r\n#include <climits>\r\n#include <functional>\r\n#include <cassert>\r\
    \n#include <numeric>\r\n#define rep(i, n) for(int i = 0; i < (n); i++)\r\n#define\
    \ per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\nusing ll = long long;\r\n#define\
    \ vi vector<int>\r\n#define vvi vector<vi>\r\n#define vl vector<ll>\r\n#define\
    \ pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n#define all(a) (a).begin(),\
    \ (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\nconstexpr int mod =\
    \ 1000000007;\r\nusing namespace std;\r\ntemplate<class T, class U>\r\nbool chmax(T\
    \ &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\ntemplate<class T, class\
    \ U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a = b, 1) : 0; }\n#line\
    \ 4 \"test/yosupo/Data-Structure/Static-Range-Inversions-Query.test.cpp\"\n\n\
    #line 1 \"others/mo.hpp\"\nll value = 0;\r\nstruct Mo {\r\n  struct Query { int\
    \ l,r,b,idx; };\r\n  vector<ll> res;\r\n  vector<Query> d;\r\n  int width, n,\
    \ q;\r\n  Mo(int n, int q) : n(n), q(q), width(max(1.0, n/max(1.0, sqrt(q*2.0/3)))),\
    \ res(q), d(q){}\r\n  void insert(const int &l, const int &r){\r\n    assert(0\
    \ <= l && l <= r && r <= n);\r\n    static int idx = 0;\r\n    d[idx] = { l, r,\
    \ l / width, idx };\r\n    idx++;\r\n  }\r\n  void build(){\r\n    sort(d.begin(),\
    \ d.end(), [&](const Query &a, const Query &b){\r\n      if(a.b != b.b) return\
    \ a.b < b.b;\r\n      return (a.b & 1) ? a.r > b.r : a.r < b.r;\r\n    });\r\n\
    \    int nl = 0, nr = 0;\r\n    for(const auto &v : d){\r\n      while(nl > v.l)\
    \ add_left(--nl);\r\n      while(nr < v.r) add_right(nr++);\r\n      while(nl\
    \ < v.l) del_left(nl++);\r\n      while(nr > v.r) del_right(--nr);\r\n      res[v.idx]\
    \ = value;\r\n    }\r\n  }\r\n  void add_left(int p);\r\n  void add_right(int\
    \ p);\r\n  void del_left(int p);\r\n  void del_right(int p);\r\n};\n#line 1 \"\
    SegmentTree/BinaryIndexedTree.hpp\"\ntemplate <class T>\r\nstruct BIT {\r\n  BIT(const\
    \ int _n = 0) : n(_n), d(n){}\r\n  BIT(const vector<T> &v) : d(v), n(v.size()){\r\
    \n    for(int i = 1; i <= n; i++){\r\n      const int j = i + (i & -i);\r\n  \
    \    if(j <= n) d[j - 1] += d[i - 1];\r\n    }\r\n  }\r\n  T sum(const int l,\
    \ const int r) const{\r\n    assert(0 <= l && l <= r && r <= n);\r\n    return\
    \ sum(r) - sum(l);\r\n  }\r\n  T sum(int i) const{\r\n    T tot = 0;\r\n    while(i\
    \ > 0){\r\n      tot += d[i - 1];\r\n      i -= i & -i;\r\n    }\r\n    return\
    \ tot;\r\n  }\r\n  void add(int i, const T &x){\r\n    assert(0 <= i && i < n);\r\
    \n    i++;\r\n    while(i <= n){\r\n      d[i - 1] += x;\r\n      i += i & -i;\r\
    \n    }\r\n  }\r\n  private:\r\n  int n = 1;\r\n  vector<T> d;\r\n};\n#line 7\
    \ \"test/yosupo/Data-Structure/Static-Range-Inversions-Query.test.cpp\"\n\nBIT<int>\
    \ seg;\nvi a;\n\nvoid Mo::add_left(int p){\n  value += seg.sum(0, a[p]);\n  seg.add(a[p],\
    \ 1);\n}\nvoid Mo::add_right(int p){\n  value += seg.sum(a[p] + 1, n);\n  seg.add(a[p],\
    \ 1);\n}\nvoid Mo::del_left(int p){\n  value -= seg.sum(0, a[p]);\n  seg.add(a[p],\
    \ -1);\n}\nvoid Mo::del_right(int p){\n  value -= seg.sum(a[p] + 1, n);\n  seg.add(a[p],\
    \ -1);\n}\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int n,q;\n  cin >> n >> q;\n  a.resize(n);\n  seg = BIT<int>(n);\n  rep(i,\
    \ n) cin >> a[i];\n  vi b = a;\n  sort(all(b));\n  b.erase(unique(all(b)), b.end());\n\
    \  rep(i, n) a[i] = lower_bound(all(b), a[i]) - b.begin();\n  Mo mo(n, q);\n \
    \ rep(i, q){\n    int l,r;\n    cin >> l >> r;\n    mo.insert(l, r);\n  }\n  mo.build();\n\
    \  rep(i, q) cout << mo.res[i] << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"../../../template/template.hpp\"\n\n#include \"../../../others/mo.hpp\"\
    \n#include \"../../../SegmentTree/BinaryIndexedTree.hpp\"\n\nBIT<int> seg;\nvi\
    \ a;\n\nvoid Mo::add_left(int p){\n  value += seg.sum(0, a[p]);\n  seg.add(a[p],\
    \ 1);\n}\nvoid Mo::add_right(int p){\n  value += seg.sum(a[p] + 1, n);\n  seg.add(a[p],\
    \ 1);\n}\nvoid Mo::del_left(int p){\n  value -= seg.sum(0, a[p]);\n  seg.add(a[p],\
    \ -1);\n}\nvoid Mo::del_right(int p){\n  value -= seg.sum(a[p] + 1, n);\n  seg.add(a[p],\
    \ -1);\n}\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int n,q;\n  cin >> n >> q;\n  a.resize(n);\n  seg = BIT<int>(n);\n  rep(i,\
    \ n) cin >> a[i];\n  vi b = a;\n  sort(all(b));\n  b.erase(unique(all(b)), b.end());\n\
    \  rep(i, n) a[i] = lower_bound(all(b), a[i]) - b.begin();\n  Mo mo(n, q);\n \
    \ rep(i, q){\n    int l,r;\n    cin >> l >> r;\n    mo.insert(l, r);\n  }\n  mo.build();\n\
    \  rep(i, q) cout << mo.res[i] << \"\\n\";\n}"
  dependsOn:
  - template/template.hpp
  - others/mo.hpp
  - SegmentTree/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Static-Range-Inversions-Query.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 19:15:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Static-Range-Inversions-Query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Static-Range-Inversions-Query.test.cpp
- /verify/test/yosupo/Data-Structure/Static-Range-Inversions-Query.test.cpp.html
title: test/yosupo/Data-Structure/Static-Range-Inversions-Query.test.cpp
---
