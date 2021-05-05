# Segment Tree

# 1. Range Minimum Query(RMQ)

## コンストラクタ
```cpp
segmentTree(int x)
```
- x 以上の 2^n の配列を作る

## update
```cpp
void update(int k, T a)
```
- k 番目の値を a に更新する

## set
```cpp
void set(int i, T x)
```
- 初めに i 番目の値を x とする

## build
```cpp
void build()
```
- setで入力した値からまとめて構築する
- 計算量は O(n)

## query
```cpp
T query(int l, int r)
```
- [l, r) の中での最小値を求める
- 計算量は O(log n)

## min_right
```cpp
int min_right(int l, int r, T x)
```
- [l, r) の中で x 以下の値がある一番右の位置を求める
- 存在しない場合は l-1 を返す
- 計算量は O(log n)

## min_left
```cpp
int min_left(int l, int r, T x)
```
- [l, r) の中で x 以下の値がある一番左の位置を求める
- 存在しない場合は r を返す
- 計算量は O(log n)

## debug
```cpp
void debug(int l = 0, int r = n)
```
- cerr で [l, r) の区間の値を出力する




# 2. Binary Indexed Tree(BIT)

## コンストラクタ
```cpp
bit(int x)
```
- x 以上の 2^n の配列を作る

## add
```cpp
void add(int i, T x)
```
- i 番目の値に x を加える
- 計算量は O(log n)

## sum
```cpp
T sum(int l, int r, T x)
```
- [l, r) の区間の値の総和を求める
- 計算量は O(log n)

## debug
```cpp
void debug(int l = 0, int r = n)
```
- cerr で [l, r) の区間の値を出力する
