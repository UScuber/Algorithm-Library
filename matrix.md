# matrix

## コンストラクタ
```cpp
matrix(int n = 0, T m = numeric_limits<T>::max())
```
- n*n の行列を作成する
- 計算では m で割った余りを使用する

## 演算
```cpp
matix a,b;
a + b;
a - b;
a * b;

a += b;
a -= b;
a *= b;
```

## pow
```cpp
mint(x).mod(ll t)
```
- x^t を求める
- 計算量は O(n^3 log t)

## debug
```cpp
void debug()
```
- 行列の値を出力する
- `cerr`を使っているので書き残したまま提出しても問題ない

## 要素の取得
```cpp
matrix a[i][j]

matrix a[i][j] = T x;
```
- 値の取得や更新を直接行える
