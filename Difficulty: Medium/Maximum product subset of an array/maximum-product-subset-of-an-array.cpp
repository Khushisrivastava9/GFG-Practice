//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int MOD=1e9+7;
    long long int findMaxProduct(vector<int>&a){
        int n=a.size();
        if(n==1) return a[0];
        long long int maxNeg = INT_MIN;
        long long int product = 1;
        int zeroCount = 0;
        int negCount = 0;
    
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                zeroCount++;
                continue;
            }
            if (a[i] < 0)
            {
                negCount++;
                maxNeg = max(maxNeg, static_cast<long long int>(a[i]));
            }
            product = (product * a[i]) % MOD;
        }
    
        // Handle cases with all zeros and only one negative number
        if (zeroCount == n || (zeroCount == n - 1 && negCount == 1))
            return 0;
    
        // Handle odd negative count
        if (negCount % 2 != 0)
            product = (product / maxNeg + MOD) % MOD;
    
        return product;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends