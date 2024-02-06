#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;

//unique_lock


recursive_mutex rm;
mutex m;

void Print(char ch)
{
	unique_lock<mutex> ul(m,std::defer_lock);
//	lock_guard<mutex> lg(m);
	this_thread::sleep_for(chrono::milliseconds(2000));
	ul.lock();
//	m.lock();
//	{	lock_guard<mutex> lg(m);
	for (int i = 0; i < 5; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
//	}
//	m.unlock();
	ul.unlock();
	this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
	setlocale(LC_ALL, "ru");
	thread t1(Print, '*');
	this_thread::sleep_for(chrono::milliseconds(500));
	thread t2(Print, '#');


	
	t1.join();
	t2.join();

	

	return 0;
}