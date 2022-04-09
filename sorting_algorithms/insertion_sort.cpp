/**
 * @file insertion_sort.cpp
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
//      THETA(n**2)
//  Worst case: array is reversely sorted, and the maximum number of comparisons and swapping has to be performed.
//      O(n**2)
//  Best Case: array is already sorted, then only the outer loop is executed n times.
//      OMEGA(n)

//Space complexity
//  O(n) because no extra memory other than a placeholder variable is required.

//References
//[1] https://www.delftstack.com/tutorial/algorithm/insertion-sort/

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


void insertionSort(int* arr, const int n ){
    
    //Iterate from arr[1] to arr[n-1];
    for (int us_key_index = 1; us_key_index < n; us_key_index++){
        std::cout << "==========\n";
        printArray(arr, n);

        int unsorted_key = arr[us_key_index]; //key to compare against from unsorted array

        //iterate through the rest of the sorted keys
        for (int s_key_index = us_key_index -1 ; s_key_index >= 0; s_key_index--){


            int sorted_key = arr[s_key_index]; //key to compare against from sorted array

            //if unsorted_key is greater than sorted_key, then we insert after sorted_key
            //This is done by shifting all the elements of sorted array from s_key_index to us_key_index up one place, 
            //and moving the unsorted_key into the right position
            if (unsorted_key > sorted_key){
                shiftArrayElemsUpByOne(arr, s_key_index, us_key_index);
                arr[s_key_index+1] = unsorted_key;
                break;
            }
            //if unsorted_key smaller than sorted_key, compare with the element before sorted_key
            else {
                //if already at the beginning of sorted array, then shift the elements up 
                if (s_key_index == 0){
                    shiftArrayElemsUpByOne(arr, s_key_index, us_key_index);
                    arr[s_key_index] = unsorted_key;
                    break;
                }
            }

        }

        std::cout << "==========\n";
    }


    return;
}

int main(int argc, char** argv){
    // int arr1[] = {5,4,3,2,1};
    // insertionSort(arr1, sizeof(arr1)/sizeof(arr1[0]));
    // printArray(arr1, sizeof(arr1)/sizeof(arr1[0]));

    // int arr2[] = {15, 2, 63, 3, 7};
    // insertionSort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    // printArray(arr2, sizeof(arr2)/sizeof(arr2[0]));

    int arr3[] = {15, 999, 2, 63, 3, 100, 51, 7, 1, 8, 4, 2502};
    insertionSort(arr3, sizeof(arr3)/sizeof(arr3[0]));
    printArray(arr3, sizeof(arr3)/sizeof(arr3[0]));

    return 0;
}
