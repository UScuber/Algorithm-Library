#include <bits/stdc++.h>
using namespace std;

template<int op, class T>
int lower_pair(const vector<pair<T,T>> &a, const T &x){
  int left = -1, right = (int)a.size();
  while(left + 1 < right){
    auto mid = (left + right) / 2;
    if(op == 0){
      if(a[mid].first < x) left = mid;
      else right = mid;
    }else{
      if(a[mid].second < x) left = mid;
      else right = mid;
    }
  }
  return right;
}

template<int op, class T>
int upper_pair(const vector<pair<T,T>> &a, const T &x){
  int left = -1, right = (int)a.size();
  while(left + 1 < right){
    auto mid = (left + right) / 2;
    if(op == 0){
      if(a[mid].first <= x) left = mid;
      else right = mid;
    }else{
      if(a[mid].second <= x) left = mid;
      else right = mid;
    }
  }
  return right;
}