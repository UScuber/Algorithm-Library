---
title: BinaryTrie
documentation_of: //data-structure/binarytrie.hpp
---

## 説明

挿入する値はすべて非負整数である必要がある

- `BinaryTrie<T,D>()`: Constructor。$2^{\mathrm{D}}$未満の値を入れられる

- `insert(val, xor_val)`: valを1つ追加。$O(\mathrm{D})$

- `erase(val, xor_val)`: valを1つ削除。$O(\mathrm{D})$

- `add(val, num, xor_val)`: valをnum個追加。$O(\mathrm{D})$

- `min(xor_val)`: 最小値を取得。$O(\mathrm{D})$

- `max(xor_val)`: 最大値を取得。$O(\mathrm{D})$

- `kth_elem(k, xor_val)`: $k$番目の値を取得。$O(\mathrm{D})$

- `lower_bound(val, xor_val)`: val以上の値の最小値を取得。$O(\mathrm{D})$

- `upper_bound(val, xor_val)`: valを超える値の最小値を取得。$O(\mathrm{D})$

- `order(val, xor_val)`: valが小さい方から何番目かを取得。$O(\mathrm{D})$

- `count(val)`: valの個数を取得。$O(\mathrm{D})$

- `size()`: 値の種類数を取得。$O(1)$

- `num_size()`: 入れられた値の個数を取得。$O(1)$

- `reserve(s)`: $s$個の領域を確保しておく。$O(s)$

- `xor_all(x)`: xorの値を更新。$O(1)$

- `clear()`: 要素をすべて削除する
