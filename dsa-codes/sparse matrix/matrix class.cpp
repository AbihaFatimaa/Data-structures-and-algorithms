# include <iostream>
# include <string>
using namespace std;
class matrix
{
	private:
		int value;
		int nonzero;
		int **m;
		int row, col;
	public:
		matrix(int r=2, int c=2)
		{
			row = r; 
			col = c;
			nonzero=0;
			m = new int *[row];
			for(int i=0; i<row; i++)
			{
				m[i] = new int[col];
				for(int j=0; j<col; j++)
				{
					m[i][j] = 0;
				}
			}
		}
		~matrix()
		{
			for (int i=0; i<row; i++)
			{
				delete[] m[i];
			}
			delete[] m;
		}
		void input()
		{
			cout<<"enter "<<row*col<<" values for the matrix: \n";
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
				{
					cin>>m[i][j];
				}
			}
		}
		void display()
		{
			cout<<"Values in the matrix are: \n";
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
				{
					cout<<m[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
		int getNonZerocount()
		{
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
				{
					if(m[i][j] != 0)
					{
						nonzero++;
					}
				}
			}
			return nonzero;
		}
		matrix(const matrix &other) {
            row = other.row;
            col = other.col;
            nonzero = other.nonzero;
            m = new int*[row];
            for(int i=0; i<row; i++) {
                m[i] = new int[col];
                for(int j=0; j<col; j++) {
                    m[i][j] = other.m[i][j];
                }
            }
        }
		bool isparse()
		{
			if(nonzero < (row*col/2))
			{
				return true;
			}
			return false;
		}
		matrix& operator=(const matrix &other) {
            if (this == &other) return *this;

            for (int i=0; i<row; i++) {
                delete[] m[i];
            }
            delete[] m;

            row = other.row;
            col = other.col;
            nonzero = other.nonzero;
            m = new int*[row];
            for(int i=0; i<row; i++) {
                m[i] = new int[col];
                for(int j=0; j<col; j++) {
                    m[i][j] = other.m[i][j];
                }
            }
            return *this;
        }

		matrix transpose(const matrix &o)
        {
            matrix p(o.col, o.row);
            for(int i=0; i<o.col; i++)
            {
                for(int j=0; j<o.row; j++)
                {
                    p.m[i][j] = o.m[j][i]; 
                }
            }
            return p;
        }
};
int main() {
	
	matrix m(3, 2);
	m.input();
	m.display();
	cout<<"is sparse: "<<m.isparse()<<"\n";
	cout<<"non zero: "<<m.getNonZerocount()<<"\n";
	matrix p = m.transpose(m);
//	p =(m.transpose(m));
	p.display();
	return 0;
	   }
