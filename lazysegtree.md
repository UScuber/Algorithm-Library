# Lazy Segment Tree

# 1. Range Updated Query(RUQ)

## コンストラクタ
```cpp
rangeUpdateQuery(int x)
```
- x 以上の 2^n の配列を作る

## update
```cpp
void update(int a, int b, T x)
```
- [a, b) の区間の値を x に更新する
- 計算量は O(log n)

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
T query(int a, int b)
```
- [a, b) の中での最小値を求める
- 計算量は O(log n)



# 2. Lazy BIT

## コンストラクタ
```cpp
lazySegmentTree(int x)
```
- x 以上の 2^n の配列を作る

## add
```cpp
void add(int a, int b, T x)
```
- [a, b) の区間の値に x を加える
- 計算量は O(log n)

## set
```cpp
void set(int i, T x)
```
- 初めに i 番目の値に x を加える

## build
```cpp
void build()
```
- setで入力した値からまとめて構築する
- 計算量は O(n)

## sum
```cpp
T sum(int a, int b)
```
- [a, b) の区間の総和を求める
- 計算量は O(log n)
