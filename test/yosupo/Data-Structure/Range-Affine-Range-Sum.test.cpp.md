---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/lazysegtree.hpp
    title: SegmentTree/lazysegtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#line 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\
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
    \ 4 \"test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp\"\n\n#line 1\
    \ \"SegmentTree/lazysegtree.hpp\"\ntemplate <class T, T(*op)(const T&,const T&),\
    \ T(*e)(), class F,\r\n          T(*mapping)(const F&,const T&), F(*composition)(const\
    \ F&,const F&), F(*id)()>\r\nstruct LazySegmentTree {\r\n  LazySegmentTree(const\
    \ int _n) : n(_n){\r\n    while((1 << log) < n) log++;\r\n    len = 1 << log;\r\
    \n    d.assign(len * 2, e());\r\n    lazy.assign(len, id());\r\n  }\r\n  void\
    \ set(const int i, const T &x){\r\n    assert(0 <= i && i < n);\r\n    d[i + len]\
    \ = x;\r\n  }\r\n  T get(int p){\r\n    assert(0 <= p && p < n);\r\n    p += len;\r\
    \n    for(int i = log; i >= 1; i--) push(p >> i);\r\n    return d[p];\r\n  }\r\
    \n  void build(){\r\n    for(int i = len - 1; i >= 1; i--) update(i);\r\n  }\r\
    \n  void update(int l, int r, const F &x){\r\n    assert(0 <= l && l <= r && r\
    \ <= n);\r\n    l += len; r += len;\r\n    const int l_ctz = __builtin_ctz(l);\r\
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
    \ left = e(), right = e();\r\n    while(l < r){\r\n      if(l & 1) left = op(left,\
    \ d[l++]);\r\n      if(r & 1) right = op(d[--r], right);\r\n      l >>= 1; r >>=\
    \ 1;\r\n    }\r\n    return op(left, right);\r\n  }\r\n  template <class G>\r\n\
    \  int max_right(int l, G g){\r\n    assert(0 <= l && l <= n);\r\n    assert(g(e()));\r\
    \n    if(l == n) return n;\r\n    l += len;\r\n    for(int i = log; i >= 1; i--)\
    \ push(l >> i);\r\n    T sm = e();\r\n    do {\r\n      l /= l & -l;\r\n     \
    \ if(!g(op(sm, d[l]))){\r\n        while(l < len){\r\n          push(l);\r\n \
    \         l <<= 1;\r\n          if(g(op(sm, d[l]))){\r\n            sm = op(sm,\
    \ d[l]);\r\n            l++;\r\n          }\r\n        }\r\n        return l -\
    \ len;\r\n      }\r\n      sm = op(sm, d[l]);\r\n      l++;\r\n    }while(l &\
    \ (l - 1));\r\n    return n;\r\n  }\r\n  template <class G>\r\n  int min_left(int\
    \ r, G g){\r\n    assert(0 <= r && r <= n);\r\n    assert(g(e()));\r\n    if(r\
    \ == 0) return 0;\r\n    r += len;\r\n    for(int i = log; i >= 1; i--) push((r\
    \ - 1) >> i);\r\n    T sm = e();\r\n    do {\r\n      r /= r & -r;\r\n      if(r\
    \ > 1) r--;\r\n      if(!g(op(d[r], sm))){\r\n        while(r < len){\r\n    \
    \      push(r);\r\n          r = r * 2 + 1;\r\n          if(g(op(d[r], sm))){\r\
    \n            sm = op(d[r], sm);\r\n            r--;\r\n          }\r\n      \
    \  }\r\n        return r + 1 - len;\r\n      }\r\n      sm = op(d[r], sm);\r\n\
    \    }while(r & (r - 1));\r\n    return 0;\r\n  }\r\n  private:\r\n  vector<T>\
    \ d;\r\n  vector<F> lazy;\r\n  int n = 1, log = 0, len = 0;\r\n  inline void update(const\
    \ int k){ d[k] = op(d[2*k], d[2*k+1]); }\r\n  inline void apply(const int k, const\
    \ F &x){\r\n    d[k] = mapping(x, d[k]);\r\n    if(k < len) lazy[k] = composition(lazy[k],\
    \ x);\r\n  }\r\n  inline void push(const int k){\r\n    apply(2*k, lazy[k]);\r\
    \n    apply(2*k+1, lazy[k]);\r\n    lazy[k] = id();\r\n  }\r\n};\n#line 2 \"math/mint.hpp\"\
    \n\r\ntemplate <int mod>\r\nstruct Mint {\r\n  ll x;\r\n  constexpr Mint(ll x\
    \ = 0) : x((x + mod) % mod){}\r\n  static constexpr int get_mod(){ return mod;\
    \ }\r\n  constexpr Mint operator-() const{ return Mint(-x); }\r\n  constexpr Mint\
    \ operator+=(const Mint &a){\r\n    if((x += a.x) >= mod) x -= mod;\r\n    return\
    \ *this;\r\n  }\r\n  constexpr Mint &operator++(){\r\n    if(++x == mod) x = 0;\r\
    \n    return *this;\r\n  }\r\n  constexpr Mint operator++(int){\r\n    Mint temp\
    \ = *this;\r\n    if(++x == mod) x = 0;\r\n    return temp;\r\n  }\r\n  constexpr\
    \ Mint &operator-=(const Mint &a){\r\n    if((x -= a.x) < 0) x += mod;\r\n   \
    \ return *this;\r\n  }\r\n  constexpr Mint &operator--(){\r\n    if(--x < 0) x\
    \ += mod;\r\n    return *this;\r\n  }\r\n  constexpr Mint operator--(int){\r\n\
    \    Mint temp = *this;\r\n    if(--x < 0) x += mod;\r\n    return temp;\r\n \
    \ }\r\n  constexpr Mint &operator*=(const Mint &a){\r\n    (x *= a.x) %= mod;\r\
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
    \ os << a.x; }\r\n};\r\n//using mint = Mint<1000000007>;\n#line 7 \"test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp\"\
    \n\nusing mint = Mint<998244353>;\n\nstruct Data {\n  mint a, len;\n};\nstruct\
    \ Lazy {\n  mint a, b;\n};\nData op(const Data &a, const Data &b){\n  return {\
    \ a.a+b.a, a.len+b.len };\n}\nData e(){ return { 0, 0 }; }\nData mapping(const\
    \ Lazy &a, const Data &b){\n  return { a.a*b.a + a.b*b.len, b.len };\n}\nLazy\
    \ composition(const Lazy &a, const Lazy &b){\n  return { a.a*b.a, a.b*b.a + b.b\
    \ };\n}\nLazy id(){ return { 1, 0 }; }\n\nint main(){\n  cin.tie(nullptr);\n \
    \ ios::sync_with_stdio(false);\n  int n,q;\n  cin >> n >> q;\n  LazySegmentTree<Data,op,e,Lazy,mapping,composition,id>\
    \ seg(n);\n  rep(i, n){\n    int a; cin >> a;\n    seg.set(i, { a, 1 });\n  }\n\
    \  seg.build();\n  int t,l,r,b,c;\n  rep(_, q){\n    cin >> t >> l >> r;\n   \
    \ if(t == 0){\n      cin >> b >> c;\n      seg.update(l, r, { b, c });\n    }else{\n\
    \      cout << seg.query(l, r).a << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../../template/template.hpp\"\n\n#include \"../../../SegmentTree/lazysegtree.hpp\"\
    \n#include \"../../../math/mint.hpp\"\n\nusing mint = Mint<998244353>;\n\nstruct\
    \ Data {\n  mint a, len;\n};\nstruct Lazy {\n  mint a, b;\n};\nData op(const Data\
    \ &a, const Data &b){\n  return { a.a+b.a, a.len+b.len };\n}\nData e(){ return\
    \ { 0, 0 }; }\nData mapping(const Lazy &a, const Data &b){\n  return { a.a*b.a\
    \ + a.b*b.len, b.len };\n}\nLazy composition(const Lazy &a, const Lazy &b){\n\
    \  return { a.a*b.a, a.b*b.a + b.b };\n}\nLazy id(){ return { 1, 0 }; }\n\nint\
    \ main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n,q;\n \
    \ cin >> n >> q;\n  LazySegmentTree<Data,op,e,Lazy,mapping,composition,id> seg(n);\n\
    \  rep(i, n){\n    int a; cin >> a;\n    seg.set(i, { a, 1 });\n  }\n  seg.build();\n\
    \  int t,l,r,b,c;\n  rep(_, q){\n    cin >> t >> l >> r;\n    if(t == 0){\n  \
    \    cin >> b >> c;\n      seg.update(l, r, { b, c });\n    }else{\n      cout\
    \ << seg.query(l, r).a << \"\\n\";\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - SegmentTree/lazysegtree.hpp
  - math/mint.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-07-10 18:11:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
- /verify/test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp.html
title: test/yosupo/Data-Structure/Range-Affine-Range-Sum.test.cpp
---
