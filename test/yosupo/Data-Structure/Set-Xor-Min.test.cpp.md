---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binarytrie.hpp
    title: data-structure/binarytrie.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo/Data-Structure/Set-Xor-Min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\r\n\r\n#line 1 \"template/template.hpp\"\
    \n#include <iostream>\r\n#include <cmath>\r\n#include <string>\r\n#include <vector>\r\
    \n#include <algorithm>\r\n#include <utility>\r\n#include <tuple>\r\n#include <cstdint>\r\
    \n#include <cstdio>\r\n#include <map>\r\n#include <queue>\r\n#include <set>\r\n\
    #include <stack>\r\n#include <deque>\r\n#include <unordered_map>\r\n#include <unordered_set>\r\
    \n#include <bitset>\r\n#include <cctype>\r\n#include <climits>\r\n#include <functional>\r\
    \n#include <cassert>\r\n#include <numeric>\r\n#define rep(i, n) for(int i = 0;\
    \ i < (n); i++)\r\n#define per(i, n) for(int i = (n) - 1; i >= 0; i--)\r\nusing\
    \ ll = long long;\r\n#define vi vector<int>\r\n#define vvi vector<vi>\r\n#define\
    \ vl vector<ll>\r\n#define pii pair<int, int>\r\n#define pll pair<ll, ll>\r\n\
    #define all(a) (a).begin(), (a).end()\r\n#define rall(a) (a).rbegin(), (a).rend()\r\
    \nconstexpr int mod = 1000000007;\r\nusing namespace std;\r\ntemplate<class T,\
    \ class U>\r\nbool chmax(T &a, const U &b){ return a < b ? (a = b, 1) : 0; }\r\
    \ntemplate<class T, class U>\r\nbool chmin(T &a, const U &b){ return a > b ? (a\
    \ = b, 1) : 0; }\n#line 4 \"test/yosupo/Data-Structure/Set-Xor-Min.test.cpp\"\n\
    \r\n#line 1 \"data-structure/binarytrie.hpp\"\ntemplate <class T, size_t MAX_DIGIT>\r\
    \nstruct BinaryTrie {\r\n  struct Node {\r\n    int cnt = 0;\r\n    int ch[2]\
    \ = { -1, -1 };\r\n  };\r\n  T lazy = 0;\r\n  BinaryTrie() : root(1){}\r\n  void\
    \ xor_all(T x){ lazy ^= x; }\r\n  void reserve(int s){ root.reserve(s); }\r\n\
    \  void insert(T val, T xor_val = 0){ add(val, 1, xor_val); }\r\n  void erase(T\
    \ val, T xor_val = 0){ add(val, -1, xor_val); }\r\n  void add(T val, int num,\
    \ T xor_val = 0){\r\n    const T nval = val ^ lazy ^ xor_val;\r\n    int idx =\
    \ 0;\r\n    root[idx].cnt += num;\r\n    for(int i = MAX_DIGIT-1; i >= 0; i--){\r\
    \n      const int f = nval >> i & 1;\r\n      if(root[idx].ch[f] == -1){\r\n \
    \       root[idx].ch[f] = (int)root.size();\r\n        root.emplace_back(Node());\r\
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
    \n    }\r\n    return idx;\r\n  }\r\n};\n#line 6 \"test/yosupo/Data-Structure/Set-Xor-Min.test.cpp\"\
    \n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n\
    \  int q;\r\n  cin >> q;\r\n  BinaryTrie<int, 30> bt;\r\n  bt.reserve(q);\r\n\
    \  rep(_, q){\r\n    int t,x;\r\n    cin >> t >> x;\r\n    if(t == 0){\r\n   \
    \   if(!bt.count(x)) bt.insert(x);\r\n    }else if(t == 1){\r\n      if(bt.count(x))\
    \ bt.erase(x);\r\n    }else{\r\n      cout << bt.min(x) << \"\\n\";\r\n    }\r\
    \n  }\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\r\n\r\n#include\
    \ \"../../../template/template.hpp\"\r\n\r\n#include \"../../../data-structure/binarytrie.hpp\"\
    \r\n\r\nint main(){\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  int q;\r\n  cin >> q;\r\n  BinaryTrie<int, 30> bt;\r\n  bt.reserve(q);\r\n\
    \  rep(_, q){\r\n    int t,x;\r\n    cin >> t >> x;\r\n    if(t == 0){\r\n   \
    \   if(!bt.count(x)) bt.insert(x);\r\n    }else if(t == 1){\r\n      if(bt.count(x))\
    \ bt.erase(x);\r\n    }else{\r\n      cout << bt.min(x) << \"\\n\";\r\n    }\r\
    \n  }\r\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/binarytrie.hpp
  isVerificationFile: true
  path: test/yosupo/Data-Structure/Set-Xor-Min.test.cpp
  requiredBy: []
  timestamp: '2023-03-31 19:15:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/Data-Structure/Set-Xor-Min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/Data-Structure/Set-Xor-Min.test.cpp
- /verify/test/yosupo/Data-Structure/Set-Xor-Min.test.cpp.html
title: test/yosupo/Data-Structure/Set-Xor-Min.test.cpp
---
