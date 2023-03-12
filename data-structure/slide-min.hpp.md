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
  bundledCode: "#line 1 \"data-structure/slide-min.hpp\"\ntemplate <class T>\r\nvector<T>\
    \ slide_min(const vector<T> &a, int k){\r\n  int n = (int)a.size();\r\n  deque<T>\
    \ que;\r\n  vector<T> res(n);\r\n  for(int i = 0; i < n + k - 1; i++){\r\n   \
    \ while(!que.empty() && i < n && a[que.back()] >= a[i]){\r\n      que.pop_back();\r\
    \n    }\r\n    que.push_back(i);\r\n    if(i - k + 1 >= 0){\r\n      res[i - k\
    \ + 1] = a[que.front()];\r\n      if(que.front() == i - k + 1) que.pop_front();\r\
    \n    }\r\n  }\r\n  return res;\r\n}\n"
  code: "template <class T>\r\nvector<T> slide_min(const vector<T> &a, int k){\r\n\
    \  int n = (int)a.size();\r\n  deque<T> que;\r\n  vector<T> res(n);\r\n  for(int\
    \ i = 0; i < n + k - 1; i++){\r\n    while(!que.empty() && i < n && a[que.back()]\
    \ >= a[i]){\r\n      que.pop_back();\r\n    }\r\n    que.push_back(i);\r\n   \
    \ if(i - k + 1 >= 0){\r\n      res[i - k + 1] = a[que.front()];\r\n      if(que.front()\
    \ == i - k + 1) que.pop_front();\r\n    }\r\n  }\r\n  return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slide-min.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/slide-min.hpp
layout: document
redirect_from:
- /library/data-structure/slide-min.hpp
- /library/data-structure/slide-min.hpp.html
title: data-structure/slide-min.hpp
---
