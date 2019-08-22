//https://www.spoj.com/problems/KNAPSACK/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

  int knapsackRecursive(vector<vector<int>> &dp, const vector<int> &profits,
                        const vector<int> &weights, int capacity, int currentIndex) {
    // base checks
    if (capacity <= 0 || currentIndex >= profits.size()) {
      return 0;
    }

    // if we have already solved a similar problem, return the result from memory
    if (dp[currentIndex][capacity] != -1) {
      return dp[currentIndex][capacity];
    }

    // recursive call after choosing the element at the currentIndex
    // if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
    int profit1 = 0;
    if (weights[currentIndex] <= capacity) {
      profit1 = profits[currentIndex] + knapsackRecursive(dp, profits, weights,
                                                          capacity - weights[currentIndex],
                                                          currentIndex + 1);
    }

    // recursive call after excluding the element at the currentIndex
    int profit2 = knapsackRecursive(dp, profits, weights, capacity, currentIndex + 1);

    dp[currentIndex][capacity] = max(profit1, profit2);
    return dp[currentIndex][capacity];
  }

int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    vector<vector<int>> dp(profits.size(), vector<int>(capacity + 1, -1));
    return knapsackRecursive(dp, profits, weights, capacity, 0);
  }



int main() {
	// your code goes here
	int s,n;
	cin >> s;
	cin >> n;
	vector<int> profits(n);
	vector<int> weights(n);
	for(int i = 0; i < n; i++)
		cin >> weights[i] >> profits[i];

	//given W(s) , maximize profit
	 int maxProfit = solveKnapsack(profits, weights, s);
	 cout << maxProfit;



	return 0;
}
