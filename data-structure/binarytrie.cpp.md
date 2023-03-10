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
  bundledCode: "#line 1 \"data-structure/binarytrie.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\ntemplate <class T, size_t MAX_DIGIT>\nstruct BinaryTrie\
    \ {\n  struct Node {\n    int cnt = 0;\n    int ch[2] = { -1, -1 };\n  };\n  T\
    \ lazy = 0;\n  BinaryTrie() : root(1){}\n  void xor_all(T x){ lazy ^= x; }\n \
    \ void reserve(int s){ root.reserve(s); }\n  void insert(T val, T xor_val = 0){\
    \ add(val, 1, xor_val); }\n  void erase(T val, T xor_val = 0){ add(val, -1, xor_val);\
    \ }\n  void add(T val, int num, T xor_val = 0){\n    const T nval = val ^ lazy\
    \ ^ xor_val;\n    int idx = 0;\n    root[idx].cnt += num;\n    for(int i = MAX_DIGIT-1;\
    \ i >= 0; i--){\n      const int f = nval >> i & 1;\n      if(root[idx].ch[f]\
    \ == -1){\n        root[idx].ch[f] = (int)root.size();\n        root.emplace_back(Node());\n\
    \      }\n      idx = root[idx].ch[f];\n      root[idx].cnt += num;\n    }\n \
    \ }\n  void clear(){\n    root = { 0 };\n    lazy = 0;\n  }\n  T min(T xor_val\
    \ = 0) const{ return kth_elem(0, xor_val); }\n  T max(T xor_val = 0) const{ return\
    \ kth_elem(num_size()-1, xor_val); }\n  T kth_elem(int k, T xor_val = 0) const{\n\
    \    xor_val ^= lazy;\n    int idx = 0;\n    T res = 0;\n    for(int i = MAX_DIGIT-1;\
    \ i >= 0; i--){\n      const int f = xor_val >> i & 1;\n      const int l = root[idx].ch[f];\n\
    \      const int r = root[idx].ch[!f];\n      if(l == -1 || root[l].cnt <= k){\n\
    \        if(l != -1) k -= root[l].cnt;\n        idx = r;\n        res |= T(1)\
    \ << i;\n      }else idx = l;\n    }\n    return res;\n  }\n  T lower_bound(T\
    \ val, T xor_val = 0) const{\n    return kth_elem(order(val, xor_val));\n  }\n\
    \  T upper_bound(T val, T xor_val = 0) const{\n    return kth_elem(order(val+1,\
    \ xor_val));\n  }\n  int order(T val, T xor_val = 0) const{\n    xor_val ^= lazy;\n\
    \    int idx = 0, ord = 0;\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\n     \
    \ const int f = xor_val >> i & 1;\n      const int l = root[idx].ch[f];\n    \
    \  const int r = root[idx].ch[!f];\n      if(val >> i & 1){\n        if(l != -1)\
    \ ord += root[l].cnt;\n        idx = r;\n      }else idx = l;\n      if(idx ==\
    \ -1) break;\n    }\n    return ord;\n  }\n  int count(T val) const{\n    const\
    \ int t = find(val);\n    return t == -1 ? 0 : root[t].cnt;\n  }\n  int size()\
    \ const{ return root.size(); }\n  int num_size() const{ return root[0].cnt; }\n\
    \  private:\n  vector<Node> root;\n  int find(T val, T xor_val = 0) const{\n \
    \   const T nval = val ^ lazy ^ xor_val;\n    int idx = 0;\n    for(int i = MAX_DIGIT-1;\
    \ i >= 0; i--){\n      const int f = nval >> i & 1;\n      if(root[idx].ch[f]\
    \ == -1) return -1;\n      idx = root[idx].ch[f];\n    }\n    return idx;\n  }\n\
    };\n\n\n\n//----- binary trie (sum) -----\ntemplate <class T, size_t MAX_DIGIT>\n\
    struct BinaryTrie {\n  struct Node {\n    int cnt = 0;\n    T sum = 0;\n    int\
    \ ch[2] = { -1, -1 };\n  };\n  T lazy = 0;\n  BinaryTrie() : root(1){}\n  void\
    \ xor_all(T x){ lazy ^= x; }\n  void reserve(int s){ root.reserve(s); }\n  void\
    \ insert(T val, T xor_val = 0){ add(val, 1, xor_val); }\n  void erase(T val, T\
    \ xor_val = 0){ add(val, -1, xor_val); }\n  void add(T val, int num, T xor_val\
    \ = 0){\n    const T nval = val ^ lazy ^ xor_val;\n    int idx = 0;\n    root[idx].cnt\
    \ += num;\n    root[idx].sum += val * num;\n    for(int i = MAX_DIGIT-1; i >=\
    \ 0; i--){\n      const int f = nval >> i & 1;\n      if(root[idx].ch[f] == -1){\n\
    \        root[idx].ch[f] = (int)root.size();\n        root.emplace_back(Node());\n\
    \      }\n      idx = root[idx].ch[f];\n      root[idx].cnt += num;\n      root[idx].sum\
    \ += val * num;\n    }\n  }\n  void clear(){\n    root = { 0 };\n    lazy = 0;\n\
    \  }\n  pair<T, T> kth_elem(int k, T xor_val = 0) const{\n    xor_val ^= lazy;\n\
    \    int idx = 0;\n    T res = 0, tot = 0;\n    for(int i = MAX_DIGIT-1; i >=\
    \ 0; i--){\n      const int f = xor_val >> i & 1;\n      const int l = root[idx].ch[f];\n\
    \      const int r = root[idx].ch[!f];\n      if(l == -1 || root[l].cnt <= k){\n\
    \        if(l != -1){\n          k -= root[l].cnt;\n          tot += root[l].sum;\n\
    \        }\n        idx = r;\n        res |= T(1) << i;\n      }else idx = l;\n\
    \    }\n    tot += res * (k + 1);\n    return { res, tot };\n  }\n  int order(T\
    \ val, T xor_val = 0) const{\n    xor_val ^= lazy;\n    int idx = 0, ord = 0;\n\
    \    for(int i = MAX_DIGIT-1; i >= 0; i--){\n      const int f = xor_val >> i\
    \ & 1;\n      const int l = root[idx].ch[f];\n      const int r = root[idx].ch[!f];\n\
    \      if(val >> i & 1){\n        if(l != -1) ord += root[l].cnt;\n        idx\
    \ = r;\n      }else idx = l;\n      if(idx == -1) break;\n    }\n    return ord;\n\
    \  }\n  int count(T val) const{\n    const int t = find(val);\n    return t ==\
    \ -1 ? 0 : root[t].cnt;\n  }\n  int size() const{ return root.size(); }\n  int\
    \ num_size() const{ return root[0].cnt; }\n  private:\n  vector<Node> root;\n\
    \  int find(T val, T xor_val = 0) const{\n    const T nval = val ^ lazy ^ xor_val;\n\
    \    int idx = 0;\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\n      const int\
    \ f = nval >> i & 1;\n      if(root[idx].ch[f] == -1) return -1;\n      idx =\
    \ root[idx].ch[f];\n    }\n    return idx;\n  }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <class T, size_t\
    \ MAX_DIGIT>\nstruct BinaryTrie {\n  struct Node {\n    int cnt = 0;\n    int\
    \ ch[2] = { -1, -1 };\n  };\n  T lazy = 0;\n  BinaryTrie() : root(1){}\n  void\
    \ xor_all(T x){ lazy ^= x; }\n  void reserve(int s){ root.reserve(s); }\n  void\
    \ insert(T val, T xor_val = 0){ add(val, 1, xor_val); }\n  void erase(T val, T\
    \ xor_val = 0){ add(val, -1, xor_val); }\n  void add(T val, int num, T xor_val\
    \ = 0){\n    const T nval = val ^ lazy ^ xor_val;\n    int idx = 0;\n    root[idx].cnt\
    \ += num;\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\n      const int f = nval\
    \ >> i & 1;\n      if(root[idx].ch[f] == -1){\n        root[idx].ch[f] = (int)root.size();\n\
    \        root.emplace_back(Node());\n      }\n      idx = root[idx].ch[f];\n \
    \     root[idx].cnt += num;\n    }\n  }\n  void clear(){\n    root = { 0 };\n\
    \    lazy = 0;\n  }\n  T min(T xor_val = 0) const{ return kth_elem(0, xor_val);\
    \ }\n  T max(T xor_val = 0) const{ return kth_elem(num_size()-1, xor_val); }\n\
    \  T kth_elem(int k, T xor_val = 0) const{\n    xor_val ^= lazy;\n    int idx\
    \ = 0;\n    T res = 0;\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\n      const\
    \ int f = xor_val >> i & 1;\n      const int l = root[idx].ch[f];\n      const\
    \ int r = root[idx].ch[!f];\n      if(l == -1 || root[l].cnt <= k){\n        if(l\
    \ != -1) k -= root[l].cnt;\n        idx = r;\n        res |= T(1) << i;\n    \
    \  }else idx = l;\n    }\n    return res;\n  }\n  T lower_bound(T val, T xor_val\
    \ = 0) const{\n    return kth_elem(order(val, xor_val));\n  }\n  T upper_bound(T\
    \ val, T xor_val = 0) const{\n    return kth_elem(order(val+1, xor_val));\n  }\n\
    \  int order(T val, T xor_val = 0) const{\n    xor_val ^= lazy;\n    int idx =\
    \ 0, ord = 0;\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\n      const int f =\
    \ xor_val >> i & 1;\n      const int l = root[idx].ch[f];\n      const int r =\
    \ root[idx].ch[!f];\n      if(val >> i & 1){\n        if(l != -1) ord += root[l].cnt;\n\
    \        idx = r;\n      }else idx = l;\n      if(idx == -1) break;\n    }\n \
    \   return ord;\n  }\n  int count(T val) const{\n    const int t = find(val);\n\
    \    return t == -1 ? 0 : root[t].cnt;\n  }\n  int size() const{ return root.size();\
    \ }\n  int num_size() const{ return root[0].cnt; }\n  private:\n  vector<Node>\
    \ root;\n  int find(T val, T xor_val = 0) const{\n    const T nval = val ^ lazy\
    \ ^ xor_val;\n    int idx = 0;\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\n \
    \     const int f = nval >> i & 1;\n      if(root[idx].ch[f] == -1) return -1;\n\
    \      idx = root[idx].ch[f];\n    }\n    return idx;\n  }\n};\n\n\n\n//-----\
    \ binary trie (sum) -----\ntemplate <class T, size_t MAX_DIGIT>\nstruct BinaryTrie\
    \ {\n  struct Node {\n    int cnt = 0;\n    T sum = 0;\n    int ch[2] = { -1,\
    \ -1 };\n  };\n  T lazy = 0;\n  BinaryTrie() : root(1){}\n  void xor_all(T x){\
    \ lazy ^= x; }\n  void reserve(int s){ root.reserve(s); }\n  void insert(T val,\
    \ T xor_val = 0){ add(val, 1, xor_val); }\n  void erase(T val, T xor_val = 0){\
    \ add(val, -1, xor_val); }\n  void add(T val, int num, T xor_val = 0){\n    const\
    \ T nval = val ^ lazy ^ xor_val;\n    int idx = 0;\n    root[idx].cnt += num;\n\
    \    root[idx].sum += val * num;\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\n\
    \      const int f = nval >> i & 1;\n      if(root[idx].ch[f] == -1){\n      \
    \  root[idx].ch[f] = (int)root.size();\n        root.emplace_back(Node());\n \
    \     }\n      idx = root[idx].ch[f];\n      root[idx].cnt += num;\n      root[idx].sum\
    \ += val * num;\n    }\n  }\n  void clear(){\n    root = { 0 };\n    lazy = 0;\n\
    \  }\n  pair<T, T> kth_elem(int k, T xor_val = 0) const{\n    xor_val ^= lazy;\n\
    \    int idx = 0;\n    T res = 0, tot = 0;\n    for(int i = MAX_DIGIT-1; i >=\
    \ 0; i--){\n      const int f = xor_val >> i & 1;\n      const int l = root[idx].ch[f];\n\
    \      const int r = root[idx].ch[!f];\n      if(l == -1 || root[l].cnt <= k){\n\
    \        if(l != -1){\n          k -= root[l].cnt;\n          tot += root[l].sum;\n\
    \        }\n        idx = r;\n        res |= T(1) << i;\n      }else idx = l;\n\
    \    }\n    tot += res * (k + 1);\n    return { res, tot };\n  }\n  int order(T\
    \ val, T xor_val = 0) const{\n    xor_val ^= lazy;\n    int idx = 0, ord = 0;\n\
    \    for(int i = MAX_DIGIT-1; i >= 0; i--){\n      const int f = xor_val >> i\
    \ & 1;\n      const int l = root[idx].ch[f];\n      const int r = root[idx].ch[!f];\n\
    \      if(val >> i & 1){\n        if(l != -1) ord += root[l].cnt;\n        idx\
    \ = r;\n      }else idx = l;\n      if(idx == -1) break;\n    }\n    return ord;\n\
    \  }\n  int count(T val) const{\n    const int t = find(val);\n    return t ==\
    \ -1 ? 0 : root[t].cnt;\n  }\n  int size() const{ return root.size(); }\n  int\
    \ num_size() const{ return root[0].cnt; }\n  private:\n  vector<Node> root;\n\
    \  int find(T val, T xor_val = 0) const{\n    const T nval = val ^ lazy ^ xor_val;\n\
    \    int idx = 0;\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\n      const int\
    \ f = nval >> i & 1;\n      if(root[idx].ch[f] == -1) return -1;\n      idx =\
    \ root[idx].ch[f];\n    }\n    return idx;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binarytrie.cpp
  requiredBy: []
  timestamp: '2022-12-12 10:06:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binarytrie.cpp
layout: document
redirect_from:
- /library/data-structure/binarytrie.cpp
- /library/data-structure/binarytrie.cpp.html
title: data-structure/binarytrie.cpp
---
