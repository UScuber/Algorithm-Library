template<class T>
T gcd(T a, T b){
  if(!b) return a;
  return gcd(b, a % b);
}

template<class T>
T lcm(T a, T b){
  return a / gcd(a, b) * b;
}