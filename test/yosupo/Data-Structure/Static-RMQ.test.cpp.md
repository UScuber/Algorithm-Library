---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/SparseTable.hpp
    title: data-structure/SparseTable.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Static-RMQ.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"template/template.hpp\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Data-Structure/Static-RMQ.test.cpp\"\n\
    \n#line 1 \"data-structure/SparseTable.hpp\"\ntemplate <class T, const T&(*op)(const\
    \ T&,const T&)>\r\nstruct SparseTable {\r\n  int n;\r\n  vector<T> a;\r\n  private:\r\
    \n  vector<vector<T>> d;\r\n  vector<int> len;\r\n  T inf = numeric_limits<T>::max();\r\
    \n  public:\r\n  SparseTable(const int n) : n(n), a(n), len(n + 1){}\r\n  SparseTable(const\
    \ vector<T> &a) : a(a), n(a.size()), len(a.size() + 1){}\r\n  T &operator[](const\
    \ int i){ return a[i]; }\r\n  void build(){\r\n    inf = -op(inf, -inf);\r\n \
    \   int logn = 0;\r\n    while((1 << logn) < n) logn++;\r\n    d.resize(logn +\
    \ 1, vector<T>(n, inf));\r\n    d[0] = a;\r\n    for(int i = 0; i < logn; i++){\r\
    \n      for(int j = 0; j <= n - (1 << i); j++){\r\n        d[i + 1][j] = op(d[i][j],\
    \ d[i][j + (1 << i)]);\r\n      }\r\n    }\r\n    for(int i = 2; i <= n; i++)\
    \ len[i] = len[i >> 1] + 1;\r\n  }\r\n  T query(const int l, const int r) const{\r\
    \n    assert(0 <= l && l <= r && r <= n);\r\n    if(l == r) return inf;\r\n  \
    \  const int range = len[r - l];\r\n    assert(0 <= range && range < d.size());\r\
    \n    return op(d[range][l], d[range][r - (1 << range)]);\r\n  }\r\n};\n#line\
    \ 6 \"test/yosupo/Data-Structure/Static-RMQ.test.cpp\"\n\nint main(){\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  int n,q;\n  cin >> n >> q;\n  SparseTable<int,\
    \ min> st(n);\n  rep(i, n) cin >> st[i];\n  st.build();\n  rep(i, q){\n    int\
    \ l,r;\n    cin >> l >> r;\n    cout << st.query(l, r) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../../template/template.hpp\"\n\n#include \"../../../data-structure/SparseTable.hpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n\
    \  cin >> n >> q;\n  SparseTable<int, min> st(n);\n  rep(i, n) cin >> st[i];\n\
    \  st.build();\n  rep(i, q){\n    int l,r;\n    cin >> l >> r;\n    cout << st.query(l,\
    \ r) << \"\\n\";\n  }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/SparseTable.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Static-RMQ.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 19:15:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Static-RMQ.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Static-RMQ.test.cpp
- /verify/test/yosupo/Data-Structure/Static-RMQ.test.cpp.html
title: test/yosupo/Data-Structure/Static-RMQ.test.cpp
---
