---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/HashMap.hpp
    title: data-structure/HashMap.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Associative-Array.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n#line\
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
    \ 4 \"test/yosupo/Data-Structure/Associative-Array.test.cpp\"\n\n#line 1 \"data-structure/HashMap.hpp\"\
    \n#include <chrono>\r\n\r\ntemplate <class Key, class Val, int logn = 20, Val\
    \ initval = Val()>\r\nstruct HashMap {\r\n  using uint = unsigned int;\r\n  using\
    \ ull = unsigned long long;\r\n  private:\r\n  static constexpr unsigned int N\
    \ = 1 << logn;\r\n  Key *keys;\r\n  Val *vals;\r\n  bitset<N> flag;\r\n  const\
    \ ull r;\r\n  static constexpr uint shift = 64 - logn;\r\n  constexpr ull rng()\
    \ const{\r\n    ull m = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();\r\
    \n    m ^= m >> 16;\r\n    m ^= m << 32;\r\n    return m;\r\n  }\r\n  public:\r\
    \n  HashMap() : keys(new Key[N]), vals(new Val[N]), r(rng()){}\r\n  inline constexpr\
    \ Val &operator[](const Key i) noexcept{\r\n    uint hash = (ull(i) * r) >> shift;\r\
    \n    while(true){\r\n      if(!flag[hash]){\r\n        keys[hash] = i;\r\n  \
    \      flag[hash] = 1;\r\n        return vals[hash] = initval;\r\n      }\r\n\
    \      if(keys[hash] == i) return vals[hash];\r\n      hash = (hash + 1) & (N\
    \ - 1);\r\n    }\r\n  }\r\n  inline constexpr bool count(const Key i) const noexcept{\r\
    \n    uint hash = (ull(i) * r) >> shift;\r\n    while(true){\r\n      if(!flag[hash])\
    \ return false;\r\n      if(keys[hash] == i) return true;\r\n      hash = (hash\
    \ + 1) & (N - 1);\r\n    }\r\n  }\r\n};\n#line 6 \"test/yosupo/Data-Structure/Associative-Array.test.cpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int q;\n\
    \  cin >> q;\n  HashMap<ll,ll> cnt;\n  int t; ll k,v;\n  rep(i, q){\n    cin >>\
    \ t;\n    if(t == 0){\n      cin >> k >> v;\n      cnt[k] = v;\n    }else{\n \
    \     cin >> k;\n      cout << cnt[k] << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include \"../../../template/template.hpp\"\n\n#include \"../../../data-structure/HashMap.hpp\"\
    \n\nint main(){\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  int q;\n\
    \  cin >> q;\n  HashMap<ll,ll> cnt;\n  int t; ll k,v;\n  rep(i, q){\n    cin >>\
    \ t;\n    if(t == 0){\n      cin >> k >> v;\n      cnt[k] = v;\n    }else{\n \
    \     cin >> k;\n      cout << cnt[k] << \"\\n\";\n    }\n  }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/HashMap.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Associative-Array.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 19:15:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Associative-Array.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Associative-Array.test.cpp
- /verify/test/yosupo/Data-Structure/Associative-Array.test.cpp.html
title: test/yosupo/Data-Structure/Associative-Array.test.cpp
---
