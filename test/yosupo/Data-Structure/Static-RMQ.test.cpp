#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../../template/template.hpp"

#include "../../../data-structure/SparseTable.hpp"

int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,q;
  cin >> n >> q;
  SparseTable<int, min> st(n);
  rep(i, n) cin >> st[i];
  st.build();
  rep(i, q){
    int l,r;
    cin >> l >> r;
    cout << st.query(l, r) << "\n";
  }
}