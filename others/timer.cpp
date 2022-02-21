#include <bits/stdc++.h>
using namespace std;

//chronoを使った計測
#include <chrono>
struct Timer {
  chrono::high_resolution_clock::time_point st;
  Timer(){ start(); }
  void start(){ st = chrono::high_resolution_clock::now(); }
  chrono::milliseconds::rep result(){
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end-st).count();
  }
};


//windows.hを使った計測
#include <windows.h>
struct Timer {
	LARGE_INTEGER s, e, freq;
	Timer(){
		memset(&e, 0, sizeof(e));
		QueryPerformanceFrequency(&freq);
		start();
	}
	void start(){ QueryPerformanceCounter(&s); }
	void end(){ QueryPerformanceCounter(&e); }
	double result(){
		double time = static_cast<double>(e.QuadPart - s.QuadPart) * 1000.0 / freq.QuadPart;
		return time;
	}
};