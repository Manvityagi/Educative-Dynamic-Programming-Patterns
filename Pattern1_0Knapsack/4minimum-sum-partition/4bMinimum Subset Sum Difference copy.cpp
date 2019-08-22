//https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
//https://www.techiedelight.com/minimum-sum-partition-problem/

//Recursion - TLE

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int minPartition(vector<int>S, int n, int S1, int S2)
{
	// base case: if list becomes empty, return the absolute
	// difference between two sets
	if (n < 0)
		return abs(S1 - S2);

	// Case 1. include current item in the subset S1 and recur
	// for remaining items (n - 1)
	int inc = minPartition(S, n - 1, S1 + S[n], S2);

	// Case 2. exclude current item from subset S1 and recur for
	// remaining items (n - 1)
	int exc = minPartition(S, n - 1, S1, S2 + S[n]);

	return min (inc, exc);
}

int main() {
	//code
	int t;
	cin >> t;
	
	while(t--) {
	    int n;
	    cin >> n;
	    vector<int> arr(n);
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	    }
	    
	    cout << minPartition(arr,n-1,0,0) << "\n";
	}
	return 0;
}