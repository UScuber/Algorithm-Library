---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/rupdate-rmin.hpp
    title: SegmentTree/rupdate-rmin.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL/DSL_2_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\
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
    \ 4 \"test/aoj/DSL/DSL_2_D.test.cpp\"\n\n#line 1 \"SegmentTree/rupdate-rmin.hpp\"\
    \ntemplate <class T, const T&(*op)(const T&,const T&)>\r\nstruct LazySegmentTree\
    \ {\r\n  LazySegmentTree(const int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\
    \n    len = 1 << log;\r\n    d.assign(len * 2, inf);\r\n    lazy.assign(len, inf);\r\
    \n  }\r\n  void set(const int i, const T &x){\r\n    assert(0 <= i && i < n);\r\
    \n    d[i + len] = x;\r\n  }\r\n  T get(int p){\r\n    assert(0 <= p && p < n);\r\
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
    \ left = inf, right = inf;\r\n    while(l < r){\r\n      if(l & 1) left = op(left,\
    \ d[l++]);\r\n      if(r & 1) right = op(d[--r], right);\r\n      l >>= 1; r >>=\
    \ 1;\r\n    }\r\n    return op(left, right);\r\n  }\r\n  template <class G>\r\n\
    \  int max_right(int l, G g){\r\n    assert(0 <= l && l <= n);\r\n    assert(g(inf));\r\
    \n    if(l == n) return n;\r\n    l += len;\r\n    for(int i = log; i >= 1; i--)\
    \ push(l >> i);\r\n    T sm = inf;\r\n    do {\r\n      l /= l & -l;\r\n     \
    \ if(!g(op(sm, d[l]))){\r\n        while(l < len){\r\n          push(l);\r\n \
    \         l <<= 1;\r\n          if(g(op(sm, d[l]))){\r\n            sm = op(sm,\
    \ d[l]);\r\n            l++;\r\n          }\r\n        }\r\n        return l -\
    \ len;\r\n      }\r\n      sm = op(sm, d[l]);\r\n      l++;\r\n    }while(l &\
    \ (l - 1));\r\n    return n;\r\n  }\r\n  template <class G>\r\n  int min_left(int\
    \ r, G g){\r\n    assert(0 <= r && r <= n);\r\n    assert(g(inf));\r\n    if(r\
    \ == 0) return 0;\r\n    r += len;\r\n    for(int i = log; i >= 1; i--) push((r\
    \ - 1) >> i);\r\n    T sm = inf;\r\n    do {\r\n      r /= r & -r;\r\n      if(r\
    \ > 1) r--;\r\n      if(!g(op(d[r], sm))){\r\n        while(r < len){\r\n    \
    \      push(r);\r\n          r = r * 2 + 1;\r\n          if(g(op(d[r], sm))){\r\
    \n            sm = op(d[r], sm);\r\n            r--;\r\n          }\r\n      \
    \  }\r\n        return r + 1 - len;\r\n      }\r\n      sm = op(d[r], sm);\r\n\
    \    }while(r & (r - 1));\r\n    return 0;\r\n  }\r\n  private:\r\n  vector<T>\
    \ d, lazy;\r\n  const T inf = -op(numeric_limits<T>::max(), -numeric_limits<T>::max());\r\
    \n  int n = 1, log = 0, len = 0;\r\n  inline void update(const int k){ d[k] =\
    \ op(d[2*k], d[2*k+1]); }\r\n  inline void apply(const int k, const T &x){\r\n\
    \    d[k] = x;\r\n    if(k < len) lazy[k] = x;\r\n  }\r\n  inline void push(const\
    \ int k){\r\n    if(lazy[k] == inf) return;\r\n    apply(2*k, lazy[k]);\r\n  \
    \  apply(2*k+1, lazy[k]);\r\n    lazy[k] = inf;\r\n  }\r\n};\n#line 6 \"test/aoj/DSL/DSL_2_D.test.cpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n\
    \  cin >> n >> q;\n  LazySegmentTree<int,min> seg(n);\n  rep(i, q){\n    int t;\
    \ cin >> t;\n    if(!t){\n      int l,r,x;\n      cin >> l >> r >> x;\n      seg.update(l,\
    \ r + 1, x);\n    }else{\n      int x; cin >> x;\n      cout << seg.get(x) <<\
    \ \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../SegmentTree/rupdate-rmin.hpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n\
    \  cin >> n >> q;\n  LazySegmentTree<int,min> seg(n);\n  rep(i, q){\n    int t;\
    \ cin >> t;\n    if(!t){\n      int l,r,x;\n      cin >> l >> r >> x;\n      seg.update(l,\
    \ r + 1, x);\n    }else{\n      int x; cin >> x;\n      cout << seg.get(x) <<\
    \ \"\\n\";\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - SegmentTree/rupdate-rmin.hpp
  isVerificationFile: true
  path: test/aoj/DSL/DSL_2_D.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 18:03:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL/DSL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL/DSL_2_D.test.cpp
- /verify/test/aoj/DSL/DSL_2_D.test.cpp.html
title: test/aoj/DSL/DSL_2_D.test.cpp
---
