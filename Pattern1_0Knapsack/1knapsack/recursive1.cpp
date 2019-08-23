//https://www.spoj.com/problems/KNAPSACK/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Include ans parameter

int wcapacity, n;
vector<int> profits(1000);
vector<int> weights(1000);
int knapsackRecursive(int ans, int i)
{
    cout <<"hey\n";
    //base case
    if(i >= n || ans >= wcapacity)
        {
            cout <<"base";
            return ans;
        }

    int exc = knapsackRecursive(ans,i+1);
    //include or exclude ith weight
    if(ans + weights[i] >= wcapacity)
        return exc;

    int inc = knapsackRecursive(ans+profits[i],i+1);
        return max(inc,exc);

}

int main()
{
    cin >> wcapacity;
    cin >> n;
    for (int i = 0; i < n; i++)
        {
            cout << i << "wtpro \n";
            cin >> weights[i] >> profits[i];
        }

    //given W(s) , maximize profit
    int maxProfit = knapsackRecursive(0,0);
    cout << maxProfit;

    return 0;
}

