# graph

## UnionFind
```cpp
UnionFind(int n)
```
- 頂点$x,y$を接続
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

## Weighted UnionFind
- 重み付きUnionFind
```cpp
UnionFindW(int n = 1, int sum_unity = 0)
```
- 頂点$x,y$を$w$で接続
```cpp
bool merge(int x, int y, int w)
```
- 同じ集合か判定
```cpp
bool same(int x, int y)
```
- $x$と$y$の重みの差を求める
```cpp
int diff(int x, int y)
```

## lca
- Longest Common Ancestor(最小共通祖先)
```cpp
lca(const graph &G, int root = 0)
```
- $x$と$y$の最小共通祖先を求める
```cpp
int lca::query(int u, int v)
```

## cycle detect
- 閉路を検出し、そのうち１つの閉路の頂点集合を返す
- 閉路が存在しなければ、空の配列を返す
```cpp
vector<edge<int>> detect(const graph &root)
```

## bellman ford
- ベルマンフォード法
- 負のコストを含めた最短経路を求める
- $O(NM)$
```cpp
bellman_ford<T, const T&(*op)(const T&, const T&)>(int n);
bellman_ford<T, const T&(*op)(const T&, const T&)>(const Graph<T> &r);
```
- 頂点$s$を始点として最短経路を求める
```cpp
void solve(int s)
```
- $i$までの最短距離を`変数名[i]`で取得
- 負閉路の場合はinfが出力される
```cpp
const T &operator[](const int &i)
```
- 負閉路判定
```cpp
bool is_cycle(const int &i)
```

## kruskal
- 最小全域木を求める
- 戻り値は全域木の最小コスト
```cpp
ll kruskal(vector<edge<T>> &es, int V)
```

## scc
- Strongly Connected Component(強連結成分分解)
- group[i]: 分解後のグループiに入る頂点集合
- comp[i]: iが入っている成分の番号
```cpp
scc(const int &n);
scc(const graph &g);
```
- 構築
```cpp
void build()
```

## center
- 木の中心を求める
```cpp
vector<int> find_centor(const graph &g)
```
