#include "fps-template.hpp"
using ll = long long;

namespace ArbitraryNTT {
using u128 = __uint128_t;
constexpr int m0 = 167772161;
constexpr int m1 = 469762049;
constexpr int m2 = 754974721;
using mint0 = Mint<m0>;
using mint1 = Mint<m1>;
using mint2 = Mint<m2>;
constexpr int r01 = mint1(m0).inv().x;
constexpr int r02 = mint2(m0).inv().x;
constexpr int r12 = mint2(m1).inv().x;
constexpr int r02r12 = ll(r02) * r12 % m2;
constexpr ll w1 = m0;
constexpr ll w2 = ll(m0) * m1;

template <class T, class submint>
vector<submint> mul(const vector<T> &a, const vector<T> &b){
  static NTT<submint> ntt;
  vector<submint> s(a.size()), t(b.size());
  for(int i = 0; i < (int)a.size(); i++) s[i] = ll(a[i] % submint::get_mod());
  for(int i = 0; i < (int)b.size(); i++) t[i] = ll(b[i] % submint::get_mod());
  return ntt.multiply(s, t);
}
template <class T>
vector<int> multiply(const vector<T> &s, const vector<T> &t, const int mod){
  const auto d0 = mul<T, mint0>(s, t);
  const auto d1 = mul<T, mint1>(s, t);
  const auto d2 = mul<T, mint2>(s, t);
  const int n = d0.size();
  vector<int> ret(n);
  const int W1 = w1 % mod;
  const int W2 = w2 % mod;
  for(int i = 0; i < n; i++){
    const int n1 = d1[i].x, n2 = d2[i].x, a = d0[i].x;
    const int b = ll(n1 + m1 - a) * r01 % m1;
    const int c = (ll(n2 + m2 - a) * r02r12 + ll(m2 - b) * r12) % m2;
    ret[i] = (ll(a) + ll(b) * W1 + ll(c) * W2) % mod;
  }
  return ret;
}

template <class mint>
vector<mint> multiply(const vector<mint> &a, const vector<mint> &b){
  if(a.size() == 0 && b.size() == 0) return {};
  if(min<int>(a.size(), b.size()) < 128){
    vector<mint> ret(a.size() + b.size() - 1);
    for(int i = 0; i < (int)a.size(); i++)
      for(int j = 0; j < (int)b.size(); j++) ret[i + j] += a[i] * b[j];
    return ret;
  }
  vector<int> s(a.size()), t(b.size());
  for(int i = 0; i < (int)a.size(); i++) s[i] = a[i].x;
  for(int i = 0; i < (int)b.size(); i++) t[i] = b[i].x;
  vector<int> u = multiply<int>(s, t, mint::get_mod());
  vector<mint> ret(u.size());
  for(int i = 0; i < (int)u.size(); i++) ret[i] = mint(u[i]);
  return ret;
}

template <class T>
vector<u128> multiply_u128(const vector<T> &s, const vector<T> &t){
  if(s.size() == 0 && t.size() == 0) return {};
  if(min<int>(s.size(), t.size()) < 128){
    vector<u128> ret(s.size() + t.size() - 1);
    for(int i = 0; i < (int)s.size(); i++)
      for(int j = 0; j < (int)t.size(); j++) ret[i + j] += ll(s[i]) * t[j];
    return ret;
  }
  const auto d0 = mul<T, mint0>(s, t);
  const auto d1 = mul<T, mint1>(s, t);
  const auto d2 = mul<T, mint2>(s, t);
  const int n = d0.size();
  vector<u128> ret(n);
  for(int i = 0; i < n; i++){
    ll n1 = d1[i].x, n2 = d2[i].x;
    ll a = d0[i].x;
    u128 b = (n1 + m1 - a) * r01 % m1;
    u128 c = ((n2 + m2 - a) * r02r12 + (m2 - b) * r12) % m2;
    ret[i] = a + b * w1 + c * w2;
  }
  return ret;
}
} // namespace ArbitraryNTT
template <class mint> void FPS<mint>::set_fft(){ ntt_ptr = nullptr; }
template <class mint> void FPS<mint>::ntt(){ exit(1); }
template <class mint> void FPS<mint>::intt(){ exit(1); }
template <class mint> void FPS<mint>::ntt_doubling(){ exit(1); }
template <class mint> int FPS<mint>::ntt_pr(){ exit(1); }
template <class mint>
FPS<mint> &FPS<mint>::operator*=(const FPS<mint> &r){
  if(this->empty() || r.empty()){
    this->clear();
    return *this;
  }
  const auto ret = ArbitraryNTT::multiply(*this, r);
  return *this = FPS<mint>(ret.begin(), ret.end());
}
template <class mint>
FPS<mint> FPS<mint>::inv(int deg) const{
  assert((*this)[0] != mint(0));
  if(deg == -1) deg = (*this).size();
  FPS<mint> ret({mint(1) / (*this)[0]});
  for(int i = 1; i < deg; i <<= 1)
    ret = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);
  return ret.pre(deg);
}
template <class mint>
FPS<mint> FPS<mint>::exp(int deg) const{
  assert((*this).size() == 0 || (*this)[0] == mint(0));
  if(deg == -1) deg = (int)this->size();
  FPS<mint> ret({mint(1)});
  for(int i = 1; i < deg; i <<= 1){
    ret = (ret * (pre(i << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);
  }
  return ret.pre(deg);
}