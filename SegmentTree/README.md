# SegmentTree

## segtree
- 一点更新、区間取得
```cpp
SegmentTree<class T,T(*op)(const T&,const T&),T(*e)()>(int _n)
```

## update - range min
- 一点更新、区間min/max
- opには`std::min,std::max`が入る
```cpp
segmentTree<T, const T&(*op)(const T&,const T&)>(int x)
```
- 例
```cpp
segmentTree<int, std::min> seg_min(n);
segmentTree<int, std::max> seg_max(n);
```
- verified: https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_A/review/6077862/US_cube/C++11

## add - range sum
- BIT(Binary Indexed Tree)
- 一点加算、区間和
```cpp
bit<T>(int x)
```
- verified: https://judge.yosupo.jp/submission/67889


# Lazy SegmentTree

## lazysegtree
```cpp
LazySegmentTree<class T, T(*op)(const T&,const T&), T(*e)(), class F,
          T(*mapping)(const F&,const T&), F(*composition)(const F&,const F&), F(*id)()>(int _n)
```

## range update - range min
- 区間更新、区間min/max
```cpp
segmentTree<T, const T&(*op)(const T&,const T&)>(int x)
```
- verified: https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_F/review/6077870/US_cube/C++11

## range add - range sum
- 区間加算、区間和
```cpp
segmentTree<T>(int x)
```
- verified: https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/6077880/US_cube/C++11

## range update - range sum
- 区間更新、区間和
```cpp
segmentTree<T>(int x)
```
- verified: https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_I/review/6077887/US_cube/C++11

## range add - range min
- Starry Sky Tree
- 区間加算、区間min/max
```cpp
segmentTree<T, const T&(*op)(const T&,const T&)>(int x, T sum_unity = T())
```
- verified: https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_H/review/6077890/US_cube/C++11

## liner segtree
```cpp
LazySegmentTree<Data,op,e,Lazy,mapping,composition,id>(int _n);
```
- クエリ sum[i=l, r-1] a[i] を求める
```cpp
Data query(int l, int r);
```
- 更新 (l <= i < r) の区間で a[i] <- a[i] + s + p*(i - l)
```cpp
void update(int l, int r, const Lazy &x);
```


## 2D segtree
- 2D Segment Tree
- 一点更新、長方形の区間でsum/min/max
- idは初期値
```cpp
SegmentTree2D<T, T(*op)(const T&,const T&), T id>(int _h, int _w)
```
- 例
```cpp
int op(const int &a, const int &b){
  return a + b;
}
SegmentTree2D<int, op, 0> seg2d(h, w);
```
- verified: https://atcoder.jp/contests/abc228/submissions/27566771
