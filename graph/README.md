# graph

## UnionFind
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
- verified: https://judge.yosupo.jp/submission/57767

## Weighted UnionFind
- 重み付きUnionFind
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
- verified: https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_1_B/review/5295028/US_cube/C++17

## Undo UnionFind
- Undoが可能なUnionFind
```cpp
UndoUnionFind(int n)
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
- 一つ前の状態に戻す
```cpp
void undo()
```
- 最初の状態に戻す
```cpp
void rollback()
```
- 現在の状態を保存する
- これ以降、rollbackした後はこの状態に戻る
```cpp
void snapshot()
```

## lca
- Longest Common Ancestor(最小共通祖先)
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
- verified: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C

## cycle detect
- 閉路を検出し、そのうち１つの閉路の頂点集合を返す
- 閉路が存在しなければ、空の配列を返す
```cpp
vector<edge<int>> detect(const graph &root)
```
- verified: https://judge.yosupo.jp/submission/65892

## bellman ford
- ベルマンフォード法
- 負のコストを含めた最短経路を求める
- O(NM)
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
- verified: https://atcoder.jp/contests/abc061/submissions/33358312

## kruskal
- 最小全域木を求める
- 戻り値は全域木の最小コスト
```cpp
ll kruskal(vector<Edge<T>> &es, int V)
```

## scc
- Strongly Connected Component(強連結成分分解)
- group[i]: 分解後のグループiに入る頂点集合
- comp[i]: iが入っている成分の番号
```cpp
scc(const graph &g);
```
- verified: https://atcoder.jp/contests/typical90/submissions/33353968

## diameter
- グラフの直径を求める
```cpp
vector<int> diameter(const Graph<T> &g)
```
- verified: https://judge.yosupo.jp/submission/72240

## center
- 木の中心を求める
```cpp
vector<int> find_centor(const graph &g)
```
- verified: https://atcoder.jp/contests/abc221/submissions/33353795
