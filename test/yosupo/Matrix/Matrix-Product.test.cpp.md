---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':question:'
    path: math/mint.hpp
    title: math/mint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/yosupo/Matrix/Matrix-Product.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_product\"\r\n\r\n#line 1 \"template/template.hpp\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Matrix/Matrix-Product.test.cpp\"\n\r\n\
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
    \ os << a.x; }\r\n};\r\n//using mint = Mint<1000000007>;\n#line 1 \"math/matrix.hpp\"\
    \ntemplate <class T>\r\nstruct matrix {\r\n  int n,m;\r\n  private:\r\n  vector<vector<T>>\
    \ a;\r\n  public:\r\n  matrix(const int n) : n(n), m(n), a(n, vector<T>(n)){}\r\
    \n  matrix(const int n, const int m) : n(n), m(m), a(n, vector<T>(m)){}\r\n  matrix(const\
    \ vector<vector<T>> &d) : a(d), n(d.size()), m(d[0].size()){}\r\n  vector<T> &operator[](const\
    \ int i){ return a[i]; }\r\n  matrix &operator*=(const matrix &b){\r\n    assert(m\
    \ == b.n);\r\n    vector<vector<T>> c(n, vector<T>(b.m));\r\n    for(int i = 0;\
    \ i < n; i++) for(int j = 0; j < m; j++)\r\n    for(int k = 0; k < b.m; k++){\r\
    \n      c[i][k] += a[i][j] * b.a[j][k];\r\n    }\r\n    a = c;\r\n    return *this;\r\
    \n  }\r\n  matrix &operator+=(const matrix &b){\r\n    assert(n == b.n && m ==\
    \ b.m);\r\n    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)\r\n     \
    \ a[i][j] += b.a[i][j];\r\n    return *this;\r\n  }\r\n  matrix &operator-=(const\
    \ matrix &b){\r\n    assert(n == b.n && m == b.m);\r\n    for(int i = 0; i < n;\
    \ i++) for(int j = 0; j < m; j++)\r\n      a[i][j] -= b.a[i][j];\r\n    return\
    \ *this;\r\n  }\r\n  matrix operator*(const matrix &b) const{ return matrix(*this)\
    \ *= b; }\r\n  matrix operator+(const matrix &b) const{ return matrix(*this) +=\
    \ b; }\r\n  matrix operator-(const matrix &b) const{ return matrix(*this) -= b;\
    \ }\r\n  matrix pow(ll t) const{\r\n    assert(n == m);\r\n    matrix<T> b(n),\
    \ c = *this;\r\n    for(int i = 0; i < n; i++) b[i][i] = 1;\r\n    while(t > 0){\r\
    \n      if(t & 1) b *= c;\r\n      c *= c;\r\n      t >>= 1;\r\n    }\r\n    return\
    \ b;\r\n  }\r\n  T det() const{\r\n    assert(n == m);\r\n    matrix b = *this;\r\
    \n    T res(1);\r\n    bool flip = false;\r\n    for(int i = 0; i < n; i++){\r\
    \n      for(int j = i + 1; j < n; j++){\r\n        while(b[j][i] > 0){\r\n   \
    \       swap(b[i], b[j]);\r\n          flip ^= 1;\r\n          const T d = b[j][i]\
    \ / b[i][i];\r\n          for(int k = i; k < n; k++){\r\n            b[j][k] -=\
    \ b[i][k] * d;\r\n          }\r\n        }\r\n      }\r\n      if(b[i][i] == 0)\
    \ return 0;\r\n      res *= b[i][i];\r\n    }\r\n    if(flip) res = -res;\r\n\
    \    return res;\r\n  }\r\n  matrix inv(){\r\n    assert(n == m);\r\n    matrix\
    \ b(n), c = *this;\r\n    for(int i = 0; i < n; i++) b[i][i] = 1;\r\n    int r\
    \ = 0;\r\n    for(int i = 0; i < n && r < n; i++){\r\n      if(c[r][i] == 0){\r\
    \n        T max_val = 0; int mx_pos;\r\n        for(int j = r+1; j < n; j++){\r\
    \n          if(max_val < c[j][i]) max_val = c[j][i], mx_pos = j;\r\n        }\r\
    \n        if(max_val == 0) return false;\r\n        swap(c[r], c[mx_pos]); swap(b[r],\
    \ b[mx_pos]);\r\n      }     \r\n      T d = T(1) / c[r][i];\r\n      for(int\
    \ j = 0; j < n; j++) c[r][j] *= d, b[r][j] *= d;\r\n      for(int j = 0; j < n;\
    \ j++){\r\n        T v = c[j][i];\r\n        if(j == r || c[j][i] == 0) continue;\r\
    \n        for(int k = 0; k < n; k++){\r\n          c[j][k] -= c[r][k] * v;\r\n\
    \          b[j][k] -= b[r][k] * v;\r\n        }\r\n      }\r\n      r++;\r\n \
    \   }\r\n    return b;\r\n  }\r\n  int size() const{ return n; }\r\n  void debug(){\r\
    \n    for(int i = 0; i < n; i++){\r\n      for(int j = 0; j < n; j++) cerr <<\
    \ a[i][j] << \" \";\r\n      cerr << \"\\n\";\r\n    }\r\n  }\r\n};\n#line 7 \"\
    test/yosupo/Matrix/Matrix-Product.test.cpp\"\n\r\nusing mint = Mint<998244353>;\r\
    \n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios_base::sync_with_stdio(false);\r\
    \n  int n,m,k;\r\n  cin >> n >> m >> k;\r\n  matrix<mint> a(n, m), b(m, k);\r\n\
    \  rep(i, n) rep(j, m) cin >> a[i][j];\r\n  rep(i, m) rep(j, k) cin >> b[i][j];\r\
    \n  a *= b;\r\n  rep(i, n){\r\n    rep(j, k) cout << a[i][j] << \" \";\r\n   \
    \ cout << \"\\n\";\r\n  }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\r\n\r\n\
    #include \"../../../template/template.hpp\"\r\n\r\n#include \"../../../math/mint.hpp\"\
    \r\n#include \"../../../math/matrix.hpp\"\r\n\r\nusing mint = Mint<998244353>;\r\
    \n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios_base::sync_with_stdio(false);\r\
    \n  int n,m,k;\r\n  cin >> n >> m >> k;\r\n  matrix<mint> a(n, m), b(m, k);\r\n\
    \  rep(i, n) rep(j, m) cin >> a[i][j];\r\n  rep(i, m) rep(j, k) cin >> b[i][j];\r\
    \n  a *= b;\r\n  rep(i, n){\r\n    rep(j, k) cout << a[i][j] << \" \";\r\n   \
    \ cout << \"\\n\";\r\n  }\r\n}"
  dependsOn:
  - template/template.hpp
  - math/mint.hpp
  - math/matrix.hpp
  isVerificationFile: true
  path: test/yosupo/Matrix/Matrix-Product.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 19:15:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/Matrix/Matrix-Product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Matrix/Matrix-Product.test.cpp
- /verify/test/yosupo/Matrix/Matrix-Product.test.cpp.html
title: test/yosupo/Matrix/Matrix-Product.test.cpp
---
