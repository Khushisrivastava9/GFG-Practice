//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int mod=1e9+7;
  int dp[501][501];
  int solve(int i,int j,string s1,string s2){
      if(i>s1.length()) return 0;
      if(j>=s2.length()){
          return 1;
      }
      if(dp[i][j]!=-1) return dp[i][j];
      int ans1=0;
      if(s1[i]==s2[j]) ans1=solve(i+1,j+1,s1,s2)%mod;
      int ans2=solve(i+1,j,s1,s2)%mod;
      return dp[i][j]=(ans1+ans2)%mod;
  }
    int countWays(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s1,s2);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends