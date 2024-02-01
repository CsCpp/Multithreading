#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

				//Многозадачность и многопоточность
				// запуск методов класса в отдельном потоке
class myClass {
public:
	
	void DoWork ()
	{
		
		cout << "------------\tStart DoWork\t------------" << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(7000));
		cout << "------------\tEND DoWork\t------------\t" << this_thread::get_id() << endl;
	
	}
	void DoWork2(int a)
	{
		
		cout << "------------\tStart DoWork2\t------------" << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(4000));

		cout << "\t DoWork2 - значение параметра = " << a << "\t" << endl;
		this_thread::sleep_for(chrono::milliseconds(4000));
		cout << "------------\tEND DoWork2\t------------\t" << this_thread::get_id() << endl;

	}
	int Sum(int& a, int& b)
	{
		
		cout << "------------\tStart Sum\t------------" << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));

		cout << "\t Sum a+b = " << a+b << "\t" << endl;
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "------------\tEND Sum\t------------\t" << this_thread::get_id() << endl;
		return a + b;
	}

};



int main()
{
	setlocale(LC_ALL, "ru");
	myClass m;

	
	int a = 2;
	int b = 4;
	int result;
	thread t3(&myClass::DoWork2,m,a);

	thread t2(&myClass::DoWork, m);

	thread t([&]() {result = m.Sum(a, b);});
	


	for (rsize_t i=0;i<10; ++i)
	{
		
		cout << "ID thread = " << this_thread::get_id() << "\t int main(){} " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	
	t.join();
	cout << "Результат работы метода SUM = " << result << endl;
	t2.join();
	t3.join();

	return 0;
}