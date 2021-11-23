#include <bits/stdc++.h>
#include <cassert>
using namespace std;

template <class T, T(*op)(const T&,const T&), const T(*e)()>
struct SWAG : deque<T> {
  private:
  T front = e();
  stack<T> back;
  int l = 0, r = 0;
  public:
  SWAG(int n = 0) : deque<T>(n){}
  SWAG(const deque<T> &v) : deque<T>(v){}
  T fold(int i, int j){
    assert(l <= i && i <= j);
    assert(r <= j && j <= (*this).size());
    while(r < j) front = op(front, (*this)[r++]);
    while(l < i){
      if(back.empty()){
        T temp = e();
        for(int u = r - 1; u >= l; u--) back.push(temp = op((*this)[u], temp));
        front = e();
      }
      back.pop();
      l++;
    }
    if(back.empty()) return front;
    return op(back.top(), front);
  }
  void pop(){
    if(!l) fold(l + 1, max(l + 1, r));
    l--; r--;
    (*this).pop_front();
  }
};