---
title: Longest Common Ancestor(最小共通祖先)
documentation_of: //graph/lca.hpp
---

## 説明

- Constructor
```cpp
lca(const graph &G, int root = 0)
```

- uとvの最小共通祖先を求める
```cpp
int lca::query(int u, int v)
```

- u,v間の距離を求める
```cpp
int lca::dist(int u, int v)
```

- u-vのパスでuからの距離がdの頂点を求める
```cpp
int lca::jump(int u, int v, int d)
```
