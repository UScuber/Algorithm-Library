# data-structure

## slide-min
- スライド最小値
- $min(a_i, a_{i+1}, \cdots, a_{\min(N-1,i+k)}) $を求める($0 \leq i \leq N - 1$)
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
