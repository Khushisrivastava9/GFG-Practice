//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int dp[1001][1001];
    int solve(int i,int j,string &a, string &b,int n,int m,int &maxi){
        if(i>=n || j>=m){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int take=0;
        if(a[i]==b[j]){
            take=1+solve(i+1,j+1,a,b,n,m,maxi);
            maxi=max(maxi,take);
        }else{
            take=0;
        }
        solve(i+1,j,a,b,n,m,maxi);
        solve(i,j+1,a,b,n,m,maxi);
        
        return dp[i][j]=take;
    }
    int longestCommonSubstr (string S1, string S2)
    {
        int n=S1.size();
        int m=S2.size();
        memset(dp,-1,sizeof(dp));
        int maxi=0;
        solve(0,0,S1,S2,n,m,maxi);
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends