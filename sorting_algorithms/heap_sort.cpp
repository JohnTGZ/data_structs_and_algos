/**
 * @file heap_sort.cpp
 * @author John Tan (johnchenguanzhong@gmail.com)
 * @brief Heap sort 
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//Description

//Time complexity
//  Average case: O(nlog n)
//      
//  Worst case: O(nlog n)
//  Best Case: O(nlog n)

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


void heapify(int* arr, const int n, int i){
    //initialize parent index with index of the current element
    int parent_idx = i;

    //compute leftchild and rightchild as (2*i + 1) and (2*i + 2) respectively
    int leftchild_idx = (2*i + 1); 
    int rightchild_idx = (2*i + 2);

    //Set parent index to the largest value

    //IF arr[leftchild_idx] > arr[parent_idx], set parent index to left child
    if (leftchild_idx < n && arr[leftchild_idx] > arr[parent_idx]){
        parent_idx = leftchild_idx;
    }
    //IF arr[rightchild_idx] > arr[parent_idx], set parent index to right child
    if (rightchild_idx < n && arr[rightchild_idx] > arr[parent_idx]){
        parent_idx = rightchild_idx;
    }

    if (parent_idx != i){
        //if parent index has changed in last 2 steps, then swap parent with the current element 
        //This is to make sure that the largest value is always a parent of a smaller value
        swapArrayElems(arr, i, parent_idx);
        //recursively heapify the parent index subtree
        heapify(arr, n, parent_idx);
    }
    return;

}

void heapSort(int* arr, const int n){
    for (int i = n/2 - 1; i >= 0; i--){
        //Build a max heap with elements present inside array A
        heapify(arr, n, i);
    }
    printArray(arr, n);
    //for every element starting from the last element in A do the following
    for (int i = n -1 ; i >= 0; i--){
        //A[0] contains the maximum element, swap it with this element
        swapArrayElems(arr, i, 0);
        //reduce heap size by one 
        //Heapify() the max heap with the last element removed;
        heapify(arr, i, 0);
    }
}


int main(int argc, char** argv){
    int arr1[] = {5,4,3,2,1};
    heapSort(arr1, sizeof(arr1)/sizeof(arr1[0]));
    printArray(arr1, sizeof(arr1)/sizeof(arr1[0]));

    int arr2[] = {15, 2, 63, 3, 7};
    heapSort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    printArray(arr2, sizeof(arr2)/sizeof(arr2[0]));

    int arr3[] = {15, 999, 2, 63, 3, 100, 51, 7, 1, 8, 4, 2502};
    heapSort(arr3, sizeof(arr3)/sizeof(arr3[0]));
    printArray(arr3, sizeof(arr3)/sizeof(arr3[0]));

    return 0;
}
