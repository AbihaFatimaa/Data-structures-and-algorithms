# include <iostream>
# include <string>
# include <fstream>
using namespace std;
int main() {
/*Create a program that asks the user for:
Name
Age
City
Save the information into person.txt.*/
	ofstream fout("person.txt");
	if(!fout)
	{
		cout<<"File not open!";
		return 0;
	}
	string name, city;
	int age;
	cout<<"Enter your name, age, and city: \n";
	cin>>name>>age>>city;
	fout<<name<<"	"<<age<<"	"<<"	"<<city<<"\n";
	fout.close();
	cout<<"file operation successful! \n";
	
/*Create a program that asks for the marks of 5 students and stores them in:

marks.txt

Then read the file and calculate:

Total marks
Average
Highest mark
Lowest mark

Practice: loops + text file reading/writing*/
	ofstream foo ("marks.txt");
	float n;
	for(int i=0; i<5; i++)
	{
		cout<<"Enter marks: \n";
		cin>>n;
		foo<<n<<"\n";
	}
	foo.close();
	ifstream fin ("marks.txt");
	float sum=0; 
	float highest=0;
	float lowest=10000;
	for(int i=0; i<5; i++)
	{
		fin>>n;
		sum += n;
		if(n>highest)
		{
			highest = n;
		}
		if(n<lowest)
		{
			lowest = n;
		}
	}
	cout<<"Total marks are: "<<sum<<"\n";
	cout<<"Average of total marks are: "<<sum/5<<"\n";
	cout<<"Highest marks are: "<<highest<<"\n";
	cout<<"Lowest marks are: "<<lowest<<"\n";
	fin.close();
	cout<<"File closed successfully \n";
	return 0;
	   }
