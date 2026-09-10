# include <iostream>
# include <string>
# include <fstream>
using namespace std;
int main() {
	cout<<"Notes Manager \n";
	fstream fout ("notes.txt", ios::out|ios::in|ios::app);
	string task;
	int option;
	do
	{
	cout<<"Main Menu \n";
	cout<<"1. add task \n";
	cout<<"2. view task \n";
	cout<<"3. Exit \n";
	cin>>option;
	if(option == 1)
	{
		cout<<"enter task to add: \n";
		cin.ignore();
		getline(cin, task);
		fout<<task<<"\n";
		cout<<"Task added successfully \n";
	}
	else if(option == 2)
	{
		cout<<"Your tasks are: \n";
		fout.clear();
    	fout.seekg(0, ios::beg); 
		while(getline(fout, task))
		{
		cout<<task<<"\n";
		}
	}
	else if (option == 3)
	{
		break;
	}
	}while(option != 3);
	fout.close();
	cout<<"Task manager exited \n";
	return 0;
	   }
