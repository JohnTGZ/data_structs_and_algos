/**
 * @file quick_sort.cpp
 * @author John Tan (johnchenguanzhong@gmail.com)
 * @brief Insertion sort 
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */



//Description

//Time complexity
//  Average case: Recursive algorithm: T(n) = 2T(n/2) + THETA(n)
//      
//  Worst case: O(nlogn) 
//  Best Case: O(nlogn)

//Space complexity
//  O(n) because n auxiliary space is requred for storing the sorted subaray in the auxiliary array

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

int partition(int* arr, int beg, int end){
    //select last element as the pivot element
    int pivot = arr[end];
    //initialize value of point i to (beg-1) so that we can move elements
    //smaller than pivot to starting of array
    int i = beg - 1; //i will always point to a value smaller than the pivot but before the pivot index
    for (int j = beg; j < end;j++){
        if (arr[j] < pivot){
            i++; 
            swapArrayElems(arr, i, j );
        }
    }
    swapArrayElems(arr, i+1, end);

    return i+1;
}

void quickSort(int* arr, int beg, int end ){

    
    if (beg < end){
        ///Select pivot index pi
        int pi = partition(arr, beg, end);
        //recursively sort elements on left side of pivot
        quickSort(arr, beg, pi-1);
        //recursively sort elements on right side of pivot
        quickSort(arr, pi+1, end);

    }

}

int main(int argc, char** argv){
    int arr1[] = {5,4,3,2,1};
    quickSort(arr1, 0, sizeof(arr1)/sizeof(arr1[0]) -1);
    printArray(arr1, sizeof(arr1)/sizeof(arr1[0]));

    int arr2[] = {15, 2, 63, 3, 7};
    quickSort(arr2, 0, sizeof(arr2)/sizeof(arr2[0])-1);
    printArray(arr2, sizeof(arr2)/sizeof(arr2[0]));

    int arr3[] = {15, 999, 2, 63, 3, 100, 51, 7, 1, 8, 4, 2502};
    quickSort(arr3, 0, sizeof(arr3)/sizeof(arr3[0])-1);
    printArray(arr3, sizeof(arr3)/sizeof(arr3[0]));

    return 0;
}
