#include <iostream>

void Heapify(int arr[], int i){
    //initialize parent index with index of current element
    //Compute leftchild as (2*i+1) and rightchild as (2*i+2)
    int parent = i;
    leftChild_idx = 2*i+1;
    rightChild_idx = 2*i+2;

    if (leftChild_idx < n && arr[leftChild_idx] > arr[parent]){
        parent = leftChild_idxl;
    } 
    else if (rightChild_idx < n && arr[rightChild_idx] > arr[parent]){
        parent = rightChild_idx;
    }

    if (parent != i){
        //swap parent with current element
        swap(arr[parent], arr[i])
        heapify(arr, parent)
    }
    
}

void heapSort(int arr[], int n){
    //Build max heap with A

    //last non-leaf node is the parent of the last node
    //so we start from there
    for (int i = (n/2 - 1); i >= 0; i-- ){
        heapify(arr, n, i);
    }

    //for every element starting from last element in A
    for (int i = n- 1; i >=0 ; i-- ){
    //  the root element[0] will contain maximum element, swap with this element
        swap(arr[0], arr[i]);
        //  Reduce heap size by one and heapify the max heap with last element removed
        // This leads to  the max element again being at position 0
        heapify(arr, i, 0);
    }

}


int main(){

    // int arr[6] = {3, 2, 1 , 5, 12, 8};
    // int arr[6] = {3, 2, 1 , 5, 4, 6};
    int arr[5] = {5, 4, 1, 2, 3};
    // int arr[2] = {3,2};

    int arr_size = sizeof(arr) /(sizeof(arr[0])); 
    // std::printf("arr_size: %d \n", arr_size);

    std::cout << "Before sorted: " << std::endl;
    printArr(arr, 0, arr_size-1);

    // heapSort();

    std::cout << "Final sorted: " << std::endl;
    printArr(arr, 0, arr_size-1);

    return 0;

}