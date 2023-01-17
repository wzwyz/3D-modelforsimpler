#include <iostream>
#include <vector>
#include <sys/time.h>
#include <math.h>
#include <thread>
#include<windows.h>
using namespace std;

void parallel(int a){
	char zhiling[100];
	sprintf(zhiling,".\\function\\%d.exe",a);
	system(zhiling);
}
int main(int argc, char **argv) {
  struct timeval start, end;
  int a; 
  gettimeofday(&start, NULL);
  thread t1(parallel,1);
  thread t2(parallel,2);
  thread t3(parallel,3);
  thread t4(parallel,4);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  gettimeofday(&end, NULL);
  float cost_time = (end.tv_usec-start.tv_usec)/1000000.0 + end.tv_sec-start.tv_sec;
  cout << cost_time << endl;

  return 0;
}
// Êä³ö 0.067235
//     0.497571

