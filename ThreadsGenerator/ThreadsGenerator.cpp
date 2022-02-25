//name: David Nguyen
//class: CPSC 5042
//homework: HW3 - programming HW

#include "ThreadsGenerator.h"
#include <iostream>
#include <thread>
#include <mutex>
//#include <pthread.h>

using namespace std;
std::mutex mutx;

using namespace std;
int j = 0;


/// <summary>
/// c. threadfunc will attempt to use the value that it was passed to it, 
/// and add to the  global variable j to whatever value was passed to it.  
/// You will need to guard this with a MUTEX lock and MUTEX unlock call.
/// </summary>
/// <param name="value"></param>
void threadfunc(int value) {
	//You will need to guard this with a MUTEX lock 
	mutx.lock();
	//according to slack conversation
	//each thread created is j + 1; 
	j++;
	//You will need to guard this with a MUTEX lock 
	mutx.unlock();
}

/// <summary>
/// b. After processing input, program will create "n" amount of threads. 
/// It will create threads within a for loop (for i=0 to n-1)  
/// </summary>
/// <param name="n"></param>
void threads(int n) {
	//It will pass as an input argument to a function in which you want the threads to go
	for (int i = 0; i < n; i++) {
		threadfunc(i);
	}
}

/// <summary>
/// a. Create a program that accepts as input, the number of threads to create
/// </summary>
/// <returns></returns>
int main()
{
	//pthread_t thread;

	cout << "Thread generators." << endl;
	//input, the number of threads to create
	threads(10);
	//you should print the final value for j.
	cout << "J value after thread returned: " << j << endl;
	return 0;
}



