# include <iostream>
# include <string>
using namespace std;
void isValidPassword(const string &s, int index = 0)
{
	while(index<s.length()){
	if(index%2 == 0)
	{
		if (s[index]>='0' && s[index]<='9')
		{
			cout<<"t";
		//	return true;
		}
		else
		{
			cout<<"f";
		//	return false;
		}
	}
	else {
		if(s[index]>='a'&& s[index]<='z')
		{
			cout<<"t";
			//return true;
		}
		else
		{
			cout<<"f";
			//return false;
		}
	}
	isValidPassword(s, index+1);
	//if(isValidPassword(s, index+1))
	 {
	 //	cout<<"t";
		//return true;
	 }
	 //return false;
	 
}
//return false;
}
int main() {
	isValidPassword("1234");
	return 0;
	   }
