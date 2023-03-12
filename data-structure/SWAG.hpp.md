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
  bundledCode: "#line 1 \"data-structure/SWAG.hpp\"\ntemplate <class T, T(*op)(const\
    \ T&,const T&), const T(*e)()>\r\nstruct SWAG : deque<T> {\r\n  private:\r\n \
    \ T front = e();\r\n  stack<T> back;\r\n  int l = 0, r = 0;\r\n  public:\r\n \
    \ SWAG(const int n = 0) : deque<T>(n, e()){}\r\n  SWAG(const deque<T> &v) : deque<T>(v){}\r\
    \n  T fold(const int i, const int j){\r\n    assert(l <= i && i <= j);\r\n   \
    \ assert(r <= j && j <= (int)(*this).size());\r\n    while(r < j) front = op(front,\
    \ (*this)[r++]);\r\n    while(l < i){\r\n      if(back.empty()){\r\n        T\
    \ temp = e();\r\n        for(int u = r - 1; u >= l; u--) back.push(temp = op((*this)[u],\
    \ temp));\r\n        front = e();\r\n      }\r\n      back.pop();\r\n      l++;\r\
    \n    }\r\n    if(back.empty()) return front;\r\n    return op(back.top(), front);\r\
    \n  }\r\n  void pop(){\r\n    if(!l) fold(l + 1, max(l + 1, r));\r\n    l--; r--;\r\
    \n    (*this).pop_front();\r\n  }\r\n};\n"
  code: "template <class T, T(*op)(const T&,const T&), const T(*e)()>\r\nstruct SWAG\
    \ : deque<T> {\r\n  private:\r\n  T front = e();\r\n  stack<T> back;\r\n  int\
    \ l = 0, r = 0;\r\n  public:\r\n  SWAG(const int n = 0) : deque<T>(n, e()){}\r\
    \n  SWAG(const deque<T> &v) : deque<T>(v){}\r\n  T fold(const int i, const int\
    \ j){\r\n    assert(l <= i && i <= j);\r\n    assert(r <= j && j <= (int)(*this).size());\r\
    \n    while(r < j) front = op(front, (*this)[r++]);\r\n    while(l < i){\r\n \
    \     if(back.empty()){\r\n        T temp = e();\r\n        for(int u = r - 1;\
    \ u >= l; u--) back.push(temp = op((*this)[u], temp));\r\n        front = e();\r\
    \n      }\r\n      back.pop();\r\n      l++;\r\n    }\r\n    if(back.empty())\
    \ return front;\r\n    return op(back.top(), front);\r\n  }\r\n  void pop(){\r\
    \n    if(!l) fold(l + 1, max(l + 1, r));\r\n    l--; r--;\r\n    (*this).pop_front();\r\
    \n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/SWAG.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/SWAG.hpp
layout: document
redirect_from:
- /library/data-structure/SWAG.hpp
- /library/data-structure/SWAG.hpp.html
title: data-structure/SWAG.hpp
---
