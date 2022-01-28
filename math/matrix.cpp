#include <bits/stdc++.h>
using namespace std;

template<class T> struct matrix {
  int n,m;
  private:
  vector<vector<T>> a;
  public:
  matrix(int n) : n(n), m(n), a(n, vector<T>(n)){}
  matrix(int n, int m) : n(n), m(m), a(n, vector<T>(m)){}
  matrix(const vector<vector<T>> &d) : a(d), n(d.size()), m(d[0].size()){}
  vector<T> &operator[](const int &i){ return a[i]; }
  matrix &operator*=(const matrix &b){
    assert(m == b.n);
    vector<vector<T>> c(n, vector<T>(b.m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
    for(int k = 0; k < b.m; k++){
      c[i][k] += a[i][j] * b.a[j][k];
    }
    a = c;
    return *this;
  }
  matrix &operator+=(const matrix &b){
    assert(n == b.n && m == b.m);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
      a[i][j] += b.a[i][j];
    return *this;
  }
  matrix &operator-=(const matrix &b){
    assert(n == b.n && m == b.m);
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
      a[i][j] -= b.a[i][j];
    return *this;
  }
  matrix operator*(const matrix &b) const{ return matrix(*this) *= b; }
  matrix operator+(const matrix &b) const{ return matrix(*this) += b; }
  matrix operator-(const matrix &b) const{ return matrix(*this) -= b; }
  matrix pow(ll t) const{
    assert(n == m);
    matrix<T> b(n), c = *this;
    for(int i = 0; i < n; i++) b[i][i] = 1;
    while(t > 0){
      if(t & 1) b *= c;
      c *= c;
      t >= 2;
    }
    return b;
  }
  T det() const{
    assert(n == m);
    matrix b = *this;
    T res(1);
    for(int i = 0; i < n; i++){
      if(b[i][i] == 0){
        for(int j = i + 1; j < n; j++){
          if(b[j][i] > 0){
            swap(b[i], b[j]);
            res = -res;
            break;
          }
        }
      }
      res *= b[i][i];
      for(int j = i + 1; j < n; j++){
        T d = T(1) / b[i][i];
        for(int k = i + 1; k < n; k++){
          b[j][k] -= b[j][i] * d * b[i][k];
        }
      }
    }
    return res;
  }
  matrix inv(){
    assert(n == m);
    matrix b(n), c = *this;
    for(int i = 0; i < n; i++) b[i][i] = 1;
    int r = 0;
    for(int i = 0; i < n && r < n; i++){
      if(c[r][i] == 0){
        T max_val = 0; int mx_pos;
        for(int j = r+1; j < n; j++){
          if(max_val < c[j][i]) max_val = c[j][i], mx_pos = j;
        }
        if(max_val == 0) return false;
        swap(c[r], c[mx_pos]); swap(b[r], b[mx_pos]);
      }     
      T d = T(1) / c[r][i];
      for(int j = 0; j < n; j++) c[r][j] *= d, b[r][j] *= d;
      for(int j = 0; j < n; j++){
        T v = c[j][i];
        if(j == r || c[j][i] == 0) continue;
        for(int k = 0; k < n; k++){
          c[j][k] -= c[r][k] * v;
          b[j][k] -= b[r][k] * v;
        }
      }
      r++;
    }
    return b;
  }
  int size() const{ return n; }
  void debug(){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++) cerr << a[i][j] << " ";
      cerr << "\n";
    }
  }
};