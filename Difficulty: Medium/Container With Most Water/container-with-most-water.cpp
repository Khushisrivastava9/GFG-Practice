//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int i = 0;
        int j = arr.size()-1;
        int maxi = INT_MIN;
        while(i < j) {
            int area = min(arr[i],arr[j]) * (j-i);
            maxi = max(maxi,area);
            if(arr[i]<arr[j]) {
                i++;
            }
            else{
                j--;
            }
        }
        
        return maxi == INT_MIN? 0 : maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends