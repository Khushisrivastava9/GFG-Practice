//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int mod = 1e9 + 7;
    int distinctSubseq(string &s){
        int n = s.size();
        vector<int> dp(n + 1, 0);
        unordered_map<char, int> m;
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            dp[i] = (2 * dp[i - 1]) % mod;
            char c = s[i - 1];
            if(m.find(c) != m.end()){
                dp[i] -= dp[m[c] - 1];
            }
            m[c] = i;
        }
        return dp[n] % mod;
    }
    string betterString(string str1, string str2) {
        int sub1 = distinctSubseq(str1);
        int sub2 = distinctSubseq(str2);
        if(sub2 > sub1) return str2;
        return str1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends