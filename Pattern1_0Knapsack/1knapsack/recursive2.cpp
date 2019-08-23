//https://www.spoj.com/problems/KNAPSACK/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Manage in capacity parameter

int wcapacity, n;
vector<int> profits(1000);
vector<int> weights(1000);
int knapsackRecursive(int wcapacity, int i)
{
    cout <<"hey\n";
    //base case
    if(i >= n || wcapacity <= 0)
        {
            cout <<"base";
            return 0;
        }

    int exc = knapsackRecursive(wcapacity,i+1);
    //include or exclude ith weight
    if(weights[i] >= wcapacity)
        return exc;

    int inc = profits[i] + knapsackRecursive(wcapacity-profits[i],i+1);
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
    int maxProfit = knapsackRecursive(wcapacity,0);
    cout << maxProfit;

    return 0;
}

