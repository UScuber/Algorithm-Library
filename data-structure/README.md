# data-structure

## slide-min
- スライド最小値
- min(a_i, a_{i+1}, ... , a_{min(N-1,i+k)}) を求める(0 <= i < N)
```cpp
vector<T> slide_min(const vector<T> &a, int k);
```
- verified: https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_3_D/review/6071329/US_cube/C++11

## SWAG
- Sliding Window Aggregation
```cpp
SWAG<class T, T(*op)(const T&,const T&), const T(*e)()>(int n = 0);
SWAG<class T, T(*op)(const T&,const T&), const T(*e)()>(const deque<T> &v);
```
- 例
```cpp
int op(const int &a, const int &b){ return max(a, b); }
const int e(){ return 0; }
SWAG<int, op, e> swag(n);
```
- クエリ([i,j)の区間で計算)
- l,rの値は前回の値以上でないといけない
```cpp
T SWAG::fold(int i, int j);
```
- 値の追加
```cpp
void SWAG::push_back(T x);
```
- 値の消去(前から)
```cpp
void SWAG::pop();
```
- verified: https://judge.yosupo.jp/submission/67274

## SparseTable
- 区間min/max(更新なし)
```cpp
SparseTable<class T, const T&(*op)(const T&,const T&)>(int n);
SparseTable<class T, const T&(*op)(const T&,const T&)>(const vector<T> &a);
```
- 構築(値の入力が終わったら実行する) O(NlogN)
```cpp
void build();
```
- 区間min/maxを求める O(1)
```cpp
int query(int l, int r);
```
- verified: https://judge.yosupo.jp/submission/68186

## Cumulative Sum 2D
- 二次元累積和
```cpp
CumulativeSum2D<class T>(int h, int w);
CumulativeSum2D<class T>(const vector<vector<T>> &v);
```
- 構築
```cpp
void build();
```
- 長方形の区間の和を求める
```cpp
T query(int ly, int lx, int ry, int rx);
```
- verified: https://atcoder.jp/contests/abc005/submissions/27791299

## Bit Vector
- 完備辞書
- 初期化
```cpp
BitVector(int len);
```
- 構築
```cpp
void build();
```
- k番目の値をbにする
```cpp
void set(const int &k, const int &b = 1);
```
- [0,k]にある val の数を求める O(1)
```cpp
int rank(const int &val, const int &k);
```

## Wavelet Matrix / Compressed Wavelet Matrix
- ウェーブレット行列
- 構築
```cpp
WaveletMatrix<class T, int maxlog>(vector<T> v);
CompWaveletMatrix<class T, maxlog>(const vector<T> v);
```
- 計算量：O(maxlog)
- v[k]の値を求める
```cpp
T access(int k);
```
- [0,r)の区間でxが現れる数を求める
```cpp
int rank(const T &x, int r);
```
- [l,r)の中でk番目に小さい/大きい値を求める
```cpp
T kth_smallest(int l, int r, int k);
T kth_largest(int l, int r, int k);
```
- [l,r)のiについて lower <= v[i] < upper を満たすiの数を求める
```cpp
int range_freq(int l, int r, const T &lower, const T &upper);
```
- [l,r)のiについて v[i] < upper を満たす最大のv[i]を求める
```cpp
T prev_value(int l, int r, const T &upper);
```
- [l,r)のiについて lower <= v[i] を満たす最小のv[i]を求める
```cpp
T next_value(int l, int r, const T &lower);
```
- verified: https://judge.yosupo.jp/submission/76069
- verified(Compressed): https://judge.yosupo.jp/submission/76070

## Vector
- std::vectorを高速化した配列
- begin(),end()の戻り値がポインタで、それ以外の操作はstd::vectorとほとんど同じ

- 10^8個の値のpush_back(emplace_back)
  - Vector: 540[ms], std::vector: 945[ms]
- 10^8回 pop_back
  - Vector: 256[ms], std::vector: 344[ms]
- 10^5回 assign (サイズは0以上10^4以下の乱数)
  - Vector: 467[ms], std::vector: 488[ms]
- 10^7の配列のソート
  - Vector: 1325[ms], std::vector: 2764[ms]
- 10^5回 insert (1点追加)
  - Vector: 232[ms], std::vector: 237[ms]
- 10^5回 erase (1点消去)
  - Vector: 327[ms], std::vector: 337[ms]
