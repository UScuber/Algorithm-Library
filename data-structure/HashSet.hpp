#include <chrono>

template <class Key, int logn = 20>
struct HashSet {
  using uint = unsigned int;
  using ull = unsigned long long;
  private:
  static constexpr unsigned int N = 1 << logn;
  Key *keys;
  bitset<N> flag;
  const ull r;
  static constexpr uint shift = 64 - logn;
  constexpr ull rng() const{
    ull m = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
    m ^= m >> 16;
    m ^= m << 32;
    return m;
  }
  public:
  HashSet() : keys(new Key[N]), r(rng()){}
  inline constexpr void set(const Key i) noexcept{
    uint hash = (ull(i) * r) >> shift;
    while(true){
      if(!flag[hash]){
        keys[hash] = i;
        flag[hash] = 1;
        return;
      }
      if(keys[hash] == i) return;
      hash = (hash + 1) & (N - 1);
    }
  }
  inline constexpr bool count(const Key i) const noexcept{
    uint hash = (ull(i) * r) >> shift;
    while(true){
      if(!flag[hash]) return false;
      if(keys[hash] == i) return true;
      hash = (hash + 1) & (N - 1);
    }
  }
};