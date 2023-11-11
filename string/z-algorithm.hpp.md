---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/String/Z-Algorithm.test.cpp
    title: test/yosupo/String/Z-Algorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/z-algorithm.hpp\"\nvector<int> z_algo(const string\
    \ &s){\r\n  const int n = s.size();\r\n  vector<int> z(n);\r\n  z[0] = n;\r\n\
    \  int i = 1, j = 0;\r\n  while(i < n){\r\n    while(i + j < n && s[j] == s[i\
    \ + j]) j++;\r\n    z[i] = j;\r\n    if(!j){\r\n      i++;\r\n      continue;\r\
    \n    }\r\n    int k = 1;\r\n    while(k < j && z[k] + k < j) z[i + k++] = z[k];\r\
    \n    i += k;\r\n    j -= k;\r\n  }\r\n  return z;\r\n}\n"
  code: "vector<int> z_algo(const string &s){\r\n  const int n = s.size();\r\n  vector<int>\
    \ z(n);\r\n  z[0] = n;\r\n  int i = 1, j = 0;\r\n  while(i < n){\r\n    while(i\
    \ + j < n && s[j] == s[i + j]) j++;\r\n    z[i] = j;\r\n    if(!j){\r\n      i++;\r\
    \n      continue;\r\n    }\r\n    int k = 1;\r\n    while(k < j && z[k] + k <\
    \ j) z[i + k++] = z[k];\r\n    i += k;\r\n    j -= k;\r\n  }\r\n  return z;\r\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: string/z-algorithm.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/String/Z-Algorithm.test.cpp
documentation_of: string/z-algorithm.hpp
layout: document
redirect_from:
- /library/string/z-algorithm.hpp
- /library/string/z-algorithm.hpp.html
title: string/z-algorithm.hpp
---
