#include "fps.hpp"
// #include "fps-arbitrary-mod.hpp"

template <class mint>
mint LinearRecurrence(ll k, FPS<mint> Q, FPS<mint> P){
  Q.shrink();
  mint ret = 0;
  if(P.size() >= Q.size()){
    const auto R = P / Q;
    P -= R * Q;
    P.shrink();
    if(k < (int)R.size()) ret += R[k];
  }
  if((int)P.size() == 0) return ret;
  FPS<mint>::set_fft();
  if(FPS<mint>::ntt_ptr == nullptr){
    P.resize((int)Q.size() - 1);
    while(k){
      auto Q2 = Q;
      for(int i = 1; i < (int)Q2.size(); i += 2) Q2[i] = -Q2[i];
      const auto S = P * Q2;
      const auto T = Q * Q2;
      if(k & 1){
        for(int i = 1; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
        for(int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
      }else{
        for(int i = 0; i < (int)S.size(); i += 2) P[i >> 1] = S[i];
        for(int i = 0; i < (int)T.size(); i += 2) Q[i >> 1] = T[i];
      }
      k >>= 1;
    }
    return ret + P[0];
  }else{
    int N = 1;
    while(N < (int)Q.size()) N <<= 1;
    P.resize(2 * N);
    Q.resize(2 * N);
    P.ntt();
    Q.ntt();
    vector<mint> S(2 * N), T(2 * N);
    vector<int> btr(N);
    for(int i = 0, logn = __builtin_ctz(N); i < (1 << logn); i++){
      btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (logn - 1));
    }
    const mint dw = mint(FPS<mint>::ntt_pr()).inv().pow((mint::get_mod() - 1) / (2 * N));
    while(k){
      mint inv2 = mint(2).inv();
      // even degree of Q(x)Q(-x)
      T.resize(N);
      for(int i = 0; i < N; i++) T[i] = Q[(i << 1) | 0] * Q[(i << 1) | 1];
      S.resize(N);
      if(k & 1){
        // odd degree of P(x)Q(-x)
        for(auto &i : btr) {
          S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] -
                  P[(i << 1) | 1] * Q[(i << 1) | 0]) * inv2;
          inv2 *= dw;
        }
      }else{
        // even degree of P(x)Q(-x)
        for(int i = 0; i < N; i++){
          S[i] = (P[(i << 1) | 0] * Q[(i << 1) | 1] +
                  P[(i << 1) | 1] * Q[(i << 1) | 0]) * inv2;
        }
      }
      swap(P, S);
      swap(Q, T);
      k >>= 1;
      if(k < N) break;
      P.ntt_doubling();
      Q.ntt_doubling();
    }
    P.intt();
    Q.intt();
    return ret + (P * (Q.inv()))[k];
  }
}
template <class mint>
mint kitamasa(ll N, FPS<mint> Q, FPS<mint> a){
  assert(!Q.empty() && Q[0] != 0);
  if(N < (int)a.size()) return a[N];
  assert((int)a.size() >= int(Q.size()) - 1);
  auto P = a.pre((int)Q.size() - 1) * Q;
  P.resize(Q.size() - 1);
  return LinearRecurrence<mint>(N, Q, P);
}