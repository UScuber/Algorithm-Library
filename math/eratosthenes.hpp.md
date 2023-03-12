---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/eratosthenes.hpp\"\n#include <bits/stdc++.h>\r\nusing\
    \ namespace std;\r\nusing ll = long long;\r\n\r\nstruct range_factorization {\r\
    \n  private:\r\n  ll L,R,M;\r\n  vector<int> small;  // \u5C0F\u3055\u3044\u7BE9\
    \r\n  vector<vector<ll>> large;  // \u5927\u304D\u3044\u7BE9\r\n  vector<ll> aux;\
    \  // aux[i] := large[i] \u306E\u7D20\u56E0\u6570\u306E\u7A4D\r\n  public:\r\n\
    \  range_factorization(const ll L, const ll R): L(L), R(R), M(sqrt(R)+1){\r\n\
    \    small.resize(M);\r\n    for(int i = 0; i < M; i++) small[i] = i;\r\n    large.resize(R-L);\r\
    \n    aux.assign(R-L, 1);\r\n\r\n    for(ll i = 2; i*i < R; i++){\r\n      if(small[i]\
    \ < i) continue;\r\n      small[i] = i;\r\n      for(ll j = i*i; j < M; j += i){\r\
    \n        if(small[j] == j) small[j] = i;\r\n      }\r\n      for(ll j = max(2*i,\
    \ L+i-1)/i*i; j < R; j += i){\r\n        ll k = j;\r\n        //\u7D20\u56E0\u6570\
    \u306E\u7A4D\u304Csqrt(R)\u3092\u8D85\u3048\u308B\u307E\u3067\u7D20\u56E0\u6570\
    \u3092\u63A2\u3059\r\n        while(k % i == 0){\r\n          if(aux[j-L] * aux[j-L]\
    \ > R) break;\r\n          large[j-L].push_back(i);\r\n          aux[j-L] *= i;\r\
    \n          k /= i;\r\n        }\r\n      }\r\n    }\r\n  }\r\n  vector<ll> factor(ll\
    \ n){\r\n    assert(L <= n && n < R);\r\n    vector<ll> res = large[n - L];\r\n\
    \    n /= aux[n-L];\r\n    if(n >= M){\r\n      res.push_back(n);\r\n      return\
    \ res;\r\n    }\r\n    while(n > 1){\r\n      res.push_back(small[n]);\r\n   \
    \   n /= small[n];\r\n    }\r\n    return res;\r\n  }\r\n};\r\n\r\n\r\n\r\nstruct\
    \ range_eratosthenes {\r\n  private:\r\n  ll L,R,M;\r\n  static constexpr int\
    \ Max_range = 1000010; //10^6\r\n  bitset<Max_range> small, large;\r\n  public:\r\
    \n  range_eratosthenes(const ll L, const ll R) : L(L), R(R), M(sqrt(R)+1){\r\n\
    \    assert(M <= Max_range && R - L <= Max_range);\r\n    for(ll i = 2; i < M;\
    \ i++){\r\n      if(small[i]) continue;\r\n      for(ll j = i+i; j < M; j += i)\
    \ small[j] = 1;\r\n      for(ll j = max(2LL, (L+i-1)/i)*i; j < R; j += i)\r\n\
    \        large[j - L] = 1;\r\n    }\r\n  }\r\n  bool is_prime(const ll n) const{\r\
    \n    assert(L <= n && n < R);\r\n    return !large[n - L];\r\n  }\r\n};\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\nusing ll = long long;\r\
    \n\r\nstruct range_factorization {\r\n  private:\r\n  ll L,R,M;\r\n  vector<int>\
    \ small;  // \u5C0F\u3055\u3044\u7BE9\r\n  vector<vector<ll>> large;  // \u5927\
    \u304D\u3044\u7BE9\r\n  vector<ll> aux;  // aux[i] := large[i] \u306E\u7D20\u56E0\
    \u6570\u306E\u7A4D\r\n  public:\r\n  range_factorization(const ll L, const ll\
    \ R): L(L), R(R), M(sqrt(R)+1){\r\n    small.resize(M);\r\n    for(int i = 0;\
    \ i < M; i++) small[i] = i;\r\n    large.resize(R-L);\r\n    aux.assign(R-L, 1);\r\
    \n\r\n    for(ll i = 2; i*i < R; i++){\r\n      if(small[i] < i) continue;\r\n\
    \      small[i] = i;\r\n      for(ll j = i*i; j < M; j += i){\r\n        if(small[j]\
    \ == j) small[j] = i;\r\n      }\r\n      for(ll j = max(2*i, L+i-1)/i*i; j <\
    \ R; j += i){\r\n        ll k = j;\r\n        //\u7D20\u56E0\u6570\u306E\u7A4D\
    \u304Csqrt(R)\u3092\u8D85\u3048\u308B\u307E\u3067\u7D20\u56E0\u6570\u3092\u63A2\
    \u3059\r\n        while(k % i == 0){\r\n          if(aux[j-L] * aux[j-L] > R)\
    \ break;\r\n          large[j-L].push_back(i);\r\n          aux[j-L] *= i;\r\n\
    \          k /= i;\r\n        }\r\n      }\r\n    }\r\n  }\r\n  vector<ll> factor(ll\
    \ n){\r\n    assert(L <= n && n < R);\r\n    vector<ll> res = large[n - L];\r\n\
    \    n /= aux[n-L];\r\n    if(n >= M){\r\n      res.push_back(n);\r\n      return\
    \ res;\r\n    }\r\n    while(n > 1){\r\n      res.push_back(small[n]);\r\n   \
    \   n /= small[n];\r\n    }\r\n    return res;\r\n  }\r\n};\r\n\r\n\r\n\r\nstruct\
    \ range_eratosthenes {\r\n  private:\r\n  ll L,R,M;\r\n  static constexpr int\
    \ Max_range = 1000010; //10^6\r\n  bitset<Max_range> small, large;\r\n  public:\r\
    \n  range_eratosthenes(const ll L, const ll R) : L(L), R(R), M(sqrt(R)+1){\r\n\
    \    assert(M <= Max_range && R - L <= Max_range);\r\n    for(ll i = 2; i < M;\
    \ i++){\r\n      if(small[i]) continue;\r\n      for(ll j = i+i; j < M; j += i)\
    \ small[j] = 1;\r\n      for(ll j = max(2LL, (L+i-1)/i)*i; j < R; j += i)\r\n\
    \        large[j - L] = 1;\r\n    }\r\n  }\r\n  bool is_prime(const ll n) const{\r\
    \n    assert(L <= n && n < R);\r\n    return !large[n - L];\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/eratosthenes.hpp
layout: document
redirect_from:
- /library/math/eratosthenes.hpp
- /library/math/eratosthenes.hpp.html
title: math/eratosthenes.hpp
---
