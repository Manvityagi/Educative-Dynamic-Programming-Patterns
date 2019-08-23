//https://www.spoj.com/problems/KNAPSACK/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Manage in capacity parameter
//memoized1 & memoized2 shall be same, bcz effectively , we are making recursive calls on varying capacity & currentindex


int wcapacity, n;
vector<int> profits(1000);
vector<int> weights(1000);
int knapsackRecursive(int wcapacity, int i, vector<vector<int>> dp)
{
   // cout <<"hey\n";
    //base case
    if(i >= n || wcapacity <= 0)
        {
          //  cout <<"base";
             dp[wcapacity][i] = 0;
            return 0;
        }

    int exc = knapsackRecursive(wcapacity,i+1,dp);
    //include or exclude ith weight
    if(weights[i] >= wcapacity)
        {
            dp[wcapacity][i] = exc;
            return exc;
        }

    int inc = profits[i] + knapsackRecursive(wcapacity-profits[i],i+1,dp);
       
           dp[wcapacity][i] = max(inc,exc);
           return dp[wcapacity][i];
       

}

int main()
{
    cin >> wcapacity;
    cin >> n;
vector<vector<int>> dp(wcapacity+1, vector<int>(n,-1));

    for (int i = 0; i < n; i++)
        {
            cout << i << "wtpro \n";
            cin >> weights[i] >> profits[i];
        }

    //given W(s) , maximize profit
    int maxProfit = knapsackRecursive(wcapacity,0,dp);
    cout << maxProfit;

    return 0;
}

