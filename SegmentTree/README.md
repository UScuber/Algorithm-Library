# SegmentTree

## update-rmin
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

## add-rsum
- BIT(Binary Indexed Tree)
- 一点加算、区間和
```cpp
bit<T>(int x)
```

## rupdate-rmin
- 区間更新、区間min/max
```cpp
segmentTree<T, const T&(*op)(const T&,const T&)>(int x)
```

## radd-rsum
- 区間加算、区間和
```cpp
segmentTree<T>(int x)
```

## rupdate-rsum
- 区間更新、区間和
```cpp
segmentTree<T>(int x)
```
## radd-rmin
- Starry Sky Tree
- 区間加算、区間min/max
```cpp
segmentTree<T, const T&(*op)(const T&,const T&)>(int x, T sum_unity = T())
```

## 2d-segtree
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
