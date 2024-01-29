#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

				//Многозадачность и многопоточность
				//Поток с параметрами
			

void DoWorK(int a,int b,string msg)
{
	cout << "------------\tStart DoWorK()\t------------" << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "\t DoWork = " << a + b <<"\t" << msg << endl;
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "------------\tEND DoWorK()\t------------\t" << endl;

}

int main()
{
	setlocale(LC_ALL, "ru");
	thread th(DoWorK,2, 4, "MSG *Hi bro*");
	

	
	for (rsize_t i=0;true; ++i)
	{

		cout << "ID thread = " << this_thread::get_id() << "\t int main(){} " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}


	
	//th.join();
	
	return 0;
}