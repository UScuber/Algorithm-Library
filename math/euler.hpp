ll euler(ll n){
  ll res = n, k = n;
  for(ll i = 2; i*i <= k; i++){
    if(n % i) continue;
    res = res / i * (i - 1);
    while(n % i == 0) n /= i;
  }
  if(n != 1) res = res / n * (n - 1);
  return res;
}