// /https://www.geeksforgeeks.org/coin-change-dp-7/
#include <bits/stdc++.h>
using namespace std;


int coin(vector<int> coins,int n,int total) {
    //base case
    if(total == 0)
        return 1;
    
    if(total < 0) return 0;
    
     if (n <=0 && total >= 1) 
        return 0;
    
    // Case 1. include current coin coins[n-1] in solution and recur
	// with remaining change (total - coins[n-1]) with same number of coins
	int include = coin(coins, n, total - coins[n-1]);

	// Case 2. exclude current coin coins[n] from solution and recur
	// for remaining coins (n - 1)
	int exclude = coin(coins, n - 1, total);

	// return total ways by including or excluding current coin
	return include + exclude;
   
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	vector<int> coins(n);
    	
    	for(int i = 0; i < n; i++)
    	    cin >> coins[i];
    	
    	int total;
    	cin >> total;
    	//Print number of possible ways to make change for 'total' cents.
            
        cout << coin(coins,n,total) << endl;
        
    	
    }
    return 0;
}



static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();