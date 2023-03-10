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
  bundledCode: "#line 1 \"string/z-algorithm.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nvector<int> z_algo(const string &s){\n  const int n = s.size();\n\
    \  vector<int> z(n);\n  z[0] = n;\n  int i = 1, j = 0;\n  while(i < n){\n    while(i\
    \ + j < n && s[j] == s[i + j]) j++;\n    z[i] = j;\n    if(!j){\n      i++;\n\
    \      continue;\n    }\n    int k = 1;\n    while(k < j && z[k] + k < j) z[i\
    \ + k++] = z[k];\n    i += k;\n    j -= k;\n  }\n  return z;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int> z_algo(const\
    \ string &s){\n  const int n = s.size();\n  vector<int> z(n);\n  z[0] = n;\n \
    \ int i = 1, j = 0;\n  while(i < n){\n    while(i + j < n && s[j] == s[i + j])\
    \ j++;\n    z[i] = j;\n    if(!j){\n      i++;\n      continue;\n    }\n    int\
    \ k = 1;\n    while(k < j && z[k] + k < j) z[i + k++] = z[k];\n    i += k;\n \
    \   j -= k;\n  }\n  return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z-algorithm.cpp
  requiredBy: []
  timestamp: '2022-01-28 17:27:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/z-algorithm.cpp
layout: document
redirect_from:
- /library/string/z-algorithm.cpp
- /library/string/z-algorithm.cpp.html
title: string/z-algorithm.cpp
---
