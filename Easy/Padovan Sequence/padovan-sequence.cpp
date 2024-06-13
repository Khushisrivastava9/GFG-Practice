//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int mod=1e9+7;
    int padovanSequence(int n) {
       if(n<=2) return 1;
       int n1=1, n2=1, n3=1, ans;
       for(int i=0;i<n-2;i++){
           ans=(n2+n3)%mod;
           
           n3=n2;
           n2=n1;
           n1=ans;
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends