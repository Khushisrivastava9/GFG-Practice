//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n =arr.size();
        sort(arr.begin(),arr.end());
        int diff=arr[n-1]-arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-k<0){
                continue;
            }
            int mini=min(arr[0]+k,arr[i]-k);//trying to make all towers minimum except 1st
            int maxi=max(arr[i-1]+k,arr[n-1]-k);//trying to make all towers maximum except last
            diff=min(diff,maxi-mini);
        }
        return diff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends