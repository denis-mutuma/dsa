// Merge sort in C++

#include <iostream>
#include <vector>

// This function sorts the sub-arrays and merges them into one array
std::vector<int> merge(std::vector<int> &vec, int lb, int mid, int ub)
{
    // initialize the size of the sub-arrays
    int n1 = mid - lb + 1;
    int n2 = ub - mid;

    // create two arrays to represent the left "L" and right "R" sub-arrays
    // where L = vec[lb...mid] and R = vec[mid+1...ub]
    std::vector<int> L(n1), R(n2);

    // populate the sub-arrays
    for (int i = 0; i < n1; i++)
    {
        L[i] = vec[lb + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = vec[mid + j + 1];
    }

    // track the index of sub-arrays and the larger array
    int i = 0, j = 0, k = lb;

    // loop until you reach the end of L or R and push the smaller
    // element of L[i] of R[j] into the main array
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    // push remaining elements of L into main array if any
    while (i < n1)
    {
        vec[k] = L[i];
        i++;
        k++;
    }
    // push remaining elements of R into main array if any
    while (j < n2)
    {
        vec[k] = R[j];
        j++;
        k++;
    }
    // return the input array
    return vec;
}

// divide the input array into sub-arrays and sort the sub-arrays
// then merge them to form a sorted array
void mergeSort(std::vector<int> &vec, int lb, int ub)
{
    // the exit condition
    if (lb >= ub)
    {
        return;
    }
    // we divide the array at the index mid
    int mid = lb + (ub - lb) / 2;

    // divide the input array into two sub-arrays at the index mid
    mergeSort(vec, lb, mid);
    mergeSort(vec, mid + 1, ub);

    // merge the sorted sub-arrays
    merge(vec, lb, mid, ub);
}

// a function to print the vector
void printVector(std::vector<int> &vec)
{
    for (const int num : vec)
    {
        std::cout << num << ",";
    }
    std::cout << "\n";
}

// the entry point of our program
int main()
{
    std::vector<int> vec{150, 5, 24, 8, 1, 3, 16, 10, 20, -2};
    printVector(vec);
    mergeSort(vec, 0, vec.size() - 1);
    printVector(vec);
}