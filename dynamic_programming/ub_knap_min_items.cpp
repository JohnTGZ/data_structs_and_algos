#include <bits/stdc++.h>
#include <algorithm>

//k: Max weight
//items: items
int unboundedKnapsack(int k, std::vector<int> items) {
    
    std::vector<int> min_items(k+1, k+1);
    //we get the maximum value at each amount
    //which is made up of previous calculated values at smaller amounts
    min_items[0] = 0;

    //iterate through the amount
    for (int i = 1; i <= k; i++){
        //iterate through each item
        for (int j =0; j < items.size(); j++){
            //if item <= current amount 
            if (items[j] <= i){
                min_items[i] = std::min(min_items[i], min_items[i-items[j]] + 1);
            } 
        }
        std::printf("[%d]: %d \n", i, min_items[i]);
    }    
    
    return min_items[k] > k ? -1 : min_items[k];
    
}


int main() {
    int sum = 11;
    std::vector<int> arr {1,2,5};

    int num_ways = unboundedKnapsack(sum, arr);

    std::cout << "Min items required for sum==" << sum  << " is "<< num_ways << std::endl;

    return 0;
}
