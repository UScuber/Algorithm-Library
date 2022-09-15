#include "ntt.hpp"
#include "../mint.hpp"

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
vector<ll> multiply_ll(const vector<ll> &s, const vector<ll> &t){
  const auto d0 = mul<ll, mint0>(s, t);
  const auto d1 = mul<ll, mint1>(s, t);
  const auto d2 = mul<ll, mint2>(s, t);
  const int n = d0.size();
  vector<ll> ret(n);
  const ll W1 = w1;
  const ll W2 = w2;
  for(int i = 0; i < n; i++){
    const ll n1 = d1[i].x, n2 = d2[i].x, a = d0[i].x;
    const ll b = ll(n1 + m1 - a) * r01 % m1;
    const ll c = (ll(n2 + m2 - a) * r02r12 + ll(m2 - b) * r12) % m2;
    ret[i] = (ll(a) + ll(b) * W1 + ll(c) * W2);
  }
  return ret;
}
} // namespace ArbitraryNTT
template <class mint>
vector<mint> convolution(const vector<mint> &a, const vector<mint> &b){
  return ArbitraryNTT::multiply(a, b);
}
vector<ll> convolution_ll(const vector<ll> &a, const vector<ll> &b){
  return ArbitraryNTT::multiply_ll(a, b);
}