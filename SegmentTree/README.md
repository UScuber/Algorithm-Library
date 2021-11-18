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
