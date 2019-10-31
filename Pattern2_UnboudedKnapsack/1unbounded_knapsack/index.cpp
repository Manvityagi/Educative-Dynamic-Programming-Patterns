#include<bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define INF LONG_MAX
#define pr(i,x,n) for(int ii=i;ii<n+i;ii++){cout<<x[ii]<<" ";}cout<<endl;
#define ip(i,x,n) for(int ii=i;ii<n+i;ii++){cin>>x[ii];};
#define db(x,y) cout<<x<<" "<<y<<endl;
#define N 400100
#define LD long double
#define PR pair<LD,LL>

int unboundedKnapsack(int W, int n, int val[], int wt[]) 
{ 
    // dp[i] is going to store maximum value 
    // with knapsack capacity i. 
    int dp[W+1]; 
    memset(dp, 0, sizeof dp); 
  
    int ans = 0; 
  
    // Fill dp[] using above recursive formula 
    for (int i=0; i<=W; i++) 
      for (int j=0; j<n; j++) 
         if (wt[j] <= i) 
            dp[i] = max(dp[i], dp[i-wt[j]]+val[j]); 
  
    return dp[W]; 
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
	int n,W;
	int val[1000],wt[1000];
    	cin>>n>>W;
    	
    	for(int i = 0; i < n; i++)
    	    cin >> val[i] >> wt[i];

    	int ans = unboundedKnapsack(W,n,val,wt);
    	cout << ans << endl;
    }
    return 0;
}



static const int _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
}();