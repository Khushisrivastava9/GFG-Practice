//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  int dp[201][201];
	int solve(int i,vector<int> cost,int n,int w){
	    if(w==0){
	        return 0;
	    }
	    if(i>=n){
	        return 1e9;
	    }
	    if(dp[i][w]!=-1){
	        return dp[i][w];
	    }
	    int take=INT_MAX,notake=INT_MAX;
	    if(w-(i+1)>=0 && cost[i]!=-1){
	        take=cost[i]+solve(i,cost,n,w-(i+1));
	        
	   }
	   notake=solve(i+1,cost,n,w);
	   return dp[i][w]=min(take,notake);
	}
    int minimumCost(int N, int W, vector<int> &cost) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,cost,N,W);
        if(ans==1e9)  return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends