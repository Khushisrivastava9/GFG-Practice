//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int nthRoot(int n, int m) {
        int s=1;
        int e=m;
        while(s<=e){
            int mid=s+(e-s)/2;
            int midn=1;
            for(int i=0;i<n;i++){
                midn*=mid;
                if(midn>m) break;
            }
            if(midn==m) return mid;
            else if(midn>m) e=mid-1;
            else s=mid+1;
        }
        return -1;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends