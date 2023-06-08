---
title: SCC(Stronly Connected Components)(強連結成分分解)
documentation_of: //graph/scc.hpp
---

## 説明

- dag[i]: 分解後の頂点と辺からなるグラフ(DAG)
- group[i]: 分解後のグループiに入る頂点集合
- comp[i]: iが入っている成分のグループの番号

- Constructor
```cpp
scc(const graph &g);
```
