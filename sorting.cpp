#include <iostream>

#define BINARY_SORT

void swap(int& a, int&b);

void printArr(int arr[], int size);

int binarySearch(int arr[], const int n, const int val);

void insertionSort(int arr[], const int n);
void binarySort(int arr[], const int n);


int main(int argc, char** argv){

    #ifdef INSERT_SORT
        int arr[5] = {5, 3, 4, 1, 2};
        int arr_size = sizeof(arr)/(sizeof(arr[0]));

        std::cout << "Before Sort:" << std::endl;
        printArr(arr, arr_size);

        insertionSort(arr, arr_size);

        std::cout << "After Sort:" << std::endl;
        printArr(arr, arr_size);

    #endif

    #ifdef BINARY_SORT

    int arr[14] = {1489, 5, 492, 3, 4, 300, 1, 195, 2, 69, 8, 19234, 0, 9};
    // int arr[5] = {5, 3, 4, 1, 2};
    int arr_size = sizeof(arr)/(sizeof(arr[0]));

    std::cout << "Before Sort:" << std::endl;
    printArr(arr, arr_size);

    binarySort(arr, arr_size);

    std::cout << "After Sort:" << std::endl;
    printArr(arr, arr_size);

    #endif


    #ifdef MERGE_SORT



    #endif

    #ifdef HEAP_SORT



    #endif

    return 0;
}

int binarySearch(int arr[], const int n, const int val){
    int start = 0;
    int end = n;
    int mid;

    int itr = 0;
    while (start <= end){
        mid = start + (end - start)/2; //offset from the starting position
        std::cout << "Itr "<< itr << ", start: " << start << ", mid: " << mid << ", end: " << end << std::endl;
        
        if (arr[mid] == val){
            return mid;
        } 
        //Search the second half of the remaining array
        else if (val > arr[mid])  {
            start = mid + 1; //we already check arr[mid]
        }
        //Search the first half of the remaining array
        else {
            end = mid - 1; //we already check arr[mid]
        }
        itr++;
    }
    return -1;
}

/**
 * Sort algorithms 
 */

//O(n^2)
void insertionSort(int arr[], const int n){

    //Iterate through n elements
    for (int i = 0; i < n; i++){
        int j = i; 
        
        //IF: arr[j-1] > arr[j], then we swap the values, 
        //  since we want the smaller value to be in front, and
        //  we go on to compare for the rest of the sorted array.
        //ELSE: the order is correct and we move on to the next i.

        while ( (j > 0 ) && arr[j-1] > arr[j]){ //Iterate through (n-1) elements
            swap(arr[j-1], arr[j]); //move the smaller value forward within the sorted array
            j--; 
        }
    }
}

// O(n log (n))
void binarySort(int arr[], const int n){
    //mark the first element from A[1] as the key
    
    //Iterate through n elements
    for (int i = 1; i < n; i++){

        int key = arr[i];
        int j = i -1;
        int start = 0, end = j; //start and end should be in the sorted half of the array

        //Search takes O(log n)
        while (start <= end){
            int mid = start + (end - start)/2; 
            // std::cout << "key: " << key << ", start: " << start << ", mid: " << mid << ", end: " << end << std::endl;

            if (arr[i] > arr[mid])  {
                start = mid + 1; //we already check arr[mid]
            }
            else {
                end = mid - 1; //we already check arr[mid]
            }
        }
        
        int p = start;
        //shift the sorted array rightwards from position p
        while (j >= p){
            arr[j+1] = arr[j];
            j--;
        }

        //assign array to position p
        arr[p] = key; 

    }

}

/**
 * Helper functions
 */

void swap(int& a, int&b){
    int temp = a;
    a = b;
    b = temp;
}

void printArr(int arr[], int size){
    // std::cout << "Size of array: " << getArrSize(arr) << std::endl;
    for (int i = 0; i < size - 1; i++){
        std::cout << arr[i] << ", ";
    }

    std::cout << arr[size-1] << std::endl;

}



void merge(int arr[], int beg, int mid, int end){
    int output[end - beg + 1];

    int i = beg;
    int j = mid+1;
    int k = 0;

    while (i <= mid && j <= end){
        if (arr[i] <= arr[j]){
            output[k] = arr[i];
            i++;
        }
        else {
            output[k] = arr[j];
            j++;
        }
        k++;
    }

    //remaining elements add to output
    while (i <= mid){
        output[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end){
        output[k] = arr[j];
        j++;
        k++;
    }

    //copy output to original array
    for (i = beg; i <= end; i++){
        arr[i] = output[i - beg];
    }

}

void mergeSort(int arr[], int beg, int end){

    if (beg < end){
        int mid = (beg + end)/2;
        //divide and conquer
        mergeSort(arr, beg, mid); //divide first half
        mergeSort(arr, mid+1, end); //divide second half
        merge(arr, beg, mid, end);
    }



}