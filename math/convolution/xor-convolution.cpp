#include <vector>
#include <cassert>
using namespace std;

template <class T>
void fzt(vector<T> &a){
  const int n = a.size();
  for(int j = 0; (1 << j) < n; j++){
    for(int i = 0; i < n; i++){
      if(!(i >> j & 1)){
        const T x = a[i], y = a[i | 1 << j];
        a[i] = x + y;
        a[i | 1 << j] = x - y;
      }
    }
  }
}
template <class T>
void fmt(vector<T> &a){
  const int n = a.size();
  for(int j = 0; (1 << j) < n; j++){
    for(int i = 0; i < n; i++){
      if(!(i >> j & 1)){
        const T x = a[i], y = a[i | 1 << j];
        a[i] = (x + y) / 2;
        a[i | 1 << j] = (x - y) / 2;
      }
    }
  }
}
template <class T>
vector<T> xor_convolution(vector<T> a, vector<T> b){
  const int n = a.size();
  assert((n & (n - 1)) == 0 && a.size() == b.size());
  fzt(a);
  fzt(b);
  vector<T> c(n);
  for(int i = 0; i < n; i++) c[i] = a[i] * b[i];
  fmt(c);
  return c;
}