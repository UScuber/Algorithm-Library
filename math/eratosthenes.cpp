#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct range_factorization {
  ll L, R, M;
  vector<int> small;  // 小さい篩
  vector<vector<ll>> large;  // 大きい篩
  vector<ll> aux;  // aux[i] := large[i] の素因数の積

  range_factorization(ll L, ll R): L(L), R(R), M(sqrt(R)+1){
    small.resize(M);
    for(int i = 0; i < M; i++) small[i] = i;
    large.resize(R-L);
    aux.assign(R-L, 1);

    for (ll i = 2; i*i < R; ++i){
      if(small[i] < i) continue;
      small[i] = i;
      for(ll j = i*i; j < M; j += i){
        if(small[j] == j) small[j] = i;
      }
      for(ll j = max(i, L+i-1)/i*i; j < R; j += i){
        ll k = j;
        //素因数の積がsqrt(R)を超えるまで素因数を探す
        while(k % i == 0){
          if(aux[j-L] * aux[j-L] > R) break;
          large[j-L].push_back(i);
          aux[j-L] *= i;
          k /= i;
        }
      }
    }
  }
  vector<ll> factor(ll n){
    vector<ll> res = large[n - L];
    n /= aux[n-L];
    if(n >= M){
      res.push_back(n);
      return res;
    }
    while(n > 1){
      res.push_back(small[n]);
      n /= small[n];
    }
    return res;
  }
};