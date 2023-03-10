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
  bundledCode: "#line 1 \"math/math.cpp\"\n#include <bits/stdc++.h>\nusing ll = long\
    \ long;\nusing namespace std;\n\n\ntemplate<class T>\nT gcd(T a, T b){\n  if(!b)\
    \ return a;\n  return gcd(b, a % b);\n}\n\ntemplate<class T>\nT lcm(T a, T b){\n\
    \  return a / gcd(a, b) * b;\n}\n\n\nll modPow(ll a, ll n, ll p){\n  a %= p;\n\
    \  ll res = 1;\n  while(n){\n    if(n & 1) (res *= a) %= p;\n    (a *= a) %= p;\n\
    \    n >>= 1;\n  }\n  return res;\n}\n\n\nll ext_gcd(ll a, ll b, ll &x, ll &y){\n\
    \  ll d = a;\n  if(b){\n    d = ext_gcd(b, a % b, y, x);\n    y -= (a / b) * x;\n\
    \  }else{ x = 1; y = 0; }\n  return d;\n}\n\n\npair<ll, ll> crt(const vector<ll>\
    \ &r,const vector<ll> &m){\n  assert(r.size() == m.size());\n  const int n = (int)r.size();\n\
    \  ll r0 = 0, m0 = 1;\n  for(int i = 0; i < n; i++){\n    assert(1 <= m[i]);\n\
    \    ll r1 = (r[i] % m[i] + m[i]) % m[i], m1 = m[i];\n    if(m0 < m1){\n     \
    \ swap(r0, r1);\n      swap(m0, m1);\n    }\n    if(m0 % m1 == 0){\n      if(r0\
    \ % m1 != r1) return { 0, 0 };\n      continue;\n    }\n    ll im, tmp;\n    const\
    \ ll g = ext_gcd(m0, m1, im, tmp);\n    const ll u1 = (m1 / g);\n    if((r1 -\
    \ r0) % g) return { 0, 0 };\n    const ll x = (r1 - r0) / g % u1 * im % u1;\n\
    \    r0 += x * m0;\n    m0 *= u1;\n    if(r0 < 0) r0 += m0;\n  }\n  return { r0,\
    \ m0 };\n}\n\n\nll euler(ll n){\n  ll res = n, k = n;\n  for(ll i = 2; i*i <=\
    \ k; i++){\n    if(n % i) continue;\n    res = res / i * (i - 1);\n    while(n\
    \ % i == 0) n /= i;\n  }\n  if(n != 1) res = res / n * (n - 1);\n  return res;\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing ll = long long;\nusing namespace std;\n\n\
    \ntemplate<class T>\nT gcd(T a, T b){\n  if(!b) return a;\n  return gcd(b, a %\
    \ b);\n}\n\ntemplate<class T>\nT lcm(T a, T b){\n  return a / gcd(a, b) * b;\n\
    }\n\n\nll modPow(ll a, ll n, ll p){\n  a %= p;\n  ll res = 1;\n  while(n){\n \
    \   if(n & 1) (res *= a) %= p;\n    (a *= a) %= p;\n    n >>= 1;\n  }\n  return\
    \ res;\n}\n\n\nll ext_gcd(ll a, ll b, ll &x, ll &y){\n  ll d = a;\n  if(b){\n\
    \    d = ext_gcd(b, a % b, y, x);\n    y -= (a / b) * x;\n  }else{ x = 1; y =\
    \ 0; }\n  return d;\n}\n\n\npair<ll, ll> crt(const vector<ll> &r,const vector<ll>\
    \ &m){\n  assert(r.size() == m.size());\n  const int n = (int)r.size();\n  ll\
    \ r0 = 0, m0 = 1;\n  for(int i = 0; i < n; i++){\n    assert(1 <= m[i]);\n   \
    \ ll r1 = (r[i] % m[i] + m[i]) % m[i], m1 = m[i];\n    if(m0 < m1){\n      swap(r0,\
    \ r1);\n      swap(m0, m1);\n    }\n    if(m0 % m1 == 0){\n      if(r0 % m1 !=\
    \ r1) return { 0, 0 };\n      continue;\n    }\n    ll im, tmp;\n    const ll\
    \ g = ext_gcd(m0, m1, im, tmp);\n    const ll u1 = (m1 / g);\n    if((r1 - r0)\
    \ % g) return { 0, 0 };\n    const ll x = (r1 - r0) / g % u1 * im % u1;\n    r0\
    \ += x * m0;\n    m0 *= u1;\n    if(r0 < 0) r0 += m0;\n  }\n  return { r0, m0\
    \ };\n}\n\n\nll euler(ll n){\n  ll res = n, k = n;\n  for(ll i = 2; i*i <= k;\
    \ i++){\n    if(n % i) continue;\n    res = res / i * (i - 1);\n    while(n %\
    \ i == 0) n /= i;\n  }\n  if(n != 1) res = res / n * (n - 1);\n  return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/math.cpp
  requiredBy: []
  timestamp: '2022-12-12 10:07:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math.cpp
layout: document
redirect_from:
- /library/math/math.cpp
- /library/math/math.cpp.html
title: math/math.cpp
---
