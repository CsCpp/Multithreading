#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

				//Многозадачность и многопоточность
				//Thread 
			

void DoWorK() 
{
	cout << "Start DoWorK()" << endl;
	for (int i = 0; i < 10; ++i)
	{

		cout << "ID thread = " << this_thread::get_id() << "\t void DoWorK(){} " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}

	cout << "END DoWorK()" << endl;

}

int main()
{
	setlocale(LC_ALL, "ru");
	thread th(DoWorK);
	thread th2(DoWorK);

	cout << "Start int main()" << endl;
	for (int i=0;i<10; ++i)
	{

		cout << "ID thread = " << this_thread::get_id() << "\t int main(){} " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	cout << "END int main()" << endl;
	
	th.join();
	th2.join();
	return 0;
}