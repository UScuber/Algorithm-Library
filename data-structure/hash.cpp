#include <bits/stdc++.h>
#include <chrono>
using namespace std;

template <class Key, class Val, int logn = 20, Val initval = Val()>
struct HashMap {
  using uint = unsigned int;
  using ull = unsigned long long;
  private:
  static constexpr unsigned int N = 1 << logn;
  Key *keys;
  Val *vals;
  bitset<N> flag;
  static constexpr uint shift = 64 - logn;
  ull rng() const{
    ull m = chrono::duration_cast<chrono::nanoseconds>(
            chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    m ^= m >> 16;
    m ^= m << 32;
    return m;
  }
  public:
  HashMap() : keys(new Key[N]), vals(new Val[N]){}
  Val &operator[](const Key &i){
    const static ull r = rng();
    uint hash = (ull(i) * r) >> shift;
    while(true){
      if(!flag[hash]){
        keys[hash] = i;
        flag[hash] = 1;
        return vals[hash] = initval;
      }
      if(keys[hash] == i) return vals[hash];
      hash = (hash + 1) & (N - 1);
    }
  }
};