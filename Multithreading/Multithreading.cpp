#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

				//Многозадачность и многопоточность
				// std::ref()
				//получение результатов работы функции из потока 
			

void DoWorK(int &a,int &b)
{
	cout << "------------\tStart DoWorK()\t------------" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	a =a + b;
	cout << "\t DoWork = " << a <<"\t" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "------------\tEND DoWorK()\t------------\t" << endl;

}

int main()
{
	setlocale(LC_ALL, "ru");
	int a = 2;
	int b = 4;
	//DoWorK(a, b);
	thread th(DoWorK, std::ref(a), std::ref(b));
	

	
	for (rsize_t i=0;i<10; ++i)
	{

		cout << "ID thread = " << this_thread::get_id() << "\t int main(){} " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}


	
	th.join();
	cout << a << endl;
	return 0;
}