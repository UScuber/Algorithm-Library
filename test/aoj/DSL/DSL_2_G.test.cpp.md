---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/radd-rsum.hpp
    title: SegmentTree/radd-rsum.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G
  bundledCode: "#line 1 \"test/aoj/DSL/DSL_2_G.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G\"\
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
    \ 4 \"test/aoj/DSL/DSL_2_G.test.cpp\"\n\n#line 1 \"SegmentTree/radd-rsum.hpp\"\
    \ntemplate <class T>\r\nstruct LazySegmentTree {\r\n  LazySegmentTree(const int\
    \ _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\n    len = 1 << log;\r\n\
    \    d.assign(len * 2, 0);\r\n    lazy.assign(len, 0);\r\n    si.assign(len *\
    \ 2, 1);\r\n    for(int i = len - 1; i >= 1; i--) si[i] = si[i<<1] << 1;\r\n \
    \ }\r\n  void set(const int i, const T &x){\r\n    assert(0 <= i && i < n);\r\n\
    \    d[i + len] = x;\r\n  }\r\n  T get(int p){\r\n    assert(0 <= p && p < n);\r\
    \n    p += len;\r\n    for(int i = log; i >= 1; i--) push(p >> i);\r\n    return\
    \ d[p];\r\n  }\r\n  void build(){\r\n    for(int i = len - 1; i >= 1; i--) update(i);\r\
    \n  }\r\n  void update(int l, int r, const T &x){\r\n    assert(0 <= l && l <=\
    \ r && r <= n);\r\n    l += len; r += len;\r\n    const int l_ctz = __builtin_ctz(l);\r\
    \n    const int r_ctz = __builtin_ctz(r);\r\n    for(int i = log; i > l_ctz; i--)\
    \ push(l >> i);\r\n    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\r\n\
    \    const int lt = l, rt = r;\r\n    while(l < r){\r\n      if(l & 1) apply(l++,\
    \ x);\r\n      if(r & 1) apply(--r, x);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n\
    \    l = lt; r = rt;\r\n    for(int i = l_ctz + 1; i <= log; i++) update(l >>\
    \ i);\r\n    for(int i = r_ctz + 1; i <= log; i++) update((r - 1) >> i);\r\n \
    \ }\r\n  T query(int l, int r){\r\n    assert(0 <= l && l <= r && r <= n);\r\n\
    \    l += len; r += len;\r\n    const int l_ctz = __builtin_ctz(l);\r\n    const\
    \ int r_ctz = __builtin_ctz(r);\r\n    for(int i = log; i > l_ctz; i--) push(l\
    \ >> i);\r\n    for(int i = log; i > r_ctz; i--) push((r - 1) >> i);\r\n    T\
    \ res = 0;\r\n    while(l < r){\r\n      if(l & 1) res += d[l++];\r\n      if(r\
    \ & 1) res += d[--r];\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    return res;\r\
    \n  }\r\n  private:\r\n  vector<T> d, lazy;\r\n  vector<int> si;\r\n  int n =\
    \ 1, log = 0, len = 0;\r\n  inline void update(const int k){ d[k] = d[2*k] + d[2*k+1];\
    \ }\r\n  inline void apply(const int k, const T &x){\r\n    d[k] += x * si[k];\r\
    \n    if(k < len) lazy[k] += x;\r\n  }\r\n  inline void push(const int k){\r\n\
    \    if(!lazy[k]) return;\r\n    apply(2*k, lazy[k]);\r\n    apply(2*k+1, lazy[k]);\r\
    \n    lazy[k] = 0;\r\n  }\r\n};\n#line 6 \"test/aoj/DSL/DSL_2_G.test.cpp\"\n\n\
    int main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n\
    \  cin >> n >> q;\n  LazySegmentTree<ll> seg(n);\n  while(q--){\n    int t; cin\
    \ >> t;\n    if(t == 0){\n      int l,r,x;\n      cin >> l >> r >> x;\n      seg.update(l-1,\
    \ r, x);\n    }else{\n      int l,r;\n      cin >> l >> r;\n      cout << seg.query(l-1,\
    \ r) << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../SegmentTree/radd-rsum.hpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n\
    \  cin >> n >> q;\n  LazySegmentTree<ll> seg(n);\n  while(q--){\n    int t; cin\
    \ >> t;\n    if(t == 0){\n      int l,r,x;\n      cin >> l >> r >> x;\n      seg.update(l-1,\
    \ r, x);\n    }else{\n      int l,r;\n      cin >> l >> r;\n      cout << seg.query(l-1,\
    \ r) << \"\\n\";\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - SegmentTree/radd-rsum.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2023-03-14 17:59:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_2_G.test.cpp
- /verify/test/aoj/DSL/DSL_2_G.test.cpp.html
title: test/aoj/DSL/DSL_2_G.test.cpp
---
