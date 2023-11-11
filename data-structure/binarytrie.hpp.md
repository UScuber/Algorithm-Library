---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/Data-Structure/Set-Xor-Min.test.cpp
    title: test/yosupo/Data-Structure/Set-Xor-Min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binarytrie.hpp\"\ntemplate <class T, size_t\
    \ MAX_DIGIT>\r\nstruct BinaryTrie {\r\n  struct Node {\r\n    int cnt = 0;\r\n\
    \    int ch[2] = { -1, -1 };\r\n  };\r\n  T lazy = 0;\r\n  BinaryTrie() : root(1){}\r\
    \n  void xor_all(T x){ lazy ^= x; }\r\n  void reserve(int s){ root.reserve(s);\
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
    \n    }\r\n    return idx;\r\n  }\r\n};\n"
  code: "template <class T, size_t MAX_DIGIT>\r\nstruct BinaryTrie {\r\n  struct Node\
    \ {\r\n    int cnt = 0;\r\n    int ch[2] = { -1, -1 };\r\n  };\r\n  T lazy = 0;\r\
    \n  BinaryTrie() : root(1){}\r\n  void xor_all(T x){ lazy ^= x; }\r\n  void reserve(int\
    \ s){ root.reserve(s); }\r\n  void insert(T val, T xor_val = 0){ add(val, 1, xor_val);\
    \ }\r\n  void erase(T val, T xor_val = 0){ add(val, -1, xor_val); }\r\n  void\
    \ add(T val, int num, T xor_val = 0){\r\n    const T nval = val ^ lazy ^ xor_val;\r\
    \n    int idx = 0;\r\n    root[idx].cnt += num;\r\n    for(int i = MAX_DIGIT-1;\
    \ i >= 0; i--){\r\n      const int f = nval >> i & 1;\r\n      if(root[idx].ch[f]\
    \ == -1){\r\n        root[idx].ch[f] = (int)root.size();\r\n        root.emplace_back(Node());\r\
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
    \n    }\r\n    return idx;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binarytrie.hpp
  requiredBy: []
  timestamp: '2023-03-13 21:53:46+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/Data-Structure/Set-Xor-Min.test.cpp
documentation_of: data-structure/binarytrie.hpp
layout: document
title: BinaryTrie
---

## 説明

挿入する値はすべて非負整数である必要がある

- `BinaryTrie<T,D>()`: Constructor。$2^{\mathrm{D}}$未満の値を入れられる

- `insert(val, xor_val)`: valを1つ追加。$O(\mathrm{D})$

- `erase(val, xor_val)`: valを1つ削除。$O(\mathrm{D})$

- `add(val, num, xor_val)`: valをnum個追加。$O(\mathrm{D})$

- `min(xor_val)`: 最小値を取得。$O(\mathrm{D})$

- `max(xor_val)`: 最大値を取得。$O(\mathrm{D})$

- `kth_elem(k, xor_val)`: $k$番目の値を取得。$O(\mathrm{D})$

- `lower_bound(val, xor_val)`: val以上の値の最小値を取得。$O(\mathrm{D})$

- `upper_bound(val, xor_val)`: valを超える値の最小値を取得。$O(\mathrm{D})$

- `order(val, xor_val)`: valが小さい方から何番目かを取得。$O(\mathrm{D})$

- `count(val)`: valの個数を取得。$O(\mathrm{D})$

- `size()`: 値の種類数を取得。$O(1)$

- `num_size()`: 入れられた値の個数を取得。$O(1)$

- `reserve(s)`: $s$個の領域を確保しておく。$O(s)$

- `xor_all(x)`: xorの値を更新。$O(1)$

- `clear()`: 要素をすべて削除する
