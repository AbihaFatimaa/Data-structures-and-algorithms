# include <iostream>
# include <string>
# include <fstream>
using namespace std;
class Matrix
{
	private:
		int row;
		int col;
		int ** data;
	public:
		Matrix()
		{
			row = 0;
			col = 0;
			data = nullptr;
		}
		Matrix(int row, int col)
		{
			this->row = row;
			this->col = col;
			data = new int* [row];
			for(int i=0; i<row; i++)
			{
				data[i] = new int [col];
				for(int j=0; j<col; j++)
				{
					data[i][j] = 0;
				}
			}
		}
		Matrix(const Matrix& m)
		{
			row = m.row;
			col = m.col;
			data = new int* [row];
			for(int i=0; i<row; i++)
			{
				data[i] = new int[col];
				for(int j=0; j<col; j++){
					data[i][j] = m.data[i][j];
				}
			}
		}
		~Matrix()
		{
			for(int i=0; i<row; i++)
			{
				delete[] data[i];
			}
			delete[] data;
		}
		Matrix& operator=(const Matrix& m)
		{
			 if (this != &m)
        {
             if (data != nullptr)
            {
                for (int i = 0; i < row; i++)
                {
                    delete[] data[i];
                }

                delete[] data;
            }

            row = m.row;
            col = m.col;

            data = new int*[row];

            for (int i = 0; i < row; i++)
            {
                data[i] = new int[col];

                for (int j = 0; j < col; j++)
                {
                    data[i][j] = m.data[i][j];
                }
            }
        }

        return *this;
		}
		int* operator[](int index)const
		{
			return data[index];
		}
		int getrow()const
		{
			return row;
		}
		int getcol()const
		{
			return col;
		}
		bool readfile(const char* filename)
		{
			ifstream file(filename);
			if(!file)
			{
				cout<<"error";
				return false;
			}
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
				{
					file>>data[i][j];
				}
			}
			file.close();
			return true;
		}
		void display()const
		{
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
				{
					cout<<data[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
		int nonzerocount()
		{
			int count = 0;
			for(int i=0; i<row; i++)
			{
				for(int j=0; j<col; j++)
				{
					if(data[i][j] != 0)
					{
						count++;
					}
				}
			}
			return count;
		}
};

class sparseMatrix
{
	private:
		Matrix matrix;
		int nonzero;
		int* row;
		int* col;
		int* data;
	public:
		sparseMatrix(const Matrix& m)
		{
			matrix = m;
			nonzero = matrix.nonzerocount();
			if(nonzero > 0)
			{
				row = new int[nonzero];
				col = new int[nonzero];
				data = new int[nonzero];
				
				int k=0;
				int r = matrix.getrow();
				int c = matrix.getcol();
				for(int i=0; i<r; i++)
				{
					for(int j=0; j<c; j++)
					{
						if(matrix[i][j] != 0)
						{
							row[k] = i;
							col[k] = j;
							data[k] = matrix[i][j];
							k++; 
						}
					}
				}
			}
			else
			{
				row = nullptr;
				col = nullptr;
				data = nullptr;
			}
		}
		sparseMatrix(const sparseMatrix& other)
    {
        matrix = other.matrix;

        nonzero = other.nonzero;

        if (nonzero > 0)
        {
            row = new int[nonzero];
            col = new int[nonzero];
            data = new int[nonzero];

            for (int i = 0; i < nonzero; i++)
            {
                row[i] = other.row[i];
                col[i] = other.col[i];
                data[i] = other.data[i];
            }
        }
        else
        {
            row = nullptr;
            col = nullptr;
            data = nullptr;
        }
    }
    ~sparseMatrix()
    {
    	delete[] row;
    	delete[] col;
    	delete[] data;
	}
	void displayOriginal() const
    {
        matrix.display();
    }
    void displaySparse()
    {
    	for(int i=0; i<nonzero; i++)
    	{
    		cout<<row[i]<<" "<<col[i]<<" "<<data[i]<<" \n";
		}
	}
    sparseMatrix add(const sparseMatrix& other) const
    {
        int rows = matrix.getrow();
        int cols = matrix.getcol();
        
        Matrix result(rows, cols);


        for (int i = 0; i < nonzero; i++)
        {
            result[row[i]][col[i]] = data[i];
        }


        for (int i = 0; i < other.nonzero; i++)
        {
            result[other.row[i]][other.col[i]]
                += other.data[i];
        }


        sparseMatrix resultSparse(result);

        return resultSparse;
    }


};
int main()
{
    int rows = 3;
    int cols = 3;


    // --------------------------------------------------
    // Create two Matrix objects
    // --------------------------------------------------

    Matrix A(rows, cols);
    Matrix B(rows, cols);


    // --------------------------------------------------
    // Read matrices from separate files
    // --------------------------------------------------

    if (!A.readfile("matrixA.txt"))
    {
        return 1;
    }

    if (!B.readfile("matrixB.txt"))
    {
        return 1;
    }


    // --------------------------------------------------
    // Display original matrices
    // --------------------------------------------------

    cout << "================ MATRIX A ================" << endl;
    A.display();

    cout << endl;

    cout << "================ MATRIX B ================" << endl;
    B.display();


    // --------------------------------------------------
    // Convert to SparseMatrix
    // --------------------------------------------------

    sparseMatrix sp_A(A);
    sparseMatrix sp_B(B);


    // --------------------------------------------------
    // Display sparse matrices
    // --------------------------------------------------

    cout << endl;
    cout << "============ SPARSE MATRIX A ============" << endl;
    sp_A.displaySparse();

    cout << endl;

    cout << "============ SPARSE MATRIX B ============" << endl;
    sp_B.displaySparse();


    // --------------------------------------------------
    // Add sparse matrices
    // --------------------------------------------------

    sparseMatrix sp_C = sp_A.add(sp_B);


    // --------------------------------------------------
    // Display result
    // --------------------------------------------------

    cout << endl;
    cout << "========== RESULT OF ADDITION ==========" << endl;

    sp_C.displayOriginal();

    cout << endl;

    cout << "========== RESULT AS SPARSE MATRIX ==========" << endl;

    sp_C.displaySparse();


    return 0;
}
