//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minSteps(int d) {
        int a = 1;
        int ele = 0, cnt = 0;
        while(ele<d){
            ele+=a;
            a++;
            cnt++;
        }
        
        while((ele-d)%2 != 0){
            cnt++;
            ele+=a;
            a++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d;
        cin >> d;

        Solution ob;
        cout << ob.minSteps(d) << "\n";
    }
    return 0;
}
// } Driver Code Ends