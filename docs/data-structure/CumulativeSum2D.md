---
title: 2次元累積和
documentation_of: //data-structure/CumulativeSum2D.hpp
---

## 説明

- `CumulativeSum2D<T>(h, w)`: Constructor。$O(HW)$
- `CumulativeSum2D<T>(const vector<vector<T>> &v)`: Constructor。$O(HW)$

- `set(i, j, x)`: 値の加算。$O(1)$

- `build()`: 累積和の構築。$O(HW)$

- `query(ly, lx, ry, rx)`: 長方形内($[ly,ry),[lx,rx)$)の和を取得。$O(1)$
