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
  bundledCode: "#line 1 \"math/factorizaiton.hpp\"\nstruct range_factorization {\n\
    \  private:\n  ll L,R,M;\n  vector<int> small;  // \u5C0F\u3055\u3044\u7BE9\n\
    \  vector<vector<ll>> large;  // \u5927\u304D\u3044\u7BE9\n  vector<ll> aux; \
    \ // aux[i] := large[i] \u306E\u7D20\u56E0\u6570\u306E\u7A4D\n  public:\n  range_factorization(const\
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
    \      n /= small[n];\n    }\n    return res;\n  }\n};\n"
  code: "struct range_factorization {\n  private:\n  ll L,R,M;\n  vector<int> small;\
    \  // \u5C0F\u3055\u3044\u7BE9\n  vector<vector<ll>> large;  // \u5927\u304D\u3044\
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
    \      n /= small[n];\n    }\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/factorizaiton.hpp
  requiredBy: []
  timestamp: '2023-03-13 22:02:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/factorizaiton.hpp
layout: document
redirect_from:
- /library/math/factorizaiton.hpp
- /library/math/factorizaiton.hpp.html
title: math/factorizaiton.hpp
---
