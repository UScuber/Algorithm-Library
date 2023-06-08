---
title: Bellman Ford法
documentation_of: //graph/bellman-ford.hpp
---

## 説明

- ベルマンフォード法
- 負のコストを含めた最短経路を求める
- O(NM)

- Constructor
```cpp
BellmanFord<T, const T&(*op)(const T&, const T&)>(const Graph<T> &r);
```

- 頂点sを始点として最短経路を求める
```cpp
void solve(int s)
```

- i までの最短距離を`変数名[i]`で取得
- 負閉路の場合はinfが出力される
```cpp
const T &operator[](const int i)
```

- 負閉路判定
```cpp
bool is_cycle(const int i)
```