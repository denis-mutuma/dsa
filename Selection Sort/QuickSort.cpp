#include <iostream>
#include <vector>

// swap takes pointers to two numbers
// and swaps the numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// this function assumes the last element of the array to be
// the pivot point and places it at its correct position in
// the sorted array with elements smaller than itself to the left
// and equal or larger elements to its right
int partition(std::vector<int> &vec, int low, int high)
{
    // take last element as the pivot
    int pivot = vec[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        // if element smaller than pivot
        // swap it with largest number seen so far
        if (vec[j] < pivot)
        {
            i++;
            swap(&vec[i], &vec[j]);
        }
    }
    // place the pivot at the correct index
    // and return the pivot index
    swap(&vec[i + 1], &vec[high]);
    return (i + 1);
}

// quicksort function sorts and vector in ascending order
void quickSort(std::vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(vec, low, high);
        quickSort(vec, low, partitionIndex - 1);
        quickSort(vec, partitionIndex + 1, high);
    }
}

// a function to print all the elements in a vector
void printVector(std::vector<int> &vec)
{
    for (int &num : vec)
    {
        std::cout << num << ",";
    }
    std::cout << "\n";
}

// program execution starts here
int main()
{
    std::vector<int> vec{-1, -15, 3, 6, 2, -10};
    printVector(vec);
    int n = vec.size();
    quickSort(vec, 0, n - 1);
    printVector(vec);
}