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
  bundledCode: "#line 1 \"math/crt.hpp\"\npair<ll, ll> crt(const vector<ll> &r,const\
    \ vector<ll> &m){\n  assert(r.size() == m.size());\n  const int n = (int)r.size();\n\
    \  ll r0 = 0, m0 = 1;\n  for(int i = 0; i < n; i++){\n    assert(1 <= m[i]);\n\
    \    ll r1 = (r[i] % m[i] + m[i]) % m[i], m1 = m[i];\n    if(m0 < m1){\n     \
    \ swap(r0, r1);\n      swap(m0, m1);\n    }\n    if(m0 % m1 == 0){\n      if(r0\
    \ % m1 != r1) return { 0, 0 };\n      continue;\n    }\n    ll im, tmp;\n    const\
    \ ll g = ext_gcd(m0, m1, im, tmp);\n    const ll u1 = (m1 / g);\n    if((r1 -\
    \ r0) % g) return { 0, 0 };\n    const ll x = (r1 - r0) / g % u1 * im % u1;\n\
    \    r0 += x * m0;\n    m0 *= u1;\n    if(r0 < 0) r0 += m0;\n  }\n  return { r0,\
    \ m0 };\n}\n"
  code: "pair<ll, ll> crt(const vector<ll> &r,const vector<ll> &m){\n  assert(r.size()\
    \ == m.size());\n  const int n = (int)r.size();\n  ll r0 = 0, m0 = 1;\n  for(int\
    \ i = 0; i < n; i++){\n    assert(1 <= m[i]);\n    ll r1 = (r[i] % m[i] + m[i])\
    \ % m[i], m1 = m[i];\n    if(m0 < m1){\n      swap(r0, r1);\n      swap(m0, m1);\n\
    \    }\n    if(m0 % m1 == 0){\n      if(r0 % m1 != r1) return { 0, 0 };\n    \
    \  continue;\n    }\n    ll im, tmp;\n    const ll g = ext_gcd(m0, m1, im, tmp);\n\
    \    const ll u1 = (m1 / g);\n    if((r1 - r0) % g) return { 0, 0 };\n    const\
    \ ll x = (r1 - r0) / g % u1 * im % u1;\n    r0 += x * m0;\n    m0 *= u1;\n   \
    \ if(r0 < 0) r0 += m0;\n  }\n  return { r0, m0 };\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/crt.hpp
  requiredBy: []
  timestamp: '2023-03-13 22:17:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/crt.hpp
layout: document
redirect_from:
- /library/math/crt.hpp
- /library/math/crt.hpp.html
title: math/crt.hpp
---
