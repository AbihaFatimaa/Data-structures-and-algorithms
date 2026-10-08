# include <iostream>
# include <string>
# include "../../ds/Stack.h"
using namespace std;
class history
{
	private:
		Stack<string> s1;
		Stack<string> s2;
	public:
		history():s1(), s2()
		{
		}
		void visitpage(string s)
		{
			s1.push(s);

		}	
		string goback()
		{
			if(!s1.isEmpty())
				return s1.pop();
			return "No history available\n";
		}
		void displayHistory()
		{
			if(s1.isEmpty())
			{
				cout<<"No previous History\n";
				return;
			}
			int n=s1.getTop();
			for(int i=0; i<n; i++)
			{
				if(!s1.isEmpty())
				{
					cout<<s1.StackTop()<<endl;
					s2.push(s1.pop());
				}
			}
			while(!s2.isEmpty())
			{
				s1.push(s2.pop());
			}
		}
};
int main() {
	history h;
	int n;
	do
	{
		cout<<"1. VisitPage \n"
		<<"2. Go Back \n"
		<<"3. Display History \n"
		<<"4. Exit \n";
		cout<<"\nenter choice: \n";
		cin>>n;
		
		if(n==1)
		{
			string s;
			cout<<"enter page: \n";
			cin.ignore();
			getline(cin, s);
			h.visitpage(s);
		}
		else if(n==2)
		{
			string a = h.goback();
			cout<<"Going back to: "<<a<<"\n";
		}
		else if(n==3)
		{
			cout<<"Browser history: \n\n";
			h.displayHistory();
			cout<<"\n";
		}
		else if(n==4)
		{
			cout<<"exiting browser history...";
			return 0;
		}
	}while(true);
	return 0;
	   }
