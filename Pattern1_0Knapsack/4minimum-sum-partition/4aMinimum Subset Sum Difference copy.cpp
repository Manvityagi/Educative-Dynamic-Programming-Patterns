//https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
//https://www.techiedelight.com/minimum-sum-partition-problem/

//Recursion - TLE


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int minsum(vector<int> arr, int i, int sumCalc, int sumTotal) {
    if(i == arr.size()) {
        return abs( (sumTotal-sumCalc) - sumCalc);
    }
    
    return min( minsum(arr,i+1,sumCalc+arr[i],sumTotal),
                minsum(arr,i+1,sumCalc,sumTotal));
}

int main() {
	//code
	int t;
	cin >> t;
	
	while(t--) {
	    int n,sumTotal = 0;
	    cin >> n;
	    vector<int> arr(n);
	    for(int i = 0; i < n; i++) {
	        cin >> arr[i];
	        sumTotal += arr[i];
	    }
	    
	    cout << minsum(arr,0,0,sumTotal) << "\n";
	}
	return 0;
}