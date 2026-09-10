# include <iostream>
# include <string>
# include <fstream>
using namespace std;
struct student
{
	char name[30];
	int roll;
	float marks;
};
int main() {
	fstream file("student.dat", ios::in|ios::out|ios::binary|ios::trunc);
	if(!file)
	{
		cout<<"File not open!! \n";
		return 0;
	}
	student s[5];
	for(int i=0; i<5; i++)
	{
		cout<<"Enter name, roll number, marks: \n";
		cin>>s[i].name>>s[i].roll>>s[i].marks;
	}
	file.write((char *)s, sizeof(s));
	file.seekg(0, ios::beg);
	cout<<"Reading data from the file: \n";
	for(int i = 0; i < 5; i++)
	{
    file.read((char*)&s[i], sizeof(student));

    cout << s[i].name << "\t"
         << s[i].roll << "\t"
         << s[i].marks << "\n";
	}
	file.clear();
	file.seekg(0, ios::beg);
	int n;
	cout<<"enter roll number to search: \n";
	cin>>n;
	for(int i = 0; i < 5; i++)
	{
    file.read((char*)&s[i], sizeof(student));

    if(s[i].roll == n)
    {
        cout << "Name: " << s[i].name << "\n";
        cout << "Marks: " << s[i].marks << "\n";
        break;
    }
	}
	file.close();
	cout<<"file closed successfully!";
	
	return 0;
	   }
