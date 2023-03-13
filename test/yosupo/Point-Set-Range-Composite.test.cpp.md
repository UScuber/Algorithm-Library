---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/segtree.hpp
    title: SegmentTree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: math/mint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/Point-Set-Range-Composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#line\
    \ 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\n#include\
    \ <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <utility>\r\
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
    \ 4 \"test/yosupo/Point-Set-Range-Composite.test.cpp\"\n\n#line 1 \"SegmentTree/segtree.hpp\"\
    \ntemplate <class T, T(*op)(const T&,const T&), T(*e)()>\r\nstruct SegmentTree\
    \ {\r\n  SegmentTree(const int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\
    \n    len = 1 << log;\r\n    d.resize(len * 2, e());\r\n  }\r\n  void update(int\
    \ k, const T &x){\r\n    assert(0 <= k && k < n);\r\n    k += len;\r\n    d[k]\
    \ = x;\r\n    while(k > 1){\r\n      k >>= 1;\r\n      d[k] = op(d[k*2], d[k*2+1]);\r\
    \n    }\r\n  }\r\n  void set(const int i, const T &x){\r\n    assert(0 <= i &&\
    \ i < n);\r\n    d[i + len] = x;\r\n  }\r\n  T get(const int i) const{\r\n   \
    \ assert(0 <= i && i < n);\r\n    return d[i + len];\r\n  }\r\n  void build(){\r\
    \n    for(int k = len - 1; k >= 1; k--)\r\n      d[k] = op(d[2*k], d[2*k+1]);\r\
    \n  }\r\n  T query(int l, int r){\r\n    assert(0 <= l && l <= r && r <= n);\r\
    \n    l += len; r += len;\r\n    T left = e(), right = e();\r\n    while(l < r){\r\
    \n      if(l & 1) left = op(left, d[l++]);\r\n      if(r & 1) right = op(d[--r],\
    \ right);\r\n      l >>= 1; r >>= 1;\r\n    }\r\n    return op(left, right);\r\
    \n  }\r\n  private:\r\n  int n = 1, log = 0, len = 0;\r\n  vector<T> d;\r\n};\n\
    #line 2 \"math/mint.hpp\"\n\r\ntemplate <int mod>\r\nstruct Mint {\r\n  ll x;\r\
    \n  constexpr Mint(ll x = 0) : x((x + mod) % mod){}\r\n  static constexpr int\
    \ get_mod(){ return mod; }\r\n  constexpr Mint operator-() const{ return Mint(-x);\
    \ }\r\n  constexpr Mint operator+=(const Mint &a){\r\n    if((x += a.x) >= mod)\
    \ x -= mod;\r\n    return *this;\r\n  }\r\n  constexpr Mint &operator++(){\r\n\
    \    if(++x == mod) x = 0;\r\n    return *this;\r\n  }\r\n  constexpr Mint operator++(int){\r\
    \n    Mint temp = *this;\r\n    if(++x == mod) x = 0;\r\n    return temp;\r\n\
    \  }\r\n  constexpr Mint &operator-=(const Mint &a){\r\n    if((x -= a.x) < 0)\
    \ x += mod;\r\n    return *this;\r\n  }\r\n  constexpr Mint &operator--(){\r\n\
    \    if(--x < 0) x += mod;\r\n    return *this;\r\n  }\r\n  constexpr Mint operator--(int){\r\
    \n    Mint temp = *this;\r\n    if(--x < 0) x += mod;\r\n    return temp;\r\n\
    \  }\r\n  constexpr Mint &operator*=(const Mint &a){\r\n    (x *= a.x) %= mod;\r\
    \n    return *this;\r\n  }\r\n  constexpr Mint operator+(const Mint &a) const{\
    \ return Mint(*this) += a; }\r\n  constexpr Mint operator-(const Mint &a) const{\
    \ return Mint(*this) -= a; }\r\n  constexpr Mint operator*(const Mint &a) const{\
    \ return Mint(*this) *= a; }\r\n  constexpr Mint pow(ll t) const{\r\n    if(!t)\
    \ return 1;\r\n    Mint res = 1, v = *this;\r\n    while(t){\r\n      if(t & 1)\
    \ res *= v;\r\n      v *= v;\r\n      t >>= 1;\r\n    }\r\n    return res;\r\n\
    \  }\r\n  constexpr Mint inv() const{ return pow(mod - 2); }\r\n  constexpr Mint\
    \ &operator/=(const Mint &a){ return (*this) *= a.inv(); }\r\n  constexpr Mint\
    \ operator/(const Mint &a) const{ return Mint(*this) /= a; }\r\n  constexpr bool\
    \ operator==(const Mint &a) const{ return x == a.x; }\r\n  constexpr bool operator!=(const\
    \ Mint &a) const{ return x != a.x; }\r\n  constexpr bool operator<(const Mint\
    \ &a) const{ return x < a.x; }\r\n  constexpr bool operator>(const Mint &a) const{\
    \ return x > a.x; }\r\n  friend istream &operator>>(istream &is, Mint &a){ return\
    \ is >> a.x; }\r\n  friend ostream &operator<<(ostream &os, const Mint &a){ return\
    \ os << a.x; }\r\n};\r\n//using mint = Mint<1000000007>;\n#line 7 \"test/yosupo/Point-Set-Range-Composite.test.cpp\"\
    \n\nusing mint = Mint<998244353>;\n\nstruct Data {\n  mint a,b;\n};\nData op(const\
    \ Data &l, const Data &m){\n  return { l.a*m.a, l.b*m.a + m.b };\n}\nData e(){\n\
    \  return { 1, 0 };\n}\n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  int n,q;\n  cin >> n >> q;\n  SegmentTree<Data,op,e> seg(n);\n  rep(i, n){\n\
    \    int a,b;\n    cin >> a >> b;\n    seg.set(i, { a, b });\n  }\n  seg.build();\n\
    \  rep(i, q){\n    int t,l,r,x;\n    cin >> t >> l >> r >> x;\n    if(t == 0){\n\
    \      seg.update(l, { r,x });\n    }else{\n      const Data res = seg.query(l,\
    \ r);\n      cout << res.a*x + res.b << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../template/template.hpp\"\n\n#include \"../../SegmentTree/segtree.hpp\"\
    \n#include \"../../math/mint.hpp\"\n\nusing mint = Mint<998244353>;\n\nstruct\
    \ Data {\n  mint a,b;\n};\nData op(const Data &l, const Data &m){\n  return {\
    \ l.a*m.a, l.b*m.a + m.b };\n}\nData e(){\n  return { 1, 0 };\n}\n\nint main(){\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n  cin >> n >>\
    \ q;\n  SegmentTree<Data,op,e> seg(n);\n  rep(i, n){\n    int a,b;\n    cin >>\
    \ a >> b;\n    seg.set(i, { a, b });\n  }\n  seg.build();\n  rep(i, q){\n    int\
    \ t,l,r,x;\n    cin >> t >> l >> r >> x;\n    if(t == 0){\n      seg.update(l,\
    \ { r,x });\n    }else{\n      const Data res = seg.query(l, r);\n      cout <<\
    \ res.a*x + res.b << \"\\n\";\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - SegmentTree/segtree.hpp
  - math/mint.hpp
  isVerificationFile: true
  path: test/yosupo/Point-Set-Range-Composite.test.cpp
  requiredBy: []
  timestamp: '2023-03-14 01:16:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Point-Set-Range-Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Point-Set-Range-Composite.test.cpp
- /verify/test/yosupo/Point-Set-Range-Composite.test.cpp.html
title: test/yosupo/Point-Set-Range-Composite.test.cpp
---
