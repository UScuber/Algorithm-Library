# data-structure

## slide-min
- スライド最小値
- $min(a_i, a_{i+1}, \cdots, a_{\min(N-1,i+k)}) $を求める($0 \leq i \leq N - 1$)
```cpp
vector<T> slide_min(const vector<T> &a, int k);
```

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
