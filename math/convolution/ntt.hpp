#include <bits/stdc++.h>
using namespace std;

template <class mint>
struct NTT {
  static constexpr uint32_t get_pr(){
    const uint32_t _mod = mint::get_mod();
    using u64 = uint64_t;
    u64 ds[32] = {};
    int idx = 0;
    u64 m = _mod - 1;
    for(u64 i = 2; i * i <= m; i++){
      if(m % i == 0){
        ds[idx++] = i;
        while(m % i == 0) m /= i;
      }
    }
    if(m != 1) ds[idx++] = m;
    uint32_t _pr = 2;
    while(true){
      int flg = 1;
      for(int i = 0; i < idx; i++){
        u64 a = _pr, b = (_mod - 1) / ds[i], r = 1;
        while(b){
          if(b & 1) r = r * a % _mod;
          a = a * a % _mod;
          b >>= 1;
        }
        if(r == 1){
          flg = 0;
          break;
        }
      }
      if(flg == 1) break;
      _pr++;
    }
    return _pr;
  };
  static constexpr uint32_t mod = mint::get_mod();
  static constexpr uint32_t pr = get_pr();
  static constexpr int level = __builtin_ctzll(mod - 1);
  mint dw[level], dy[level];
  void setwy(const int k){
    mint w[level], y[level];
    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));
    y[k - 1] = w[k - 1].inv();
    for(int i = k - 2; i > 0; i--)
      w[i] = w[i + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];
    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] = y[2];
    for(int i = 3; i < k; i++){
      dw[i] = dw[i - 1] * y[i - 2] * w[i];
      dy[i] = dy[i - 1] * w[i - 2] * y[i];
    }
  }
  NTT(){ setwy(level); }
  void fft4(vector<mint> &a, const int k){
    if((int)a.size() <= 1) return;
    if(k == 1){
      mint a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    if(k & 1){
      int v = 1 << (k - 1);
      for(int j = 0; j < v; j++) {
        mint ajv = a[j + v];
        a[j + v] = a[j] - ajv;
        a[j] += ajv;
      }
    }
    int u = 1 << (2 + (k & 1));
    int v = 1 << (k - 2 - (k & 1));
    const mint one = mint(1);
    mint imag = dw[1];
    while(v) {
      // jh = 0
      {
        int j0 = 0;
        int j1 = v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        for(; j0 < v; j0++, j1++, j2++, j3++){
          const mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          const mint t0p2 = t0 + t2, t1p3 = t1 + t3;
          const mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
        }
      }
      // jh >= 1
      mint ww = one, xx = one * dw[2], wx = one;
      for(int jh = 4; jh < u;){
        ww = xx * xx, wx = ww * xx;
        int j0 = jh * v;
        int je = j0 + v;
        int j2 = je + v;
        for(; j0 < je; j0++, j2++){
          const mint t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2] * ww, t3 = a[j2 + v] * wx;
          const mint t0p2 = t0 + t2, t1p3 = t1 + t3;
          const mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
          a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;
        }
        xx *= dw[__builtin_ctzll((jh += 4))];
      }
      u <<= 2;
      v >>= 2;
    }
  }
  void ifft4(vector<mint> &a, const int k){
    if((int)a.size() <= 1) return;
    if(k == 1){
      mint a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    int u = 1 << (k - 2);
    int v = 1;
    const mint one = mint(1);
    mint imag = dy[1];
    while(u){
      // jh = 0
      {
        int j0 = 0;
        int j1 = v;
        int j2 = v + v;
        int j3 = j2 + v;
        for(; j0 < v; j0++, j1++, j2++, j3++){
          const mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          const mint t0p1 = t0 + t1, t2p3 = t2 + t3;
          const mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;
          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;
          a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;
        }
      }
      // jh >= 1
      mint ww = one, xx = one * dy[2], yy = one;
      u <<= 2;
      for(int jh = 4; jh < u;){
        ww = xx * xx, yy = xx * imag;
        int j0 = jh * v;
        int je = j0 + v;
        int j2 = je + v;
        for(; j0 < je; j0++, j2++){
          const mint t0 = a[j0], t1 = a[j0 + v], t2 = a[j2], t3 = a[j2 + v];
          const mint t0p1 = t0 + t1, t2p3 = t2 + t3;
          const mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;
          a[j0 + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;
        }
        xx *= dy[__builtin_ctzll(jh += 4)];
      }
      u >>= 4;
      v <<= 2;
    }
    if(k & 1){
      u = 1 << (k - 1);
      for(int j = 0; j < u; j++){
        mint ajv = a[j] - a[j + u];
        a[j] += a[j + u];
        a[j + u] = ajv;
      }
    }
  }
  void ntt(vector<mint> &a){
    if((int)a.size() <= 1) return;
    fft4(a, __builtin_ctz(a.size()));
  }
  void intt(vector<mint> &a){
    if((int)a.size() <= 1) return;
    ifft4(a, __builtin_ctz(a.size()));
    const mint iv = mint(a.size()).inv();
    for(auto &x : a) x *= iv;
  }
  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b){
    const int l = a.size() + b.size() - 1;
    if(min<int>(a.size(), b.size()) <= 40){
      vector<mint> s(l);
      for(int i = 0; i < (int)a.size(); i++)
        for(int j = 0; j < (int)b.size(); j++) s[i + j] += a[i] * b[j];
      return s;
    }
    int k = 2, M = 4;
    while(M < l) M <<= 1, k++;
    setwy(k);
    vector<mint> s(M), t(M);
    for(int i = 0; i < (int)a.size(); i++) s[i] = a[i];
    for(int i = 0; i < (int)b.size(); i++) t[i] = b[i];
    fft4(s, k);
    fft4(t, k);
    for(int i = 0; i < M; i++) s[i] *= t[i];
    ifft4(s, k);
    s.resize(l);
    const mint invm = mint(M).inv();
    for(int i = 0; i < l; i++) s[i] *= invm;
    return s;
  }
  void ntt_doubling(vector<mint> &a){
    const int M = (int)a.size();
    auto b = a;
    intt(b);
    mint r = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));
    for(int i = 0; i < M; i++) b[i] *= r, r *= zeta;
    ntt(b);
    copy(begin(b), end(b), back_inserter(a));
  }
};