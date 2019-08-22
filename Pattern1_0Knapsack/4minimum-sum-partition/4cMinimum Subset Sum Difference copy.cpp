//https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/
//https://www.techiedelight.com/minimum-sum-partition-problem/

//TOP-DOWN MEMOIZATION

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// create a map to store solutions of subproblems
unordered_map<string, int> lookup;

// Partition the set S into two subsets S1, S2 such that the
// difference between the sum of elements in S1 and the sum
// of elements in S2 is minimized
int minPartition(int S[], int n, int S1, int S2)
{
	// base case: if list becomes empty, return the absolute
	// difference between two sets
	if (n < 0)
		return abs(S1 - S2);

	// construct a unique map key from dynamic elements of the input
	// Note that can uniquely identify the sub-problem with n and S1 only,
	// as S2 is nothing but S - S1 where S is sum of all elements
	string key = to_string(n) + "|" + to_string(S1);

	// if sub-problem is seen for the first time, solve it and
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// Case 1. include current item in the subset S1 and recur
		// for remaining items (n - 1)
		int inc = minPartition(S, n - 1, S1 + S[n], S2);

		// Case 2. exclude current item from subset S1 and recur for
		// remaining items (n - 1)
		int exc = minPartition(S, n - 1, S1, S2 + S[n]);

		lookup[key] = min (inc, exc);
	}

	return lookup[key];
}

// main function
int main()
{
	// Input: set of items
	int S[] = { 10, 20, 15, 5, 25 };

	// number of items
	int n = sizeof(S) / sizeof(S[0]);

	cout << "The minimum difference is " << minPartition(S, n - 1, 0, 0);

	return 0;
}