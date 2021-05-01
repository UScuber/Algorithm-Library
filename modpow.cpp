#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll modPow(ll a, ll n, ll p){
  if(!n) return 1;
  if(n == 1) return a % p;
  if(n & 1) return (a * modPow(a, n - 1, p)) % p;
  ll t = modPow(a, n / 2, p);
  return (t * t) % p;
}