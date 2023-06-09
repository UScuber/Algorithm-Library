---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp
    title: test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Math/Primary-Test.test.cpp
    title: test/yosupo/Math/Primary-Test.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/isprime.hpp\"\nusing ull = unsigned long long;\r\n\r\
    \ninline ull modmul(ull a, ull b, ull m) noexcept{\r\n\tll ret = a * b - m * ull(1.L\
    \ / m * a * b);\r\n\treturn ret + m * (ret < 0) - m * (ret >= (ll)m);\r\n}\r\n\
    inline ull modpow(ull b, ull e, ull m) noexcept{\r\n\tull ans = 1;\r\n\tfor(;\
    \ e; b = modmul(b, b, m), e >>= 1)\r\n\t\tif(e & 1) ans = modmul(ans, b, m);\r\
    \n\treturn ans;\r\n}\r\nbool is_prime(const ull n){\r\n\tif(n < 2 || n % 6 % 4\
    \ != 1) return (n | 1) == 3;\r\n\tstatic constexpr ull A[] = { 2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022 };\r\n\tconst ull s = __builtin_ctzll(n - 1), d\
    \ = n >> s;\r\n\tfor(ull a : A){   // ^ count trailing zeroes\r\n\t\tull p = modpow(a\
    \ % n, d, n), i = s;\r\n\t\twhile(p != 1 && p != n - 1 && a % n && i--)\r\n\t\t\
    \tp = modmul(p, p, n);\r\n\t\tif(p != n - 1 && i != s) return false;\r\n\t}\r\n\
    \treturn true;\r\n}\n"
  code: "using ull = unsigned long long;\r\n\r\ninline ull modmul(ull a, ull b, ull\
    \ m) noexcept{\r\n\tll ret = a * b - m * ull(1.L / m * a * b);\r\n\treturn ret\
    \ + m * (ret < 0) - m * (ret >= (ll)m);\r\n}\r\ninline ull modpow(ull b, ull e,\
    \ ull m) noexcept{\r\n\tull ans = 1;\r\n\tfor(; e; b = modmul(b, b, m), e >>=\
    \ 1)\r\n\t\tif(e & 1) ans = modmul(ans, b, m);\r\n\treturn ans;\r\n}\r\nbool is_prime(const\
    \ ull n){\r\n\tif(n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;\r\n\tstatic constexpr\
    \ ull A[] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };\r\n\tconst ull\
    \ s = __builtin_ctzll(n - 1), d = n >> s;\r\n\tfor(ull a : A){   // ^ count trailing\
    \ zeroes\r\n\t\tull p = modpow(a % n, d, n), i = s;\r\n\t\twhile(p != 1 && p !=\
    \ n - 1 && a % n && i--)\r\n\t\t\tp = modmul(p, p, n);\r\n\t\tif(p != n - 1 &&\
    \ i != s) return false;\r\n\t}\r\n\treturn true;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/isprime.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1/ALDS1_1_C.test2.test.cpp
  - test/yosupo/Math/Primary-Test.test.cpp
documentation_of: math/isprime.hpp
layout: document
redirect_from:
- /library/math/isprime.hpp
- /library/math/isprime.hpp.html
title: math/isprime.hpp
---
