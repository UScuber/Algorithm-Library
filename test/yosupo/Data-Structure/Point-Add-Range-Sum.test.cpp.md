---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: SegmentTree/BinaryIndexedTree.hpp
    title: SegmentTree/BinaryIndexedTree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Point-Add-Range-Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #line 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\n\
    #include <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <tuple>\r\
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
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Data-Structure/Point-Add-Range-Sum.test.cpp\"\
    \n\n#line 1 \"SegmentTree/BinaryIndexedTree.hpp\"\ntemplate <class T>\r\nstruct\
    \ BIT {\r\n  BIT(const int _n = 0) : n(_n), d(n){}\r\n  BIT(const vector<T> &v)\
    \ : d(v), n(v.size()){\r\n    for(int i = 1; i <= n; i++){\r\n      const int\
    \ j = i + (i & -i);\r\n      if(j <= n) d[j - 1] += d[i - 1];\r\n    }\r\n  }\r\
    \n  T sum(const int l, const int r) const{\r\n    assert(0 <= l && l <= r && r\
    \ <= n);\r\n    return sum(r) - sum(l);\r\n  }\r\n  T sum(int i) const{\r\n  \
    \  T tot = 0;\r\n    while(i > 0){\r\n      tot += d[i - 1];\r\n      i -= i &\
    \ -i;\r\n    }\r\n    return tot;\r\n  }\r\n  void add(int i, const T &x){\r\n\
    \    assert(0 <= i && i < n);\r\n    i++;\r\n    while(i <= n){\r\n      d[i -\
    \ 1] += x;\r\n      i += i & -i;\r\n    }\r\n  }\r\n  private:\r\n  int n = 1;\r\
    \n  vector<T> d;\r\n};\n#line 1 \"others/fastIO.hpp\"\nnamespace FastIO {\r\n\
    struct PreCalc {\r\n  char num[10000 * 4];\r\n  constexpr PreCalc() : num(){\r\
    \n    for(int i = 0; i < 10000; i++){\r\n      int t = i;\r\n      for(int j =\
    \ 3; j >= 0; j--){\r\n        num[i*4 + j] = (t % 10) + '0';\r\n        t /= 10;\r\
    \n      }\r\n    }\r\n  }\r\n};\r\nstatic constexpr PreCalc pr;\r\nstruct FastIO\
    \ {\r\n  template <class T>\r\n  using enable_if_integer = enable_if_t<is_integral<T>::value\
    \ || is_same<T, __int128_t>::value || is_same<T, __uint128_t>::value>;\r\n  static\
    \ constexpr int buf_size = 1 << 20;\r\n  static constexpr int rem = 1 << 6;\r\n\
    \  char in_buf[buf_size], *in_cur = in_buf + buf_size;\r\n  char out_buf[buf_size],\
    \ *out_cur = out_buf;\r\n  FastIO(){ load(); }\r\n  ~FastIO(){ flush(); }\r\n\
    \  void load(){\r\n    const int len = in_buf + buf_size - in_cur;\r\n    memmove(in_buf,\
    \ in_cur, len);\r\n    in_cur = in_buf;\r\n    fread(in_buf + len, 1, buf_size\
    \ - len, stdin);\r\n  }\r\n  void flush(){\r\n    fwrite(out_buf, 1, out_cur -\
    \ out_buf, stdout);\r\n    out_cur = out_buf;\r\n  }\r\n  void through(){\r\n\
    \    if(in_cur - in_buf >= buf_size - rem) load();\r\n    while(*in_cur <= ' ')\
    \ in_cur++;\r\n    assert(in_buf <= in_cur && in_cur < in_buf + buf_size);\r\n\
    \  }\r\n  #define gc() (*in_cur++)\r\n  template <class T, enable_if_integer<T>*\
    \ = nullptr>\r\n  inline void read(T &x){\r\n    through();\r\n    bool neg =\
    \ false;\r\n    int c = gc();\r\n    if(c == '-') neg = true, c = gc();\r\n  \
    \  x = c^'0'; c = gc();\r\n    while(c >= '0' && c <= '9') x = x*10 + (c^'0'),\
    \ c = gc();\r\n    if(neg) x = -x;\r\n  }\r\n  inline void read(string &x){\r\n\
    \    through();\r\n    x.clear();\r\n    while(true){\r\n      char *p = in_cur;\r\
    \n      while(*p > ' ' && p - in_buf < buf_size - rem) p++;\r\n      copy(in_cur,\
    \ p, back_inserter(x));\r\n      in_cur = p;\r\n      if(*p <= ' ') break;\r\n\
    \      load();\r\n    }\r\n  }\r\n  inline void read(char &x){\r\n    through();\r\
    \n    x = gc();\r\n  }\r\n  #undef gc\r\n  #define pc(c) *out_cur++ = (c)\r\n\
    \  template <class T, enable_if_integer<T>* = nullptr>\r\n  inline void out(T\
    \ x){\r\n    static constexpr int tmp_size = sizeof(T)*5/2;\r\n    static char\
    \ tmp[tmp_size];\r\n    if(out_cur - out_buf >= buf_size - rem) flush();\r\n \
    \   if(!x){ pc('0'); return; }\r\n    if(x < 0){ pc('-'); x = -x; }\r\n    int\
    \ idx = tmp_size;\r\n    while(x >= 10000){\r\n      idx -= 4;\r\n      memcpy(tmp\
    \ + idx, pr.num + (x % 10000)*4, 4);\r\n      x /= 10000;\r\n    }\r\n    if(x\
    \ < 100){\r\n      if(x < 10){\r\n        pc(x + '0');\r\n      }else{\r\n   \
    \     pc(x/10 + '0');\r\n        pc(x%10 + '0');\r\n      }\r\n    }else{\r\n\
    \      if(x < 1000){\r\n        memcpy(out_cur, pr.num + x*4 + 1, 3);\r\n    \
    \    out_cur += 3;\r\n      }else{\r\n        memcpy(out_cur, pr.num + x*4, 4);\r\
    \n        out_cur += 4;\r\n      }\r\n    }\r\n    memcpy(out_cur, tmp + idx,\
    \ tmp_size - idx);\r\n    out_cur += tmp_size - idx;\r\n  }\r\n  inline void out(const\
    \ string &s){\r\n    flush();\r\n    fwrite(s.c_str(), 1, s.size(), stdout);\r\
    \n  }\r\n  inline void out(const char c){\r\n    if(out_cur - out_buf >= buf_size\
    \ - rem) flush();\r\n    pc(c);\r\n  }\r\n  #undef pc\r\n  template <class T>\r\
    \n  friend FastIO &operator>>(FastIO &io, T &x){\r\n    io.read(x);\r\n    return\
    \ io;\r\n  }\r\n  template <class T>\r\n  friend FastIO &operator<<(FastIO &io,\
    \ const T &x){\r\n    io.out(x);\r\n    return io;\r\n  }\r\n};\r\nFastIO io;\r\
    \n} // namespace FastIO\r\nusing FastIO::io;\r\n#define cin io\r\n#define cout\
    \ io\n#line 7 \"test/yosupo/Data-Structure/Point-Add-Range-Sum.test.cpp\"\n\n\
    int main(){\n  int n,q;\n  cin >> n >> q;\n  BIT<ll> seg(n);\n  rep(i, n){\n \
    \   int a; cin >> a;\n    seg.add(i, a);\n  }\n  rep(i, q){\n    int t,a,b;\n\
    \    cin >> t >> a >> b;\n    if(t == 0) seg.add(a, b);\n    else cout << seg.sum(a,\
    \ b) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../../template/template.hpp\"\n\n#include \"../../../SegmentTree/BinaryIndexedTree.hpp\"\
    \n#include \"../../../others/fastIO.hpp\"\n\nint main(){\n  int n,q;\n  cin >>\
    \ n >> q;\n  BIT<ll> seg(n);\n  rep(i, n){\n    int a; cin >> a;\n    seg.add(i,\
    \ a);\n  }\n  rep(i, q){\n    int t,a,b;\n    cin >> t >> a >> b;\n    if(t ==\
    \ 0) seg.add(a, b);\n    else cout << seg.sum(a, b) << '\\n';\n  }\n}"
  dependsOn:
  - template/template.hpp
  - SegmentTree/BinaryIndexedTree.hpp
  - others/fastIO.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Point-Add-Range-Sum.test.cpp
  requiredBy: []
  timestamp: '2023-11-12 01:15:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Point-Add-Range-Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Point-Add-Range-Sum.test.cpp
- /verify/test/yosupo/Data-Structure/Point-Add-Range-Sum.test.cpp.html
title: test/yosupo/Data-Structure/Point-Add-Range-Sum.test.cpp
---
