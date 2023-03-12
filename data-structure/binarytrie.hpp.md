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
  bundledCode: "#line 1 \"data-structure/binarytrie.hpp\"\n#include <bits/stdc++.h>\r\
    \nusing namespace std;\r\n\r\ntemplate <class T, size_t MAX_DIGIT>\r\nstruct BinaryTrie\
    \ {\r\n  struct Node {\r\n    int cnt = 0;\r\n    int ch[2] = { -1, -1 };\r\n\
    \  };\r\n  T lazy = 0;\r\n  BinaryTrie() : root(1){}\r\n  void xor_all(T x){ lazy\
    \ ^= x; }\r\n  void reserve(int s){ root.reserve(s); }\r\n  void insert(T val,\
    \ T xor_val = 0){ add(val, 1, xor_val); }\r\n  void erase(T val, T xor_val = 0){\
    \ add(val, -1, xor_val); }\r\n  void add(T val, int num, T xor_val = 0){\r\n \
    \   const T nval = val ^ lazy ^ xor_val;\r\n    int idx = 0;\r\n    root[idx].cnt\
    \ += num;\r\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int f =\
    \ nval >> i & 1;\r\n      if(root[idx].ch[f] == -1){\r\n        root[idx].ch[f]\
    \ = (int)root.size();\r\n        root.emplace_back(Node());\r\n      }\r\n   \
    \   idx = root[idx].ch[f];\r\n      root[idx].cnt += num;\r\n    }\r\n  }\r\n\
    \  void clear(){\r\n    root = { 0 };\r\n    lazy = 0;\r\n  }\r\n  T min(T xor_val\
    \ = 0) const{ return kth_elem(0, xor_val); }\r\n  T max(T xor_val = 0) const{\
    \ return kth_elem(num_size()-1, xor_val); }\r\n  T kth_elem(int k, T xor_val =\
    \ 0) const{\r\n    xor_val ^= lazy;\r\n    int idx = 0;\r\n    T res = 0;\r\n\
    \    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int f = xor_val >>\
    \ i & 1;\r\n      const int l = root[idx].ch[f];\r\n      const int r = root[idx].ch[!f];\r\
    \n      if(l == -1 || root[l].cnt <= k){\r\n        if(l != -1) k -= root[l].cnt;\r\
    \n        idx = r;\r\n        res |= T(1) << i;\r\n      }else idx = l;\r\n  \
    \  }\r\n    return res;\r\n  }\r\n  T lower_bound(T val, T xor_val = 0) const{\r\
    \n    return kth_elem(order(val, xor_val));\r\n  }\r\n  T upper_bound(T val, T\
    \ xor_val = 0) const{\r\n    return kth_elem(order(val+1, xor_val));\r\n  }\r\n\
    \  int order(T val, T xor_val = 0) const{\r\n    xor_val ^= lazy;\r\n    int idx\
    \ = 0, ord = 0;\r\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int\
    \ f = xor_val >> i & 1;\r\n      const int l = root[idx].ch[f];\r\n      const\
    \ int r = root[idx].ch[!f];\r\n      if(val >> i & 1){\r\n        if(l != -1)\
    \ ord += root[l].cnt;\r\n        idx = r;\r\n      }else idx = l;\r\n      if(idx\
    \ == -1) break;\r\n    }\r\n    return ord;\r\n  }\r\n  int count(T val) const{\r\
    \n    const int t = find(val);\r\n    return t == -1 ? 0 : root[t].cnt;\r\n  }\r\
    \n  int size() const{ return root.size(); }\r\n  int num_size() const{ return\
    \ root[0].cnt; }\r\n  private:\r\n  vector<Node> root;\r\n  int find(T val, T\
    \ xor_val = 0) const{\r\n    const T nval = val ^ lazy ^ xor_val;\r\n    int idx\
    \ = 0;\r\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int f = nval\
    \ >> i & 1;\r\n      if(root[idx].ch[f] == -1) return -1;\r\n      idx = root[idx].ch[f];\r\
    \n    }\r\n    return idx;\r\n  }\r\n};\r\n\r\n\r\n\r\n//----- binary trie (sum)\
    \ -----\r\ntemplate <class T, size_t MAX_DIGIT>\r\nstruct BinaryTrie {\r\n  struct\
    \ Node {\r\n    int cnt = 0;\r\n    T sum = 0;\r\n    int ch[2] = { -1, -1 };\r\
    \n  };\r\n  T lazy = 0;\r\n  BinaryTrie() : root(1){}\r\n  void xor_all(T x){\
    \ lazy ^= x; }\r\n  void reserve(int s){ root.reserve(s); }\r\n  void insert(T\
    \ val, T xor_val = 0){ add(val, 1, xor_val); }\r\n  void erase(T val, T xor_val\
    \ = 0){ add(val, -1, xor_val); }\r\n  void add(T val, int num, T xor_val = 0){\r\
    \n    const T nval = val ^ lazy ^ xor_val;\r\n    int idx = 0;\r\n    root[idx].cnt\
    \ += num;\r\n    root[idx].sum += val * num;\r\n    for(int i = MAX_DIGIT-1; i\
    \ >= 0; i--){\r\n      const int f = nval >> i & 1;\r\n      if(root[idx].ch[f]\
    \ == -1){\r\n        root[idx].ch[f] = (int)root.size();\r\n        root.emplace_back(Node());\r\
    \n      }\r\n      idx = root[idx].ch[f];\r\n      root[idx].cnt += num;\r\n \
    \     root[idx].sum += val * num;\r\n    }\r\n  }\r\n  void clear(){\r\n    root\
    \ = { 0 };\r\n    lazy = 0;\r\n  }\r\n  pair<T, T> kth_elem(int k, T xor_val =\
    \ 0) const{\r\n    xor_val ^= lazy;\r\n    int idx = 0;\r\n    T res = 0, tot\
    \ = 0;\r\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int f = xor_val\
    \ >> i & 1;\r\n      const int l = root[idx].ch[f];\r\n      const int r = root[idx].ch[!f];\r\
    \n      if(l == -1 || root[l].cnt <= k){\r\n        if(l != -1){\r\n         \
    \ k -= root[l].cnt;\r\n          tot += root[l].sum;\r\n        }\r\n        idx\
    \ = r;\r\n        res |= T(1) << i;\r\n      }else idx = l;\r\n    }\r\n    tot\
    \ += res * (k + 1);\r\n    return { res, tot };\r\n  }\r\n  int order(T val, T\
    \ xor_val = 0) const{\r\n    xor_val ^= lazy;\r\n    int idx = 0, ord = 0;\r\n\
    \    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int f = xor_val >>\
    \ i & 1;\r\n      const int l = root[idx].ch[f];\r\n      const int r = root[idx].ch[!f];\r\
    \n      if(val >> i & 1){\r\n        if(l != -1) ord += root[l].cnt;\r\n     \
    \   idx = r;\r\n      }else idx = l;\r\n      if(idx == -1) break;\r\n    }\r\n\
    \    return ord;\r\n  }\r\n  int count(T val) const{\r\n    const int t = find(val);\r\
    \n    return t == -1 ? 0 : root[t].cnt;\r\n  }\r\n  int size() const{ return root.size();\
    \ }\r\n  int num_size() const{ return root[0].cnt; }\r\n  private:\r\n  vector<Node>\
    \ root;\r\n  int find(T val, T xor_val = 0) const{\r\n    const T nval = val ^\
    \ lazy ^ xor_val;\r\n    int idx = 0;\r\n    for(int i = MAX_DIGIT-1; i >= 0;\
    \ i--){\r\n      const int f = nval >> i & 1;\r\n      if(root[idx].ch[f] == -1)\
    \ return -1;\r\n      idx = root[idx].ch[f];\r\n    }\r\n    return idx;\r\n \
    \ }\r\n};\r\n"
  code: "#include <bits/stdc++.h>\r\nusing namespace std;\r\n\r\ntemplate <class T,\
    \ size_t MAX_DIGIT>\r\nstruct BinaryTrie {\r\n  struct Node {\r\n    int cnt =\
    \ 0;\r\n    int ch[2] = { -1, -1 };\r\n  };\r\n  T lazy = 0;\r\n  BinaryTrie()\
    \ : root(1){}\r\n  void xor_all(T x){ lazy ^= x; }\r\n  void reserve(int s){ root.reserve(s);\
    \ }\r\n  void insert(T val, T xor_val = 0){ add(val, 1, xor_val); }\r\n  void\
    \ erase(T val, T xor_val = 0){ add(val, -1, xor_val); }\r\n  void add(T val, int\
    \ num, T xor_val = 0){\r\n    const T nval = val ^ lazy ^ xor_val;\r\n    int\
    \ idx = 0;\r\n    root[idx].cnt += num;\r\n    for(int i = MAX_DIGIT-1; i >= 0;\
    \ i--){\r\n      const int f = nval >> i & 1;\r\n      if(root[idx].ch[f] == -1){\r\
    \n        root[idx].ch[f] = (int)root.size();\r\n        root.emplace_back(Node());\r\
    \n      }\r\n      idx = root[idx].ch[f];\r\n      root[idx].cnt += num;\r\n \
    \   }\r\n  }\r\n  void clear(){\r\n    root = { 0 };\r\n    lazy = 0;\r\n  }\r\
    \n  T min(T xor_val = 0) const{ return kth_elem(0, xor_val); }\r\n  T max(T xor_val\
    \ = 0) const{ return kth_elem(num_size()-1, xor_val); }\r\n  T kth_elem(int k,\
    \ T xor_val = 0) const{\r\n    xor_val ^= lazy;\r\n    int idx = 0;\r\n    T res\
    \ = 0;\r\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int f = xor_val\
    \ >> i & 1;\r\n      const int l = root[idx].ch[f];\r\n      const int r = root[idx].ch[!f];\r\
    \n      if(l == -1 || root[l].cnt <= k){\r\n        if(l != -1) k -= root[l].cnt;\r\
    \n        idx = r;\r\n        res |= T(1) << i;\r\n      }else idx = l;\r\n  \
    \  }\r\n    return res;\r\n  }\r\n  T lower_bound(T val, T xor_val = 0) const{\r\
    \n    return kth_elem(order(val, xor_val));\r\n  }\r\n  T upper_bound(T val, T\
    \ xor_val = 0) const{\r\n    return kth_elem(order(val+1, xor_val));\r\n  }\r\n\
    \  int order(T val, T xor_val = 0) const{\r\n    xor_val ^= lazy;\r\n    int idx\
    \ = 0, ord = 0;\r\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int\
    \ f = xor_val >> i & 1;\r\n      const int l = root[idx].ch[f];\r\n      const\
    \ int r = root[idx].ch[!f];\r\n      if(val >> i & 1){\r\n        if(l != -1)\
    \ ord += root[l].cnt;\r\n        idx = r;\r\n      }else idx = l;\r\n      if(idx\
    \ == -1) break;\r\n    }\r\n    return ord;\r\n  }\r\n  int count(T val) const{\r\
    \n    const int t = find(val);\r\n    return t == -1 ? 0 : root[t].cnt;\r\n  }\r\
    \n  int size() const{ return root.size(); }\r\n  int num_size() const{ return\
    \ root[0].cnt; }\r\n  private:\r\n  vector<Node> root;\r\n  int find(T val, T\
    \ xor_val = 0) const{\r\n    const T nval = val ^ lazy ^ xor_val;\r\n    int idx\
    \ = 0;\r\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int f = nval\
    \ >> i & 1;\r\n      if(root[idx].ch[f] == -1) return -1;\r\n      idx = root[idx].ch[f];\r\
    \n    }\r\n    return idx;\r\n  }\r\n};\r\n\r\n\r\n\r\n//----- binary trie (sum)\
    \ -----\r\ntemplate <class T, size_t MAX_DIGIT>\r\nstruct BinaryTrie {\r\n  struct\
    \ Node {\r\n    int cnt = 0;\r\n    T sum = 0;\r\n    int ch[2] = { -1, -1 };\r\
    \n  };\r\n  T lazy = 0;\r\n  BinaryTrie() : root(1){}\r\n  void xor_all(T x){\
    \ lazy ^= x; }\r\n  void reserve(int s){ root.reserve(s); }\r\n  void insert(T\
    \ val, T xor_val = 0){ add(val, 1, xor_val); }\r\n  void erase(T val, T xor_val\
    \ = 0){ add(val, -1, xor_val); }\r\n  void add(T val, int num, T xor_val = 0){\r\
    \n    const T nval = val ^ lazy ^ xor_val;\r\n    int idx = 0;\r\n    root[idx].cnt\
    \ += num;\r\n    root[idx].sum += val * num;\r\n    for(int i = MAX_DIGIT-1; i\
    \ >= 0; i--){\r\n      const int f = nval >> i & 1;\r\n      if(root[idx].ch[f]\
    \ == -1){\r\n        root[idx].ch[f] = (int)root.size();\r\n        root.emplace_back(Node());\r\
    \n      }\r\n      idx = root[idx].ch[f];\r\n      root[idx].cnt += num;\r\n \
    \     root[idx].sum += val * num;\r\n    }\r\n  }\r\n  void clear(){\r\n    root\
    \ = { 0 };\r\n    lazy = 0;\r\n  }\r\n  pair<T, T> kth_elem(int k, T xor_val =\
    \ 0) const{\r\n    xor_val ^= lazy;\r\n    int idx = 0;\r\n    T res = 0, tot\
    \ = 0;\r\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int f = xor_val\
    \ >> i & 1;\r\n      const int l = root[idx].ch[f];\r\n      const int r = root[idx].ch[!f];\r\
    \n      if(l == -1 || root[l].cnt <= k){\r\n        if(l != -1){\r\n         \
    \ k -= root[l].cnt;\r\n          tot += root[l].sum;\r\n        }\r\n        idx\
    \ = r;\r\n        res |= T(1) << i;\r\n      }else idx = l;\r\n    }\r\n    tot\
    \ += res * (k + 1);\r\n    return { res, tot };\r\n  }\r\n  int order(T val, T\
    \ xor_val = 0) const{\r\n    xor_val ^= lazy;\r\n    int idx = 0, ord = 0;\r\n\
    \    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\n      const int f = xor_val >>\
    \ i & 1;\r\n      const int l = root[idx].ch[f];\r\n      const int r = root[idx].ch[!f];\r\
    \n      if(val >> i & 1){\r\n        if(l != -1) ord += root[l].cnt;\r\n     \
    \   idx = r;\r\n      }else idx = l;\r\n      if(idx == -1) break;\r\n    }\r\n\
    \    return ord;\r\n  }\r\n  int count(T val) const{\r\n    const int t = find(val);\r\
    \n    return t == -1 ? 0 : root[t].cnt;\r\n  }\r\n  int size() const{ return root.size();\
    \ }\r\n  int num_size() const{ return root[0].cnt; }\r\n  private:\r\n  vector<Node>\
    \ root;\r\n  int find(T val, T xor_val = 0) const{\r\n    const T nval = val ^\
    \ lazy ^ xor_val;\r\n    int idx = 0;\r\n    for(int i = MAX_DIGIT-1; i >= 0;\
    \ i--){\r\n      const int f = nval >> i & 1;\r\n      if(root[idx].ch[f] == -1)\
    \ return -1;\r\n      idx = root[idx].ch[f];\r\n    }\r\n    return idx;\r\n \
    \ }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binarytrie.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binarytrie.hpp
layout: document
redirect_from:
- /library/data-structure/binarytrie.hpp
- /library/data-structure/binarytrie.hpp.html
title: data-structure/binarytrie.hpp
---
