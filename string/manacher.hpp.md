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
  bundledCode: "#line 1 \"string/manacher.hpp\"\nvector<int> manacher(const string\
    \ &s){\r\n  const int len = s.size();\r\n  vector<int> r(len);\r\n  int i = 0,\
    \ j = 0;\r\n  while(i < len){\r\n    while(i-j >= 0 && i+j < len && s[i-j] ==\
    \ s[i+j]) j++;\r\n    r[i] = j;\r\n    int k = 1;\r\n    while(i-k >= 0 && k+r[i-k]\
    \ < j) r[i+k] = r[i-k], k++;\r\n    i += k; j -= k;\r\n  }\r\n  return r;\r\n\
    }\n"
  code: "vector<int> manacher(const string &s){\r\n  const int len = s.size();\r\n\
    \  vector<int> r(len);\r\n  int i = 0, j = 0;\r\n  while(i < len){\r\n    while(i-j\
    \ >= 0 && i+j < len && s[i-j] == s[i+j]) j++;\r\n    r[i] = j;\r\n    int k =\
    \ 1;\r\n    while(i-k >= 0 && k+r[i-k] < j) r[i+k] = r[i-k], k++;\r\n    i +=\
    \ k; j -= k;\r\n  }\r\n  return r;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: string/manacher.hpp
---
