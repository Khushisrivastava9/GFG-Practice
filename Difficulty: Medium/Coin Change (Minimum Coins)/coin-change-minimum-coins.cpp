//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int minCoins(vector<int> &coins, int sum) {
        int dp[sum+1];
       fill(dp, dp +sum+1, INT_MAX);
        for(int i=0; i < coins.size();i++) {
            if(coins[i] <= sum)
            dp[coins[i]] = 1;
        }
        for(int i=1; i <= sum;i++) {
            for(int j =1; j < i;j++) {
                if(dp[j] != INT_MAX && dp[i-j] != INT_MAX)
                   dp[i] = min(dp[i], dp[j] + dp[i-j]);
            }
        }
        if(dp[sum] == INT_MAX)
         return -1;
        return dp[sum] ;
        
        
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends