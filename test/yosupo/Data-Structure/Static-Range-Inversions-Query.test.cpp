#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../../../template/template.hpp"

#include "../../../others/mo.hpp"
#include "../../../SegmentTree/BinaryIndexedTree.hpp"
#include "../../../others/fastIO.hpp"

BIT<int> seg;
vi a;

void Mo::add_left(int p){
  value += seg.sum(0, a[p]);
  seg.add(a[p], 1);
}
void Mo::add_right(int p){
  value += seg.sum(a[p] + 1, n);
  seg.add(a[p], 1);
}
void Mo::del_left(int p){
  value -= seg.sum(0, a[p]);
  seg.add(a[p], -1);
}
void Mo::del_right(int p){
  value -= seg.sum(a[p] + 1, n);
  seg.add(a[p], -1);
}

int main(){
  int n,q;
  cin >> n >> q;
  a.resize(n);
  seg = BIT<int>(n);
  rep(i, n) cin >> a[i];
  vi b = a;
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  rep(i, n) a[i] = lower_bound(all(b), a[i]) - b.begin();
  Mo mo(n, q);
  rep(i, q){
    int l,r;
    cin >> l >> r;
    mo.insert(l, r);
  }
  mo.build();
  rep(i, q) cout << mo.res[i] << '\n';
}