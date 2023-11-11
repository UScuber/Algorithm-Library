---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/floor-sum.hpp
    title: math/floor-sum.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/yosupo/Math/Sum-of-Floor-of-Linear.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\r\n\r\n#line\
    \ 1 \"template/template.hpp\"\n#include <iostream>\r\n#include <cmath>\r\n#include\
    \ <string>\r\n#include <vector>\r\n#include <algorithm>\r\n#include <tuple>\r\n\
    #include <cstdint>\r\n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\
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
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Math/Sum-of-Floor-of-Linear.test.cpp\"\
    \n\r\n#line 1 \"math/floor-sum.hpp\"\nusing ull = unsigned long long;\r\n\r\n\
    ull floor_sum_unsigned(ull n, ull m, ull a, ull b){\r\n  ull ans = 0;\r\n  while(true){\r\
    \n    if(a >= m){\r\n      ans += n * (n - 1) / 2 * (a / m);\r\n      a %= m;\r\
    \n    }\r\n    if(b >= m){\r\n      ans += n * (b / m);\r\n      b %= m;\r\n \
    \   }\r\n    const ull y_max = a * n + b;\r\n    if(y_max < m) break;\r\n    n\
    \ = y_max / m;\r\n    b = y_max % m;\r\n    swap(m, a);\r\n  }\r\n  return ans;\r\
    \n}\r\nll floor_sum(const ll n, const ll m, ll a, ll b){\r\n  assert(0 <= n &&\
    \ n < (1LL << 32));\r\n  assert(1 <= m && m < (1LL << 32));\r\n  ull ans = 0;\r\
    \n  if(a < 0){\r\n    const ull a2 = (a % m + m) % m;\r\n    ans -= 1ULL * n *\
    \ (n - 1) / 2 * ((a2 - a) / m);\r\n    a = a2;\r\n  }\r\n  if(b < 0){\r\n    const\
    \ ull b2 = (b % m + m) % m;\r\n    ans -= 1ULL * n * ((b2 - b) / m);\r\n    b\
    \ = b2;\r\n  }\r\n  return ans + floor_sum_unsigned(n, m, a, b);\r\n}\n#line 6\
    \ \"test/yosupo/Math/Sum-of-Floor-of-Linear.test.cpp\"\n\r\nint main(){\r\n  cin.tie(nullptr);\r\
    \n  ios_base::sync_with_stdio(false);\r\n  int t;\r\n  cin >> t;\r\n  rep(_, t){\r\
    \n    int n,m,a,b;\r\n    cin >> n >> m >> a >> b;\r\n    cout << floor_sum(n,\
    \ m, a, b) << \"\\n\";\r\n  }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \r\n\r\n#include \"../../../template/template.hpp\"\r\n\r\n#include \"../../../math/floor-sum.hpp\"\
    \r\n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios_base::sync_with_stdio(false);\r\
    \n  int t;\r\n  cin >> t;\r\n  rep(_, t){\r\n    int n,m,a,b;\r\n    cin >> n\
    \ >> m >> a >> b;\r\n    cout << floor_sum(n, m, a, b) << \"\\n\";\r\n  }\r\n}"
  dependsOn:
  - template/template.hpp
  - math/floor-sum.hpp
  isVerificationFile: true
  path: test/yosupo/Math/Sum-of-Floor-of-Linear.test.cpp
  requiredBy: []
  timestamp: '2023-11-11 17:58:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Math/Sum-of-Floor-of-Linear.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Math/Sum-of-Floor-of-Linear.test.cpp
- /verify/test/yosupo/Math/Sum-of-Floor-of-Linear.test.cpp.html
title: test/yosupo/Math/Sum-of-Floor-of-Linear.test.cpp
---
