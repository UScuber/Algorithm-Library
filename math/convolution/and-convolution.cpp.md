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
  bundledCode: "#line 1 \"math/convolution/and-convolution.cpp\"\n#include <vector>\n\
    #include <cassert>\nusing namespace std;\n\ntemplate <class T>\nvoid fzt(vector<T>\
    \ &a){\n  const int n = a.size();\n  for(int j = 0; (1 << j) < n; j++){\n    for(int\
    \ i = 0; i < n; i++){\n      if(!(i >> j & 1)) a[i] += a[i | 1 << j];\n    }\n\
    \  }\n}\ntemplate <class T>\nvoid fmt(vector<T> &a){\n  const int n = a.size();\n\
    \  for(int j = 0; (1 << j) < n; j++){\n    for(int i = 0; i < n; i++){\n     \
    \ if(!(i >> j & 1)) a[i] -= a[i | 1 << j];\n    }\n  }\n}\ntemplate <class T>\n\
    vector<T> and_convolution(vector<T> a, vector<T> b){\n  const int n = a.size();\n\
    \  assert((n & (n - 1)) == 0 && a.size() == b.size());\n  fzt(a);\n  fzt(b);\n\
    \  vector<T> c(n);\n  for(int i = 0; i < n; i++) c[i] = a[i] * b[i];\n  fmt(c);\n\
    \  return c;\n}\n"
  code: "#include <vector>\n#include <cassert>\nusing namespace std;\n\ntemplate <class\
    \ T>\nvoid fzt(vector<T> &a){\n  const int n = a.size();\n  for(int j = 0; (1\
    \ << j) < n; j++){\n    for(int i = 0; i < n; i++){\n      if(!(i >> j & 1)) a[i]\
    \ += a[i | 1 << j];\n    }\n  }\n}\ntemplate <class T>\nvoid fmt(vector<T> &a){\n\
    \  const int n = a.size();\n  for(int j = 0; (1 << j) < n; j++){\n    for(int\
    \ i = 0; i < n; i++){\n      if(!(i >> j & 1)) a[i] -= a[i | 1 << j];\n    }\n\
    \  }\n}\ntemplate <class T>\nvector<T> and_convolution(vector<T> a, vector<T>\
    \ b){\n  const int n = a.size();\n  assert((n & (n - 1)) == 0 && a.size() == b.size());\n\
    \  fzt(a);\n  fzt(b);\n  vector<T> c(n);\n  for(int i = 0; i < n; i++) c[i] =\
    \ a[i] * b[i];\n  fmt(c);\n  return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/and-convolution.cpp
  requiredBy: []
  timestamp: '2022-09-15 18:24:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convolution/and-convolution.cpp
layout: document
redirect_from:
- /library/math/convolution/and-convolution.cpp
- /library/math/convolution/and-convolution.cpp.html
title: math/convolution/and-convolution.cpp
---
