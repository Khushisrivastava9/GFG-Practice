//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        sort(arr.begin(),arr.end());
        string ans = "";
        for(int i=0; i<arr[0].size(); i++){
            for(int j=1; j<arr.size(); j++){
                if(arr[0][i] != arr[j][i]){
                    return ans.size() ? ans : "-1";
                }
            }
            ans += arr[0][i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends