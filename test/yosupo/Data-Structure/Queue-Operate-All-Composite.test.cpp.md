---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/SWAG.hpp
    title: SWAG(Sliding Window Aggregation)
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: math/mint.hpp
  - icon: ':heavy_check_mark:'
    path: others/fastIO.hpp
    title: others/fastIO.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#line 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\
    \n#include <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <tuple>\r\
    \n#include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <deque>\r\n#include <bitset>\r\
    \n#include <cctype>\r\n#include <climits>\r\n#include <functional>\r\n#include\
    \ <cassert>\r\n#include <numeric>\r\n#include <cstring>\r\n#define rep(i, n) for(int\
    \ i = 0; i < (n); i++)\r\n#define per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\
    \nusing ll = long long;\r\n#define vi vector<int>\r\n#define vvi vector<vi>\r\n\
    #define vl vector<ll>\r\n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\
    \n#define all(a) (a).begin(), (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\
    \nconstexpr int mod = 1000000007;\r\nusing namespace std;\r\ntemplate<class T,\
    \ class U>\r\nbool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\
    \ntemplate<class T, class U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a\
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp\"\
    \n\n#line 1 \"data-structure/SWAG.hpp\"\ntemplate <class T, T(*op)(const T&,const\
    \ T&), const T(*e)()>\r\nstruct SWAG : deque<T> {\r\n  private:\r\n  T front =\
    \ e();\r\n  stack<T> back;\r\n  int l = 0, r = 0;\r\n  public:\r\n  SWAG(const\
    \ int n = 0) : deque<T>(n, e()){}\r\n  SWAG(const deque<T> &v) : deque<T>(v){}\r\
    \n  T fold(const int i, const int j){\r\n    assert(l <= i && i <= j);\r\n   \
    \ assert(r <= j && j <= (int)(*this).size());\r\n    while(r < j) front = op(front,\
    \ (*this)[r++]);\r\n    while(l < i){\r\n      if(back.empty()){\r\n        T\
    \ temp = e();\r\n        for(int u = r - 1; u >= l; u--) back.push(temp = op((*this)[u],\
    \ temp));\r\n        front = e();\r\n      }\r\n      back.pop();\r\n      l++;\r\
    \n    }\r\n    if(back.empty()) return front;\r\n    return op(back.top(), front);\r\
    \n  }\r\n  void pop(){\r\n    if(!l) fold(l + 1, max(l + 1, r));\r\n    l--; r--;\r\
    \n    (*this).pop_front();\r\n  }\r\n};\n#line 2 \"math/mint.hpp\"\n\r\ntemplate\
    \ <int mod>\r\nstruct Mint {\r\n  ll x;\r\n  constexpr Mint(ll x = 0) : x((x +\
    \ mod) % mod){}\r\n  static constexpr int get_mod(){ return mod; }\r\n  constexpr\
    \ Mint operator-() const{ return Mint(-x); }\r\n  constexpr Mint operator+=(const\
    \ Mint &a){\r\n    if((x += a.x) >= mod) x -= mod;\r\n    return *this;\r\n  }\r\
    \n  constexpr Mint &operator++(){\r\n    if(++x == mod) x = 0;\r\n    return *this;\r\
    \n  }\r\n  constexpr Mint operator++(int){\r\n    Mint temp = *this;\r\n    if(++x\
    \ == mod) x = 0;\r\n    return temp;\r\n  }\r\n  constexpr Mint &operator-=(const\
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
    \ 1 \"others/fastIO.hpp\"\nnamespace FastIO {\r\nstruct PreCalc {\r\n  char num[10000\
    \ * 4];\r\n  constexpr PreCalc() : num(){\r\n    for(int i = 0; i < 10000; i++){\r\
    \n      int t = i;\r\n      for(int j = 3; j >= 0; j--){\r\n        num[i*4 +\
    \ j] = (t % 10) + '0';\r\n        t /= 10;\r\n      }\r\n    }\r\n  }\r\n};\r\n\
    static constexpr PreCalc pr;\r\nstruct FastIO {\r\n  template <class T>\r\n  using\
    \ enable_if_integer = enable_if_t<is_integral<T>::value || is_same<T, __int128_t>::value\
    \ || is_same<T, __uint128_t>::value>;\r\n  static constexpr int buf_size = 1 <<\
    \ 20;\r\n  static constexpr int rem = 1 << 6;\r\n  char in_buf[buf_size], *in_cur\
    \ = in_buf + buf_size;\r\n  char out_buf[buf_size], *out_cur = out_buf;\r\n  FastIO(){\
    \ load(); }\r\n  ~FastIO(){ flush(); }\r\n  void load(){\r\n    const int len\
    \ = in_buf + buf_size - in_cur;\r\n    memmove(in_buf, in_cur, len);\r\n    in_cur\
    \ = in_buf;\r\n    fread(in_buf + len, 1, buf_size - len, stdin);\r\n  }\r\n \
    \ void flush(){\r\n    fwrite(out_buf, 1, out_cur - out_buf, stdout);\r\n    out_cur\
    \ = out_buf;\r\n  }\r\n  void through(){\r\n    if(in_cur - in_buf >= buf_size\
    \ - rem) load();\r\n    while(*in_cur <= ' ') in_cur++;\r\n    assert(in_buf <=\
    \ in_cur && in_cur < in_buf + buf_size);\r\n  }\r\n  #define gc() (*in_cur++)\r\
    \n  template <class T, enable_if_integer<T>* = nullptr>\r\n  inline void read(T\
    \ &x){\r\n    through();\r\n    bool neg = false;\r\n    int c = gc();\r\n   \
    \ if(c == '-') neg = true, c = gc();\r\n    x = c^'0'; c = gc();\r\n    while(c\
    \ >= '0' && c <= '9') x = x*10 + (c^'0'), c = gc();\r\n    if(neg) x = -x;\r\n\
    \  }\r\n  inline void read(string &x){\r\n    through();\r\n    x.clear();\r\n\
    \    while(true){\r\n      char *p = in_cur;\r\n      while(*p > ' ' && p - in_buf\
    \ < buf_size - rem) p++;\r\n      copy(in_cur, p, back_inserter(x));\r\n     \
    \ in_cur = p;\r\n      if(*p <= ' ') break;\r\n      load();\r\n    }\r\n  }\r\
    \n  inline void read(char &x){\r\n    through();\r\n    x = gc();\r\n  }\r\n \
    \ #undef gc\r\n  #define pc(c) *out_cur++ = (c)\r\n  template <class T, enable_if_integer<T>*\
    \ = nullptr>\r\n  inline void out(T x){\r\n    static constexpr int tmp_size =\
    \ sizeof(T)*5/2;\r\n    static char tmp[tmp_size];\r\n    if(out_cur - out_buf\
    \ >= buf_size - rem) flush();\r\n    if(!x){ pc('0'); return; }\r\n    if(x <\
    \ 0){ pc('-'); x = -x; }\r\n    int idx = tmp_size;\r\n    while(x >= 10000){\r\
    \n      idx -= 4;\r\n      memcpy(tmp + idx, pr.num + (x % 10000)*4, 4);\r\n \
    \     x /= 10000;\r\n    }\r\n    if(x < 100){\r\n      if(x < 10){\r\n      \
    \  pc(x + '0');\r\n      }else{\r\n        pc(x/10 + '0');\r\n        pc(x%10\
    \ + '0');\r\n      }\r\n    }else{\r\n      if(x < 1000){\r\n        memcpy(out_cur,\
    \ pr.num + x*4 + 1, 3);\r\n        out_cur += 3;\r\n      }else{\r\n        memcpy(out_cur,\
    \ pr.num + x*4, 4);\r\n        out_cur += 4;\r\n      }\r\n    }\r\n    memcpy(out_cur,\
    \ tmp + idx, tmp_size - idx);\r\n    out_cur += tmp_size - idx;\r\n  }\r\n  inline\
    \ void out(const string &s){\r\n    flush();\r\n    fwrite(s.c_str(), 1, s.size(),\
    \ stdout);\r\n  }\r\n  inline void out(const char c){\r\n    if(out_cur - out_buf\
    \ >= buf_size - rem) flush();\r\n    pc(c);\r\n  }\r\n  #undef pc\r\n  template\
    \ <class T>\r\n  friend FastIO &operator>>(FastIO &io, T &x){\r\n    io.read(x);\r\
    \n    return io;\r\n  }\r\n  template <class T>\r\n  friend FastIO &operator<<(FastIO\
    \ &io, const T &x){\r\n    io.out(x);\r\n    return io;\r\n  }\r\n};\r\nFastIO\
    \ io;\r\n} // namespace FastIO\r\nusing FastIO::io;\r\n#define cin io\r\n#define\
    \ cout io\n#line 8 \"test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp\"\
    \n\nusing mint = Mint<998244353>;\n\n//Data: ax+b\nstruct Data {\n  mint a,b;\n\
    };\n//\u5408\u6210\u95A2\u6570 g(f(x))\nData op(const Data &l, const Data &m){\n\
    \  return { l.a*m.a, l.b*m.a + m.b };\n}\nconst Data e(){\n  return { 1, 0 };\n\
    }\nint main(){\n  int q;\n  cin >> q;\n  SWAG<Data, op, e> sw;\n  rep(i, q){\n\
    \    int t; cin >> t;\n    if(t == 0){\n      int a,b;\n      cin >> a >> b;\n\
    \      sw.push_back({ a, b });\n    }else if(t == 1){\n      sw.pop();\n    }else{\n\
    \      int x; cin >> x;\n      const Data l = sw.fold(0, sw.size());\n      cout\
    \ << (l.a*x + l.b).x << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../../template/template.hpp\"\n\n#include \"../../../data-structure/SWAG.hpp\"\
    \n#include \"../../../math/mint.hpp\"\n#include \"../../../others/fastIO.hpp\"\
    \n\nusing mint = Mint<998244353>;\n\n//Data: ax+b\nstruct Data {\n  mint a,b;\n\
    };\n//\u5408\u6210\u95A2\u6570 g(f(x))\nData op(const Data &l, const Data &m){\n\
    \  return { l.a*m.a, l.b*m.a + m.b };\n}\nconst Data e(){\n  return { 1, 0 };\n\
    }\nint main(){\n  int q;\n  cin >> q;\n  SWAG<Data, op, e> sw;\n  rep(i, q){\n\
    \    int t; cin >> t;\n    if(t == 0){\n      int a,b;\n      cin >> a >> b;\n\
    \      sw.push_back({ a, b });\n    }else if(t == 1){\n      sw.pop();\n    }else{\n\
    \      int x; cin >> x;\n      const Data l = sw.fold(0, sw.size());\n      cout\
    \ << (l.a*x + l.b).x << '\\n';\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/SWAG.hpp
  - math/mint.hpp
  - others/fastIO.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 01:15:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
- /verify/test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp.html
title: test/yosupo/Data-Structure/Queue-Operate-All-Composite.test.cpp
---
