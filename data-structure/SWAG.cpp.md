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
  bundledCode: "#line 1 \"data-structure/SWAG.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class T, T(*op)(const T&,const T&), const T(*e)()>\n\
    struct SWAG : deque<T> {\n  private:\n  T front = e();\n  stack<T> back;\n  int\
    \ l = 0, r = 0;\n  public:\n  SWAG(const int n = 0) : deque<T>(n, e()){}\n  SWAG(const\
    \ deque<T> &v) : deque<T>(v){}\n  T fold(const int i, const int j){\n    assert(l\
    \ <= i && i <= j);\n    assert(r <= j && j <= (int)(*this).size());\n    while(r\
    \ < j) front = op(front, (*this)[r++]);\n    while(l < i){\n      if(back.empty()){\n\
    \        T temp = e();\n        for(int u = r - 1; u >= l; u--) back.push(temp\
    \ = op((*this)[u], temp));\n        front = e();\n      }\n      back.pop();\n\
    \      l++;\n    }\n    if(back.empty()) return front;\n    return op(back.top(),\
    \ front);\n  }\n  void pop(){\n    if(!l) fold(l + 1, max(l + 1, r));\n    l--;\
    \ r--;\n    (*this).pop_front();\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T, T(*op)(const\
    \ T&,const T&), const T(*e)()>\nstruct SWAG : deque<T> {\n  private:\n  T front\
    \ = e();\n  stack<T> back;\n  int l = 0, r = 0;\n  public:\n  SWAG(const int n\
    \ = 0) : deque<T>(n, e()){}\n  SWAG(const deque<T> &v) : deque<T>(v){}\n  T fold(const\
    \ int i, const int j){\n    assert(l <= i && i <= j);\n    assert(r <= j && j\
    \ <= (int)(*this).size());\n    while(r < j) front = op(front, (*this)[r++]);\n\
    \    while(l < i){\n      if(back.empty()){\n        T temp = e();\n        for(int\
    \ u = r - 1; u >= l; u--) back.push(temp = op((*this)[u], temp));\n        front\
    \ = e();\n      }\n      back.pop();\n      l++;\n    }\n    if(back.empty())\
    \ return front;\n    return op(back.top(), front);\n  }\n  void pop(){\n    if(!l)\
    \ fold(l + 1, max(l + 1, r));\n    l--; r--;\n    (*this).pop_front();\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/SWAG.cpp
  requiredBy: []
  timestamp: '2022-09-30 21:07:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/SWAG.cpp
layout: document
redirect_from:
- /library/data-structure/SWAG.cpp
- /library/data-structure/SWAG.cpp.html
title: data-structure/SWAG.cpp
---
