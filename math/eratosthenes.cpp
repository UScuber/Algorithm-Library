#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct range_factorization {
  private:
  ll L,R,M;
  vector<int> small;  // 小さい篩
  vector<vector<ll>> large;  // 大きい篩
  vector<ll> aux;  // aux[i] := large[i] の素因数の積
  public:
  range_factorization(const ll L, const ll R): L(L), R(R), M(sqrt(R)+1){
    small.resize(M);
    for(int i = 0; i < M; i++) small[i] = i;
    large.resize(R-L);
    aux.assign(R-L, 1);

    for(ll i = 2; i*i < R; i++){
      if(small[i] < i) continue;
      small[i] = i;
      for(ll j = i*i; j < M; j += i){
        if(small[j] == j) small[j] = i;
      }
      for(ll j = max(2*i, L+i-1)/i*i; j < R; j += i){
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
    assert(L <= n && n < R);
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



struct range_eratosthenes {
  private:
  ll L,R,M;
  static constexpr int Max_range = 1000010; //10^6
  bitset<Max_range> small, large;
  public:
  range_eratosthenes(const ll L, const ll R) : L(L), R(R), M(sqrt(R)+1){
    assert(M <= Max_range && R - L <= Max_range);
    for(ll i = 2; i < M; i++){
      if(small[i]) continue;
      for(ll j = i+i; j < M; j += i) small[j] = 1;
      for(ll j = max(2LL, (L+i-1)/i)*i; j < R; j += i)
        large[j - L] = 1;
    }
  }
  bool is_prime(const ll n) const{
    assert(L <= n && n < R);
    return !large[n - L];
  }
};