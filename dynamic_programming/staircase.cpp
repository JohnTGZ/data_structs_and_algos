#include <bits/stdc++.h>
#include <algorithm>

//You have to build a staircase in such a way that, each type of staircase should consist of 
// 2 or more steps. No two steps are allowed to be at the same height — each step must be lower 
// than the previous one. All steps must contain at least one brick. A step’s height is 
// classified as the total amount of bricks that make up that step.

//returns number of ways stairs can be put together but 1-0
int staircaseFunc(int N){
    //the knapsack contains steps from 1 up to N-1
    
    std::vector<int> num_combi(N+1, 0);

    num_combi[0] = 1;

    //Iterate through the number of bricks
    for (int i = 1; i <= N; i++){
        //Iterate through the max height of the bricks
        for (int j = N; j >= i; j--){
            num_combi[j] += num_combi[j-i];
        }
    }

    return num_combi[N] - 1;

}


int main() {
    int N = 200;

    int num_ways = staircaseFunc(N);

    std::cout << "Number of ways: " << num_ways << std::endl;

    return 0;
}
