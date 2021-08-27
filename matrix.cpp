#include <bits/stdc++.h>
using namespace std;

template<class T> struct matrix {
  matrix(int n = 0) : n(n), a(n, vector<T>(n)){}
  vector<T> &operator[](const int &m){ return a[m]; }
  matrix &operator*=(const matrix &b){
    vector<vector<T>> c(n, vector<T>(n));
    for(int i = 0; i < n; i++) for(int j = 0; j < b.n; j++)
    for(int k = 0; k < n; k++){
      c[i][j] += a[i][k] * b.a[k][j];
    }
    a = c;
    return *this;
  }
  matrix &operator+=(const matrix &b){
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
      a[i][j] += b.a[i][j];
    return *this;
  }
  matrix &operator-=(const matrix &b){
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
      a[i][j] -= b.a[i][j];
    return *this;
  }
  matrix operator*(const matrix &b) const{ return matrix(*this) *= b; }
  matrix operator+(const matrix &b) const{ return matrix(*this) += b; }
  matrix operator-(const matrix &b) const{ return matrix(*this) -= b; }
  matrix pow(ll t) const{
    matrix<T> b(n), c = *this;
    for(int i = 0; i < n; i++) b[i][i] = 1;
    while(t > 0){
      if(t & 1) b *= c;
      c *= c;
      t /= 2;
    }
    return b;
  }
  T det() const{
    if(n == 2) return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    T res = 0;
    for(int i = 0; i < n; i++){
      T p = 1, m = 1;
      for(int j = 0; j < n; j++){
        p *= a[(i+j) % n][j];
        m *= a[(i+j) % n][n-j-1];
      }
      res += p - m;
    }
    return res;
  }
  matrix inv(){
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
  void debug(){
    rep(i, n){
      rep(j, n) cerr << a[i][j] << " ";
      cerr << "\n";
    }
  }
  int n;
  private:
  vector<vector<T>> a;
};