#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <chrono>
#include <random>
using ull = unsigned long long;
template <int max_len>
struct Hash {
  static constexpr ull m = (1ULL << 61) - 1;
  const ull base;
  vector<ull> h;
  Hash(const ull base, const ull power[]) : base(base), power(power){}
  inline ull query(int l, int r) const{
    assert(max_len >= r - l);
    assert(0 <= l && l <= r && r < h.size());
    return add(h[r], m - mul(h[l], power[r - l]));
  }
  void combine(const Hash<max_len> &a){
    const int len = h.size();
    h.insert(h.end(), a.h.begin()+1, a.h.end());
    const int tot_len = h.size();
    ull val = h[len - 1];
    for(int i = len; i < tot_len; i++){
      val = mul(val, base);
      h[i] = add(val, h[i]);
    }
  }
  inline int size() const{ return h.size(); }
  private:
  const ull *power;
  inline ull add(ull a, const ull b) const{
    if((a += b) >= m) a -= m;
    return a;
  }
  inline ull mul(const ull a, const ull b) const{
    const __uint128_t c = (__uint128_t)a * b;
    return add(c >> 61, c & m);
  }
  inline ull fma(const ull a, const ull b, const ull c) const{
    const __uint128_t d = (__uint128_t)a * b + c;
    return add(d >> 61, d & m);
  }
};
template <int max_len>
struct RollingHash {
  static constexpr ull m = (1ULL << 61) - 1;
  const ull base;
  RollingHash() : base(rnd()){
    power[0] = 1;
    for(int i = 0; i < max_len; i++){
      power[i + 1] = mul(power[i], base);
    }
  }
  Hash<max_len> gen(const string &s) const{
    const int len = s.size();
    Hash<max_len> hash(base, power);
    hash.h.resize(len + 1);
    for(int i = 0; i < len; i++){
      hash.h[i+1] = fma(hash.h[i], base, s[i]);
    }
    return hash;
  }
  template <class T>
  Hash<max_len> gen(const vector<T> &s) const{
    const int len = s.size();
    Hash<max_len> hash(base, power);
    hash.h.resize(len + 1);
    for(int i = 0; i < len; i++){
      hash.h[i+1] = fma(hash.h[i], base, s[i]);
    }
    return hash;
  }
  ull combine(ull h1, ull h2, ull h2_len) const{
    assert(max_len >= h2_len);
    return fma(h1, power[h2_len], h2);
  }
  ull combine(const Hash<max_len> &a, int l1, int r1, const Hash<max_len> &b, int l2, int r2) const{
    assert(max_len >= r2 - l2);
    return fma(a.query(l1, r1), power[r2-l2], b.query(l2, r2));
  }
  int lcp(const Hash<max_len> &a, int l1, int r1, const Hash<max_len> &b, int l2, int r2) const{
    assert(0 <= l1 && l1 <= r1 && r1 < a.size());
    assert(0 <= l2 && l2 <= r2 && r2 < b.size());
    const int len = min(r1 - l1, r2 - l2);
    int left = 0, right = len + 1;
    while(left + 1 < right){
      const int mid = (left + right) / 2;
      if(a.query(l1, l1+mid) == b.query(l2, l2+mid)) left = mid;
      else right = mid;
    }
    return left;
  }
  private:
  ull power[max_len + 1];
  ull rnd() const{
    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<ull> rand(2, m-1);
    return rand(mt);
  }
  inline ull add(ull a, const ull b) const{
    if((a += b) >= m) a -= m;
    return a;
  }
  inline ull mul(const ull a, const ull b) const{
    const __uint128_t c = (__uint128_t)a * b;
    return add(c >> 61, c & m);
  }
  inline ull fma(const ull a, const ull b, const ull c) const{
    const __uint128_t d = (__uint128_t)a * b + c;
    return add(d >> 61, d & m);
  }
};