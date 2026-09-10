# include <iostream>
# include <string>
# include <fstream>
using namespace std;
class student
{
	private:
		char name[30];
		int rollNo;
		float marks;
		char department[30];
	public:
		void input()
		{
			cout<<"enter name: \n";
			cin.ignore();
			cin.getline(name, 30);
			cout<<"enter rollno: \n";
			cin>>rollNo;
			cout<<"enter marks: \n";
			cin>>marks;
			cout<<"enter department: \n";
			cin.ignore();
			cin.getline(department, 30);
		}
		void display()
		{
			cout << "\nName       : " << name;
	        cout << "\nRoll No    : " << rollNo;
	        cout << "\nMarks      : " << marks;
	        cout << "\nDepartment : " << department;
	        cout << "\n-----------------------------\n";
		}
		int getRollNo()
		{
			return rollNo;
		}
		float getMarks()
		{
			return marks;
		}
		char* getName()
		{
			return name;
		}
		char* getDepartment()
		{
			return department;
		}
};
	
		void addStudent()
		{
			student s;
			s.input();
			ofstream file("student.dat", ios::binary|ios::app);
			if(!file)
			{
				cout<<"file not open!!";
				return;
			}
			file.write((char *)&s, sizeof(s));
			cout<<"file written successfully \n";
			file.close();
		}
		void displayStudents()
		{
			student s;
			ifstream file("student.dat", ios::binary);
			if(!file)
			{
				cout<<"file not open \n ";
				return;
			}
			cout<<"All Students: \n";
			while(file.read((char *)&s, sizeof(s)))
			{
				s.display();
			}
			file.close();
			cout<<"file closed";
		}
		void searchStudent()
		{
			int roll;
			student s;
			bool found;
			ifstream file("student.dat", ios::binary);
			if(!file)
			{
				cout<<"file not open \n";
				return;
			}
			cout<<"enter the roll number to search: \n";
			cin>>roll;
			while(file.read((char *)&s, sizeof(s)))
			{
				if(s.getRollNo() == roll)
				{
					found = true;
					cout<<"Student found \n";
					s.display();
					break;
				}
			file.close();
			}
		}
		void updateStudent()
		{
			student s;
		    int roll;
		    bool found = false;
		
		    cout << "Enter Roll Number to update: ";
		    cin >> roll;
		
		    fstream file("student.dat",
		                 ios::in | ios::out | ios::binary);
		
		    if (!file)
		    {
		        cout << "File could not be opened!\n";
		        return;
		    }
		
		    while (file.read((char*)&s, sizeof(s)))
		    {
		        if (s.getRollNo() == roll)
		        {
		            cout << "\nCurrent Record:\n";
		            s.display();
		
		            cout << "\nEnter new information:\n";
		            s.input();
		
		            file.seekp(
		                file.tellg() - (streamoff)sizeof(s)
		            );
		
		            file.write((char*)&s, sizeof(s));
		
		            found = true;
		
		            cout << "\nStudent updated successfully!\n";
		            break;
		        }
		    }
		
		    file.close();
		
		    if (!found)
		    {
		        cout << "\nStudent not found!\n";
		    }
		}
		
		void deleteStudent()
		{
			int roll;
			student s;
			bool found;
			cout<<"enter roll number to delete: \n";
			cin>>roll;
			ifstream file("student.dat", ios::binary);
			ofstream tmp("temp.dat", ios::binary);
			if(!file || !tmp)
			{
				cout<<"file not open \n";
				return;
			}
			while(file.read((char *)&s, sizeof(s)))
			{
				if(s.getRollNo() == roll)
				{
					found = true;
				}
				else
				{
					tmp.write((char *)&s, sizeof(s));
					
				}
			}
			file.close();
			tmp.close();
			remove("student.dat");
			rename("temp.dat", "student.dat");
			if(found)
			{
				cout<<"student deleted \n";
			}
		}
		void exportToText()
		{
			student s;
		
		    ifstream binaryFile("student.dat",
		                        ios::binary);
		
		    ofstream textFile("student.txt");
		
		    if (!binaryFile || !textFile)
		    {
		        cout << "File could not be opened!\n";
		        return;
		    }
		
		    while (binaryFile.read((char*)&s, sizeof(s)))
		    {
		        textFile << "Name       : "
		                 << s.getName() << endl;
		
		        textFile << "Roll No    : "
		                 << s.getRollNo() << endl;
		
		        textFile << "Marks      : "
		                 << s.getMarks() << endl;
		
		        textFile << "Department : "
		                 << s.getDepartment() << endl;
		
		        textFile << "-----------------------------"
		                 << endl;
		    }
		
		    binaryFile.close();
		    textFile.close();
		
		    cout << "\nRecords exported to students.txt\n";
		}
		void fileInformation()
		{
		    student s;
		
		    fstream file("student.dat",
		                 ios::in | ios::binary);
		
		    if (!file)
		    {
		        cout << "File could not be opened!\n";
		        return;
		    }
		
		    // Move get pointer to end
		    file.seekg(0, ios::end);
		
		    // Get total file size
		    streampos fileSize = file.tellg();
		
		    // Calculate number of records
		    int totalStudents =
		        fileSize / sizeof(student);
		
		    cout << "\n===== FILE INFORMATION =====\n";
		
		    cout << "File size       : "
		         << fileSize << " bytes\n";
		
		    cout << "Student record  : "
		         << sizeof(student) << " bytes\n";
		
		    cout << "Total students  : "
		         << totalStudents << endl;
		
		    file.close();
		}
int main()
{
    int choice;

    do
    {
        cout << "\n\n";
        cout << "==============================\n";
        cout << " STUDENT RECORD MANAGEMENT\n";
        cout << "==============================\n";

        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Export to Text File\n";
        cout << "7. Display File Information\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            exportToText();
            break;

        case 7:
            fileInformation();
            break;

        case 8:
            cout << "\nProgram terminated.\n";
            break;

        default:
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}
