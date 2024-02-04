#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

using namespace std;

//взаимная блокировка
// DeadLock

								
mutex mtx1;
mutex mtx2;

void Print()
{
	mtx1.lock();
	this_thread::sleep_for(chrono::milliseconds(1000));
	mtx2.lock();
	this_thread::sleep_for(chrono::milliseconds(200));
	{
		
		for (int i = 0; i < 5; ++i)
		{
			for (int i = 0; i < 10; i++)
			{

				cout << "*";

				this_thread::sleep_for(chrono::milliseconds(20));

			}

			cout << endl;

		}

		cout << endl;
	}
	
	this_thread::sleep_for(chrono::milliseconds(200));
	
	mtx1.unlock();
	mtx2.unlock();
}
void Print2()
{
	mtx2.lock();
	this_thread::sleep_for(chrono::milliseconds(1000));
	mtx1.lock();
	this_thread::sleep_for(chrono::milliseconds(200));
	{
		
		for (int i = 0; i < 5; ++i)
		{
			for (int i = 0; i < 10; i++)
			{

				cout << "#";

				this_thread::sleep_for(chrono::milliseconds(20));

			}

			cout << endl;

		}

		cout << endl;
	}

	this_thread::sleep_for(chrono::milliseconds(200));

	mtx1.unlock();
	mtx2.unlock();
}

int main()
{
	setlocale(LC_ALL, "ru");
	thread t1(Print);
	thread t2(Print2);
	
	
	t1.join();
	t2.join();
	

	return 0;
}