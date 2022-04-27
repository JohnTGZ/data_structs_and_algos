#include <bits/stdc++.h>
#include <algorithm>


int Knapsack01(int N, std::vector<int> items_weight, std::vector<int> items_value){
    //the knapsack contains steps from 1 up to N-1
    
    //Create 2 dimensional array M[i][j]
    //  where i = steps of up to height i that will be used
    //  where j = max steps
    // [i][j] is the max value that can be attained with items up to i with total weight at j
    std::vector<std::vector<int>> M( N, std::vector<int>( N+1, 0));

    //max value with 0 items == 0
    for (int j = 1; j <= N; j++){
        M[0][j] = 0;
    }

    //max value at desired weight == 0
    for (int i = 1; i < N; i++){
        M[i][0] = 0;
    }

    //iterate through the weight of the items to be used
    for (int i = 1; i <= N - 1; i++){
        //iterate through the max weight
        for (int j = 1; j <= N; j++){
            //if current item's weight less than total weight
            if (i <= j){
                //take the max of:
                //A: the previous set of items at current weight
                //B: The previous set of items at (current weight - current item's weight) + current item value
                M[i][j] = std::max(M[i-1][j], M[i-1][j-items_weight[i]] + items_value[i]);
            }
            else {
                //take the value of the previous item
                M[i][j] = M[i-1][j];
            }
        }
    }

    return M[N-1][N];
}



int main() {
    int N = 5;
    std::vector<int> arr_weight;
    std::vector<int> arr_value;

    int num_ways = Knapsack01(N, arr);

    std::cout << "Number of ways: " << num_ways << std::endl;

    return 0;
}
