#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0560"

#include "../../../template/template.hpp"

#include "../../../data-structure/CumulativeSum2D.hpp"

const string t = "JOI";
int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,m,K;
  cin >> n >> m >> K;
  vector<CumulativeSum2D<int>> cnt(3, CumulativeSum2D<int>(n, m));
  rep(i, n){
    string s; cin >> s;
    rep(j, m){
      rep(k, 3) if(s[j] == t[k]){
        cnt[k].set(i, j, 1);
        break;
      }
    }
  }
  rep(i, 3) cnt[i].build();
  rep(_, K){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--; b--;
    rep(i, 3) cout << cnt[i].query(a, b, c, d) << " \n"[i == 2];
  }
}