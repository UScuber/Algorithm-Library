---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/BinaryIndexedTree.hpp
    title: SegmentTree/BinaryIndexedTree.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL/DSL_2_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\
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
    \ 4 \"test/aoj/DSL/DSL_2_B.test.cpp\"\n\n#line 1 \"SegmentTree/BinaryIndexedTree.hpp\"\
    \ntemplate <class T>\r\nstruct BIT {\r\n  BIT(const int _n = 0) : n(_n), d(n){}\r\
    \n  BIT(const vector<T> &v) : d(v), n(v.size()){\r\n    for(int i = 1; i <= n;\
    \ i++){\r\n      const int j = i + (i & -i);\r\n      if(j <= n) d[j - 1] += d[i\
    \ - 1];\r\n    }\r\n  }\r\n  T sum(const int l, const int r) const{\r\n    assert(0\
    \ <= l && l <= r && r <= n);\r\n    return sum(r) - sum(l);\r\n  }\r\n  T sum(int\
    \ i) const{\r\n    T tot = 0;\r\n    while(i > 0){\r\n      tot += d[i - 1];\r\
    \n      i -= i & -i;\r\n    }\r\n    return tot;\r\n  }\r\n  void add(int i, const\
    \ T &x){\r\n    assert(0 <= i && i < n);\r\n    i++;\r\n    while(i <= n){\r\n\
    \      d[i - 1] += x;\r\n      i += i & -i;\r\n    }\r\n  }\r\n  private:\r\n\
    \  int n = 1;\r\n  vector<T> d;\r\n};\n#line 6 \"test/aoj/DSL/DSL_2_B.test.cpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n\
    \  cin >> n >> q;\n  BIT<int> seg(n);\n  while(q--){\n    int t,x,y;\n    cin\
    \ >> t >> x >> y;\n    x--;\n    if(t == 0){\n      seg.add(x, y);\n    }else{\n\
    \      cout << seg.sum(x, y) << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../SegmentTree/BinaryIndexedTree.hpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n\
    \  cin >> n >> q;\n  BIT<int> seg(n);\n  while(q--){\n    int t,x,y;\n    cin\
    \ >> t >> x >> y;\n    x--;\n    if(t == 0){\n      seg.add(x, y);\n    }else{\n\
    \      cout << seg.sum(x, y) << \"\\n\";\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - SegmentTree/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2023-03-14 17:59:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_2_B.test.cpp
- /verify/test/aoj/DSL/DSL_2_B.test.cpp.html
title: test/aoj/DSL/DSL_2_B.test.cpp
---
