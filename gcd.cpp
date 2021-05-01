#include <bits/stdc++.h>
using namespace std;

template<class T>
T gcd(T a, T b){
  if(a % b == 0) return b;
  return gcd(b, a % b);
}