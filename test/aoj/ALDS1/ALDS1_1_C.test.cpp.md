---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/eratosthenes.hpp
    title: math/eratosthenes.hpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj/ALDS1/ALDS1_1_C.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C\"\r\n\r\n#line 1 \"template/template.hpp\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/aoj/ALDS1/ALDS1_1_C.test.cpp\"\n\r\n#line 1 \"\
    math/eratosthenes.hpp\"\nstruct range_eratosthenes {\r\n  private:\r\n  ll L,R,M;\r\
    \n  static constexpr int Max_range = 100000010; //10^8\r\n  bitset<Max_range>\
    \ small, large;\r\n  public:\r\n  range_eratosthenes(const ll L, const ll R) :\
    \ L(L), R(R), M(sqrt(R)+1){\r\n    assert(M <= Max_range && R - L <= Max_range);\r\
    \n    for(ll i = 2; i < M; i++){\r\n      if(small[i]) continue;\r\n      for(ll\
    \ j = i+i; j < M; j += i) small[j] = 1;\r\n      for(ll j = max(2LL, (L+i-1)/i)*i;\
    \ j < R; j += i)\r\n        large[j - L] = 1;\r\n    }\r\n  }\r\n  bool is_prime(const\
    \ ll n) const{\r\n    assert(L <= n && n < R);\r\n    return !large[n - L];\r\n\
    \  }\r\n};\n#line 6 \"test/aoj/ALDS1/ALDS1_1_C.test.cpp\"\n\r\nint main(){\r\n\
    \  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  range_eratosthenes\
    \ ss(1, 100000010);\r\n  int n;\r\n  cin >> n;\r\n  int ans = 0;\r\n  rep(i, n){\r\
    \n    int a; cin >> a;\r\n    if(ss.is_prime(a)) ans++;\r\n  }\r\n  cout << ans\
    \ << \"\\n\";\r\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C\"\r\
    \n\r\n#include \"../../../template/template.hpp\"\r\n\r\n#include \"../../../math/eratosthenes.hpp\"\
    \r\n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  range_eratosthenes ss(1, 100000010);\r\n  int n;\r\n  cin >> n;\r\n  int ans\
    \ = 0;\r\n  rep(i, n){\r\n    int a; cin >> a;\r\n    if(ss.is_prime(a)) ans++;\r\
    \n  }\r\n  cout << ans << \"\\n\";\r\n}"
  dependsOn:
  - template/template.hpp
  - math/eratosthenes.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2023-03-13 22:02:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1/ALDS1_1_C.test.cpp
- /verify/test/aoj/ALDS1/ALDS1_1_C.test.cpp.html
title: test/aoj/ALDS1/ALDS1_1_C.test.cpp
---
