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
  bundledCode: "#line 1 \"string/manacher.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nvector<int> manacher(const string &s){\n  const int len = s.size();\n\
    \  vector<int> r(len);\n  int i = 0, j = 0;\n  while(i < len){\n    while(i-j\
    \ >= 0 && i+j < len && s[i-j] == s[i+j]) j++;\n    r[i] = j;\n    int k = 1;\n\
    \    while(i-k >= 0 && k+r[i-k] < j) r[i+k] = r[i-k], k++;\n    i += k; j -= k;\n\
    \  }\n  return r;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int> manacher(const\
    \ string &s){\n  const int len = s.size();\n  vector<int> r(len);\n  int i = 0,\
    \ j = 0;\n  while(i < len){\n    while(i-j >= 0 && i+j < len && s[i-j] == s[i+j])\
    \ j++;\n    r[i] = j;\n    int k = 1;\n    while(i-k >= 0 && k+r[i-k] < j) r[i+k]\
    \ = r[i-k], k++;\n    i += k; j -= k;\n  }\n  return r;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.cpp
  requiredBy: []
  timestamp: '2023-01-11 10:00:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/manacher.cpp
layout: document
redirect_from:
- /library/string/manacher.cpp
- /library/string/manacher.cpp.html
title: string/manacher.cpp
---
