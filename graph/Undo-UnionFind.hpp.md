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
  bundledCode: "#line 1 \"graph/Undo-UnionFind.hpp\"\nstruct UndoUnionFind {\r\n \
    \ private:\r\n  int n;\r\n  stack<pair<int,int>> hist;\r\n  public:\r\n  vector<int>\
    \ d;\r\n  UndoUnionFind(int n): n(n), d(n, -1){}\r\n  int root(int x){\r\n   \
    \ assert(0 <= x && x < n);\r\n    if(d[x] < 0) return x;\r\n    return d[x] =\
    \ root(d[x]);\r\n  }\r\n  bool unite(int x, int y){\r\n    x = root(x);\r\n  \
    \  y = root(y);\r\n    hist.emplace(x, d[x]);\r\n    hist.emplace(y, d[y]);\r\n\
    \    if(x == y) return false;\r\n    if(d[x] > d[y]) swap(x, y);\r\n    d[x] +=\
    \ d[y];\r\n    d[y] = x;\r\n    return true;\r\n  }\r\n  bool same(int x, int\
    \ y){\r\n    return root(x) == root(y);\r\n  }\r\n  int size(int x){\r\n    return\
    \ -d[root(x)];\r\n  }\r\n  void undo(){\r\n    assert(!hist.empty());\r\n    d[hist.top().first]\
    \ = hist.top().second;\r\n    hist.pop();\r\n    d[hist.top().first] = hist.top().second;\r\
    \n    hist.pop();\r\n  }\r\n  void snapshot(){\r\n    while(!hist.empty()) hist.pop();\r\
    \n  }\r\n  void rollback(){\r\n    while(!hist.empty()) undo();\r\n  }\r\n};\n"
  code: "struct UndoUnionFind {\r\n  private:\r\n  int n;\r\n  stack<pair<int,int>>\
    \ hist;\r\n  public:\r\n  vector<int> d;\r\n  UndoUnionFind(int n): n(n), d(n,\
    \ -1){}\r\n  int root(int x){\r\n    assert(0 <= x && x < n);\r\n    if(d[x] <\
    \ 0) return x;\r\n    return d[x] = root(d[x]);\r\n  }\r\n  bool unite(int x,\
    \ int y){\r\n    x = root(x);\r\n    y = root(y);\r\n    hist.emplace(x, d[x]);\r\
    \n    hist.emplace(y, d[y]);\r\n    if(x == y) return false;\r\n    if(d[x] >\
    \ d[y]) swap(x, y);\r\n    d[x] += d[y];\r\n    d[y] = x;\r\n    return true;\r\
    \n  }\r\n  bool same(int x, int y){\r\n    return root(x) == root(y);\r\n  }\r\
    \n  int size(int x){\r\n    return -d[root(x)];\r\n  }\r\n  void undo(){\r\n \
    \   assert(!hist.empty());\r\n    d[hist.top().first] = hist.top().second;\r\n\
    \    hist.pop();\r\n    d[hist.top().first] = hist.top().second;\r\n    hist.pop();\r\
    \n  }\r\n  void snapshot(){\r\n    while(!hist.empty()) hist.pop();\r\n  }\r\n\
    \  void rollback(){\r\n    while(!hist.empty()) undo();\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/Undo-UnionFind.hpp
  requiredBy: []
  timestamp: '2023-03-13 02:01:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/Undo-UnionFind.hpp
layout: document
title: "Undo-UnionFind(Undo\u4ED8\u304DUnionFind)"
---

## 説明

Undoが可能なUnionFindです

- Constructor
```cpp
UndoUnionFind(int n)
```

- 頂点x,yを接続
```cpp
bool unite(int x, int y)
```

- 同じ集合か判定
```cpp
bool same(int x, int y)
```

- その頂点を含む集合の大きさを求める
```cpp
int size(int x)
```

- 一つ前の状態に戻す
```cpp
void undo()
```

- 最初の状態に戻す
```cpp
void rollback()
```

- 現在の状態を保存する
- これ以降、rollbackした後はこの状態に戻る
```cpp
void snapshot()
```
