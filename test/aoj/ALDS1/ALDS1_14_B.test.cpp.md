---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: string/rolling-hash.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1/ALDS1_14_B.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\r\n\r\n#line 1 \"template/template.hpp\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/aoj/ALDS1/ALDS1_14_B.test.cpp\"\n\r\n#line 1\
    \ \"string/rolling-hash.hpp\"\n#include <chrono>\r\n#include <random>\r\nusing\
    \ ull = unsigned long long;\r\n\r\ntemplate <class T, int max_len>\r\nstruct Hash\
    \ {\r\n  static constexpr ull m = (1ULL << 61) - 1;\r\n  const ull base;\r\n \
    \ vector<ull> h;\r\n  const T data;\r\n  Hash(const T &d, const ull base, const\
    \ ull power[]) : data(d), base(base), power(power){}\r\n  inline ull query(int\
    \ l, int r) const{\r\n    assert(max_len >= r - l);\r\n    assert(0 <= l && l\
    \ <= r && r <= h.size());\r\n    return add(h[r], m - mul(h[l], power[r - l]));\r\
    \n  }\r\n  void combine(const Hash<T, max_len> &a){\r\n    const int len = h.size();\r\
    \n    h.insert(h.end(), a.h.begin()+1, a.h.end());\r\n    const int tot_len =\
    \ h.size();\r\n    ull val = h[len - 1];\r\n    for(int i = len; i < tot_len;\
    \ i++){\r\n      val = mul(val, base);\r\n      h[i] = add(val, h[i]);\r\n   \
    \ }\r\n  }\r\n  inline int size() const noexcept{ return (int)h.size()-1; }\r\n\
    \  private:\r\n  const ull *power;\r\n  inline ull add(ull a, const ull b) const\
    \ noexcept{\r\n    if((a += b) >= m) a -= m;\r\n    return a;\r\n  }\r\n  inline\
    \ ull mul(const ull a, const ull b) const noexcept{\r\n    const __uint128_t c\
    \ = (__uint128_t)a * b;\r\n    return add(c >> 61, c & m);\r\n  }\r\n  inline\
    \ ull fma(const ull a, const ull b, const ull c) const noexcept{\r\n    const\
    \ __uint128_t d = (__uint128_t)a * b + c;\r\n    return add(d >> 61, d & m);\r\
    \n  }\r\n};\r\ntemplate <int max_len>\r\nstruct RollingHash {\r\n  static constexpr\
    \ ull m = (1ULL << 61) - 1;\r\n  const ull base;\r\n  RollingHash() : base(rnd()){\r\
    \n    power[0] = 1;\r\n    for(int i = 0; i < max_len; i++){\r\n      power[i\
    \ + 1] = mul(power[i], base);\r\n    }\r\n  }\r\n  Hash<string, max_len> gen(const\
    \ string &s) const{\r\n    const int len = s.size();\r\n    Hash<string, max_len>\
    \ hash(s, base, power);\r\n    hash.h.resize(len + 1);\r\n    for(int i = 0; i\
    \ < len; i++){\r\n      hash.h[i+1] = fma(hash.h[i], base, s[i]);\r\n    }\r\n\
    \    return hash;\r\n  }\r\n  template <class T>\r\n  Hash<vector<T>, max_len>\
    \ gen(const vector<T> &s) const{\r\n    const int len = s.size();\r\n    Hash<vector<T>,\
    \ max_len> hash(s, base, power);\r\n    hash.h.resize(len + 1);\r\n    for(int\
    \ i = 0; i < len; i++){\r\n      hash.h[i+1] = fma(hash.h[i], base, s[i]);\r\n\
    \    }\r\n    return hash;\r\n  }\r\n  ull combine(const ull h1, const ull h2,\
    \ const ull h2_len) const{\r\n    assert(max_len >= h2_len);\r\n    return fma(h1,\
    \ power[h2_len], h2);\r\n  }\r\n  template <class T>\r\n  ull combine(const Hash<T,max_len>\
    \ &a, const int l1, const int r1,\r\n              const Hash<T,max_len> &b, const\
    \ int l2, const int r2) const{\r\n    assert(max_len >= r2 - l2);\r\n    return\
    \ fma(a.query(l1, r1), power[r2-l2], b.query(l2, r2));\r\n  }\r\n  template <class\
    \ T>\r\n  int lcp(const Hash<T,max_len> &a, const int l1, const int r1,\r\n  \
    \        const Hash<T,max_len> &b, const int l2, const int r2) const{\r\n    assert(0\
    \ <= l1 && l1 <= r1 && r1 <= a.size());\r\n    assert(0 <= l2 && l2 <= r2 && r2\
    \ <= b.size());\r\n    const int len = min(r1-l1, r2-l2);\r\n    int left = 0,\
    \ right = len + 1;\r\n    while(left + 1 < right){\r\n      const int mid = (left\
    \ + right) / 2;\r\n      if(a.query(l1, l1+mid) == b.query(l2, l2+mid)) left =\
    \ mid;\r\n      else right = mid;\r\n    }\r\n    return left;\r\n  }\r\n  template\
    \ <class T>\r\n  int strcmp(const Hash<T,max_len> &a, const int l1, const int\
    \ r1\r\n            ,const Hash<T,max_len> &b, const int l2, const int r2) const{\r\
    \n    assert(0 <= l1 && l1 <= r1 && r1 <= a.size());\r\n    assert(0 <= l2 &&\
    \ l2 <= r2 && r2 <= b.size());\r\n    const int pos = lcp(a, l1, r1, b, l2, r2);\r\
    \n    if(pos < min(r1-l1, r2-l2)) return a.data[l1+pos] < b.data[l2+pos] ? 1 :\
    \ -1;\r\n    if(r1-l1 == r2-l2) return 0;\r\n    return r1-l1 < r2-l2 ? 1 : -1;\r\
    \n  }\r\n  private:\r\n  ull power[max_len + 1];\r\n  ull rnd() const{\r\n   \
    \ mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\r\n \
    \   uniform_int_distribution<ull> rand(2, m-1);\r\n    return rand(mt);\r\n  }\r\
    \n  inline ull add(ull a, const ull b) const noexcept{\r\n    if((a += b) >= m)\
    \ a -= m;\r\n    return a;\r\n  }\r\n  inline ull mul(const ull a, const ull b)\
    \ const noexcept{\r\n    const __uint128_t c = (__uint128_t)a * b;\r\n    return\
    \ add(c >> 61, c & m);\r\n  }\r\n  inline ull fma(const ull a, const ull b, const\
    \ ull c) const noexcept{\r\n    const __uint128_t d = (__uint128_t)a * b + c;\r\
    \n    return add(d >> 61, d & m);\r\n  }\r\n};\n#line 6 \"test/aoj/ALDS1/ALDS1_14_B.test.cpp\"\
    \n\r\nRollingHash<10000> roliha;\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  string s,t;\r\n  cin >> s >> t;\r\n  const auto sh = roliha.gen(s);\r\n  const\
    \ auto th = roliha.gen(t);\r\n  for(int i = 0; i + t.size() <= s.size(); i++){\r\
    \n    if(sh.query(i, i+t.size()) == th.query(0, t.size())){\r\n      cout << i\
    \ << \"\\n\";\r\n    }\r\n  }\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_B\"\r\
    \n\r\n#include \"../../../template/template.hpp\"\r\n\r\n#include \"../../../string/rolling-hash.hpp\"\
    \r\n\r\nRollingHash<10000> roliha;\r\nint main(){\r\n  cin.tie(nullptr);\r\n \
    \ ios::sync_with_stdio(false);\r\n  string s,t;\r\n  cin >> s >> t;\r\n  const\
    \ auto sh = roliha.gen(s);\r\n  const auto th = roliha.gen(t);\r\n  for(int i\
    \ = 0; i + t.size() <= s.size(); i++){\r\n    if(sh.query(i, i+t.size()) == th.query(0,\
    \ t.size())){\r\n      cout << i << \"\\n\";\r\n    }\r\n  }\r\n}"
  dependsOn:
  - template/template.hpp
  - string/rolling-hash.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2023-03-13 21:51:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1/ALDS1_14_B.test.cpp
- /verify/test/aoj/ALDS1/ALDS1_14_B.test.cpp.html
title: test/aoj/ALDS1/ALDS1_14_B.test.cpp
---
