---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/Bitwise-Xor-Convolution.test.cpp
    title: test/yosupo/Bitwise-Xor-Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/convolution/xor-convolution.hpp\"\ntemplate <class\
    \ T>\r\nvoid fzt(vector<T> &a){\r\n  const int n = a.size();\r\n  for(int j =\
    \ 0; (1 << j) < n; j++){\r\n    for(int i = 0; i < n; i++){\r\n      if(!(i >>\
    \ j & 1)){\r\n        const T x = a[i], y = a[i | 1 << j];\r\n        a[i] = x\
    \ + y;\r\n        a[i | 1 << j] = x - y;\r\n      }\r\n    }\r\n  }\r\n}\r\ntemplate\
    \ <class T>\r\nvoid fmt(vector<T> &a){\r\n  const int n = a.size();\r\n  for(int\
    \ j = 0; (1 << j) < n; j++){\r\n    for(int i = 0; i < n; i++){\r\n      if(!(i\
    \ >> j & 1)){\r\n        const T x = a[i], y = a[i | 1 << j];\r\n        a[i]\
    \ = (x + y) / 2;\r\n        a[i | 1 << j] = (x - y) / 2;\r\n      }\r\n    }\r\
    \n  }\r\n}\r\ntemplate <class T>\r\nvector<T> xor_convolution(vector<T> a, vector<T>\
    \ b){\r\n  const int n = a.size();\r\n  assert((n & (n - 1)) == 0 && a.size()\
    \ == b.size());\r\n  fzt(a);\r\n  fzt(b);\r\n  vector<T> c(n);\r\n  for(int i\
    \ = 0; i < n; i++) c[i] = a[i] * b[i];\r\n  fmt(c);\r\n  return c;\r\n}\n"
  code: "template <class T>\r\nvoid fzt(vector<T> &a){\r\n  const int n = a.size();\r\
    \n  for(int j = 0; (1 << j) < n; j++){\r\n    for(int i = 0; i < n; i++){\r\n\
    \      if(!(i >> j & 1)){\r\n        const T x = a[i], y = a[i | 1 << j];\r\n\
    \        a[i] = x + y;\r\n        a[i | 1 << j] = x - y;\r\n      }\r\n    }\r\
    \n  }\r\n}\r\ntemplate <class T>\r\nvoid fmt(vector<T> &a){\r\n  const int n =\
    \ a.size();\r\n  for(int j = 0; (1 << j) < n; j++){\r\n    for(int i = 0; i <\
    \ n; i++){\r\n      if(!(i >> j & 1)){\r\n        const T x = a[i], y = a[i |\
    \ 1 << j];\r\n        a[i] = (x + y) / 2;\r\n        a[i | 1 << j] = (x - y) /\
    \ 2;\r\n      }\r\n    }\r\n  }\r\n}\r\ntemplate <class T>\r\nvector<T> xor_convolution(vector<T>\
    \ a, vector<T> b){\r\n  const int n = a.size();\r\n  assert((n & (n - 1)) == 0\
    \ && a.size() == b.size());\r\n  fzt(a);\r\n  fzt(b);\r\n  vector<T> c(n);\r\n\
    \  for(int i = 0; i < n; i++) c[i] = a[i] * b[i];\r\n  fmt(c);\r\n  return c;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: math/convolution/xor-convolution.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/Bitwise-Xor-Convolution.test.cpp
documentation_of: math/convolution/xor-convolution.hpp
layout: document
redirect_from:
- /library/math/convolution/xor-convolution.hpp
- /library/math/convolution/xor-convolution.hpp.html
title: math/convolution/xor-convolution.hpp
---
