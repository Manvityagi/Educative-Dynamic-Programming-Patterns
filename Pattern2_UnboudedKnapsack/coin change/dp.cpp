//https://www.geeksforgeeks.org/coin-change-dp-7/
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// create a map to store solutions of subproblems
unordered_map<string, int> lookup;

// Function to find the total number of distinct ways to get change of N
// from unlimited supply of coins in set S
int count(int S[], int n, int N)
{
	// if total is 0, return 1 (solution found)
	if (N == 0)
		return 1;

	// return 0 (solution do not exist) if total become negative or
	// no elements are left
	if (N < 0 || n < 0)
		return 0;

	// construct a unique map key from dynamic elements of the input
	string key = to_string(n) + "|" + to_string(N);

	// if sub-problem is seen for the first time, solve it and
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// Case 1. include current coin S[n] in solution and recur
		// with remaining change (N - S[n]) with same number of coins
		int include = count(S, n, N - S[n]);

		// Case 2. exclude current coin S[n] from solution and recur
		// for remaining coins (n - 1)
		int exclude = count(S, n - 1, N);

		// assign total ways by including or excluding current coin
		lookup[key] = include + exclude;
	}

	// return solution to current sub-problem
	return lookup[key];
}

// Coin Change Problem
int main()
{
	// n coins of given denominations
	int S[] = { 1, 2, 3 };
	int n = sizeof(S) / sizeof(S[0]);

	// Total Change required
	int N = 4;

	cout << "Total number of ways to get desired change is "
		<< count(S, n - 1, N);

	return 0;
}