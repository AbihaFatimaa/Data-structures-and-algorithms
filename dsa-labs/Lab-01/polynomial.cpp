# include <iostream>
# include <string>
# include <cmath>
using namespace std;
class Term
{
	private:
		int term;
		int power;
	public:
		Term(int t=0, int p=0)
		{
			term = t;
			power = p;
		}
		void setPower(int p)
		{
			power = p;
		}
		void setTerm(int t)
		{
			term = t;
		}
		int getPower()
		{
			return power;
		}
		int getTerm()
		{
			return term;
		}
		
};
class Polynomial
{
	private:
		Term * t;
		int capacity;
		int size;
	public:
		Polynomial()
		{
			capacity = 10;
			size=0;
			t= new Term[capacity];
			for (int i=0; i<capacity; i++)
			{
				t[i]=0;
			}
		}
		Polynomial(const Polynomial &p)
		{
			t = new Term[p.size];
			for(int i=0; i<p.size; i++)
			{
				t[i].setPower(p.t[i].getPower());
				t[i].setTerm(p.t[i].getTerm());
			}
			size = p.size;
			capacity = p.capacity;
		}
		void sort()
		{
			for(int i=0; i<size; i++)
			{
				if(t[i].getPower() < t[i++].getPower())
				{
					Term a;
					a.setPower(t[i].getPower());
					a.setTerm(t[i].getTerm());
					t[i].setPower(t[i++].getPower());
					t[i].setTerm(t[i++].getTerm());
					t[i++].setPower (a.getPower());
					t[i++].setTerm(a.getTerm());
				}
		}
		}
		void addTerm(int coefficient, int power)
		{
			for(int i=0; i<capacity; i++)
			{
				if(t[i].getPower() == power)
				{
					int val = t[i].getTerm();
					t[i].setTerm(val+coefficient);
				}
				else
				{
					t[size].setTerm(coefficient);
					t[size].setPower(power);
					size++; 
				}
			}
			sort();
		}
		
		int getDegree()
		{
			int largest=0;
			for(int i=0; i<size; i++)
			{
				if(this->t[i].getPower()>largest)
				{
					largest = this->t[i].getPower();
				}
			}
			return largest;
		}
		int getcoefficient(int power)
		{
			for(int i=0; i<size; i++)
			{
				if(this->t[i].getPower() == power)
				{
					return t[i].getTerm();
				}
			}
			return 0;
		}
		~Polynomial()
		{
			delete[] t;
			size = 0;
			capacity = 0;
		}
		Polynomial& operator=(const Polynomial &p)
		{
			Polynomial q;
			q = (p);
			return q;
		}
		void clear()
		{
			for (int i=0; i<size; i++)
			{
				this->t[i].setTerm(0); 
			}
		}
		void addtoCoefficient(int coefficient, int power)
		{
			for(int i=0; i<size; i++)
			{
				if(this->t[i].getPower() == power)
				{
					int n = t[i].getTerm();
					t[i].setTerm(n+coefficient);
				}
				else
				{
					t[size+1].setPower(power);
					t[size+1].setTerm(coefficient);
					size++;
				}
			}
		}
		void setCoefficient(int coefficient, int power)
		{
			for(int i=0; i<size; i++)
			{
				if(this->t[i].getPower() == power)
				{
					t[i].setTerm(coefficient);
				}
				else
				{
					t[size].setPower(power);
					t[size].setTerm(coefficient);
					size++;
				}
			}
		}
		int getPower(int i)
		{
			return t[i].getPower();
		}
		friend ostream& operator<<(ostream &out,  Polynomial &p)
		{
			for(int i=0; i<p.size; i++)
			{
				out<<p.getcoefficient(i)<<"x^"<<p.getPower(i)<<"+";
			}
			
		}
	
	Polynomial& operator*( Polynomial &p)
	{
		for(int i=0; i<size+p.size; i++)
		{
			if (t[i].getPower() == p.getPower(i))
			{
				t[i].setTerm(this->getcoefficient(i)*p.getcoefficient(i));
				t[i].setPower(this->getPower(i)+p.getPower(i));
			}
			else
			{
				t[size].setTerm(p.getcoefficient(i));
				t[size].setPower(p.getPower(i));
			}
		}
		sort();
		return *this;
	}
	Polynomial& operator-( Polynomial &p)
	{
		for(int i=0; i<size+p.size; i++)
		{
			if (t[i].getPower() == p.getPower(i))
			{
				t[i].setTerm(this->getcoefficient(i)-p.getcoefficient(i));
			}
			else
			{
				t[size].setTerm(p.getcoefficient(i));
				t[size].setPower(p.getPower(i));
			}
		}
		sort();
		return *this;
	}
	float Operator(int value)
		{
			float solution=0;
			for(int i=size-1; i>0; i--)
			{
				solution += t[i].getTerm()*(pow(value, t[i].getPower()));
			}
			return solution;
		}
};
int main() {
	Polynomial p;
	p.addTerm(5, 4);
	cout<<"term added \n";
	cout<<"polynomial: "<<p.getcoefficient(4)<<endl;
	cout<<"degree: "<<p.getDegree()<<endl;
	cout<<"power: "<<p.getPower(3)<<endl;
	p.addtoCoefficient(4, 6);
	p.setCoefficient(6,4);
	cout<<"get coefficient after setting: "<<p.getcoefficient(4);
	cout<<"set coefficient \n";
	return 0;
	   }
