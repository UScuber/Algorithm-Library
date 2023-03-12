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
  bundledCode: "#line 1 \"math/math.hpp\"\n#include <bits/stdc++.h>\r\nusing ll =\
    \ long long;\r\nusing namespace std;\r\n\r\n\r\ntemplate<class T>\r\nT gcd(T a,\
    \ T b){\r\n  if(!b) return a;\r\n  return gcd(b, a % b);\r\n}\r\n\r\ntemplate<class\
    \ T>\r\nT lcm(T a, T b){\r\n  return a / gcd(a, b) * b;\r\n}\r\n\r\n\r\nll modPow(ll\
    \ a, ll n, ll p){\r\n  a %= p;\r\n  ll res = 1;\r\n  while(n){\r\n    if(n & 1)\
    \ (res *= a) %= p;\r\n    (a *= a) %= p;\r\n    n >>= 1;\r\n  }\r\n  return res;\r\
    \n}\r\n\r\n\r\nll ext_gcd(ll a, ll b, ll &x, ll &y){\r\n  ll d = a;\r\n  if(b){\r\
    \n    d = ext_gcd(b, a % b, y, x);\r\n    y -= (a / b) * x;\r\n  }else{ x = 1;\
    \ y = 0; }\r\n  return d;\r\n}\r\n\r\n\r\npair<ll, ll> crt(const vector<ll> &r,const\
    \ vector<ll> &m){\r\n  assert(r.size() == m.size());\r\n  const int n = (int)r.size();\r\
    \n  ll r0 = 0, m0 = 1;\r\n  for(int i = 0; i < n; i++){\r\n    assert(1 <= m[i]);\r\
    \n    ll r1 = (r[i] % m[i] + m[i]) % m[i], m1 = m[i];\r\n    if(m0 < m1){\r\n\
    \      swap(r0, r1);\r\n      swap(m0, m1);\r\n    }\r\n    if(m0 % m1 == 0){\r\
    \n      if(r0 % m1 != r1) return { 0, 0 };\r\n      continue;\r\n    }\r\n   \
    \ ll im, tmp;\r\n    const ll g = ext_gcd(m0, m1, im, tmp);\r\n    const ll u1\
    \ = (m1 / g);\r\n    if((r1 - r0) % g) return { 0, 0 };\r\n    const ll x = (r1\
    \ - r0) / g % u1 * im % u1;\r\n    r0 += x * m0;\r\n    m0 *= u1;\r\n    if(r0\
    \ < 0) r0 += m0;\r\n  }\r\n  return { r0, m0 };\r\n}\r\n\r\n\r\nll euler(ll n){\r\
    \n  ll res = n, k = n;\r\n  for(ll i = 2; i*i <= k; i++){\r\n    if(n % i) continue;\r\
    \n    res = res / i * (i - 1);\r\n    while(n % i == 0) n /= i;\r\n  }\r\n  if(n\
    \ != 1) res = res / n * (n - 1);\r\n  return res;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\nusing ll = long long;\r\nusing namespace std;\r\
    \n\r\n\r\ntemplate<class T>\r\nT gcd(T a, T b){\r\n  if(!b) return a;\r\n  return\
    \ gcd(b, a % b);\r\n}\r\n\r\ntemplate<class T>\r\nT lcm(T a, T b){\r\n  return\
    \ a / gcd(a, b) * b;\r\n}\r\n\r\n\r\nll modPow(ll a, ll n, ll p){\r\n  a %= p;\r\
    \n  ll res = 1;\r\n  while(n){\r\n    if(n & 1) (res *= a) %= p;\r\n    (a *=\
    \ a) %= p;\r\n    n >>= 1;\r\n  }\r\n  return res;\r\n}\r\n\r\n\r\nll ext_gcd(ll\
    \ a, ll b, ll &x, ll &y){\r\n  ll d = a;\r\n  if(b){\r\n    d = ext_gcd(b, a %\
    \ b, y, x);\r\n    y -= (a / b) * x;\r\n  }else{ x = 1; y = 0; }\r\n  return d;\r\
    \n}\r\n\r\n\r\npair<ll, ll> crt(const vector<ll> &r,const vector<ll> &m){\r\n\
    \  assert(r.size() == m.size());\r\n  const int n = (int)r.size();\r\n  ll r0\
    \ = 0, m0 = 1;\r\n  for(int i = 0; i < n; i++){\r\n    assert(1 <= m[i]);\r\n\
    \    ll r1 = (r[i] % m[i] + m[i]) % m[i], m1 = m[i];\r\n    if(m0 < m1){\r\n \
    \     swap(r0, r1);\r\n      swap(m0, m1);\r\n    }\r\n    if(m0 % m1 == 0){\r\
    \n      if(r0 % m1 != r1) return { 0, 0 };\r\n      continue;\r\n    }\r\n   \
    \ ll im, tmp;\r\n    const ll g = ext_gcd(m0, m1, im, tmp);\r\n    const ll u1\
    \ = (m1 / g);\r\n    if((r1 - r0) % g) return { 0, 0 };\r\n    const ll x = (r1\
    \ - r0) / g % u1 * im % u1;\r\n    r0 += x * m0;\r\n    m0 *= u1;\r\n    if(r0\
    \ < 0) r0 += m0;\r\n  }\r\n  return { r0, m0 };\r\n}\r\n\r\n\r\nll euler(ll n){\r\
    \n  ll res = n, k = n;\r\n  for(ll i = 2; i*i <= k; i++){\r\n    if(n % i) continue;\r\
    \n    res = res / i * (i - 1);\r\n    while(n % i == 0) n /= i;\r\n  }\r\n  if(n\
    \ != 1) res = res / n * (n - 1);\r\n  return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/math.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math.hpp
layout: document
redirect_from:
- /library/math/math.hpp
- /library/math/math.hpp.html
title: math/math.hpp
---
