//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        int n=num;
        int getith=(n>>i-1)&1;
        cout<<getith<<" ";
        int no=1<<i-1;
        int setith=num|no;
        cout<<setith<<" ";
        int cl=~(1<<i-1);
        int clearith=num&cl;
        cout<<clearith<<" ";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends