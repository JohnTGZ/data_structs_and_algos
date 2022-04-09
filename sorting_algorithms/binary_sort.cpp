/**
 * @file binary_sort.cpp
 * @author John Tan (johnchenguanzhong@gmail.com)
 * @brief Insertion sort 
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */



//Description
//We maintain 2 subarrays: an sorted and unsorted subarray.
//One element from the unsorted subarray finds its correct position in the sorted subarray and gets inserted there.

//Time complexity
//  Average case
//      THETA(nlog n)
//  Worst case: array is reversely sorted, and the maximum number of comparisons and swapping has to be performed.
//      O(nlog n)
//  Best Case: array is already sorted, then only the outer loop is executed n times.
//      OMEGA(n)

//Space complexity
//  O(n) because no extra memory other than a placeholder variable is required.

//References
//[1] https://www.delftstack.com/tutorial/algorithm/binary-sort/

#include <iostream>

void printArray(int* arr, const int n){
    std::cout << "Array: ";
    for (int i = 0; i < n; i ++){
        if (i > 0){
            std::cout << " ";
        }
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

//Swaps elements at index m and n of an array
void swapArrayElems(int* arr, int m, int n){
    int temp_var = arr[m];
    arr[m] = arr[n];
    arr[n] = temp_var;
}

//Shifts array positions from m to n upwards by one index
void shiftArrayElemsUpByOne(int* arr, int m, int n){
    for (int idx = n; n > m; n--){
        //assign to current position the value before it 
        arr[n] = arr[n-1];
    }
}

//Finds correct position "p" of give value "val" inside array "arr" of size "n"
int binarySearch(int* arr, const int n, const int val){
    int low = 0;
    int high = n-1;
    while (low < high){
        int mid = low + (high - low)/2;
        if (arr[mid] == val){
            return mid;
        } 
        else if (arr[mid] < val) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}


int binarySearchForSort(int* arr, const int n, int low, int high, const int val){
    int mid = low;
    while (low < high){
        mid = low + (high - low)/2;
        if (arr[mid] < val) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return (val > arr[low]) ? low+1 : low;
}


void BinarySort(int* arr, const int n ){
    //us_idx: unsorted subarray index
    //s_idx: key correspodning to unsorted subarray index, being compared and sorted into the right place in the sorted subarray

    for (int us_idx = 1; us_idx < n; us_idx++){
        std::cout << "============ \n";
        printArray(arr, n);

        int us_key = arr[us_idx];

        //Use binary search to find the correct position p of us_key inside sorted subarray
        int p = binarySearchForSort(arr, n, 0, us_idx, us_key);
        shiftArrayElemsUpByOne(arr, p, us_idx);
        arr[p] = us_key;
        std::cout << "============ \n";
    }

    return;
}

int main(int argc, char** argv){
    // int arr1[] = {5,4,3,2,1};
    // BinarySort(arr1, sizeof(arr1)/sizeof(arr1[0]));
    // printArray(arr1, sizeof(arr1)/sizeof(arr1[0]));

    // int arr2[] = {15, 2, 63, 3, 7};
    // BinarySort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    // printArray(arr2, sizeof(arr2)/sizeof(arr2[0]));

    int arr3[] = {15, 999, 2, 63, 3, 100, 51, 7, 1, 8, 4, 2502};
    BinarySort(arr3, sizeof(arr3)/sizeof(arr3[0]));
    printArray(arr3, sizeof(arr3)/sizeof(arr3[0]));

    return 0;
}
