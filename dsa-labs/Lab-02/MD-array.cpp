#include <iostream>
using namespace std;

class NDarray
{
private:
    int *size;          // Size of each dimension
    int *lowerBound;    // Starting index of each dimension
    int dim;            // Number of dimensions
    int totalSize;      // Total number of elements
    int *arr;           // 1D array for storing data

public:

    // Constructor
    NDarray(int dim, int size[], int lowerBound[])
    {
        this->dim = dim;

        // Allocate arrays for dimension information
        this->size = new int[dim];
        this->lowerBound = new int[dim];

        totalSize = 1;

        for(int i = 0; i < dim; i++)
        {
            this->size[i] = size[i];
            this->lowerBound[i] = lowerBound[i];

            totalSize *= size[i];
        }

        // Allocate 1D array
        arr = new int[totalSize];

        // Initialize all values to 0
        for(int i = 0; i < totalSize; i++)
        {
            arr[i] = 0;
        }
    }

    // Destructor
    ~NDarray()
    {
        delete[] size;
        delete[] lowerBound;
        delete[] arr;
    }

    // Calculate Row-Major index
    int calculateIndex(int index[])
    {
        int ind = 0;

        for(int i = 0; i < dim; i++)
        {
            // Check whether index is valid
            if(index[i] < lowerBound[i] ||
               index[i] >= lowerBound[i] + size[i])
            {
                return -1;
            }

            // Row-major calculation
            ind = ind * size[i] + (index[i] - lowerBound[i]);
        }

        return ind;
    }

    // Set value at given index
    void setValue(int index[], int val)
    {
        int ind = calculateIndex(index);

        if(ind == -1)
        {
            cout << "Index does not exist!" << endl;
            return;
        }

        arr[ind] = val;
    }

    // Get value at given index
    int getValue(int index[])
    {
        int ind = calculateIndex(index);

        if(ind == -1)
        {
            cout << "Index does not exist!" << endl;
            return -1;
        }

        return arr[ind];
    }

    // Display the complete 1D array
    void display()
    {
        for(int i = 0; i < totalSize; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};


int main()
{
    // Number of dimensions
    int dim_size[3] = {5, 3, 10};

    // Starting index of each dimension
    int lowerBound[3] = {1, 1, 1};

    // Create 3D array
    NDarray arr(3, dim_size, lowerBound);

    // Index to access
    int indexset[3] = {4, 2, 8};

    // Calculate row-major index
    cout << "Calculated Index: "
         << arr.calculateIndex(indexset)
         << endl;

    // Set value
    arr.setValue(indexset, 3);

    // Get value
    cout << "Value: "
         << arr.getValue(indexset)
         << endl;

    // Another index
    int indexset2[3] = {1, 2, 3};

    arr.setValue(indexset2, 8);

    cout << "Value: "
         << arr.getValue(indexset2)
         << endl;

    return 0;
}