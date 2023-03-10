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
  bundledCode: "#line 1 \"math/isprime.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing ull = unsigned long long;\n\ninline ull\
    \ modmul(ull a, ull b, ull m) noexcept{\n\tll ret = a * b - m * ull(1.L / m *\
    \ a * b);\n\treturn ret + m * (ret < 0) - m * (ret >= (ll)m);\n}\ninline ull modpow(ull\
    \ b, ull e, ull m) noexcept{\n\tull ans = 1;\n\tfor(; e; b = modmul(b, b, m),\
    \ e >>= 1)\n\t\tif(e & 1) ans = modmul(ans, b, m);\n\treturn ans;\n}\nbool is_prime(const\
    \ ull n){\n\tif(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\n\tstatic constexpr\
    \ ull A[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };\n\tconst ull\
    \ s = __builtin_ctzll(n - 1), d = n >> s;\n\tfor(ull a : A){   // ^ count trailing\
    \ zeroes\n\t\tull p = modpow(a % n, d, n), i = s;\n\t\twhile(p != 1 && p != n\
    \ - 1 && a % n && i--)\n\t\t\tp = modmul(p, p, n);\n\t\tif(p != n - 1 && i !=\
    \ s) return false;\n\t}\n\treturn true;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\
    using ull = unsigned long long;\n\ninline ull modmul(ull a, ull b, ull m) noexcept{\n\
    \tll ret = a * b - m * ull(1.L / m * a * b);\n\treturn ret + m * (ret < 0) - m\
    \ * (ret >= (ll)m);\n}\ninline ull modpow(ull b, ull e, ull m) noexcept{\n\tull\
    \ ans = 1;\n\tfor(; e; b = modmul(b, b, m), e >>= 1)\n\t\tif(e & 1) ans = modmul(ans,\
    \ b, m);\n\treturn ans;\n}\nbool is_prime(const ull n){\n\tif(n < 2 || n % 6 %\
    \ 4 != 1) return (n | 1) == 3;\n\tstatic constexpr ull A[] = { 2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022 };\n\tconst ull s = __builtin_ctzll(n - 1), d =\
    \ n >> s;\n\tfor(ull a : A){   // ^ count trailing zeroes\n\t\tull p = modpow(a\
    \ % n, d, n), i = s;\n\t\twhile(p != 1 && p != n - 1 && a % n && i--)\n\t\t\t\
    p = modmul(p, p, n);\n\t\tif(p != n - 1 && i != s) return false;\n\t}\n\treturn\
    \ true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/isprime.cpp
  requiredBy: []
  timestamp: '2022-12-24 01:13:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/isprime.cpp
layout: document
redirect_from:
- /library/math/isprime.cpp
- /library/math/isprime.cpp.html
title: math/isprime.cpp
---
