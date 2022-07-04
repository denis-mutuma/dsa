#include <bits/stdc++.h>

// swap takes pointers to numbers
// in an array an swaps the numbers
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// selection sort sorts an array in ascending order
void selectionSort(std::vector<int> &vec)
{
    for (int step = 0; step < vec.size(); step++)
    {
        // take current number as the smallest number
        // and use it's index
        int min_index = step;
        for (int j = step + 1; j < vec.size(); j++)
        {
            // if number at current iteration is smaller than
            // smallest number, update index of smallest number
            if (vec[j] < vec[min_index])
            {
                min_index = j;
            }
        }
        // swap number at current index with smallest number
        swap(&vec[min_index], &vec[step]);
    }
}

// a function to print the contents of a vector
void printVector(std::vector<int> &vec)
{
    for (int &num : vec)
    {
        std::cout << num << ",";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> arr{-1, 5, 3, 6, 2, 10};
    printVector(arr);
    selectionSort(arr);
    printVector(arr);
}