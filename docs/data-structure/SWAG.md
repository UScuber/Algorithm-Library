---
title: SWAG(Sliding Window Aggregation)
documentation_of: //data-structure/SWAG.hpp
---

## 説明

- `SWAG<T,op,e>(int n)`: Constructor。$O(N)$
- `SWAG<T,op,e>(vector<vector<T>> &v)`: Constructor。$O(N)$

- `fold(i, j)`: 区間$[i,j)$のクエリに答える。前回のクエリを$(i',j')$とすると、$i'\leq i$かつ$j'\leq j$である必要がある。$O(1)$

- `pop()`: 先頭の値を削除する。$O(1)$
