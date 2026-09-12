# include <iostream>
# include <string>
# include <cmath>
using namespace std;
class Term
{
	private:
		double coefficient;
		int power;
	public:
		Term(double c = 0, int p = 0)
		{
			coefficient = c;
			power = p;
		}
		void setCoefficient(double c)
		{
			coefficient = c;
		}
		void setPower(int p)
		{
			power = p;
		}
		double getCoefficient() const
		{
			return coefficient;
		}
		int getPower() const
		{
			return power;
		}
};
class Polynomial
{
	private:
		Term* term;
		int size;
		int capacity;
		
		void resize()
		{
			capacity = capacity * 2;
			Term* temp = new Term[capacity];
			for (int i=0; i<size; i++)
			{
				temp[i] = term[i];
			}
			delete[] term;
			term = temp;
		}
		int findPower(int power) const
		{
			for(int i=0; i<size; i++)
			{
				if(term[i].getPower() == power)
				{
					return i;
				}
			}
			return -1;
		}
		void sort()
		{
			for(int i=0; i<size-1; i++)
			{
				for(int j=i+1; j<size; j++)
				{
					if(term[i].getPower() < term[j].getPower())
					{
						Term temp = term[i];
						term[i] = term[j];
						term[j] = temp;
					}
				}
			}
		}
	public:
		Polynomial(int initcapacity = 10)
		{
			if(initcapacity < 0)
			{
				initcapacity = 10;
			}
			capacity = initcapacity;
			size = 0;
			term = new Term[capacity];
		}
		Polynomial(const Polynomial& p)
		{
			capacity = p.capacity;
			size = p.size;
			term = new Term[capacity];
			for(int i=0; i<size; i++)
			{
				term[i] = p.term[i];
			}
		}
		Polynomial& operator=(const Polynomial& p)
		{
			if(this == &p)
			{
				return *this;
			}
			delete[] term;
			capacity = p.capacity;
			size = p.size;
			term = new Term[capacity];
			for(int i=0; i<size; i++)
			{
				term[i] = p.term[i];
			}
			return *this;
		}
		~Polynomial()
		{
			delete[] term;
		}
		void addTerm(double coefficient, int power)
		{
			if(power < 0)
			{
				throw "Power cant be negative";
				
			}
			int index = findPower(power);
			if(index != -1)
			{
				double newcoefficient = term[index].getCoefficient() + coefficient;
				term[index].setCoefficient(newcoefficient);
				if(coefficient == 0)
				{
					for(int i=index; i<size-1; i++)
					{
						term[i] = term[i+1];
					}
					size--;
				}
			}
			else
			{
				if(size == capacity)
				{
					resize();
				}
				term[size].setCoefficient(coefficient);
				term[size].setPower(power);
				size++;
			}
			sort();
		}
	    int getDegree() const
	    {
	        if (size == 0)
	        {
	            return 0;
	        }
	
	        return term[0].getPower();
	    }
		double getCoefficient(int power) const
	    {
	        int index = findPower(power);
	
	        if (index != -1)
	        {
	            return term[index].getCoefficient();
	        }
	
	        return 0;
	    }
	    double operator()(double val) const
	    {
	    	double answer = 0;
	    	for(int i=0; i<size; i++)
			{
	    		answer += term[i].getCoefficient() * pow(val, term[i].getPower());
			}
			return answer;
		}
		Polynomial operator+(const Polynomial& p) const
		{
			Polynomial ans;
			for(int i=0; i<size; i++)
			{
				ans.addTerm(term[i].getCoefficient(), term[i].getPower());
			}
			for(int i=0; i<p.size; i++)
			{
				ans.addTerm(p.term[i].getCoefficient(), p.term[i].getPower());
			}
			return ans;
		}
		Polynomial operator-(const Polynomial& p) const
		{
			Polynomial ans;
				for(int i=0; i<size; i++)
				{
					ans.addTerm(term[i].getCoefficient(), term[i].getPower());
				}
				for(int i=0; i<p.size; i++)
				{
					ans.addTerm(-p.term[i].getCoefficient(), p.term[i].getPower());
				}
				return ans;	
		}
		Polynomial operator*(const Polynomial& p) const
		{
			Polynomial ans;
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<p.size; j++)
				{
					double newcoeff = term[i].getCoefficient()*p.term[i].getCoefficient();
					int newp = term[i].getPower()+p.term[i].getPower();
					ans.addTerm(newcoeff, newp);			
				}
			}
			return ans;
		}
		 Polynomial derivative() const
	    {
	        Polynomial result;
	
	        for (int i = 0; i < size; i++)
	        {
	            int power = term[i].getPower();
	            double coefficient = term[i].getCoefficient();
	
	            if (power != 0)
	            {
	                result.addTerm(
	                    coefficient * power,
	                    power - 1
	                );
	            }
	        }
	
	        return result;
	    }
		Polynomial antiDerivative() const
	    {
	        Polynomial result;
	
	        for (int i = 0; i < size; i++)
	        {
	            double coefficient = term[i].getCoefficient();
	            int power = term[i].getPower();
	
	            result.addTerm(
	                coefficient / (power + 1),
	                power + 1
	            );
	        }
	
	        int randomConstant = rand() % 21 - 10;
	
	        result.addTerm(randomConstant, 0);
	
	        return result;
	    }
	    void addTocoefficient(double coeff, int power)
	    {
	    	if(power < 0)
	    	{
	    		throw "power less than 0";
			}
			int index = findPower(power);
			if(index != -1)
			{
				double ncoff = term[index].getCoefficient()+coeff;
				term[index].setCoefficient(ncoff);
				if(ncoff == 0)
				{
					for(int i=index; i<size-1; i++)
					{
						term[i] = term[i+1];
					}
					size--;
				}
			}
			else
			{
				addTerm(coeff, power);	
			}
			sort();
		}
		void setCoefficient(double newCoefficient, int power)
	    {
	        if (power < 0)
	        {
	            throw "Power cannot be negative.";
	        }
	
	        int index = findPower(power);
	
	        if (index != -1)
	        {
	            term[index].setCoefficient(newCoefficient);
	
	            if (newCoefficient == 0)
	            {
	                for (int i = index; i < size - 1; i++)
	                {
	                    term[i] = term[i + 1];
	                }
	
	                size--;
	            }
	        }
	        else
	        {
	            addTerm(newCoefficient, power);
	        }
	
	        sort();
	    }
	    void clear()
	    {
	    	size = 0;
		}
		friend ostream& operator<<(ostream& out, const Polynomial& p);
};
ostream& operator<<(ostream& out, const Polynomial& p)
{
	if(p.size == 0)
	{
		out<<"0";
		return out;
	}
	for(int i=0; i<p.size; i++)
	{
		double coefficient = p.term[i].getCoefficient();
		int power = p.term[i].getPower();
		if(i>0)
		{
			out<<" + ";
		}
		if(power == 0)
		{
			out<<coefficient;
		}
		else if(power == 1)
		{
			out << coefficient <<"x";
		}
		else
		{
			out<<coefficient<<"x^";
		}
	}
	return out;
}
int main() {
	    try
    {
        Polynomial p1;

        p1.addTerm(4, 5);
        p1.addTerm(7, 3);
        p1.addTerm(-1, 2);
        p1.addTerm(9, 0);

        cout << "p1 = " << p1 << endl;

        cout << "Degree = "
             << p1.getDegree() << endl;

        cout << "Coefficient of x^3 = "
             << p1.getCoefficient(3) << endl;

        cout << "p1(2) = "
             << p1(2) << endl;


        Polynomial p2;

        p2.addTerm(6, 4);
        p2.addTerm(3, 2);
        p2.addTerm(2, 1);

        cout << "\np2 = " << p2 << endl;


        Polynomial p3 = p1 + p2;

        cout << "\np1 + p2 = "
             << p3 << endl;


        Polynomial p4 = p1 - p2;

        cout << "p1 - p2 = "
             << p4 << endl;


        Polynomial p5 = p1 * p2;

        cout << "p1 * p2 = "
             << p5 << endl;


        Polynomial p6 = p1.derivative();

        cout << "\nderivative of p1 = "
             << p6 << endl;


        Polynomial p7 = p6.antiDerivative();

        cout << "antiDerivative of derivative = "
             << p7 << endl;


        p1.addTocoefficient(2.5, 3);

        cout << "\nAfter addToCoefficient(2.5, 3): "
             << p1 << endl;


        p1.setCoefficient(-3, 7);

        cout << "After setCoefficient(-3, 7): "
             << p1 << endl;


        Polynomial copy(p1);

        cout << "\nCopy of p1 = "
             << copy << endl;


        Polynomial assigned;

        assigned = p1;

        cout << "Assigned polynomial = "
             << assigned << endl;


        p1.clear();

        cout << "\nAfter clear(): "
             << p1 << endl;
    }

    catch (const char* message)
    {
        cout << "Error: " << message << endl;
    }

    return 0;
}

