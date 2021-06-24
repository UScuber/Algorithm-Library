# maxflow

## コンストラクタ
```cpp
maxflow(int n)
maxflow(const vector<vector<edge>> &g)
```
- $n$頂点のグラフを生成する
- グラフgを使ってグラフを生成する

## add_edge)
```cpp
void add_edge(int from, int to, T cap)
```
- fromからtoへの重みがcapの有向辺を張る

## max_flow
```cpp
T max_flow(int s, int t)
```
- sからtへの最大流、最小カットを求める
- 計算量はフローの流量を$F$とすると$O(FE)$
