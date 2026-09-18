# include <iostream>
# include <string>
# include <fstream>
# include <windows.h>
# include <stdio.h>
using namespace std;
	struct Student
	{
		int roll;
		char name[30];
		Student():roll(0)
		{
			strcpy(name,"none");
		}
	};
	void addToStudentUnBuffered(int N)
	{
	ofstream ofs("studentdatabase.txt",ios::binary|ios::out);
	Student s;
	for (int i=1; i<N; i++)
	{
	s.roll = i;
	ofs.write((char*)(&s),sizeof(Student));
	}
	ofs.close();
	}
	void addToStudentBuffered(int N)
	{
		ofstream file("studentdatabase.txt",ios::binary|ios::out);
		Student s[N];
		for(int i=0; i<N; i++)
		{
			s[i].roll = i;
		}
		
		file.write((char*) &s, sizeof(s));
		file.close();	
	}
	void displayUnbefferd(int N)
	{
		ifstream file("studentdatabase.txt",ios::binary|ios::in);
		Student s;
		for(int i=0; i<N; i++)
		{
			file.read((char*) &s, sizeof(Student));
		}
		file.close();
	}
	void displayBuffered(int N)
	{
		ifstream file("studentdatabase.txt",ios::binary|ios::in);
		Student s[N];
		file.read((char*) &s, sizeof(s));
		file.close();

	}
int main() {
	SYSTEMTIME systime;
	cout<<"\nWriting Records to File one by one";
	GetLocalTime(&systime);
	cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
	addToStudentUnBuffered(10000);
	GetLocalTime(&systime);
	cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
	cout<<"\nwriting records buffered"<<endl;
	GetLocalTime(&systime);
	cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
	addToStudentBuffered(10000);
	GetLocalTime(&systime);
	cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
	cout<<"\nreading unbuffered: \n";
	GetLocalTime(&systime);
	cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
	displayUnbefferd(10000);
	GetLocalTime(&systime);
	cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
	cout<<"\nreading buffered: \n";
	GetLocalTime(&systime);
	cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
	displayBuffered(10000);
	GetLocalTime(&systime);
	cout<<endl<<systime.wHour<<":"<<systime.wMinute<<":"<<systime.wSecond<<":"<<systime.wMilliseconds;
	
	return 0;
	   }
