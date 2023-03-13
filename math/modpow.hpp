ll modPow(ll a, ll n, ll p){
  a %= p;
  ll res = 1;
  while(n){
    if(n & 1) (res *= a) %= p;
    (a *= a) %= p;
    n >>= 1;
  }
  return res;
}