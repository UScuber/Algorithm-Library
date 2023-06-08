---
title: Cycle Detect(サイクル検出)
documentation_of: //graph/cycle-detect.hpp
---

## 説明

- 閉路を検出し、そのうち１つの閉路の頂点集合を返す
- 閉路が存在しなければ、空の配列を返す

- Constructor
```cpp
Cycle (const graph &_g)
```

- 閉路検出
```cpp
vector<Edge<int>> Cycle::detect()
```
