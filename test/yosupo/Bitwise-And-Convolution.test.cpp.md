---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/convolution/and-convolution.hpp
    title: math/convolution/and-convolution.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/yosupo/Bitwise-And-Convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\n#line\
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
    \ 4 \"test/yosupo/Bitwise-And-Convolution.test.cpp\"\n\n#line 1 \"math/convolution/and-convolution.hpp\"\
    \ntemplate <class T>\r\nvoid fzt(vector<T> &a){\r\n  const int n = a.size();\r\
    \n  for(int j = 0; (1 << j) < n; j++){\r\n    for(int i = 0; i < n; i++){\r\n\
    \      if(!(i >> j & 1)) a[i] += a[i | 1 << j];\r\n    }\r\n  }\r\n}\r\ntemplate\
    \ <class T>\r\nvoid fmt(vector<T> &a){\r\n  const int n = a.size();\r\n  for(int\
    \ j = 0; (1 << j) < n; j++){\r\n    for(int i = 0; i < n; i++){\r\n      if(!(i\
    \ >> j & 1)) a[i] -= a[i | 1 << j];\r\n    }\r\n  }\r\n}\r\ntemplate <class T>\r\
    \nvector<T> and_convolution(vector<T> a, vector<T> b){\r\n  const int n = a.size();\r\
    \n  assert((n & (n - 1)) == 0 && a.size() == b.size());\r\n  fzt(a);\r\n  fzt(b);\r\
    \n  vector<T> c(n);\r\n  for(int i = 0; i < n; i++) c[i] = a[i] * b[i];\r\n  fmt(c);\r\
    \n  return c;\r\n}\n#line 2 \"math/mint.hpp\"\n\r\ntemplate <int mod>\r\nstruct\
    \ Mint {\r\n  ll x;\r\n  constexpr Mint(ll x = 0) : x((x + mod) % mod){}\r\n \
    \ static constexpr int get_mod(){ return mod; }\r\n  constexpr Mint operator-()\
    \ const{ return Mint(-x); }\r\n  constexpr Mint operator+=(const Mint &a){\r\n\
    \    if((x += a.x) >= mod) x -= mod;\r\n    return *this;\r\n  }\r\n  constexpr\
    \ Mint &operator++(){\r\n    if(++x == mod) x = 0;\r\n    return *this;\r\n  }\r\
    \n  constexpr Mint operator++(int){\r\n    Mint temp = *this;\r\n    if(++x ==\
    \ mod) x = 0;\r\n    return temp;\r\n  }\r\n  constexpr Mint &operator-=(const\
    \ Mint &a){\r\n    if((x -= a.x) < 0) x += mod;\r\n    return *this;\r\n  }\r\n\
    \  constexpr Mint &operator--(){\r\n    if(--x < 0) x += mod;\r\n    return *this;\r\
    \n  }\r\n  constexpr Mint operator--(int){\r\n    Mint temp = *this;\r\n    if(--x\
    \ < 0) x += mod;\r\n    return temp;\r\n  }\r\n  constexpr Mint &operator*=(const\
    \ Mint &a){\r\n    (x *= a.x) %= mod;\r\n    return *this;\r\n  }\r\n  constexpr\
    \ Mint operator+(const Mint &a) const{ return Mint(*this) += a; }\r\n  constexpr\
    \ Mint operator-(const Mint &a) const{ return Mint(*this) -= a; }\r\n  constexpr\
    \ Mint operator*(const Mint &a) const{ return Mint(*this) *= a; }\r\n  constexpr\
    \ Mint pow(ll t) const{\r\n    if(!t) return 1;\r\n    Mint res = 1, v = *this;\r\
    \n    while(t){\r\n      if(t & 1) res *= v;\r\n      v *= v;\r\n      t >>= 1;\r\
    \n    }\r\n    return res;\r\n  }\r\n  constexpr Mint inv() const{ return pow(mod\
    \ - 2); }\r\n  constexpr Mint &operator/=(const Mint &a){ return (*this) *= a.inv();\
    \ }\r\n  constexpr Mint operator/(const Mint &a) const{ return Mint(*this) /=\
    \ a; }\r\n  constexpr bool operator==(const Mint &a) const{ return x == a.x; }\r\
    \n  constexpr bool operator!=(const Mint &a) const{ return x != a.x; }\r\n  constexpr\
    \ bool operator<(const Mint &a) const{ return x < a.x; }\r\n  constexpr bool operator>(const\
    \ Mint &a) const{ return x > a.x; }\r\n  friend istream &operator>>(istream &is,\
    \ Mint &a){ return is >> a.x; }\r\n  friend ostream &operator<<(ostream &os, const\
    \ Mint &a){ return os << a.x; }\r\n};\r\n//using mint = Mint<1000000007>;\n#line\
    \ 7 \"test/yosupo/Bitwise-And-Convolution.test.cpp\"\n\nusing mint = Mint<998244353>;\n\
    \nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n;\n\
    \  cin >> n;\n  n = 1 << n;\n  vector<mint> a(n), b(n);\n  rep(i, n) cin >> a[i];\n\
    \  rep(i, n) cin >> b[i];\n  const auto res = and_convolution(a, b);\n  rep(i,\
    \ n) cout << res[i] << \" \\n\"[i == n - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include \"../../template/template.hpp\"\n\n#include \"../../math/convolution/and-convolution.hpp\"\
    \n#include \"../../math/mint.hpp\"\n\nusing mint = Mint<998244353>;\n\nint main(){\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n;\n  cin >> n;\n\
    \  n = 1 << n;\n  vector<mint> a(n), b(n);\n  rep(i, n) cin >> a[i];\n  rep(i,\
    \ n) cin >> b[i];\n  const auto res = and_convolution(a, b);\n  rep(i, n) cout\
    \ << res[i] << \" \\n\"[i == n - 1];\n}"
  dependsOn:
  - template/template.hpp
  - math/convolution/and-convolution.hpp
  - math/mint.hpp
  isVerificationFile: true
  path: test/yosupo/Bitwise-And-Convolution.test.cpp
  requiredBy: []
  timestamp: '2023-03-14 00:33:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Bitwise-And-Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Bitwise-And-Convolution.test.cpp
- /verify/test/yosupo/Bitwise-And-Convolution.test.cpp.html
title: test/yosupo/Bitwise-And-Convolution.test.cpp
---
