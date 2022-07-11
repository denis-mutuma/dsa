#include <bits/stdc++.h>
using namespace std;

// swap takes pointers to integers and swaps
// the content of the memory location
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort takes a reference to an array
// and sorts its contents in ascending order
void bubbleSort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (vec[j] > vec[i])
            {
                swap(&vec[j], &vec[i]);
            }
        }
    }
}

// prints a vector on one line
void printVector(vector<int> &vec)
{
    for (const int num : vec)
    {
        cout << num << ",";
    }
    cout << "\n";
}

int main()
{
    vector<int> vec{1, 3, 8, 2, 9, 2, 5, 6, -9};
    printVector(vec);
    bubbleSort(vec);
    printVector(vec);
}