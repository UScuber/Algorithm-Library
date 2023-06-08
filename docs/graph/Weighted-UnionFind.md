---
title: Weighted-UnionFind(重み付きUnionFind)
documentation_of: //graph/Weighted-UnionFind.hpp
---

## 説明

- Constructor
```cpp
UnionFindW(int n = 1, int sum_unity = 0)
```

- 頂点x,yを重みwで接続
```cpp
bool merge(int x, int y, int w)
```

- 同じ集合か判定
```cpp
bool same(int x, int y)
```

- xとyの重みの差を求める
```cpp
int diff(int x, int y)
```
