#include <bits/stdc++.h>
#include <algorithm>

int unboundedKnapsack(int k, vector<int> arr) {
    
    std::vector<int> sum(k+1, 0);
    //we get the maximum value at each amount
    //which is made up of previous calculated values at smaller amounts
    
    //iterate through the amount
    for (int i = 1; i <= k; i++){
        //iterate through each item
        for (int j =0; j < arr.size(); j++){
            //if item <= current amount 
            if (arr[j] <= i){
                sum[i] = std::max(sum[i], sum[i-arr[j]] + arr[j]);
            }
        }
    }    
    std::cout << sum[k] << std::endl;
    
    return sum[k];
    
}


void getCombi(int amount, std::vector<int> set){
    
    int sum = amount;
    for (int i = 0; i < set.size(); i++){
        int num_set = 0;
        while (sum > 0){
            sum = sum - set[i];
            num_set++;
        }

    }

}









int main() {
    int N = 5;

    int num_ways = staircaseFunc(N);

    std::cout << "Number of ways: " << num_ways << std::endl;

    return 0;
}
