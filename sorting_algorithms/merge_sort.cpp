/**
 * @file merge_sort.cpp
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

void merge(int*arr, const int n){
    int output[n];
    //
    
    //

}



void mergeSort(int* arr, int beg, int end ){

    int mid = (beg+end)/2;

    //break up array into 2 parts arr[beg,...,mid], and arr[mid+1,...,end]
    mergeSort(arr, beg, mid);
    mergeSort(arr, mid+1, end);

    //repeatedly divide array into subarrays with single elements using recursion

    //call the merge function to start building the sorted array
    merge()

    return;
}

int main(int argc, char** argv){
    int arr1[] = {5,4,3,2,1};
    mergeSort(arr1, sizeof(arr1)/sizeof(arr1[0]));
    printArray(arr1, sizeof(arr1)/sizeof(arr1[0]));

    // int arr2[] = {15, 2, 63, 3, 7};
    // mergeSort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    // printArray(arr2, sizeof(arr2)/sizeof(arr2[0]));

    // int arr3[] = {15, 999, 2, 63, 3, 100, 51, 7, 1, 8, 4, 2502};
    // mergeSort(arr3, sizeof(arr3)/sizeof(arr3[0]));
    // printArray(arr3, sizeof(arr3)/sizeof(arr3[0]));

    return 0;
}
