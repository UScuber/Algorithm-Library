#include <chrono>
#include <random>
using ull = unsigned long long;

template <class T, int max_len>
struct Hash {
  static constexpr ull m = (1ULL << 61) - 1;
  const ull base;
  vector<ull> h;
  const T data;
  Hash(const T &d, const ull base, const ull power[]) : data(d), base(base), power(power){}
  inline ull query(int l, int r) const{
    assert(max_len >= r - l);
    assert(0 <= l && l <= r && r <= h.size());
    return add(h[r], m - mul(h[l], power[r - l]));
  }
  void combine(const Hash<T, max_len> &a){
    const int len = h.size();
    h.insert(h.end(), a.h.begin()+1, a.h.end());
    const int tot_len = h.size();
    ull val = h[len - 1];
    for(int i = len; i < tot_len; i++){
      val = mul(val, base);
      h[i] = add(val, h[i]);
    }
  }
  inline int size() const noexcept{ return (int)h.size()-1; }
  private:
  const ull *power;
  inline ull add(ull a, const ull b) const noexcept{
    if((a += b) >= m) a -= m;
    return a;
  }
  inline ull mul(const ull a, const ull b) const noexcept{
    const __uint128_t c = (__uint128_t)a * b;
    return add(c >> 61, c & m);
  }
  inline ull fma(const ull a, const ull b, const ull c) const noexcept{
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
  Hash<string, max_len> gen(const string &s) const{
    const int len = s.size();
    Hash<string, max_len> hash(s, base, power);
    hash.h.resize(len + 1);
    for(int i = 0; i < len; i++){
      hash.h[i+1] = fma(hash.h[i], base, s[i]);
    }
    return hash;
  }
  template <class T>
  Hash<vector<T>, max_len> gen(const vector<T> &s) const{
    const int len = s.size();
    Hash<vector<T>, max_len> hash(s, base, power);
    hash.h.resize(len + 1);
    for(int i = 0; i < len; i++){
      hash.h[i+1] = fma(hash.h[i], base, s[i]);
    }
    return hash;
  }
  ull combine(const ull h1, const ull h2, const ull h2_len) const{
    assert(max_len >= h2_len);
    return fma(h1, power[h2_len], h2);
  }
  template <class T>
  ull combine(const Hash<T,max_len> &a, const int l1, const int r1,
              const Hash<T,max_len> &b, const int l2, const int r2) const{
    assert(max_len >= r2 - l2);
    return fma(a.query(l1, r1), power[r2-l2], b.query(l2, r2));
  }
  template <class T>
  int lcp(const Hash<T,max_len> &a, const int l1, const int r1,
          const Hash<T,max_len> &b, const int l2, const int r2) const{
    assert(0 <= l1 && l1 <= r1 && r1 <= a.size());
    assert(0 <= l2 && l2 <= r2 && r2 <= b.size());
    const int len = min(r1-l1, r2-l2);
    int left = 0, right = len + 1;
    while(left + 1 < right){
      const int mid = (left + right) / 2;
      if(a.query(l1, l1+mid) == b.query(l2, l2+mid)) left = mid;
      else right = mid;
    }
    return left;
  }
  template <class T>
  int strcmp(const Hash<T,max_len> &a, const int l1, const int r1
            ,const Hash<T,max_len> &b, const int l2, const int r2) const{
    assert(0 <= l1 && l1 <= r1 && r1 <= a.size());
    assert(0 <= l2 && l2 <= r2 && r2 <= b.size());
    const int pos = lcp(a, l1, r1, b, l2, r2);
    if(pos < min(r1-l1, r2-l2)) return a.data[l1+pos] < b.data[l2+pos] ? 1 : -1;
    if(r1-l1 == r2-l2) return 0;
    return r1-l1 < r2-l2 ? 1 : -1;
  }
  private:
  ull power[max_len + 1];
  ull rnd() const{
    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<ull> rand(2, m-1);
    return rand(mt);
  }
  inline ull add(ull a, const ull b) const noexcept{
    if((a += b) >= m) a -= m;
    return a;
  }
  inline ull mul(const ull a, const ull b) const noexcept{
    const __uint128_t c = (__uint128_t)a * b;
    return add(c >> 61, c & m);
  }
  inline ull fma(const ull a, const ull b, const ull c) const noexcept{
    const __uint128_t d = (__uint128_t)a * b + c;
    return add(d >> 61, d & m);
  }
};