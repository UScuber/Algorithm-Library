#include <bits/stdc++.h>
using namespace std;

struct BitVector {
  using uint = unsigned int;
  static constexpr int w = 32;
  #define rem(k) ((k) & (w - 1))
  int len, blocks;
  vector<uint> bit, sum;
  BitVector(){}
  BitVector(const int len) : len(len), blocks((len+w-1)/w){
    bit.assign(blocks, 0);
    sum.assign(blocks, 0);
  }
  inline void set(const int k, const int b = 1) noexcept{
    if(b) bit[k / w] |= 1U << rem(k);
    else bit[k / w] &= ~(1U << rem(k));
  }
  void build(){
    sum[0] = 0;
    for(int i = 1; i < blocks; i++){
      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
    }
  }
  int operator[](const int k) const{
    return bit[k / w] >> rem(k) & 1;
  }
  inline int rank(const int k) const noexcept{
    return sum[k / w] + __builtin_popcount(bit[k / w] & ((1U << rem(k)) - 1));
  }
  inline int rank(const int val, const int k) const noexcept{
    return val ? rank(k) : k - rank(k);
  }
  #undef rem
};