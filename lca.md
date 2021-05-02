# LCA

## コンストラクタ
```cpp
lca(const vector<vector<int>> &G, int root = 0)
```
- G: グラフ、root: グラフの根

## query
```cpp
int query(int u, int v)
```
- 共通の祖先を求める
- 計算量は O(log n)