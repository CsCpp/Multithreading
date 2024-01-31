#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

				//Многозадачность и многопоточность
				// лямбда функции
			

int Sum(int &a,int &b)
{
	cout << "------------\tStart Sum()\t------------" <<this_thread::get_id()<< endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	
	cout << "\t Sum = " << a+b <<"\t" << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "------------\tEND Sum()\t------------\t" << this_thread::get_id() << endl;
	return a + b;
}

int main()
{
	setlocale(LC_ALL, "ru");
	int a = 2;
	int b = 4;
	
	int result;
	 
	thread th([&result,&a,&b]() {result = Sum(a, b); });
	int result2;
	auto f = [&result2, &a, &b]() {result2 = Sum(a, b); };
	
	thread th2(f);
	
	for (rsize_t i=0;i<10; ++i)
	{
		
		cout << "ID thread = " << this_thread::get_id() << "\t int main(){} " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}


	
	th.join();
	th2.join();
	cout << result << " - result " << endl;
	cout << result2 << " - result2 " << endl;
	return 0;
}