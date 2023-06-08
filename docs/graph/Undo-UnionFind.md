---
title: Undo-UnionFind(Undo付きUnionFind)
documentation_of: //graph/Undo-UnionFind.hpp
---

## 説明

Undoが可能なUnionFindです

- Constructor
```cpp
UndoUnionFind(int n)
```

- 頂点x,yを接続
```cpp
bool unite(int x, int y)
```

- 同じ集合か判定
```cpp
bool same(int x, int y)
```

- その頂点を含む集合の大きさを求める
```cpp
int size(int x)
```

- 一つ前の状態に戻す
```cpp
void undo()
```

- 最初の状態に戻す
```cpp
void rollback()
```

- 現在の状態を保存する
- これ以降、rollbackした後はこの状態に戻る
```cpp
void snapshot()
```
