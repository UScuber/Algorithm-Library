# Union Find

## コンストラクタ
```cpp
UnionFind(int n)
```
- n 頂点のグラフを張る

## unite
```cpp
bool unite(int x, int y)
```
- x と y に辺を張る
- 元から x と y がつながっていれば `false`つながっていなければ`true`を返す

## same
```cpp
bool same(int x, int y)
```
- x と y が同じ連結であるかどうかを判定する
- 連結であれば`true`、そうでなければ`false`を返す

## size
```cpp
int size(int x)
```
- x の属する連結成分のサイズを返す

## root
```cpp
int root(int x)
```
- x の連結成分の根の頂点の場所を返す



# 重み付きUnion Find

## コンストラクタ
```cpp
UnionFindW(int n = 1, int sum_unity = 0)
```
- n 頂点のグラフを張る
- すべての頂点の重みの初期値を設定する(default は 0)

## merge
```cpp
bool merge(int x, int y, int w)
```
- x と y に重さが w の辺を張る
- すでに x と y が連結であれば`false`そうでなければ`true`を返す

## same
```cpp
bool same(int x, int y)
```
- x と y が同じ連結であるかどうかを判定する
- 連結であれば`true`、そうでなければ`false`を返す

## root
```cpp
int root(int x)
```
- x の連結成分の根の頂点の場所を返す

## diff
```cpp
int diff(int x, int y)
```
- x と y の重みの差を返す

## weight
```cpp
int weight(int x)
```
- 頂点 x の重みの値を返す
