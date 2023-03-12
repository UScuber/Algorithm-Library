#include "ntt.hpp"

template <class mint>
vector<mint> convolution(const vector<mint> &a, const vector<mint> &b){
  static NTT<mint> ntt;
  return ntt.multiply(a, b);
}