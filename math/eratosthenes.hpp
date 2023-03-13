struct range_eratosthenes {
  private:
  ll L,R,M;
  static constexpr int Max_range = 100000010; //10^8
  bitset<Max_range> small, large;
  public:
  range_eratosthenes(const ll L, const ll R) : L(L), R(R), M(sqrt(R)+1){
    assert(M <= Max_range && R - L <= Max_range);
    for(ll i = 2; i < M; i++){
      if(small[i]) continue;
      for(ll j = i+i; j < M; j += i) small[j] = 1;
      for(ll j = max(2LL, (L+i-1)/i)*i; j < R; j += i)
        large[j - L] = 1;
    }
  }
  bool is_prime(const ll n) const{
    assert(L <= n && n < R);
    return !large[n - L];
  }
};