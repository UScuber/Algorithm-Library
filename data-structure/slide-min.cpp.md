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
  bundledCode: "#line 1 \"data-structure/slide-min.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T>\nvector<T> slide_min(const vector<T>\
    \ &a, int k){\n  int n = (int)a.size();\n  deque<T> que;\n  vector<T> res(n);\n\
    \  for(int i = 0; i < n + k - 1; i++){\n    while(!que.empty() && i < n && a[que.back()]\
    \ >= a[i]){\n      que.pop_back();\n    }\n    que.push_back(i);\n    if(i - k\
    \ + 1 >= 0){\n      res[i - k + 1] = a[que.front()];\n      if(que.front() ==\
    \ i - k + 1) que.pop_front();\n    }\n  }\n  return res;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T>\nvector<T>\
    \ slide_min(const vector<T> &a, int k){\n  int n = (int)a.size();\n  deque<T>\
    \ que;\n  vector<T> res(n);\n  for(int i = 0; i < n + k - 1; i++){\n    while(!que.empty()\
    \ && i < n && a[que.back()] >= a[i]){\n      que.pop_back();\n    }\n    que.push_back(i);\n\
    \    if(i - k + 1 >= 0){\n      res[i - k + 1] = a[que.front()];\n      if(que.front()\
    \ == i - k + 1) que.pop_front();\n    }\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slide-min.cpp
  requiredBy: []
  timestamp: '2022-01-28 17:27:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/slide-min.cpp
layout: document
redirect_from:
- /library/data-structure/slide-min.cpp
- /library/data-structure/slide-min.cpp.html
title: data-structure/slide-min.cpp
---
