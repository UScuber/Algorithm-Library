---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/isprime.hpp
    title: math/isprime.hpp
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
  bundledCode: "#line 1 \"test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C\"\n\n#line 1 \"template/template.hpp\"\
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
    \ = b, 1) : 0; }\n#line 4 \"test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp\"\n\n#line\
    \ 1 \"math/isprime.hpp\"\nusing ull = unsigned long long;\r\n\r\ninline ull modmul(ull\
    \ a, ull b, ull m) noexcept{\r\n\tll ret = a * b - m * ull(1.L / m * a * b);\r\
    \n\treturn ret + m * (ret < 0) - m * (ret >= (ll)m);\r\n}\r\ninline ull modpow(ull\
    \ b, ull e, ull m) noexcept{\r\n\tull ans = 1;\r\n\tfor(; e; b = modmul(b, b,\
    \ m), e >>= 1)\r\n\t\tif(e & 1) ans = modmul(ans, b, m);\r\n\treturn ans;\r\n\
    }\r\nbool is_prime(const ull n){\r\n\tif(n < 2 || n % 6 % 4 != 1) return (n |\
    \ 1) == 3;\r\n\tstatic constexpr ull A[] = { 2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022 };\r\n\tconst ull s = __builtin_ctzll(n - 1), d = n >> s;\r\n\tfor(ull\
    \ a : A){   // ^ count trailing zeroes\r\n\t\tull p = modpow(a % n, d, n), i =\
    \ s;\r\n\t\twhile(p != 1 && p != n - 1 && a % n && i--)\r\n\t\t\tp = modmul(p,\
    \ p, n);\r\n\t\tif(p != n - 1 && i != s) return false;\r\n\t}\r\n\treturn true;\r\
    \n}\n#line 6 \"test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp\"\n\nint main(){\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  int n;\n  cin >> n;\n  int ans = 0;\n  rep(i,\
    \ n){\n    int a; cin >> a;\n    if(is_prime(a)) ans++;\n  }\n  cout << ans <<\
    \ \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_1_C\"\n\
    \n#include \"../../../template/template.hpp\"\n\n#include \"../../../math/isprime.hpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int n;\n\
    \  cin >> n;\n  int ans = 0;\n  rep(i, n){\n    int a; cin >> a;\n    if(is_prime(a))\
    \ ans++;\n  }\n  cout << ans << \"\\n\";\n}"
  dependsOn:
  - template/template.hpp
  - math/isprime.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp
  requiredBy: []
  timestamp: '2023-03-14 00:34:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp
- /verify/test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp.html
title: test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp
---
