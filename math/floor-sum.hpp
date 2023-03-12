using ull = unsigned long long;

ull floor_sum_unsigned(ull n, ull m, ull a, ull b){
  ull ans = 0;
  while(true){
    if(a >= m){
      ans += n * (n - 1) / 2 * (a / m);
      a %= m;
    }
    if(b >= m){
      ans += n * (b / m);
      b %= m;
    }
    const ull y_max = a * n + b;
    if(y_max < m) break;
    n = y_max / m;
    b = y_max % m;
    swap(m, a);
  }
  return ans;
}
ll floor_sum(const ll n, const ll m, ll a, ll b){
  assert(0 <= n && n < (1LL << 32));
  assert(1 <= m && m < (1LL << 32));
  ull ans = 0;
  if(a < 0){
    const ull a2 = (a % m + m) % m;
    ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);
    a = a2;
  }
  if(b < 0){
    const ull b2 = (b % m + m) % m;
    ans -= 1ULL * n * ((b2 - b) / m);
    b = b2;
  }
  return ans + floor_sum_unsigned(n, m, a, b);
}