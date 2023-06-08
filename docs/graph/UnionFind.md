---
title: UnionFind
documentation_of: //graph/UnionFind.hpp
---

## 説明

- Constructor
```cpp
UnionFind(int n)
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
