//https://www.spoj.com/problems/KNAPSACK/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//memoized1 & memoized2 shall be same, bcz effectively , we are making recursive calls on varying capacity & currentindex

int wcapacity, n;
vector<int> profits(1000);
vector<int> weights(1000);
int knapsackRecursive(int ans, int i, vector<vector<int>> dp)
{
    //cout <<"hey\n";
    //base case
    if(i >= n || ans >= wcapacity)
        {
          //  cout <<"base";
            dp[ans][i] = ans;
            return ans;
        }

    int exc = knapsackRecursive(ans,i+1,dp);
    //include or exclude ith weight
    if(ans + weights[i] >= wcapacity)
        {
           dp[ans][i] = exc;
          return exc;
        }

    int inc = knapsackRecursive(ans+profits[i],i+1,dp);
     dp[ans][i] = max(inc,exc);
        return dp[ans][i];

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
    int maxProfit = knapsackRecursive(0,0,dp);
    cout << maxProfit;

    return 0;
}
