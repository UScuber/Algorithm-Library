---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/eratosthenes.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n\nstruct range_factorization {\n  private:\n\
    \  ll L,R,M;\n  vector<int> small;  // \u5C0F\u3055\u3044\u7BE9\n  vector<vector<ll>>\
    \ large;  // \u5927\u304D\u3044\u7BE9\n  vector<ll> aux;  // aux[i] := large[i]\
    \ \u306E\u7D20\u56E0\u6570\u306E\u7A4D\n  public:\n  range_factorization(const\
    \ ll L, const ll R): L(L), R(R), M(sqrt(R)+1){\n    small.resize(M);\n    for(int\
    \ i = 0; i < M; i++) small[i] = i;\n    large.resize(R-L);\n    aux.assign(R-L,\
    \ 1);\n\n    for(ll i = 2; i*i < R; i++){\n      if(small[i] < i) continue;\n\
    \      small[i] = i;\n      for(ll j = i*i; j < M; j += i){\n        if(small[j]\
    \ == j) small[j] = i;\n      }\n      for(ll j = max(2*i, L+i-1)/i*i; j < R; j\
    \ += i){\n        ll k = j;\n        //\u7D20\u56E0\u6570\u306E\u7A4D\u304Csqrt(R)\u3092\
    \u8D85\u3048\u308B\u307E\u3067\u7D20\u56E0\u6570\u3092\u63A2\u3059\n        while(k\
    \ % i == 0){\n          if(aux[j-L] * aux[j-L] > R) break;\n          large[j-L].push_back(i);\n\
    \          aux[j-L] *= i;\n          k /= i;\n        }\n      }\n    }\n  }\n\
    \  vector<ll> factor(ll n){\n    assert(L <= n && n < R);\n    vector<ll> res\
    \ = large[n - L];\n    n /= aux[n-L];\n    if(n >= M){\n      res.push_back(n);\n\
    \      return res;\n    }\n    while(n > 1){\n      res.push_back(small[n]);\n\
    \      n /= small[n];\n    }\n    return res;\n  }\n};\n\n\n\nstruct range_eratosthenes\
    \ {\n  private:\n  ll L,R,M;\n  static constexpr int Max_range = 1000010; //10^6\n\
    \  bitset<Max_range> small, large;\n  public:\n  range_eratosthenes(const ll L,\
    \ const ll R) : L(L), R(R), M(sqrt(R)+1){\n    assert(M <= Max_range && R - L\
    \ <= Max_range);\n    for(ll i = 2; i < M; i++){\n      if(small[i]) continue;\n\
    \      for(ll j = i+i; j < M; j += i) small[j] = 1;\n      for(ll j = max(2LL,\
    \ (L+i-1)/i)*i; j < R; j += i)\n        large[j - L] = 1;\n    }\n  }\n  bool\
    \ is_prime(const ll n) const{\n    assert(L <= n && n < R);\n    return !large[n\
    \ - L];\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    struct range_factorization {\n  private:\n  ll L,R,M;\n  vector<int> small;  //\
    \ \u5C0F\u3055\u3044\u7BE9\n  vector<vector<ll>> large;  // \u5927\u304D\u3044\
    \u7BE9\n  vector<ll> aux;  // aux[i] := large[i] \u306E\u7D20\u56E0\u6570\u306E\
    \u7A4D\n  public:\n  range_factorization(const ll L, const ll R): L(L), R(R),\
    \ M(sqrt(R)+1){\n    small.resize(M);\n    for(int i = 0; i < M; i++) small[i]\
    \ = i;\n    large.resize(R-L);\n    aux.assign(R-L, 1);\n\n    for(ll i = 2; i*i\
    \ < R; i++){\n      if(small[i] < i) continue;\n      small[i] = i;\n      for(ll\
    \ j = i*i; j < M; j += i){\n        if(small[j] == j) small[j] = i;\n      }\n\
    \      for(ll j = max(2*i, L+i-1)/i*i; j < R; j += i){\n        ll k = j;\n  \
    \      //\u7D20\u56E0\u6570\u306E\u7A4D\u304Csqrt(R)\u3092\u8D85\u3048\u308B\u307E\
    \u3067\u7D20\u56E0\u6570\u3092\u63A2\u3059\n        while(k % i == 0){\n     \
    \     if(aux[j-L] * aux[j-L] > R) break;\n          large[j-L].push_back(i);\n\
    \          aux[j-L] *= i;\n          k /= i;\n        }\n      }\n    }\n  }\n\
    \  vector<ll> factor(ll n){\n    assert(L <= n && n < R);\n    vector<ll> res\
    \ = large[n - L];\n    n /= aux[n-L];\n    if(n >= M){\n      res.push_back(n);\n\
    \      return res;\n    }\n    while(n > 1){\n      res.push_back(small[n]);\n\
    \      n /= small[n];\n    }\n    return res;\n  }\n};\n\n\n\nstruct range_eratosthenes\
    \ {\n  private:\n  ll L,R,M;\n  static constexpr int Max_range = 1000010; //10^6\n\
    \  bitset<Max_range> small, large;\n  public:\n  range_eratosthenes(const ll L,\
    \ const ll R) : L(L), R(R), M(sqrt(R)+1){\n    assert(M <= Max_range && R - L\
    \ <= Max_range);\n    for(ll i = 2; i < M; i++){\n      if(small[i]) continue;\n\
    \      for(ll j = i+i; j < M; j += i) small[j] = 1;\n      for(ll j = max(2LL,\
    \ (L+i-1)/i)*i; j < R; j += i)\n        large[j - L] = 1;\n    }\n  }\n  bool\
    \ is_prime(const ll n) const{\n    assert(L <= n && n < R);\n    return !large[n\
    \ - L];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/eratosthenes.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/eratosthenes.cpp
layout: document
redirect_from:
- /library/math/eratosthenes.cpp
- /library/math/eratosthenes.cpp.html
title: math/eratosthenes.cpp
---
