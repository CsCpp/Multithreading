#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;

//recursive_mutex


recursive_mutex rm;
mutex m;

void Foo(int a)
{
	rm.lock();
	cout << a << " ";
	this_thread::sleep_for(chrono::milliseconds(300));
	if (a <= 1)
	{
		cout << endl;
		rm.unlock();
		return;
	}
	a--;

	Foo(a);
	rm.unlock();

}


int main()
{
	setlocale(LC_ALL, "ru");
	thread t1(Foo, 10);
	this_thread::sleep_for(chrono::milliseconds(500));
	thread t2(Foo, 10);


	
	t1.join();
	t2.join();

	

	return 0;
}